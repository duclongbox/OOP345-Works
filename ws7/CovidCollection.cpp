/*/////////////////////////////////////////////////////////////////////////
	   workshop 7
Full Name  : Long Duc Hoang
Student ID#: 122702228
Email      : dhoang19@myseneca.ca
Section    : ZAA
Date	   : 11/10/2023
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include "CovidCollection.h"
using namespace std;
namespace sdds {
	CovidCollection::CovidCollection(const char* namefile) {
		ifstream file(namefile);
		if (!file) {
			throw "can not open the file";
		}
		
		string line{};
		while (getline(file, line)) {
			Covid covid{};
			string country = line.substr(0, 25);
			size_t spacePos = country.find_last_not_of(" ");
			covid.m_country = country.substr(0, spacePos+1);
			line.erase(0, 25);

			string city = line.substr(0, 25);
			spacePos = city.find_last_not_of(" ");
			covid.m_city = city.substr(0, spacePos+1);
			line.erase(0, 25);

			string variant = line.substr(0, 25);
			spacePos = variant.find_last_not_of(" ");
			covid.m_variant = variant.substr(0, spacePos+1);
			line.erase(0, 25);

			string year = line.substr(0, 5);
			spacePos = year.find_last_not_of(" ");
			covid.m_year = stoi(year.substr(0, spacePos+1));
			if (covid.m_year < 0) {
				covid.m_year = 0;
			}
			line.erase(0, 5);

			string cases = line.substr(0, 5);
			spacePos = cases.find_last_not_of(" ");
			covid.m_cases = stoi(cases.substr(0, spacePos+1));
			line.erase(0, 5);

			string death = line.substr(0, 5);
			spacePos = death.find_last_not_of(" ");
			covid.m_deaths = stoi(death.substr(0, spacePos+1));
			collection.push_back(covid);
		}
		
	}
	void CovidCollection::display(std::ostream& out, const std::string& country) const {
		int totalCase{};
		int totalDeath{};
		int countryCase{};
		int countryDeath{};
		if (country != "ALL") {
			out << "Displaying information of country = " << country << endl;
		}
			for (const Covid& covid : collection) {
				if (country == "ALL") {
					out << covid << endl;
				}
				else if (covid.m_country == country) {
					out << covid << endl;
					countryCase += covid.m_cases;
					countryDeath += covid.m_deaths;
				}
				totalCase += covid.m_cases;
				totalDeath += covid.m_deaths;
			}
			if (country == "ALL") {
				out << "| ";
				out.width(21 + 15 + 20 + 6 + 1 + 13 + 8);
				out << "Total cases around the world: " +to_string(totalCase);
				out << " |"<<endl;

				out << "| ";
				out.width(21 + 15 + 20 + 6 + 1 + 13 + 8);
				out << "Total deaths around the world: " +to_string(totalDeath);
				out << " |" << endl;
			}
			else {
				out << "----------------------------------------------------------------------------------------" << endl;
				out << "| ";
				out.width(21 + 15 + 20 + 6 + 1 + 13 + 8);
				out << "Total cases in " + country + ": " + to_string(countryCase);
				out << " |" << endl;
				out << "| ";
				out.width(21 + 15 + 20 + 6 + 1 + 13 + 8);
				out << "Total deaths in " + country + ": " + to_string(countryDeath);
				out << " |" << endl;
				out << "| ";
				out.width(21 + 15 + 20 + 6 + 1 + 13 + 8);
				out <<  country + " has " + to_string(((double)countryCase / totalCase) * 100) + "% of global cases and "+ to_string(((double)countryDeath / totalDeath) * 100) +"% of global deaths";
				out << " |" << endl;
			}
	}
	void CovidCollection::sort(const std::string& field) {
		auto comparator = [field](const Covid& a, const Covid& b) {
			if (field == "country") {
				if (a.m_country != b.m_country) {
					return a.m_country < b.m_country;
				}
				else {
					return a.m_deaths < b.m_deaths;
				}
			}
			else if (field == "city") {
				if (a.m_city != b.m_city) {
					return a.m_city < b.m_city;
				}
				else {
					return a.m_deaths < b.m_deaths;
				}
			}
			else if (field == "year") {
				if (a.m_year != b.m_year) {
					return a.m_year < b.m_year;
				}
				else {
					return a.m_deaths < b.m_deaths;
				}
			}
			else if (field == "variant") {
				if (a.m_variant != b.m_variant) {
					return a.m_variant < b.m_variant;
				}
				else {
					return a.m_deaths < b.m_deaths;
				}
			}
			if (a.m_country != b.m_country) {
				return a.m_country < b.m_country;
			}
			else {
				return a.m_deaths < b.m_deaths;
			}
		};
		std::sort(collection.begin(), collection.end(), comparator);
	}
	bool CovidCollection::inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const {
		auto condition = [&](const Covid& covid) {
			return (variant == covid.m_variant) && (country == covid.m_country) && (covid.m_deaths > deaths);
		};
		auto result = find_if(collection.begin(), collection.end(), condition);
		return (result != collection.end());
	}
	std::list<Covid> CovidCollection::getListForDeaths(unsigned int deaths) const {
		auto condition = [&](const Covid& covid) {
			return (covid.m_deaths >= deaths);
		};
		list<Covid> m_list;
		copy_if(collection.begin(), collection.end(), inserter(m_list, m_list.begin()), condition);
		return m_list;
	}

	void CovidCollection::updateStatus() {
		transform(collection.begin(), collection.end(), collection.begin(), [](Covid& covid) {
			if (covid.m_deaths > 300) {
				covid.m_status = "EPIDEMIC";
			}
			else if (covid.m_deaths < 50) {
				covid.m_status = "EARLY";
			}
			else {
				covid.m_status = "MILD";
			}
			return covid;
		});
	}



	std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
		out << "| ";

		out.width(21);
		out.fill(' ');
		out << left << theCovid.m_country << " | ";


		out.width(15);
		out << left << theCovid.m_city << " | ";
		out.width(20);
		out << left << theCovid.m_variant << " | ";
		out.width(6);
		if (theCovid.m_year > 0) {
			out << right << theCovid.m_year;
		}
		else {
			out << " ";
		}
		out << " | ";
		out.width(4);
		out << right << theCovid.m_cases << " | ";
		out.width(3);
		out << right << theCovid.m_deaths << " | ";

		out << "| ";
		out.width(8);
		out << right << theCovid.m_status << " | ";
		return out;
	}
}