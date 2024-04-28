#pragma once

#include <iostream>

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
};

class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        if (node == nullptr) { return 0; }
        return node->height;
    }

    int balanceFactor(Node* node) {
        if (node == nullptr) { return 0; }
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* balance(Node* node) {
        if (node == nullptr)
            return nullptr;

        node->height = std::max(height(node->left), height(node->right)) + 1;

        int bf = balanceFactor(node);

        if (bf > 1) {
            if (balanceFactor(node->left) < 0)
                node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        else if (bf < -1) {
            if (balanceFactor(node->right) > 0)
                node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            node = new Node;
            node->data = data;
            node->height = 1;
            node->left = nullptr;
            node->right = nullptr;
            return node;
        }

        if (data < node->data) {
            node->left = insert(node->left, data);
        }
        else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        else {
            return node;
        }

        return balance(node);
    }

    void inorderTraversalHelper(Node* node) {
        if (node == nullptr)
            return;
        inorderTraversalHelper(node->left);
        std::cout << node->data << " ";
        inorderTraversalHelper(node->right);
    }

    Node* search(Node* node, int data) {
        if (node == nullptr || node->data == data)
            return node;

        if (data < node->data)
            return search(node->left, data);
        else
            return search(node->right, data);
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* remove(Node* node, int data) {
        if (node == nullptr)
            return node;

        if (data < node->data)
            node->left = remove(node->left, data);
        else if (data > node->data)
            node->right = remove(node->right, data);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = node->left ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                }
                else
                    *node = *temp;
                delete temp;
            }
            else {
                Node* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }

        if (node == nullptr)
            return node;

        return balance(node);
    }

    void printTree(Node* node, int indent = 0, char branch = ' ') {
        if (node == nullptr) return;

        printTree(node->right, indent + 4, '/');

        for (int i = 0; i < indent; ++i) {
            std::cout << ' ';
        }

        std::cout << branch << "--" << node->data << std::endl;

        printTree(node->left, indent + 4, '\\');
    }

    void clearTree(Node* node) {
        if (node == nullptr) return;

        clearTree(node->left);
        clearTree(node->right);

        delete node;
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int data) {
        root = insert(root, data);
    }

    void remove(int data) {
        root = remove(root, data);
    }

    Node* search(int data) {
        return search(root, data);
    }

    void inorderTraversal() {
        inorderTraversalHelper(root);
    }

    void printTree() {
        printTree(root);
    }

    void clear() {
        clearTree(root);
        root = nullptr;
    }
};
