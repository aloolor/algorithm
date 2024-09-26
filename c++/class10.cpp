#include <iostream>

class ListNode
{
    public:
    int val;
    ListNode* next;
    ListNode(int val) : val(val),next(nullptr){}
    ListNode(int val,ListNode* next) : val(val),next(next){}
};

class Solution
{
    public:
        ListNode* partition(ListNode* head,int x)
        {
            ListNode* leftHead = nullptr;
            ListNode* leftTail = nullptr;
            ListNode* rightHead = nullptr;
            ListNode* rightTail = nullptr;
            ListNode* next = nullptr;
            while(head != nullptr)
            {
                next = head->next;
                head->next = nullptr;

                
                    if(head->val < x)
                    {
                        if(leftHead == nullptr)
                        {
                            leftHead = head;
                        }else{
                            leftTail->next = head;
                        }
                        leftTail = head;

                    }else{
                        if(rightHead == nullptr)
                        {
                            rightHead = head;
                        }else{
                            rightTail->next = head;
                        }
                        rightTail = head;
                    }
                
               

                
            } if(leftHead == nullptr)
                {
                    return rightHead;
                }
                leftTail->next = rightHead;
                return leftHead;
        }
};