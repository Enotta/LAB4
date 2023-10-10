#include "autosort.h"
#include "element.h"
#include <iostream>

using namespace std;

// ����ߧ����ܧ��� �� �է֧����ܧ��� autosort-���ڧ�ܧ�
autosort::autosort() : head(nullptr), tail(nullptr) {};
autosort::~autosort()
{
	element_k* current = head;
	while (current != tail)
	{
		element_k* temp = current;
		current = current->next;

		delete temp;
	}

	delete tail;

	cout << "OK" << endl;
}

/// <summary>
/// ����ҧѧӧݧ֧ߧڧ� ��ݧ֧ާ֧ߧ�� �� ���ڧ���
/// </summary>
/// <param name="_value"></param>
void autosort::add(int _key, int _value)
{
	element_k* newElem = new element_k(_key, _value);

	if (head == nullptr)
	{
		head = newElem;
		tail = newElem;
		return;
	}
	else if (tail->key < newElem->key)
	{
		tail->next = newElem;
		tail = newElem;
		return;
	}

	element_k* current = head;
	while (current->next != nullptr && current->next->key < _key)
	{
		current = current->next;
	}

	if (current->key >= newElem->key)
	{
		newElem->next = current;
		if (current == head)
		{
			head = newElem;
		}
	}
	else
	{
		newElem->next = current->next;
		current->next = newElem;
	}
}

/// <summary>
/// ���էѧݧ֧ߧڧ� ��ݧ֧ާ֧ߧ�� �ڧ� ���ڧ�ܧ� ��� �٧ߧѧ�֧ߧڧ�
/// </summary>
/// <param name="_value"></param>
void autosort::pop(int _value)
{
	element_k* first = head;
	element_k* second = first->next;

	if (first->value == _value)
	{
		head = second;
		delete first;

		return;
	}

	while (second != tail)
	{
		if (second->value == _value)
		{
			first->next = second->next;
			delete second;

			return;
		}

		first = first->next;
		second = first->next;
	}

	if (second->value == _value)
	{
		tail = first;
		tail->next = nullptr;

		delete second;
	}
}

/// <summary>
/// ���ѧ��اէ֧ߧڧ� ��֧�ӧ�ԧ� �ӧ��اէ֧ߧڧ� ��ݧ֧ާ֧ߧ�� ��� �٧ߧѧ�֧ߧڧ�
/// </summary>
/// <param name="_value"></param>
/// <returns></returns>
element_k* autosort::find(int _value)
{
	element_k* current = head;
	while (current != tail)
	{
		if (current->value == _value)
		{
			return current;
		}

		current = current->next;
	}

	if (tail->value == _value)
	{
		return tail;
	}

	return nullptr;
}

/// <summary>
/// ����է��ק� �ܧ�ݧڧ�֧��ӧ� ��ݧ֧ާ֧ߧ��� �٧ѧէѧߧߧ�ԧ� �٧ߧѧ�֧ߧڧ�
/// </summary>
/// <param name="_value"></param>
int autosort::count(int _value)
{
	int count = 0;

	element_k* current = head;
	while (current != tail)
	{
		if (current->value == _value)
		{
			count++;
		}

		current = current->next;
	}

	if (tail->value == _value)
	{
		count++;
	}

	return count;
}

/// <summary>
/// ����ӧ�� ���ڧ�ܧ� �� �ߧѧ�ѧݧ� �� �է� �ܧ�ߧ��
/// </summary>
void autosort::prints()
{
	element_k* currentHead = head;

	while (currentHead != tail)
	{
		cout << currentHead->value << " ";
		currentHead = currentHead->next;
	}

	cout << currentHead->value << endl;
}

/// <summary>
/// ����ӧ�� �� �ܧ�ߧ�� �� �է� �ߧѧ�ѧݧ� (��֧ܧ���ڧӧߧ�)
/// </summary>
/// <param name="current"></param>
void autosort::printf(element_k* current = nullptr)
{
	if (current == nullptr)
	{
		current = head;
	}

	if (current != tail)
	{
		printf(current->next);
	}

	if (current != head)
	{
		cout << current->value << " ";
	}
	else
	{
		cout << current->value << endl;
	}
}

/// <summary>
/// ���֧ާ�ߧ���ѧ�ڧ� ��ѧҧ���
/// </summary>
void autosort::display()
{
	int key;
	int value;
	autosort* lst = new autosort();

	cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� �ܧݧ�� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
	cin >> key;
	cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� �٧ߧѧ�֧ߧڧ� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
	cin >> value;
	
	while (key != 0 && value != 0)
	{
		lst->add(key, value);

		cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� �ܧݧ�� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
		cin >> key;
		cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� �٧ߧѧ�֧ߧڧ� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
		cin >> value;
	}

	// ���֧ާ�ߧ���ѧ�ڧ� ��ѧҧ��� �ާ֧��է�� fifo- �ܧݧѧ���
	cout << "�����ާ�� �ӧ�ӧ��: ";
	lst->prints();

	cout << "���ҧ�ѧ�ߧ�� �ӧ�ӧ��: ";
	lst->printf(0);

	cout << "���ӧ֧էڧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ�, �ܧ������ ����ڧ�� ��էѧݧڧ�� ";
	cin >> value;
	lst->pop(value);

	cout << "�����ާ�� �ӧ�ӧ��: ";
	lst->prints();

	cout << "���ҧ�ѧ�ߧ�� �ӧ�ӧ��: ";
	lst->printf(0);

	cout << "���ӧ֧էڧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ�, �ܧ������ ����ڧ�� �ߧѧۧ�� ";
	cin >> value;
	cout << lst->find(value) << endl;

	cout << "���ӧ֧էڧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ�, �ܧ�ݧڧ�֧��ӧ� �ܧ������ ����ڧ�� �����ڧ�ѧ�� ";
	cin >> value;
	cout << lst->count(value) << endl;

	delete lst;
}