#include "NodeInt.hpp"

NodeInt::NodeInt(std::size_t index, int data) : index(index), data(data) {}

NodeInt::NodeInt() = default;


size_t NodeInt::getIndex() const {
    return index;
}

void NodeInt::setIndex(size_t newIndex) {
    index = newIndex;
}

int NodeInt::getData() const {
    return data;
}

NodeType NodeInt::getType() const {
    return NodeType::Int;
}


