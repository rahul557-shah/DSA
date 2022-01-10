/*Given a singly linked list of characters, write a function that returns true 
if the given list is a palindrome, else false.*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
  char data;
  struct node *next;
} *first = NULL;
void create(struct node *p, int n)
{
  int x;
  struct node *t, *temp;
  first = (struct node *)malloc(sizeof(struct node));
  printf("Enter the data: ");
  scanf("%s", &x);
  first->data = x;
  first->next = NULL;
  temp = first;
  for (int i = 1; i < n; i++)
  {
    t = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%s", &x);
    t->data = x;
    t->next = NULL;
    temp->next = t;
    temp = temp->next;
  }
}
void display(struct node *p)
{
  while (p != NULL)
  {
    printf("%c->", p->data);
    p = p->next;
  }
  printf("null");
}
struct Stack
{
  int size;
  int top;
  int *S;
};
void createStack(struct Stack *st, int size)
{
  st->size = size;
  st->S = (int *)malloc(st->size * sizeof(int));
  st->top = -1;
}
void push(struct Stack *st, char x)
{
  if (st->top == st->size - 1)
    printf("Stack is Full");
  else
  {
    st->top++;
    st->S[st->top] = x;
  }
}
char pop(struct Stack *st)
{
  char x;
  if (st->top == -1)
    printf("Stack is empty!!");
  else
  {
    x = st->S[st->top];
    st->top--;
  }
  return x;
}
void displayStack(struct Stack st)
{
  for (int i = st.top; i > -1; i--)
  {
    printf("%c ", st.S[i]);
  }
}
int traverse(struct node *p)
{
  struct Stack st;
  createStack(&st, 100);
  int i;
  while (p != NULL)
  {
    push(&st, p->data);
    p = p->next;
  }
  displayStack(st);
  while (first != NULL)
  {
    i = st.S[st.top];
    if (first->data != i)
      return 0;
    pop(&st);
    first = first->next;
  }
  return 1;
}
int main()
{
  struct Stack st;
  int n;
  char x;
  printf("Enter the size:");
  scanf("%d", &n);
  create(first, n);
  printf("The linked list is\n");
  display(first);
  printf("\n");
  int result = traverse(first);
  if (result == 1)
    printf("\nIs Palindrome!!");
  else
    printf("\nNot a Palindrome!!");
  return 0;
}