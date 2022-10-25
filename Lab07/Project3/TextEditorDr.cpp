// Test driver
#include <iostream>
#include <fstream>
#include "TextEditor.h"

using namespace std;


int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed
  
  string item;
  TextEditor editor;
  LineType* temp;
  int numCommands;


  // Prompt for file names, read file names, and prepare files
  /*
  * 입력파일 : TextEditor.in
  * 출력파일 : TextEditor.out
  * command
  *   1. InsertItem
  *   2. GetLength
  *   3. IsEmpty
  *   4. ResetList
  *   5. GetNextItem
  *   6. GoToTop
  *   7. GoToBottom
  *   8. MakeEmpty
  *   9. Quit
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
        if (command == "InsertItem")
        {
            inFile >> item;
            editor.InsertItem(item);
        }
        else if (command == "GetLength")
            outFile << "Length is " << editor.GetLength() << endl;
        else if (command == "IsEmpty")
            if (editor.IsEmpty())
                outFile << "TextEditor is empty." << endl;
            else
                outFile << "TextEditor is not empty." << endl;
        else if (command == "ResetList")
        {
            editor.ResetList();
            outFile << "Reset TextEditor." << endl;
        }
        else if (command == "GetNextItem")
        {
            item = "";
            editor.GetNextItem(item);
            outFile << "Next item is \"" << item << "\""<<endl;
        }
        else if (command == "GoToTop")
        {
            editor.GoToTop(temp);
            outFile << "Go to top: " << temp->data << endl;
        }
        else if (command == "GoToBottom")
        {
            editor.GoToBottom(temp);
            outFile << "Go to bottom: " << temp->data << endl;
        }
        else if (command == "MakeEmpty")
        {
            editor.MakeEmpty();
            outFile << "Make empty TextEditor" << endl;
        }
    }
    catch (ArrayIndexOutOfBoundsException)
    {
      outFile << "ArrayIndexOutOfBoundsException thrown." << endl;
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
