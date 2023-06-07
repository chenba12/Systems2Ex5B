#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
        : container(&container), flip(true), front(container.elementsAsc.getHead()),
          count(1) {
    if (container.currentSize != 0) {
        back = container.elementsAsc.getAnEnd()->prev.lock();
    }

}

MagicalContainer::SideCrossIterator::SideCrossIterator()
        : container(nullptr), flip(true), front(nullptr), back(nullptr), count(1) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) {
    this->container = other.container;
    this->front = other.front;
    this->back = other.back;
    this->flip = other.flip;
    this->count = other.count;
}

MagicalContainer::SideCrossIterator::~SideCrossIterator() = default;

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

//
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

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    SideCrossIterator it(*container);
    it.front = container->elementsAsc.getHead();
    it.flip = true;
    it.back = back->prev.lock();
    return it;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    SideCrossIterator it(*container);
    it.flip = false;
    it.front = container->elementsAsc.getAnEnd();
    it.back = container->elementsAsc.getAnEnd();
    it.count = container->currentSize + 1;
    return it;
}

bool MagicalContainer::SideCrossIterator::operator==(const AscendingIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");

}

bool MagicalContainer::SideCrossIterator::operator!=(const AscendingIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::SideCrossIterator::operator<(const AscendingIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::SideCrossIterator::operator>(const AscendingIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
    if (container != other.container) throw std::runtime_error("Not the same container");

    return this->count == other.count;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {
    if (container != other.container) throw std::runtime_error("Not the same container");
    return this->count < other.count;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {
    return other < *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const PrimeIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::SideCrossIterator::operator!=(const PrimeIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::SideCrossIterator::operator<(const PrimeIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

bool MagicalContainer::SideCrossIterator::operator>(const PrimeIterator &other) const {
    throw std::runtime_error("Not the same type of Iterator");
}

MagicalContainer::SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(MagicalContainer::SideCrossIterator &&other) noexcept = default;

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer::SideCrossIterator &&other) noexcept = default;
