#ifndef UTILITIES_H
#define UTILITIES_H
#include <utility>
#include <memory>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
namespace
{
    string kHpName = "Health";
    string kHpAbbr = "HP";
    string kAtkName = "Attack";
    string kAtkAbbr = "ATK";
    string kDefName = "Defense";
    string kDefAbbr = "DEF";
    string kMovName = "Move";
    string kMovAbbr = "Mov";
    string kJmpName = "Jump";
    string kJmpAbbr = "JMP";
}

class Unit;
class Stat;
class Panel;
class Board;
class Job;
/*
typedef shared_ptr<Unit> UnitPtr;
typedef shared_ptr<Stat> StatPtr;
typedef shared_ptr<Panel> PanelPtr;
typedef shared_ptr<Board> BoardPtr;
*/
typedef pair<int,int> Point;

class Utilities
{
public:
private:
    Utilities();
};
#endif // UTILITIES_H
