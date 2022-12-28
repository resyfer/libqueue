# libqueue

A generic C library for a a queue. Pretty easy to use. For instructions on usage, please go [here](#usage).
For installation, please go [here](#installation). For documentation, please go [here](#documentation).

Also, technically can hold any data type, including multiple ones at once (your headache on which is of which data type when popped 😆).

## Usage

### TL;DR

The shown below is a tl;dr version. Proper instructions are [here](#step-1)

```c
#include <libqueue/libqueue.h>
#include <stdio.h>

int main() {
  struct queue *q = queue_new();

  int a = 10;
  char *b = "Hello World";

  queue_push(q, (void*) &a);
  queue_push(q, (void*) &b);

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
#include <libqueue/libqueue.h>
```

**NOTE**: Link the library when compiling

```bash
$ gcc a.c -o a.o -lqueue
```

### Step 2

Initialize an empty queue:

```c
struct queue *q = queue_new();
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
struct queue* queue_new();
```

### Push-Pop

```c
void queue_push(struct queue *queue, void *value);
void* queue_pop(struct queue *queue);
```

### Peek

```c
void* queue_front(struct queue *queue);
void* queue_back(struct queue *queue);
```

### Free

```c
void queue_free(struct queue *queue);
```

### Misc

```c
bool queue_empty(struct queue *queue); // Checks if queue is empty
```
