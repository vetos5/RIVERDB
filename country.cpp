#include "country.h"

Country::Country() {
    name = "-";
    int riverCount = 0;
}

Country::Country(const string& c, int co) {
    name = c;
    riverCount = co;
    for (int i = 0; i < co; ++i) {
        cin >> rivers[i];
    }
}

istream& operator>>(istream& is, Country& c) {
    is >> c.name >> c.riverCount;

    for (int i = 0; i < c.riverCount; ++i) {
        is >> c.rivers[i];
    }
    return is;
}

ostream& operator<<(ostream& os, const Country& c) {
    os << "Country: " << c.name << ", Number of rivers: " << c.riverCount << endl;
    for (int i = 0; i < c.riverCount; ++i) {
        os << "  " << c.rivers[i] << endl;
    }
    return os;
}

const string& Country::getName() {
    return name;
}
bool Country::hasRiver(const string& r) {
    for (int i = 0; i < riverCount; ++i) {
        if (rivers[i].getName() == r) {
            return true;
        }
    }
    return false;
}

void Country::printLongestRiver() {
    River* longestRiver = &rivers[0];

    for (int i = 1; i < riverCount; ++i) {
        if (rivers[i] > *longestRiver) {
            longestRiver = &rivers[i];
        }
    }

    cout << "Longest river in " << name << ": " << *longestRiver << endl;
}


int Country::getTotalLength() {
    int totalLength = 0;
    for (int i = 0; i < riverCount; ++i) {
        totalLength += rivers[i].getLength();
    }
    return totalLength;
}



