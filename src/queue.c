#include <stdlib.h>
#include <stdio.h>

#include <include/queue.h>

queue_t*
queue_new()
{
	queue_t *new_queue = malloc(sizeof(queue_t));
	new_queue->head = NULL;
	new_queue->tail = NULL;
	new_queue->size = 0;
	return new_queue;
}

bool
queue_empty(queue_t *queue)
{
	return queue->size == 0;
}

void
queue_push(queue_t *queue, void *value)
{
	if(!queue || !value) {
		return;
	}

	queue_node_t *new_node = malloc(sizeof(queue_node_t));
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
queue_pop(queue_t *queue)
{
	if(!queue) {
		return NULL;
	}

	if(queue_empty(queue)) {
		return NULL;
	}

	queue_node_t *elem = queue->head;
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
queue_front(queue_t *queue)
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
queue_back(queue_t *queue)
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
queue_free(queue_t *queue)
{
	queue_node_t *temp = queue->head;

	while(temp) {
		queue_node_t *temp2 = temp;
		temp = temp->next;
		free(temp2);
	}

	free(queue);
}