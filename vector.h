#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <string.h>

#define VECTOR_TYPE int

struct {
  size_t len;
  size_t cap;
  VECTOR_TYPE *arr;
} typedef Vec;

Vec new_vec(size_t cap);

void vec_reserve(Vec *v, size_t n);

void vec_push(Vec *v, VECTOR_TYPE elem);
VECTOR_TYPE vec_pop(Vec *v);

void vec_shift(Vec *v, VECTOR_TYPE elem);
VECTOR_TYPE vec_unshift(Vec *v);

#endif
