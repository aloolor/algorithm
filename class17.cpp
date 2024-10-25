#include <iostream>
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

void preOrder(TreeNode* head)
{
    if(head == nullptr){
        return;
    }
    cout << head->val << endl;
    preOrder(head->left);
    preOrder(head->right);
}

void inOrder(TreeNode* head)
{
    if(head == nullptr){
        return;
    }
    inOrder(head->left);
    cout << head->val << endl;
    inOrder(head->right);
}
void posOrder(TreeNode* head) {
    if (head == nullptr) {
        return;
    }
    posOrder(head->left);
    posOrder(head->right);
    cout << head->val << endl;
}

int main() {
    // 创建二叉树
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(7);

    // 先序遍历
    preOrder(head);
    cout << endl << "先序遍历递归版" << endl;

    // 中序遍历
    inOrder(head);
    cout << endl << "中序遍历递归版" << endl;

    // 后序遍历
    posOrder(head);
    cout << endl << "后序遍历递归版" << endl;

    // 释放内存
    delete head->left->left;
    delete head->left->right;
    delete head->right->left;
    delete head->right->right;
    delete head->left;
    delete head->right;
    delete head;

    return 0;
}