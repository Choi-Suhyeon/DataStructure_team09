#include "predef.h"

typedef unsigned char uChar;
typedef unsigned short uShort;
typedef unsigned int uInt;
typedef long long LLong;

void LLong_LSDRadixSort(LLong seq[], uLLong length);
void Int_LSDRadixSort(int seq[], uLLong length);
void Short_LSDRadixSort(short seq[], uLLong length);
void Char_LSDRadixSort(char seq[], uLLong length);
void uLLong_LSDRadixSort(uLLong seq[], uLLong length);
void uInt_LSDRadixSort(uInt seq[], uLLong length);
void uShort_LSDRadixSort(uShort seq[], uLLong length);
void uChar_LSDRadixSort(uChar seq[], uLLong length);