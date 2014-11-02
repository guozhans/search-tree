#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

static const int KDefaultIncreaseSize = 4;

template <typename T>
class CBinaryHeap
{
public:
  CBinaryHeap();
  explicit CBinaryHeap(const vector<T>& aHeap);
  virtual ~CBinaryHeap();
  
  //The methods of binary heap
  void Insert(const T& aNode);
  void DeleteMin(T& aMinNode);
  void DumpHeap();
  
private:
  int GetParentIndex(const int aChildIndex) const;
  int GetLeftNodeIndex(const int aParentIndex) const;
  int GetRightNodeIndex(const int aParentIndex) const;
  void MoveUp(int aIndex, const T& aNode);
  void MoveDown(int aIndex, const T& aNode);
  
private:
  int iSize;
  vector<T> iContainer;
};


template <typename T> CBinaryHeap<T>::CBinaryHeap()
  : iSize(0)
{}

template <typename T> CBinaryHeap<T>::CBinaryHeap(const vector<T>& aHeap)
{
}

template <typename T> CBinaryHeap<T>::~CBinaryHeap()
{
  iContainer.clear();
  iSize = 0;
}

template <typename T> int CBinaryHeap<T>::GetParentIndex(const int aChildIndex) const
{
  if (aChildIndex > 0)
  {
    return ((aChildIndex - 1) / 2);
  }
  else
  {
    return 0;
  }
}

template <typename T> int CBinaryHeap<T>::GetLeftNodeIndex(const int aParentIndex) const
{
  return aParentIndex * 2 + 1;
}

template <typename T> int CBinaryHeap<T>::GetRightNodeIndex(const int aParentIndex) const
{
  return aParentIndex * 2 + 2;
}

template <typename T> void CBinaryHeap<T>::MoveUp(int aIndex, const T& aNode)
{
  for (int holeIndex = aIndex; holeIndex >= 0; holeIndex = GetParentIndex(holeIndex))
  {
    if (iContainer[GetParentIndex(holeIndex)] > aNode && holeIndex > 0)
    {
      iContainer[holeIndex] = iContainer[GetParentIndex(holeIndex)];
    }
    else
    {
      iContainer[holeIndex] = aNode;
      break;
    }
  }
}

template <typename T> void CBinaryHeap<T>::MoveDown(int aIndex, const T& aNode)
{
  int holeIndex = aIndex;
  int child = 0;
  for (; (holeIndex * 2) < (iSize - 1); holeIndex = child)
  {
    int rightNodeIndex = GetRightNodeIndex(holeIndex);
	child = GetLeftNodeIndex(holeIndex);
    if ((child < (iSize - 1)) && (iContainer[child] > iContainer[rightNodeIndex]))
    {
      child = GetRightNodeIndex(holeIndex);
    }
    
    if (aNode > iContainer[child])
    {
      iContainer[holeIndex] = iContainer[child];
    }
    else
    {
      break;
    }
  }
  
  iContainer[holeIndex] = aNode;
}

template <typename T> void CBinaryHeap<T>::Insert(const T& aNode)
{
  if (iSize == iContainer.size())
  {
    iContainer.resize(iContainer.size() + KDefaultIncreaseSize);
  }
  
  int holeIndex = iSize++;
  MoveUp(holeIndex, aNode);
}

template <typename T> void CBinaryHeap<T>::DeleteMin(T& aMinNode)
{
  if (iContainer.size() == 0 || iSize == 0)
  {
    return;
  }
  aMinNode = iContainer[0];
  MoveDown(0, iContainer[--iSize]);
}

template <typename T> void CBinaryHeap<T>::DumpHeap()
{
  int oount = 0;
  vector<T>::iterator it = iContainer.begin();
  cout << "===> Dump heap: ";
  while (it != iContainer.end() && oount++ < iSize)
  {
    cout << *it << " | ";
	++it;
  }
}


#endif //BINARY_HEAP_H