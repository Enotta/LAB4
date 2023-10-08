#pragma once

/// <summary>
/// ���ߧڧӧ֧��ѧݧ�ߧ�� ��ݧ֧ާ֧ߧ� �էݧ� lifo\fifo ���ڧ�ܧ�� �ݧѧҧ��ѧ���ߧ�� ��ѧҧ���
/// </summary>
struct element
{
	int value;
	element* next;

	element(int value);
	element(int value, element* next);
};

struct element_k
{
	int key;
	int value;
	element_k* next;

	element_k(int key, int value);
	element_k(int key, int value, element_k* next);
};
