#include <cstdio>
#include <cstdlib>

class ShellCommand
{
private:
  FILE *pipe;
  char output[1035];
  const char* command;

public:
  ShellCommand();
  ~ShellCommand();

  ShellCommand(const char* command);
  void set(const char* command);
  void execute();
  const char* read();
  void close();
};

ShellCommand::ShellCommand() {}
ShellCommand::~ShellCommand() {}

ShellCommand::ShellCommand(const char* command)
                          : command(command) {}

void ShellCommand::set(const char* command)
{
  this->command = command;
}

void ShellCommand::execute()
{
  this->pipe = popen(this->command, "r");
}

const char* ShellCommand::read()
{
  while (fgets(output, sizeof(output), this->pipe) != NULL)
  {
    return output;
  }

  return "";
}

void ShellCommand::close()
{
  pclose(this->pipe);
}

int main( int argc, char *argv[] )
{
  ShellCommand command;

  command.set("echo Hello World!");
  command.execute();

  printf( "Command: %s", command.read() );

  command.close();

  return 0;
}
