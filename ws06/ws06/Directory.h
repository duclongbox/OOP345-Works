//
//  Directory.h
//  ws06
//
//  Created by Long Hoàng on 2023-10-29.
//

#ifndef SDDS_Directory_h
#define SDDS_Directory_h
#include <iostream>
#include "Resource.h"
namespace sdds{
    class Directory:public Resource{
        std::vector<Resource*> m_contents{};
    public:
        Directory()=default;
        Directory(const std::string& name);
        void update_parent_path(const std::string&);
        NodeType type() const;
        std::string path() const;
        std::string name() const;
        int count() const;
        size_t size() const;
        Directory& operator+=(Resource*);
        Resource* find(const std::string&, const std::vector<OpFlags>& flagg={});
        ~Directory();
        Directory(const Directory&) = delete;
        Directory& operator=(const Directory&) = delete;
        Directory(Directory&&) = delete;
        Directory& operator=(Directory&&) = delete;
        void remove(const std::string&, const std::vector<OpFlags>& flagg={});
        void display(std::ostream&, const std::vector<FormatFlags>& flagg={}) const;
        };

}


#endif
