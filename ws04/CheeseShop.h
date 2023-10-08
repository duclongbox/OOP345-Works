#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H
#include <iostream>
#include "Cheese.h"
namespace sdds {
	class CheeseShop {
		std::string m_shopName{};
		const Cheese** cheeses{};
		size_t m_size{};
	

	public:
		CheeseShop(const std::string& name = "No Name");
		CheeseShop& addCheese(const Cheese& other);
		//rules of 5
		CheeseShop(const CheeseShop& other);
		CheeseShop& operator=(const CheeseShop& other);
		CheeseShop(CheeseShop&& other);
		CheeseShop& operator=( CheeseShop&& other);
		~CheeseShop();
		friend std::ostream& operator<<(std::ostream& os, const CheeseShop& shop);
		
	};

}

#endif // !SDDS_CHEESESHOP_H
