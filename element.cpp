#include "element.h"

// ����ߧ����ܧ���� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ�
element::element(int value) : value(value), next(nullptr) {};

// ����ߧ����ܧ���� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ�
element_k::element_k(int key, int value) : key(key), value(value), next(nullptr) {};

// ����ߧ����ܧ���� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ�
element_k_bi::element_k_bi(int key, int value) : key(key), value(value), previous(nullptr), next(nullptr) {};