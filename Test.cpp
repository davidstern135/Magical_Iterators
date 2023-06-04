#include "doctest.h"
#include <stdexcept>
#include "sources/MagicalContainer.hpp"


using namespace std;
using namespace ariel;
TEST_CASE("Check prime is prime") {
    CHECK(isPrime(5));
    CHECK(isPrime(7));
    CHECK(!isPrime(10));
}
TEST_CASE("Check MegicalContainer basic functions") {

    CHECK_NOTHROW(MagicalContainer cont);
    MagicalContainer container;
    CHECK_NOTHROW(container.size());

    //container.addElement(int)+container.size()

    CHECK_EQ(container.size(), 0);
    container.addElement(1);
    CHECK_EQ(container.size(), 1);
    container.addElement(2);
    CHECK_EQ(container.size(), 2);
    container.addElement(3);
    CHECK_EQ(container.size(), 3);
    container.addElement(4);
    CHECK_EQ(container.size(), 4);
    container.addElement(5);
    CHECK_EQ(container.size(), 5);
    container.addElement(6);
    CHECK_EQ(container.size(), 6);

    //container.removeElement(int)+container.size()

    container.removeElement(6);
    CHECK_EQ(container.size(), 5);
    container.removeElement(5);
    CHECK_EQ(container.size(), 4);
    container.removeElement(6);//an element that shouldn't be there.
    CHECK_EQ(container.size(), 4);
}

TEST_CASE("Checking ascending iterator") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(4);
    container.addElement(17);
    container.addElement(22);
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);


    MagicalContainer::AscendingIterator ascending(container);

    auto ascendingItr = ascending.begin();
    CHECK_EQ(*ascendingItr, 1);
    ++ascendingItr;
    CHECK_EQ(*ascendingItr, 2);
    ++ascendingItr;
    CHECK_EQ(*ascendingItr, 3);
    ++ascendingItr;
    CHECK_EQ(*ascendingItr, 4);
    ++ascendingItr;
    CHECK_EQ(*ascendingItr, 5);
    ++ascendingItr;
    CHECK_EQ(*ascendingItr, 17);
    ++ascendingItr;
    CHECK_EQ(*ascendingItr, 22);
    CHECK_THROWS(++ascendingItr);


}

TEST_CASE("Check the PrimeIterator") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(6);
    container.addElement(15);
    container.addElement(3);
    container.addElement(7);
    container.addElement(5);
    container.addElement(10);

    MagicalContainer::PrimeIterator prime(container);

    auto primeItr = prime.begin();
    CHECK_EQ(*primeItr, 2);
    ++primeItr;
    CHECK_EQ(*primeItr, 3);
    ++primeItr;
    CHECK_EQ(*primeItr, 7);
    ++primeItr;
    CHECK_EQ(*primeItr, 5);
    CHECK_THROWS(++primeItr);
}

TEST_CASE("Check the SideCrossIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);
    container.addElement(7);
    container.addElement(8);
    container.addElement(9);
    container.addElement(10);

    MagicalContainer::SideCrossIterator side(container);

    auto sideItr = side.begin();
    for(int i=1; i<=10;i++){
        CHECK_EQ(*sideItr, i);
        ++sideItr;
    }
    CHECK_THROWS(++sideItr);
}

TEST_CASE("Check iterator comparisons") {
    MagicalContainer containerToAsc;
    containerToAsc.addElement(1);
    containerToAsc.addElement(2);
    containerToAsc.addElement(3);
    containerToAsc.addElement(4);
    containerToAsc.addElement(5);
    MagicalContainer::AscendingIterator ascendingItr1(containerToAsc);

    MagicalContainer containerToAsc2;
    containerToAsc2.addElement(1);
    containerToAsc2.addElement(3);
    containerToAsc2.addElement(2);
    containerToAsc2.addElement(4);
    containerToAsc2.addElement(5);
    MagicalContainer::AscendingIterator ascendingItr2(containerToAsc2);

    CHECK_EQ(ascendingItr1, ascendingItr2);
    containerToAsc.addElement(6);

    MagicalContainer containerToAsc3;
    containerToAsc3.addElement(1);
    containerToAsc3.addElement(2);
    containerToAsc3.addElement(3);
    containerToAsc3.addElement(4);
    containerToAsc3.addElement(5);
    MagicalContainer::AscendingIterator ascendingItr3(containerToAsc3);
    CHECK_NE(ascendingItr3, ascendingItr2);

    MagicalContainer containerToPrime;
    containerToPrime.addElement(2);
    containerToPrime.addElement(4);
    containerToPrime.addElement(3);
    containerToPrime.addElement(5);
    containerToPrime.addElement(6);
    MagicalContainer::PrimeIterator primeItr(containerToPrime);


    MagicalContainer containerToPrime2;
    containerToPrime2.addElement(2);
    containerToPrime2.addElement(10);
    containerToPrime2.addElement(3);
    containerToPrime2.addElement(12);
    containerToPrime2.addElement(5);
    MagicalContainer::PrimeIterator primeItr2(containerToPrime2);


    CHECK_EQ(primeItr, primeItr2);

    MagicalContainer containerToPrime3;
    containerToPrime3.addElement(3);
    containerToPrime3.addElement(2);
    containerToPrime3.addElement(12);
    containerToPrime3.addElement(10);
    containerToPrime3.addElement(5);
    MagicalContainer::PrimeIterator primeItr3(containerToPrime3);

    CHECK_NE(primeItr3, primeItr2);





}