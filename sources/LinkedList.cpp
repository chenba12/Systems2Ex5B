#include "LinkedList.hpp"

template<>
const int **LinkedList<const int *>::insertSortedAscending(const int *data) {
    auto newNode = std::make_shared<Node<const int *>>(data, 0);
    if (head == end) {
        newNode->next = end;
        end->prev = newNode;
        head = newNode;
    } else if (*(head->data) > *(newNode->data)) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        auto current = head;
        int idx = 0;
        while (current->next != end && *(current->next->data) < *(newNode->data)) {
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

template<>
void LinkedList<const int *>::deleteElement(const int *data) {
    if (head == end)
        throw std::runtime_error("Node not found");

    if (*(head->data) == *(data)) {
        head = head->next;
        head->prev.reset();
    } else {
        auto current = head;
        while (current->next != end && *(current->next->data) != *(data)) {
            current = current->next;
        }

        if (current->next == end) {
            throw std::runtime_error("Node not found");
        }
        auto toDelete = current->next;
        current->next = toDelete->next;
        if (toDelete->next != end) {
            toDelete->next->prev = current;
        }

        current = current->next;
        while (current != end) {
            current->index--;
            current = current->next;
        }
    }
}