// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "UnsortedType.h"

using namespace std;
void PrintList(ofstream& outFile, UnsortedType<int>& list);
template<class ItemType>
void MergeLists(UnsortedType<ItemType>& l_a, UnsortedType<ItemType>& l_b, UnsortedType<ItemType>& result);

/*
* 입력파일 : UnsortedType.in
* 출력파일 : UnsortedType.out
* command
*   1. InsertItem
*   2. DeleteItem
*   3. RetrieveItem
*   4. LengthIs
*   5. IsFull
*   6. Merge(Merge + size + list)
*     ex) Merge 4 1 50 4 2
*   7. Quit
*/

/*
int main()
{

    ifstream inFile;       // file containing operations
    ofstream outFile;      // file containing output
    string inFileName;     // input file external name
    string outFileName;    // output file external name
    string outputLabel;
    string command;        // operation to be executed

    int item;
    UnsortedType<int> list;
    bool found;
    int numCommands;


    // Prompt for file names, read file names, and prepare files
    cout << "Enter name of input command file; press return." << endl;
    cin >> inFileName;
    inFile.open(inFileName.c_str());

    cout << "Enter name of output file; press return." << endl;
    cin >> outFileName;
    outFile.open(outFileName.c_str());

    cout << "Enter name of test run; press return." << endl;
    cin >> outputLabel;
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
                list.InsertItem(item);
                outFile << item;
                outFile << " is inserted" << endl;
            }
            else if (command == "DeleteItem")
            {
                inFile >> item;
                list.DeleteItem(item);
                outFile << item;
                outFile << " is deleted" << endl;
            }
            else if (command == "RetrieveItem")
            {
                inFile >> item;

                list.RetrieveItem(item, found);
                if (found)
                    outFile << item << " found in list." << endl;
                else outFile << item << " not in list." << endl;
            }
            else if (command == "LengthIs")
                outFile << "Length is " << list.LengthIs() << endl;
            else if (command == "IsFull")
                if (list.IsFull())
                    outFile << "List is full." << endl;
                else outFile << "List is not full." << endl;

            else if (command == "Merge")
            {
                UnsortedType<int> temp, result;
                int size;

                inFile >> size;
                for (int i = 0; i < size; i++)
                {
                    inFile >> item;
                    temp.InsertItem(item);
                }

                //멤버 함수
                list.MergeLists(temp, result);

                //클라이언트 함수
                //MergeLists(list, temp, result);
                PrintList(outFile, result);
            }

            else PrintList(outFile, list);

        }
        catch (EmptyListData)
        {
            outFile << "EmtpyListData exception thrown." << endl;
        }
        numCommands++;
        cout << " Command " << command << " completed."
            << endl;
        inFile >> command;
    }
    cout << "Testing completed." << endl;
    inFile.close();
    outFile.close();
    return 0;
}
*/

void PrintList(ofstream& dataFile, UnsortedType<int>& list)
// Pre:  list has been initialized.      
//       dataFile is open for writing.   
// Post: Each component in list has been written to dataFile.
//       dataFile is still open.         
{
    int length;
    int item;
    list.ResetList();
    length = list.LengthIs();
    dataFile << "List Items: " << endl;
    for (int counter = 1; counter <= length; counter++)
    {
        list.GetNextItem(item);
        dataFile << item << endl;
    }
    dataFile << endl;
}


template<class ItemType>
void MergeLists(UnsortedType<ItemType>& l_a, UnsortedType<ItemType>& l_b, UnsortedType<ItemType>& result)
{
    ItemType aItem, bItem;
    int aSize = l_a.LengthIs();
    int bSize = l_b.LengthIs();

    l_a.ResetList();
    l_b.ResetList();
    while (aSize != 0)
    {
        l_a.GetNextItem(aItem);
        result.InsertItem(aItem);
        aSize--;
    }

    while (bSize != 0)
    {
        l_b.GetNextItem(bItem);
        result.InsertItem(bItem);
        bSize--;
    }
}