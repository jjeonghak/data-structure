#pragma once
#include <iostream>
#include <fstream>

using namespace std;

const int MAX_ITEMS = 200;

class FullStack
	// Exception class thrown by Push when stack is full.
{};

class EmptyStack
	// Exception class thrown by Pop and Top when stack is emtpy.
{};

class DoubleStack
{
private:
	int top_small;
	int top_big;
	int items[MAX_ITEMS];
public:
	DoubleStack() {
		top_small = -1;
		top_big = 200;
	}

	bool IsFull() const {
		if (top_big - top_small == 1)
			return true;
		return false;
	}

	bool IsEmpty() const {
		return top_small == -1 && top_big == 200;
	}

	void Push(int item) {
		if (IsFull())
			throw FullStack();
		else {
			if (item > 1000)
				items[--top_big] = item;
			else
				items[++top_small] = item;
		}
	}
	
	void Print() {
		int l = top_small;
		int r = top_big;
		int smallSize = top_small + 1;
		int bigSize = 200 - top_big;
		int totalSize = smallSize + bigSize;

		printf("small stack size : %d\n", smallSize);
		printf("big stack size : %d\n", bigSize);
		printf("total stack size : %d\n", totalSize);

		printf("small stack index : ");
		if (smallSize == 0)
			printf("empty");
		else {
			while (l > -1) {
				printf("%d ", items[l]);
				l--;
			}
		}
		printf("\n");

		printf("big stack index : ");
		if (bigSize == 0)
			printf("empty");
		else {
			while (r < 200) {
				printf("%d ", items[r]);
				r++;
			}
		}
		printf("\n");
	}

	void Print(ofstream& outFile) {
		int l = top_small;
		int r = top_big;
		int smallSize = top_small + 1;
		int bigSize = 200 - top_big;
		int totalSize = smallSize + bigSize;

		outFile << "DoubleStack Info Print" << "\n";
		outFile << "  small stack size : " << smallSize << "\n";
		outFile << "  big stack size : " << bigSize << "\n";
		outFile << "  total stack size : " << totalSize << "\n";

		outFile << "  small stack index : ";
		if (smallSize == 0)
			outFile << "empty";
		else {
			while (l > -1) {
				outFile << items[l] << " ";
				l--;
			}
		}
		outFile << "\n";

		outFile << "  big stack index : ";
		if (bigSize == 0)
			outFile << "empty";
		else {
			while (r < 200) {
				outFile << items[r] << " ";
				r++;
			}
		}
		outFile << "\n";
	}
};