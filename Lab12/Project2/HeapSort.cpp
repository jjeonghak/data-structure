template <class ItemType>
static void Swap(ItemType& one, ItemType& two)
{
    ItemType temp;
    temp = one;
    one = two;
    two = temp;
}

template<class ItemType>
void ReheapDown(ItemType values[], int root, int bottom)
// Post: Heap property is restored.
{
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;
    if (leftChild <= bottom)
    {
        if (leftChild == bottom)
            maxChild = leftChild;
        else
        {
            if (values[leftChild] <= values[rightChild])
                maxChild = rightChild;
            else
                maxChild = leftChild;
        }
        if (values[root] < values[maxChild])
        {
            Swap(values[root], values[maxChild]);
            ReheapDown(values, maxChild, bottom);
        }
    }
}

template <class ItemType>
void HeapSort(ItemType values[], int numValues) {
	for (int index = numValues / 2 - 1; index >= 0; index--)
		ReheapDown(values, index, numValues - 1);
	for (int index = numValues - 1; index >= 1; index--) {
		Swap(values[0], values[index]);
		ReheapDown(values, 0, index - 1);
	}
}

template <class ItemType>
int GetHeight(ItemType values[], int start, int numValues) {
    if (numValues < start * 2 + 1)
        return 0;
    int l_height = GetHeight(values, start * 2 + 1, numValues);
    int r_height = GetHeight(values, start * 2 + 2, numValues);
    return l_height < r_height ? r_height + 1 : l_height + 1;
}

template <class ItemType>
int GetHeightSum(ItemType values[], int numValues) {
    int index, sum = 0;

    for (index = 0; index < numValues; index++)
        sum += GetHeight(values, index, numValues - 1);
    return sum;
}