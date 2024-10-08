#ifndef TM__DLL_C
#define TM__DLL_C
#include<stdlib.h>
#include<tm_dll.h>
DoublyLinkedList *createDoublyLinkedList(bool *success)
{
if(success) *success=false;
DoublyLinkedList *doublyLinkedList;
doublyLinkedList=(DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
if(doublyLinkedList==NULL) return NULL;
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;
if(success) *success=true;
return doublyLinkedList;
}
void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success)
{
if(success)*success=false;
DoublyLinkedListNode *node;
if(doublyLinkedList==NULL)return;
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL)return;
node->ptr=ptr;
node->next=NULL;
if(doublyLinkedList->start==NULL)
{
doublyLinkedList->start=node;
doublyLinkedList->end=node;
}
else
{
doublyLinkedList->end->next=node;
doublyLinkedList->end=node;
}
if(success) *success=true;
doublyLinkedList->size++;
}
void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,void *ptr,bool *success)
{
DoublyLinkedListNode *node,*p1,*p2;
int x;
if(success) *success=false;
if(doublyLinkedList==NULL)return;
if(index<0 || index>doublyLinkedList->size)return;
if(index==doublyLinkedList->size)
{
addToDoublyLinkedList(doublyLinkedList,ptr,success);
return;
}
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL)return;
node->ptr=ptr;
node->next=NULL;
if(index==0)
{
node->next=doublyLinkedList->start;
doublyLinkedList->start=node;
doublyLinkedList->size++;
if(success)*success=true;
return;
}
p1=doublyLinkedList->start;
x=0;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
node->next=p1;
p2->next=node;
doublyLinkedList->size++;
if(success)*success=true;
}
void *removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)
{
void *ptr;
DoublyLinkedListNode *p1,*p2;
int x;
if(success) *success=false;
if(doublyLinkedList==NULL)return NULL;
if(index<0 || index>=doublyLinkedList->size)return NULL;
p1=doublyLinkedList->start;
x=0;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
ptr=p1->ptr;
if(doublyLinkedList->start==p1 && doublyLinkedList->end==p1)
{
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
}
else if(doublyLinkedList->start==p1)
{
doublyLinkedList->start=doublyLinkedList->start->next;
}
else if(doublyLinkedList->end==p1)
{
doublyLinkedList->end=p2;
doublyLinkedList->end->next=NULL;
}
else
{
p2->next=p1->next;
}
free(p1);
doublyLinkedList->size--;
if(success)*success=true;
return ptr;
}
void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList *sourceDoublyLinkedList,bool *success)
{
DoublyLinkedListNode *s,*e,*t,*node;
bool done;
if(success)*success=false;
if(targetDoublyLinkedList==NULL)return;
if(sourceDoublyLinkedList==NULL || sourceDoublyLinkedList->size==0)
{
if(success)*success=true;
return;
}
s=NULL;
e=NULL;
done=true;
t=sourceDoublyLinkedList->start;
while(t!=NULL)
{
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL)
{
done=false;
break;
}
node->ptr=t->ptr;
node->next=NULL;
if(s==NULL)
{
s=node;
e=node;
}
else
{
e->next=node;
e=node;
}
t=t->next;
}
if(done==false)
{
while(s!=NULL)
{
node=s;
s=s->next;
free(node);
}
return;
}
if(targetDoublyLinkedList->start==NULL)
{
targetDoublyLinkedList->start=s;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size=sourceDoublyLinkedList->size;
}
else
{
targetDoublyLinkedList->end->next=s;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size+=sourceDoublyLinkedList->size;
}
if(success)*success=true;
}
void *getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)
{
DoublyLinkedListNode *node;
int x;
if(success)*success=false;
if(doublyLinkedList==NULL)return NULL;
if(index<0 || index>=doublyLinkedList->size)return NULL;
x=0;
node=doublyLinkedList->start;
while(x<index)
{
node=node->next;
x++;
}
if(success)*success=true;
return node->ptr;
}
void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
DoublyLinkedListNode *node;
if(doublyLinkedList==NULL)return;
while(doublyLinkedList->start!=NULL)
{
node=doublyLinkedList->start;
doublyLinkedList->start=doublyLinkedList->start->next;
free(node);
}
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;
}
void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL)return;
clearDoublyLinkedList(doublyLinkedList);
free(doublyLinkedList);
}
int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL)return 0;
return doublyLinkedList->size;
}
DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList,bool *success)
{
DoublyLinkedListIterator doublyLinkedListIterator;
doublyLinkedListIterator.node=NULL;
if(success)*success=false;
if(doublyLinkedList==NULL)return doublyLinkedListIterator;
if(doublyLinkedList->start==NULL)
{
if(success)*success=true;
return doublyLinkedListIterator;
}
if(success)*success=true;
doublyLinkedListIterator.node=doublyLinkedList->start;
return doublyLinkedListIterator;
}
bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator)
{
if(doublyLinkedListIterator==NULL)return false;
return true;
}
void *getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator,bool *success)
{
void *ptr;
if(success)*success=false;
if(doublyLinkedListIterator==NULL || doublyLinkedListIterator->node==NULL)return ptr;
ptr=doublyLinkedListIterator->node->ptr;
doublyLinkedListIterator->node=doublyLinkedListIterator->node->next;
if(success)*success=true;
return ptr;
}
#endif