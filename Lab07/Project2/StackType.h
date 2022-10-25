// Linked Stack ADT
#include <cstddef>
#include <new>

template <class ItemType>
struct NodeType;


class FullStack
// Exception class thrown by Push when stack is full.
{};

class EmptyStack
// Exception class thrown by Pop and Top when stack is emtpy.
{};


template <class ItemType>
class StackType
{
public:

  StackType();
  
  StackType(const StackType<ItemType>& other);

  ~StackType();

  bool IsFull() const;
  // Function: Determines whether the stack is full.
  // Pre:  Stack has been initialized.
  // Post: Function value = (stack is full)

  bool IsEmpty() const;
  // Function: Determines whether the stack is empty.
  // Pre:  Stack has been initialized.
  // Post: Function value = (stack is empty)

  void Push(ItemType item);
  // Function: Adds newItem to the top of the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is full), FullStack exception is thrown;
  //     otherwise, newItem is at the top of the stack.

  void Pop();
  // Function: Removes top item from the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is empty), EmptyStack exception is thrown;
  //     otherwise, top element has been removed from stack.

  ItemType Top();
  // Function: Returns a copy of top item on the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is empty), EmptyStack exception is thrown;
  //     otherwise, top element has been removed from stack.

  void ReplaceItem(ItemType oldItem, ItemType newItem);

  size_t Size();

  void Copy(StackType<ItemType>& anotherStack);

private:
  NodeType<ItemType>* topPtr;
  size_t size;
};

template <class ItemType>
struct NodeType
{
  ItemType info;
  NodeType* next;
};

template <class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
// Adds newItem to the top of the stack.
// Pre:  Stack has been initialized.
// Post: If stack is full, FullStack exception is thrown;
//       else newItem is at the top of the stack.

{
    if (IsFull())
        throw FullStack();
    else
    {
        NodeType<ItemType>* location;
        location = new NodeType<ItemType>;
        location->info = newItem;
        location->next = topPtr;
        topPtr = location;
        size++;
    }
}

template <class ItemType>
void StackType<ItemType>::Pop()
// Removes top item from Stack and returns it in item.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else top element has been removed.
{
    if (IsEmpty())
        throw EmptyStack();
    else
    {
        NodeType<ItemType>* tempPtr;
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
        size--;
    }
}

template <class ItemType>
ItemType StackType<ItemType>::Top()
// Returns a copy of the top item in the stack.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else a copy of the top element is returned.
{
    if (IsEmpty())
        throw EmptyStack();
    else
        return topPtr->info;
}

template <class ItemType>
bool StackType<ItemType>::IsEmpty() const
// Returns true if there are no elements on the stack; false otherwise.
{
    return (topPtr == NULL);
}

template <class ItemType>
bool StackType<ItemType>::IsFull() const
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
    catch (std::bad_alloc)
    {
        return true;
    }
}

template <class ItemType>
StackType<ItemType>::~StackType()
// Post: stack is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (topPtr != NULL)
    {
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}

template <class ItemType>
StackType<ItemType>::StackType()	// Class constructor.
{
    topPtr = NULL;
    size = 0;
}

template <class ItemType>
StackType<ItemType>::StackType(const StackType<ItemType>& origin)
{
    StackType<ItemType> temp;
    NodeType<ItemType>* location;
    size = origin.size;
    location = origin.topPtr;
    topPtr = NULL;
    while (location != NULL)
    {
        temp.Push(location->info);
        location = location->next;
    }
    while (!temp.IsEmpty())
    {
        location = new NodeType<ItemType>;
        location->info = temp.Top();
        location->next = topPtr;
        topPtr = location;
        temp.Pop();
    }
}

template <class ItemType>
void StackType<ItemType>::ReplaceItem(ItemType oldItem, ItemType newItem)
{
    NodeType<ItemType>* location = topPtr;

    while (location != NULL)
    {
        if (location->info == oldItem)
            location->info = newItem;
        location = location->next;
    }
}

template <class ItemType>
size_t StackType<ItemType>::Size()
{
    return size;
}

template <class ItemType>
void StackType<ItemType>::Copy(StackType<ItemType>& anotherStack)
{
    StackType<ItemType> temp;
    NodeType<ItemType>* location;
    size = anotherStack.size;
    location = anotherStack.topPtr;
    topPtr = NULL;
    while (location != NULL)
    {
        temp.Push(location->info);
        location = location->next;
    }
    while (!temp.IsEmpty())
    {
        location = new NodeType<ItemType>;
        location->info = temp.Top();
        location->next = topPtr;
        topPtr = location;
        temp.Pop();
    }
}
