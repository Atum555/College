// -------------------------------------------------------------
// Algoritmos e Estruturas de Dados 2024/2025 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2425/
// -------------------------------------------------------------
// Singly Linked List
// Last update: 20/10/2024
// -------------------------------------------------------------

#ifndef SLLIST_H
#define SLLIST_H

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

// -------------------------------------------------------------
// Simple Node<T> class with a link to the next node
// -------------------------------------------------------------

template <class T> class Node {
  private:
    T        value; // value in the node
    Node<T> *next;  // pointer to next node

  public:
    Node(const T &v, Node<T> *n) : value(v), next(n) {}

    T &getValue() { return value; }

    Node<T> *getNext() { return next; }

    void setValue(T &v) { value = v; }

    void setNext(Node<T> *n) { next = n; }
};

// -------------------------------------------------------------
// Implementation of a SinglyLinkedList<T>
// -------------------------------------------------------------

template <class T> class SinglyLinkedList {
  private:
    Node<T> *first;  // first element
    int      length; // length

  public:
    // Construtor (creates empty list)
    SinglyLinkedList() : first(nullptr), length(0) {}

    // Destrutor
    ~SinglyLinkedList() {
        while (!isEmpty()) {
            assert(first != nullptr && "length bigger than what it should be");
            removeFirst();
        }
        assert(first == nullptr && "length smaller than what it should be");
    }

    // Returns the length of the list
    int size() { return length; }

    // Returns true iff the list is empty
    bool isEmpty() { return (length == 0); }

    // Adds v to the head of the list
    void addFirst(const T &v) {
        Node<T> *newNode = new Node<T>(v, first);
        first            = newNode;
        length++;
    }

    // Adds v to the end of the list
    void addLast(const T &v) {
        Node<T> *newNode = new Node<T>(v, nullptr);
        if (isEmpty()) {
            first = newNode;
        } else {
            Node<T> *cur = first;
            while (cur->getNext() != nullptr) cur = cur->getNext();
            cur->setNext(newNode);
        }
        length++;
    }

    // Returns the reference to the first value
    T &getFirst() {
        assert(!isEmpty() && "trying to get first from empty list");
        return first->getValue();
    }

    // Returns the last value
    T &getLast() {
        assert(!isEmpty() && "trying to get last from empty list");
        Node<T> *cur = first;
        while (cur->getNext() != nullptr) cur = cur->getNext();
        return cur->getValue();
    }

    // Removes the first element (does nothing if the list is empty)
    void removeFirst() {
        if (isEmpty()) return;
        Node<T> *victim = first;
        first           = first->getNext();
        delete victim;
        length--;
    }

    // Removes the last element (does nothing if the list is empty)
    void removeLast() {
        if (isEmpty()) return;
        if (length == 1) {
            delete first;
            first = nullptr;
        } else {
            // Using length and a for loop to show an alternative to while loop
            Node<T> *cur = first;
            for (int i = 0; i < length - 2; i++) cur = cur->getNext();
            Node<T> *victim = cur->getNext();
            cur->setNext(victim->getNext());
            delete victim;
        }
        length--;
    }

    // Convert a list to a string
    std::string toString() {
        if (isEmpty()) return "{}";
        std::stringstream sstr;
        sstr << "{" << first->getValue();
        Node<T> *cur = first->getNext();
        while (cur != nullptr) {
            sstr << "," << cur->getValue();
            cur = cur->getNext();
        }
        sstr << "}";
        std::string str;
        std::getline(sstr, str);
        return str;
    }

    // ------------------------------------------------------------
    // TODO: put the functions you need to implement below this
    // ------------------------------------------------------------


    T &get(int pos) {
        Node<T> *n = this->first;
        while (pos-- > 0) n = n->getNext();

        return n->getValue();
    }
};


#endif
