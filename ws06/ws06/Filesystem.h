//
//  Filesystem.h
//  ws06
//
//  Created by Long Hoàng on 2023-10-30.
//

#ifndef sdds_Filesystem_h
#define sdds_Filesystem_h
#include <iostream>
#include "Directory.h"
#include "Resource.h"
#include "File.h"


namespace sdds{
class Filesystem{
    Directory* m_root{};
    Directory* m_current{};
public:
    Filesystem(const std::string& fileName, const std::string& path={});
    Filesystem(const Filesystem& other)=delete;
    Filesystem& operator=(const Filesystem& other)=delete;
    Filesystem(Filesystem&& other);
    Filesystem& operator=(Filesystem&& other);
    Filesystem& operator+=(Resource*);
    Directory* change_directory(const std::string& name={});
    Directory* get_current_directory() const;
    ~Filesystem();
};



}




#endif
