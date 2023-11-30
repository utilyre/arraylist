#include "vector.h"

Vec new_vec(size_t cap) {
  Vec v = {
      .len = 0,
      .cap = cap,
      .arr = malloc(cap * sizeof(int)),
  };

  return v;
}

Vec vec_reserve(Vec v, size_t size) {
  v.cap = 2 * (v.cap + size);

  // WARNING: arr is not freed
  int *arr = malloc(v.cap * sizeof(int));
  memcpy(arr, v.arr, v.len * sizeof(int));

  v.arr = arr;
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

Vec vec_append(Vec v, int elem) {
  if (v.len == v.cap) {
    v = vec_reserve(v, 1);
  }

  v.arr[v.len] = elem;
  v.len++;

  return v;
}

Vec vec_merge(Vec v, Vec elems) {
  if (v.len == v.cap) {
    v = vec_reserve(v, elems.len);
  }

  memcpy(v.arr + v.len, elems.arr, elems.len * sizeof(int));
  v.len += elems.len;

  return v;
}
