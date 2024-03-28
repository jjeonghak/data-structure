#include <iostream>
#include "Student.h"
#include "QuickSortPointer.h"
#include "MergeSortPointer.h"

using namespace std;

int main() {
	Student stu[100];
	Student* stuPtrs[10];

	stu[0].InitValue(2003200111, (char*)"�̿���", 3.0);
	stu[1].InitValue(2004200121, (char*)"�ǿ���", 3.2);
	stu[2].InitValue(2005200132, (char*)"������", 2.7);
	stu[3].InitValue(2006200140, (char*)"�ڿϿ�", 4.1);
	stu[4].InitValue(2003200200, (char*)"������", 1.1);
	stu[5].InitValue(2003200209, (char*)"�ڿϿ�", 3.5);
	stu[6].InitValue(2003200210, (char*)"���ϼ�", 0.8);
	stu[7].InitValue(2001200201, (char*)"�̽¿�", 1.8);
	stu[8].InitValue(2007200207, (char*)"������", 3.8);
	stu[9].InitValue(2001200215, (char*)"������", 3.3);

	for (int k = 0; k < 10; k++)
		stuPtrs[k] = &stu[k];
	//QuickSortPointer(stuPtrs, 0, 9);
	MergeSortPointer(stuPtrs, 0, 9);
	cout << "====== Pointer Data =======\n\n";
	PrintByPointer(cout, stuPtrs, 10);
	cout << "\n======= Origin Data =======\n\n";
	Print(cout, stu, 10);
	return 0;
}