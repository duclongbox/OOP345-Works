/*/////////////////////////////////////////////////////////////////////////
       workshop 5
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 10/15/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include "Movie.h"

using namespace std;
namespace sdds {
	Movie::Movie(){}
	const std::string& Movie::title() const {
		return m_title;
	}
	Movie::Movie(const std::string& strMovie) {
		string remaining = strMovie;
        size_t startPos = remaining.find_first_not_of(" ");
        if (startPos != string::npos) {
            size_t commaPos = remaining.find(',');
            if (commaPos != string::npos) {
                // Find the position of the last non-space character before the comma
                size_t endPos = remaining.find_last_not_of(" ", commaPos - 1);
                m_title = remaining.substr(startPos, endPos - startPos + 1);

            }
            remaining.erase(0, commaPos + 1);

        }

        startPos = remaining.find_first_not_of(" ");
        if (startPos != string::npos) {
            size_t commaPos = remaining.find(',');
            if (commaPos != string::npos) {
                // Find the position of the last non-space character before the comma
                size_t endPos = remaining.find_last_not_of(" ", commaPos - 1);
                m_year = stoi(remaining.substr(startPos, endPos - startPos + 1));

            }
            remaining.erase(0, commaPos + 1);
        }
        startPos = remaining.find_first_not_of(" ");
        remaining.erase(0, startPos);
        m_desc = remaining;

	}
    std::ostream& operator<<(std::ostream& ostr, const Movie& other) {
        ostr.width(40);
        ostr.fill(' ');
        ostr << other.m_title << " | ";
        ostr.width(4);
        ostr.fill(' ');
        ostr << other.m_year << " | " << other.m_desc << endl;
        return ostr;
    }


}
