#include <stdbool.h>
#include <sys/types.h>

#ifndef __LIBQUEUE_H
#define __LIBQUEUE_H

struct queue_node {
	void* value;
	struct queue_node* next;
};

struct queue {
	u_int32_t size;
	struct queue_node *head;
	struct queue_node* tail;
};

struct queue* queue_new();

void queue_push(struct queue *queue, void *value);
void* queue_pop(struct queue *queue);

void* queue_front(struct queue *queue);
void* queue_back(struct queue *queue);

bool queue_empty(struct queue *queue);

void queue_free(struct queue *queue);

#endif