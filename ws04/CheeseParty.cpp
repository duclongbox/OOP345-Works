#include <iostream>
#include "CheeseParty.h"

using namespace std;
namespace sdds{
	CheeseParty::CheeseParty() {};
	CheeseParty& CheeseParty::addCheese(const Cheese& other) {
		// looking for item already available
		bool found = false;
		for (size_t i = 0; i < m_numOfCheese; i++) {
			if (m_pcheeses[i] == &other) {
				found = true;
			}
		}
		if(!found) {
			const Cheese** copyArray = new const Cheese * [m_numOfCheese + 1];
			for (size_t i = 0; i < m_numOfCheese; i++) {
				copyArray[i] = m_pcheeses[i];
			}
			delete[] m_pcheeses;
			copyArray[m_numOfCheese] = &other;
			
			m_pcheeses = copyArray;
			m_numOfCheese++;
		}
		return *this;
	}

	CheeseParty& CheeseParty::removeCheese() {
		for (size_t i = 0; i < m_numOfCheese; i++) {
			if (m_pcheeses[i]->getWeight() == 0) {
				m_pcheeses[i] = nullptr;
			}
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const CheeseParty& party) {
		os << "--------------------------" << endl;
		os << "Cheese Party" << endl;
		os << "--------------------------" << endl;
		if (party.m_numOfCheese != 0) {
			for (size_t i=0; i < party.m_numOfCheese; i++) {
				if (party.m_pcheeses[i]!= nullptr) {
					os << *party.m_pcheeses[i] ;
				}
			}
		}
		else {
			os << "This party is just getting started!" << endl;
		}
		os << "--------------------------" << endl; 
		return os;
	}
	CheeseParty::~CheeseParty() {
		delete[] m_pcheeses;
	}
	//copy constructor
	CheeseParty::CheeseParty(const CheeseParty& other) {
		*this = other;
	}
	CheeseParty& CheeseParty::operator=(const CheeseParty& other) {
		if (this != &other) {
			delete[] m_pcheeses;
			m_numOfCheese = other.m_numOfCheese;
			m_pcheeses = new const Cheese * [m_numOfCheese];
			for (size_t i = 0; i < m_numOfCheese; i++) {
				m_pcheeses[i] = other.m_pcheeses[i];
			}
			
		}
		return *this;
	}
	//move constructor
	CheeseParty::CheeseParty( CheeseParty&& other) {
		*this = move(other);
	}
	CheeseParty& CheeseParty::operator=(CheeseParty&& other) {
		if (this != &other) {
			delete[] m_pcheeses;
			m_numOfCheese = other.m_numOfCheese;
			other.m_numOfCheese = 0;
			m_pcheeses = other.m_pcheeses;
			other.m_pcheeses = nullptr;
		}
		return *this;
	}
}