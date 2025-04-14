#pragma once
#include <stdbool.h>

struct DynamicArray
{
  unsigned int cap;
  unsigned int size;
  void **data;
};

struct DynamicArray *DynamicArray_Create(unsigned int cap);
void DynamicArray_Destroy(struct DynamicArray *data);
void DynamicArray_Append(struct DynamicArray *data, void *value);
int DynamicArray_Find(struct DynamicArray *data, void *value, bool (*compare)(const void *data1, const void *data2));
void DynamicArray_Display(struct DynamicArray *data, void (*display)(const void *data));
