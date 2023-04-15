#ifndef POLYNOMIAL
#define POLYNOMIAL


#include <map>
#include <iostream>
#include <string>

class Polynomial
{
private:
    std::map<int, int> polynom;
    int degree;

public:
    //need to add error handling for negative degree
    Polynomial(int degree1, int coEfficient) : 
                                                polynom{},
                                               degree{degree1}
    {
        // this->polynom.insert(degree1, coEfficient);
        this->polynom[degree1] = coEfficient;
    }

    Polynomial() : 
                   polynom{},
                   degree{-1}
    {
    }



    // iterates through newTerms polynom map, checks if a term with the same degree exists and adds them together.
    // Otherwise adds it to the end of this object

    std::string pTo_string()
    {
        std::string temp = "";

        for (auto d : this->polynom)
        {
            // int c = this->polynom.find(d.first);
            int c = d.second;

            if (d.first == 0)
            {
                temp += (std::to_string(c));
            }
            else if(d.first > 1){
                // if coefficient is 1, then print x(degree) otherwise check if coefficent is -1, then print -x(degree) otherwise print coefficient(x)degree
                temp += c == 1 ? "x" + std::to_string(d.first) : c == -1 ? "-x" + std::to_string(d.first) : std::to_string(c) + "x" + std::to_string(d.first);
                //really ugly.
            }
            else{
                temp += (std::to_string(c) + "x");
            }

            if (d.first < this->degree)
            {
                temp += " + ";
            }
        }
        return temp;
    }

    Polynomial &operator+=(Polynomial const &newTerm)
    {
        // for (auto i = newTerm.polynom.cbegin(); i != newTerm.polynom.cend(); i++)
        for (auto & i : newTerm.polynom)
        {

            if (i.first > degree)
            { // as i
                degree = i.first;
            }

            if(this->polynom.find(i.first) != this->polynom.end()){
                int sum = this->polynom.find(i.first)->second + i.second;

                if(sum == 0){
                    this->polynom.erase(i.first);
                }
                else{
                    this->polynom[i.first] = this->polynom.find(i.first)->second + i.second;
                }
                // std::cout<< this->polynom.find(i.first)->first << " " <<  this->polynom.find(i.first)->second << "\n";
                // std::cout << i.first << " " << i.second << '\n';

            } 
            else{
                this->polynom[i.first] = i.second;
            }
        }

        return *this;
    }
    Polynomial &operator-=(Polynomial const &newTerm)
    {
        for (auto & i : newTerm.polynom){
            // newTerm.polynom[i.first] = -newTerm.polynom[i.first];
            Polynomial inverse{i.first, -newTerm.polynom.at(i.first)};
            *this += inverse;
        }

        return *this;
    }


    
    Polynomial &operator*=(Polynomial const& lhs){
        //we create a holder map to replace the map in the implicit variable
        Polynomial newMap{};

        for(auto & i : this->polynom){
            for (auto & j : lhs.polynom){
                // this->polynom[i.first + j.first] = this->polynom.find(i.first)->second * lhs.polynom.find(j.first)->second;
                newMap += Polynomial{i.first + j.first, this->polynom.find(i.first)->second * lhs.polynom.find(j.first)->second};
                if(i.first + j.first > this->degree) this->degree = i.first + j.first;
            }
        }
        //we can delete our current map and erase any of the previous values
        this->polynom.clear();
        //we can use the std::map() copy constructer to copy the newMap back into our this pointer and our polynom member;
        this->polynom = std::map<int,int>(newMap.polynom);
        //probably more memory efficient way of doing this.
    return *this;
    }
};
//for some reason I can't call pTo_string() on const Polynomials, I also can't build the string in the function, as this function does not have access to private memebers of m
// std::ostream& operator<<(std::ostream& os ,Polynomial const& m){
std::ostream& operator<<(std::ostream& os, Polynomial m){
    // auto i =  m.pTo_string();
    // os << i;
    os << m.pTo_string();
    
    return os;
}

Polynomial operator+(Polynomial const &rhs, Polynomial const &lhs)
{
    Polynomial lhsi{lhs};
    lhsi += rhs;
    return lhsi;
}
Polynomial operator-(Polynomial const &rhs, Polynomial const &lhs)
{
    Polynomial lhsi{lhs};
    lhsi -= rhs;
    return lhsi;
}
Polynomial operator*(Polynomial const &rhs, Polynomial const &lhs)
{
    Polynomial lhsi{lhs};
    lhsi *= rhs;
    return lhsi;
}

#endif