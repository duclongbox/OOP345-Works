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
#include "Book.h"

using namespace std;
namespace sdds {
	Book::Book() {

	}
	const string& Book::title() const {
		return m_title;
	}
	const std::string& Book::country() const {
		return m_country;
	}
	const size_t& Book::year() const {
		return m_year;
	}
	double& Book::price() {
		return m_price;
	}
	Book::Book(const std::string& strBook) {
		string remaining = strBook;
		size_t pos = remaining.find(',');
		m_author = remaining.substr(0, pos);
		remaining.erase(0, pos+1);

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
				m_country = remaining.substr(startPos, endPos - startPos + 1);

			}
			remaining.erase(0, commaPos + 1);
		}
		 startPos = remaining.find_first_not_of(" ");
		if (startPos != string::npos) {
			size_t commaPos = remaining.find(',');
			if (commaPos != string::npos) {
				// Find the position of the last non-space character before the comma
				size_t endPos = remaining.find_last_not_of(" ", commaPos - 1);
				m_price = stod(remaining.substr(startPos, endPos - startPos + 1));

			}
			remaining.erase(0, commaPos + 1);
		}
		 startPos = remaining.find_first_not_of(" ");
		if (startPos != string::npos) {
			size_t commaPos = remaining.find(',');
			if (commaPos != string::npos) {
				// Find the position of the last non-space character before the comma
				size_t endPos = remaining.find_last_not_of(" ", commaPos - 1);
				m_year = stod(remaining.substr(startPos, endPos - startPos + 1));

			}
			remaining.erase(0, commaPos+1);
		}
		size_t posSpace = remaining.find_first_not_of(" ");
		remaining.erase(0, posSpace);
		m_description = remaining;
	}
	std::ostream& operator<<(std::ostream& ostr, const Book& other) {
		ostr.width(20);
		ostr.fill(' ');
		ostr << other.m_author << " | ";
		ostr.width(22);
		ostr.fill(' ');
		ostr << other.m_title << " | ";
		ostr.width(5);
		ostr.fill(' ');
		ostr << other.m_country << " | ";
		ostr.width(4);
		ostr.fill(' ');
		ostr << other.m_year << " | ";
		ostr.setf(ios::fixed);
		ostr.width(6);
		ostr.fill(' ');
		ostr.precision(2);
		ostr << other.m_price << " | ";
		ostr << other.m_description <<endl;
		return ostr;
	}
}
