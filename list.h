#ifndef DATA_STRUCTURE_LIST_H
#define DATA_STRUCTURE_LIST_H

#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#define DEFINE_LIST(T) \
    typedef struct _##T##_ListNode * T##_LiPtr; \
    typedef unsigned long long    DtTyOfLiLen;  \
    typedef struct _##T##_ListNode { \
        T         data;              \
        T##_LiPtr l_link;            \
        T##_LiPtr r_link;            \
    } T##_ListNode;                  \
    typedef struct {           \
        T##_ListNode * header; \
        T##_ListNode * footer; \
        DtTyOfLiLen    length; \
    } T##_List;                \
    \
    T##_List * T##List() {                           \
        T##_List * li = calloc(1, sizeof(T##_List)); \
        return li;                                   \
    }                                                \
    \
    T##_ListNode * T##GetElement(T##_List * const li, const DtTyOfLiLen idx) { \
        assert(idx < li->length);                                              \
                                                                               \
        unsigned       is_lower = idx <= li->length / 2;                       \
        T##_ListNode * elem     = is_lower ? li->header : li->footer;          \
        DtTyOfLiLen    r_idx    = li->length - (idx + 1);                      \
        DtTyOfLiLen    i        = 0;                                           \
                                                                               \
        if (is_lower) for (; i < idx;   i++) elem = elem->r_link;              \
        else          for (; i < r_idx; i++) elem = elem->l_link;              \
                                                                               \
        return elem;                                                           \
    }                                                                          \
    \
    T T##Get(T##_List * const li, const DtTyOfLiLen idx) { \
        return T##GetElement(li, idx)->data;               \
    }                                                      \
    \
    void T##Append(T##_List * const li, T value) {          \
        assert(li->length < ULLONG_MAX);                    \
                                                            \
        T##_ListNode * elem = malloc(sizeof(T##_ListNode)); \
        elem->data   = value;                               \
        elem->l_link = li->footer;                          \
        elem->r_link = NULL;                                \
                                                            \
        if (li->length) li->footer->r_link = elem;          \
        else            li->header         = elem;          \
                                                            \
        li->footer = elem;                                  \
        ++li->length;                                       \
    }                                                       \
    \
    void T##Insert(T##_List * const li, const DtTyOfLiLen idx, T value) { \
        assert(li->length < ULLONG_MAX);                                  \
                                                                          \
        T##_ListNode * elem = !idx ? li->header : T##GetElement(li, idx); \
                                                                          \
        T##_ListNode * new_elem = malloc(sizeof(T##_ListNode));           \
        new_elem->data   = value;                                         \
        new_elem->l_link = elem->l_link;                                  \
        new_elem->r_link = elem;                                          \
                                                                          \
        if (idx) elem->l_link->r_link = new_elem;                         \
        else     li->header           = new_elem;                         \
        elem->l_link = new_elem;                                          \
        ++li->length;                                                     \
    }                                                                     \
    \
    T T##Remove(T##_List * const li, const DtTyOfLiLen idx) {  \
        assert(li->length);                                    \
                                                               \
        T##_ListNode * elem = T##GetElement(li, idx);          \
        T val = elem->data;                                    \
                                                               \
        if (elem->l_link) elem->l_link->r_link = elem->r_link; \
        if (elem->r_link) elem->r_link->l_link = elem->l_link; \
                                                               \
        if (li->length > 1) {                                  \
            if (elem == li->header) li->header = elem->r_link; \
            if (elem == li->footer) li->footer = elem->l_link; \
        }                                                      \
        else li->header = li->footer = NULL;                   \
                                                               \
        --li->length;                                          \
        free(elem);                                            \
        return val;                                            \
    }                                                          \
    \
    void T##TestForNormalcyLi(T##_List * const li) { \
        const unsigned kLenBool  = !!li->length,     \
                       kFntBool  = !!li->header,     \
                       kRearBool = !!li->footer;     \
                                                     \
        assert(!(kLenBool | kFntBool | kRearBool)    \
             || (kLenBool & kFntBool & kRearBool));  \
    }                                                \
    \
    unsigned T##IsEmptyList(T##_List * const li) { \
        T##TestForNormalcyLi(li);                  \
        return !li->length;                        \
    }                                              \
    \
    unsigned T##IsFullList(T##_List * const li) { \
        T##TestForNormalcyLi(li);                 \
        return li->length == ULLONG_MAX;          \
    }
#define LIST(T)          T##_List *
#define NEW_LIST(T)      T##List()
#define GET(T)           T##Get
#define APPEND(T)        T##Append
#define INSERT(T)        T##Insert
#define REMOVE(T)        T##Remove
#define IS_EMPTY_LIST(T) T##IsEmptyList
#define IS_FULL_LIST(T)  T##IsFullList

#endif //DATA_STRUCTURE_LIST_H