#include "predef.h"
#include "queue.h"
#include "stack.h"
#include "LSDRadixSort.h"
#include <stdio.h>

DEFINE_QUEUE(int)
DEFINE_STACK(int)
DEFINE_QUEUE(short)
DEFINE_STACK(short)
DEFINE_QUEUE(uLLong)
DEFINE_STACK(uLLong)

void uint_LSDRadixSort(int list[], uLLong length){
    int factor = 1;
    int max_value = 0;
    int max_digit = 0;
    for (uLLong i = 0; i < length; i++) if(list[i] > max_value) max_value = list[i];
    for (int i = max_value; i > 0; i /= 10) max_digit++;
    
    STACK(int) bucket1 = NEW_STACK(int);
    QUEUE(int) bucket2 = NEW_QUEUE(int);
    
    for (int i = 0; i < max_digit; i++){

        for (int j = 0; j < 10; j++){
            for (uLLong k = 0; k < length; k++){
                if (list[k] < 0){
                    if((int)(list[k] * -1/factor)%10==j){
                        PUSH(int)(bucket1, list[k]);
                    }
                }
                else {
                    if((int)(list[k]/factor)%10==j){
                        ENQUEUE(int)(bucket2, list[k]);
                    }
                }                
            }
        }
        factor = factor * 10;
        for (uLLong i = 0; i < length; i++){
            if(!IS_EMPTY_STACK(int)(bucket1))   list[i] = POP(int)(bucket1);
            else list[i] = DEQUEUE(int)(bucket2);            
        }
    }
    DELETE_STACK(int)(bucket1);
    DELETE_QUEUE(int)(bucket2);
}