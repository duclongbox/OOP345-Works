/*/////////////////////////////////////////////////////////////////////////
	   workshop 7
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 11/10/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H
#include <iostream>
#include <list>
#include <vector>
namespace sdds {
	struct Covid {
		std::string m_country{};
		std::string m_city{};
		std::string m_variant{};
		int m_year{};
		unsigned int m_cases{};
		unsigned int m_deaths{};
		std::string m_status{ "General" };

	};

	class CovidCollection {
		std::vector<Covid> collection{};
	public:
		CovidCollection(const char* namefile);
		/*void display(std::ostream& out) const;*/
		void display(std::ostream& out, const std::string& country  = "ALL" ) const;
		void sort(const std::string& field = "country");
		bool inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const;
		std::list<Covid> getListForDeaths(unsigned int deaths) const ;
		void updateStatus();

	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);

}


#endif // !SDDS_COVIDCOLLECTION_H

