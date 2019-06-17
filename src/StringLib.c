#include "StringLib.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int isWordInString(char *str1 , char *str2){
  return NULL;
  
  
  
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
  for(int i=0;i< strlen(str);i++){
    if(isspace(str[i-1])&&isalnum(str[i])){
     return &str[i] ;
     
    } 
  }
  return str;
}

char *skipNonWhiteSpaces(char *str){
    for(int i=0;i< strlen(str);i++){
    if(isspace(str[i])){
     return &str[i] ;
     
    } 
  }
  return str;
}


char*skipIfAlphaNumberics(char *str){
    for(int i=0;i< strlen(str);i++){
    if(!isalnum(str[i])){
     return &str[i] ;
    } 
  }
  return str;
}


int convertStringToInteger(char **strPtr){
  int long a = strtol(*strPtr , strPtr , 10);
 return a;
}		
		
		
		

