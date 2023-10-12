#include <string>
#include "element.h"

using namespace std;

#pragma once

class bi_autosort
{
private:
	element_k_bi* head; // ����ݧ�ӧ� - ��֧�ӧ�� ��ݧ֧ާ֧ߧ�
	element_k_bi* tail; // ���ӧ��� -  ����ݧ֧էߧڧ� ��ݧ֧ާ֧ߧ�

public:
	bi_autosort();
	~bi_autosort();

	void add(int _key, int _value);
	void pop(int _value);

	element_k_bi* find(int _value);
	int count(int _value);

	void prints();
	void printf();

	static void display();
};