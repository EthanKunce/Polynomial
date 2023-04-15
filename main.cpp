#include <iostream>
// #include "myLinkedList.hpp"
#include "polynomial.hpp"

int main(){

    // myLinkedList<int> a;
    // std::cout<< a.i << '\n';

    // Polynomial p1{};
    Polynomial p1{0, -10};
    // Polynomial p2{0, 5};
    Polynomial p3{3, 2};
    Polynomial p4{3, 2};
    // p1 += p2;
    // p1 += p3 + p2;

    p4 *= p3;

    // p3 -= p1;
    // std::cout << p1.pTo_string() << "\n";
    std::cout << p1 << "\n";
    std::cout << p4 << "\n";
    return 0;
}
