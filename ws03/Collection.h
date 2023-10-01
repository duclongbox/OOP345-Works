#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
#include "Book.h"

namespace sdds {
    template<typename T, size_t C>
    class Collection {
        T m_items[C]{}; // array of items
        static T m_smallestItem;
        static T m_largestItem;
        size_t m_size{}; // number of items
    protected:
        void setSmallestItem(const T& other) {
            if (other < m_smallestItem) {
                m_smallestItem = other;
            }
        }
        void setLargestItem(const T& other) {
            if (other > m_largestItem) {
                m_largestItem = other;
            }
        }
    public:
        // public members
        static T getSmallestItem() {
            return m_smallestItem;
        }
        static T getLargestItem() {
            return m_largestItem;
        }
        //public instances
        size_t size()const {
            //return the number of items
            return m_size;
        }
        size_t capacity() const {
            //return the capacity of collection
            return C;
        }

        bool operator+=(const T& other) {
            if (m_size >= C) {
                return false;
            }
            if ( other < m_smallestItem) {
                setSmallestItem(other);
            }
            if ( other > m_largestItem) {
                setLargestItem(other);
            }
            m_items[m_size++] = other;
            //m_size++;
            return true;
        }
        
        void print(std::ostream& ostr) {
            ostr << "[";
            for (size_t i = 0; i < m_size; i++) {
                ostr << m_items[i];
                if (i != m_size - 1) {
                    ostr << ",";
                }
            }
            ostr << "]" << std::endl;
        }
        //return the corresponding element from array
        T& operator[](size_t index){
            return m_items[index];
        }
        void incrSize(){
            m_size++;
        }
        
    };
    // initialize
    template<typename T, size_t C>
     T Collection <T, C> ::m_smallestItem = 9999;
    template<typename T, size_t C>
     T Collection <T, C> ::m_largestItem = -9999;
    //specializtion template
    template <>
    Book Collection<Book, 10>::m_smallestItem("", 1, 1000);
    template <>
    Book Collection<Book, 10>::m_largestItem("", 1000, 1);
    template <>
    Book Collection<Book, 72>::m_smallestItem("", 1, 10000);
    template <>
    Book Collection<Book, 72>::m_largestItem("", 10000, 1);
    template <>
    void Collection<Book,10>::print(std::ostream& ostr){
        ostr << "|---------------------------------------------------------------------------|" << std::endl;
        for (size_t i =0; i < m_size; i++){
            ostr << "| " << m_items[i] << "|" << std::endl;
        }
        ostr << "|---------------------------------------------------------------------------|" << std::endl;
    }
    template <>
    void Collection<Book,72>::print(std::ostream& ostr){
        ostr << "|---------------------------------------------------------------------------|" << std::endl;
        for (size_t i =0; i < m_size; i++){
            ostr << "| " << m_items[i] << "|" << std::endl;
        }
        ostr << "|---------------------------------------------------------------------------|" << std::endl;
    }
    
    
}


#endif // !SDDS_COLLECTION_H
