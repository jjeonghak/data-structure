#include <iostream>

using namespace std;

int BinarySearch(int[], int, int);

int main(void) {
	int list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int result = BinarySearch(list, 10, 11);
	cout << result << endl;
	result = BinarySearch(list, 10, 7);
	cout << result << endl;
	return 0;
}