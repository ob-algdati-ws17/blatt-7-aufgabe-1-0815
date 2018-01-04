#ifndef BLATT_7_AUFGABE_1_0815_AVLTREE_H
#define BLATT_7_AUFGABE_1_0815_AVLTREE_H

#include <ostream>

class avlTree {
public:
    // everything public for easier testing
    struct Node {
        int val;
        int bal=0;
        Node *prev= nullptr;
        Node *left= nullptr;
        Node *right= nullptr;
        Node(int);
    };

    Node *root;

    void rotateLeft(Node *);
    void rotateRight(Node *);
    void upin(Node *);
    void upout(Node *);

    bool contains(int value);
    bool insert(int value);
    bool remove(int value);

};

#endif //BLATT_7_AUFGABE_1_0815_AVLTREE_H
