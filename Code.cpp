#include <iostream>
#include <string>
#include <fstream>

#include "Code.h"
#include "GenStack.h"

using std::cout;
using std::endl;

Code::Code(std::ifstream& f) : codeFile(f) {
  openBrackets = new GenStack<char> (1000);
}

bool Code::scan() {
  // Iterates through the stored code file, keeping track of the line number
  // and storing each open delimiter in the openBrackets stack. Writes an alert
  // to the console if one of three possible syntax errors occurs. Returns a
  // bool indicating whether the file passed the syntax checks.
  char current, openChar;
  int line = 1;

  while (codeFile.get(current)) {

    if (current == '\n') {
      line++;
    }
    else if ( isOpeningChar(current) ) {
      openBrackets->push(current);
    }
    else if ( isClosingChar(current) ) {
      // Error message if no opening brackets remain
      if (openBrackets->isEmpty()) {
        missingOpenBracketAlert(line, current);
        return false;
      }
      // Error message if opening and closing brackets do not match
      openChar = openBrackets->pop();
      if ( current != closingVersion(openChar) ) {
        mismatchingBracketAlert(line, openChar, current);
        return false;
      }
    }
  }
  // Error message if opening brackets remain at the end of the file
  if ( !openBrackets->isEmpty() ) {
    missingClosedBracketAlert(openBrackets->pop());
    return false;
  }

  cout << "The delimiter syntax for this file is valid." << endl;
  return true;
}

bool Code::isOpeningChar(char c) const {
  return (c == '{' or c == '[' or c == '(');
}

bool Code::isClosingChar(char c) const {
  return (c == '}' or c == ']' or c == ')');
}

void Code::missingOpenBracketAlert(int line, char closingChar) const {
  // Alerts if a closing delimiter is encountered when no open delimiters
  // are presently stored.
  std::cout << "Line " << line << ": No open delimiter found to match "
            << closingChar << std::endl;
}

void Code::missingClosedBracketAlert(char openChar) const {
  // Alerts if the end of the file is reached and open delimiters remain
  cout << "Reached end of file: missing " << closingVersion(openChar) << endl;
}

void Code::mismatchingBracketAlert(int line, char openChar, char closingChar) const {
  // Alerts if the most recently stored opening delimiter does not match a
  // closing delimiter

  char expected = closingVersion(openChar);
  cout << "Line " << line << ": expected " << expected
            << " and found " << closingChar << endl;
}

char Code::closingVersion(char openChar) const {
  // Given an open delimiter, returns its corresponding closing delimiter.
  // Throws an exception if the argument is not a recognized closing delimiter.
  switch (openChar) {
    case '(' : return ')';
    case '[' : return ']';
    case '{' : return '}';
    default  : throw std::runtime_error("Invalid opening bracket");
  }
}
