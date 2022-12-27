#include <cstring>
#include <iostream>
using namespace std;
class FullHashTable
{};

template <class ItemType>
class HashTable {
public:
	HashTable();
	~HashTable();
	int Hash(char* key) const;
	void InsertItem(ItemType item);
	void RetrieveItem(ItemType& item, bool& found);

private:
	static const int MAX_ITEMS = 100;

	int length;
	ItemType* info[MAX_ITEMS];
};

template <class ItemType>
HashTable<ItemType>::HashTable() {
	length = 0;
	for (int i = 0; i < MAX_ITEMS; i++)
		info[i] = NULL;
}

template <class ItemType>
HashTable<ItemType>::~HashTable() {
	for (int i = 0; i < MAX_ITEMS; i++)
		if (info[i] != NULL)
			delete info[i];
}

int getIntFromString(char* key) {
	int sum = 0;
	int len = strlen(key);
	if (len % 2 == 1)
		len++;
	for (int i = 0; i < len; i += 2)
		sum = (sum + 100 * key[i] + key[i + 1]) % 19937;
	if (sum < 0)
		sum *= -1;
	return sum;
}

template <class ItemType>
int HashTable<ItemType>::Hash(char* key) const {
	return getIntFromString(key) % MAX_ITEMS;
}

template <class ItemType>
void HashTable<ItemType>::InsertItem(ItemType item) {
	int location;

	if (length == MAX_ITEMS)
		throw FullHashTable();
	location = Hash(item.Key());
	
	while (info[location] != NULL)
		location = (location + 1) % MAX_ITEMS;
	info[location] = new ItemType;
	*info[location] = item;
	length++;
}

template <class ItemType>
void HashTable<ItemType>::RetrieveItem(ItemType& item, bool& found) {
	int location = Hash(item.Key());
	bool moreToSerch = true;

	do {
		if ((info[location] == NULL) || (strcmp(info[location]->Key(), item.Key()) == 0))
			moreToSerch = false;
		else
			location++;
	} while (moreToSerch);
	if (info[location] != NULL)
		found = (*info[location] == item);
	else
		found = false;
	if (found)
		item = *info[location];
}