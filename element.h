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
