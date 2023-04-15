#ifndef MYLINKED
#define MYLINKED

#include <iterator>



    template <typename T>
    class myLinkedList
    {
    private:
        unsigned int size;
        T i;
        T *next;

    public:
        // myLinkedList(T const&) = default;
        // myLinkedList(T&&) = default;

        myLinkedList() : size{1}, next{nullptr}, i{}
        {
        }

        myLinkedList(T const& a) : size{1}, next{nullptr}, i{a}
        {
        }


        T getValue(){
            return i;
        }

        // friend std::ostream& operator<<(std::ostream& os, myLinkedList const& L){
        //     for( )
        // }


        // template<typename T, typename ... Rest>
        // requires (std::same_as<T,Rest> && ...)
        // myLinkedList(T const& a, Rest const&... rest)
        // {
            
        // }

    // myLinkedList& operator+=(myLinkedList const& rhs){
    //     // next = &rhs;
    //     T *current;

    //     if(next == nullptr){
    //        next = &rhs 
    //     }

    //     return *this;
    // }

};

#endif