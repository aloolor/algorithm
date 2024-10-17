#include <iostream>
#include <stack>
#include <queue>

using namespace std;
/*
通过栈实现队列

两个栈：in，out
通过out栈实现数据的先进先出
需要有一个倒数据的过程，但是不能随时进行
1.out为空，才能倒
2.如果要倒，in必须都倒完 




栈：
push() ：入栈。在栈顶添加一个元素，无返回值；
pop() ：出栈。将栈顶元素删除（出队），无返回值；
top() ：获得栈顶元素。此函数返回值为栈顶元素，常与pop()函数一起，先通过top()获得栈顶元素，然后将其从栈中删除；
size() ：获得栈大小。此函数返回栈的大小，返回值也是“size_t”类型的数据，“size_t”是“unsigned int”的别名。
empty() ：判断栈是否为空。此函数返回栈是否为空，返回值是bool类型。栈空：返回true；不空：返回false。

*/
class MyQueue {
public:
        stack<int> in;
        stack<int> out;
    MyQueue() {

    }
        void inToOut()
    {
        if(out.empty()){
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
    }
    void push(int x) {
        in.push(x);
        inToOut();
    }
    
    int pop() {
        inToOut();
        int a = out.top();
        out.pop();
        return a;
    }
    
    int peek() {
        inToOut();
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};



/*
队列：
push() ：入队。在队列尾端添加一个元素，无返回值；
pop() ：出队。将队列头部元素删除（出队），无返回值；
front() ：获得队列头部元素。此函数返回值为队列的头部元素，常与pop()函数一起，先通过front()获得队列头部元素，然后将其从队列中删除；
size() ：获得队列大小。此函数返回队列的大小，返回值是“size_t”类型的数据，“size_t”是“unsigned int”的别名。
empty() ：判断队列是否为空。此函数返回队列是否为空，返回值是bool类型。队列空：返回true；不空：返回false。
back() ：返回队列尾部元素，就是队列中最后一个进去的元素。
*/
class MyStack {
private:
    queue<int> queue;
public:
    MyStack() {

    }
    
    void push(int x) {
        queue.push(x);
        // 将队列中除了新插入的元素外的所有元素依次重新入队
        int n = queue.size() - 1;  // 处理前面所有的元素
        while (n--) {
            queue.push(queue.front());
            queue.pop();
        }
        
    }
    
    int pop() {
        int a = queue.front();
        queue.pop();
        return a;
    }
    
    int top() {
        return queue.front();
    }
    
    bool empty() {
        return queue.empty();
    }
};

