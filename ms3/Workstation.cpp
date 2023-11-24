#include <iostream>
#include <deque>
#include <string>
#include "Workstation.h"


using namespace std;
namespace sdds {
	std::deque<CustomerOrder> g_pending;
	std::deque<CustomerOrder> g_completed;
	std::deque<CustomerOrder> g_incomplete;
	Workstation::Workstation(const std::string& itenName) :Station(itenName){}
	void Workstation::fill(std::ostream& os) {
		if (!m_orders.empty()) {
			m_orders.front().fillItem(*this, os);
		}
	}
	bool Workstation::attemptToMoveOrder() {
		bool result = false;
		if (!m_orders.empty()) {
			if (m_orders.front().isItemFilled(getItemName())) {
				if (m_pNextStation) {
					*m_pNextStation+= move(m_orders.front());
				}
				else {
					if (!m_orders.front().isOrderFilled()) {
						g_incomplete.push_back(move(m_orders.front()));
					}
					else {
						g_completed.push_back(move(m_orders.front()));
					}
				}
				
				m_orders.pop_front();
				result = true;
			}
			else {
				if (this->getQuantity() <= 0) {
					if (m_pNextStation) {
						*m_pNextStation += move(m_orders.front());
					}
					else {
						g_incomplete.push_back(move(m_orders.front()));
					}
					result = true;
					m_orders.pop_front();
				}
			}
		}
		return result;
	}
	void Workstation::setNextStation(Workstation* station) {
		m_pNextStation = station;
	}
	Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}
	void Workstation::display(std::ostream& os) const {
		os << getItemName() << " --> ";
		if (m_pNextStation) {
			os << m_pNextStation->getItemName()<<endl;
		}
		else {
			os << "End of Line" << endl;
		}
	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
		m_orders.push_back(move(newOrder));
		return *this;
	}

}
