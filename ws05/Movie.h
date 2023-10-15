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
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>

namespace sdds {
	class Movie {
		std::string m_title{};
		size_t m_year{};
		std::string m_desc{};
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker.operator()(m_title);
			spellChecker.operator()(m_desc);

		}
		friend std::ostream& operator<<(std::ostream& ostr, const Movie& other);
	};
}

#endif // !SDDS_MOVIE_H
