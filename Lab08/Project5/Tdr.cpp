#include<iostream>
#include "UnsortedType.h"

using namespace std;

template <class ItemType>
void printList(NodeType<ItemType>* list);

int main() {
	int item1 = 1;
	int item2 = 13;
	int item3 = 2;
	int item4 = 9;
	int item5 = 19;
	int item6 = 110;
	int item7 = 208;
	int item8 = 2147483647;
	int item9 = 0;
	int item10 = -8;

	UnsortedType<int> list;

	list.InsertItem(item1);
	list.InsertItem(item2);
	list.InsertItem(item3);
	list.InsertItem(item4);
	list.InsertItem(item5);
	list.InsertItem(item6);
	list.InsertItem(item7);
	list.InsertItem(item8);
	list.InsertItem(item9);
	list.InsertItem(item10);

	list.Sort(list.GetListData());
	printList(list.GetListData());
	return 0;
}

template <class ItemType>
void printList(NodeType<ItemType>* list) {
	NodeType<ItemType>* temp;

	temp = list;
	cout << "=====PrintList=====\n";
	while (temp != NULL) {
		cout << temp->info << " ";
		temp = temp->next;
	}
	cout << "\n===================\n";
}