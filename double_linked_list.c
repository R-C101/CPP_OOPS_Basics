#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
struct node *previous;
};
struct node *head=NULL;
void addAtEnd(int item)
{
struct node *node;
node=(struct node *)malloc(sizeof(struct node));
if(node==NULL) printf("Overflow\n");
else
{
node->data=item;
if(head==NULL)
{
node->next=NULL;
node->previous=NULL;
head=node;
}
else
{
struct node *temp;
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=node;
node->next=NULL;
node->previous=temp;
}
}
printf("Node inserted\n");
}
void addAtBeg(int item)
{
struct node *node;
node=(struct node *)malloc(sizeof(struct node));
if(node==NULL) printf("Overflow\n");
else
{
node->next=head;
node->previous=NULL;
head->previous=node;
head=node;
printf("Node inserted\n");
}
}
void addAtPos(int item)
{
int pos;
struct node *node;
node=(struct node *)malloc(sizeof(struct node));
if(node==NULL) printf("overflow\n");
else
{
node->data=item;
printf("Enter position to insert  a node : ");
scanf("%d",&pos);
struct node *temp;
temp=head;
for(int i=1;i<pos;i++)
{
temp=temp->next;
if(temp==NULL)
{
printf("Not found\n");
return;
}
}
temp->previous=node;
temp->previous->next=node;
node->next=temp;
node->previous=temp->previous;
printf("Node inserted\n");
}
}
void deleteAtEnd()
{
struct node *node;
if(head==NULL) printf("Underflow\n");
else
{
node=head;
while(node->next!=NULL)
{
node=node->next;
}
node->previous->next=NULL;
free(node);
printf("Node deleted\n");
}
}
void deleteAtBeg()
{
struct node *node;
if(head==NULL) printf("Underflow\n");
else
{
node=head;
node->next->previous=NULL;
head=node->next;
free(node);
printf("Node deleted\n");
}
}
void deleteAtPos()
{
struct node *node;
int pos;
printf("Enter a position  : ");
scanf("%d",&pos);
head=node;
for(int i=1;i<pos;i++)
{
node=node->next;
if(node==NULL)
{
printf("Not found\n");
return;
}
}
node->previous->next=node->next;
node->next->previous=node->previous;
free(node);
}
void traverseLR()
{
struct node *node;
for(node=head;node!=NULL;node=node->next)
{
printf("Data is : %d\n",node->data);
}
}
void traverseRL()
{
struct node *node,*temp;
for(node=head;node!=NULL;node=node->next);
for(temp=node;temp!=head;temp=temp->previous)
{
printf("Data is : %d\n",temp->data);
}
}
void search(int item)
{
struct node *node;
for(node=head;node!=NULL;node=node->next)
{
if(node->data=item)
{
printf("Found\n");
}
}
if(node==NULL) 
{
printf("Not found\n");
return;
}
}
int main()
{
int ch,item;
while(1)
{
printf("1.Add to doubly linked list at end\n");
printf("2.Add to doubly linked list at beg\n");
printf("3. Add to doubly linked list at a position\n");
printf("4.Delete from doubly linked list at end\n");
printf("5.Delete from doubly linked list at beg\n");
printf("6.Delete from doubly linked list at a pos\n");
printf("7.Traverse left to right in doubly linked list\n");
printf("8.Traverse right to left in doubly linked list\n");
printf("9.Search in sll\n");
printf("10.Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("Enter data : ");
scanf("%d",&item);
fflush(stdin);
addAtEnd(item);
}
if(ch==2)
{
printf("Enter data : ");
scanf("%d",&item);
fflush(stdin);
addAtBeg(item);
}
if(ch==3)
{
printf("Enter data : ");
scanf("%d",&item);
fflush(stdin);
addAtPos(item);
}
if(ch==4)
{
deleteAtEnd();
}
if(ch==5)
{
deleteAtBeg();
}
if(ch==6)
{
deleteAtPos();
}
if(ch==7)
{
traverseLR();
}
if(ch==8)
{
traverseRL();
}
if(ch==9)
{
printf("Enter data : ");
scanf("%d",&item);
fflush(stdin);
search(item);
}
if(ch==10) break;
fflush(stdin);
}
return 0;
}