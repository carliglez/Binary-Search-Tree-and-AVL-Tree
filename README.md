# Binary Search Trees (BST) and AVL Trees in C++

## Overview

This project implements two types of binary search trees: **Binary Search Tree (BST)** and **Balanced Binary Search Tree (AVL)** using C++. The implementation utilizes generic types, dynamic polymorphism, and operator overloading to define and manipulate these tree data structures. 

The main goals of this project are:
- Implementing the binary search tree (BST) where each node satisfies:
  - The root value of each subtree is greater than the values of the nodes in its left subtree.
  - The root value is less than the values of the nodes in its right subtree.
  
- Implementing the balanced binary search tree (AVL), where the height difference between the left and right subtrees of every node is at most 1. When this balance condition is violated due to node insertion or deletion, the tree is rebalanced using rotations:
  - Left-Left (LL)
  - Right-Right (RR)
  - Left-Right (LR)
  - Right-Left (RL)

The program provides a generic abstract data type `AB<Key>`, from which the `BST<Key>` and `AVL<Key>` types are derived, allowing the creation and manipulation of these trees.

### Operations Supported by Binary Trees
The implemented tree structures support the following operations:

- **Insert**: Add a new key to the tree.
- **Search**: Check if a given key exists in the tree.
- **Traverse**: Traverse the tree nodes in different orders:
  - **In-order traversal**: Visit nodes in the order: left subtree - root - right subtree.
  - **Level-order traversal**: Visit nodes level by level, from the root downwards, and within each level from left to right.

### Trace Mode for AVL Trees

The program includes a "trace mode" to visualize the balancing operations in AVL trees. When an imbalance occurs, the program displays:
- The tree before the rotation.
- The type of rotation (LL, RR, LR, RL).
- The node where the rotation is applied.

The trace mode is activated at compile time using a preprocessor directive, allowing the user to include or exclude this feature.

## Program Functionality

The program behaves as follows:

1. The key type `Key = long` is used for all operations.
2. The user is prompted to select the type of binary tree to create: **BST** or **AVL**.
3. An empty tree is generated based on the user's choice.
4. The program provides a menu with the following options:
   - [0] Exit
   - [1] Insert key
   - [2] Search key
   - [3] Display tree (in-order traversal)
   
5. For each insertion or search, the program prompts the user to input a key value and performs the operation.
6. After each insertion, the program displays the resulting tree using level-order traversal, with operator overloading used to show the structure.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
