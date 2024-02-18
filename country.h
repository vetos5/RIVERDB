
#include <iostream>
#include <string>
#include "river.h"

int const MAX_RIVERS = 10;

class Country {
private:
    string name;
    River rivers[MAX_RIVERS];
    int riverCount;

public:
    Country();
    Country(const string& c, int co);

    friend istream& operator>>(istream& is, Country& c);
    friend ostream& operator<<(ostream& os, const Country& c);
    bool hasRiver(const string& name);
    void printLongestRiver();

    const string& getName();
    int getTotalLength();

    
};

