#include "element.h"

// ����ߧ����ܧ���� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ�
element::element(int value) : value(value), next(nullptr) {};
element::element(int value, element* next) : value(value), next(next) {};

// ����ߧ����ܧ���� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ�
element_k::element_k(int key, int value) : key(key), value(value), next(nullptr) {};
element_k::element_k(int key, int value, element_k* next) : key(key), value(value), next(next) {};