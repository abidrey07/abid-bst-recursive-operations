# Mini-Lab: BST Recursive Operations

**Estimated Time:** 20-30 minutes
**Difficulty:** Medium

## Overview

In this mini-lab, you'll implement four recursive functions for a Binary Search Tree (BST). This will give you hands-on practice with:
- Recursive thinking and base cases
- Tree traversal
- BST properties

## Starter Code

You are provided with `bst-starter.cpp` which includes:
- Complete `TreeNode` struct
- Working `insert()` function
- Function stubs for you to implement
- Test cases in `main()`

## Your Tasks

Implement the following four recursive functions:

### 1. `countNodes()` - Count Total Nodes

```cpp
int countNodes(TreeNode* node)
```

Count and return the total number of nodes in the tree.

**Hints:**
- Base case: What's the count for an empty tree (nullptr)?
- Recursive case: Count = 1 (current node) + nodes in left subtree + nodes in right subtree

**Example:**
```
Tree:     5
         / \
        3   7
       /
      1

countNodes() should return 4
```

---

### 2. `findHeight()` - Find Tree Height

```cpp
int findHeight(TreeNode* node)
```

Find and return the height of the tree. Height is defined as the number of edges on the longest path from root to leaf.

**Hints:**
- Base case: Empty tree (nullptr) has height -1
- Recursive case: Height = 1 + max(left height, right height)

**Example:**
```
Tree:     5
         / \
        3   7
       /
      1

findHeight() should return 2 (path: 5 -> 3 -> 1)
```

---

### 3. `contains()` - Search for Value

```cpp
bool contains(TreeNode* node, int target)
```

Search the tree for a target value. Return `true` if found, `false` otherwise.

**Hints:**
- Base case 1: Empty tree (nullptr) means not found
- Base case 2: Current node contains the target value
- Recursive case: Use BST property to search left or right subtree
  - If target < current value, search left
  - If target > current value, search right

**Example:**
```
Tree:     5
         / \
        3   7
       /
      1

contains(tree, 3) should return true
contains(tree, 6) should return false
```

---

### 4. `findMin()` - Find Minimum Value

```cpp
int findMin(TreeNode* node)
```

Find and return the minimum value in the tree. Assumes tree is not empty.

**Hints:**
- Think about BST properties: where is the minimum value located?
- Base case: When you can't go any further left
- Recursive case: Keep going left

**Example:**
```
Tree:     5
         / \
        3   7
       /
      1

findMin() should return 1
```

---

## Testing

The provided `main()` function creates this test tree:

```
        10
       /  \
      5    15
     / \   / \
    3   7 12  20
```

And tests all your functions with expected outputs shown.

## Steps to Complete

1. Download `bst-starter.cpp`
2. Read through the starter code to understand the structure
3. Implement each function one at a time:
   - Start with `countNodes()` (simplest)
   - Then `findHeight()`
   - Then `contains()`
   - Finally `findMin()`
4. After implementing each function, compile and test:
   ```bash
   g++ -std=c++11 bst-starter.cpp -o bst
   ./bst
   ```
5. Verify your output matches the expected output

## Expected Output

```
=== BST Recursive Operations Test ===

Test Tree Structure:
        10
       /  \
      5    15
     / \   / \
    3   7 12  20

countNodes(): 7
findHeight(): 2
contains(7): true
contains(8): false
findMin(): 3

All tests complete!
```

## Submission

Submit your completed `bst-starter.cpp` file (you can rename it if you'd like).

## Tips

- Start with the base case(s) for each function
- Then think about how to break down the problem recursively
- Use the BST property in `contains()` to make the search efficient
- Test frequently as you implement each function
- Remember: recursion works by trusting that your function works on smaller inputs
