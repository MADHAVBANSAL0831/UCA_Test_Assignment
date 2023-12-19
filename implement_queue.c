typedef struct {
    int *arr;
    int size;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->arr = (int*)malloc(sizeof(int)*10);
    obj->size=0;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    if(obj->size==0)
    {
        obj->arr[obj->size++]=x;
        return;
    }

    int ele = obj->arr[obj->size-1];
    obj->size--;
    myQueuePush(obj, x);
    obj->arr[obj->size++] = ele;
}

int myQueuePop(MyQueue* obj) {
    int ele = obj->arr[obj->size-1];
    obj->size--;
    return ele;
}

int myQueuePeek(MyQueue* obj) {
    int ele = obj->arr[obj->size-1];
    return ele;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->size ==0;
}

void myQueueFree(MyQueue* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/