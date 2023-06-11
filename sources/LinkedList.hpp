#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <memory>
#include <iostream>
#include "limits"

/**
 * @class Node
 * Class representing a node in the LinkedList
 * @tparam T Type of data that will be stored in the Node
 */
template<typename T>
class Node {
public:
    T data;
    int index;
    std::shared_ptr<Node<T>> next;
    std::weak_ptr<Node<T>> prev;
    bool isEnd;

    /**
     * Default constructor
     */
    Node() : data(T()), index(0), next(nullptr), prev(), isEnd(false) {}
    /**
     * Constructor to initialize a node with data, index, and isEnd flag
     * @param data Data to be stored in the node
     * @param index Index of the node in the list
     * @param isEnd Whether the node is the end of the list
     */
    Node(T data, int index, bool isEnd = false) : data(data), index(index), next(nullptr), prev(), isEnd(isEnd) {}

    bool operator<(const Node &node) const { return this->index < node.index; }

    bool operator>(const Node &node) const { return this->index > node.index; }

    bool operator==(const Node &node) const { return this->index == node.index; }

    bool operator!=(const Node &node) const { return this->index != node.index; }
};

/**
 * @class LinkedList
 * Class representing a LinkedList data structure
 * @tparam T Type of data that will be stored in the LinkedList
 */
template<typename T>
class LinkedList {
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> end;

public:
    /**
    * Default constructor
    * Initializes the LinkedList with a head and end nodes
    */
    LinkedList() : end(std::make_shared<Node<T>>(T(), std::numeric_limits<int>::max(), true)) {
        head = end;
    }

    /**
    * Inserts an element in ascending order
    * @param data Element to be inserted
    * @return Pointer to the inserted element
    */
    T *insertSortedAscending(T data);

    /**
    * Deletes an element from the LinkedList
    * @param data Element to be deleted
    */
    void deleteElement(T data);

    /**
    * @return Number of elements in the LinkedList
    */
    int size() const;

    /**
    * @return Pointer to the head node
    */
    const std::shared_ptr<Node<T>> &getHead() const;

    /**
    * @param anEnd Pointer to the new end node
    */
    const std::shared_ptr<Node<T>> &getAnEnd() const;

};

/**
* Inserts an element in ascending order
* @param data Element to be inserted
* @return Pointer to the inserted element
*/
template<typename T>
T *LinkedList<T>::insertSortedAscending(T data) {
    auto newNode = std::make_shared<Node<T>>(data, 0);
    if (head == end) {
        newNode->next = end;
        end->prev = newNode;
        head = newNode;
    } else if (head->data > newNode->data) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        auto current = head;
        int idx = 0;
        while (current->next != end && current->next->data < newNode->data) {
            current = current->next;
            idx++;
        }
        newNode->index = idx + 1;
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != end) {
            current->next->prev = newNode;
        }
        if (current->next == end) {
            end->prev = newNode;
        }
        current->next = newNode;

        current = newNode->next;
        while (current != end) {
            current->index++;
            current = current->next;
        }
    }
    return &(newNode->data);
}

/**
* Deletes an element from the LinkedList
* @param data Element to be deleted
*/
template<typename T>
void LinkedList<T>::deleteElement(T data) {
    if (head == end) {
        throw std::runtime_error("Node not found");
    }
    if (head->data == data) {
        head = head->next;
        if (head != end) {
            head->prev.reset();
        }
    } else {
        auto current = head;
        while (current->next != end && current->next->data != data) {
            current = current->next;
        }

        if (current->next == end) {
            throw std::runtime_error("Node not found");
        }

        auto toDelete = current->next;
        current->next = toDelete->next;
        if (toDelete->next != end) {
            toDelete->next->prev = current;
        } else {
            end->prev = current;
        }
        toDelete->next.reset();
        toDelete->prev.reset();
        toDelete.reset();

        current = current->next;
        while (current != end) {
            current->index--;
            current = current->next;
        }
    }
}
/**
* @return Number of elements in the LinkedList
*/
template<typename T>
int LinkedList<T>::size() const {
    int count = 0;
    auto current = head;

    while (current != end) {
        count++;
        current = current->next;
    }

    return count;
}

template<typename T>
const std::shared_ptr<Node<T>> &LinkedList<T>::getHead() const {
    return head;
}


template<typename T>
const std::shared_ptr<Node<T>> &LinkedList<T>::getAnEnd() const {
    return end;
}

template<typename T>
void printLinkedList(const LinkedList<T> &linkedList) {
    auto current = linkedList.getHead();

    while (current != linkedList.getAnEnd()) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template<>
int **LinkedList<int *>::insertSortedAscending(int *data);

template<>
void LinkedList<const int *>::deleteElement(const int *data);

#endif
