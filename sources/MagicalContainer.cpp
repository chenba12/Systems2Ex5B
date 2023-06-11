#include "MagicalContainer.hpp"

using namespace ariel;

/**
 * empty ctr
 */
MagicalContainer::MagicalContainer() : currentSize(0) {}

/**
 * add a new element to the double linkedList named elementsASc
 * if the element is a prime number add a pointer to the inserted element into
 * elementsPrime
 * @param element the element to add
 */
void MagicalContainer::addElement(int element) {
    auto dataPtr = elementsAsc.insertSortedAscending(element);
    if (isPrime(element)) {
        elementsPrime.insertSortedAscending(dataPtr);
    }
    currentSize++;
}

/**
 * removes an element from the linkedlist
 * if the element is a prime removes it from the elementsPrime linkedlist as well
 * @param element the element to remove
 */
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
/**
 * @return the size of the elementsAsc linkedList
 */
size_t MagicalContainer::size() const {
    return currentSize;
}

/**
 * @param element to check if its prime or not
 * @return true if the element is prime false otherwise
 */
bool MagicalContainer::isPrime(int element) {
    if (element <= 1) {
        return false;
    }
    if (element == 2) {
        return true;
    }
    if (element % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= element; i += 2) {
        if (element % i == 0) {
            return false;
        }
    }
    return true;
}

/**
 * @return the elementsAsc linkedList
 */
const LinkedList<int> &MagicalContainer::getElementsAsc() const {
    return elementsAsc;
}

/**
 * @return the elementsPrime linkedList
 */
const LinkedList<const int *> &MagicalContainer::getElementsPrime() const {
    return elementsPrime;
}

