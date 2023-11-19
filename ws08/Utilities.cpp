// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
/*/////////////////////////////////////////////////////////////////////////
       workshop 8
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 11/19/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <memory>
#include <utility>
#include "DataBase.h"
#include "Profile.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	DataBase<Profile> excludeRaw(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles) {
		DataBase<Profile> result;
		// TODO: Add your code here to build a collection of Profiles.
		//         The result should contain only profiles from `allProfiles`
		//         which are not in `bannedProfiles` using Raw Pointers.
        
        for (size_t i = 0; i < allProfiles.size(); ++i) {
            bool found = true;
            for (size_t j = 0; j < bannedProfiles.size()&&found; ++j) {
                if ((bannedProfiles[j].m_name.first_name == allProfiles[i].m_name.first_name)&& (bannedProfiles[j].m_name.last_name == allProfiles[i].m_name.last_name)&& (bannedProfiles[j].m_age == allProfiles[i].m_age)) {
                    found = false;
                }
            }
            if (found) {
                Profile* newProfile= new Profile(
                    allProfiles[i].m_name,
                    allProfiles[i].m_address,
                    allProfiles[i].m_age
                );
              
                try {
                    //std::unique_ptr<Profile> uniqueProfile(newProfile);
                    newProfile->validateAddress();
                    result += newProfile;

                }
                catch (const std::string& msg) {
                    delete newProfile;
                    throw ;
                }
               delete newProfile;
            }
               
        }
		return result;
	}
    DataBase<Profile> excludeSmart(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles) {
        DataBase<Profile> result;
        // TODO: Add your code here to build a collection of Profiles.
        //		   The result should contain only profiles from `allProfiles`
        //         which are not in `bannedProfiles` using Smart Pointers.
        for (size_t i = 0; i < allProfiles.size(); ++i) {
            bool found = true;
            for (size_t j = 0; j < bannedProfiles.size() && found; ++j) {
                if ((bannedProfiles[j].m_name.first_name == allProfiles[i].m_name.first_name) && (bannedProfiles[j].m_name.last_name == allProfiles[i].m_name.last_name) && (bannedProfiles[j].m_age == allProfiles[i].m_age)) {
                    found = false;
                }
            }
            if (found) {
                Profile* newProfile = new Profile(
                    allProfiles[i].m_name,
                    allProfiles[i].m_address,
                    allProfiles[i].m_age
                );
                std::unique_ptr<Profile> uniqueProfile(newProfile);
                uniqueProfile->validateAddress();
                result += std::move(uniqueProfile);

            }

        }
        return result;
    }
}