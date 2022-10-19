// Test driver
#include <iostream>
#include <fstream>

#include "StackType.h"

using namespace std;

void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem);

int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed
  
  ItemType item, oldItem, newItem;
  StackType stack;
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
  *   7. Quit
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

void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem) 
{
    StackType temp_stack;
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


