#include "countingSort.h"

void uIntCountingSort(unsigned * seq, const uLLong len) {
    unsigned max = *seq,
        idx = 0;

    for (uLLong i = 1; i < len; i++) {
        if (seq[i] > max) max = seq[i];
    }

    unsigned * cnt_arr = calloc(++max, sizeof(unsigned));

    for (uLLong i = 0; i < len;) ++cnt_arr[seq[i++]];

    for (unsigned i = 0; i < max; i++) {
        for (unsigned j = cnt_arr[i]; j; j--) seq[idx++] = i;
    }

    free(cnt_arr);
}

void uCharCountingSort(unsigned char * seq, const uLLong len) {
    unsigned char max = *seq,
                  idx = 0;

    for (uLLong i = 1; i < len; i++) {
        if (seq[i] > max) max = seq[i];
    }

    unsigned char * cnt_arr = calloc(++max, sizeof(unsigned char));

    for (uLLong i = 0; i < len;) ++cnt_arr[seq[i++]];

    for (unsigned char i = 0; i < max; i++) {
        for (unsigned char j = cnt_arr[i]; j; j--) seq[idx++] = i;
    }

    free(cnt_arr);
}

void uShortCountingSort(unsigned short * seq, const uLLong len) {
    unsigned short max = *seq,
                   idx = 0;

    for (uLLong i = 1; i < len; i++) {
        if (seq[i] > max) max = seq[i];
    }

    unsigned short * cnt_arr = calloc(++max, sizeof(unsigned short));

    for (uLLong i = 0; i < len;) ++cnt_arr[seq[i++]];

    for (unsigned short i = 0; i < max; i++) {
        for (unsigned short j = cnt_arr[i]; j; j--) seq[idx++] = i;
    }

    free(cnt_arr);
}

void uLLongCountingSort(uLLong * seq, const uLLong len) {
    unsigned max = *seq,
            idx = 0;

    for (uLLong i = 1; i < len; i++) {
        if (seq[i] > max) max = seq[i];
    }

    int * cnt_arr = calloc(++max, sizeof(uLLong));

    for (uLLong i = 0; i < len;) ++cnt_arr[seq[i++]];

    for (uLLong i = 0; i < max; i++) {
        for (uLLong j = cnt_arr[i]; j; j--) seq[idx++] = i;
    }

    free(cnt_arr);
}