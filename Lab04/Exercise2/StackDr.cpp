// Test driver
#include <iostream>
#include <fstream>

#include "StackType.h"

using namespace std;

void ReplaceItem(StackType& st, int oldItem, int newItem);

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
  * 입력파일 : Replace.in
  * 출력파일 : Replace.out
  * command
  *   1. Push
  *   2. Pop
  *   3. Top
  *   4. IsEmpty
  *   5. IsFull
  *   6. Replace
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

      else if (command == "Replace") {
          inFile >> oldItem >> newItem;
          //클라이언트 함수
          ReplaceItem(stack, oldItem, newItem);

          //멤버 함수
          //stack.Replace(oldItem, newItem);
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
    cout <<  " Command number " << numCommands << " completed." 
         << endl;
    inFile >> command;
 
  };
 
  cout << "Testing completed."  << endl;
  inFile.close();
  outFile.close();
  return 0;
}

void ReplaceItem(StackType& st, int oldItem, int newItem) {
    if (st.IsEmpty())
        return;
    int top = st.Top();
    if (top == oldItem)
        top = newItem;
    st.Pop();
    ReplaceItem(st, oldItem, newItem);
    st.Push(top);
    return;
}



