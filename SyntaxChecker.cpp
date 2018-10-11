#include <iostream>
#include "GenStack.h"
#include "CodeScanner.h"


using std::cout;
using std::endl;

int main(int argc, char** argv) {
  if (argc <= 1) {
    cout << "Error: a directory must be provided in the command line." << endl;
    return 1;
  }

  CodeScanner scanner(argv[1]);
  scanner.start();

  return 0;
}
