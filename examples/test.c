#include <stdio.h>
#include <libqueue.h>

int main() {

	struct queue *q = queue_new();

	int a = 10;
	char *b = "Hello World";

	queue_push(q, (void*) &a);
	queue_push(q, (void*) b);

	int *k = queue_pop(q);
	char *l = queue_pop(q);

	printf("%d\n", *k);
	printf("%s\n", l);

	queue_free(q);

	return 0;
}