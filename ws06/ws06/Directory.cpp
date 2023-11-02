//
//  Directory.cpp
//  ws06
//
//  Created by Long Hoàng on 2023-10-29.
//

#include <iostream>
#include <iomanip>
#include <exception>
#include <string>
#include "Directory.h"
#include "Flags.h"

using namespace std;
namespace  sdds {
    Directory::Directory(const std::string& name){
        m_name = name ;
    }
    void Directory::update_parent_path(const std::string& crpath){
        m_parent_path = crpath;
        for (size_t i =0; i < m_contents.size();i++){
            m_contents[i]->update_parent_path(path());
        }
    }
    NodeType Directory::type() const{
        return sdds::NodeType::DIR;
    }
    std::string Directory::path() const{
        return m_parent_path+m_name;
    }
    std::string Directory::name() const{
        return m_name;
    }
    int Directory::count() const{
        return int(m_contents.size());
    }
    size_t Directory::size()const{
        size_t total=0u;
        for(size_t i =0; i< m_contents.size();i++){
            total += m_contents[i]->size();
        }
        return total;
    }
    Directory& Directory::operator+=(Resource* other){
        for (size_t i =0; i<m_contents.size();i++){
            if(m_contents[i]->name() == other->name()){
                throw exception();
            }
        }
        m_contents.push_back(other);
        
//        m_contents[m_contents.size()-1]->update_parent_path( m_contents[m_contents.size()-1]->path());
        other-> update_parent_path(path());
        
        return *this;
    }
    Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& flagg){
        for (size_t i=0; i< m_contents.size();i++) {
                // Check if the RECURSIVE flag is set in the flagg vector
                bool isRecursive = false;
                for(OpFlags flags:flagg){
                    if(flags == sdds::OpFlags::RECURSIVE){
                        isRecursive = true;
                    }
                }
                if (m_contents[i]->name() == name) {
                    return m_contents[i];
                }
                if (isRecursive && m_contents[i]->type() == sdds::NodeType::DIR) {
                    Resource* find =dynamic_cast<Directory*>(m_contents[i])->find(name, flagg);
                    if(find){
                        return find;
                    }
                }
                
        }
        return nullptr;
    }
    Directory::~Directory(){
        for(size_t i=0;i<m_contents.size();i++){
            delete m_contents[i];
        }
    }
void Directory::remove(const std::string& name, const std::vector<OpFlags>& flagg){
    bool found = false;
    for (size_t i=0; i< m_contents.size() && found ;i++) {
            // Check if the RECURSIVE flag is set in the flagg vector
            bool isRecursive = false;
            for(OpFlags flags:flagg){
                if(flags == sdds::OpFlags::RECURSIVE){
                    isRecursive = true;
                }
            }
            if (isRecursive && m_contents[i]->type() == sdds::NodeType::DIR) {
                if (dynamic_cast<Directory*>(m_contents[i])->find(name,flagg)) {
                    m_contents[i] = nullptr;
                    delete m_contents[i];
                     //m_contents.erase(m_contents.begin() + i);
                    found = true;
                }
                else{
                    throw "NAME does not exist in DIRECTORY_NAME";
                }
            }
            else if (m_contents[i]->type() != sdds::NodeType::DIR){
                throw invalid_argument("NAME is a directory. Pass the recursive flag to delete directories.");
            }
        }
}
void Directory::display(std::ostream& os, const std::vector<FormatFlags>& flagg) const{
    bool isLong = false;
    for(FormatFlags flags:flagg){
        if(flags == sdds::FormatFlags::LONG){
            isLong = true;
        }
    }
    os << "Total size: " << size() << " bytes"<< endl;
    for(size_t i=0; i < m_contents.size();i++){
        if(isLong){
            if(m_contents[i]->type() == sdds::NodeType::DIR){
                os<< "D" <<" | ";
                os.setf(ios::left);
                os.width(15);
                os.fill(' ');
                os << m_contents[i]->name();
                os <<" | ";
                os.unsetf(ios::left);
                
                os.setf(ios::right);
                os.width(2);
                os.fill(' ');
                os << m_contents[i]->count();
                os << " | ";
                
                os.setf(ios::right);
                os.width(15);
                os.fill(' ');
                os << to_string(m_contents[i]->size())+" bytes" << " |"<<endl;
                os.unsetf(ios::right);

            }
            else{
                os<< "F" <<" | ";
                os.setf(ios::left);
                os.width(15);
                os.fill(' ');
                os << m_contents[i]->name();
                
                os <<" | ";
                os << "  ";
                os << " | ";
                
                os.setf(ios::right);
                os.width(15);
                os.fill(' ');
                os << to_string(m_contents[i]->size())+" bytes" << " |"<<endl;
                os.unsetf(ios::right);

            }
        }
        else{
            if(m_contents[i]->type() == sdds::NodeType::DIR){
                os<< "D" <<" | ";
                os.setf(ios::left);
                os.width(15);
                os.fill(' ');
                os << m_contents[i]->name();
                os <<" | " <<endl;
            }
            else{
                os<< "F" <<" | ";
                os.setf(ios::left);
                os.width(15);
                os.fill(' ');
                os << m_contents[i]->name();
                os <<" |"<<endl;
            }
        }
    }
}
}
