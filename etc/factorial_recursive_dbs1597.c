#include <stdio.h>

unsigned long long factorial(int number)
{
  if (number == 1)
  {
    return number;
  }
  else
  {
    return number * factorial(number - 1);
  }
}

int main()
{
  printf("%llu\n", factorial(65));
}