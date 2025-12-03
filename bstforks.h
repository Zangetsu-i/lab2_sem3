#ifndef BSTFORKS_H
#define BSTFORKS_H

#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

inline void insert(Node*& root, int x) {
    if (!root) {
        root = new Node(x);
        return;
    }
    if (x < root->key) {
        insert(root->left, x);
    } else if (x > root->key) {
        insert(root->right, x);
    } else {

    }
}

inline void printForksInOrder(const Node* root) {
    if (!root) return;

    printForksInOrder(root->left);

    if (root->left && root->right) {
        std::cout << root->key << ' ';
    }

    printForksInOrder(root->right);
}

inline void destroy(Node* root) {
    if (!root) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

#endif
