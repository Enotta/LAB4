#include <iostream>
#include <string>
#include "fifo.h"

using namespace std;

int main()
{	
	
	int value = -1;
	fifo* lst = new fifo();

	cout << "Введите очередной элемент списка (0 - прекращение ввода) ";
	cin >> value;
	while (value != 0)
	{
		lst->add(value);

		cout << "Введите очередной элемент списка (0 - прекращение ввода) ";
		cin >> value;
	}

	// Демонстрация работы методов fifo- класса
	lst->prints();
	lst->printf(0);

	lst->pop(3);
	lst->pop(4);

	lst->prints();

	cout << lst->find(2) << endl;
	cout << lst->find(3) << endl;

	cout << lst->count(2) << endl;
	cout << lst->count(3) << endl;

	delete lst;
}