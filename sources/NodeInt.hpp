#ifndef NODEINT_HPP
#define NODEINT_HPP

#include "NodeBase.hpp"

class NodeInt : public NodeBase {
    std::size_t index{};
    int data{};

public:
    NodeInt(std::size_t index, int data);

    NodeInt();

    size_t getIndex() const override;

    void setIndex(size_t newIndex) override;

    int getData() const override;

    NodeType getType() const override;

};

#endif // NODEINT_HPP
