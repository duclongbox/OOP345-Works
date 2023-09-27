//
//  Book.cpp
//  ws03
//
//  Created by Long Hoàng on 2023-09-27.
//
#include <iostream>
#include "Book.h"

using namespace std;
namespace sdds {
    Book::Book(const std::string& title, unsigned nChapters, unsigned nPages){
        m_title = title;
        m_numChapters = nChapters;
        m_numPages = nPages;
        
    }
    bool Book::operator<(const Book& other){
        if ((other.m_numPages/other.m_numChapters)>(m_numPages/m_numChapters)){
            return true;
        }
        return false;
    }
    bool Book::operator>(const Book& other){
        if ((other.m_numPages/other.m_numChapters)<(m_numPages/m_numChapters)){
            return true;
        }
        return false;
    }
    ostream& Book::print(ostream& os) const {
        if(m_title.length()!=0){
            string book = m_title + "," + to_string(m_numChapters)+ "," + to_string(m_numPages);
            os.setf(ios::right);
            os.width(56);
            os<< book << " | ";
            os.unsetf(ios::right);
            os << "(";
            os.setf(ios::fixed);
            os.precision(6);
            os << (double)m_numPages/(double)m_numChapters;
            os << ")    ";
            os.unsetf(ios::fixed);
        }
        else{
            os << "| Invalid book data";
        }
        
        return os;
    }
    ostream& operator<<(ostream& os, const Book& bk){
        bk.print(os);
        return os;
    }

    
}
