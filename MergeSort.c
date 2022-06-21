#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

void MergeSort(void * seq, const unsigned long long type_size, const unsigned long long length, int (*comparator)(const void * x, const void * y)){
    if(length == 1) return;
    
    unsigned long long half = (unsigned long long)((length) / 2);
    
    byte* list = (byte*)seq;
    byte* left_start = list;
    byte* right_start = list + ((half)* type_size);

    MergeSort(left_start, type_size, half, comparator);
    MergeSort(right_start, type_size, length - half, comparator);

    byte* tmp = (byte*)malloc(length * type_size);

    while(1){
        if (comparator(right_start,left_start) > 0){
            memcpy(tmp, left_start, type_size);
            left_start = left_start + (type_size);
        }
        else{
            memcpy(tmp, right_start, type_size);
            right_start = right_start + (type_size);
        }
        tmp = tmp + (type_size);
        
        if (right_start == (byte*)seq + (half * type_size))
            ;
        else if (right_start == (byte*)seq + (half * type_size))
            ;
    }

}

int icomp(const void *a, const void *b){
    ;
}

int main(){
    int * list =  (int *)malloc(sizeof(int) * 11);
    for (int i = 0; i < 11; i++)    list[i] = i;
    MergeSort(list, sizeof(int), 11, icomp); 
}

