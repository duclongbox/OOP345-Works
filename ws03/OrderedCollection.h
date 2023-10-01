//
//  OrderedCollection.h
//  ws03
//
//  Created by Long Hoàng on 2023-09-28.
//

#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H

#include <iostream>
#include "Collection.h"
namespace sdds {
    template<typename T>
    class OrderedCollection: public Collection< T, 72>{
    public:
        bool operator+=(const T& other) {
            if (this->size() >= this->capacity()) {
                return false;
            }
            if ( other < this->getSmallestItem()) {
                this->setSmallestItem(other);
            }
            if ( other > this->getLargestItem()) {
                this->setLargestItem(other);
            }
            this->operator[](this->size()) = other;
            this->incrSize();
             //bubble sort
            for (size_t i = 0; i < this->size() - 1; i++) {
                for (size_t j = 0; j < this->size() - i - 1; j++) {
                    if (this->operator[](j) > this->operator[](j + 1)) {
                        T temp = this->operator[](j);
                        this->operator[](j) = this->operator[](j + 1);
                        this->operator[](j + 1) = temp;
                    }
                }
            }
            
            //m_size++;
            return true;
        }
        
    };
}

#endif //!SDDS_ORDEREDCOLLECTION_H
