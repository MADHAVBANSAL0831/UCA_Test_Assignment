typedef struct {
    int *arr;
    int size;
    int front;
    int rear;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->arr = (int*)malloc(sizeof(int)*k);
    obj->size=k;
    obj->rear=-1;
    obj->front=-1;
    return obj;
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->front ==-1)
    return 1;

    return 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if((obj->front==obj->rear+1) || (obj->front==0 && obj->rear == obj->size-1))
    return 1;

    return 0;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
     if(myCircularQueueIsFull(obj))
      return 0;
    else {
        if (obj->front == -1) obj->front = 0;
        obj->rear = (obj->rear + 1) % obj->size;
        obj->arr[obj->rear] = value;
    }

    return 1;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
    {
        return 0;
    }
    else
    {
        if (obj->front == obj->rear) {
        obj->front = -1;
        obj->rear = -1;
        } 
        else {
        obj->front = (obj->front + 1) % obj->size;
        }
    }

    return 1;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
    return -1;
    else
    {
        int element = obj->arr[obj->front];
        return element;
    }

    return 1;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
    return -1;
    else
    {
        int element = obj->arr[obj->rear];
            return element;
    }

    return 1;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/