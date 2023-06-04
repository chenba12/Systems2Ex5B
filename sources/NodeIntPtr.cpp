#include "NodeIntPtr.hpp"

NodeIntPtr::NodeIntPtr(std::size_t index, int *data) : index(index), data(data) {}

size_t NodeIntPtr::getIndex() const {
    return index;
}

void NodeIntPtr::setIndex(size_t newIndex) {
    index = newIndex;
}

int NodeIntPtr::getData() const {
    return *data;
}

NodeType NodeIntPtr::getType() const {
    return NodeType::IntPtr;
}

