#include <iostream>
#include <string>
#include <fstream>

#include "CodeScanner.h"
#include "Code.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void CodeScanner::start() {
  // Continues to process files until either a file fails the syntax check or
  // the user asks to quit

  processFile();
  while ( codePassesTests && queryFileName() ) {
    processFile();
  }
}

void CodeScanner::processFile() {
  // Checks if the file exists in the working directory, then creates a new
  // code object and scans it for errors, updating whether the scan was a pass
  // or a fail
  if ( fileExists() ) {
    std::ifstream f (fileName);
    Code code (f);
    codePassesTests = code.scan();
  }
  else {
    cout << "Sorry, the file wasn't found." << endl;
  }
}

bool CodeScanner::fileExists() const {
  // Returns true if the fileName field leads to an existing file
  std::ifstream f (fileName);
  if ( f.is_open() ) {
    return true;
    f.close();
  }
  return false;
}

bool CodeScanner::queryFileName() {
  // Queries and returns whether the user would like to continue, and reads in
  // the new fileName if this is the case
  string cont;
  cout << "Would you like to analyze another file? ";
  cin >> cont;

  while (cont != "no" and cont != "n" and cont != "yes" and cont != "y") {
    cout << "Please enter either 'yes' or 'no': ";
    cin >> cont;
  }

  bool wantsToContinue = (cont == "yes" or cont == "y");

  if (wantsToContinue) {
    cout << "Ok, what file would you like to scan? ";
    cin >> fileName;
  }

  return wantsToContinue;
}
