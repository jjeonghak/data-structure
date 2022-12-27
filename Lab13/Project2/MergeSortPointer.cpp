#include "MergeSortPointer.h"

void Merge(Student *values[], int leftFirst, int leftLast, int rightFirst, int rightLast) {
	int arySize = rightLast - leftFirst + 1;
	Student** tempArray = new Student*[arySize];

	int index = 0;
	int saveFirst = leftFirst;

	while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
		if (*values[leftFirst] <= *values[rightFirst]) {
			tempArray[index] = values[leftFirst];
			leftFirst++;
		}
		else {
			tempArray[index] = values[rightFirst];
			rightFirst++;
		}
		index++;
	}
	while (leftFirst <= leftLast) {
		tempArray[index] = values[leftFirst];
		leftFirst++;
		index++;
	}
	while (rightFirst <= rightLast) {
		tempArray[index] = values[rightFirst];
		rightFirst++;
		index++;
	}
	for (int valuesIndex = saveFirst; valuesIndex <= rightLast; valuesIndex++)
		values[valuesIndex] = tempArray[valuesIndex - saveFirst];
	delete[] tempArray;
}

void MergeSortPointer(Student *values[], int first, int last) {

	if (first < last) {
		int middle = (first + last) / 2;
		MergeSortPointer(values, first, middle);
		MergeSortPointer(values, middle + 1, last);
		Merge(values, first, middle, middle + 1, last);
	}
}