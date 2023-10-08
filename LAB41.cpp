#include <iostream>
#include <string>
#include "fifo.h"

using namespace std;

int main()
{	
	int value;
	fifo lst = fifo();

	do
	{
		cout << "Введите очередной элемент списка (0 - прекращение ввода) ";
		cin >> value;

		lst.add(value);
	} while (value != 0);

	lst.prints();
	lst.pop(3);
	//lst.pop(4);
	cout << endl;
	lst.prints();

	lst.~fifo();

	lst.prints();
}