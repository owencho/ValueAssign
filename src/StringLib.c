#include "StringLib.h"
#include <stdio.h>

int stringCompare(char *str1 , char *str2){
  
  if(str1 == NULL || str2== NULL){
   if(str1 == str2)
		return 0;
	if(str1==NULL && str2 > 0)
		return -1;
    if(str1 > 0 && str2 == NULL)
		return 1;
  }
	if(strcmp(str1,str2)==0)
		return 0;
	if(strcmp(str1,str2)>=0)
		return 1;
    if(strcmp(str1,str2)<=0)
		return -1;
	}
  
char *skipWhiteSpaces(char *str){
  return NULL;
}

char *skipNonWhiteSpaces(char *str){
  return NULL;
}

int ConvertStringToInteger(char **strPtr)
{
}
