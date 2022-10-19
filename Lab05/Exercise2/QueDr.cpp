// Test driver
#include <iostream>
#include <fstream>

#include "QueType.h"

using namespace std;

int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed
  
  ItemType item, oldItem, newItem;
  QueType<ItemType> queue(5);
  QueType<ItemType> *temp;
  int numCommands, size, len;


  // Prompt for file names, read file names, and prepare files
  /*
  * 입력파일 : QueType.in
  * 출력파일 : QueType.out
  * command
  *   1. Enqueue
  *   2. MinDequeue
  *   3. IsEmpty
  *   4. IsFull
  *   5. Length
  *   6. Quit
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
        if (command == "Enqueue")
        {
            inFile >> item;
            queue.Enqueue(item);
            outFile << item << " is enqueued." << endl;
        }
        else if (command == "MinDequeue")
        {
            queue.MinDequeue(item);
            outFile << item << " is minDequeued. " << endl;
        }
        else if (command == "IsEmpty")
            if (queue.IsEmpty())
                outFile << "Queue is empty." << endl;
            else
                outFile << "Queue is not empty." << endl;

        else if (command == "IsFull")
            if (queue.IsFull())
                outFile << "Queue is full." << endl;
            else outFile << "Queue is not full." << endl;

        else if (command == "Length")
        {
            //멤버함수
            outFile << "Length is " << queue.Length() << "." << endl;

            //클라이언트 함수
            //outFile << "Length is " << Length(queue) << "." << endl;
        }
        /*
        else if (command == "Identical")
        {
            inFile >> size >> len;
            if (size < len)
                continue;
            temp = new QueType<ItemType>(size);
            
            while (len) {
                inFile >> item;
                temp->Enqueue(item);
                len--;
            }
            
            //멤버함수
            outFile << "Identical is " << queue.Identical(*temp) << "." << endl;

            //클라이언트 함수
            //outFile << "Identical is " << Identical(queue, *temp) << "." << endl;
            delete temp;
        }
        
        else if (command == "Replace")
        {
            inFile >> oldItem >> newItem;

            //멤버함수
            queue.ReplaceItem(oldItem, newItem);
            
            //클라이언트 함수
            //ReplaceItem(queue, oldItem, newItem);

            outFile << "Queue replaced from " << oldItem << " to " << newItem << endl;
        }
        */
    }
    catch (FullQueue)
    {
      outFile << "FullQueue exception thrown." << endl;
    }
    
    catch (EmptyQueue)
    {
      outFile << "EmtpyQueue exception thrown." << endl;
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

