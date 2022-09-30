#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::string PRO = "cgraph";
  std::string DIR = ".";
  std::string INC = DIR + "inc";
  std::string SRC = DIR + "src";
  std::string SRC_TYPE = SRC + "type";

  if (1 == argc) {
  } else if (0 == std::string(argv[1]).compare("test")) {
  } else if (0 == std::string(argv[1]).compare("clean")) {
  } else if (0 == std::string(argv[1]).compare("distclean")) {
  } else if (0 == std::string(argv[1]).compare("help")) {
    std::cout << argv[0] << " <target>" << std::endl;
    std::cout << "<target>: " << std::endl;
    std::cout << "                    compile cgraph" << std::endl;
    std::cout << "          test      test cgraph" << std::endl;
    std::cout << "          clean     clean all the generated files"
              << std::endl;
    std::cout << "          distclean clean all the generated files and "
                 "directories"
              << std::endl;
    std::cout << "          help      commands to this program" << std::endl;
  } else {
    std::cout << argv[1] << " is an unsupported command" << std::endl;
    std::cout << "use \"" << argv[0] << " help\" to know all supported commands"
              << std::endl;
  }

  return 0;
}
