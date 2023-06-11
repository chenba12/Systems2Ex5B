#include "MagicalContainer.hpp"

using namespace ariel;

/**
 * default ctr
 * @param container the magicalContainer the iterator will work on
 */
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
        : container(&container), current(container.elementsPrime.getHead()) {
}

/**
 * copy ctr
 * @param other PrimeIterator
 */
MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer::PrimeIterator &other) = default;

/**
 * assignment operator
 * @param other PrimeIterator to assign from
 * @return this after assignment
 */
MagicalContainer::PrimeIterator &
MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator &other) {
    if (this == &other) {
        return *this;
    }
    if (this->container != other.container) throw std::runtime_error("Not the same container");
    this->current = other.current;
    return *this;
}
/**
 * default ctr
 */
MagicalContainer::PrimeIterator::PrimeIterator() = default;
/**
 * default destructor
 */
MagicalContainer::PrimeIterator::~PrimeIterator() = default;

/**
 * prefix increment operator
 * @return this after increment
 */
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    if (current == container->elementsPrime.getAnEnd()) throw std::runtime_error("Out of bounds");
    current = current->next;
    return *this;
}


/**
* dereference operator
* @return the current data
*/
const int &MagicalContainer::PrimeIterator::operator*() const {
    if (current == nullptr || current == container->elementsPrime.getAnEnd()) {
        throw std::runtime_error("Dereferencing an invalid iterator");
    }
    return *(current->data);
}

/**
 * @return a new iterator pointing to the start of the container
 */
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    PrimeIterator head(*container);
    head.container->elementsPrime.getHead();
    return head;
}
/**
 * @return a new iterator pointing to the end of the container
 */
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    PrimeIterator it(*container);
    it.current = container->elementsPrime.getAnEnd();
    return it;
}

/**
 * Less than operator
 * @param other PrimeIterator to compare with
 * @return true if this is less than other, false otherwise
 */
bool
MagicalContainer::PrimeIterator::operator<(const MagicalContainer::PrimeIterator &other) const {
    if (container != other.container) throw std::runtime_error("Not the same container");
    return current->index < other.current->index;
}

/**
 * Greater than operator
 * @param other PrimeIterator to compare with
 * @return true if this is greater than other, false otherwise
 */
bool
MagicalContainer::PrimeIterator::operator>(const MagicalContainer::PrimeIterator &other) const {
    return other < *this;
}

/**
 * Equality operator
 * @param other PrimeIterator to compare with
 * @return true if this is equal to other, false otherwise
 */
bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::PrimeIterator &other) const {
    return container == other.container &&
           current->index == other.current->index;
}
/**
 * Not equal operator
 * @param other PrimeIterator to compare with
 * @return true if this is not equal to other, false otherwise
 */
bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::PrimeIterator &other) const {
    return !(other == *this);
}

/**
 * move ctr
 * @param other PrimeIterator to move from
 */
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer::PrimeIterator &&other) noexcept = default;

/**
 * move assignment operator
 * @param other PrimeIterator to move from
 * @return this after move assignment
 */
MagicalContainer::PrimeIterator &
MagicalContainer::PrimeIterator::operator=(MagicalContainer::PrimeIterator &&other) noexcept = default;



/**
 * Comparison operator with SideCrossIterator
 * @param other SideCrossIterator to compare with
 * @return always throws runtime error
 */
bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::SideCrossIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

/**
 * Comparison operator with SideCrossIterator
 * @param other SideCrossIterator to compare with
 * @return always throws runtime error
 */
bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::SideCrossIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}
/**
 * Comparison operator with AscendingIterator
 * @param other AscendingIterator to compare with
 * @return always throws runtime error
 */
bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::AscendingIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}
/**
 * Comparison operator with AscendingIterator
 * @param other AscendingIterator to compare with
 * @return always throws runtime error
 */
bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::AscendingIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}
/**
 * Comparison operator with SideCrossIterator
 * @param other SideCrossIterator to compare with
 * @return always throws runtime error
 */
bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::SideCrossIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}
/**
 * Comparison operator with SideCrossIterator
 * @param other SideCrossIterator to compare with
 * @return always throws runtime error
 */
bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::SideCrossIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}
/**
 * Comparison operator with AscendingIterator
 * @param other AscendingIterator to compare with
 * @return always throws runtime error
 */
bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::AscendingIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}
/**
 * Comparison operator with AscendingIterator
 * @param other AscendingIterator to compare with
 * @return always throws runtime error
 */
bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::AscendingIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}