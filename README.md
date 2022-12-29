# libqueue

A generic C library for a a queue. Pretty easy to use and can hold any data type. For instructions on usage, please go [here](#usage).
For installation, please go [here](#installation). For documentation, please go [here](#documentation).

## Usage

### TL;DR

The shown below is a tl;dr version. Proper instructions are [here](#step-1)

```c
#include <libqueue/queue.h>
#include <stdio.h>

int main() {

	queue_t *q = queue_new();

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
```

Compile and run:

```bash
$ gcc test.c -o test.o -lqueue
$ ./test.o
```

### Step 1

Import the library:

```c
#include <libqueue/queue.h>
```

**NOTE**: Link the library when compiling

```bash
$ gcc a.c -o a.o -lqueue
```

### Step 2

Initialize an empty queue:

```c
queue_t *q = queue_new();
```

### Step 3

To push:

```c
int a = 10;
queue_push(q, (void*) &a);
```

To pop:

```c
int *k = queue_pop(a);
```

**NOTE**: Memory management for items pushed into the queue is on you. Please consider scopes while using the queue. Also, you can use dynamic memory allocation for persistent values across scopes.

### Step 4

Free up the queue's allocated memory after use:

```c
queue_free(q);
```

## Installation

Make sure to have [make](https://www.gnu.org/software/make/), [gcc](https://www.gnu.org/software/gcc/) and [git](https://git-scm.com/) installed

```bash
git clone https://github.com/resyfer/libqueue.git
cd libqueue
make install
cd ..
rm -rf libqueue
```

Provide the password when prompted.

## Documentation

### Initialize

```c
queue_t* queue_new();
```

### Push-Pop

```c
void queue_push(queue_t *queue, void *value);
void* queue_pop(queue_t *queue);
```

### Peek

```c
void* queue_front(queue_t *queue);
void* queue_back(queue_t *queue);
```

### Free

```c
void queue_free(queue_t *queue);
```

### Misc

```c
bool queue_empty(queue_t *queue); // Checks if queue is empty
```
