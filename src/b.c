/**
 * @file: b.c
 *
 * @brief Implementation of the b module.
 */

#include "b.h"
#include "a.h"

void b_init(a_ctx_t *a) {
  a_init(a);
}

void b_increment_count(a_ctx_t *a) {
  a_set_count(a, a_get_count(a) + 1);
}

int b_get_count(a_ctx_t *a) {
  return a_get_count(a);
}


