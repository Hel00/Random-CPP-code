//#include <cstdio>

using size = long long int;
using intptr = long long int;

extern char end asm("end"); // `_environ` on windows

void *systemBreak( intptr increment )
{
  static void *heapEnd = nullptr;

  if ( heapEnd == nullptr )
  {
    heapEnd = &end;
  }

  void *previousHeapEnd = heapEnd;
  heapEnd = (char*) heapEnd + increment;
  return previousHeapEnd;
}

void *alloc( size size )
{
  void *result = systemBreak( 0 );
  void *request = systemBreak( size );

  if ( request == (void*) -1 )
  {
    return nullptr;
  }

  return result;
}

int main()
{
  int *pointer = (int*) alloc( sizeof( int ) );
  *pointer = 123;

  //printf( " pointer = %x\n",  pointer );
  //printf( "*pointer = %d\n", *pointer );
  return 0;
}


// OR


using size_t = long long int;
using intptr = long long int;

extern char end asm("end"); // `_environ` on windows

void *systemBreak( intptr increment )
{
  static void *heapEnd = nullptr;

  if ( heapEnd == nullptr )
  {
    heapEnd = &end;
  }

  void *previousHeapEnd = heapEnd;
  heapEnd = (char*) heapEnd + increment;
  return previousHeapEnd;
}

struct MemBlock {
  void *ptr;
  size_t size;
  MemBlock *next;
};

MemBlock *head = nullptr;

void *alloc(size_t size) {
  void *result = systemBreak(0);
  void *request = systemBreak(size);

  if (request == (void*) -1) {
    return nullptr;
  }

  MemBlock *newBlock = (MemBlock*) systemBreak(sizeof(MemBlock));
  newBlock->ptr = result;
  newBlock->size = size;
  newBlock->next = head;
  head = newBlock;

  return result;
}

void free(void *ptr) {
  MemBlock *prev = nullptr;
  MemBlock *curr = head;

  while (curr != nullptr && curr->ptr != ptr) {
    prev = curr;
    curr = curr->next;
  }

  if (curr == nullptr) {
    return;
  }

  if (prev == nullptr) {
    head = curr->next;
  } else {
    prev->next = curr->next;
  }

  systemBreak((intptr) curr - (intptr) head);
}

/*
void checkMemoryLeak() {
  MemBlock *curr = head;

  while (curr != nullptr) {
    printf("Memory leak detected: %llu bytes at %p\n", curr->size, curr->ptr);
    curr = curr->next;
  }
}
*/

int main() {
  int *pointer = (int*) alloc(sizeof(int));
  *pointer = 123;

  free(pointer);

  //checkMemoryLeak();

  return 0;
}
