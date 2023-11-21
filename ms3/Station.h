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
#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>


namespace sdds {
	class Station {
		int m_stationID{};
		std::string m_name{};
		std::string m_desc{};
		size_t m_nextNum{};
		size_t m_noOfItem{};
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station(const std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};

}


#endif // !SDDS_STATION_H
