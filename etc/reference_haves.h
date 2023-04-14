#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MALLOC(A, B)\
if (((A) = malloc(B)) == NULL){\
printf("Error memory allocate!\n");\
exit(1);\
}

#define REALLOC(A, B)\
if (((A) = realloc(A, B)) == NULL){\
printf("Error memory allocate!\n");\
exit(1);\
}

#define COMPARE(A, B) ((A) < (B)) ? -1 : ((A) == (B)) ? 0 : 1

#define SWAP(A, B, T) (T) = (A); (A) = (B); (B) = (T);