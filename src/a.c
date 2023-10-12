/**
 * @file: a.c
 *
 * @brief Implemtation of the a module.
 */
#include "a.h"

void a_init(a_ctx_t *a) {
  a->count = 0;
}

void a_set_count(a_ctx_t *a, int count) {
  a->count = count;
}

int a_get_count(a_ctx_t *a) {
  return a->count;
}

  
