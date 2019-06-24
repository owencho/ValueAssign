#include "AssignValue.h"
#include "StringLib.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void assignValue(NameValueMap map[], char *str){
if(isEqualSign(str)){
  int mapsize = (sizeof(*map) /sizeof(map));
  for(int i=0 ; i<mapsize; i++ ){
      if(map[i].name != NULL){
  if(isWordInString(map[i].name , skipWhiteSpaces(str))){
      char* ptr = NameFind(map,str);
      int newValue = convertStringToInteger(&str);
      if(map[i].name != NULL){
        if(isWordInString(map[i].name ,ptr))
          *map[i].value = newValue;
        }
  }
}
}
}
}
int isEqualSign(char *ptr){
  for (int i = 0; i<strlen(ptr);i++){
    if((ptr[i] == '='&&ptr[i+1]==' ')||(ptr[i] == ' '&&ptr[i+1]=='=')||ptr[i] == '=' ){
     return 1;
    }
  }
  return 0;
}
char* NameFind(NameValueMap insert[],char *ptr){
  int insertsize = (sizeof(insert[0])/sizeof(insert));
for(int i=0 ; i<insertsize ; i ++){
      char* aftercommar = skipIfNonCommarSign(ptr);
      char* whitespaces =  skipWhiteSpaces(ptr);
    if(isWordInString(insert[i].name , aftercommar)){
/*      if(isWordInString(insert[i].name , skipIfNonCommarSign(aftercommar))){
      return skipIfNonCommarSign(aftercommar);
    }
      else*/
        return aftercommar;
      }
    else
    //if(isWordInString(insert[i].name,whitespaces)){
      return skipNonWhiteSpaces(ptr);
  //  }
  }
return NULL;
}
