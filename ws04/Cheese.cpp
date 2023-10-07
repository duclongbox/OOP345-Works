//
//  Cheese.cpp
//  ws04
//
//  Created by Long Hoàng on 2023-10-02.
//

#include <iostream>
#include "Cheese.h"

using namespace std;
namespace sdds{
    Cheese::Cheese(const std::string& str){
        string remaining = str;

        size_t pos = remaining.find(',');
        if (pos != string::npos) {
            m_name = remaining.substr(0, pos);
            remaining.erase(0, pos + 2); // Skip ',' and space
        }

        pos = remaining.find(',');
        if (pos != string::npos) {
            m_weight = stoi(remaining.substr(0, pos));
            remaining.erase(0, pos + 2); // Skip ',' and space
        }

        pos = remaining.find(',');
        if (pos != string::npos) {
            m_price = stod(remaining.substr(0, pos));
            remaining.erase(0, pos + 2); // Skip ',' and space
        }

        
        size_t firstCommaPos = remaining.find(',');
        if (firstCommaPos != string::npos) {
            m_features += remaining.substr(0,firstCommaPos);
            remaining.erase(0, firstCommaPos +1);
         }
        size_t secondCommaPos = remaining.find(',');
        if (secondCommaPos != string::npos) {
        //     remaining.erase(0, secondCommaPos + 1);
            m_features += remaining.substr(0,secondCommaPos);
            remaining.erase(0, secondCommaPos +1);
        }
        m_features += remaining;
    }

    Cheese Cheese::slice(size_t weight){
        if (weight< m_weight){
            Cheese slicedCheese = *this;
            slicedCheese.m_weight= weight;
            m_weight -= weight;
            return slicedCheese;
        }
        else{
            // return Cheese in empty state
            return Cheese();
        }
    }
    string Cheese::getName() const{
        return n_name;
    }
    int Cheese::getWeight() const{
        return m_weight;
    }
    double Cheese::getPrice() const{
        return m_price;
    }
    string Cheese::getFeatures() const{
        return m_features;
    }
    friend std::ostream& operator<<(std::ostream& os, const Cheese& cheese){
        os << "|";
        os.setf(ios::left);
        os.width(21);
        os.fill('');
        os << m_name << "|";
        os.unsetf(ios::left);
        
        os.width(5);
        os.fill('');
        os << m_weight << "|";
        
        os.setf(ios::fixed);
        os.precision(2);
        os.width(5);
        os.fill('');
        os << m_price << "|";
        
        os.setf(ios::right);
        os.width(34);
        os.fill('');
        os << m_features << "|" << endl;
        os.unsetf(ios::right);
    }

}
