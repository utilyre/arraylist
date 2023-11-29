#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
  size_t len;
  size_t cap;
  int *arr;
} typedef Vec;

Vec new_vec(size_t cap) {
  Vec v = {
      .len = 0,
      .cap = cap,
      .arr = malloc(cap * sizeof(int)),
  };

  return v;
}

void vec_drop(Vec v) { free(v.arr); }

Vec vec_append(Vec v, int elem) {
  if (v.len == v.cap) {
    v.cap = 2 * (v.cap + 1);

    int *arr = malloc(v.cap * sizeof(int));
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

    int *arr = malloc(v.cap * sizeof(int));
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

void vec_dump(Vec v) {
  for (size_t i = 0; i < v.len; i++) {
    printf("[%lu]: %d\n", i, v.arr[i]);
  }
}

int main() {
  Vec v1 = new_vec(5);
  v1 = vec_append(v1, 1);
  v1 = vec_append(v1, 2);
  v1 = vec_append(v1, 3);
  v1 = vec_append(v1, 4);
  v1 = vec_append(v1, 5);

  Vec v2 = new_vec(5);
  v2 = vec_append(v2, 6);
  v2 = vec_append(v2, 7);
  v2 = vec_append(v2, 8);
  v2 = vec_append(v2, 9);
  v2 = vec_append(v2, 10);

  v1 = vec_merge(v1, v2);

  vec_dump(v1);
  vec_dump(v2);

  vec_drop(v2);
  vec_drop(v1);
  return 0;
}
