#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

void MergeSort(void * seq, const unsigned long long type_size, const unsigned long long elem_size, int (*comparator)(const void * x, const void * y)){
    if(elem_size == 1) return;
    
    unsigned long long half = (int)((elem_size) / 2);
    unsigned long long left = elem_size - half;
    
    byte* list = (byte*)seq;
    byte* left_start = list;
    byte* right_start = list + (half * type_size);
    
    MergeSort(left_start, type_size, half, comparator);
    MergeSort(right_start, type_size, left, comparator);
    
    printf("%d %d\n",*(int*)seq, *((int*)seq + (elem_size * type_size)));
}

int icomp(const void *a, const void *b){
    ;
}

int main(){
    int * list =  (int *)malloc(sizeof(int) * 11);
    for (int i = 0; i < 11; i++)    list[i] = 11 - i;

    MergeSort(list, sizeof(int), 11, icomp);
    
}