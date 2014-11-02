
#include "WordSearch.h"
#include <iostream>

CWordLinearSearch::CWordLinearSearch()
{
}

CWordLinearSearch::~CWordLinearSearch()
{
}

bool CWordLinearSearch::Search(const vector<string>& aStrings, const string& aToken)
{
  int lineCount = 0;
  for (vector<string>::const_iterator it = aStrings.begin(); it != aStrings.end(); it++)
  {
    if (*it == aToken)
    {
      cout << "==> Linear search found: " << aToken << ", at line " << lineCount << "\n";
      return true;
    }
    lineCount++;
  }
  cout << "==> Linear search not found.\n";
  return false;
}


CWordBinarySearch::CWordBinarySearch()
{
}

CWordBinarySearch::~CWordBinarySearch()
{
}
/*
void CWordBinarySearch::InsertNode(CNode*& aNode, fstream& aFile)
{
  string newData;
  newData << aFile;
  
  if (aNode == NULL)
  {
    aNode = new CNode(aFile.tellg(), newData);
    return;
  }
  
  if ( newData < aNode->iString)
  {
    InsertNode(aNode->left, newData);
  }
  else
  {
    InsertNode(aNode->right, newData);
  }
}

CNode* CWordBinarySearch::BuildBinaryTree(fstream& aFile, streamoff& start, streamoff& end)
{
  streamoff middle = (start + end) / 2;
  CNode* node = new CNode(aFile.tellg());
  
  return node;
}
*/
bool CWordBinarySearch::Search(const vector<string>& aStrings, const string& aToken)
{
  int first = 0;
  int last = aStrings.size() - 1;
  while (first <= last)
  {
    int middle = (first + last) / 2;
    if (aStrings[middle] > aToken)
    {
      last = middle - 1;
    }
    else if (aStrings[middle] < aToken)
    {
      first = middle + 1;
    }
    else
    {
      cout << "==> Binary search found: " << aToken << ", at line " << middle << "\n";
      return true;
    }
  }
  cout << "==> Binary search not found.\n";
  return false;
}