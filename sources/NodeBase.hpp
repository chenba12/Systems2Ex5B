#ifndef NODEBASE_HPP
#define NODEBASE_HPP

#include <cstddef>

enum class NodeType {
    Int,
    IntPtr
};

class NodeBase {
public:

    virtual ~NodeBase() = default;

    virtual std::size_t getIndex() const = 0;

    virtual void setIndex(size_t) = 0;

    virtual NodeType getType() const = 0;

    virtual int getData() const = 0;

};

#endif // NODEBASE_HPP
