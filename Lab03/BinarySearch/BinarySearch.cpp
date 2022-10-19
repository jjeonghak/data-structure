
// A. BinarySearch
int BinarySearch(int array[], int sizeOfArray, int value) {
	int l = 0;
	int r = sizeOfArray - 1;
	while (l <= r) {
		int mid = ((long long)l + r) / 2;
		if (value > array[mid])
			l = mid + 1;
		else if (value < array[mid])
			r = mid - 1;
		else
			return mid;
	}
	return -1;
}


/*
// B. BinarySearch
int BinarySearch(int array[], int sizeOfArray, int value) {
	int l = 0;
	int r = sizeOfArray - 1;
	int mid = 0;
	while (l < r) {
		mid = ((long long)l + r) / 2;
		if (value > array[mid])
			l = mid + 1;
		else if (value < array[mid])
			r = mid - 1;
		else
			return array[mid];
	}
	if (value >= array[r])
		return array[r];
	else
		return -1;
}
*/

/*
// C. BinarySearch
int BinarySearch(int array[], int sizeOfArray, int value) {
	int l = 0;
	int r = sizeOfArray - 1;
	int mid = 0;
	while (l < r) {
		mid = ((long long)l + r) / 2;
		if (value > array[mid])
			l = mid + 1;
		else
			r = mid;
	}
	if (value <= array[r])
		return array[r];
	else
		return -1;
}
*/