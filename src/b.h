/**
 * @file: b.h
 *
 * @brief b is a prototype for a simple library module that has a dependency on a.
 */

#ifndef _B_H_
#define _B_H_

#include "a.h:

#ifdef __cplusplus
extern "C" {
#endif

void b_init(a_ctx_t *a);

void b_increment_count(a_ctx_t *a);

int b_get_count(a_ctx_t *a);

#ifdef __cplusplus
}
#endif
