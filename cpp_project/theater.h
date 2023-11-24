#pragma once
#include <iostream>
#include <string>

using namespace std;

class Theater {
private:

    char* name = nullptr; //dynamically defined array of characters
    string address= "";
    string artist = "";
    int duration = 0;
    int numberSeat = 0; //statically defined array
    string seat = "";
    string row = "";
    int numberRow = 0;
    int occupiedSeats = 0; //statically defined array
    const int max_number_seats;




    static int min_number_seats;
    
  

public:

    friend istream& operator>>(istream& console, Theater& play);
    friend ostream& operator<<(ostream& console, const Theater& play);


    // default constructor
    Theater():max_number_seats(1000) {
        this->numberSeat = 0;
        this->occupiedSeats = 0;
        this->numberRow = 0;
        this->name = nullptr;
        this->duration = 0;
        this->address = "";
        this->artist = "";
        this->seat = "";
        this->row = "";
    }

    // 1st constructor with parameters
    Theater(char* name, int numberSeat, int numberRow) :max_number_seats(max_number_seats) {

        if (name != nullptr && strlen(name) < 15) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
        else {
            this->name = nullptr;
        }
        this->seat = seat;
        this->row= row;
        
       
    }

    // 2nd constructor with parameters
    Theater( char* name, string seat, string row, string address, string artist, int duration) :max_number_seats(max_number_seats) {

        if (name != nullptr && strlen(name) < 15) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
        else {
            this->name = nullptr;
        }
        
        this->name = name;
        this->address = address;
        this->artist = artist;
        this->duration = duration;
       

    }


    // copy constructor
    Theater(const Theater& play) :max_number_seats(max_number_seats) {
        this->seat = play.seat;
        this->numberSeat = play.numberSeat;
        this->seat = play.seat;
        this->row = play.row;
        this->occupiedSeats = play.occupiedSeats;
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

    // getter Number Seats
    int getNumberSeat() {
        return this->numberSeat;
    }

    // setter Number Seats



    void setNumberSeat(int numberSeat) {
        if (numberSeat < Theater::max_number_seats || numberSeat > Theater::min_number_seats) {
            this->numberSeat = numberSeat;
        }
        else {
            throw exception("Invalid");
        }
    }

    // getter Number Rows

    int getNumberRow() {
        return this->numberRow;
    }


    //setter Number Rows

    void setNumberRow(int numberRow) {
        if (numberRow < Theater::numberRow) {
            this->numberRow = numberRow;
        }
        else {
            throw exception("Invalid");
        }
    }

    //setter name
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

    //setter name

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
     

    //getter address

    string getAddress() {
        return this->address;
    }


    //setter address

    void setAddress(string address) {
        this->address = address;

    }

    //getter artist
    string getArtist() {
        return this->artist;
    }

    //setter artist

    void setArtist(string artist) {
        this->artist = artist;

    }

    //getter duration
    int getDuration() {
        return this->duration;
    }

    //setter duration

    void setDuration(int duration) {
        if (duration < 300 || duration > 5) {
            this->duration = duration;
        }
        else {
            throw exception("Invalid");
        }
    }

    //getter number seats occupied
    int occupiedSeats() {
        return this->occupiedSeats;
    }

    //setter number seats occupied

    void setOccupiedSeats(int occupiedSeats) {
        if (occupiedSeats < 100) {
            throw exception("The event will not take place.");

        }
        else {
            this->occupiedSeats = occupiedSeats;
        }
        
    }

    //getter seat

    string getSeat() {
        return this->seat;
    }

    //setter seat

    void setSeat(string seat) {
        this->seat=seat;
    }

        //getter row

    string getRow() {
        return this->row;
    }

    //setter row

    void setRow(string row) {
        this->row = row;
    }

        
    //getter min number of seats
    static int getMinNumberSeats() {
        return min_number_seats;
    }

    // setter min number of seats
    
    void setMinNumberSeats(int min_number_seats)
    {
        Theater::min_number_seats = min_number_seats;
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
        ++occupiedSeats;
        return copy;

    }

    //! operator 
    bool operator!()
    {
        if ( this->numberSeat< min_number_seats|| this->numberSeat>occupiedSeats)
        {
            return true;
        }
        else
        {
            return false;
        }

       
    }

    //a method that prints the details
    void showDetailsTheater()
    {

        if (this->name != nullptr)
        {


            cout << "PLay's name is" << this->name;

        }
        cout << "Your seat is" << this->seat << "and your row is" << this->row << "\n";
        cout << "The address for where the play takes place is" << this->address << "and the approximate duration is" << this->duration << "\n";
        cout << "The artist that will perform is" << this->artist << "\n";

    }

    void showCapacityTeather()
    {
        if (this->name != nullptr)
        {


            cout << "PLay's name is" << this->name;

        }
        cout << "The number of seats available are " << this->numberSeat << "and the number of rows are" << this->numberRow << "\n";
        

    }

    

    //<<operator
    friend ostream& operator<<(ostream& console, const Theater& play) {


        if (play.name != nullptr) {

            console << "Play's name is: " << play.name << '\n';
        }
 
        console << "Your seat is: " << play.numberSeat << '\n';
        console << "Your row is: " << play.numberRow << '\n';
       

        return console;
    }

    //>> operator
      friend istream& operator>>(istream& console, Theater& play) {
        cout <<"Play's name is:"<<'\n';
        char buffer[100];
        console.getline(buffer, 100);
        console.clear();

        play.setName(buffer);

        cout << "Your seat: ";
        console >>play.seat;

        cout << "Your row: ";
        console >> play.row;


        return console;


    }



};

// initializing static variables
int Theater::min_number_seats = 15;





