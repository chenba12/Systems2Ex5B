#include "MagicalContainer.hpp"

using namespace ariel;

/**
 * Parametrized ctr
 * @param container the magicalContainer the iterator will work on
 */
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
        : container(&container), flip(true), front(container.elementsAsc.getHead()),
          count(1) {
    if (container.currentSize != 0) {
        back = container.elementsAsc.getAnEnd()->prev.lock();
    }

}
/**
 * default ctr
 */
MagicalContainer::SideCrossIterator::SideCrossIterator()
        : container(nullptr), flip(true), front(nullptr), back(nullptr), count(1) {}

/**
* copy ctr
* @param other SideCrossIterator
*/
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) {
    this->container = other.container;
    this->front = other.front;
    this->back = other.back;
    this->flip = other.flip;
    this->count = other.count;
}
/**
 * default destructor
 */
MagicalContainer::SideCrossIterator::~SideCrossIterator() = default;

/**
 * assignment operator
 * @param other SideCrossIterator to assign from
 * @return this after assignment
 */
MagicalContainer::SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
    if (*this == other) {
        return *this;
    }
    if (this->container != other.container) throw std::runtime_error("Not the same container.");
    this->count = other.count;
    this->front = other.front;
    this->back = other.back;
    this->flip = other.flip;
    return *this;
}
/**
 * Equality operator
 * @param other SideCrossIterator to compare with
 * @return true if *this == other, false otherwise
 */
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
    if (container != other.container) throw std::runtime_error("Not the same container");

    return this->count == other.count;
}

/**
 * Inequality operator
 * @param other SideCrossIterator to compare with
 * @return true if *this != other, false otherwise
 */
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
    return !(*this == other);
}

/**
 * Less than operator
 * @param other SideCrossIterator to compare with
 * @return true if *this < other, false otherwise
 */
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {
    if (container != other.container) throw std::runtime_error("Not the same container");
    return this->count < other.count;
}
/**
 * Greater than operator
 * @param other SideCrossIterator to compare with
 * @return true if *this > other, false otherwise
 */
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {
    return other < *this;
}

/**
 * prefix increment operator
 * @return this after increment
 */
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    if (count > container->currentSize) {
        throw std::runtime_error("Out of bounds");
    }

    if (flip) {
        front = front->next;
    } else {
        back = back->prev.lock();
    }
    flip = !flip;
    count++;
    return *this;
}
/**
 * dereference operator
 * @return the current data
 */
int &MagicalContainer::SideCrossIterator::operator*() const {
    if (flip) {
        if (count > container->currentSize) {
            throw std::runtime_error("Dereferencing an invalid iterator");
        }
        return front->data;
    } else {
        if (count > container->currentSize) {
            throw std::runtime_error("Dereferencing an invalid iterator");
        }
        return back->data;
    }
}
/**
 * @return a new iterator pointing to the start of the container
 */
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    SideCrossIterator it(*container);
    it.front = container->elementsAsc.getHead();
    it.flip = true;
    it.back = back->prev.lock();
    return it;
}
/**
 * @return a new iterator pointing to the end of the container
 */
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    SideCrossIterator it(*container);
    it.flip = false;
    it.front = container->elementsAsc.getAnEnd();
    it.back = container->elementsAsc.getAnEnd();
    it.count = container->currentSize + 1;
    return it;
}

/**
 * Move assignment operator
 * @param other SideCrossIterator to assign from
 * @return this after assignment
 */
MagicalContainer::SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(MagicalContainer::SideCrossIterator &&other) noexcept = default;
/**
 * Move ctr
 * @param other SideCrossIterator to initialize from
 */
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer::SideCrossIterator &&other) noexcept = default;
/**
 * Comparison operator with AscendingIterator
 * @param other AscendingIterator to compare with
 * @return always throws runtime error
 */
bool MagicalContainer::SideCrossIterator::operator==(const AscendingIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");

}
/**
 * Comparison operator with AscendingIterator
 * @param other AscendingIterator to compare with
 * @return always throws runtime error
 */
bool MagicalContainer::SideCrossIterator::operator!=(const AscendingIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}
/**
 * Comparison operator with AscendingIterator
 * @param other AscendingIterator to compare with
 * @return always throws runtime error
 */
bool MagicalContainer::SideCrossIterator::operator<(const AscendingIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}
/**
 * Comparison operator with AscendingIterator
 * @param other AscendingIterator to compare with
 * @return always throws runtime error
 */
bool MagicalContainer::SideCrossIterator::operator>(const AscendingIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

/**
 * Comparison operator with PrimeIterator
 * @param other PrimeIterator to compare with
 * @return always throws runtime error
 */
bool MagicalContainer::SideCrossIterator::operator==(const PrimeIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}
/**
 * Comparison operator with PrimeIterator
 * @param other PrimeIterator to compare with
 * @return always throws runtime error
 */
bool MagicalContainer::SideCrossIterator::operator!=(const PrimeIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}
/**
 * Comparison operator with PrimeIterator
 * @param other PrimeIterator to compare with
 * @return always throws runtime error
 */
bool MagicalContainer::SideCrossIterator::operator<(const PrimeIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}
/**
 * Comparison operator with PrimeIterator
 * @param other PrimeIterator to compare with
 * @return always throws runtime error
 */
bool MagicalContainer::SideCrossIterator::operator>(const PrimeIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}


