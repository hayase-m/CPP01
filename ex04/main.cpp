#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

static bool readFile(const std::string &filename, std::string &content) {
  std::ifstream input(filename.c_str());

  if (!input)
    return false;
  std::ostringstream buffer;
  buffer << input.rdbuf();
  content = buffer.str();
  return true;
}

static bool writeFile(const std::string &filename, const std::string &content) {
  std::ofstream output(filename.c_str());

  if (!output)
    return false;
  output << content;
  return true;
}

static std::string replaceAll(const std::string &content, const std::string &s1,
                              const std::string &s2) {
  std::string result;
  std::size_t start = 0;
  std::size_t pos = 0;

  while (1) {
    pos = content.find(s1, start);
    if (pos == std::string::npos) {
      result += content.substr(start);
      break;
    }
    result += content.substr(start, pos - start) + s2;
    start = pos + s1.length();
  }

  return result;
}

int main(int ac, char **av) {
  if (ac != 4) {
    std::cerr << "Usage: ./ft_sed <filename> <s1> <s2>" << std::endl;
    return 1;
  }
  std::string filename = av[1];
  std::string s1 = av[2];
  std::string s2 = av[3];
  std::string content;

  if (s1.empty()) {
    std::cerr << "Error: s1 must not be empty" << std::endl;
    return 1;
  }
  if (!readFile(filename, content)) {
    std::cerr << "Error: cannot open input file" << std::endl;
    return 1;
  }
  if (!writeFile(filename + ".replace", replaceAll(content, s1, s2))) {
    std::cerr << "Error: cannot open output file" << std::endl;
    return 1;
  }
  return 0;
}
