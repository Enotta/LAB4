#include "element.h"

// ����ߧ����ܧ���� ��ݧ֧ާ֧ߧ�� ���ڧ�ܧ�
element::element(int value) : value(value), next(nullptr) {};
element::element(int value, element* next) : value(value), next(next) {};