#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include "NodeInt.hpp"
#include "NodeIntPtr.hpp"
#include "list"


namespace ariel {
    enum iteratorType {
        asc = 0, cross = 1, prime = 2
    };

    class MagicalContainer {
    private:
        size_t currentSize;
        std::list<NodeInt> elementsAsc;
        std::list<NodeIntPtr> primeHelper;


    public:
        void addElement(int element);

        void removeElement(int element);

        size_t size() const;

        class BaseIterator {
            MagicalContainer *magicalContainerPtr;
            enum iteratorType type;
            NodeBase *current;
        public:
            BaseIterator(MagicalContainer *magicalContainerPtr, iteratorType type, NodeBase *current);

            bool operator>(const BaseIterator &other) const;

            bool operator<(const BaseIterator &other) const;

            bool operator==(const BaseIterator &other) const;

            bool operator!=(const BaseIterator &other) const;

            int operator*();

            iteratorType getType() const;

            MagicalContainer *getMagicalContainerPtr() const;

            NodeBase *getCurrent() const {
                return current;
            }

            void setCurrent(NodeBase *newCurrent) {
                BaseIterator::current = newCurrent;
            }
        };

        class AscendingIterator : public BaseIterator {

        public:
            explicit AscendingIterator(MagicalContainer &container);

            AscendingIterator(const AscendingIterator &other);

            AscendingIterator();

            ~AscendingIterator();

            AscendingIterator &operator=(const AscendingIterator &other);

            AscendingIterator &operator++();

            AscendingIterator begin();

            AscendingIterator end();
        };

        class SideCrossIterator : public BaseIterator {
        private:
            bool front;
            NodeInt *tail;
        public:
            explicit SideCrossIterator(MagicalContainer &container);

            SideCrossIterator();

            SideCrossIterator(const SideCrossIterator &other);

            ~SideCrossIterator();

            SideCrossIterator &operator=(const SideCrossIterator &other);

            SideCrossIterator &operator++();

            SideCrossIterator begin();

            SideCrossIterator end();

            bool isFront() const;

            void setFront(bool front);

            NodeInt *getTail() const;

            void setTail(NodeInt *tail);
        };

        class PrimeIterator : public BaseIterator {
        public:
            explicit PrimeIterator(MagicalContainer &container);

            PrimeIterator();

            PrimeIterator(const PrimeIterator &other);

            ~PrimeIterator();

            PrimeIterator &operator=(const PrimeIterator &other);

            PrimeIterator &operator++();

            PrimeIterator begin();

            PrimeIterator end();
        };

    private:

        static bool isPrime(int n);


    };
}

#endif
