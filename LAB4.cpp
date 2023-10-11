#include <iostream>
#include <string>
#include "fifo.h"
#include "lifo.h"
#include "autosort.h"
#include "bi_autosort.h"
#include "linear.h"
#include "tree.h"

using namespace std;

int main()
{	
	unsigned short decision;

	cout << "С чем вы хотите работать\n"
		 << "1 - fifo\n"
		 << "2 - lifo\n"
		 << "3 - autosort\n"
		 << "4 - bi_autosort\n"
		 << "5 - linear\n"
		 << "6 - tree\n"
		 << "-> ";
	cin >> decision;

	switch (decision)
	{
	case 1:
		fifo::display();
		break;
	case 2:
		lifo::display();
		break;
	case 3:
		autosort::display();
		break;
	case 4:
		bi_autosort::display();
		break;
	case 5:
		linear::display();
		break;
	case 6:
		tree::display();
		break;
	default:
		cout << "Неправильный ввод!";
		break;
	}
}