#ifndef __LIBQUEUE_H
#define __LIBQUEUE_H

#include <stdbool.h>
#include <sys/types.h>

struct __queue_node {
	void* value;
	struct __queue_node* next;
};
typedef struct __queue_node queue_node_t;

typedef struct {
	u_int32_t size;
	queue_node_t* head;
	queue_node_t* tail;
} queue_t;

queue_t* queue_new();

void queue_push(queue_t *queue, void *value);
void* queue_pop(queue_t *queue);

void* queue_front(queue_t *queue);
void* queue_back(queue_t *queue);

bool queue_empty(queue_t *queue);

void queue_free(queue_t *queue);

#endif