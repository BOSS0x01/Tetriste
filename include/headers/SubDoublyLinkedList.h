#pragma once
#include "DoublyLinkedList.h"
template <typename T>
class SubDoublyLinkedList : public DoublyLinkedList<T>
{
private:
public:
    SubDoublyLinkedList();
    ~SubDoublyLinkedList();
    void offsetLeft(DoublyLinkedList<T> *);
    void insertFront(T *, int);
    void insertBack(T *, int);
};

template <typename T>
SubDoublyLinkedList<T>::SubDoublyLinkedList() : DoublyLinkedList<T>()
{
}
template <typename T>
SubDoublyLinkedList<T>::~SubDoublyLinkedList()
{
}

template <typename T>
void SubDoublyLinkedList<T>::insertFront(T *data, int PosIndex)
{
    Node<T> *newNode = new Node<T>(data);

    newNode->setPositionIndex(PosIndex);
    newNode->setNext(DoublyLinkedList<T>::head->getNext());
    newNode->setPrev(DoublyLinkedList<T>::head);
    DoublyLinkedList<T>::head->getNext()->setPrev(newNode);
    DoublyLinkedList<T>::head->setNext(newNode);
    DoublyLinkedList<T>::size++;
}

template <typename T>
void SubDoublyLinkedList<T>::insertBack(T *data, int PosIndex)
{
    Node<T> *newNode = new Node<T>(data);
    newNode->setPositionIndex(PosIndex);
    newNode->setNext(DoublyLinkedList<T>::tail);
    newNode->setPrev(DoublyLinkedList<T>::tail->getPrev());
    DoublyLinkedList<T>::tail->getPrev()->setNext(newNode);
    DoublyLinkedList<T>::tail->setPrev(newNode);
    DoublyLinkedList<T>::size++;
}

template <typename T>
void SubDoublyLinkedList<T>::offsetLeft(DoublyLinkedList<T> *MainList)
{
    std::cout << "inside offsetLeft";
    // this part shift the positions of the shapes to the left and keeping the position still
    Node<T> *currentElement = DoublyLinkedList<T>::head->getNext();

    T *firstShape = currentElement->getData();
    int stopIndex = 100;
    std::cout << " list size is : " << this->getSize() << "\n";
    this->display();
    while (stopIndex-- > 0 && currentElement != DoublyLinkedList<T>::tail)
    {
        std::cout << " currentElement posindex " << currentElement->getPositionIndex() << "\n";

        currentElement->setData(currentElement->getNext()->getData());
        currentElement = currentElement->getNext();
    }
    DoublyLinkedList<T>::tail->getPrev()->setData(firstShape);

    // second step comparing the positions in the main list with the sublist
    Node<T> *listNode = MainList->getHead()->getNext();
    Node<T> *currentNode = DoublyLinkedList<T>::head->getNext();
    int i = 1;
    while (i < 100 && listNode != MainList->getTail())
    {
        std::cout << "current element  " << *listNode->getData() << "\n";

        if (currentNode->getPositionIndex() == i++)
        {
            std::cout << "equals\n";
            listNode->setData(currentNode->getData());
            if (currentNode->getNext() != DoublyLinkedList<T>::tail)
                currentNode = currentNode->getNext();
        }
        listNode = listNode->getNext();
    }

    // updating the shapes that have been affected in the other subLists

    // for (int i = testHeadNode->getPositionIndex(); testHeadNode != DoublyLinkedList<T>::tail; i = testHeadNode->getPositionIndex())
    // {
    //     std::cout << " inside for loop : test posindex  :" << i << "\n";

    //     DoublyLinkedList<T>::replaceData(MainList->getFrontNode(i), testHeadNode);
    //     testHeadNode = testHeadNode->getNext();
    // }
}

// backup
//  template <typename T>
//  void SubDoublyLinkedList<T>::offsetLeft(DoublyLinkedList<T> *MainList)
//  {
//      std::cout << "inside offsetLeft";
//      // this part shift the positions of the shapes to the right
//      Node<T> *currentElement = DoublyLinkedList<T>::tail->getPrev();

//     int lastPosIndex = currentElement->getPositionIndex();
//     int stopIndex = 100;
//     std::cout << " list size is : " << this->getSize() << "\n";
//     this->display();
//     while (stopIndex-- > 0 && currentElement != DoublyLinkedList<T>::head)
//     {
//         std::cout << " currentElement posindex " << currentElement->getPositionIndex() << "\n";

//         currentElement->setPositionIndex(currentElement->getPrev()->getPositionIndex());
//         currentElement = currentElement->getPrev();
//     }
//     DoublyLinkedList<T>::head->getNext()->setPositionIndex(lastPosIndex);

//     // second step : shifting the nodes to the left in the sublist
//     Node<T> *firstElement = DoublyLinkedList<T>::head->getNext();
//     DoublyLinkedList<T>::head->setNext(firstElement->getNext());
//     DoublyLinkedList<T>::tail->getPrev()->setNext(firstElement);
//     DoublyLinkedList<T>::tail->setPrev(firstElement);
//     firstElement->setPrev(DoublyLinkedList<T>::tail->getPrev());
//     firstElement->setNext(DoublyLinkedList<T>::tail);

//     // third step comparing the positions in the main list with the sublist
//     Node<T> *listNode = MainList->getHead()->getNext();
//     Node<T> *testHeadNode = DoublyLinkedList<T>::head->getNext();
//     int i = 1;
//     while (i < 100 && listNode != MainList->getTail())
//     {
//         std::cout << "current element  " << *listNode->getData() << "\n";

//         if (testHeadNode->getPositionIndex() == i++)
//         {
//             std::cout << "equals\n";
//             listNode->setData(testHeadNode->getData());
//             if (testHeadNode->getNext() != DoublyLinkedList<T>::tail)
//                 testHeadNode = testHeadNode->getNext();
//         }
//         listNode = listNode->getNext();
//     }

//     // for (int i = testHeadNode->getPositionIndex(); testHeadNode != DoublyLinkedList<T>::tail; i = testHeadNode->getPositionIndex())
//     // {
//     //     std::cout << " inside for loop : test posindex  :" << i << "\n";

//     //     DoublyLinkedList<T>::replaceData(MainList->getFrontNode(i), testHeadNode);
//     //     testHeadNode = testHeadNode->getNext();
//     // }
// }
