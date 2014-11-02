#ifndef WORDSEARCH_H
#define WORDSEARCH_H

#include "IWordSearch.h"

using namespace std;

class CWordLinearSearch : public IWordSearch
{
public:
  CWordLinearSearch();
  virtual ~CWordLinearSearch();
  virtual bool Search(const vector<string>& aStrings, const string& aToken);
  
private:
  CWordLinearSearch& operator=(const CWordLinearSearch& aWordSearch);
  CWordLinearSearch(const CWordLinearSearch& aWordSearch);

};


class CWordBinarySearch : public IWordSearch
{
public:
  CWordBinarySearch();
  virtual ~CWordBinarySearch();
  virtual bool Search(const vector<string>& aStrings, const string& aToken);
  
private:
  CWordBinarySearch& operator=(const CWordBinarySearch& aWordSearch);
  CWordBinarySearch(const CWordBinarySearch& aWordSearch);
//  void InsertNode(CNode*& aNode, fstream& aFile);
  
  struct CNode
  {
    CNode(streamoff aOffset)
    {
      iOffset = aOffset;
      left = NULL;
      right = NULL;
    }
    
    streamoff iOffset;
    struct CNode* left;
    struct CNode* right;
  };
  
  struct CNode* iRoot;
};

#endif //WORDSEARCH_H