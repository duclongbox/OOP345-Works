
#include <iostream>
#include "CheeseShop.h"

using namespace std;
namespace sdds {
	CheeseShop::CheeseShop(const string& name) : m_shopName(name) {
	}
	CheeseShop& CheeseShop::addCheese(const Cheese& other) {
		const Cheese** copyArray = new const Cheese * [m_size + 1];

		for (size_t i = 0; i < m_size; i++) {
			copyArray[i] = cheeses[i];
		}
		delete[] cheeses;
		copyArray[m_size] = new Cheese(other); // shallow copy
		m_size++;
		cheeses = copyArray;

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const CheeseShop& shop) {
		os << "--------------------------" << endl;
		os << shop.m_shopName << endl;
		os << "--------------------------" << endl;
		if (shop.m_size != 0) {
			for (size_t i = 0; i < shop.m_size; i++) {
				os << *shop.cheeses[i];
			}
		}
		else {
			os << "This shop is out of cheese!" << endl;
		}
		os << "--------------------------" << endl;
		return os;
	}
	//destructor
	CheeseShop::~CheeseShop() {
		for (size_t i = 0; i < m_size; i++) {
			delete cheeses[i];
		}
		delete[] cheeses;
	}
	//copy constructor
	CheeseShop::CheeseShop(const CheeseShop& other) {
		*this = other;
	}
	CheeseShop& CheeseShop::operator=(const CheeseShop& other) {
		if (this != &other) {
			for (size_t i = 0; i < m_size; i++) {
				delete cheeses[i];
			}
			delete[] cheeses;
			m_shopName = other.m_shopName;
			m_size = other.m_size;
			cheeses = new const Cheese * [m_size];
			for (size_t i = 0; i < m_size; i++) {
				cheeses[i] = new Cheese(*other.cheeses[i]);
			}

		}
		return *this;
	}


	//move constructor
	CheeseShop::CheeseShop(CheeseShop&& other) {
		*this = move(other);
	}
	CheeseShop& CheeseShop::operator=(CheeseShop&& other) {
		if (this != &other) {
			for (size_t i = 0; i < m_size; i++) {
				delete cheeses[i];
			}
			delete[] cheeses;
			m_shopName = move(other.m_shopName);
			m_size = other.m_size;
			other.m_size = 0;
			cheeses = other.cheeses;
			other.cheeses = nullptr;

		}
		return *this;
	}
}