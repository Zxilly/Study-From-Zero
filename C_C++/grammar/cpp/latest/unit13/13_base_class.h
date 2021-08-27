// tabtenn0.h -- a table-tennis base class
#ifndef TABTENN0_H_
#define TABTENN0_H_

#include <string>

using std::string;

// simple base class
class TableTennisPlayer {
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    explicit TableTennisPlayer(string fn, string ln, bool ht = false);

    void Name() const;

    bool HasTable() const { return hasTable; };

    void ResetTable(bool v) { hasTable = v; };
};

class RatedPlayer : public TableTennisPlayer { // https://www.runoob.com/cplusplus/cpp-inheritance.html
    //public 标记继承来的东西的保护等级
private:
    unsigned int rating;
public:
    explicit RatedPlayer(unsigned int r = 0, const string &fn = "none",
                         const string &ln = "none", bool ht = false);

    RatedPlayer(unsigned int r, const TableTennisPlayer &tp);

    unsigned int Rating() const { return rating; }

    void ResetRating(unsigned int r) { rating = r; }
};

#endif
