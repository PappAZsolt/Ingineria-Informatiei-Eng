#include "da.h"
#include <stdio.h>
#include <stdlib.h>

struct DynamicArray *DynamicArray_Create(unsigned int cap)
{
  struct DynamicArray *arr = (struct DynamicArray *)malloc(sizeof(struct DynamicArray));
  if (!arr)
    exit;
  arr->cap = cap;
  arr->size = 0;
  arr->data = (void **)malloc(sizeof(void *));
  if (!arr->data)
    exit;
  return arr;
}

void DynamicArray_Destroy(struct DynamicArray *arr)
{
  if (arr->data)
    free(arr->data)
}