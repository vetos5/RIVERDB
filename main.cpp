
#include <iostream>
#include <fstream>
#include "country.h"

int main() {

    ifstream file("rivers.txt");

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int k;
    file >> k;

    Country* countries = new Country[k];

    for (int i = 0; i < k; ++i) {
        file >> countries[i];
    }

    file.close();

    for (int i = 0; i < k; ++i) {
        cout << countries[i];
    }

    Country* maxLengthCountry = nullptr;
    int maxLength = 0;

    for (int i = 0; i < k; ++i) {
        int currentTotalLength = countries[i].getTotalLength();
        if (currentTotalLength > maxLength) {
            maxLength = currentTotalLength;
            maxLengthCountry = &countries[i];
        }
    }

    if (maxLengthCountry) {
        cout << "Country with maximum total river length: " << maxLengthCountry->getName() << endl;
    }

    string name;
    cout << "Enter the name of the river: ";
    cin >> name;

    cout << "Countries where the river '" << name << "' flows:" << endl;
    for (int i = 0; i < k; ++i) {
        if (countries[i].hasRiver(name)) {
            cout << countries[i].getName() << endl;
           
        }
    }



    string name1;
    cout << "Enter the country name to find the longest river: ";
    cin >> name1;

    for (int i = 0; i < k; ++i) {
        if (countries[i].getName() == name1) {
            countries[i].printLongestRiver();
            break;
        }
    }

    delete[] countries;

    return 0;
}