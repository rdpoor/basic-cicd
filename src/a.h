/**
 * @file: a.h
 *
 * @brief a is a prototype for a simple library module.
 */

#ifndef _A_H_
#define _A_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int count;
} a_ctx_t;

void a_init(a_ctx_t *a);

void a_set_count(a_ctx_t *a, int count);

int a_get_count(a_ctx_t *a);

#ifdef __cplusplus
}
#endif
