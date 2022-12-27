#include <iostream>
#include <fstream>
#include "TreeType.h"
#include "SortedType.h"
#include "UnsortedType.h"

using namespace std;

int Smaller(TreeType tree, ItemType value);
void AddElement(TreeType& tree, ItemType Array[], int from, int to);
void MakeTree(TreeType& tree, SortedType<ItemType>& list);
bool MatchingItem_Unsorted(TreeType& tree, UnsortedType<ItemType>& list);



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
    *   5. Ancestors
    *   6. Smaller
    *   7. MakeTree
    *   8. MatchingItem
    *   9. Print
    *   10. Quit
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
            else if (command == "Ancestors") {
                inFile >> item;
                cout << endl;
                tree.Ancestors(item);
                tree.Ancestors_re(item);
                cout << "\n\n";
            }
            else if (command == "Smaller") {
                inFile >> item;
                outFile << "Tree has " << Smaller(tree, item) << " items smaller than " << item << endl;
            }
            else if (command == "MakeTree") {
                int size;
                SortedType<ItemType> list;
                inFile >> size;
                for (int i = 0; i < size; i++) {
                    inFile >> item;
                    list.InsertItem(item);
                }
                MakeTree(tree, list);
            }
            else if (command == "MatchingItem") {
                int size;
                UnsortedType<ItemType> list;
                inFile >> size;
                for (int i = 0; i < size; i++) {
                    inFile >> item;
                    list.InsertItem(item);
                }
                if (MatchingItem_Unsorted(tree, list))
                    outFile << "Matched.\n";
                else
                    outFile << "Not matched.\n";
            }
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

int Smaller(TreeType tree, ItemType value) {
    ItemType item;
    bool finished = false;
    int count = 0;

    tree.ResetTree(IN_ORDER);

    do {
        tree.GetNextItem(item, IN_ORDER, finished);
        if (item < value)
            count++;
        else
            finished = true;
    } while (!finished);
    return count;
}

void AddElement(TreeType& tree, ItemType Array[], int from, int to) {
    int mid;
    if (from <= to) {
        mid = (long)(from + to) / 2;
        tree.InsertItem(Array[mid]);
        AddElement(tree, Array, mid + 1, to);
        AddElement(tree, Array, from, mid - 1);
    }
}

void MakeTree(TreeType& tree, SortedType<ItemType>& list) {
    int length = list.LengthIs();
    ItemType* array = new ItemType[length];
    ItemType item_info;

    for (int i = 0; i < length; i++) {
        list.GetNextItem(item_info);
        array[i] = item_info;
    }
    AddElement(tree, array, 0, length - 1);
    delete [] array;
}

bool MatchingItem_Unsorted(TreeType& tree, UnsortedType<ItemType>& list) {
    int list_length = list.LengthIs();
    int tree_length = tree.LengthIs();

    if (list_length != tree_length)
        return false;
    ItemType item;
    bool check;

    list.ResetList();
    for (int i = 0; i < list_length; i++) {
        list.GetNextItem(item);
        tree.RetrieveItem(item, check);
        if (!check)
            return false;
    }
    return true;
}
