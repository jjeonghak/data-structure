#include <iostream>
#include <fstream>
#include "TreeType.h"

using namespace std;

int main()
{
    ifstream inFile;       // file containing operations
    ofstream outFile;      // file containing output
    string inFileName;     // input file external name
    string outFileName;    // output file external name
    string outputLabel;
    string command;        // operation to be executed

    ItemType item;
    TreeType tree;
    int numCommands;


    // Prompt for file names, read file names, and prepare files
    /*
    * 입력파일 : TreeType.in
    * 출력파일 : TreeType.out
    * command
    *   1. InsertItem
    *   2. DeleteItem
    *   3. IsEmpty
    *   4. IsFull
    *   5. IsBST
    *   6. LeafCount
    *   7. SingleParentCount
    *   8. Print
    *   9. Quit
    */
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
                tree.InsertItem(item);
            }
            else if (command == "DeleteItem")
            {
                inFile >> item;
                tree.DeleteItem(item);
            }
            else if (command == "IsEmpty")
                if (tree.IsEmpty())
                    outFile << "Tree is empty." << endl;
                else
                    outFile << "Tree is not empty." << endl;

            else if (command == "IsFull")
                if (tree.IsFull())
                    outFile << "Tree is full." << endl;
                else outFile << "Tree is not full." << endl;
            else if (command == "IsBST")
                if (tree.IsBST())
                    outFile << "Tree is BST." << endl;
                else
                    outFile << "Tree is not BST." << endl;
            else if (command == "LeafCount")
                outFile << "Tree has " << tree.LeafCount() << " leaf nodes." << endl;
            else if (command == "SingleParentCount")
                outFile << "Tree has " << tree.SingleParentCount() << " single parent nodes." << endl;
            else if (command == "Print")
            {
                tree.Print(outFile);
                outFile << endl;
            }
        }
        catch (exception)
        {
            outFile << "Tree exception thrown." << endl;
        }

        numCommands++;
        cout << " Command number " << numCommands << " completed."
            << endl;
        inFile >> command;

    };

    cout << "Testing completed." << endl;
    inFile.close();
    outFile.close();
    return 0;
}