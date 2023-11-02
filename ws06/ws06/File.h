//
//  File.h
//  ws06
//
//  Created by Long Hoàng on 2023-10-29.
//

#ifndef SDDS_File_h
#define SDDS_File_h

#include <iostream>
#include "Resource.h"
#include "Flags.h"
namespace sdds{
    class File:public Resource{
        std::string m_contents{};
    public:
        File(const std::string& name, const std::string& content);
        void update_parent_path(const std::string&);
        NodeType type() const;
        std::string path() const;
        std::string name() const;
        int count() const;
        size_t size() const;
    };
}


#endif 
