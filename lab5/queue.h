#ifndef QUEUE_H
#define QUEUE_H

struct queue;
typedef struct queue queue_t;

int create(queue_t* q);
void createCopy(queue_t* old_q, queue_t* new_q);
int enqueue(queue_t *q, int value);
int dequeue(queue_t *q);
int peak(queue_t* q);
int delete_q(queue_t* q);

#endif //QUEUE_H
