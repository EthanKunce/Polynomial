#include <iostream>
// #include "myLinkedList.hpp"
#include "polynomial.hpp"

int main(){

    // myLinkedList<int> a;
    // std::cout<< a.i << '\n';

    // Polynomial p1{};
    Polynomial p1{0, 2};
    Polynomial p2{0, 5};
    // p1 += p2;
    std::cout << p1 << "\n";


    Polynomial p3{1, 1};
    Polynomial p4{1, 1};

    p3 += p1;
    p4 += Polynomial(0, 3);

    p4 *= p3;

    // p3 -= p1;
    // std::cout << p1.pTo_string() << "\n";
    std::cout << p4 << "\n";
    return 0;
}
