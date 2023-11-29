#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <string.h>

struct {
  size_t len;
  size_t cap;
  int *arr;
} typedef Vec;

Vec new_vec(size_t cap);

void vec_drop(Vec v);
Vec vec_append(Vec v, int elem);
Vec vec_merge(Vec v, Vec rhs);
Vec vec_slice(Vec v, size_t start, size_t end);

#endif
