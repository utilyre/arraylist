#include "vector.h"
#include <stdio.h>

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

  vec_drop(v2);
  vec_drop(v1);
  return 0;
}
