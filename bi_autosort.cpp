#include "bi_autosort.h"
#include "element.h"
#include <iostream>

using namespace std;

// §¬§à§ß§ã§ä§â§å§Ü§ä§à§â §Ú §Õ§Ö§ã§ä§â§å§Ü§ä§à§â bi_autosort-§ã§á§Ú§ã§Ü§Ñ
bi_autosort::bi_autosort() : head(nullptr), tail(nullptr) {};
bi_autosort::~bi_autosort()
{
	// §±§â§à§Ó§Ö§â§Ü§Ñ §ß§Ñ §á§å§ã§ä§à§ä§å
	if (head == nullptr)
	{
		cout << "§³§á§Ú§ã§à§Ü §á§å§ã§ä!" << endl;
		return;
	}

	// §±§â§à§ç§à§Õ §à§ä §á§Ö§â§Ó§à§Ô§à §Õ§à §á§à§ã§Ý§Ö§Õ§ß§Ö§Ô§à §Ú §å§Õ§Ñ§Ý§Ö§ß§Ú§Ö §é§Ö§â§Ö§Ù §Ó§â§Ö§Þ§Ö§ß§ß§å§ð §á§Ö§â§Ö§Þ§Ö§ß§ß§å§ð
	element_k_bi* current = head;
	while (current != tail)
	{
		element_k_bi* temp = current;
		current = current->next;

		delete temp;
	}

	delete tail;

	cout << "OK" << endl;
}

/// <summary>
/// §¥§à§Ò§Ñ§Ó§Ý§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §Ó §ã§á§Ú§ã§à§Ü
/// </summary>
/// <param name="_value"></param>
void bi_autosort::add(int _key, int _value)
{
	element_k_bi* newElem = new element_k_bi(_key, _value);

	if (head == nullptr)
	{
		head = newElem;
		tail = newElem;
		return;
	}
	if (tail->key < newElem->key)
	{
		tail->next = newElem;
		newElem->previous = tail;
		tail = newElem;
		return;
	}

	element_k_bi* current = head;
	while (current != nullptr && current->next->key < _key)
	{
		current = current->next;
	}

	if (current->key >= newElem->key)
	{
		newElem->next = current;
		current->previous = newElem;
		head = newElem;
	}
	else
	{
		newElem->next = current->next;
		current->next->previous = newElem;
		current->next = newElem;
		newElem->previous = current;
	}
}

/// <summary>
/// §µ§Õ§Ñ§Ý§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §Ú§Ù §ã§á§Ú§ã§Ü§Ñ §á§à §Ù§ß§Ñ§é§Ö§ß§Ú§ð
/// </summary>
/// <param name="_value"></param>
void bi_autosort::pop(int _value)
{
	// §±§â§à§Ó§Ö§â§Ü§Ñ §ß§Ñ §á§å§ã§ä§à§ä§å
	if (head == nullptr)
	{
		cout << "§³§á§Ú§ã§à§Ü §á§å§ã§ä!" << endl;
		return;
	}

	// §¥§Ó§Ö §á§Ö§â§Þ§Ö§ß§ß§í§Ö §Õ§Ý§ñ §å§Õ§à§Ò§ã§ä§Ó§Ñ §à§Ò§â§Ñ§ë§Ö§ß§Ú§ñ (§Ú§ç §Õ§Ó§Ö §ä§Ñ§Ü §Ü§Ñ§Ü §ã§á§Ú§ã§à§Ü §à§Õ§ß§à§ã§Ó§ñ§Ù§ß§í§Û)
	element_k_bi* temp;
	element_k_bi* current = head;

	if (current->value == _value)
	{
		temp = current;
		head = current->next;

		if (head == nullptr)
		{
			head = nullptr;
			return;
		}

		head->previous = nullptr;
		delete temp;

		return;
	}

	while (current != tail) // §±§â§à§Ò§Ö§Ô §á§à §ã§á§Ú§ã§Ü§å
	{
		if (current->value == _value)
		{
			temp = current;

			current->next->previous = current->previous;
			current->previous->next = current->next;

			delete temp;

			return;
		}

		current = current->next;
	}

	if (current->value == _value)
	{
		temp = current;

		current->previous->next = nullptr;
		tail = current->previous;

		delete temp;
	}
}

/// <summary>
/// §¯§Ñ§ç§à§Ø§Õ§Ö§ß§Ú§Ö §á§Ö§â§Ó§à§Ô§à §Ó§ç§à§Ø§Õ§Ö§ß§Ú§ñ §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §á§à §Ù§ß§Ñ§é§Ö§ß§Ú§ð
/// </summary>
/// <param name="_value"></param>
/// <returns></returns>
element_k_bi* bi_autosort::find(int _value)
{
	// §±§â§à§Ó§Ö§â§Ü§Ñ §ß§Ñ §á§å§ã§ä§à§ä§å
	if (head == nullptr)
	{
		cout << "§³§á§Ú§ã§à§Ü §á§å§ã§ä!" << endl;
		return nullptr;
	}

	element_k_bi* current = head;
	while (current != tail) // §±§â§à§Ò§Ö§Ô §á§à §ã§á§Ú§ã§Ü§å
	{
		if (current->value == _value)
		{
			return current;
		}

		current = current->next;
	}

	if (tail->value == _value) // §±§â§à§Ó§Ö§â§Ü§Ñ §ç§Ó§à§ã§ä§Ñ
	{
		return tail;
	}

	return nullptr;
}

/// <summary>
/// §±§à§Õ§ã§é§×§ä §Ü§à§Ý§Ú§é§Ö§ã§ä§Ó§Ñ §ï§Ý§Ö§Þ§Ö§ß§ä§à§Ó §Ù§Ñ§Õ§Ñ§ß§ß§à§Ô§à §Ù§ß§Ñ§é§Ö§ß§Ú§ñ
/// </summary>
/// <param name="_value"></param>
int bi_autosort::count(int _value)
{
	// §±§â§à§Ó§Ö§â§Ü§Ñ §ß§Ñ §á§å§ã§ä§à§ä§å
	if (head == nullptr)
	{
		cout << "§³§á§Ú§ã§à§Ü §á§å§ã§ä!" << endl;
		return 0;
	}

	int count = 0;

	element_k_bi* current = head;
	while (current != tail) // §±§â§à§Ò§Ö§Ô §á§à §ã§á§Ú§ã§Ü§å
	{
		if (current->value == _value)
		{
			count++;
		}

		current = current->next;
	}

	if (tail->value == _value) // §±§â§à§Ó§Ö§â§Ü§Ñ §ç§Ó§à§ã§ä§Ñ
	{
		count++;
	}

	return count;
}

/// <summary>
/// §£§í§Ó§à§Õ §ã§á§Ú§ã§Ü§Ñ §ã §ß§Ñ§é§Ñ§Ý§Ñ §Ú §Õ§à §Ü§à§ß§è§Ñ
/// </summary>
void bi_autosort::prints()
{
	// §±§â§à§Ó§Ö§â§Ü§Ñ §ß§Ñ §á§å§ã§ä§à§ä§å
	if (head == nullptr)
	{
		cout << "§³§á§Ú§ã§à§Ü §á§å§ã§ä!" << endl;
		return;
	}

	element_k_bi* currentHead = head;

	while (currentHead != tail) // §±§â§à§Ò§Ö§Ô §á§à §ã§á§Ú§ã§Ü§å
	{
		cout << currentHead->value << " ";
		currentHead = currentHead->next;
	}

	cout << currentHead->value << endl;
}

/// <summary>
/// §£§í§Ó§à§Õ §ã §Ü§à§ß§è§Ñ §Ú §Õ§à §ß§Ñ§é§Ñ§Ý§Ñ
/// </summary>
/// <param name="current"></param>
void bi_autosort::printf()
{
	// §±§â§à§Ó§Ö§â§Ü§Ñ §ß§Ñ §á§å§ã§ä§à§ä§å
	if (head == nullptr)
	{
		cout << "§³§á§Ú§ã§à§Ü §á§å§ã§ä!" << endl;
		return;
	}

	element_k_bi* current = tail;
	while (current->previous != nullptr) // §±§â§à§Ò§Ö§Ô §á§à §ã§á§Ú§ã§Ü§å §ã §Ù§Ñ§Õ§Ñ §ß§Ñ §á§Ö§â§Ö§Õ
	{
		cout << current->value << " ";
		current = current->previous;
	}

	cout << current->value << endl;
}

/// <summary>
/// §¥§Ö§Þ§à§ß§ã§ä§â§Ñ§è§Ú§ñ §â§Ñ§Ò§à§ä§í
/// </summary>
void bi_autosort::display()
{
	int key;
	int value;
	bi_autosort* lst = new bi_autosort();

	cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §Ü§Ý§ð§é §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
	cin >> key;
	cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Ö §Ù§ß§Ñ§é§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
	cin >> value;
	while (value != 0)
	{
		lst->add(key, value);

		cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Û §Ü§Ý§ð§é §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
		cin >> key;
		cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Ö §Ù§ß§Ñ§é§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
		cin >> value;
	}

	// §¥§Ö§Þ§à§ß§ã§ä§â§Ñ§è§Ú§ñ §â§Ñ§Ò§à§ä§í §Þ§Ö§ä§à§Õ§à§Ó fifo- §Ü§Ý§Ñ§ã§ã§Ñ
	cout << "§±§â§ñ§Þ§à§Û §Ó§í§Ó§à§Õ: ";
	lst->prints();

	cout << "§°§Ò§â§Ñ§ä§ß§í§Û §Ó§í§Ó§à§Õ: ";
	lst->printf();

	cout << endl << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Ö §Ù§ß§Ñ§é§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ §Õ§Ý§ñ §å§Õ§Ñ§Ý§Ö§ß§Ú§ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
	cin >> value;
	while (value != 0)
	{
		lst->pop(value);

		cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Ö §Ù§ß§Ñ§é§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ §Õ§Ý§ñ §å§Õ§Ñ§Ý§Ö§ß§Ú§ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
		cin >> value;
	}

	cout << "§±§â§ñ§Þ§à§Û §Ó§í§Ó§à§Õ: ";
	lst->prints();

	cout << "§°§Ò§â§Ñ§ä§ß§í§Û §Ó§í§Ó§à§Õ: ";
	lst->printf();

	cout << endl << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Ö §Ù§ß§Ñ§é§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ §Õ§Ý§ñ §á§à§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
	cin >> value;
	while (value != 0)
	{
		cout << lst->find(value) << endl;

		cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Ö §Ù§ß§Ñ§é§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ §Õ§Ý§ñ §á§à§Ú§ã§Ü§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
		cin >> value;
	}

	cout << endl << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Ö §Ù§ß§Ñ§é§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ §Õ§Ý§ñ §á§à§Õ§ã§é§×§ä§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
	cin >> value;
	while (value != 0)
	{
		cout << lst->count(value) << endl;

		cout << "§£§Ó§Ö§Õ§Ú§ä§Ö §à§é§Ö§â§Ö§Õ§ß§à§Ö §Ù§ß§Ñ§é§Ö§ß§Ú§Ö §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ §Õ§Ý§ñ §á§à§Õ§ã§é§×§ä§Ñ (0 - §á§â§Ö§Ü§â§Ñ§ë§Ö§ß§Ú§Ö §Ó§Ó§à§Õ§Ñ) ";
		cin >> value;
	}

	delete lst;
}