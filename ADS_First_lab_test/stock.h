#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED
#include "appconst.h"

typedef struct _stock_ Stock;

struct _stock_{
    char name[20];
    char date[20];
    int64_t price;
    int32_t quantity;


};

typedef struct _queue_ Queue;


struct _queue_ {
    uint64_t rear;
    uint64_t front;
    uint64_t queuesize;
    uint64_t count;
    int64_t data[Q_LEN];
};


struct _result_ Result{
    TradingQ share;
    uint32_t status;
};


Queue queue_new(uint32_t size);
uint8_t queue_full(Queue *q);
uint8_t queue_empty(Queue *q);
Queue* queue_add(Queue *q, TradingQ share, QueueResult *res);
Queue* queue_delete(Queue *q, QueueResult *res);
Queue* look_up(Queue * q, TradingQ share );
Queue* topup(Queue *q, TradingQ share, int32_t quantity);
uint32_t queue_length(Queue *q);

#endif // STOCK_H_INCLUDED
