// -------------------------------------------------------------
// Algoritmos e Estruturas de Dados 2024/2025 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2425/
// -------------------------------------------------------------
// Binary Tree
// Last update: 09/11/2024
// -------------------------------------------------------------

#ifndef BTREE_H
#define BTREE_H

#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>

template <class T> class BTree {
  private:
    struct Node {
        T     value;        // The value stored on the node
        Node *left, *right; // Pointers to left and right child
    };

    // The tree
    Node *root; // Pointer to the root node

  public:
    // Constructor: initially the tree is empty
    BTree() { root = nullptr; }

    // Destructor: delete all nodes (garbage collection) [see slide 33]
    ~BTree() { destroy(root); }

    // Recursively delete left and right subtrees and then current node
    void destroy(Node *n) {
        if (n == nullptr) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }

    // ---------------------------------------------------------
    // Count the number of nodes (see slides 13 and 14)
    // ---------------------------------------------------------

    int numberNodes() { return numberNodes(root); }

    int numberNodes(Node *n) {
        if (n == nullptr) return 0;
        return 1 + numberNodes(n->left) + numberNodes(n->right);
    }

    // ---------------------------------------------------------
    // Height of the tree (see slides 15 and 16)
    // ---------------------------------------------------------

    int height() { return height(root); }

    int height(Node *n) {
        if (n == nullptr) return -1;
        return 1 + std::max(height(n->left), height(n->right));
    }

    // ---------------------------------------------------------
    // Does the tree contain value 'val'? (see slides 17 and 18)
    // ---------------------------------------------------------

    bool contains(const T &val) { return contains(root, val); }

    bool contains(Node *n, const T &val) {
        if (n == nullptr) return false;
        if (n->value == val) return true;
        return contains(n->left, val) || contains(n->right, val);
    }

    // ---------------------------------------------------------
    // Print tree in PreOrder (see slides 20 and 21)
    // ---------------------------------------------------------

    void printPreOrder() {
        std::cout << "PreOrder:";
        printPreOrder(root);
        std::cout << std::endl;
    }

    void printPreOrder(Node *n) {
        if (n == nullptr) return;
        std::cout << " " << n->value;
        printPreOrder(n->left);
        printPreOrder(n->right);
    }

    // ---------------------------------------------------------
    // Print tree in InOrder (see slides 22 and 23)
    // ---------------------------------------------------------

    void printInOrder() {
        std::cout << "InOrder:";
        printInOrder(root);
        std::cout << std::endl;
    }

    void printInOrder(Node *n) {
        if (n == nullptr) return;
        printInOrder(n->left);
        std::cout << " " << n->value;
        printInOrder(n->right);
    }

    // ---------------------------------------------------------
    // Print tree in PostOrder (see slides 22 and 24)
    // ---------------------------------------------------------

    void printPostOrder() {
        std::cout << "PostOrder:";
        printPostOrder(root);
        std::cout << std::endl;
    }

    void printPostOrder(Node *n) {
        if (n == nullptr) return;
        printPostOrder(n->left);
        printPostOrder(n->right);
        std::cout << " " << n->value;
    }

    // ---------------------------------------------------------
    // Print tree in Breadt-First order using a queue
    // (see slides 25, 26 and 27)
    // ---------------------------------------------------------

    void printBFS() {
        std::cout << "BFS:";

        std::queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *cur = q.front();
            q.pop();
            if (cur != nullptr) {
                std::cout << " " << cur->value;
                q.push(cur->left);
                q.push(cur->right);
            }
        }

        std::cout << std::endl;
    }

    // ---------------------------------------------------------
    // Print tree in Depth-First order using a stack
    // (see slides 28 and 29)
    // ---------------------------------------------------------

    void printDFS() {
        std::cout << "DFS:";

        std::stack<Node *> s;
        s.push(root);
        while (!s.empty()) {
            Node *cur = s.top();
            s.pop();
            if (cur != nullptr) {
                std::cout << " " << cur->value;
                s.push(cur->left);
                s.push(cur->right);
            }
        }

        std::cout << std::endl;
    }

    // ---------------------------------------------------------
    // Read a tree in PreOrder from standard input
    // (see slides 30, 31 and 32)
    // ---------------------------------------------------------

    void read(std::string null) { root = readNode(null); }

    Node *readNode(std::string null) {
        std::string buffer;
        std::cin >> buffer;
        if (buffer == null) return nullptr;
        Node              *n = new Node;
        std::istringstream ss(buffer);
        ss >> n->value;
        n->left  = readNode(null);
        n->right = readNode(null);
        return n;
    }

    // ---------------------------------------------------------
    // TODO: put the functions you need to implement below this
    // ---------------------------------------------------------

    std::string maxSum() {
        std::pair<std::string, int> path = maxSum({ "", 0 }, this->root);
        return path.first;
    }

    std::pair<std::string, int> maxSum(std::pair<std::string, int> path, Node *n) {
        if (n == nullptr) return path;
        path.second += n->value;

        if (n->left == nullptr and n->right == nullptr) return path;

        auto left   = path;
        left.first += "L";

        auto right   = path;
        right.first += "R";

        left  = maxSum(left, n->left);
        right = maxSum(right, n->right);

        return left.second > right.second ? left : right;
    }
};


#endif
