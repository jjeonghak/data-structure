// Header file for Sorted List ADT.  
template <class ItemType>
struct NodeType;
#include <stddef.h>
#include <iostream>
#include <fstream>

// Assumption:  ItemType is a type for which the operators "<" 
// and "==" are defined-either an appropriate built-in type or
// a class that overloads these operators.

class EmptyListData
// Exception class thrown by GetNextItem when listData is empty.
{};

template <class ItemType>
class SortedType
{
public:
  SortedType();     // Class constructor	
  ~SortedType();    // Class destructor

  bool IsFull() const;
  // Determines whether list is full.
  // Post: Function value = (list is full)

  int  LengthIs() const;
  // Determines the number of elements in list.
  // Post: Function value = number of elements in list.

  void MakeEmpty();
  // Initializes list to empty state.
  // Post:  List is empty.

  void RetrieveItem(ItemType& item, bool& found);
  // Retrieves list element whose key matches item's key 
  // (if present).
  // Pre:  Key member of item is initialized.
  // Post: If there is an element someItem whose key matches 
  //       item's key, then found = true and item is a copy 
  //       of someItem; otherwise found = false and item is 
  //       unchanged. 
  //       List is unchanged.
    
  void ResetList();
  // Initializes current position for an iteration through the
  // list.
  // Post: Current position is prior to list.

  void GetNextItem(ItemType&);
  // Gets the next element in list.
  // Pre:  Current position is defined.
  //       Element at current position is not last in list.
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

  void DeleteItem(ItemType item);
  
  void InsertItem(ItemType item);
  
  void PrintReverse();

  void PrintReverse(std::ofstream& outFile);


private:
  NodeType<ItemType>* listData;
  int length;
  NodeType<ItemType>* currentPos;
};
template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};
template <class ItemType>
SortedType<ItemType>::SortedType()  // Class constructor
{
  length = 0;
  listData = NULL;
}
template<class ItemType>
bool SortedType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
  NodeType<ItemType>* location;
  try
  {
    location = new NodeType<ItemType>;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}
template <class ItemType>
int SortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
  return length;
}
template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, 
     bool& found)
{
  bool moreToSearch;
  NodeType<ItemType>* location;

  location = listData;
  found = false;
  moreToSearch = (location != NULL);

  while (moreToSearch && !found)
  {
    if (location->info < item)
    {
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else if (item == location->info)
    {
      found = true;
      item = location->info;
    }
    else
      moreToSearch = false;
  }
}

 template <class ItemType>
void SortedType<ItemType>::ResetList()
{
    currentPos = NULL;
}

template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is 
//        current item.
{
    if (listData == NULL)
        throw EmptyListData();
    if (currentPos == NULL)
      currentPos = listData;
    item = currentPos->info; 
    currentPos = currentPos->next;
} 

template <class ItemType>
SortedType<ItemType>::~SortedType()
// Post: List is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    int size = length;

    for (int i = 0; i < size; i++)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
  }


template<class ItemType>
void FindItem(NodeType<ItemType>* listData,
    ItemType item,
    NodeType<ItemType>*& location,
    NodeType<ItemType>*& predLoc,
    bool& found)
    // Assumption: ItemType is a type for which the operators ''<'' and
    //      "==" are defined as either an appropriate built-in type or a
    //      class that overloads these operations.
    // Pre: List is not empty.
    // Post:If there is an element someItem whose key matches item's
    //      key, then found = true; otherwise, found = false.
    //      If found, location contains the address of someItem and
    //      predLoc contains the address of someItem's predecessor;
    //      otherwise, location contains the address of item's logical
    //      successor and predLoc contains the address of item's
    //      logical predecessor.
{
    bool moreToSearch = true;

    location = listData->next;
    predLoc = listData;
    found = false;

    while (moreToSearch && !found)
    {
        if (item < location->info)
            moreToSearch = false;
        else if (item == location->info)
            found = true;
        else
        {
            predLoc = location;
            location = location->next;
            moreToSearch = (location != listData->next);
        }
    }
}

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
    NodeType<ItemType>* newNode;  // pointer to node being inserted
    NodeType<ItemType>* predLoc;  // trailing pointer
    NodeType<ItemType>* location; // traveling pointer
    bool moreToSearch;

    location = listData;
    predLoc = NULL;
    moreToSearch = (location != NULL);

    // Find insertion point.
    while (moreToSearch)
    {
        if (location->info < item)
        {
            predLoc = location;
            location = location->next;
            moreToSearch = (location != NULL);
        }
        else
            moreToSearch = false;
    }

    // Prepare node for insertion
    newNode = new NodeType<ItemType>;
    newNode->info = item;
    // Insert node into list.
    if (predLoc == NULL)         // Insert as first
    {
        newNode->next = listData;
        listData = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}

template<class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
{
    NodeType<ItemType>* location;
    NodeType<ItemType>* predLoc;
    bool found;

    if (length == 0)
        throw EmptyListData();
    FindItem(listData, item, location, predLoc, found);
    if (predLoc == location) // Only node in list?
        listData = NULL;
    else
    {
        predLoc->next = location->next;
        if (location == listData) // Deleting last node in list?
            listData = predLoc;
    }
    delete location;
    length--;
}

template<class ItemType>
void SortedType<ItemType>::PrintReverse()
{
    NodeType<ItemType>* location;
    ItemType* arr = new ItemType[length];
    location = listData;
    for (int i = 0; i < length; i++)
    {
        *(arr + i) = location->info;
        location = location->next;
    }
    for (int i = length - 1; i >= 0; i--)
        std::cout << *(arr + i) << std::endl;
    delete[] arr;
}

template<class ItemType>
void SortedType<ItemType>::PrintReverse(std::ofstream &outFile)
{
    NodeType<ItemType>* location;
    ItemType* arr = new ItemType[length];
    location = listData;
    for (int i = 0; i < length; i++)
    {
        *(arr + i) = location->info;
        location = location->next;
    }
    for (int i = length - 1; i >= 0; i--)
        outFile << *(arr + i) << std::endl;
    delete[] arr;
}