#ifndef UTILITIES_H
#define UTILITIES_H
#include <utility>
#include <memory>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
namespace
{
    std::string kHpName = "Health";
    std::string kHpAbbr = "HP";
    std::string kAtkName = "Attack";
    std::string kAtkAbbr = "ATK";
    std::string kDefName = "Defense";
    std::string kDefAbbr = "DEF";
    std::string kMovName = "Move";
    std::string kMovAbbr = "Mov";
    std::string kJmpName = "Jump";
    std::string kJmpAbbr = "JMP";
}

class Unit;
class Stat;
class Panel;
class Board;
class Job;
/*
typedef std::shared_ptr<Unit> UnitPtr;
typedef std::shared_ptr<Stat> StatPtr;
typedef std::shared_ptr<Panel> PanelPtr;
typedef std::shared_ptr<Board> BoardPtr;
*/
typedef std::pair<int,int> Point;

class Utilities
{
public:
private:
    Utilities();
};
#endif // UTILITIES_H
