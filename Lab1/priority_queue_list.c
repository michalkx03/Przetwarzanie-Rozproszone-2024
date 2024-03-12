#include <stdio.h>
#include <stdlib.h>
#include "priority_queue_list.h"
#define _CRT_SECURE_NO_WARNINGS

void qlist(pqueue* head, void (*print_data)(void*)) {
	pqueue* p;

	for (p = head; p != NULL; p = p->next) {
		printf("%d: ", p->k);
		print_data(p->data);
		printf("\n");
	}

}

void qinsert(pqueue** phead, void* data, int k) {
	pqueue* new_ = (pqueue*)malloc(sizeof(pqueue));
	if (new_ == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new_->k = k;
	new_->data = data;
	new_->next = NULL;
	new_->prev = NULL;

	if (*phead == NULL) {
		*phead = new_;
	}
	else
	{
		pqueue* current = *phead;
		pqueue* prev = NULL;
		while (current != NULL && current->k<k) {
			prev = current;
			current = current->next;
		}
		if (prev == NULL) {
			new_->next = *phead;
			current->prev = new_;
			*phead = new_;
		}
		else {
			prev->next = new_;
			new_->prev = prev;
			new_->next = current;
			if (current != NULL) {
				current->prev = new_;
			}
		}
	}
}


void qremove(pqueue** phead, int k) {
	if (*phead == NULL) {
		return;
	}
	pqueue* curr = *phead;
	while (curr->k != k&&curr!=NULL) {
		curr = curr->next;
	}
	if(curr==NULL) {
		return;
	}
	if (curr->prev == NULL) {
		*phead = curr->next;
		if (*phead != NULL) {
			(*phead)->prev = NULL;
		}
	}
	else
	{
		curr->prev->next = curr->next;
		if(curr->next!=NULL)
			curr->next->prev = curr->prev;
	}
	free(curr);
}

