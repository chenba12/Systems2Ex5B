#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
        : container(&container), current(container.elementsPrime.getHead()) {
}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer::PrimeIterator &other) = default;

MagicalContainer::PrimeIterator &
MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator &other) {
    if (this == &other) {
        return *this;
    }
    if (this->container != other.container) throw std::runtime_error("Not the same container");
    this->current = other.current;
    return *this;
}

MagicalContainer::PrimeIterator::PrimeIterator() = default;

MagicalContainer::PrimeIterator::~PrimeIterator() = default;

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    if (current == container->elementsPrime.getAnEnd()) throw std::runtime_error("Out of bounds");
    current = current->next;

    return *this;
}

const int &MagicalContainer::PrimeIterator::operator*() const {
    if (current == nullptr || current == container->elementsPrime.getAnEnd()) {
        throw std::runtime_error("Dereferencing an invalid iterator");
    }
    return *(current->data);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    PrimeIterator head(*container);
    head.container->elementsPrime.getHead();
    return head;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    PrimeIterator it(*container);
    it.current = container->elementsPrime.getAnEnd();
    return it;
}


bool
MagicalContainer::PrimeIterator::operator<(const MagicalContainer::PrimeIterator &other) const {
    if (container != other.container) throw std::runtime_error("Not the same container");
    return current->index < other.current->index;
}

bool
MagicalContainer::PrimeIterator::operator>(const MagicalContainer::PrimeIterator &other) const {
    return other < *this;
}

bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::SideCrossIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::SideCrossIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::AscendingIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::AscendingIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::PrimeIterator &other) const {
    return container == other.container &&
           current->index == other.current->index;
}

bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::PrimeIterator &other) const {
    return !(other == *this);
}

bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::SideCrossIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::SideCrossIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::AscendingIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::AscendingIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer::PrimeIterator &&other) noexcept = default;

MagicalContainer::PrimeIterator &
MagicalContainer::PrimeIterator::operator=(MagicalContainer::PrimeIterator &&other) noexcept = default;
