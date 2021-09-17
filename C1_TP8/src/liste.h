#ifndef listeH
#define listeH

void initList(list_t *);
int insert(list_t *, char *, int);
void displayByKey(list_t);
void displayByValue(list_t);
void freeList(list_t *);

#endif