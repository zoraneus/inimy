/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_chained
*/

#ifndef MY_CHAINED_H_
#define MY_CHAINED_H_

#include "stdlib.h"

// double chained  //
struct double_chained {
    struct double_chained *next;
    struct double_chained *prev;
    void *content;
};
typedef struct double_chained double_chained_t;

double_chained_t *double_chain_create(void *content);
void double_chain_push_back(double_chained_t *link, void *content);
void double_chain_push_top(double_chained_t **link, void *content);
void double_chain_push_after(double_chained_t *link, void *content);
void double_chain_push_before(double_chained_t *link, void *content);
void double_chain_pop_me(double_chained_t *link);
void double_chain_pop_back(double_chained_t *link);
void double_chain_pop_top(double_chained_t *link);

//debug
void double_chain_debug_desc(double_chained_t *link);
void double_chain_debug_asc(double_chained_t *link);

#endif /* !MY_CHAINED_H_ */