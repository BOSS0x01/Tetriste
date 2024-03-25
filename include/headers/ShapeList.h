#pragma once

#include <iostream>
#include "ShapeNode.h"
#include "Shape.h"

class ShapeList
{
protected:
    int size;
    ShapeNode *head;
    ShapeNode *tail;

public:
    ShapeList();
    ~ShapeList();

    void insertFront(Shape *);
    void insertBack(Shape *);

    void insertAfter(ShapeNode *, Shape *);
    void insertBefore(ShapeNode *, Shape *);

    ShapeNode *removeFront();
    ShapeNode *removeBack();
    ShapeNode *removeShapeNode(ShapeNode *);

    bool isEmpty();
    ShapeNode *search(Shape *);
    ShapeNode *getFrontShapeNode(int i);
    ShapeNode *getBackShapeNode(int i);

    Shape *getFront(int);
    Shape *getBack(int);
    int getSize() const;

    ShapeNode *getHead() const;
    void setHead(ShapeNode *);
    Shape *getFirstEelement() const;
    ShapeNode *getTail() const;
    void setTail(ShapeNode *);
    void replaceData(ShapeNode *, ShapeNode *);
    void display();
};

ShapeList::ShapeList()
{
    head = new ShapeNode();
    tail = new ShapeNode();
    head->setNextInList(tail);
    tail->setPrevInList(head);
    size = 0;
}

void ShapeList::insertFront(Shape *data)
{
    ShapeNode *newShapeNode = new ShapeNode(data);
    newShapeNode->setNextInList(head->getNextInList());
    newShapeNode->setPrevInList(head);
    head->getNextInList()->setPrevInList(newShapeNode);
    head->setNextInList(newShapeNode);
    size++;
}

void ShapeList::insertBack(Shape *data)
{
    ShapeNode *newShapeNode = new ShapeNode(data);
    newShapeNode->setNextInList(tail);
    newShapeNode->setPrevInList(tail->getPrevInList());
    tail->getPrevInList()->setNextInList(newShapeNode);
    tail->setPrevInList(newShapeNode);
    size++;
}

void ShapeList::insertAfter(ShapeNode *prevShapeNode, Shape *data)

{
    ShapeNode *newShapeNode = new ShapeNode(data);
    newShapeNode->setNextInList(prevShapeNode->getNextInList());
    newShapeNode->setPrevInList(prevShapeNode);
    prevShapeNode->getNextInList()->setPrevInList(newShapeNode);
    prevShapeNode->setNextInList(newShapeNode);
    size++;
}

void ShapeList::insertBefore(ShapeNode *nextShapeNode, Shape *data)
{
    ShapeNode *newShapeNode = new ShapeNode(data);
    newShapeNode->setNextInList(nextShapeNode);
    newShapeNode->setPrevInList(nextShapeNode->getPrevInList());
    nextShapeNode->getPrevInList()->setNextInList(newShapeNode);
    nextShapeNode->setPrevInList(newShapeNode);
    size++;
}

ShapeNode *ShapeList::removeFront()
{
    ShapeNode *tmp = head->getNextInList();

    head->setNextInList(head->getNextInList()->getNextInList());
    head->getNextInList()->getNextInList()->setPrevInList(head);
    size--;
    return tmp;
}

ShapeNode *ShapeList::removeBack()
{
    tail->setPrevInList(tail->getPrevInList()->getPrevInList());
    tail->getPrevInList()->getPrevInList()->setNextInList(tail);
    size--;
    return tail->getPrevInList();
}

ShapeNode *ShapeList::removeShapeNode(ShapeNode *currentShapeNode)
{
    currentShapeNode->getPrevInList()->setNextInList(currentShapeNode->getNextInList());
    currentShapeNode->getNextInList()->setPrevInList(currentShapeNode->getPrevInList());
    size--;
    return currentShapeNode;
}

bool ShapeList::isEmpty()
{
    return head->getNextInList() == tail;
}

ShapeNode *ShapeList::search(Shape *data)
{
    if (!isEmpty())
    {
        for (ShapeNode *currentShapeNode = head->getNextInList(); currentShapeNode != tail; currentShapeNode = currentShapeNode->getNextInList())
        {
            if (*currentShapeNode->getShape() == *data)
            {
                return currentShapeNode;
            }
        }
    }
    return nullptr;
}

Shape *ShapeList::getFront(int i)
{
    int counter = 0;
    ShapeNode *currentShapeNode = head;

    while (currentShapeNode != tail && counter++ <= i)
    {
        currentShapeNode = currentShapeNode->getNextInList();
    }

    return currentShapeNode->getShape();
}

Shape *ShapeList::getBack(int i)
{
    int counter = 0;
    ShapeNode *currentShapeNode = tail;

    while (currentShapeNode != head && counter++ <= i)
    {
        currentShapeNode = currentShapeNode->getPrevInList();
    }

    return currentShapeNode->getShape();
}

ShapeNode *ShapeList::getFrontShapeNode(int i)
{
    int counter = 0;
    ShapeNode *currentShapeNode = head;

    while (currentShapeNode != tail && counter++ <= i)
    {
        currentShapeNode = currentShapeNode->getNextInList();
    }

    return currentShapeNode;
}

ShapeNode *ShapeList::getBackShapeNode(int i)
{
    int counter = 0;
    ShapeNode *currentShapeNode = tail;

    while (currentShapeNode != head && counter++ <= i)
    {
        currentShapeNode = currentShapeNode->getPrevInList();
    }

    return currentShapeNode;
}

void ShapeList::replaceData(ShapeNode *ShapeNodeToReplace, ShapeNode *newShapeNode)
{
    ShapeNodeToReplace->setShape(newShapeNode->getShape());
}

ShapeNode *ShapeList::getHead() const { return head; }

void ShapeList::setHead(ShapeNode *newHead) { this->head = newHead; }

Shape *ShapeList::getFirstEelement() const { return head->getNextInList()->getShape(); }

ShapeNode *ShapeList::getTail() const { return tail; }

void ShapeList::setTail(ShapeNode *newTail) { this->tail = newTail; }

int ShapeList::getSize() const { return size; }

void ShapeList::display()
{
    if (!isEmpty())
    {
        ShapeNode *currentShapeNode = head->getNextInList();
        while (currentShapeNode != tail)
        {
            std::cout << *currentShapeNode->getShape() << "\n";
            currentShapeNode = currentShapeNode->getNextInList();
        }
        std::cout << "\n\n\n";
    }
    else
    {
        std::cout << "List is empty" << std::endl;
    }
}

ShapeList::~ShapeList()
{

    // while (head)
    // {

    //     tmp = head;
    //     head = head->getNextInList();
    //     delete tmp;
    // }
    while (!isEmpty())
    {
        delete removeFront();
    }
}
