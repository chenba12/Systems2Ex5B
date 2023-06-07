#include "MagicalContainer.hpp"

using namespace ariel;


MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
        : container(&container), current(container.elementsAsc.getHead()) {
}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator &other) = default;

MagicalContainer::AscendingIterator &
MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator &other) {
    if (this == &other) {
        return *this;
    }
    if (this->container != other.container) throw std::runtime_error("Not the same container");
    this->current = other.current;
    return *this;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    if (current == container->elementsAsc.getAnEnd()) throw std::runtime_error("Out of bounds");
    current = current->next;
    return *this;
}

int &MagicalContainer::AscendingIterator::operator*() const {
    if (current == nullptr || current == container->elementsAsc.getAnEnd()) {
        throw std::runtime_error("Dereferencing an invalid iterator");
    }
    return current->data;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    AscendingIterator head(*container);
    head.container->elementsAsc.getHead();
    return head;

}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    AscendingIterator it(*container);
    it.current = container->elementsAsc.getAnEnd();
    return it;
}

MagicalContainer::AscendingIterator::AscendingIterator() = default;

MagicalContainer::AscendingIterator::~AscendingIterator() = default;

bool
MagicalContainer::AscendingIterator::operator<(const MagicalContainer::AscendingIterator &other) const {
    if (container != other.container) throw std::runtime_error("Not the same container");
    return current->index < other.current->index;
}

bool
MagicalContainer::AscendingIterator::operator>(const MagicalContainer::AscendingIterator &other) const {
    return other < *this;
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

bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::AscendingIterator &other) const {
    return container == other.container &&
           current->index == other.current->index;
}

bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::AscendingIterator &other) const {
    return !(other == *this);
}

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

MagicalContainer::AscendingIterator &
MagicalContainer::AscendingIterator::operator=(MagicalContainer::AscendingIterator &&other) noexcept = default;

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer::AscendingIterator &&other) noexcept = default;






