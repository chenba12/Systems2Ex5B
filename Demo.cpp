#include <iostream>
#include <cassert>
#include "sources/MagicalContainer.hpp"

using namespace ariel;
using namespace std;

int main() {
    try {
        MagicalContainer container;

        // Test adding elements
        container.addElement(10);
        assert(container.size() == 1);
        cout << "Adding a single element passed" << endl;

        container.addElement(20);
        container.addElement(30);
        assert(container.size() == 3);
        cout << "Adding multiple elements passed" << endl;

        // Test removing elements
        container.removeElement(10);
        assert(container.size() == 2);
        cout << "Removing an existing element passed" << endl;

        try {
            container.removeElement(40);
        } catch(const std::runtime_error& e) {
            cout << "Removing a non-existing element threw an exception as expected" << endl;
        }

        // Test AscendingIterator
        MagicalContainer::AscendingIterator itAsc(container);
        assert(*itAsc == 20);
        ++itAsc;
        assert(*itAsc == 30);
        ++itAsc;
        assert(itAsc == itAsc.end());
        cout << "AscendingIterator passed" << endl;

        // Test SideCrossIterator
        MagicalContainer::SideCrossIterator itSideCross(container);
        assert(*itSideCross == 20);
        ++itSideCross;
        assert(*itSideCross == 30);
        ++itSideCross;
        assert(itSideCross == itSideCross.end());
        cout << "SideCrossIterator passed" << endl;

        // Test PrimeIterator
        MagicalContainer primeContainer;
        primeContainer.addElement(2);
        primeContainer.addElement(3);
        primeContainer.addElement(4);
        MagicalContainer::PrimeIterator itPrime(primeContainer);
        assert(*itPrime == 2);
        ++itPrime;
        assert(*itPrime == 3);
        ++itPrime;
        assert(itPrime == itPrime.end());
        cout << "PrimeIterator passed" << endl;




    } catch(const std::exception& e) {
        cout << "An exception occurred: " << e.what() << endl;
    }

    return 0;
}