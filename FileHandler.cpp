#include <cstdio>
#include <cstdlib>

class FileHandler
{
private:
  FILE* file;
  int CUR_SIZE;// = 4095;
  char* content; //= (char*) malloc(sizeof(char) * CUR_SIZE); // allocate content.
  int length = 0;

public:
  FileHandler();
  ~FileHandler();

  FileHandler(const char* path, const char* mode);
  void write(const char* data);
  const char* read();

  void open(const char* path);
  void close();
};

FileHandler::FileHandler()
{
  CUR_SIZE = 4095;
  content = (char*) malloc(sizeof(char) * CUR_SIZE);
}

FileHandler::~FileHandler(){}

FileHandler::FileHandler(const char* path, const char* mode)
{
  CUR_SIZE = 4095;
  content = (char*) malloc(sizeof(char) * CUR_SIZE);
  this->file = fopen(path, mode);
}

void FileHandler::write(const char* data)
{
  fputs(data, this->file);
}

const char* FileHandler::read()
{
  int ch = getc(this->file);

  while (ch != EOF)
  {
    if (length == CUR_SIZE)
    {
      CUR_SIZE *= 2;
      content = (char*)realloc(content, CUR_SIZE);
    }

    content[length] = ch;
    ch = getc(file);
    length++;
  }

  return content;
}

void FileHandler::open(const char* path, const char* mode)
{
  this->file = fopen(path, mode);
}

void FileHandler::close()
{
  fclose(this->file);
}

/* TEST */

/*
int main(int argc, char const *argv[])
{
  FileHandler file("C:\\Users\\dusan.popovic\\Documents\\CppWorkspace\\a.txt", "r+");

  printf("%s", file.read() );

  file.write("AROOOGAA");

  return 0;
}
*/
