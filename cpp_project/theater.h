#include <iostream>
#include <string>

class Theater {
private:
    char* name = nullptr;
    int numberSeat = 0;
    int numberRow = 0;
    int occupiedSeats = 0;
    int occupiedRows = 0;

    static int min_number_seats;
    static int max_number_seats;
    static int number_rows;

public:

    friend std::istream& operator>>(std::istream& console, Theater& play);
    friend std::ostream& operator<<(std::ostream& console, const Theater& play);


    // default constructor
    Theater() {
        this->numberSeat = 0;
        this->numberRow = 0;
        this->name = nullptr;
    }

    // constructor with parameters
    Theater(const char* name, int numberSeat, int numberRow) {
        this->numberSeat = numberSeat;
        this->numberRow = numberRow;
        if (name != nullptr && strlen(name) < 15) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
        else {
            this->name = nullptr;
        }
    }

    // copy constructor
    Theater(const Theater& play) {
        this->numberSeat = play.numberSeat;
        this->numberRow = play.numberRow;
        if (play.name != nullptr) {
            this->name = new char[strlen(play.name) + 1];
            strcpy(this->name, play.name);
        }
        else {
            this->name = nullptr;
        }
    }

    // destructor
    ~Theater() {
        delete[] name;
    }

    // getters
    int getNumberSeat() {
        return this->numberSeat;
    }

    int getNumberRow() {
        return this->numberRow;
    }

    char* getName() {
        if (this->name != nullptr) {
            char* copy = new char[strlen(this->name) + 1];
            strcpy(copy, this->name);
            return copy;
        }
        else {
            return nullptr;
        }
    }
    int getNumberOccupiedSeats() {
        return occupiedSeats;
    }
    int getNumberOccupiedRows() {
        return occupiedRows;
    }

    // setters
    void setNumberSeat(int numberSeat) {
        if (numberSeat < Theater::max_number_seats || numberSeat > Theater::min_number_seats) {
            this->numberSeat = numberSeat;
        }
        else {
            throw std::exception("Invalid");
        }
    }

    void setNumberRow(int numberRow) {
        if (numberRow < Theater::number_rows) {
            this->numberRow = numberRow;
        }
        else {
            throw std::exception("Invalid");
        }
    }

    void setName(const char* name) {
        if (this->name != nullptr) {
            delete[] this->name;
        }
        if (name != nullptr && strlen(name) < 15) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
        else {
            this->name = nullptr;
        }
    }

    // overloading of operator =
    Theater& operator=(const Theater& play) {
        if (this != &play) {
            this->numberSeat = play.numberSeat;
            this->numberRow = play.numberRow;
            if (this->name != nullptr) {
                delete[] this->name;
            }
            if (play.name != nullptr) {
                this->name = new char[strlen(play.name) + 1];
                strcpy(this->name, play.name);
            }
            else {
                this->name = nullptr;
            }
        }
        return *this;
    }

    //++ operator-preincrement. It counts the number of seats that have been occupied
    Theater& operator++() {
        ++occupiedSeats;
        ++numberSeat;
        return*this;

    }



    //++ operator-postincrement. It counts the number of rows that have been occupied
    Theater operator++(int) {

        Theater copy = *this;
        ++occupiedRows;
        return copy;

    }


    //<<operator
    std::ostream& operator<<(std::ostream& console, const Theater& play) {


        if (play.name != nullptr) {

            console << "The play is " << play.name << '\n';
        }
        console << "The number of seats that have been occupied is: " << play.numberSeat << '\n';
        console << "The number of rows that have been occupied is: " << play.numberRow << '\n';

        return console;
    }

    //>> operator
    void operator>>(std::istream& console, Theater& play) {
        cout << endl << "Play's name is:";
        char buffer[100];
        console.getline(buffer, 100);
        console.clear();

        play.setName(buffer);

        cout << "The number of occupied seats: ";
        console >> play.numberSeat;

        cout << "The number of occupied rows: ";
        console >> play.numberRow;
        return console;


    }



};

// initializing static variables
int Theater::min_number_seats = 15;
int Theater::max_number_seats = 350;
int Theater::number_rows = 20;



int main() {
    Theater t;
    std::cin >> t;

    std::cout << t;
}