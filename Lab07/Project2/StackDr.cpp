// Test driver
#include <iostream>
#include <fstream>
#include "StackType.h"

using namespace std;

template <class ItemType>
void ReplaceItem(StackType<ItemType>& stack, ItemType oldItem, ItemType newItem);

template <class ItemType>
void Print(StackType<ItemType> stack, ofstream& outFile);


int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed
  
  int item, oldItem, newItem, size;
  StackType<int> stack;
  StackType<int>* temp;
  StackType<int>* copyStack;
  int numCommands;


  // Prompt for file names, read file names, and prepare files
  /*
  * 입력파일 : StackType.in
  * 출력파일 : StackType.out
  * command
  *   1. Push
  *   2. Pop
  *   3. Top
  *   4. IsEmpty
  *   5. IsFull
  *   6. Replace(Replace + oldItem + newItem)
  *     ex) Replace 3 5
  *   7. Copy(Copy + size + list)
  *     ex) Copy 5 42 2 13 1 101 
  *   8. Quit
  */
  cout << "Enter name of input command file; press return." << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press return." << endl;
  cin  >> outputLabel;
  outFile << outputLabel << endl;

  inFile >> command;

  numCommands = 0;
  while (command != "Quit")
  { 
    try 
    {
      if (command == "Push")
      {
        inFile >> item; 
        stack.Push(item);
      }  
      else if (command == "Pop")
        stack.Pop();
      else if (command == "Top")
      {
        item = stack.Top(); 
        outFile<< "Top element is " << item << endl;
      } 
      else if (command == "IsEmpty") 
        if (stack.IsEmpty())
          outFile << "Stack is empty." << endl;
        else 
          outFile << "Stack is not empty." << endl;
             
      else if (command == "IsFull")
        if (stack.IsFull())
          outFile << "Stack is full." << endl;
        else outFile << "Stack is not full."  << endl;

      else if (command == "Replace")
      {
          inFile >> oldItem >> newItem;

          //멤버함수
          stack.ReplaceItem(oldItem, newItem);

          //클라이언트 함수
          //ReplaceItem(stack, oldItem, newItem);

          outFile << "Stack replaced from " << oldItem << " to " << newItem << endl;
      }

      else if (command == "Copy")
      {
          temp = new StackType<int>;
          copyStack = new StackType<int>;
          inFile >> size;
          for (int i = 0; i < size; i++)
          {
              inFile >> item;
              temp->Push(item);
          }

          copyStack->Copy(*temp);

          outFile << "Stack copy and print" << endl;
          Print(*copyStack, outFile);
          delete temp;
          delete copyStack;
      }
    }
    catch (FullStack)
    {
      outFile << "FullStack exception thrown." << endl;
    }
    
    catch (EmptyStack)
    {
      outFile << "EmtpyStack exception thrown." << endl;
    }    
    numCommands++;
    cout <<  " Command number " << numCommands  << " completed." 
         << endl;
    inFile >> command;
 
  };
 
  cout << "Testing completed."  << endl;
  inFile.close();
  outFile.close();
  return 0;
}

template <class ItemType>
void ReplaceItem(StackType<ItemType>& stack, ItemType oldItem, ItemType newItem)
{
    StackType<ItemType> temp_stack;
    ItemType temp_item;

    while (!stack.IsEmpty())
    {
        temp_item = stack.Top();
        stack.Pop();
        if (temp_item == oldItem)
            temp_item = newItem;
        temp_stack.Push(temp_item);
    }

    while (!temp_stack.IsEmpty())
    {
        stack.Push(temp_stack.Top());
        temp_stack.Pop();
    }
}

template <class ItemType>
void Print(StackType<ItemType> stack, ofstream &outFile)
{
    outFile << "==== Print stack ====" << endl;
    while (!stack.IsEmpty())
    {
        outFile << "  " << stack.Top() << endl;
        stack.Pop();
    }
}