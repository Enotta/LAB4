#include <string>

using namespace std;

#pragma once

/// <summary>
/// ���ߧڧӧ֧��ѧݧ�ߧ�� ��ݧ֧ާ֧ߧ� �էݧ� �ݧ�ҧ�� ���ڧ�ܧ�� �ݧѧҧ��ѧ���ߧ�� ��ѧҧ���
/// </summary>
struct element
{
	int value;
	element* next;

	element(int value);
	element(int value, element* next);
};

class fifo
{
private:
	element* head;
	element* tail;

public:
	fifo();
	~fifo();

	void add(int _value);
	void pop(int _value);

	element* find(int _value);
	int count(int _value);

	void prints();
	void printf(element* current);
};