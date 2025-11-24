#include <iostream>
#include <algorithm>
using namespace std;

// TreeNode structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert function (already implemented for you)
TreeNode* insert(TreeNode* node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    }

    return node;
}

// ============================================
// TODO: Implement the following functions
// ============================================

/**
 * Count the total number of nodes in the tree
 *
 * Base case: What should you return for an empty tree?
 * Recursive case: Current node (1) + left subtree + right subtree
 */
int countNodes(TreeNode* node) {
    int count = 0;
    if (node != nullptr) {
        count = 1 + countNodes(node->left) + countNodes(node->right);
    }
    return count;
}

/**
 * Find the height of the tree
 * Height = number of edges on longest path from root to leaf
 *
 * Base case: Empty tree has height -1
 * Recursive case: 1 + max(left height, right height)
 * Hint: You can use max() from <algorithm>
 */
int findHeight(TreeNode* node) {
    if (node == nullptr) return -1;  // Replace this
    return 1 + max(findHeight(node->left), findHeight(node->right));
}

/**
 * Search for a target value in the tree
 * Returns true if found, false otherwise
 *
 * Base case 1: Empty tree means not found
 * Base case 2: Current node contains target
 * Recursive case: Use BST property to search left or right
 */
bool contains(TreeNode* node, int target) {
    if (node == nullptr) return false;
    else if (node->data == target) return true;
    else if (node->data > target) return contains(node->left, target);
    else if (node->data < target) return contains(node->right, target);
}

/**
 * Find the minimum value in the tree
 * Assumes the tree is not empty
 *
 * Hint: In a BST, where is the minimum value?
 * Base case: When you can't go left anymore
 * Recursive case: Keep going left
 */
int findMin(TreeNode* node) {
    if (node->left == nullptr) {
        return node->data;
    } else return findMin(node->left);
}

// ============================================
// Test code (DO NOT MODIFY)
// ============================================

int main() {
    cout << "=== BST Recursive Operations Test ===" << endl << endl;

    // Build test tree
    TreeNode* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    cout << "Test Tree Structure:" << endl;
    cout << "        10" << endl;
    cout << "       /  \\" << endl;
    cout << "      5    15" << endl;
    cout << "     / \\   / \\" << endl;
    cout << "    3   7 12  20" << endl;
    cout << endl;

    // Test countNodes
    cout << "countNodes(): " << countNodes(root) << endl;
    cout << "Expected: 7" << endl << endl;

    // Test findHeight
    cout << "findHeight(): " << findHeight(root) << endl;
    cout << "Expected: 2" << endl << endl;

    // Test contains
    cout << "contains(7): " << (contains(root, 7) ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    cout << "contains(8): " << (contains(root, 8) ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;

    // Test findMin
    cout << "findMin(): " << findMin(root) << endl;
    cout << "Expected: 3" << endl << endl;

    cout << "All tests complete!" << endl;

    return 0;
}
