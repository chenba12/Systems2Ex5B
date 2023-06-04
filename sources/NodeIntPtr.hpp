#ifndef NODEINTPTR_HPP
#define NODEINTPTR_HPP

#include "NodeBase.hpp"

class NodeIntPtr : public NodeBase {
    std::size_t index;
    int *data;

public:
    NodeIntPtr(std::size_t index, int *data);

    size_t getIndex() const override;

    void setIndex(size_t newIndex) override;

    int getData() const override;

    NodeType getType() const override;

};

#endif // NODEINTPTR_HPP
