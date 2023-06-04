#include <iostream>
#include <csignal>
#include "MagicalContainer.hpp"

using namespace ariel;

void MagicalContainer::addElement(int element) {
    auto it = std::find_if(elementsAsc.begin(), elementsAsc.end(),
                           [element](const NodeBase &node) { return node.getData() > element; });

    auto index = it != elementsAsc.end() ? it->getIndex() : currentSize;

    NodeInt newNode(index, element);

    if (it == elementsAsc.begin()) {
        auto insertedIt = elementsAsc.insert(it, newNode);
        if (isPrime(element)) {
            std::cout <<element<< " prime\n";
            NodeIntPtr nodeIntPtr(insertedIt->getIndex(), &*insertedIt);
            primeHelper.push_back(nodeIntPtr);
        }
    } else {
        auto prev_it = std::prev(it);
        auto insertedIt=elementsAsc.insert(std::next(prev_it), newNode);
        if (isPrime(element)) {
            std::cout <<element<< " prime\n";
            NodeIntPtr nodeIntPtr(insertedIt->getIndex(), &*insertedIt);
            primeHelper.push_back(nodeIntPtr);
        }
    }


    std::cout << " prime\n";
    for (const auto &node: primeHelper) {
        std::cout << node.getData() << " ";
    }
    std::cout << " \nend\n";
    ++currentSize;
}

// 1 2 3 4 5 6
// 1
// remove(2)
// ?
void MagicalContainer::removeElement(int element) {
    for (auto it = elementsAsc.begin(); it != elementsAsc.end(); ++it) {
        if (it->getData() == element) {
            if (isPrime(element)) {
                for (auto itPrime = primeHelper.begin(); itPrime != primeHelper.end(); ++itPrime) {
                    if ((itPrime->getData()) == element) {
                        primeHelper.erase(itPrime);
                        break;
                    }
                }
            }
            elementsAsc.erase(it);
            --currentSize;
            break;
        }
    }
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

//BaseIterator
MagicalContainer::BaseIterator::BaseIterator(MagicalContainer *magicalContainerPtr, iteratorType type,
                                             NodeBase *current)
        : magicalContainerPtr(magicalContainerPtr), type(type), current(current) {}

bool MagicalContainer::BaseIterator::operator>(const MagicalContainer::BaseIterator &other) const {
    if (this->getType() != other.getType())throw std::runtime_error("Can't compare between 2 different iterators");
    if (this->magicalContainerPtr != other.magicalContainerPtr) throw std::runtime_error("Not the same container");
    if (other.getCurrent() == nullptr && this->getCurrent() != nullptr) {
        return true;
    }
    if (other.getCurrent() == nullptr && this->getCurrent() == nullptr) {
        return false;
    }
    if (this->current->getIndex() > other.current->getIndex())return true;
    return false;
}

bool MagicalContainer::BaseIterator::operator<(const MagicalContainer::BaseIterator &other) const {
    if (this->getType() != other.getType())throw std::runtime_error("Can't compare between 2 different iterators");
    if (this->magicalContainerPtr != other.magicalContainerPtr) throw std::runtime_error("Not the same container");
    if (other.getCurrent() == nullptr && this->getCurrent() != nullptr) {
        return true;
    }
    if (other.getCurrent() == nullptr && this->getCurrent() == nullptr) {
        return false;
    }
    if (this->current->getIndex() < other.current->getIndex())return true;
    return false;
}

bool MagicalContainer::BaseIterator::operator==(const MagicalContainer::BaseIterator &other) const {
    return !(*this != other);
}

bool MagicalContainer::BaseIterator::operator!=(const MagicalContainer::BaseIterator &other) const {
    return *this > other || other > *this;
}

int MagicalContainer::BaseIterator::operator*() {
    return current->getData();
}

iteratorType MagicalContainer::BaseIterator::getType() const {
    return type;
}

MagicalContainer *MagicalContainer::BaseIterator::getMagicalContainerPtr() const {
    return magicalContainerPtr;
}

// AscendingIterator
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : BaseIterator(&container, asc,
                                                                                                   &container.elementsAsc.front()),
                                                                                      iterator(
                                                                                              container.elementsAsc.begin()) {
}

MagicalContainer::AscendingIterator::AscendingIterator() : BaseIterator(nullptr, asc, nullptr) {}


MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : BaseIterator(
        other.getMagicalContainerPtr(), asc, other.getCurrent()), iterator(
        other.getIteratorConst()) {}

MagicalContainer::AscendingIterator::~AscendingIterator() = default;

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other) {
    if (this->getType() != other.getType()) throw std::runtime_error("Can't compare between 2 different iterators");
    if (this->getMagicalContainerPtr() != other.getMagicalContainerPtr())
        throw std::runtime_error("Can't compare between 2 different containers");
    this->setCurrent(other.getCurrent());
    return *this;
}


MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    if (this->getCurrent() == nullptr) {
        throw std::runtime_error("Cannot increment beyond the end of the container");
    }

    auto *container = this->getMagicalContainerPtr();
    auto &currentIterator = this->getIterator();

    if (currentIterator != container->elementsAsc.end()) {
        auto nextIterator = std::next(currentIterator);
        if (nextIterator != container->elementsAsc.end()) {
            ++currentIterator;
            this->setCurrent(&(*currentIterator));
        } else {
            ++currentIterator;
            this->setCurrent(nullptr);
        }
    }

    return *this;
}


MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    if (this->getMagicalContainerPtr() == nullptr) throw std::runtime_error("No container found");
    AscendingIterator beginIterator(*this);
    if (beginIterator.getMagicalContainerPtr() == nullptr) {
    }
    beginIterator.setCurrent(&(*getMagicalContainerPtr()->elementsAsc.begin()));
    return beginIterator;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    if (this->getMagicalContainerPtr() == nullptr) throw std::runtime_error("2No container found");
    AscendingIterator endIterator(*this);
    endIterator.setCurrent(nullptr);
    return endIterator;
}

std::list<NodeInt>::iterator &MagicalContainer::AscendingIterator::getIterator() {
    return iterator;
}

const std::list<NodeInt>::iterator &MagicalContainer::AscendingIterator::getIteratorConst() const {
    return iterator;
}


// SideCrossIterator
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : BaseIterator(&container, cross,
                                                                                                   &container.elementsAsc.front()),
                                                                                      front(true), tail() {
    this->setTail(&container.elementsAsc.back());
}

MagicalContainer::SideCrossIterator::SideCrossIterator() : BaseIterator(nullptr, cross, nullptr), front(true), tail() {}


MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : BaseIterator(
        other.getMagicalContainerPtr(), cross, other.getCurrent()), front(other.isFront()), tail() {
    this->setTail(other.getTail());
}

MagicalContainer::SideCrossIterator::~SideCrossIterator() = default;

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other) {
    if (this->getType() != other.getType()) throw std::runtime_error("Can't compare between 2 different iterators");
    if (this->getMagicalContainerPtr() != other.getMagicalContainerPtr())
        throw std::runtime_error("Can't compare between 2 different containers");
    this->setCurrent(other.getCurrent());
    this->setTail(other.getTail());
    this->setFront(other.isFront());
    return *this;
}


MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
//    auto currentNode = getCurrent();
//    if (currentNode == nullptr) {
//        throw std::runtime_error("Cannot increment beyond the end of the container");
//    }
//    auto ascList = getMagicalContainerPtr()->elementsAsc;
//    if (isFront()) {
//        if (currentNode != tail) {
//            auto it = std::next(ascList.begin(), static_cast<int>(currentNode->getIndex() + 1));
//            if (it != ascList.end()) {
//                currentNode = &(*it);
//            } else {
//                throw std::runtime_error("Cannot increment beyond the end of the container");
//            }
//        } else {
//            setFront(false);
//            this->setCurrent(std::prev(ascList.end()));
//        }
//    } else {
//        if (currentNode != ascList.begin()) {
//            auto it = std::prev(ascList.begin(), static_cast<int>(currentNode->getIndex() - 1));
//            if (it != ascList.end()) {
//                currentNode = &(*it);
//            } else {
//                throw std::runtime_error("Cannot increment beyond the end of the container");
//            }
//        } else {
//            setFront(true);
//            currentNode = std::next(ascList.begin());
//        }
//    }

    return *this;
}


MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {

    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {

    return *this;
}


NodeInt *MagicalContainer::SideCrossIterator::getTail() const {
    return tail;
}

void MagicalContainer::SideCrossIterator::setTail(NodeInt *newTail) {
    SideCrossIterator::tail = newTail;
}

bool MagicalContainer::SideCrossIterator::isFront() const {
    return front;
}

void MagicalContainer::SideCrossIterator::setFront(bool newFront) {
    SideCrossIterator::front = newFront;
}


// PrimeIterator
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : BaseIterator(&container, prime,
                                                                                           &container.primeHelper.front()),
                                                                              iterator(container.primeHelper.begin()) {}

MagicalContainer::PrimeIterator::PrimeIterator() : BaseIterator(nullptr, prime, nullptr) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : BaseIterator(
        other.getMagicalContainerPtr(), prime, other.getCurrent()), iterator(other.getIteratorConst()) {}

MagicalContainer::PrimeIterator::~PrimeIterator() = default;

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other) {
    if (this->getType() != other.getType()) throw std::runtime_error("Can't compare between 2 different iterators");
    if (this->getMagicalContainerPtr() != other.getMagicalContainerPtr())
        throw std::runtime_error("Can't compare between 2 different containers");
    this->setCurrent(other.getCurrent());
    return *this;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    if (this->getCurrent() == nullptr) {
        throw std::runtime_error("Cannot increment beyond the end of the container");
    }

    auto *container = this->getMagicalContainerPtr();
    auto &currentIterator = this->getIterator();

    if (currentIterator != container->primeHelper.end()) {
        auto nextIterator = std::next(currentIterator);
        if (nextIterator != container->primeHelper.end()) {
            ++currentIterator;
            this->setCurrent(&(*currentIterator));
        } else {
            ++currentIterator;
            this->setCurrent(nullptr);
        }
    }

    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    if (this->getMagicalContainerPtr() == nullptr) throw std::runtime_error("No container found");
    PrimeIterator beginIterator(*this);
    if (beginIterator.getMagicalContainerPtr() == nullptr) {
    }
    beginIterator.setCurrent(&(*getMagicalContainerPtr()->elementsAsc.begin()));
    return beginIterator;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    if (this->getMagicalContainerPtr() == nullptr) throw std::runtime_error("2No container found");
    PrimeIterator endIterator(*this);
    endIterator.setCurrent(nullptr);
    return endIterator;
}

std::list<NodeIntPtr>::iterator &MagicalContainer::PrimeIterator::getIterator() {
    return iterator;
}

const std::list<NodeIntPtr>::iterator &MagicalContainer::PrimeIterator::getIteratorConst() const {
    return iterator;
}



