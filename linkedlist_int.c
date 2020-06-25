/*
James Sofios
Linked List for integers
June 3 2020
*/
#include <stdio.h>
#include <stdlib.h>

#define dequeue(l) pop(l)

typedef struct Node{
	int data;
	struct Node* next;
} node;

typedef struct List{
	unsigned int total;
	struct Node* head;
	struct Node* tail;
} list;

list* new_list(void)
{
	list* l = malloc(sizeof(list));
	l->total = 0;
	l->head = NULL;
	l->tail = NULL;
	return l;
}

void free_list(list* l)
{
	if(l){
		node* tmp;
		while(l->head){
			tmp = l->head;
			l->head = l->head->next;
			free(tmp);
			tmp = NULL;
			l->total--;
		}
		l->tail = NULL;

		free(l);
		l = NULL;
	}
	return;
}

void print_list(list* l)
{
	if(l && l->head && l->tail && l->total > 0){
		printf("Total elements: %d\n", l->total);
		printf("Head->");
		if(l->head){
			node* tmp;
			tmp = l->head;
			for(unsigned int i = 0; i < l->total; i++){
					printf("%d->", tmp->data);
					tmp = tmp->next;
			}
		}
		putchar('\n');
	} else {
		puts("List has nothing to print, has been freed, or has no elements.");
	}
	return;
}

void push(list* l, const int i)
{
	node* n = malloc(sizeof(node));
	if(n){
		n->data = i;
		n->next = NULL;
		if(l->tail == NULL)
			l->tail = n;
		n->next = l->head;
		l->head = n;
		l->total++;
	}
	return;
}

int pop(list* l)
{
	int r = 0;
	if(l && l->head && l->tail && l->total > 0){
		r = l->head->data;
		node* tmp;
		tmp = l->head->next;
		free(l->head);
		l->head = NULL;
		l->head = tmp;
		tmp = NULL;
		l->total--;
	} else {
		puts("Cannot pop. List head, list tail, or list itself is NULL. Or list total is zero.");
	}
	return r;
}

void enqueue(list* l, const int z)
{
	node* n = malloc(sizeof(node));
	if(n){
		n->data = z;
		n->next = NULL;
		if(l->head == NULL)
			l->head = n;
		if(l->tail == NULL)
			l->tail = n;
		if(l->tail != n){
			l->tail->next = n;
			l->tail = n;
		}
		l->total++;
	} else {
		puts("Cannot malloc() new node.");
	}
	return;
}

int main(void)
{
	list* l = new_list();

	int lim = 10;

	for(int i = 0; i < lim; i++){
		enqueue(l, i + 1);
	}

	print_list(l);

	for(int i = 0; i < lim; i++){
		printf("%d\n", dequeue(l));
	}

	free_list(l);
	l = NULL;

	return 0;
}
