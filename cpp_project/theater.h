#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Theater {
private:
    char* name; //dynamically defined array
    int numberSeat; //statically defined array of numbers
    int numberRow;
    int occupiedSeats;
    int* occupiedRows; //dynamically defined array of numbers

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
        this->occupiedRows = nullptr;
        this->occupiedSeats = 0;
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
        this->numberSeat = 0;

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
        if (play.name != nullptr) {
            this->name = new char[strlen(play.name) + 1];
            strcpy(this->name, play.name);
        }
        else {
            this->name = nullptr;
        }
        if (play.occupiedRows != nullptr)
        {
            this->occupiedRows = new int[this->numberRow];
            for (int i = 0; i < this->numberRow; i++)
            {
                this->occupiedRows[i] = play.occupiedRows[i];
            }

        }

    }

    // destructor
    ~Theater() {
        if (occupiedRows != nullptr) {
            delete[] this->occupiedRows;
        }
        delete[] this->name;


    }

  
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
        

    }


    void showAvailability()
    {

        if (this->name != nullptr)
        {


            cout << "For the play " << this->name<<"\n";

        }
        cout << " the number of seats that have already been occupied is " << this->occupiedSeats << "\n";

      

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


    void saveInBfile() {
        ofstream f("theater.bin", std::ios::out | std::ios::binary);

        if (f.is_open()) {
            unsigned length = strlen(name);
            f.write((char*)&length, sizeof(length));
            f.write(name, length + 1);
            f.write((char*)&numberSeat, sizeof(numberSeat));
            f.write((char*)&numberRow, sizeof(numberRow));
            f.write((char*)&occupiedSeats, sizeof(occupiedSeats));

            if (occupiedRows != nullptr) {

                for (int i = 0; i < numberRow; i++) {
                    f.write((char*)&occupiedRows[i], sizeof(occupiedRows[i]));
                }
            }
            f.close();
        }
    }

    void readFromBfile() {

        ifstream f("theater.bin", std::ios::in | std::ios::binary);


        if (f.is_open()) {
            unsigned length = 0;
            f.read((char*)&length, sizeof(length));
            char* n = new char[length + 1];
            f.read(n, length + 1);
            name = n;
            delete[] n;
            f.read((char*)&numberSeat, sizeof(numberSeat));
            f.read((char*)&numberRow, sizeof(numberRow));
            f.read((char*)&occupiedSeats, sizeof(occupiedSeats));

            if (occupiedRows != nullptr) {
                for (int i = 0; i < numberRow; i++) {
                    f.read((char*)&occupiedRows[i], sizeof(occupiedRows[i]));
                }
            }
            f.close();
        }
    }



    friend istream& operator>>(istream& console, Theater& );
    friend ostream& operator<<(ostream& console, const Theater );

    friend ofstream& operator<<(std::ofstream& fout, const Theater& );
    friend ifstream& operator>>(std::ifstream& fin, Theater&);



    

   

};

// initializing static variables
int Theater::min_number_seats = 15;
int Theater::max_number_seats = 350;


//<<operator
 ostream& operator<<(ostream& console, const Theater play) {


    if (play.name != nullptr) {

        console << "The play is " << play.name << '\n';
    }
    console << "The number of seats that have been occupied is: " << play.numberSeat << '\n';


    return console;
}

//>> operator
istream& operator>>(istream& console, Theater& play) {
    cout << endl << "Play's name is: " << "\n";
    char buffer[100];
    console.getline(buffer, 100);
    console.clear();

    play.setName(buffer);

    cout << "The number of occupied seats: " << '\n';
    console >> play.numberSeat;


    return console;


}

ofstream& operator<<(ofstream& fout, const Theater& play) {
    unsigned length = strlen(play.name);
    fout.write((char*)&length, sizeof(length));
    fout.write(play.name, length + 1);
    fout.write((char*)&play.numberSeat, sizeof(play.numberSeat));
    fout.write((char*)&play.numberRow, sizeof(play.numberRow));
    fout.write((char*)&play.occupiedSeats, sizeof(play.occupiedSeats));
    if (play.occupiedRows != nullptr) {
        for (int i = 0; i < play.numberRow; i++) {
            fout.write((char*)&play.occupiedRows[i], sizeof(play.occupiedRows[i]));
        }
    }
    return fout;
}

ifstream& operator>>(std::ifstream& fin, Theater& play) {
    unsigned length = 0;
    fin.read((char*)&length, sizeof(length));
    char* n = new char[length + 1];
    fin.read(n, length + 1);
    play.name = n;
    delete[] n;
    fin.read((char*)&play.numberSeat, sizeof(play.numberSeat));
    fin.read((char*)&play.numberRow, sizeof(play.numberRow));
    fin.read((char*)&play.occupiedSeats, sizeof(play.occupiedSeats));
    if (play.occupiedRows != nullptr) {
        for (int i = 0; i < play.numberRow; i++) {
            fin.read((char*)&play.occupiedRows[i], sizeof(play.occupiedRows[i]));
        }
    }
    return fin;
}


//class created by deriving an existing class

class Cinema : public Theater {
private:
    string* movies; 
    int numMovies;

public:
    // constructor

    Cinema() : Theater() {
        this->movies = nullptr;
        this->numMovies = 0;

    }

    Cinema(const char* name, int occupiedSeats, int numberRow, int* occupiedRows, const string* movies, int numMovies)
        : Theater(name, occupiedSeats, numberRow, occupiedRows) {

        if (movies != nullptr)
        {
            this->movies = new string[numMovies];
            for (int i = 0; i < numMovies; i++)
            {
                this->movies[i] = movies[i];
            }
        }
        else
        {
            this->movies = nullptr;
        }

        this->numMovies = numMovies;
    }

    // destructor
    ~Cinema() {
        if(this->movies!=nullptr)
        delete[] this->movies;
    }

    // getters
    string* getMovies() const {
        string* copy;
        if (this->movies != nullptr)
        {
            copy = new string[this->numMovies];
            for (int i = 0; i < this->numMovies; i++)
            {
                copy[i] = this->movies[i];
            }
        }
        else
        {
            copy = nullptr;
        }

        return copy;
    }

    void setMovies(const string* movies) {
        if (this->movies != nullptr) {
            delete[] this->movies;
        }
        if (movies != nullptr)
        {
            this->movies = new string[this->numMovies];
            for (int i = 0; i < this->numMovies; i++)
            {
                this->movies[i] = movies[i];
            }
        }
        else
        {
            this->movies = nullptr;
        }

    }


    friend ostream& operator<<(ostream&, Cinema);
    friend istream& operator>>(istream&, Cinema&);
    
};




ostream& operator<<(ostream& console, Cinema c)
{
    
    console << (Theater)c << '\n';

    console <<"Number of movies: " << c.numMovies;

    return console;
}


istream& operator>>(istream& console, Cinema& c)
{
    cout << "Number of movies: ";
     
        console >> c.numMovies;
    

    return console;
}


