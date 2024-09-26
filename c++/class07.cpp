#include <iostream>
using namespace std;

// 按值传递、按引用传递
// 从堆栈角度解释链表节点
// 以堆栈视角来看链表反转
class ListReverse {
public:
    static void main() {
        // int、long、byte、short
        // char、float、double、boolean
        // 还有string
        // 都是按值传递
        int a = 10;
        f(a);
        cout << a << endl;

        // 其他类型按引用传递
        // 比如下面的Number是自定义的类
        Number b(5);
        g1(&b);
        cout << b.val << endl;
        g2(b);
        cout << b.val << endl;

        // 比如下面的一维数组
        int c[] = { 1, 2, 3, 4 };
        g3(c);
        cout << c[0] << endl;
        g4(c);
        cout << c[0] << endl;
    }

    static void f(int a) {
        a = 0;
    }

    class Number {
    public:
        int val;

        Number(int v) {
            val = v;
        }
    };

    static void g1(Number* b) {
        b = nullptr;
    }

    static void g2(Number& b) {
        b.val = 6;
    }

    static void g3(int* c) {
        c = nullptr;
    }

    static void g4(int* c) {
        c[0] = 100;
    }

    // 单链表节点
    class ListNode {
    public:
        int val;
        ListNode* next;

        ListNode(int val) : val(val), next(nullptr) {}

        ListNode(int val, ListNode* next) : val(val), next(next) {}
    };

    // 反转单链表
    class Solution {
    public:
        static ListNode* reverseList(ListNode* head) {
            ListNode* pre = nullptr;
            ListNode* next = nullptr;
            while (head != nullptr) {
                next = head->next;
                head->next = pre;
                pre = head;
                head = next;
            }
            return pre;
        }
    };

    // 双链表节点
    class DoubleListNode {
    public:
        int value;
        DoubleListNode* last;
        DoubleListNode* next;

        DoubleListNode(int v) : value(v), last(nullptr), next(nullptr) {}
    };

    // 反转双链表
    static DoubleListNode* reverseDoubleList(DoubleListNode* head) {
        DoubleListNode* pre = nullptr;
        DoubleListNode* next = nullptr;
        while (head != nullptr) {
            next = head->next;
            head->next = pre;
            head->last = next;
            pre = head;
            head = next;
        }
        return pre;
    }
};

int main() {
    ListReverse::main();
    return 0;
}