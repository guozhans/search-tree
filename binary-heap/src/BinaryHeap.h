#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>

using namespace std;

static const int KDefaultIncreaseSize = 128;

template <typename T>
class CBinaryHeap
{
public:
  CBinaryHeap();
  explicit CBinaryHeap(const vector<T>& aHeap);
  virtual ~CBinaryHeap();
  
  //The methods of binary heap
  void Insert(const T& aNode);

private:
  int GetParentIndex(const int aChildIndex) const;
  
private:
  int iSize;
  vector<T> iContainer;
};


template <typename T>
CBinaryHeap<T>::CBinaryHeap()
  : iSize(0)
{}

template <typename T> 
CBinaryHeap<T>::CBinaryHeap(const vector<T>& aHeap)
{
}

template <typename T>
CBinaryHeap<T>::~CBinaryHeap()
{
  iContainer.clear();
  iSize = 0;
}

template <typename T>
int CBinaryHeap<T>::GetParentIndex(const int aChildIndex) const
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

template <typename T>
void CBinaryHeap<T>::Insert(const T& aNode)
{
  if (iSize == iContainer.size())
  {
    iContainer.resize(iContainer.size() + KDefaultIncreaseSize);
  }
  
  int holeIndex = iSize++;
  for (; holeIndex >= 0; holeIndex = GetParentIndex(holeIndex))
  {
    if (iContainer[GetParentIndex(holeIndex)] > aNode)
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

#endif //BINARY_HEAP_H