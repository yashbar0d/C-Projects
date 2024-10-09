#include<tm_sll.h>
#include<stdio.h>
int main()
{
int i1,i2,i3,i4,i5,i6,y;
int *x;
int k;
bool succ;
SinglyLinkedList *list1,*list2;
list1=createSinglyLinkedList(&succ);
list2=createSinglyLinkedList(&succ);
i1=100;
i2=200;
i3=300;
i4=400;
i5=500;
i6=600;
addToSinglyLinkedList(list1,(void *)&i1,&succ);
addToSinglyLinkedList(list1,(void *)&i2,&succ);
addToSinglyLinkedList(list2,(void *)&i3,&succ);
addToSinglyLinkedList(list2,(void *)&i4,&succ);
addToSinglyLinkedList(list2,(void *)&i5,&succ);
addToSinglyLinkedList(list2,(void *)&i6,&succ);
for(y=0;y<getSizeOfSinglyLinkedList(list1);y++)
{
k=y;
x=(int *)getFromSinglyLinkedList(list1,y,&succ);
printf("%d\n",*x);
}
appendToSinglyLinkedList(list1,list2,&succ);
if(succ)printf("Appended\n");
else printf("Unable to appending\n");
for(y=0;y<getSizeOfSinglyLinkedList(list1);y++)
{
k=y;
x=(int *)getFromSinglyLinkedList(list1,y,&succ);
printf("%d\n",*x);
}
destroySinglyLinkedList(list1);
return 0;
}