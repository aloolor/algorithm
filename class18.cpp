#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

//用一个栈完成先序遍历
vector<int> preorderTraversal(TreeNode* head){
    vector<int> ans;
    if(head != nullptr){
        stack<TreeNode*> s;
        s.push(head);
        while(!s.empty()){
            head = s.top();
            ans.push_back(head->val);
            s.pop();
            if(head->right != nullptr){
                s.push(head->right);
            }
            if(head->left != nullptr){
                s.push(head->left);
            }

        }

    }
    return ans;
}

//用一个栈完成中序遍历
/*
1.所有左子树进栈直到左为空
2.弹出栈顶，输出，右子树进栈重复1
3.栈为空并且没有子树循环结束
*/
vector<int> inorderTraversal(TreeNode* head){
    vector<int> ans;
    if(head != nullptr){
        stack<TreeNode*> s;
        while(!s.empty() || head != nullptr){
            if(head != nullptr){
                s.push(head);
                head = head->left;
            }else{
                head = s.top();
                s.pop();
                ans.push_back(head->val);
                head = head->right;
            }
        }

    }
    return ans;
}