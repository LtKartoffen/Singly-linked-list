// main.cpp -- тест односвязного списка
#include <iostream>
#include "list.h"
using namespace std;
int main()
{
	List <int> first;
	/*first.push_back(5);
	first.push_back(10);
	first.push_back(22);

	cout << first.getSize() << endl;*/

	int numbersCount;
	cin >> numbersCount;

	for (int i = 0; i < numbersCount; i++)
	{
		first.push_back(rand() % 10);
	}



	// Вывод
	for (int i = 0; i < first.getSize(); i++)
	{
		cout << first[i] << " ";
	}
	
	first.pop_front();
	cout << endl;
	// Вывод
	for (int i = 0; i < first.getSize(); i++)
	{
		cout << first[i] << " ";
	}

	return 0;
}