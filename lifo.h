#include <string>
#include "element.h"

using namespace std;

#pragma once

class lifo
{
private:
	element* head; // ����ݧ�ӧ� - ��֧�ӧ�� ��ݧ֧ާ֧ߧ�
	element* tail; // ���ӧ��� -  ����ݧ֧էߧڧ� ��ݧ֧ާ֧ߧ�

public:
	lifo();
	~lifo();

	void add(int _value);
	void pop(int _value);

	element* find(int _value);
	int count(int _value);

	void prints();
	void printf(element* current);

	static void display();
};