#include <iostream>

using namespace std;

#pragma once

/// <summary>
/// ���ߧڧӧ֧��ѧݧ�ߧ�� ��ݧ֧ާ֧ߧ� �էݧ� lifo\fifo ���ڧ�ܧ�� �ݧѧҧ��ѧ���ߧ�� ��ѧҧ���
/// </summary>
struct element
{
	int value;

	element* next;

	element(int value);
};

/// <summary>
/// ���ݧ֧ާ֧ߧ� �� �ܧݧ����
/// </summary>
struct element_k
{
	int key;
	int value;

	element_k* next;

	element_k(int key, int value);
};

/// <summary>
/// ���ݧ֧ާ֧ߧ� �� �ܧݧ���� (�էӧ��ӧ�٧ߧ��)
/// </summary>
struct element_k_bi
{
	int key;
	int value;

	element_k_bi* previous;
	element_k_bi* next;

	element_k_bi(int key, int value);
};

/// <summary>
/// ���ݧ֧ާ֧ߧ� �� �ܧݧ��ѧާ� (�էӧ��ӧ�٧ߧ��)
/// </summary>
struct element_k2_bi
{
	int key1;
	int key2;
	
	int value;

	element_k2_bi* previous;
	element_k2_bi* next;

	element_k2_bi(int key1, int key2, int value);
};

