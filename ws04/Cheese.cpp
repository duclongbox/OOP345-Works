//
//  Cheese.cpp
//  ws04
//
//  Created by Long Hoàng on 2023-10-02.
//

#include <iostream>
#include <string>
#include "Cheese.h"

using namespace std;
namespace sdds {
    Cheese::Cheese(const std::string& str) {
        string remaining = str;
        size_t posSpace = remaining.find_first_not_of(" ");
        remaining.erase(0, posSpace);
        size_t pos = remaining.find(',');
        m_name = remaining.substr(0, pos);
        remaining.erase(0, pos + 1); // Skip ',' and space
        
       
        pos = remaining.find(',');
        m_weight = stoi(remaining.substr(0, pos));
        remaining.erase(0, pos + 1); // Skip ',' and space
        
        pos = remaining.find(',');
        if (pos != string::npos) {
            m_price = stod(remaining.substr(0, pos));
            remaining.erase(0, pos+1); // Skip ',' and space
        }

        
    
        // Find the position of the first non-space character
        size_t startPos = remaining.find_first_not_of(" ");
        if (startPos != string::npos) {
            size_t commaPos = remaining.find(',');
            if (commaPos != string::npos) {
                // Find the position of the last non-space character before the comma
                size_t endPos = remaining.find_last_not_of(" ", commaPos - 1);
                m_features = remaining.substr(startPos, endPos - startPos + 1);
               
            }
            remaining.erase(0, commaPos + 1);
           
        }
        startPos = remaining.find_first_not_of(" ");
        if (startPos != string::npos) {
            size_t commaPos = remaining.find(',');
            if (commaPos != string::npos) {
                // Find the position of the last non-space character before the comma
                size_t endPos = remaining.find_last_not_of(" ", commaPos - 1);
                m_features += " ";
                m_features += remaining.substr(startPos, endPos - startPos + 1);

            }
            remaining.erase(0, commaPos + 1);

        }
        startPos = remaining.find_first_not_of(" ");
        if (startPos != string::npos) {
            // Find the position of the last non-space character before the comma
            size_t endPos = remaining.find_last_not_of(" ");
            m_features += " ";
            m_features += remaining.substr(startPos, endPos - startPos + 1);
            m_features += " ";
            
        }
        
    }

    Cheese Cheese::slice(size_t weight) {
        if (weight <= m_weight) {
            Cheese slicedCheese = *this;
            slicedCheese.m_weight = weight;
            m_weight -= weight;
            return slicedCheese;
        }
        else {
            // return Cheese in empty state
            return Cheese();
        }
    }
    string Cheese::getName() const {
        return m_name;
    }
    int Cheese::getWeight() const {
        return m_weight;
    }
    double Cheese::getPrice() const {
        return m_price;
    }
    string Cheese::getFeatures() const {
        return m_features;
    }
    std::ostream& operator<<(std::ostream& os, const Cheese& cheese) {
        os << "|";
        os.setf(ios::left);
        os.width(21);
        os.fill(' ');
        os << cheese.m_name << "|";
        //os.unsetf(ios::left);

        os.width(5);
        os.fill(' ');
        os << cheese.m_weight << "|";

        os.setf(ios::fixed);
        os.precision(2);
        os.width(5);
        os.fill(' ');
        os << cheese.m_price << "|";

        os.setf(ios::right);
        os.width(34);
        os.fill(' ');
        os << cheese.m_features << "|" << endl;
        os.unsetf(ios::right);
        return os;
    }

}