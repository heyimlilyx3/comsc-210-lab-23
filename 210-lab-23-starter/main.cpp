#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    bool end = false;
    list<Goat> trip;
    while(!end) {
        int choice = main_menu();
        switch(choice) {
            case 1:
                add_goat(trip, names, colors);
                break;
            case 2:
                // delete_goat(trip);
                break;
            case 3:
                // display_trip(trip);
                break;
            case 4:
                end = true;
                break;
        }
    }


    return 0;
}

int main_menu() {
    system("cls");
    int choice;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if(choice < 1 || choice > 4) {
        cout << "Invalid choice. Please try again." << endl;
        return main_menu();
    }

    return choice;
}

void add_goat(list<Goat> &trip, string names[], string colors[]) {
    string name = names[rand() % SZ_NAMES];
    int age = rand() % (MAX_AGE + 1);
    string color = colors[rand() % SZ_COLORS];
    trip.push_back(Goat(name, age, color));
    // cout << "Added a goat: " << name << ", Age: " << age << ", Color: " << color << endl;
}

int select_goat(list<Goat> trip) {
    for(int i = 0; i < trip.size(); i++) {
        cout << "[" << i + 1 << "] " << trip.front().get_name()  << " (" << trip.front().get_age() << ", " << trip.front().get_color() << ")" << endl;
        trip.pop_front();
    }
}