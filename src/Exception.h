#ifndef _EXCEPTION_H
#define _EXCEPTION_H
#include <stdint.h>

typedef struct Exception* ExceptionPtr ; //ExceptionPtr
typedef struct Exception Exception ;
struct Exception{
  uint32_t errorCode;
  char* errorMessage;
};
int isPositiveValueLessThan10(int positiveValue);
void dumpException(Exception *ex);
void freeException(Exception *ex);
void throwException(uint32_t errorCode,char *errorMessage,...);
int A( int v);
int B(int v);
int C(int v);
int D(int v);
#endif // _EXCEPTION_H
