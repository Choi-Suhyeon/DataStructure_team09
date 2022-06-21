
#include "queue.h"
#include "stack.h"
#include "LSDRadixSort.h"
#include <stdio.h>

DEFINE_QUEUE(char)
DEFINE_STACK(char)
DEFINE_QUEUE(uChar)

DEFINE_QUEUE(short)
DEFINE_STACK(short)
DEFINE_QUEUE(uShort)

DEFINE_QUEUE(int)
DEFINE_STACK(int)
DEFINE_QUEUE(uInt)

DEFINE_QUEUE(LLong)
DEFINE_STACK(LLong)
DEFINE_QUEUE(uLLong)

void LLong_LSDRadixSort(LLong list[], uLLong length){
    LLong factor = 1;
    LLong max_value = 0;
    int max_digit = 0;
    for (uLLong i = 0; i < length; i++) if(list[i] > max_value) max_value = list[i];
    for (LLong i = max_value; i > 0; i /= 10) max_digit++;
    
    STACK(LLong) bucket1 = NEW_STACK(LLong);
    QUEUE(LLong) bucket2 = NEW_QUEUE(LLong);
    
    for (int i = 0; i < max_digit; i++){

        for (int j = 0; j < 10; j++){
            for (uLLong k = 0; k < length; k++){
                if (list[k] < 0){
                    if((LLong)(list[k] * -1/factor)%10==j){
                        PUSH(LLong)(bucket1, list[k]);
                    }
                }
                else {
                    if((LLong)(list[k]/factor)%10==j){
                        ENQUEUE(LLong)(bucket2, list[k]);
                    }
                }                
            }
        }
        factor = factor * 10;
        for (uLLong i = 0; i < length; i++){
            if(!IS_EMPTY_STACK(LLong)(bucket1))   list[i] = POP(LLong)(bucket1);
            else list[i] = DEQUEUE(LLong)(bucket2);            
        }
    }
    DELETE_STACK(LLong)(bucket1);
    DELETE_QUEUE(LLong)(bucket2);
}

void Int_LSDRadixSort(int list[], uLLong length){
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

void Short_LSDRadixSort(short list[], uLLong length){
    short factor = 1;
    short max_value = 0;
    int max_digit = 0;
    for (uLLong i = 0; i < length; i++) if(list[i] > max_value) max_value = list[i];
    for (int i = max_value; i > 0; i /= 10) max_digit++;
    
    STACK(short) bucket1 = NEW_STACK(short);
    QUEUE(short) bucket2 = NEW_QUEUE(short);
    
    for (short i = 0; i < max_digit; i++){

        for (int j = 0; j < 10; j++){
            for (uLLong k = 0; k < length; k++){
                if (list[k] < 0){
                    if((short)(list[k] * -1/factor)%10==j){
                        PUSH(short)(bucket1, list[k]);
                    }
                }
                else {
                    if((short)(list[k]/factor)%10==j){
                        ENQUEUE(short)(bucket2, list[k]);
                    }
                }                
            }
        }
        factor = factor * 10;
        for (uLLong i = 0; i < length; i++){
            if(!IS_EMPTY_STACK(short)(bucket1))   list[i] = POP(short)(bucket1);
            else list[i] = DEQUEUE(short)(bucket2);            
        }
    }
    DELETE_STACK(short)(bucket1);
    DELETE_QUEUE(short)(bucket2);
}

void Char_LSDRadixSort(short list[], uLLong length){
    char factor = 1;
    char max_value = 0;
    int max_digit = 0;
    for (uLLong i = 0; i < length; i++) if(list[i] > max_value) max_value = list[i];
    for (int i = max_value; i > 0; i /= 10) max_digit++;
    
    STACK(char) bucket1 = NEW_STACK(char);
    QUEUE(char) bucket2 = NEW_QUEUE(char);
    
    for (char i = 0; i < max_digit; i++){

        for (int j = 0; j < 10; j++){
            for (uLLong k = 0; k < length; k++){
                if (list[k] < 0){
                    if((char)(list[k] * -1/factor)%10==j){
                        PUSH(char)(bucket1, list[k]);
                    }
                }
                else {
                    if((char)(list[k]/factor)%10==j){
                        ENQUEUE(char)(bucket2, list[k]);
                    }
                }                
            }
        }
        factor = factor * 10;
        for (uLLong i = 0; i < length; i++){
            if(!IS_EMPTY_STACK(char)(bucket1))   list[i] = POP(char)(bucket1);
            else list[i] = DEQUEUE(char)(bucket2);            
        }
    }
    DELETE_STACK(char)(bucket1);
    DELETE_QUEUE(char)(bucket2);
}

void uLLong_LSDRadixSort(uLLong list[], uLLong length){
    uLLong factor = 1;
    uLLong max_value = 0;
    int max_digit = 0;
    for (uLLong i = 0; i < length; i++) if(list[i] > max_value) max_value = list[i];
    for (uLLong i = max_value; i > 0; i /= 10) max_digit++;
    
    QUEUE(uLLong) bucket2 = NEW_QUEUE(uLLong);
    
    for (int i = 0; i < max_digit; i++){
        for (int j = 0; j < 10; j++){
            for (uLLong k = 0; k < length; k++){
                if((uLLong)(list[k]/factor)%10==j){
                    ENQUEUE(uLLong)(bucket2, list[k]);
                }                
            }
        }
        factor = factor * 10;
        for (uLLong i = 0; i < length; i++){
            list[i] = DEQUEUE(uLLong)(bucket2);            
        }
    }
    DELETE_QUEUE(uLLong)(bucket2);
}

void uInt_LSDRadixSort(uInt list[], uLLong length){
    uInt factor = 1;
    uInt max_value = 0;
    int max_digit = 0;
    for (uLLong i = 0; i < length; i++) if(list[i] > max_value) max_value = list[i];
    for (uInt i = max_value; i > 0; i /= 10) max_digit++;
    
    QUEUE(uInt) bucket2 = NEW_QUEUE(uInt);
    
    for (int i = 0; i < max_digit; i++){
        for (int j = 0; j < 10; j++){
            for (uLLong k = 0; k < length; k++){
                if((uInt)(list[k]/factor)%10==j){
                    ENQUEUE(uInt)(bucket2, list[k]);
                }                
            }
        }
        factor = factor * 10;
        for (uLLong i = 0; i < length; i++){
            list[i] = DEQUEUE(uInt)(bucket2);            
        }
    }
    DELETE_QUEUE(uInt)(bucket2);
}

void uShort_LSDRadixSort(uShort list[], uLLong length){
    uShort factor = 1;
    uShort max_value = 0;
    int max_digit = 0;
    for (uLLong i = 0; i < length; i++) if(list[i] > max_value) max_value = list[i];
    for (uShort i = max_value; i > 0; i /= 10) max_digit++;
    
    QUEUE(uShort) bucket2 = NEW_QUEUE(uShort);
    
    for (int i = 0; i < max_digit; i++){
        for (int j = 0; j < 10; j++){
            for (uLLong k = 0; k < length; k++){
                if((uShort)(list[k]/factor)%10==j){
                    ENQUEUE(uShort)(bucket2, list[k]);
                }                
            }
        }
        factor = factor * 10;
        for (uLLong i = 0; i < length; i++){
            list[i] = DEQUEUE(uShort)(bucket2);            
        }
    }
    DELETE_QUEUE(uShort)(bucket2);
}

void uChar_LSDRadixSort(uChar list[], uLLong length){
    uChar factor = 1;
    uChar max_value = 0;
    int max_digit = 0;
    for (uLLong i = 0; i < length; i++) if(list[i] > max_value) max_value = list[i];
    for (uChar i = max_value; i > 0; i /= 10) max_digit++;
    
    QUEUE(uChar) bucket2 = NEW_QUEUE(uChar);
    
    for (int i = 0; i < max_digit; i++){
        for (int j = 0; j < 10; j++){
            for (uLLong k = 0; k < length; k++){
                if((uChar)(list[k]/factor)%10==j){
                    ENQUEUE(uChar)(bucket2, list[k]);
                }                
            }
        }
        factor = factor * 10;
        for (uLLong i = 0; i < length; i++){
            list[i] = DEQUEUE(uChar)(bucket2);            
        }
    }
    DELETE_QUEUE(uChar)(bucket2);
}