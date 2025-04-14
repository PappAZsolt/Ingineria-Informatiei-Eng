#include <stdio.h>

int checksum(int a, int b, int c, int d)
{
  int s = a + b + c + d;
  return s;
}

int checkDistinct(int a, int b, int c, int d)
{
  if ((a != b) && (c != d) && (a != d) && (a > b) && (b > c) && (c > d))
    return 1;
  return 0;
}

int main()
{
  int number = 9861;
  while (number >= 1000)
  {
    int a = number / 1000 % 10;
    int b = number / 100 % 10;
    int c = number / 10 % 10;
    int d = number % 10;
    if (checksum(a, b, c, d) == 24 && checkDistinct(a, b, c, d))
      printf("%d\n", number);
    number--;
  }
}