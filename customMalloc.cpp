//#include <cstdio>

using size_t = long long int;
using intptr_t = int;

extern char end asm("end");

void *custom_sbrk(intptr_t increment) {
    static void *heap_end = nullptr;

    if (heap_end == nullptr)
    {
        heap_end = &end;
    }

    void *previous_heap_end = heap_end;
    heap_end = (char *)heap_end + increment;
    return previous_heap_end;
}

void* custom_malloc(size_t size) {
    void* p = custom_sbrk(0);
    void* request = custom_sbrk(size);
    if (request == (void*) -1) {
        return nullptr;
    } else {
        return p;
    }
}

int main() {
    int* p = (int*) custom_malloc(sizeof(int));
    *p = 123;

    //printf("%d\n", *p);
    return 0;
}
