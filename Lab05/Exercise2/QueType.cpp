#include "QueType.h"

QueType<ItemType>::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = max;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
  for (int i = 0; i < maxQue; i++)
      items[i] = -1;
  length = 0;
  min_pos = 0;
}
QueType<ItemType>::QueType()
// Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = 500;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
  for (int i = 0; i < maxQue; i++)
      items[i] = -1;
  length = 0;
  min_pos = 0;
}
QueType<ItemType>::QueType(const QueType<ItemType>& origin) {
    int index;
    maxQue = origin.maxQue;
    front = origin.front;
    rear = origin.rear;
    items = new ItemType[maxQue];
    length = origin.length;
    min_pos = origin.min_pos;
    index = front;
    for (int i = 0; i < maxQue; i++)
        items[index] = origin.items[index];
}
QueType<ItemType>::~QueType()         // Class destructor
{
  delete [] items;
}

void QueType<ItemType>::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = maxQue - 1;
  rear = maxQue - 1;
  length = 0;
}

bool QueType<ItemType>::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return length == 0;
}

bool QueType<ItemType>::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return length == maxQue;
}

void QueType<ItemType>::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
  if (IsFull())
    throw FullQueue();
  else
  {
      if (length == 0) {
          items[0] = newItem;
          min_pos = 0;
      }
      else {
          for (int i = 0; i < maxQue; i++) {
              if (items[i] == -1) {
                  items[i] = newItem;
                  if (newItem <= items[min_pos])
                      min_pos = i;
                  break;
              }
          }
      }
      length++;
  }
}
/*
void QueType<ItemType>::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
    front = (front + 1) % maxQue;
    item = items[front];
    length--;
  }
}
*/
int QueType<ItemType>::Length() const {
    return length;
}
 
int QueType<ItemType>::Size() const {
    return maxQue;
}
/*
bool QueType<ItemType>::Identical(QueType<ItemType> queue) {
    ItemType item;
    int index = (front + 1) % maxQue;
    bool check = false;

    if (length != queue.Length() || maxQue != queue.Size())
        return false;
    while (index != (rear + 1) % maxQue) {
        queue.Dequeue(item);
        if (items[index] != item) {
            check = true;
            break;
        }
        index = (index + 1) % maxQue;
    }
    if (check)
        return false;
    return true;
}

void QueType<ItemType>::ReplaceItem(ItemType oldItem, ItemType newItem) {
    int index = front;
    for (int i = 0; i < length; i++) {
        index = (index + 1) % maxQue;
        if (items[index] == oldItem)
            items[index] = newItem;
    }
}
*/
void QueType<ItemType>::MinDequeue(ItemType& item)
{
    int temp = min_pos;
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        item = items[min_pos];
        items[min_pos] = 2147483647;
        for (int i = 0; i < maxQue; i++) {
            if (items[i] != -1 && items[i] <= items[min_pos])
                min_pos = i;
        }
        items[temp] = -1;
        length--;
    }
}