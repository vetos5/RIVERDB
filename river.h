#include <iostream>
#include <string>

using namespace std;

class River {
private:
    string name;
    int length;

public:
    River();
    River(const string& n, int l);

    friend istream& operator>>(istream& is, River& r);
    friend ostream& operator<<(ostream& os, const River& r);
    bool operator>(const River& other);

    int getLength();
    const string& getName();
};
