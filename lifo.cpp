#include "lifo.h"
#include "element.h"
#include <iostream>

using namespace std;

// ����ߧ����ܧ��� �� �է֧����ܧ��� lifo-���ڧ�ܧ�
lifo::lifo() : head(nullptr), tail(nullptr) {};
lifo::~lifo()
{
	// �����ӧ֧�ܧ� �ߧ� ��������
	if (head == nullptr)
	{
		cout << "����ڧ��� �����!" << endl;
		return;
	}

	// �������� ��� ��֧�ӧ�ԧ� �է� ����ݧ֧էߧ֧ԧ� �� ��էѧݧ֧ߧڧ� ��֧�֧� �ӧ�֧ާ֧ߧߧ�� ��֧�֧ާ֧ߧߧ��
	element* current = head;
	while (current != tail)
	{
		element* temp = current;
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
void lifo::add(int _value)
{
	element* newElem = new element(_value);

	if (head == nullptr) // ����ݧ� �����
	{
		head = newElem;
		tail = newElem;
	}
	else // ����ҧѧӧݧ֧ߧڧ� �� �ܧ�ߧ֧� ��ӧ����
	{
		newElem->next = head;
		head = newElem;
	}
}

/// <summary>
/// ���էѧݧ֧ߧڧ� ��ݧ֧ާ֧ߧ�� �ڧ� ���ڧ�ܧ� ��� �٧ߧѧ�֧ߧڧ�
/// </summary>
/// <param name="_value"></param>
void lifo::pop(int _value)
{
	// �����ӧ֧�ܧ� �ߧ� ��������
	if (head == nullptr)
	{
		cout << "����ڧ��� �����!" << endl;
		return;
	}

	// ���ӧ� ��֧�ާ֧ߧߧ�� �էݧ� ��է�ҧ��ӧ� ��ҧ�ѧ�֧ߧڧ� (�ڧ� �էӧ� ��ѧ� �ܧѧ� ���ڧ��� ��էߧ��ӧ�٧ߧ��)
	element* first = head;
	element* second = first->next;

	if (first->value == _value) // �����ӧ֧�ܧ� �ߧ� ��էѧݧ֧ߧڧ� �ԧ�ݧ�ӧ�
	{
		head = second;
		delete first;

		return;
	}

	while (second != tail) // �����ҧ֧� ��� ���ڧ�ܧ�
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

	if (second->value == _value) // �����ӧ֧�ܧ� ��ӧ����
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
element* lifo::find(int _value)
{
	// �����ӧ֧�ܧ� �ߧ� ��������
	if (head == nullptr)
	{
		cout << "����ڧ��� �����!" << endl;
		return nullptr;
	}

	element* current = head;
	while (current != tail) // �����ҧ֧� ��� ���ڧ�ܧ�
	{
		if (current->value == _value)
		{
			return current;
		}

		current = current->next;
	}

	if (current->value == _value) // �����ӧ֧�ܧ� ��ӧ����
	{
		return current;
	}

	return nullptr;
}

/// <summary>
/// ����է��ק� �ܧ�ݧڧ�֧��ӧ� ��ݧ֧ާ֧ߧ��� �٧ѧէѧߧߧ�ԧ� �٧ߧѧ�֧ߧڧ�
/// </summary>
/// <param name="_value"></param>
/// <returns></returns>
int lifo::count(int _value)
{
	// �����ӧ֧�ܧ� �ߧ� ��������
	if (head == nullptr)
	{
		cout << "����ڧ��� �����!" << endl;
		return 0;
	}

	int count = 0;

	element* current = head;
	while (current != tail) // �����ҧ֧� ��� ���ڧ�ܧ�
	{
		if (current->value == _value)
		{
			count++;
		}

		current = current->next;
	}

	if (current->value == _value) // �����ӧ֧�ܧ� ��ӧ����
	{
		count++;
	}

	return count;
}

/// <summary>
/// ����ӧ�� ���ڧ�ܧ� �� �ߧѧ�ѧݧ� �� �է� �ܧ�ߧ��
/// </summary>
void lifo::prints()
{
	// �����ӧ֧�ܧ� �ߧ� ��������
	if (head == nullptr)
	{
		cout << "����ڧ��� �����!" << endl;
		return;
	}

	element* currentHead = head;

	while (currentHead != tail) // �����ҧ֧� ��� ���ڧ�ܧ�
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
void lifo::printf(element* current = nullptr)
{
	// �����ӧ֧�ܧ� �ߧ� ��������
	if (head == nullptr)
	{
		cout << "����ڧ��� �����!" << endl;
		return;
	}

	if (current == nullptr)
	{
		current = head;
	}

	if (current != tail) // ���֧ܧ���ڧӧߧ�� �٧ѧ��� �� �ܧ�ߧ֧�
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
void lifo::display()
{
	int value;
	lifo* lst = new lifo();

	cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
	cin >> value;
	while (value != 0)
	{
		lst->add(value);

		cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
		cin >> value;
	}

	// ���֧ާ�ߧ���ѧ�ڧ� ��ѧҧ��� �ާ֧��է�� fifo- �ܧݧѧ���
	cout << "�����ާ�� �ӧ�ӧ��: ";
	lst->prints();

	cout << "���ҧ�ѧ�ߧ�� �ӧ�ӧ��: ";
	lst->printf(0);

	cout << endl << "���ӧ֧էڧ�� ���֧�֧էߧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ� �էݧ� ��էѧݧ֧ߧڧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
	cin >> value;
	while (value != 0)
	{
		lst->pop(value);

		cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ� �էݧ� ��էѧݧ֧ߧڧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
		cin >> value;
	}

	cout << "�����ާ�� �ӧ�ӧ��: ";
	lst->prints();

	cout << "���ҧ�ѧ�ߧ�� �ӧ�ӧ��: ";
	lst->printf(0);

	cout << endl << "���ӧ֧էڧ�� ���֧�֧էߧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ� �էݧ� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
	cin >> value;
	while (value != 0)
	{
		cout << lst->find(value) << endl;

		cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ� �էݧ� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
		cin >> value;
	}

	cout << endl << "���ӧ֧էڧ�� ���֧�֧էߧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ� �էݧ� ���է��ק�� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
	cin >> value;
	while (value != 0)
	{
		cout << lst->count(value) << endl;

		cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� ��ݧ֧ާ֧ߧ� ���ڧ�ܧ� �էݧ� ���է��ק�� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
		cin >> value;
	}

	delete lst;
}