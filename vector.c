#include "vector.h"
#include <string.h>

Vec new_vec(size_t cap) {
  Vec v = {
      .len = 0,
      .cap = cap,
      .arr = malloc(cap * sizeof(VECTOR_TYPE)),
  };

  return v;
}

void vec_reserve(Vec *v, size_t size) {
  v->cap = 2 * (v->cap + size);

  VECTOR_TYPE *arr = malloc(v->cap * sizeof(VECTOR_TYPE));
  memcpy(arr, v->arr, v->len * sizeof(VECTOR_TYPE));

  free(v->arr);
  v->arr = arr;
}

void vec_push(Vec *v, VECTOR_TYPE elem) {
  if (v->len == v->cap) {
    vec_reserve(v, 1);
  }

  v->arr[v->len] = elem;
  ++v->len;
}

VECTOR_TYPE vec_pop(Vec *v) { return v->arr[--v->len]; }

void vec_shift(Vec *v, VECTOR_TYPE elem) {
  if (v->len == v->cap) {
    vec_reserve(v, 1);
  }

  for (size_t i = v->len; i > 0; --i) {
    v->arr[i] = v->arr[i - 1];
  }

  v->arr[0] = elem;
  ++v->len;
}

VECTOR_TYPE vec_unshift(Vec *v) {
  VECTOR_TYPE elem = v->arr[0];

  for (size_t i = 0; i < v->len; ++i) {
    v->arr[i] = v->arr[i + 1];
  }

  --v->len;
  return elem;
}
