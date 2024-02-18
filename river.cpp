#include "river.h"

River::River() {
    name = "-";
    length = 0;
}

River::River(const string& n, int l) {
    this->name = name;
    this->length = length;
}

istream& operator>>(istream& is, River& r) {
    is >> r.name >> r.length;
    return is;
}

ostream& operator<<(ostream& os, const River& r) {
    os << r.name << "\t" << r.length;
    return os;
}

bool River::operator>(const River& o) {
    return length > o.length;
}

int River::getLength() {
    return length;
}
const string& River::getName() {
    return name;
}
