#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H

#include <iostream>
#include "Cheese.h"

namespace sdds {
	class CheeseParty {
		const Cheese** m_pcheeses{};
		size_t m_numOfCheese{};
	public:
		CheeseParty();
		CheeseParty& addCheese(const Cheese& other);
		CheeseParty& removeCheese();
		friend std::ostream& operator<<(std::ostream& os, const CheeseParty& party);
		//rules of 5
		CheeseParty(const CheeseParty& other);
		CheeseParty& operator=(const CheeseParty& other);
		CheeseParty(CheeseParty&& other);
		CheeseParty& operator=(CheeseParty&& other);

		~CheeseParty();
	};
}


#endif // !SDDS_CHEESEPARTY_H
