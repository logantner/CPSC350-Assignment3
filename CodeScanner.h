#ifndef _CODE_SCANNER_H_
#define _CODE_SCANNER_H_

#include <string>

class CodeScanner {
public:
  CodeScanner() {}
  CodeScanner(std::string name) : fileName(name) {}
  ~CodeScanner() {}
  void start();

private:
  std::string fileName;
  bool codePassesTests;

  bool fileExists() const;
  void processFile();
  bool queryFileName();

};

#endif
