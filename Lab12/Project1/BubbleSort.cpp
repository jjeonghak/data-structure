#include "BubbleSort.h"

static bool compareToStudentName(Student a, Student b) {
	if (strcmp(a.getName(), b.getName()) <= 0)
		return false;
	return true;
}

static void BubbleUp(Student values[], int startIndex, int endIndex) {
	for (int index = endIndex; index > startIndex; index--) {
		if (compareToStudentName(values[index - 1], values[index]))
			Swap(values[index - 1], values[index]);
	}
}

void BubbleSort(Student ary[], int numElems) {
	int current = 0;

	while (current < numElems - 1) {
		BubbleUp(ary, current, numElems - 1);
		current++;
	}
}