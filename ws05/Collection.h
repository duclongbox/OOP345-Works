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
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>
namespace sdds {
	template <typename T>
	class Collection {
		std::string m_name{};
		T* m_collection{};
		size_t m_size{};
		void (*m_observer)(const Collection<T>&, const T&) {};
	public:
		Collection(const std::string& name) {
			m_name = name;
		}
		Collection(const Collection& other)=delete;
		Collection& operator=(const Collection& other) = delete;
		~Collection() {
			delete[] m_collection;
		}
		const std::string& name() const {
			return m_name;
		}
		size_t size() const {
			return m_size;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			m_observer = observer;
		}
		Collection<T>& operator+=(const T& item) {
			bool found = false;
			for (size_t i = 0; i < m_size; i++) {
				if (m_collection[i].title() == item.title()) {
					found = true;
				}
			}
			if (!found) {
				//resize and add item
				T* temp = new T[m_size + 1];
				for (size_t i = 0; i < m_size; i++) {
					temp[i] = m_collection[i];
				}
				
				temp[m_size] = item;
				m_size++;
				delete[] m_collection;
				m_collection = temp;
				if (m_observer) {
					m_observer(*this, item);
				}
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			if (idx >= m_size) {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
			}
			return m_collection[idx];
		}
		T* operator[](const std::string& title) const {
			for (size_t i = 0; i < m_size; i++) {
				if(m_collection[i].title() == title){
					return &m_collection[i];
				}
			}
			return nullptr;
		}
		friend std::ostream& operator<<(std::ostream& ostr, const Collection& other) {
			for (size_t i = 0; i < other.size(); i++) {
				ostr << other[i];
			}
			return ostr;
		}
	};
}


#endif // !SDDS_COLLECTION_H
