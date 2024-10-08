#ifndef __TM__SLL__H
#define __TM__SLL__H
#include<tm_common.h>
typedef struct _$__tm_sllnode
{
void *ptr;
struct _$__tm_sllnode *next;
}SinglyLinkedListNode;
typedef struct _$__tm_sll
{
struct _$__tm_sllnode *start;
struct _$__tm_sllnode *end;
int size;
}SinglyLinkedList;
typedef struct __$__tm_sll_iterator
{
SinglyLinkedListNode *node;
}SinglyLinkedListIterator;
SinglyLinkedList * createSinglyLinkedList(bool *success);
void destroySinglyLinkedList(SinglyLinkedList *singlyLinkedList);
int getSizeOfSinglyLinkedList(SinglyLinkedList *singlyLinkedList);
void addToSinglyLinkedList(SinglyLinkedList *singlyLinkedList,void *ptr,bool *success);
void insertIntoSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,void *ptr,bool *success);
void *removeFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *success);
void clearSinglyLinkedList(SinglyLinkedList *singlyLinkedList);
void appendToSinglyLinkedList(SinglyLinkedList *targetSinglyLinkedList,SinglyLinkedList *singlyLinkedList,bool *success);
void *getFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *success);
SinglyLinkedListIterator getSinglyLinkedListIterator(SinglyLinkedList *singlyLinkedList,bool *success);
bool hasNextInSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator);
void *getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator,bool *success);
#endif