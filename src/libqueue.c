#include <stdlib.h>
#include <stdio.h>

#include <include/libqueue.h>

struct queue *
queue_new()
{
	struct queue *new_queue = malloc(sizeof(struct queue));
	new_queue->head = NULL;
	new_queue->tail = NULL;
	new_queue->size = 0;
	return new_queue;
}

bool
queue_empty(struct queue *queue)
{
	return queue->size == 0;
}

void
queue_push(struct queue *queue, void *value)
{
	if(!queue || !value) {
		return;
	}

	struct queue_node *new_node = malloc(sizeof(struct queue_node));
	new_node->value = value;
	new_node->next = NULL;

	if(queue_empty(queue)) {
		queue->tail = new_node;
		queue->head = new_node;
	} else {
		queue->tail->next = new_node;
		queue->tail = new_node;
	}

	queue->size++;
}

void *
queue_pop(struct queue *queue)
{
	if(!queue) {
		return NULL;
	}

	if(queue_empty(queue)) {
		return NULL;
	}

	struct queue_node *elem = queue->head;
	queue->head = queue->head->next;

	void *value = elem->value;
	free(elem);

	if(queue->size == 1) {
		queue->tail = NULL;
	}

	queue->size--;

	return value;
}

void *
queue_front(struct queue *queue)
{
	if(!queue) {
		return NULL;
	}

	if(queue_empty(queue)) {
		return NULL;
	}

	return queue->head->value;
}

void *
queue_back(struct queue *queue)
{
	if(!queue) {
		return NULL;
	}

	if(queue_empty(queue)) {
		return NULL;
	}

	return queue->tail->value;
}

void
queue_free(struct queue *queue)
{
	struct queue_node *temp = queue->head;

	while(temp) {
		struct queue_node *temp2 = temp;
		temp = temp->next;
		free(temp2);
	}

	free(queue);
}