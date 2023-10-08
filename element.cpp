#include "element.h"

// §¬§à§ß§ã§ä§â§å§Ü§ä§à§â§í §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ
element::element(int value) : value(value), next(nullptr) {};
element::element(int value, element* next) : value(value), next(next) {};