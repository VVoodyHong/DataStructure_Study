#include <iostream>
#include <deque>
using namespace std;
int main()
{
	deque<int> my;

	my.push_front(3);
	my.push_front(5);
	cout << "front : " << my.front() << endl;
	my.pop_front();
	my.push_back(7);
	cout << "back : " << my.back() << endl;
	my.pop_front();
	my.pop_back();

	return 1;
}
