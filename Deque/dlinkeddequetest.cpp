#include <iostream>
#include "dlinkeddeque.h"
using namespace std;
int main()
{
	DLinkedDeque A;
	A.insertFront("Bob");
	A.insertFront("Alice");
	cout << A.front() << endl; A.removeFront();
	cout << A.front() << endl;
	A.insertBack("Eve");
	A.insertBack("Jane");
	cout << A.back() << endl; A.removeBack();
	cout << A.back() << endl;

	return 1;
}