#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	node *next;
};
typedef struct node node_t;

node_t *head = NULL;

void push(int n)
{
	node_t *newNode = (node_t *)malloc(sizeof(node_t));
	newNode->data = n;
	newNode->next = NULL;

	if(head == NULL) {
		head = newNode;
		return;
	}

	node_t *cur = head;
	while(cur) {
		if(cur->next==NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void pop()
{
	if(head==NULL) return;
	node_t *tmp = head;
	head = head->next;
	free(tmp);
}

void display()
{
	node_t *cur = head;
	while(cur) {
		printf("%3d",cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int main()
{
	push(1);push(2);push(3);push(4);push(5);display();
	pop();display();
	pop();display();
	pop();display();
	pop();display();
	pop();display();
	return 0;
}