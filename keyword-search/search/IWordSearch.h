#ifndef IWORDSEARCH_H
#define IWORDSEARCH_H

#include <string>
#include <vector>
#include <fstream>

class IWordSearch
{
public:
  virtual ~IWordSearch() {}
  virtual bool Search(const std::vector<std::string>& aStrings, const std::string& aToken) = 0;
};

#endif //IWORDSEARCH_H