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
    const string kHpName = "Health";
    const string kHpAbbr = "HP";
    const string kAtkName = "Attack";
    const string kAtkAbbr = "ATK";
    const string kDefName = "Defense";
    const string kDefAbbr = "DEF";
    const string kMovName = "Move";
    const string kMovAbbr = "Mov";
    const string kJmpName = "Jump";
    const string kJmpAbbr = "JMP";
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
