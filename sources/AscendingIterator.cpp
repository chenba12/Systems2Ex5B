#include "MagicalContainer.hpp"

using namespace ariel;

/**
 * Main ctr
 * @param container magical container
 */
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
        : container(&container), current() {
    if (container.elementsAsc.size() == 0) {
        current = nullptr;
    } else {
        current = container.elementsAsc.getHead();
    }
}

/**
 * copy ctr
 * @param other AscendingIterator
 */
MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator &other) = default;

/**
 * assigment operator
 * @param other AscendingIterator
 * @return *this
 */
MagicalContainer::AscendingIterator &
MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator &other) {
    if (this == &other) {
        return *this;
    }
    if (this->container != other.container) throw std::runtime_error("Not the same container");
    this->current = other.current;
    return *this;
}

/**
 * increment the iterator to point to the next node
 * @throws runtime_error if you try to increment past the container size
 * @return  this iterator
 */
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    if (current == container->elementsAsc.getAnEnd()) throw std::runtime_error("Out of bounds");
    current = current->next;
    return *this;
}

/**
 *
 * @throws runtime_error if the iterator is pointing on end or if its null
 * @return the data of the node the iterator is pointing on
 */
int &MagicalContainer::AscendingIterator::operator*() const {
    if (current == nullptr || current == container->elementsAsc.getAnEnd()) {
        throw std::runtime_error("Dereferencing an invalid iterator");
    }
    return current->data;
}

/**
 * @return an iterator that points to the starting position of the container
 */
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    AscendingIterator head(*container);
    head.container->elementsAsc.getHead();
    return head;

}

/**
 * @return an iterator that points to the end position of the container
 */
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    AscendingIterator it(*container);
    if (container->size() == 0) {
        it.current = nullptr;
    } else {
        it.current = container->elementsAsc.getAnEnd();
    }
    return it;
}

/**
 * empty ctr
 */
MagicalContainer::AscendingIterator::AscendingIterator() = default;

/**
 * destructor
 */
MagicalContainer::AscendingIterator::~AscendingIterator() = default;

/**
 * compare 2 iterators by index
 * @param other AscendingIterator
 * @return true if this iterator < the other iterator index
 */
bool
MagicalContainer::AscendingIterator::operator<(const MagicalContainer::AscendingIterator &other) const {
    if (container != other.container) throw std::runtime_error("Not the same container");
    return current->index < other.current->index;
}

/**
 * compare 2 iterators by index
 * @param other AscendingIterator
 * @return true if this iterator > the other iterator index
 */
bool
MagicalContainer::AscendingIterator::operator>(const MagicalContainer::AscendingIterator &other) const {
    return other < *this;
}

/**
 * compare 2 iterators by index
 * @param other AscendingIterator
 * @return true if this iterator == the other iterator index
 */
bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::AscendingIterator &other) const {
    if (container != other.container) throw std::runtime_error("Not the same container");
    if (container->size() == 0 && other.container->size() == 0) {
        return true;
    }
    return current->index == other.current->index;
}

/**
 * compare 2 iterators by index
 * @param other AscendingIterator
 * @return true if this iterator != the other iterator index
 */
bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::AscendingIterator &other) const {
    return !(other == *this);
}

/**
 * move assigment operator
 * @param other AscendingIterator
 */
MagicalContainer::AscendingIterator &
MagicalContainer::AscendingIterator::operator=(MagicalContainer::AscendingIterator &&other) noexcept = default;

/**
 * move ctr
 * @param other AscendingIterator
 */
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer::AscendingIterator &&other) noexcept = default;


bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::SideCrossIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::SideCrossIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::PrimeIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::PrimeIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::SideCrossIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::SideCrossIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::PrimeIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::PrimeIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

