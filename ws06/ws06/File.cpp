//
//  File.cpp
//  ws06
//
//  Created by Long Hoàng on 2023-10-29.
//
#include <iostream>
#include "File.h"
#include "Flags.h"
using namespace std;
namespace sdds {
    File::File(const std::string& name, const std::string& content){
        m_name = name;
        m_contents = content;
    }
    void File::update_parent_path(const std::string& crPath){
        m_parent_path = crPath;
            
    }
    NodeType File::type() const{
        return sdds::NodeType::FILE;
    }
std::string File::path() const{
    return m_parent_path + m_name;
}
std::string File::name() const{
    return m_name;
}
    int File::count() const {
        return -1;
    }

    size_t File::size() const {
        return m_contents.size();
    }
}
