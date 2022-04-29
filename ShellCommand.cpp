#include <cstdio>
#include <cstdlib>

class ShellCommand
{
private:
  FILE *pipe{};
  char output[1035]{};
  const char* command{};

public:
  ShellCommand() = default;
  virtual ~ShellCommand() = default;

  explicit ShellCommand(const char* command);
  void set(const char* command);
  void execute();
  auto read() -> const char*;
  void close();
};

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

auto ShellCommand::read() -> const char*
{
  while (fgets(output, sizeof(output), this->pipe) != nullptr)
  {
    return output;
  }

  return "";
}

void ShellCommand::close()
{
  pclose(this->pipe);
}

auto main() -> int
{
  ShellCommand command;

  command.set("echo Hello World!");
  command.execute();

  printf( "Command: %s", command.read() );

  command.close();

  return 0;
}
