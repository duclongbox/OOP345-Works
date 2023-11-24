/*/////////////////////////////////////////////////////////////////////////
       milestone 1
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 11/1/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <iomanip>
#include"Utilities.h"
#include "Station.h"

using namespace std;
namespace sdds {
    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;
    Station::Station(const std::string & str) {
        Utilities util{};
        
        size_t next_pos = 0;
        bool more = true;
        id_generator++;
        m_stationID = id_generator;
        m_name = util.extractToken(str, next_pos, more);
        m_nextNum = std::stoul(util.extractToken(str, next_pos, more));
        m_noOfItem = std::stoul(util.extractToken(str, next_pos, more));
        if (util.getFieldWidth() > m_widthField) {
            m_widthField = util.getFieldWidth();
        }
        m_desc = util.extractToken(str, next_pos, more);
    }

    const std::string& Station::getItemName() const {
        return m_name;
    }

    size_t Station::getNextSerialNumber() {
       
        return m_nextNum++;
    }

    size_t Station::getQuantity() const {
        return m_noOfItem;
    }

    void  Station::updateQuantity() {
        if (m_noOfItem > 0) {
            --m_noOfItem;
        }
        else {
            m_noOfItem = 0;
        }
    }

    void Station::display(std::ostream& os, bool full) const {
        os.setf(ios::right);
        os.width(3);
        os.fill('0');
        os << m_stationID << " | ";
        os.unsetf(ios::right);

        os.setf(ios::left);
        os.width(m_widthField);
        os.fill(' ');
        os << m_name << " | ";
        os.unsetf(ios::left);
        
        os.setf(ios::right);
        os.width(6);
        os.fill('0');
        os  << m_nextNum << " | ";

        if (full) {
            os.width(4);
            os.fill(' ');
            os<< m_noOfItem << " | " << m_desc;
        }

        os << std::endl;
    }



}