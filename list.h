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
    typedef struct {             \
        T##_ListNode * elem_ptr; \
    } T##_ListIter;              \
    \
    T##_List * T##List() {                           \
        T##_List * li = calloc(1, sizeof(T##_List)); \
        return li;                                   \
    }                                                \
    \
    T##_ListIter * T##ListIter(T##_List * const li) {         \
        T##_ListIter * iter = malloc(sizeof(T##_ListIter *)); \
        iter->elem_ptr = li->header;                          \
        return iter;                                          \
    }                                                         \
    \
    T T##Next(T##_ListIter * const iter) {       \
        T val = iter->elem_ptr->data;            \
        iter->elem_ptr = iter->elem_ptr->r_link; \
        return val;                              \
    }                                            \
    \
    unsigned T##HasNext(T##_ListIter * const iter) { \
        return iter->elem_ptr != NULL;               \
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
    void T##DeleteList(T##_List * const li) {              \
        while (li->length) {                               \
            T##_ListNode * next_node = li->header->r_link; \
                                                           \
            free(li->header);                              \
            li->header = next_node;                        \
            --li->length;                                  \
        }                                                  \
                                                           \
        free(li);                                          \
    }                                                      \
    \
    inline void T##DeleteIter(T##_ListIter * const iter) { \
        free(iter);                                        \
    }                                                      \
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
#define LIST(T)            T##_List *
#define ITERATOR(T)        T##_ListIter *
#define NEW_LIST(T)        T##List()
#define NEW_ITERATOR(T)    T##ListIter
#define NEXT(T)            T##Next
#define HAS_NEXT(T)        T##HasNext
#define GET(T)             T##Get
#define APPEND(T)          T##Append
#define INSERT(T)          T##Insert
#define REMOVE(T)          T##Remove
#define DELETE_LIST(T)     T##DeleteList
#define DELETE_ITERATOR(T) T##DeleteIter
#define IS_EMPTY_LIST(T)   T##IsEmptyList
#define IS_FULL_LIST(T)    T##IsFullList

#endif //DATA_STRUCTURE_LIST_H