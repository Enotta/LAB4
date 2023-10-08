#pragma once

/// <summary>
/// §µ§ß§Ú§Ó§Ö§â§ã§Ñ§Ý§î§ß§í§Û §ï§Ý§Ö§Þ§Ö§ß§ä §Õ§Ý§ñ lifo\fifo §ã§á§Ú§ã§Ü§à§Ó §Ý§Ñ§Ò§à§â§Ñ§ä§à§â§ß§à§Û §â§Ñ§Ò§à§ä§í
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
