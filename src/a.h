/**
 * @file: a.h
 *
 * @brief Declarations for the a module.
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

#endif // #ifndef _A_H_
