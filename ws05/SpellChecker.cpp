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
#include <fstream>
#include <string>
#include "SpellChecker.h"

using namespace std;
namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		ifstream file(filename);
		// throw an exception if file doesnt exist
		if (!file) {
			throw "Bad file name!";
		}
		else {
			string line;

			for (size_t i = 0; i < 6; i++) {
				getline(file, line);
				size_t firstPos = line.find_first_of(' ');
				m_badWords[i] = line.substr(0, firstPos);
				line.erase(0, firstPos);
				size_t secPos = line.find_first_not_of(' ');
				m_goodWords[i] = line.substr(secPos);
			}
		}
		
	}
	// search bad words and replace them
	void SpellChecker::operator()(std::string& text) {
		for (size_t i = 0; i < 6; i++) {
			size_t pos = 0;
			
			while ( (pos = text.find(m_badWords[i])) != string::npos ) {
				text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
				m_numBadWords[i]++;
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const {
		out << "Spellchecker Statistics" << endl;
		for (size_t i = 0; i < 6; i++) {
			out.setf(ios::right);
			out.width(15);
			out.fill(' ');
			out << m_badWords[i] << ": " << m_numBadWords[i] << " replacements" << endl;
		}
	}


}

