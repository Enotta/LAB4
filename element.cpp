#include "element.h"

// §¬§à§ß§ã§ä§â§å§Ü§ä§à§â§í §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ
element::element(int value) : value(value), next(nullptr) {};

// §¬§à§ß§ã§ä§â§å§Ü§ä§à§â§í §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ
element_k::element_k(int key, int value) : key(key), value(value), next(nullptr) {};

// §¬§à§ß§ã§ä§â§å§Ü§ä§à§â§í §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ
element_k_bi::element_k_bi(int key, int value) : key(key), value(value), previous(nullptr), next(nullptr) {};

// §¬§à§ß§ã§ä§â§å§Ü§ä§à§â§í §ï§Ý§Ö§Þ§Ö§ß§ä§Ñ §ã§á§Ú§ã§Ü§Ñ
element_k2_bi::element_k2_bi(int key1, int key2, int value) : key1(key1), key2(key2), value(value), previous(nullptr), next(nullptr) {};