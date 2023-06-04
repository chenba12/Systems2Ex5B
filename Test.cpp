#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("Test initial state of MagicalContainer") {
    MagicalContainer container;
    CHECK_EQ(container.size(), 0);
    MagicalContainer::AscendingIterator ascIt(container);
    MagicalContainer::PrimeIterator primeIt(container);
    MagicalContainer::SideCrossIterator sideIt(container);
    CHECK(ascIt.begin() == ascIt.end());
    CHECK_FALSE(ascIt.begin() != ascIt.end());
    CHECK(primeIt.begin() == primeIt.end());
    CHECK_FALSE(primeIt.begin() != primeIt.end());
    CHECK(sideIt.begin() == sideIt.end());
    CHECK_FALSE(sideIt.begin() != sideIt.end());
}

TEST_CASE("Test adding a single element to MagicalContainer") {
    MagicalContainer container;
    container.addElement(10);
    CHECK_EQ(container.size(), 1);
    MagicalContainer::AscendingIterator ascIt(container);
    CHECK_EQ(*ascIt.begin(), 10);
    CHECK_FALSE((*ascIt.begin() != 10));
    CHECK_EQ(++ascIt, ascIt.end());
    CHECK_FALSE((++ascIt != ascIt.end()));
}

TEST_CASE("Test adding multiple primeContainer to MagicalContainer") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    CHECK_EQ(container.size(), 3);
}

TEST_CASE("Test removing an element from MagicalContainer") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    CHECK_EQ(container.size(), 3);
    container.removeElement(20);
    CHECK_EQ(container.size(), 2);
    CHECK_NE(container.size(), 3);
}

TEST_CASE("Test removing a non-existing element from MagicalContainer") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.removeElement(40);
    CHECK_EQ(container.size(), 3);
}

TEST_CASE("Test interaction between operations") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(7);
    container.addElement(3);

    MagicalContainer::PrimeIterator iterator(container);
    CHECK_EQ(*iterator.begin(), 3);

    container.addElement(2);
    CHECK_EQ(*iterator.begin(), 2);

    container.removeElement(2);
    CHECK_EQ(*iterator.begin(), 3);
}

TEST_CASE("Test Copy constructor, assignment operator") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(7);
    container.addElement(3);

    MagicalContainer copyContainer(container);
    CHECK_EQ(container.size(), copyContainer.size());
    for (MagicalContainer::AscendingIterator it1(container), it2(copyContainer); it1 != it1.end(); ++it1, ++it2) {
        CHECK_EQ(*it1, *it2);
    }

    MagicalContainer anotherContainer;
    anotherContainer.addElement(9);
    anotherContainer = container;
    CHECK_EQ(container.size(), anotherContainer.size());
    for (MagicalContainer::AscendingIterator it1(container), it2(anotherContainer); it1 != it1.end(); ++it1, ++it2) {
        CHECK_EQ(*it1, *it2);
    }
}


TEST_CASE("Test AscendingIterator with multiple primeContainer") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(5);
    container.addElement(15);

    MagicalContainer::AscendingIterator iterator(container);
    CHECK_EQ(*iterator.begin(), 5);
    CHECK_FALSE((*iterator.begin() != 5));
    CHECK_EQ(*(++iterator), 10);
    CHECK_FALSE((*(++iterator) != 10));
    CHECK_EQ(*(++iterator), 15);
    CHECK_FALSE((*(++iterator) != 15));
    CHECK_EQ(++iterator, iterator.end());
    CHECK_FALSE((++iterator != iterator.end()));
}

TEST_CASE("Test SideCrossIterator with multiple primeContainer") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(5);
    container.addElement(15);

    MagicalContainer::SideCrossIterator iterator(container);
    CHECK_EQ(*iterator.begin(), 5);
    CHECK_FALSE((*iterator.begin() != 5));
    CHECK_EQ(*(++iterator), 15);
    CHECK_FALSE((*(++iterator) != 15));
    CHECK_EQ(*(++iterator), 10);
    CHECK_FALSE((*(++iterator) != 10));
    CHECK_EQ(++iterator, iterator.end());
    CHECK_FALSE((++iterator != iterator.end()));
}

TEST_CASE("Test PrimeIterator with multiple primeContainer") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(5);
    container.addElement(15);
    container.addElement(2);
    container.addElement(17);

    MagicalContainer::PrimeIterator iterator(container);
    CHECK_EQ(*iterator.begin(), 2);
    CHECK_FALSE((*iterator.begin() != 2));
    CHECK_EQ(*(++iterator), 5);
    CHECK_FALSE((*(++iterator) != 5));
    CHECK_EQ(*(++iterator), 17);
    CHECK_FALSE((*(++iterator) != 17));
    ++iterator;
    CHECK_EQ(iterator, iterator.end());
    CHECK_FALSE((iterator != iterator.end()));
}

TEST_CASE("Test iterators with no primeContainer in container") {
    MagicalContainer container;

    MagicalContainer::AscendingIterator ascIt(container);
    CHECK(ascIt.begin() == ascIt.end());
    CHECK_FALSE(ascIt.begin() != ascIt.end());

    MagicalContainer::SideCrossIterator sideIt(container);
    CHECK(sideIt.begin() == sideIt.end());
    CHECK_FALSE(sideIt.begin() != sideIt.end());

    MagicalContainer::PrimeIterator primeIt(container);
    CHECK(primeIt.begin() == primeIt.end());
    CHECK_FALSE(primeIt.begin() != primeIt.end());
}

TEST_CASE("Test comparison operators for AscendingIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(5);
    container.addElement(4);
    container.addElement(14);

    MagicalContainer::AscendingIterator it1(container);
    MagicalContainer::AscendingIterator it2(container);

    ++it2;
    ++it2;
    CHECK_GT(it2, it1);
    CHECK_FALSE((it1 > it2));
    CHECK_LT(it1, it2);
    CHECK_FALSE((it2 < it1));

    ++it2;
    CHECK_GT(it2, it1);
    CHECK_LT(it1, it2);

    ++it2;
    CHECK_GT(it2, it1);
    CHECK_LT(it1, it2);
}

TEST_CASE("Test comparison operators for PrimeIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(5);
    container.addElement(4);
    container.addElement(14);

    MagicalContainer::PrimeIterator it1(container);
    MagicalContainer::PrimeIterator it2(container);

    ++it2;
    CHECK_GT(it2, it1);
    CHECK_FALSE((it1 > it2));
    CHECK_LT(it1, it2);
    CHECK_FALSE((it2 < it1));
}

TEST_CASE("Test comparison operators for SideCrossIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(5);
    container.addElement(4);
    container.addElement(14);

    MagicalContainer::SideCrossIterator it1(container);
    MagicalContainer::SideCrossIterator it2(container);

    ++it2;
    ++it2;
    CHECK_LT(it1, it2);
    CHECK_FALSE((it2 < it1));

    ++it2;
    CHECK_GT(it2, it1);
    CHECK_FALSE((it1 > it2));
    CHECK_LT(it1, it2);
    CHECK_FALSE((it2 < it1));
}

TEST_CASE("Test AscendingIterator after adding new primeContainer") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);

    MagicalContainer::AscendingIterator it(container);
    CHECK_EQ(*it.begin(), 1);
    CHECK_FALSE((*it.begin() != 1));
    CHECK_EQ(*(++it), 2);
    CHECK_FALSE((*(++it) != 2));
    CHECK_EQ(++it, it.end());

    container.addElement(0);
    it = MagicalContainer::AscendingIterator(container); // refresh the iterator
    CHECK_EQ(*it.begin(), 0);
    CHECK_FALSE((*it.begin() != 0));
    CHECK_EQ(++it, it.end());
}

TEST_CASE("Test PrimeIterator after adding new primeContainer") {
    MagicalContainer container;
    container.addElement(3);
    container.addElement(5);

    MagicalContainer::PrimeIterator it(container);
    CHECK_EQ(*it.begin(), 3);
    CHECK_FALSE((*it.begin() != 3));
    CHECK_EQ(*(++it), 5);
    CHECK_FALSE((*(++it) != 5));
    CHECK_EQ(++it, it.end());

    container.addElement(2);
    it = MagicalContainer::PrimeIterator(container); // refresh the iterator
    CHECK_EQ(*it.begin(), 2);
    CHECK_FALSE((*it.begin() != 2));
    CHECK_EQ(++it, it.end());
}

TEST_CASE("Test SideCrossIterator after adding new primeContainer") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);

    MagicalContainer::SideCrossIterator it(container);
    CHECK_EQ(*it.begin(), 1);
    CHECK_FALSE((*it.begin() != 1));
    CHECK_EQ(*(++it), 2);
    CHECK_FALSE((*(++it) != 2));
    CHECK_EQ(++it, it.end());

    container.addElement(3);
    it = MagicalContainer::SideCrossIterator(container); // refresh the iterator
    CHECK_EQ(*it.begin(), 1);
    CHECK_FALSE((*it.begin() != 1));
    CHECK_EQ(*(++it), 3);
    CHECK_FALSE((*(++it) != 3));
    CHECK_EQ(*(++it), 2);
    CHECK_FALSE((*(++it) != 2));
    CHECK_EQ(++it, it.end());
}

TEST_CASE("Test AscendingIterator after removing primeContainer") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    MagicalContainer::AscendingIterator it(container);
    CHECK_EQ(*it.begin(), 1);
    CHECK_FALSE((*it.begin() != 1));
    CHECK_EQ(*(++it), 2);
    CHECK_FALSE((*(++it) != 2));
    CHECK_EQ(*(++it), 3);
    CHECK_FALSE((*(++it) != 3));
    CHECK_EQ(++it, it.end());

    container.removeElement(1);
    it = MagicalContainer::AscendingIterator(container); // refresh the iterator
    CHECK_EQ(*it.begin(), 2);
    CHECK_FALSE((*it.begin() != 2));
    CHECK_EQ(*(++it), 3);
    CHECK_FALSE((*(++it) != 3));
    CHECK_EQ(++it, it.end());
}

TEST_CASE("Test PrimeIterator after removing primeContainer") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(5);

    MagicalContainer::PrimeIterator it(container);
    CHECK_EQ(*it.begin(), 2);
    CHECK_FALSE((*it.begin() != 2));
    CHECK_EQ(*(++it), 3);
    CHECK_FALSE((*(++it) != 3));
    CHECK_EQ(*(++it), 5);
    CHECK_FALSE((*(++it) != 5));
    CHECK_EQ(++it, it.end());

    container.removeElement(2);
    it = MagicalContainer::PrimeIterator(container); // refresh the iterator
    CHECK_EQ(*it.begin(), 3);
    CHECK_FALSE((*it.begin() != 3));
    CHECK_EQ(*(++it), 5);
    CHECK_FALSE((*(++it) != 5));
    CHECK_EQ(++it, it.end());
}


TEST_CASE("Test SideCrossIterator after removing primeContainer") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    MagicalContainer::SideCrossIterator it(container);
    CHECK_EQ(*it.begin(), 1);
    CHECK_FALSE((*it.begin() != 1));
    CHECK_EQ(*(++it), 3);
    CHECK_FALSE((*(++it) != 3));
    CHECK_EQ(*(++it), 2);
    CHECK_FALSE((*(++it) != 2));
    CHECK_EQ(++it, it.end());

    container.removeElement(1);
    it = MagicalContainer::SideCrossIterator(container); // refresh the iterator
    CHECK_EQ(*it.begin(), 3);
    CHECK_FALSE((*it.begin() != 3));
    CHECK_EQ(*(++it), 2);
    CHECK_FALSE((*(++it) != 2));
    CHECK_EQ(++it, it.end());
}

TEST_CASE("Test incrementing iterators past the end") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(3);

    MagicalContainer::SideCrossIterator itSide(container);
    MagicalContainer::AscendingIterator itAsc(container);
    MagicalContainer::PrimeIterator itPrime(container);

    for (auto i = itSide.begin(); i < itSide.end(); ++i) {
    }
    for (auto i = itAsc.begin(); i < itAsc.end(); ++i) {
    }
    for (auto i = itPrime.begin(); i < itPrime.end(); ++i) {
    }
    CHECK_THROWS(++itSide);
    CHECK_THROWS(++itAsc);
    CHECK_THROWS(++itPrime);
}
