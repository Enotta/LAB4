#include <string>
#include "element.h"

using namespace std;

#pragma once

class autosort
{
private:
	element_k* head; // ����ݧ�ӧ� - ��֧�ӧ�� ��ݧ֧ާ֧ߧ�
	element_k* tail; // ���ӧ��� -  ����ݧ֧էߧڧ� ��ݧ֧ާ֧ߧ�

public:
	autosort();
	~autosort();

	void add(int _key, int _value);
	void pop(int _value);

	element_k* find(int _value);
	int count(int _value);

	void prints();
	void printf(element_k* current);

	static void display();
};