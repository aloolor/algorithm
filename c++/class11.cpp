#include <iostream>
#include <queue>
#include <stack>

class Queue1{
    public:
    std::queue<int> queue;

    //调用方法之前，判断队列内是否有东西
    bool isEmpty(){
        return queue.empty();
    }

    void offer(int num ){
        queue.push(num);
    }

    int poll(){
        int front = queue.front();
        queue.pop();
        return front;
    }
    
    int peek(){
        return queue.front();
    }

    int size(){
        return queue.size();
    }

};

class Queue2{
    public:
    int *queue;
    int l;
    int r;
    int limit;

    Queue2(int n){
        queue = new int[n];
        l = 0;
        r = 0;
        limit = n;
    }
    bool isEmpty(){
        return l == r;
    }

    void offer(int num){
        queue[r] = num;
        r++;
    }

    int pool(){
        return queue[l++];
    }

    int head(){
        return queue[r];
    }
    int tail(){
        return queue[l];
    }
    int size(){
        return r-l;
    }
    ~Queue2(){
        delete[] queue;
    }

};

class Stack1{
    public:
    std::stack<int> stack;

    bool isEmpty(){
        return stack.empty();
    }

    void push(int num){
        stack.push(num);
    }
    int pop(){
        int top = stack.top();
        stack.pop();
        return top;
    }

    int peek(){
        return stack.top();
    }
    int size(){
        return stack.size();
    }
};

class Stack2
{
    public:
    int* stack;
    int size;

    Stack2(int n){
        stack = new int[n];
        size = 0;
    }

    bool empty(){
        return size == 0;
    }

    void push(int num){
        stack[size++] = num;
    }

    int  pop(){
        return stack[size--];
    }

    int peek(){
        return stack[size - 1];
    }

    int size(){
        return size;
    }
    ~Stack2(){
        delete[] stack;
    }
};


class MyCircularQueue{
    public:
    int* queue;
    int r,l,size,limit;

    MyCircularQueue(int k){
        queue = new int[k];
        r = l = size = 0;
        limit = k;

    }


    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == limit;
    }

    bool enQueue(int value){
        if(isFull()){
            return false;
        }else{
            queue[r] = value;
            r = (r + 1) % limit;
            
        }
    }



};