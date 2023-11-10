#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
  size_t len;
  size_t cap;
  int *arr;
} typedef List;

List list_new(size_t cap) {
  List list = {
      .len = 0,
      .cap = cap,
      .arr = malloc(cap * sizeof(int)),
  };

  return list;
}

void list_free(List list) { free(list.arr); }

List list_append(List list, int elem) {
  if (list.len == list.cap) {
    list.cap = 2 * (list.cap + 1);

    int *arr = malloc(list.cap * sizeof(int));
    memcpy(arr, list.arr, sizeof(int) * list.len);

    list.arr = arr;
  }

  list.arr[list.len] = elem;
  list.len++;

  return list;
}

List list_merge(List list, List other) {
  if (list.len == list.cap) {
    list.cap = 2 * (list.cap + other.len);

    int *arr = malloc(list.cap * sizeof(int));
    memcpy(arr, list.arr, sizeof(int) * list.len);

    list.arr = arr;
  }

  for (size_t i = 0; i < other.len; i++) {
    list.arr[list.len + i] = other.arr[i];
  }
  list.len += other.len;

  return list;
}

List list_slice(List list, size_t start, size_t end) {
  if (start > list.cap - 1 || end > list.cap - 1) {
    return list;
  }

  list.arr += start;
  list.len = end - start;
  list.cap = list.len;

  return list;
}

int list_get(List list, size_t index) { return list.arr[index]; }

void list_print(List list) {
  for (size_t i = 0; i < list.len; i++) {
    printf("[%lu]: %d\n", i, list_get(list, i));
  }
}

int main() {
  List l = list_new(0);

  l = list_append(l, 1); // 0
  l = list_append(l, 2); // 1
  l = list_append(l, 3); // 2
  l = list_append(l, 4); // 3
  l = list_append(l, 5); // 4

  list_print(l);

  List s = list_slice(l, 1, 20);

  printf("------------\n");
  list_print(s);

  list_free(l);
  return 0;
}
