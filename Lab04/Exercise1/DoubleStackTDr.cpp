// Test driver
#include "DoubleStack.hpp"

using namespace std;

int main()
{

    ifstream inFile;       // file containing operations
    ofstream outFile;      // file containing output
    string inFileName;     // input file external name
    string outFileName;    // output file external name
    string outputLabel;
    string command;        // operation to be executed

    int item;
    DoubleStack doubleStack;
    int numCommands;


    // Prompt for file names, read file names, and prepare files
    /*
    * 입력파일 : DoubleStack.in
    * 출력파일 : DoubleStack.out
    * command
    *   1. Push
    *   2. IsEmpty
    *   3. IsFull
    *   4. Print
    *   5. Quit
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
            if (command == "Push")
            {
                inFile >> item;
                doubleStack.Push(item);
            }
            /*
            else if (command == "Pop")
                doubleStack.Pop();
            else if (command == "Top")
            {
                item = doubleStack.Top();
                outFile << "Top element is " << item << endl;
            }
            */
            else if (command == "IsEmpty")
                if (doubleStack.IsEmpty())
                    outFile << "Stack is empty." << endl;
                else
                    outFile << "Stack is not empty." << endl;

            else if (command == "IsFull")
                if (doubleStack.IsFull())
                    outFile << "Stack is full." << endl;
                else outFile << "Stack is not full." << endl;
            else if (command == "Print") {
                //파일출력
                doubleStack.Print(outFile);

                //표준출력
                //doubleStack.Print();
            }
        }
        catch (FullStack)
        {
            outFile << "FullStack exception thrown." << endl;
        }

        /*
        catch (EmptyStack)
        {
            outFile << "EmtpyStack exception thrown." << endl;
        }
        */
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
