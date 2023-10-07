//
//  Cheese.h
//  ws04
//
//  Created by Long Hoàng on 2023-10-02.
//

#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H

#include <iostream>


namespace sdds{
    class Cheese{
        std::string m_name{"Nac"};
        size_t m_weight{};
        double m_price{};
        std::string m_features{};
    public:
        Cheese()=default;
        Cheese(const std::string& str);
        Cheese slice(size_t weight);
        std::string getName() const;
        int getWeight() const;
        double getPrice() const;
        std::string getFeatures() const;
        friend std::ostream& operator<<(std::ostream& os, const Cheese& cheese);
    };
}

#endif // !SDDS_CHEESE_H
