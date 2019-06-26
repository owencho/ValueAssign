#include "unity.h"
#include "Exception.h"
#include "Error.h"
#include "CException.h"
#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <stdarg.h>

void dumpException(Exception *ex){
    printf("%s (err=%d)", ex->errorMessage , ex->errorCode);
}

void freeException(Exception *ex){
  if(ex)
    free(ex);
}

void throwException(uint32_t errorCode,char *errorMessage,...){
    int actualLength;
    char* buffer;
    Exception *exceptionPtr;

    va_list arg;
    va_start(arg, errorMessage);

    actualLength = vsnprintf(NULL,0, errorMessage, arg);   //trick system to take actualLength
    buffer =malloc(actualLength + 1);               // allocate value to buffer
    vsnprintf(buffer,actualLength + 1, errorMessage, arg); //

  /*printf("%s \n v = %d\n", format, v); old version 1 */
  //v = va_arg(arg, int);
    va_end(arg);

  exceptionPtr = malloc(sizeof(Exception));
  exceptionPtr -> errorCode = errorCode;
  exceptionPtr -> errorMessage = buffer;
  Throw(exceptionPtr);
}



int isPositiveValueLessThan10(int positiveValue){
  Exception *exceptionPtr;
  Exception exception;
  if(positiveValue <0){
    throwException(ERR_VALUE_IS_NON_POSITIVE,"The value is %d .The value must be positive.",positiveValue);
    //throwException(ERR_VALUE_IS_NON_POSITIVE,"The value is %d .The value must be positive.",positiveValue);
  }
  if(positiveValue < 10)
    return 1;
  else
    return 0;


}

int isValueLessThan2000ButBiggerThanOrEqual10(int value){
  CEXCEPTION_T ex;
  int result ;
  if(value >= 2000){
    return 0;
  }
  Try{
    result = isPositiveValueLessThan10(value);
    return !result;
  }Catch(ex){
    return 0 ;
  }

}

int A(int v){
  CEXCEPTION_T ex;
  Try{
  return B(v);
  }Catch(ex){
    dumpException(ex);
    freeException(ex);
    throwException(777,"The value is %d .throw at A \n",v);
    return 0 ;
  }

}

int B(int v) {
  return C(v);

}

int C(int v){
  CEXCEPTION_T ex;
  Try{
  return D(v);
  }Catch(ex){
    dumpException(ex);
    freeException(ex);
    throwException(111,"The value is %d .big oof \n",v);

  }
}

int D(int v){
  CEXCEPTION_T ex;
  if(v < 0){
    dumpException(ex);
    throwException(999,"The value is %d .The value should not be negative. \n",v);
    freeException(ex);
  //  Throw(999);
  }
  if(v == 0 ){
    return 0;
  }
    return 1;
}

/*
void my_printf(char *format ,...){
  int actualLength;
  char* buffer;
  va_list arg;
  va_start(arg, format);

  actualLength = vsnprintf(NULL,0,format, arg);   //trick system to take actualLength
  buffer =malloc(actualLength + 1);               // allocate value to buffer
  vsnprintf(buffer,actualLength + 1,format, arg); //
  printf(buffer);

//printf("%s \n v = %d\n", format, v); old version 1
//v = va_arg(arg, int);
  va_end(arg);
}
*/
