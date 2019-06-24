#ifndef _ASSIGNVALUE_H
#define _ASSIGNVALUE_H

typedef struct NameValueMap NameValueMap;
struct NameValueMap{
  char *name;
  int *value;
};
void assignValue(NameValueMap map[], char *str);
int isEqualSign(char *ptr);
char* NameFind(NameValueMap insert[],char *ptr);
int isSpaceandEqualSign(char *ptr);
#endif // _ASSIGNVALUE_H
