#include "MagicalContainer.hpp"
#include <math.h>
using namespace std;

bool isPrime(int num) {
    if (num<2)
        return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}



namespace ariel {

    // MagicalContainer

    void MagicalContainer::addElement(int element) {
        elements.push_back(element);
    }

    void MagicalContainer::removeElement(int element) {
        elements.erase(remove(elements.begin(), elements.end(), element), elements.end());
    }

    int MagicalContainer::size() const {
        return elements.size();
    }


    // AscendingIterator

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& cont)
            : container(cont), iterator(cont.elements.begin()) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other)
            : container(other.container), iterator(other.iterator) {}

    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return false;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        return 0;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::begin(){
        return *this;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::end() {
        return *this;
    }

    // SideCrossIterator

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& cont)
            : container(cont), frontItr(cont.elements.begin()),
              backItr(cont.elements.rbegin()), forward(true) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
            : container(other.container),
              frontItr(other.frontItr),
              backItr(other.backItr),
              forward(other.forward) {}

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return false;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        return 0;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator:: begin(){
        return *this;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator:: end() {
        return *this;
    }

    // PrimeIterator

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& cont)
            : container(cont), iterator(cont.elements.begin()) {
        while (!isPrime(*iterator) &&iterator != container.elements.end() ) {
            ++iterator;
        }
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
            : container(other.container), iterator(other.iterator) {}

    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return false;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        return 0;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator:: begin(){
        return *this;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator:: end(){
        return *this;
    }
}