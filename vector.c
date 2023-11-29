#include "vector.h"

Vec new_vec(size_t cap) {
  Vec v = {
      .len = 0,
      .cap = cap,
      .arr = (int *)malloc(cap * sizeof(int)),
  };

  return v;
}

void vec_drop(Vec v) { free(v.arr); }

Vec vec_append(Vec v, int elem) {
  if (v.len == v.cap) {
    v.cap = 2 * (v.cap + 1);

    int *arr = (int *)malloc(v.cap * sizeof(int));
    memcpy(arr, v.arr, v.len * sizeof(int));

    v.arr = arr;
  }

  v.arr[v.len] = elem;
  v.len++;

  return v;
}

Vec vec_merge(Vec v, Vec rhs) {
  if (v.len == v.cap) {
    v.cap = 2 * (v.cap + rhs.len);

    int *arr = (int *)malloc(v.cap * sizeof(int));
    memcpy(arr, v.arr, v.len * sizeof(int));

    v.arr = arr;
  }

  memcpy(v.arr + v.len, rhs.arr, rhs.len * sizeof(int));
  v.len += rhs.len;

  return v;
}

Vec vec_slice(Vec v, size_t start, size_t end) {
  if (start >= v.cap || end >= v.cap || start > end) {
    return v;
  }

  v.arr += start;
  v.len = end - start;
  v.cap = v.len;

  return v;
}
