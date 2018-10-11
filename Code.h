#ifndef _CODE_H_
#define _CODE_H_

#include <fstream>
#include "GenStack.h"

class Code {
public:
  Code(std::ifstream&);
  ~Code() { delete openBrackets; codeFile.close(); }
  bool scan();

private:
  std::ifstream& codeFile;
  GenStack<char>* openBrackets;

  bool isOpeningChar(char) const;
  bool isClosingChar(char) const;
  void missingOpenBracketAlert(int, char) const;
  void missingClosedBracketAlert(char) const;
  void mismatchingBracketAlert(int, char, char) const;
  char closingVersion(char) const;
};

#endif
