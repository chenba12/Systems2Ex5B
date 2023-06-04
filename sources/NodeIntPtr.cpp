#include "NodeIntPtr.hpp"

NodeIntPtr::NodeIntPtr(std::size_t index, NodeInt *data) : index(index), data(data) {}

size_t NodeIntPtr::getIndex() const {
    return index;
}

void NodeIntPtr::setIndex(size_t newIndex) {
    index = newIndex;
}

NodeType NodeIntPtr::getType() const {
    return NodeType::IntPtr;
}

int NodeIntPtr::getData() const {
    return data->getData();
}

