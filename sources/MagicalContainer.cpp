#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::MagicalContainer() : currentSize(0) {}

void MagicalContainer::addElement(int element) {
    auto dataPtr = elementsAsc.insertSortedAscending(element);
    if (isPrime(element)) {
        elementsPrime.insertSortedAscending(dataPtr);
    }
    currentSize++;
}

void MagicalContainer::removeElement(int element) {
    elementsAsc.deleteElement(element);
    if (isPrime(element)) {
        auto current = elementsPrime.getHead();
        while (current != elementsPrime.getAnEnd()) {
            if (*(current->data) == element) {
                elementsPrime.deleteElement(current->data);
                break;
            }
            current = current->next;
        }
    }
    currentSize--;
}

size_t MagicalContainer::size() const {
    return currentSize;
}

bool MagicalContainer::isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

const LinkedList<int> &MagicalContainer::getElementsAsc() const {
    return elementsAsc;
}

