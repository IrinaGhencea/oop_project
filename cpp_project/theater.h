#pragma once
#include <iostream>
#include <string>

using namespace std;

class Theater {
private:

    char* name = nullptr;
    string address= "";
    string artist = "";
    int duration = 0;
    int numberSeat = 0;
    int numberRow = 0;
    int occupiedSeats = 0;
    int occupiedRows = 0;



    static int min_number_seats;
    static int max_number_seats;
    static int number_rows;

public:

    friend istream& operator>>(istream& console, Theater& play);
    friend ostream& operator<<(ostream& console, const Theater& play);


    // default constructor
    Theater() {
        this->numberSeat = 0;
        this->numberRow = 0;
        this->name = nullptr;
        this->duration = 0;
        this->address = "";
        this->artist = "";
    }

    // 1st constructor with parameters
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

    // 2nd constructor with parameters
    Theater(const char* name, string address, string artist, int duration) {
        this->address = address;
        this->duration = duration;
        this->artist = artist;
        
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
        this->address = play.address;
        this->duration= play.duration;
        this->artist = play.artist;

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
     
    string getAddress() {
        return this->address;
    }

    string getArtist() {
        return this->artist;
    }

    int getDuration() {
        return this->duration;
    }


    
    int getNumberOccupiedSeats() {
        return this->occupiedSeats;
    }
    int getNumberOccupiedRows() {
        return this->occupiedRows;
    }

    static int getNumberRows() {
        return number_rows;
    }

    // setters
    void setNumberSeat(int numberSeat) {
        if (numberSeat < Theater::max_number_seats || numberSeat > Theater::min_number_seats) {
            this->numberSeat = numberSeat;
        }
        else {
            throw exception("Invalid");
        }
    }

    void setNumberRow(int numberRow) {
        if (numberRow < Theater::number_rows) {
            this->numberRow = numberRow;
        }
        else {
            throw exception("Invalid");
        }
    }

    void setAddress(string address) {
        this->address = address;

    }
    void setArtist(string artist) {
        this->artist = artist;

    }
    
    

    void setDuration(int duration) {
        if (duration < 300 || duration > 5) {
            this->duration = duration;
        }
        else {
            throw exception("Invalid");
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

    void setRowNumber(int number_rows)
    {
        Theater::number_rows = number_rows;
    }

    // overloading of operator =
    Theater& operator=(const Theater& play) {
        if (this != &play) {
            this->numberSeat = play.numberSeat;
            this->numberRow = play.numberRow;
            this->address = play.address;
            this->duration = play.duration;
            this->artist = play.artist;
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

    //! operator 
    bool operator!()
    {
        if (this->numberSeat > max_number_seats || this->numberSeat< min_number_seats)
        {
            return true;
        }
        else
        {
            return false;
        }

       
    }

    //<<operator
    friend ostream& operator<<(ostream& console, const Theater& play) {


        if (play.name != nullptr) {

            console << "Play's name is: " << play.name << '\n';
        }
        console << "Play's address is: " << play.address << '\n';
        console << "Play's duration is: " << play.duration << '\n';
        console << "The artist that will perform: " << play.artist << '\n';
        console << "The number of seats that have been occupied is: " << play.numberSeat << '\n';
        console << "The number of rows that have been occupied is: " << play.numberRow << '\n';
       

        return console;
    }

    //>> operator
    friend istream& operator>>(istream& console, Theater& play) {
        cout <<"Play's name is:"<<'\n';
        char buffer[100];
        console.getline(buffer, 100);
        console.clear();

        play.setName(buffer);

        cout << "Play's address is: ";
        console >>play.address;

        cout << "Play's duration is: ";
        console >> play.duration;

        cout << "The artist that will perform ";
        console >> play.artist;

        cout << "The number of seats that have been occupied: ";
        console >> play.numberSeat;

        cout << "The number of rows that have been occupied: ";
        console >> play.numberRow;
        return console;


    }



};

// initializing static variables
int Theater::min_number_seats = 15;
int Theater::max_number_seats = 350;
int Theater::number_rows = 20;




