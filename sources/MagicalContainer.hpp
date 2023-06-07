#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include "LinkedList.hpp"


namespace ariel {

    class MagicalContainer {
    private:
        std::size_t currentSize;
        LinkedList<int> elementsAsc;
        LinkedList<const int *> elementsPrime;

        static bool isPrime(int n);

    public:
        MagicalContainer();

        void addElement(int element);

        void removeElement(int element);

        size_t size() const;

        const LinkedList<int> &getElementsAsc() const;

        class AscendiongIterator;

        class SideCrossIterator;

        class PrimeIterator;

        class AscendingIterator {
        private:
            MagicalContainer *container;
            std::shared_ptr<Node<int>> current;
        public:
            explicit AscendingIterator(MagicalContainer &container);

            AscendingIterator(const AscendingIterator &other);

            AscendingIterator();

            AscendingIterator(AscendingIterator &&other) noexcept;
            AscendingIterator &operator=(AscendingIterator &&other) noexcept;

            ~AscendingIterator();

            AscendingIterator &operator=(const AscendingIterator &other);

            AscendingIterator &operator++();

            int &operator*() const;

            AscendingIterator begin();

            AscendingIterator end();

            bool operator==(const AscendingIterator &other) const;

            bool operator!=(const AscendingIterator &other) const;

            bool operator<(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other) const;

            bool operator==(const SideCrossIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator==(const PrimeIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

        };

        class SideCrossIterator {
        private:
            std::size_t count;
            MagicalContainer *container;
            bool flip;
            std::shared_ptr<Node<int>> front;
            std::shared_ptr<Node<int>> back;
        public:
            explicit SideCrossIterator(MagicalContainer &container);

            SideCrossIterator();

            SideCrossIterator(const SideCrossIterator &other);

            ~SideCrossIterator();

            SideCrossIterator(SideCrossIterator &&other) noexcept;
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;

            SideCrossIterator &operator=(const SideCrossIterator &other);

            SideCrossIterator &operator++();

            int &operator*() const;

            SideCrossIterator begin();

            SideCrossIterator end();


            bool operator==(const AscendingIterator &other) const;

            bool operator!=(const AscendingIterator &other) const;

            bool operator<(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other) const;

            bool operator==(const SideCrossIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator==(const PrimeIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

        };

        class PrimeIterator {
        private:
            MagicalContainer *container;
            std::shared_ptr<Node<const int *>> current;
        public:
            explicit PrimeIterator(MagicalContainer &container);

            PrimeIterator();

            PrimeIterator(const PrimeIterator &other);

            PrimeIterator(PrimeIterator &&other) noexcept;
            PrimeIterator &operator=(PrimeIterator &&other) noexcept;

            ~PrimeIterator();

            PrimeIterator &operator=(const PrimeIterator &other);

            PrimeIterator &operator++();

            const int &operator*() const;

            PrimeIterator begin();

            PrimeIterator end();

            bool operator==(const AscendingIterator &other) const;

            bool operator!=(const AscendingIterator &other) const;

            bool operator<(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other) const;

            bool operator==(const SideCrossIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator==(const PrimeIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

        };


    };
}

#endif
