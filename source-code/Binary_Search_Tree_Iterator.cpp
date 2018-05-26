/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> nodeStack;
    
    void pushAllLefts(TreeNode* node) {
        while(node) {
            nodeStack.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode *root) {
        pushAllLefts(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodeStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* current = nodeStack.top();
        nodeStack.pop();
        pushAllLefts(current->right);
        return current->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */


// more than O(h) extra space
// O(n) space
class BSTIterator {
    vector<int> nodes;
    vector<int>::iterator iter;
    
    void BSTIteratorUtils(TreeNode *node) {
        if(!node) return;
        BSTIteratorUtils(node->left);
        nodes.push_back(node->val);
        BSTIteratorUtils(node->right);
    }
    
public:
    BSTIterator(TreeNode *root) {
        nodes = vector<int>();
        BSTIteratorUtils(root);
        iter = nodes.begin();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return iter != nodes.end();
    }

    /** @return the next smallest number */
    int next() {
        return (*iter++);
    }
};
