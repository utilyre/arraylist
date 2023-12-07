#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void dump_vector(Vec v) {
  for (size_t i = 0; i < v.len; i++) {
    printf("[%lu]: %d\n", i, v.arr[i]);
  }
}

int main() {
  Vec v = new_vec(2);

  vec_shift(&v, 1);
  vec_shift(&v, 2);
  vec_shift(&v, 3);
  vec_shift(&v, 4);
  vec_shift(&v, 5);
  vec_shift(&v, 6);

  printf("Removed %d\n", vec_unshift(&v));
  printf("Removed %d\n", vec_unshift(&v));
  printf("Removed %d\n", vec_unshift(&v));
  printf("Removed %d\n", vec_unshift(&v));
  printf("Removed %d\n", vec_unshift(&v));
  printf("Removed %d\n", vec_unshift(&v));

  dump_vector(v);

  free(v.arr);
  return 0;
}
