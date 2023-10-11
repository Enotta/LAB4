#include "linear.h"
#include "element.h"
#include <iostream>

using namespace std;

// ����ߧ����ܧ��� �� �է֧����ܧ��� linear-���ڧ�ܧ�
linear::linear() : head(nullptr), tail(nullptr) {};
linear::~linear()
{
	// �����ӧ֧�ܧ� �ߧ� ��������
	if (head == nullptr)
	{
		cout << "����ڧ��� �����!" << endl;
		return;
	}

	// �������� ��� ��֧�ӧ�ԧ� �է� ����ݧ֧էߧ֧ԧ� �� ��էѧݧ֧ߧڧ� ��֧�֧� �ӧ�֧ާ֧ߧߧ�� ��֧�֧ާ֧ߧߧ��
	element_k2_bi* current = head;
	while (current != tail)
	{
		element_k2_bi* temp = current;
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
void linear::add(int _key1, int _key2, int _value)
{
	element_k2_bi* newElem = new element_k2_bi(_key1, _key2, _value);

	if (head == nullptr)
	{
		head = newElem;
		tail = newElem;
		return;
	}

	if (tail->key1 < newElem->key1 || (tail->key1 == newElem->key1 && tail->key2 <= newElem->key2))
	{
		tail->next = newElem;
		newElem->previous = tail;
		tail = newElem;
		return;
	}

	element_k2_bi* current = head; // �����ҧ֧� ��� ���ڧ�ܧ�
	while (current->next
		!= nullptr && (current->next->key1 < newElem->key1 || (current->next->key1 == newElem->key1 && current->next->key2 <= newElem->key2)))
	{
		current = current->next;
	}

	if (current->key1 > newElem->key1 || (current->key1 == newElem->key1 && current->key2 >= newElem->key2))
	{
		newElem->next = current;
		current->previous = newElem;
		head = newElem;
	}
	else
	{
		newElem->next = current->next;
		current->next->previous = newElem;
		current->next = newElem;
		newElem->previous = current;
	}
}

/// <summary>
/// ���էѧݧ֧ߧڧ� ��ݧ֧ާ֧ߧ�� �ڧ� ���ڧ�ܧ� ��� �٧ߧѧ�֧ߧڧ�
/// </summary>
/// <param name="_value"></param>
void linear::pop(int _value)
{
	// �����ӧ֧�ܧ� �ߧ� ��������
	if (head == nullptr)
	{
		cout << "����ڧ��� �����!" << endl;
		return;
	}

	// ���ӧ� ��֧�ާ֧ߧߧ�� �էݧ� ��է�ҧ��ӧ� ��ҧ�ѧ�֧ߧڧ� (�ڧ� �էӧ� ��ѧ� �ܧѧ� ���ڧ��� ��էߧ��ӧ�٧ߧ��)
	element_k2_bi* temp;
	element_k2_bi* current = head;

	if (current->value == _value)
	{
		temp = current;
		head = current->next;

		head->previous = nullptr;
		delete temp;

		return;
	}

	while (current != tail) // �����ҧ֧� ��� ���ڧ�ܧ�
	{
		if (current->value == _value)
		{
			temp = current;

			current->next->previous = current->previous;
			current->previous->next = current->next;

			delete temp;

			return;
		}

		current = current->next;
	}
}

/// <summary>
/// ���ѧ��اէ֧ߧڧ� ��֧�ӧ�ԧ� �ӧ��اէ֧ߧڧ� ��ݧ֧ާ֧ߧ�� ��� �٧ߧѧ�֧ߧڧ�
/// </summary>
/// <param name="_value"></param>
/// <returns></returns>
element_k2_bi* linear::find(int _value)
{
	// �����ӧ֧�ܧ� �ߧ� ��������
	if (head == nullptr)
	{
		return nullptr;
	}

	element_k2_bi* current = head;
	while (current != tail) // �����ҧ֧� ��� ���ڧ�ܧ�
	{
		if (current->value == _value)
		{
			return current;
		}

		current = current->next;
	}

	if (tail->value == _value) // �����ӧ֧�ܧ� ��ӧ����
	{
		return tail;
	}

	return nullptr;
}

/// <summary>
/// ����է��ק� �ܧ�ݧڧ�֧��ӧ� ��ݧ֧ާ֧ߧ��� �٧ѧէѧߧߧ�ԧ� �٧ߧѧ�֧ߧڧ�
/// </summary>
/// <param name="_value"></param>
int linear::count(int _value)
{
	// �����ӧ֧�ܧ� �ߧ� ��������
	if (head == nullptr)
	{
		return 0;
	}

	int count = 0;

	element_k2_bi* current = head;
	while (current != tail) // �����ҧ֧� ��� ���ڧ�ܧ�
	{
		if (current->value == _value)
		{
			count++;
		}

		current = current->next;
	}

	if (tail->value == _value) // �����ӧ֧�ܧ� ��ӧ����
	{
		count++;
	}

	return count;
}

/// <summary>
/// ����ӧ�� ���ڧ�ܧ� �� �ߧѧ�ѧݧ� �� �է� �ܧ�ߧ��
/// </summary>
void linear::prints()
{
	// �����ӧ֧�ܧ� �ߧ� ��������
	if (head == nullptr)
	{
		cout << "����ڧ��� �����!" << endl;
		return;
	}

	element_k2_bi* currentHead = head;

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
void linear::printf()
{
	// �����ӧ֧�ܧ� �ߧ� ��������
	if (head == nullptr)
	{
		cout << "����ڧ��� �����!" << endl;
		return;
	}

	element_k2_bi* current = tail;
	while (current->previous != nullptr) // �����ҧ֧� ��� ���ڧ�ܧ� �� �٧ѧէ� �ߧ� ��֧�֧�
	{
		cout << current->value << " ";
		current = current->previous;
	}

	cout << current->value << endl;
}

/// <summary>
/// ���֧ާ�ߧ���ѧ�ڧ� ��ѧҧ���
/// </summary>
void linear::display()
{
	int key1;
	int key2;

	int value;

	linear* lst = new linear();

	cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� �ܧݧ�� #1 ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
	cin >> key1;
	cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� �ܧݧ�� #2 ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
	cin >> key2;
	cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� �٧ߧѧ�֧ߧڧ� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
	cin >> value;
	while (key1 != 0 && key2 != 0 && value != 0)
	{
		lst->add(key1, key2, value);

		cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� �ܧݧ�� #1 ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
		cin >> key1;
		cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� �ܧݧ�� #2 ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
		cin >> key2;
		cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� �٧ߧѧ�֧ߧڧ� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
		cin >> value;
	}

	// ���֧ާ�ߧ���ѧ�ڧ� ��ѧҧ��� �ާ֧��է�� fifo- �ܧݧѧ���
	cout << "�����ާ�� �ӧ�ӧ��: ";
	lst->prints();

	cout << "���ҧ�ѧ�ߧ�� �ӧ�ӧ��: ";
	lst->printf();

	cout << endl << "���ӧ֧էڧ�� ���֧�֧էߧ�� �٧ߧѧ�֧ߧڧ� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ� �էݧ� ��էѧݧ֧ߧڧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
	cin >> value;
	while (value != 0)
	{
		lst->pop(value);

		cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� �٧ߧѧ�֧ߧڧ� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ� �էݧ� ��էѧݧ֧ߧڧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
		cin >> value;
	}

	cout << "�����ާ�� �ӧ�ӧ��: ";
	lst->prints();

	cout << "���ҧ�ѧ�ߧ�� �ӧ�ӧ��: ";
	lst->printf();

	cout << endl << "���ӧ֧էڧ�� ���֧�֧էߧ�� �٧ߧѧ�֧ߧڧ� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ� �էݧ� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
	cin >> value;
	while (value != 0)
	{
		cout << lst->find(value) << endl;

		cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� �٧ߧѧ�֧ߧڧ� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ� �էݧ� ���ڧ�ܧ� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
		cin >> value;
	}

	cout << endl << "���ӧ֧էڧ�� ���֧�֧էߧ�� �٧ߧѧ�֧ߧڧ� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ� �էݧ� ���է��ק�� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
	cin >> value;
	while (value != 0)
	{
		cout << lst->count(value) << endl;

		cout << "���ӧ֧էڧ�� ���֧�֧էߧ�� �٧ߧѧ�֧ߧڧ� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ� �էݧ� ���է��ק�� (0 - ���֧ܧ�ѧ�֧ߧڧ� �ӧӧ�է�) ";
		cin >> value;
	}

	delete lst;
}