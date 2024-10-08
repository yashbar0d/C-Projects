#ifndef __TM__DLL__H
#define __TM__DLL__H
#include<tm_common.h>
typedef struct _$__tm_dllnode
{
void *ptr;
struct _$__tm_dllnode *next;
struct _$__tm_dllnode *previous;
}DoublyLinkedListNode;
typedef struct _$__tm_dll
{
struct _$__tm_dllnode *start;
struct _$__tm_dllnode *end;
int size;
}DoublyLinkedList;
typedef struct __$__tm_dll_iterator
{
DoublyLinkedListNode *node;
}DoublyLinkedListIterator;
typedef struct __$__tm_dll_reverse_iterator
{
DoublyLinkedListNode *node;
}DoublyLinkedListReverseIterator;
DoublyLinkedList * createDoublyLinkedList(bool *success);
void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success);
void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,void *ptr,bool *success);
void *removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success);
void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList);
void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList *doublyLinkedList,bool *success);
void *getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success);
DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList,bool *success);
bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator);
void *getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator,bool *success);
DoublyLinkedListReverseIterator getDoublyLinkedListReverseIterator(DoublyLinkedList *doublyLinkedList,bool *success);
bool hasPreviousInDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator);
void *getPreviousElementFromDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator,bool *success);
#endif