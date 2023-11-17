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
#include "Utilities.h"

using namespace std;
namespace sdds {
	char Utilities::m_delimiter{};
	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const {
		return m_widthField;

	}
	string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		string token{};
		more = false;
		string remaining = str;
		size_t found = remaining.find(m_delimiter,next_pos);
		if (found == next_pos) {

			throw "delimeter at the start position";
		}
		remaining.erase(0, next_pos);
		found = remaining.find(m_delimiter);
		
		
		if (found != string::npos) {
			size_t pos1 = remaining.find_first_not_of(" ");
			size_t pos2 = remaining.find_last_not_of(" ", found - 1);
			if (pos2 != string::npos) {
				
				token = remaining.substr(pos1, pos2 - pos1 + 1);
			}
			else {
				 token = remaining.substr(pos1, found - pos1);
			}
			more = true;
			next_pos += (found + 1);
		}
		else {
			size_t pos1 = remaining.find_first_not_of(" ");
			token = remaining.substr(pos1);
			more = false;
		}
		
		if(token.length()==0){
			more = false;
		}
		if (token.length() > m_widthField) {
			m_widthField = token.length();
		}
		return token;
	}
	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter() {
		return m_delimiter;
	}


}