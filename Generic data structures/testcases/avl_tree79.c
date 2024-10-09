#include<tm_avl_tree.h>
#include<stdio.h>
#include<stdlib.h>
int myComparator(void *left,void *right)
{
int *leftInt,*rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}
int main()
{
int ch;
AVLTreeInOrderIterator iterator;
char more;
int *x;
int num;
AVLTree *tree;
int success;
tree=createAVLTree(&success,myComparator);
if(success==false)
{
printf("Unable to create tree,low on memory\n");
return 0;
}
while(1)
{
printf("1. Insert\n");
printf("2. in order traversal\n");
printf("3. Remove\n");
printf("4. Search\n");
printf("5. Exit\n");
printf("Enter your choice:\n");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("Enter number to be inserted in tree  :");
scanf("%d",&num);
fflush(stdin);
x=(int *)malloc(sizeof(int));
*x=num;
insertIntoAVLTree(tree,(void *)x,&success);
if(success)printf("Address of item that contains %d inserted in the tree\n",*x);
else printf("Unable to insert in tree\n");
}
if(ch==2)
{
printf("In Order Iteration starts\n");
iterator=getAVLTreeIterator(tree,&success);
if(success)
{
while(hasNextInAVLTree(&iterator))
{
x=(int *)getNextElementFromAVLTree(&iterator,&success);
printf("%d\n",*x);
}
}
}
if(ch==3)
{
printf("Enter number to remove: ");
scanf("%d",&num);
fflush(stdin);
x=removeFromAVLTree(tree,&num,&success);
if(success)printf("%d found and removed\n",*x);
else printf("%d not found\n",num);
}
if(ch==4)
{
printf("Enter number to search: ");
scanf("%d",&num);
fflush(stdin);
x=getFromAVLTree(tree,&num,&success);
if(success)printf("%d found\n",*x);
else printf("%d not found\n",num);
}
if(ch==5)break;
}
destroyAVLTree(tree);
return 0;
}