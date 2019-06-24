#include "StringLib.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int isWordInString(char *str1 , char *str2){
	int counter = 0;
  char  a[strlen(str1)];
  char  b[strlen(str2)];

for(int i=0;i<strlen(str1) ;i++)
    {
        a[i] = toupper(str1[i]);
    }
for(int i=0;i<strlen(str2) ;i++)
    {
        b[i] = toupper(str2[i]);
    }

   int j =0;
     for(int i=0;i<strlen(str2) ;i++){
			if((a[j]==b[i] && a[j+1]==b[i+1])|| (a[j]==b[i] && b[i+1]== ' ' )|| (a[j]==b[i] && b[i+1]== '=')){
			counter ++;
			j++;
			}
		}

   if((counter) == strlen(str1))
     return 1;
   else
     return 0;
}


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

char*skipIfNonCommarSign(char *str){
    for(int i=0;i< strlen(str);i++){
    if((str[i-1])==','){
     return &str[i] ;
    }
  }
  return str;
}


int convertStringToInteger(char **strPtr){
   long out = strtol(*strPtr , strPtr , 10);
 return out;
}
