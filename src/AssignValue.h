#ifndef _ASSIGNVALUE_H
#define _ASSIGNVALUE_H

typedef struct NameValueMap NameValueMap;
struct NameValueMap{
  char *name;
  int *value;
};
void AssignValue(NameValueMap map[], char *str);
#endif // _ASSIGNVALUE_H
