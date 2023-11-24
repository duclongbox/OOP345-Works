/*/////////////////////////////////////////////////////////////////////////
	   milestone 2
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 11/16/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "CustomerOrder.h"
#include "Utilities.h"
using namespace std;
namespace sdds {
	size_t CustomerOrder::m_widthField = 0;
	CustomerOrder::CustomerOrder(const std::string& str) {
		Utilities util{};
		size_t next_pos = 0;
		bool more = true;
		m_name = util.extractToken(str, next_pos, more);
		m_product = util.extractToken(str, next_pos, more);
		int count = 0;
		/*m_lstItem= new Item * [10];*/
		size_t new_pos = next_pos;
		bool newMore = more;
		while (newMore) {
			string token = util.extractToken(str, new_pos, newMore);
			count++;
		}
		m_lstItem = new Item * [count];
		while (more) {
			m_lstItem[m_cntItem] = new Item(util.extractToken(str, next_pos, more));
			m_cntItem++;
		}
		if (m_widthField < util.getFieldWidth()) {
			m_widthField = util.getFieldWidth();
		}
	}
	CustomerOrder::CustomerOrder(const CustomerOrder& other) {
		throw "Copy constructor is not allowed for CustomerOrder";
	}
	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		*this = std::move(src);
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
		if (this != &src) {
			m_name = move(src.m_name);
			m_product = move(src.m_product);
			if (m_lstItem) {
				for (size_t i = 0; i < m_cntItem; i++) {
					delete m_lstItem[i];
				}
				delete[] m_lstItem;
			}
			m_lstItem = src.m_lstItem;
			m_cntItem = src.m_cntItem;
			src.m_cntItem = 0;
			src.m_lstItem = nullptr;
			
		}
		return *this;
	}
	CustomerOrder::~CustomerOrder(){
		for (size_t i = 0; i < m_cntItem; ++i) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}
	bool CustomerOrder::isOrderFilled() const {
		bool result = true;
		for (size_t i = 0; i < m_cntItem; ++i) {
			if (!(m_lstItem[i]->m_isFilled)) {
				result = false;
			}
		}
		return result;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const {	
		for (auto i = 0u; i < m_cntItem; ++i) {
			if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled)
				return false;
		}

		return true;
	}

	void CustomerOrder::fillItem(Station & station, std::ostream & os) {
		bool done = false;
		for (size_t i = 0; i < m_cntItem&& !done; i++) {
			if (m_lstItem[i]->m_itemName == station.getItemName()&& (!m_lstItem[i]->m_isFilled)) {
					if (station.getQuantity() > 0) {
						station.updateQuantity();
						m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
						m_lstItem[i]->m_isFilled = true;
						
						os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
						done = true;
					}
					else {
						os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
					}
			}
		}
		
	}
	
	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << endl;
		for (size_t i = 0; i < m_cntItem; i++) {
			os << "[";
			os.width(6);
			os.fill('0');
			os << right << m_lstItem[i]->m_serialNumber << "] ";
			os.width(m_widthField);
			os.fill(' ');
			os << left<< m_lstItem[i]->m_itemName << " - ";
			if (m_lstItem[i]->m_isFilled) {
				os << "FILLED";
			}
			else {
				os << "TO BE FILLED";
			}
			os << endl;
		}
	}


}