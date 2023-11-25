#pragma once

#include <iostream>
#include <string>
using namespace std;

class Theater {
private:
    char* name = nullptr; //dynamically defined array
    int numberSeat = 0; //statically defined array of numbers
    int numberRow = 0;
    int occupiedSeats = 0;
    int* occupiedRows = nullptr; //dynamically defined array of numbers

    static int min_number_seats;
    static int max_number_seats;
   

public:


    // default constructor
    Theater() {
        this->numberSeat = 0;
        this->numberRow = 0;
        this->name = nullptr;
        this->occupiedSeats = 0;
        this->occupiedRows = nullptr;
    }

    //1st constructor with parameters
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

    //2nd constructor with parameters
    Theater(const char* name, int occupiedSeats,int numberRow, int* occupiedRows) {
        if (occupiedRows != nullptr) {
            this->occupiedRows = new int[numberRow];
            for (int i = 0; i < numberRow; i++) {
                this->occupiedRows[i] = occupiedRows[i];
            }
        }
        else {
            this->occupiedRows=nullptr;
        }

        this->occupiedSeats= occupiedSeats;
        this -> numberRow = numberRow;

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
        this->occupiedSeats = play.occupiedSeats;
        this->occupiedRows = play.occupiedRows;
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
        if (occupiedRows != nullptr) {
            delete[] this->occupiedRows;
        }
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


    int* getOccupiedRows()
    {
        int* copy;
        if (this->occupiedRows != nullptr)
        {
            copy = new int[this->numberRow];
            for (int i = 0; i < this->numberRow; i++)
            {
                copy[i] = this->occupiedRows[i];
            }
        }
        else
        {
            copy = nullptr;
        }

        return copy;
    }
    //setters
    void setNumberSeat(int numberSeat) {
        if (numberSeat < Theater::max_number_seats || numberSeat > Theater::min_number_seats) {
            this->numberSeat = numberSeat;
        }
        else {
            throw exception("Invalid");
        }
    }

    void setNumberRow(int numberRow) {
        if (numberRow >15) {
            this->numberRow = numberRow;
        }
        else {
            throw exception("Invalid");
        }
    }


    void setOccupiedRows(int* occupiedRows)
    {
        if (this->occupiedRows != nullptr)
        {
            delete[] this->occupiedRows;
        }

        if (occupiedRows != nullptr)
        {
            this->occupiedRows = new int[this->numberRow];
            for (int i = 0; i < this->numberRow; i++)
            {
                this->occupiedRows[i] = occupiedRows[i];
            }
        }
        else
        {
            this->occupiedRows = nullptr;
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

    static int getMinNumberSeats() {
        return min_number_seats;
    }


    void setMinNumberSeats(int min_number_seats)
    {
        Theater::min_number_seats = min_number_seats;
    }


    static int getMaxNumberSeats() {
        return max_number_seats;
    }


    void setMaxNumberSeats(int max_number_seats)
    {
        Theater::max_number_seats = max_number_seats;
    }

  


    //a method that prints the details
    void showCapacity()
    {

        if (this->name != nullptr)
        {


            cout << "PLay's name is " << this->name<<'\n';

        }
        cout << "The number of seats is " << this->numberSeat << " and the number of rows is " << this->numberRow<<"\n";

    }


    void showAvailability()
    {

        if (this->name != nullptr)
        {


            cout << "For the play " << this->name<<"\n";

        }
        cout << " the number of seats that have been already occupied is " << this->occupiedSeats << "\n";

        if (this->occupiedRows != nullptr)
        {
            for (int i = 0; i < this->numberRow; i++)
            {
                cout << " and the number of rows that have been already occupied is " << this->occupiedRows[i] << "\n";
            }
        }

    }

    

    // overloading of operator =
    Theater& operator=(const Theater& play) {
        if (this != &play) {
            this->numberSeat = play.numberSeat;
            this->numberRow = play.numberRow;
            this->occupiedSeats = play.occupiedSeats;

            if (this->occupiedRows != nullptr)
            {
                delete[] this->occupiedRows;
            }

            if (play.occupiedRows != nullptr)
            {
                this->occupiedRows= new int[play.numberRow];
                for (int i = 0; i < this->numberRow; i++)
                {
                    this->occupiedRows[i] = play.occupiedRows[i];
                }
            }
            else
            {
                this->occupiedRows = nullptr;
            }

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
        this->occupiedSeats++;
        return*this;

    }



    //++ operator-postincrement. It counts the number of rows that have been occupied
    Theater operator++(int) {

        Theater copy = *this;
        this->occupiedRows++;
        return copy;

    }


    //[]  operator

    int operator[](int index) {
        if (occupiedRows != 0 && index >= 0 && index < numberRow) {
            return true;
        }
        else throw exception("invalid index");
    }


    //+ operator through member function
    Theater operator+(Theater play) {
        Theater copy = *this;
        copy.occupiedSeats = this->occupiedSeats + play.occupiedSeats;
        return copy;

    }
  

    //== operator
    bool operator==(const Theater& play) {
        if (numberSeat==play.numberSeat && this->numberRow == play.numberRow && this->occupiedSeats ==play.occupiedSeats && this->occupiedRows == play.occupiedRows)
            return true;
        else return false;
    }


    friend istream& operator>>(istream& console, Theater& play);
    friend ostream& operator<<(ostream& console, const Theater& play);


    //<<operator
    friend ostream& operator<<(ostream& console, const Theater& play) {


        if (play.name != nullptr) {

            console << "The play is " << play.name << '\n';
        }
        console << "The number of seats that have been occupied is: " << play.numberSeat << '\n';
        console << "The number of rows that have been occupied is: " << play.numberRow << '\n';

        return console;
    }

    //>> operator
    friend istream& operator>>(istream& console, Theater& play) {
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





