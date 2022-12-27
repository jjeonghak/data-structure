#include "InsertionSort.h"

static bool compareToStudentName(Student a, Student b) {
	if (strcmp(a.getName(), b.getName()) <= 0)
		return false;
	return true;
}

static void InsertItem(Student values[], int startIndex, int endIndex) {
	bool finished = false;
	bool moreTosearch = endIndex != startIndex;
	int current = endIndex;

	while (moreTosearch && !finished) {
		if (compareToStudentName(values[current - 1], values[current])) {
			Swap(values[current - 1], values[current]);
			current--;
			moreTosearch = current != startIndex;
		}
		else
			finished = true;
	}
}

void InsertionSort(Student ary[], int numElems) {
	for (int count = 0; count < numElems; count++) {
		InsertItem(ary, 0, count);
	}
}