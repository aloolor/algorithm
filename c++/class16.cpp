// class MyCircularDeque {

// private:
//     typedef struct node{
//         int val;
//         struct node* next;
//         struct node* last;
//     } node;

//     node *head;   // 指向队列的头部
//     node *tail;   // 指向队列的尾部
//     int capacity; // 队列的容量
//     int size;     // 当前队列的大小

// public:
//     MyCircularDeque(int k) {
//         capacity = k;
//         size = 0;
//         head = nullptr;
//         tail = nullptr;
//     }
    
//     ~MyCircularDeque() {
//         // 析构函数中释放链表中的节点
//         while (head != nullptr) {
//             node* temp = head;
//             head = head->next;
//             delete temp;
//         }
//     }
    
//     bool insertFront(int value) {
//         if (isFull()) return false;
//         node* newNode = new node();
//         newNode->val = value;
//         newNode->next = head;
//         newNode->last = nullptr;
        
//         if (isEmpty()) {
//             head = tail = newNode;
//         } else {
//             head->last = newNode;
//             head = newNode;
//         }
//         size++;
//         return true;
//     }
    
//     bool insertLast(int value) {
//         if (isFull()) return false;
//         node* newNode = new node();
//         newNode->val = value;
//         newNode->next = nullptr;
//         newNode->last = tail;
        
//         if (isEmpty()) {
//             head = tail = newNode;
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//         }
//         size++;
//         return true;
//     }
    
//     bool deleteFront() {
//         if (isEmpty()) return false;
//         node* temp = head;
//         if (head == tail) { // 只有一个节点的情况
//             head = tail = nullptr;
//         } else {
//             head = head->next;
//             head->last = nullptr;
//         }
//         delete temp;
//         size--;
//         return true;
//     }
    
//     bool deleteLast() {
//         if (isEmpty()) return false;
//         node* temp = tail;
//         if (head == tail) { // 只有一个节点的情况
//             head = tail = nullptr;
//         } else {
//             tail = tail->last;
//             tail->next = nullptr;
//         }
//         delete temp;
//         size--;
//         return true;
//     }
    
//     int getFront() {
//         if (isEmpty()) return -1;
//         return head->val;
//     }
    
//     int getRear() {
//         if (isEmpty()) return -1;
//         return tail->val;
//     }
    
//     bool isEmpty() {
//         return size == 0;
//     }
    
//     bool isFull() {
//         return size == capacity;
//     }
// };


class MyCircularDeque {
private:
    int* deque;
    int l , r , size , limit;

public:
    MyCircularDeque(int k) {
        deque = new int[k];
        l = r = size = 0;
        limit = k;
    }
    
    bool insertFront(int value) {
        
        if(isFull()){
            return false;
        }else{
            if(isEmpty()){
                l = r = 0;
                deque[l] = value;
            }else if(l == 0){
                l = limit - 1;
                deque[l] = value;
            }else{
                deque[--l] = value;
            }
            size++;
            return true;
        }

    }
    
    bool insertLast(int value) {
        if(isFull()){  
            return false;
        }else{
            if(isEmpty())
            {
                l = r = 0;
                deque[r] = value;
            }else if(r == limit -1){
                r = 0;
                deque[r] = value;
            }else{
                deque[++r] = value;
            }
            size++;
            return true;
        } 


    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }else{
            if(l == limit-1){
                l = 0;
            }else{
                l++;
            }
            size--;
            return true;
            
        } 
        
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }else{
            if(r == 0){
            r = limit - 1;

        }else{
            r--;

        }
        size--;
        return true;
        } 
        
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }else{
            return deque[l];
        }
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }else{
            return deque[r];
        }
    }
    
    bool isEmpty() {
        return size == 0;
        
    }
    
    bool isFull() {
        return size == limit;
        
    }
    ~MyCircularDeque(){
        delete[] deque;

    }
};