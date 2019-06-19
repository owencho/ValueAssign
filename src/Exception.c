#include "unity.h"
#include "Exception.h"
#include "Error.h"
#include "CException.h"


int isPositiveValueLessThan10(int positiveValue){
  if(positiveValue <0){
    Throw(ERR_VALUE_IS_NON_POSITIVE);
  }
  if(positiveValue < 10)
    return 1;
  else
  return 0;
  
  
}