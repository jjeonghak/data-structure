#include "SelectionSort.h"

static bool compareToStudentName(Student a, Student b) {
	if (strcmp(a.getName(), b.getName()) <= 0)
		return false;
	return true;
}

static int MinIndex(Student values[], int startIndex, int endIndex) {
	int indexOfMin = startIndex;

	for (int index = startIndex; index <= endIndex; index++) {
		if (compareToStudentName(values[indexOfMin], values[index]))
			indexOfMin = index;
	}
	return indexOfMin;
}

void SelectionSort(Student ary[], int numElems) {
	int endIndex = numElems - 1;

	for (int current = 0; current < endIndex; current++) {
		Swap(ary[current], ary[MinIndex(ary, current, endIndex)]);
	}
}