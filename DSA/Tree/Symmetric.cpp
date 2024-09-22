// Problem Statement: Given a Binary Tree, determine whether the given tree is symmetric or not. A Binary Tree would be Symmetric, when its mirror image is exactly the same as the original tree. If we were to draw a vertical line through the centre of the tree, the nodes on the left and right side would be mirror images of each other.

// intuitive approach:  we can use the level order traversal to check if the tree is symmetric or not.
// we can use the queue to store the nodes of the tree and then check if the nodes are symmetric or not.
// if the nodes are symmetric then we can return true else we can return false.

// Pseudo code:
// 1. if the root is null then return true.
// 2. create a queue and push the root node into the queue.
// 3. while the queue is not empty, we can pop the front element and store it in a variable.
// 4. if the popped element is null then we can push the null into the queue.
// 5. if the popped element is not null then we can push the left and right child of the popped element into the queue.
// 6. if the left child and right child are not equal then we can return false.
// 7. if the left child and right child are equal then we can continue the process.
// 8. if the queue is empty then we can return true.
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty, hence symmetric." << endl;
        return true;
    }

    // create a queue to store the nodes of the tree
    queue<TreeNode *> q;
    q.push(root);
    q.push(root); // push the root node twice into the queue.

    // while the queue is not empty
    while (!q.empty())
    {
        // pop the front element and store it in a variable
        TreeNode *t1 = q.front();
        q.pop();
        TreeNode *t2 = q.front();
        q.pop();

        cout << "Comparing nodes: "
             << (t1 ? to_string(t1->val) : "NULL") << " and "
             << (t2 ? to_string(t2->val) : "NULL") << endl;

        // if the popped element is null then push the null into the queue
        if (t1 == NULL && t2 == NULL)
        {
            cout << "Both nodes are NULL, continue to next pair." << endl;
            continue;
        }

        // if one of the nodes is null, or values don't match, it's not symmetric
        if (t1 == NULL || t2 == NULL || t1->val != t2->val)
        {
            cout << "Nodes are not symmetric." << endl;
            return false;
        }

        // Enqueue children in the required order
        q.push(t1->left);
        q.push(t2->right);
        q.push(t1->right);
        q.push(t2->left);

        cout << "Enqueued children: ("
             << (t1->left ? to_string(t1->left->val) : "NULL") << ", "
             << (t2->right ? to_string(t2->right->val) : "NULL") << "), ("
             << (t1->right ? to_string(t1->right->val) : "NULL") << ", "
             << (t2->left ? to_string(t2->left->val) : "NULL") << ")" << endl;
    }

    cout << "Tree is symmetric." << endl;
    return true;
}

int main()
{
    // create a tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(-1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(-1);
    root->right->right = new TreeNode(4);

    // check if the tree is symmetric or not
    if (isSymmetric(root))
    {
        cout << "The tree is symmetric" << endl;
    }
    else
    {
        cout << "The tree is not symmetric" << endl;
    }

    return 0;
}
