#pragma once
#include <iostream>
#include <string>

using namespace std;

class Game {
private:

    char* name = nullptr;
    string address = "";
    int duration = 0;
    int numberSeat = 0;
    int numberRow = 0;
    int occupiedSeats = 0;
    int occupiedRows = 0;



    static int min_number_seats;
    static int max_number_seats;
    static int number_rows;

public:

    friend istream& operator>>(istream& console, Game& play);
    friend ostream& operator<<(ostream& console, const Game& play);


    // default constructor
    Game() {
        this->numberSeat = 0;
        this->numberRow = 0;
        this->name = nullptr;
        this->duration = 0;
        this->address = "";

    }



    // 1st constructor with parameters
    Game(int numberSeat, int numberRow) {
        this->numberSeat = numberSeat;
        this->numberRow = numberRow;

    }

    // 2nd constructor with parameters
    Game(const char* name, string address, int duration) {
        this->address = address;
        this->duration = duration;


        if (name != nullptr && strlen(name) < 15) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
        else {
            this->name = nullptr;
        }
    }



    // copy constructor
    Game(const Game& game) {
        this->numberSeat = game.numberSeat;
        this->numberRow = game.numberRow;
        this->address = game.address;
        this->duration = game.duration;

        if (game.name != nullptr) {
            this->name = new char[strlen(game.name) + 1];
            strcpy(this->name, game.name);
        }
        else {
            this->name = nullptr;
        }
    }

    // destructor
    ~Game() {
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
        if (numberSeat < Game::max_number_seats || numberSeat > Game::min_number_seats) {
            this->numberSeat = numberSeat;
        }
        else {
            throw exception("No more seats!");
        }
    }

    void setNumberRow(int numberRow) {
        if (numberRow < Game::number_rows) {
            this->numberRow = numberRow;
        }
        else {
            throw exception("No more rows");
        }
    }

    void setAddress(string address) {
        this->address = address;

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
        Game::number_rows = number_rows;
    }

    // overloading of operator =
    Game& operator=(const Game& game) {
        if (this != &game) {
            this->numberSeat = game.numberSeat;
            this->numberRow = game.numberRow;
            this->address = game.address;
            this->duration = game.duration;
            if (this->name != nullptr) {
                delete[] this->name;
            }
            if (game.name != nullptr) {
                this->name = new char[strlen(game.name) + 1];
                strcpy(this->name, game.name);
            }
            else {
                this->name = nullptr;
            }
        }
        return *this;
    }

    //++ operator-preincrement. It counts the number of seats that have been occupied
    Game& operator++() {
        ++occupiedSeats;
        ++numberSeat;
        return*this;

    }



    //++ operator-postincrement. It counts the number of rows that have been occupied
    Game operator++(int) {

        Game copy = *this;
        ++occupiedRows;
        return copy;

    }

    //! operator 
    bool operator!()
    {
        if (this->numberSeat > max_number_seats || this->numberSeat < min_number_seats)
        {
            return true;
        }
        else
        {
            return false;
        }


    }

    //a method that prints the details
    void showDetailsGame()
    {

        if (this->name != nullptr)
        {


            cout << "Game's name is" << this->name;

        }
        cout << "The address for this game is" << this->address << "and the approximate duration is" << this->duration << "\n";

    }

    //a method that prints the capacity
    void showCapacityGame()
    {

        cout << "The number of seats available are " << this->numberSeat << "and the number of rows are" << this->numberRow << "\n";

    }





    //<<operator
    friend ostream& operator<<(ostream& console, const Game& game) {


        if (game.name != nullptr) {

            console << "Game's name is: " << game.name << '\n';
        }
        console << "Game's address is: " << game.address << '\n';
        console << "Game's duration is: " << game.duration << '\n';
        console << "The number of seats that have been occupied is: " << game.numberSeat << '\n';
        console << "The number of rows that have been occupied is: " << game.numberRow << '\n';


        return console;
    }

    //>> operator
    friend istream& operator>>(istream& console, Game& game) {
        cout << "Game's name is:" << '\n';
        char buffer[100];
        console.getline(buffer, 100);
        console.clear();

        game.setName(buffer);

        cout << "Game's address is: ";
        console >> game.address;

        cout << "Game's duration is: ";
        console >> game.duration;


        cout << "The number of seats that have been occupied: ";
        console >> game.numberSeat;

        cout << "The number of rows that have been occupied: ";
        console >> game.numberRow;
        return console;


    }



};

// initializing static variables
int Game::min_number_seats = 100;
int Game::max_number_seats = 20000;
int Game::number_rows = 50;




