#pragma once
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include "Node.h"
// You cannot separate the declaration and the definition when working with templates
template <typename T>
class DoublyLinkedList
{
    int size;
    Node<T> *head;
    Node<T> *tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertFront(T *);
    void insertBack(T *);

    void insertAfter(Node<T> *, T *);
    void insertBefore(Node<T> *, T *);

    Node<T> *removeFront();
    Node<T> *removeBack();
    Node<T> *removeNode(Node<T> *);

    void offsetLeft();

    bool isEmpty();
    Node<T> *search(T *);

    int getSize() const;

    Node<T> *getHead() const;
    void setHead(Node<T> *);

    Node<T> *getTail() const;
    void setTail(Node<T> *);

    void display();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = new Node<T>();
    tail = new Node<T>();
    head->setNext(tail);
    head->setPrev(tail);
    tail->setNext(head);
    tail->setPrev(head);
    size = 0;
}

template <typename T>
void DoublyLinkedList<T>::insertFront(T *data)
{
    Node<T> *newNode = new Node<T>(data);
    newNode->setNext(head->getNext());
    newNode->setPrev(head);
    head->getNext()->setPrev(newNode);
    head->setNext(newNode);
    size++;
}

template <typename T>
void DoublyLinkedList<T>::insertBack(T *data)
{
    Node<T> *newNode = new Node<T>(data);
    newNode->setNext(tail);
    newNode->setPrev(tail->getPrev());
    tail->getPrev()->setNext(newNode);
    tail->setPrev(newNode);
    size++;
}

template <typename T>
void DoublyLinkedList<T>::insertAfter(Node<T> *prevNode, T *data)

{
    Node<T> *newNode = new Node<T>(data);
    newNode->setNext(prevNode->getNext());
    newNode->setPrev(prevNode);
    prevNode->getNext()->setPrev(newNode);
    prevNode->setNext(newNode);
    size++;
}

template <typename T>
void DoublyLinkedList<T>::insertBefore(Node<T> *nextNode, T *data)
{
    Node<T> *newNode = new Node<T>(data);
    newNode->setNext(nextNode);
    newNode->setPrev(nextNode->getPrev());
    nextNode->getPrev()->setNext(newNode);
    nextNode->setPrev(newNode);
    size++;
}

template <typename T>
Node<T> *DoublyLinkedList<T>::removeFront()
{
    Node<T> *tmp = head->getNext();

    head->setNext(head->getNext()->getNext());
    head->getNext()->getNext()->setPrev(head);
    size--;
    return tmp;
}

template <typename T>
Node<T> *DoublyLinkedList<T>::removeBack()
{
    tail->setPrev(tail->getPrev()->getPrev());
    tail->getPrev()->getPrev()->setNext(tail);
    size--;
    return tail->getPrev();
}

template <typename T>
Node<T> *DoublyLinkedList<T>::removeNode(Node<T> *currentNode)
{
    currentNode->getPrev()->setNext(currentNode->getNext());
    currentNode->getNext()->setPrev(currentNode->getPrev());
    size--;
    return currentNode;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
    return head->getNext() == tail;
}

template <typename T>
Node<T> *DoublyLinkedList<T>::search(T *data)
{
    if (!isEmpty())
    {
        for (Node<T> *currentNode = head->getNext(); currentNode != tail; currentNode = currentNode->getNext())
        {
            if (*currentNode->getData() == *data)
            {
                return currentNode;
            }
        }
    }
    return nullptr;
}
template <typename T>
void DoublyLinkedList<T>::offsetLeft()
{
    Node<T> *firstElement = head->getNext();
    head->setNext(firstElement->getNext());
    tail->getPrev()->setNext(firstElement);
    firstElement->setPrev(tail->getPrev());
    firstElement->setNext(tail);
    tail->setPrev(firstElement);
}
template <typename T>
Node<T> *DoublyLinkedList<T>::getHead() const { return head; }
template <typename T>
void DoublyLinkedList<T>::setHead(Node<T> *newHead) { this->head = newHead; }

template <typename T>
Node<T> *DoublyLinkedList<T>::getTail() const { return tail; }
template <typename T>
void DoublyLinkedList<T>::setTail(Node<T> *newTail) { this->tail = newTail; }

template <typename T>
int DoublyLinkedList<T>::getSize() const { return size; }

template <typename T>
void DoublyLinkedList<T>::display()
{
    if (!isEmpty())
    {
        Node<T> *currentNode = head->getNext();
        while (currentNode != tail)
        {
            std::cout << *currentNode->getData() << "\t";
            currentNode = currentNode->getNext();
        }
    }
    else
    {
        std::cout << "List is empty" << std::endl;
    }
}
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{

    // while (head)
    // {

    //     tmp = head;
    //     head = head->getNext();
    //     delete tmp;
    // }
    while (!isEmpty())
    {
        delete removeFront();
    }
}
#endif