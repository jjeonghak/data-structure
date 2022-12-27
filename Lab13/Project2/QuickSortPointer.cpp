#include "QuickSortPointer.h"

void Split(Student *values[], int first, int last, int& splitPoint) {
	Student *splitVal = values[first];
	int saveFirst = first;
	bool onCorrectSide;

	first++;
	do {
		onCorrectSide = true;
		while (onCorrectSide) {
			if (*values[first] > *values[saveFirst])
				onCorrectSide = false;
			else {
				first++;
				onCorrectSide = first <= last;
			}
		}
		onCorrectSide = first <= last;
		while (onCorrectSide) {
			if (*values[last] < *values[saveFirst])
				onCorrectSide = false;
			else {
				last--;
				onCorrectSide = first <= last;
			}
		}
		if (first < last) {
			Swap(values[first], values[last]);
			first++;
			last--;
		}
	} while (first <= last);

	splitPoint = last;
	Swap(values[saveFirst], values[splitPoint]);
}

void QuickSortPointer(Student *values[], int first, int last) {
	
	if (first < last) {
		int splitPoint;

		Split(values, first, last, splitPoint);

		QuickSortPointer(values, first, splitPoint - 1);
		QuickSortPointer(values, splitPoint + 1, last);
	}
}