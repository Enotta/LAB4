#include <iostream>

using namespace std;

#pragma once

/// <summary>
/// §µ§ß§Ú§Ó§Ö§â§ã§Ñ§Ý§î§ß§í§Û §ï§Ý§Ö§Þ§Ö§ß§ä §Õ§Ý§ñ lifo\fifo §ã§á§Ú§ã§Ü§à§Ó §Ý§Ñ§Ò§à§â§Ñ§ä§à§â§ß§à§Û §â§Ñ§Ò§à§ä§í
/// </summary>
struct element
{
	int value;

	element* next;

	element(int value);
};

/// <summary>
/// §¿§Ý§Ö§Þ§Ö§ß§ä §ã §Ü§Ý§ð§é§à§Þ
/// </summary>
struct element_k
{
	int key;
	int value;

	element_k* next;

	element_k(int key, int value);
};

/// <summary>
/// §¿§Ý§Ö§Þ§Ö§ß§ä §ã §Ü§Ý§ð§é§à§Þ (§Õ§Ó§å§ã§Ó§ñ§Ù§ß§í§Û)
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
/// §¿§Ý§Ö§Þ§Ö§ß§ä §ã §Ü§Ý§ð§é§Ñ§Þ§Ú (§Õ§Ó§å§ã§Ó§ñ§Ù§ß§í§Û)
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

