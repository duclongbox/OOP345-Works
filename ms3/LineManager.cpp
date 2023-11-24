#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "Workstation.h"
#include "LineManager.h"
#include "Utilities.h"

using namespace std;
namespace sdds {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
		ifstream opFile(file);
		string line{};
		if (opFile) {
			while (!opFile.eof()) {
				Utilities util{};
				size_t next_pos = 0;
				bool more = true;
				getline(opFile, line);
				string currentName = util.extractToken(line, next_pos, more);
				string nextName{};
				if (more) {
					 nextName = util.extractToken(line, next_pos, more);
				}
				else {
					 nextName = "";
				}
				auto currentStation = find_if(stations.begin(), stations.end(), [&currentName](Workstation* station) {
					return station->getItemName() == currentName;
					});
				if (!nextName.empty()) {
					auto nextStation = std::find_if(stations.begin(), stations.end(), [&nextName](Workstation* station) {
						return station->getItemName() == nextName;
						});
					if (currentStation != stations.end() && nextStation != stations.end()) {
						(*currentStation)->setNextStation(*nextStation);
						m_activeLine.push_back(*currentStation);
					}
					else {
						throw "Not found";
					}
				}
				else {
					if (currentStation != stations.end()) {
						m_activeLine.push_back(*currentStation);
					}
				}

			}
			auto firstStation = find_if(m_activeLine.begin(), m_activeLine.end(),
				[this](const Workstation* station) {
					// Check if the station's next station is not found in the entire line
					return count_if(m_activeLine.begin(), m_activeLine.end(),
					[station](const Workstation* otherStation) {
							if (otherStation->getNextStation()) {
								return station->getItemName() == otherStation->getNextStation()->getItemName();
							}
							else {
								return false;
							}
					}) == 0;
				});
			if (firstStation != m_activeLine.end()) {
				m_firstStation = *firstStation;
			}
			m_cntCustomerOrder = g_pending.size();
		}
		else {
			throw "can not open the file";
		}
	}
	void LineManager::reorderStations() {
		vector<Workstation*> newLine{};
		Workstation* currentStation = m_firstStation;
		while (currentStation!=nullptr) {
			newLine.push_back(currentStation);
			currentStation = currentStation->getNextStation();
		}
		m_activeLine = newLine;
	}
	bool LineManager::run(std::ostream& os) {
		static size_t count = 1;
		os << "Line Manager Iteration: " << count++ << endl;
		if (!g_pending.empty()) {
			*m_firstStation += move(g_pending.front());
			g_pending.pop_front();
		}
		for (Workstation* station : m_activeLine) {
			station->fill(os);
		}
		for (Workstation* station : m_activeLine) {
			station->attemptToMoveOrder();
		}
		//return g_pending.empty() && g_completed.empty();
		return m_cntCustomerOrder == (g_completed.size() + g_incomplete.size());
	}
	void LineManager::display(std::ostream& os) const {
		for (Workstation* station : m_activeLine) {
			station->display(os);
		}
	}


}

