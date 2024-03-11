#pragma once
#ifndef NODE_H
#define NODE_H
#include <iostream>
template <typename T>
class Node
{
private:
    T *data;

    Node<T> *next;
    Node<T> *prev;
    // static int nbrNodeCreated;

public:
    int id = 0;
    Node();
    Node(T *data);
    ~Node();
    void setNext(Node<T> *next);
    Node<T> *getNext();

    void setPrev(Node<T> *prev);
    Node<T> *getPrev();

    void setData(T *data);
    T *getData();
};

template <typename T>
Node<T>::Node() : data(nullptr), next(nullptr), prev(nullptr) {}

template <typename T>
Node<T>::Node(T *data) : data(data), next(nullptr), prev(nullptr) {}

template <typename T>
void Node<T>::setNext(Node<T> *next)
{
    this->next = next;
}

template <typename T>
Node<T> *Node<T>::getNext()
{
    return next;
}

template <typename T>
void Node<T>::setPrev(Node<T> *prev)
{
    this->prev = prev;
}

template <typename T>
Node<T> *Node<T>::getPrev()
{
    return prev;
}

template <typename T>
void Node<T>::setData(T *data)
{
    this->data = data;
}

template <typename T>
T *Node<T>::getData()
{
    return data;
}

template <typename T>
Node<T>::~Node()
{
    if (data != nullptr)
        delete data;
    if (next != nullptr)
        delete next;
    if (prev != nullptr)
        delete prev;
}
#endif
