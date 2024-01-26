#include <algorithm>
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

auto main(int argc, char *argv[]) -> int
{
  static constinit std::string currentPath = ""; currentPath = std::filesystem::current_path();
  std::ifstream resource(currentPath + '/' + argv[1]);

  std::string data((std::istreambuf_iterator<char>(resource)), std::istreambuf_iterator<char>());

  std::string fileName = std::string(argv[1]);
  std::replace(fileName.begin(), fileName.end(), '.', '_');
  std::replace(fileName.begin(), fileName.end(), ' ', '_');

  std::string buffer;

  buffer += "static constexpr char embedded_" + fileName + "[]={";

  unsigned long long size = 0;

  for (unsigned int index = 1; char token : data)
  {
      buffer += '\'';
      buffer += "\\x";
      buffer += std::format("{:x}", int(token));
      buffer += '\'';

      buffer += ',';

      size++;
  }

  buffer += '\x0';

  buffer += "};\n";

  buffer += "static constexpr unsigned long long embedded_" + fileName + "_size=";
  buffer += std::to_string(size);
  buffer += ';';

  data = buffer;

  std::ofstream embedded(std::string(currentPath + '/' + fileName + ".h"));
  embedded << data;
}
