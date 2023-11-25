#pragma once
#include <iostream>
#include <string>

using namespace std;

class Game {
private:

    char* name = nullptr; //dynamically defined array of characters
    const int minAge;
    string address = "";
    string teams = "";
    string seat = "";
    string row = "";
    int age = 0; //statically defined array
    int duration = 0; 
    


    static int extra;

    
  

public:


    // default constructor
    Game() :minAge(14) {

        this->name = nullptr;
        this->duration = 0;
        this->address = "";
        this->seat = "";
        this->row = "";
        this->teams = "";
    

    }

    // 1st constructor with parameters
    Game( char* name, string address,string seat, string row, string teams) :minAge(minAge) {
        this->address = address;
        this->teams = teams;
        this->seat = seat;
        this->row = row;



        if (name != nullptr && strlen(name) < 15) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
        else {
            this->name = nullptr;
        }
    }

    // 2nd constructor with parameters
    Game( char* name, int duration ) :minAge(minAge) {

        if (name != nullptr&& strlen(name)<15) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);

        }
        
        this->duration = duration;

    }

    



    // copy constructor
    Game(const Game& game) :minAge(minAge) {
        this->seat = game.seat;
        this->row = game.row;
        this->teams = game.teams;
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

    
    string getSeat() {
        return this->seat;
    }


    string getRow() {
        return this->row;
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

    string getAddress() {
        return this->address;
    }


    void setAddress(string address) {
        this->address = address;

    }

    string getTeams() {
        return this->teams;
    }


    void setTeams(string teams) {
        this->teams = teams;

    }

    int getDuration() {
        return this->duration;
    }

    void setDuration(int duration) {
        if (duration < 300 || duration > 5) {
            this->duration = duration;
        }
        else {
            throw exception("Invalid");
        }
    }


     

    static int getExtra() {
        return extra;
    }

    void setExtra(int extra)
    {
        Game::extra = extra;
    }
    






    




    // overloading of operator =
    Game& operator=(const Game& game) {
        if (this != &game) {
            this->seat = game.seat;
            this->row = game.row;
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

   




   

    //generic method that prints the details
    void showDetailsGame()
    {

        if (this->name != nullptr)
        {


            cout << "Game's name is " << this->name<<"\n";

        }
        cout << "Your seat is " << this->seat << " and your row is " << this->row<<"\n";
        cout << "The address for this game is " << this->address << " and the teams that are playing " << this->teams << "\n";

    }

    void showDuration() {
        if (this->name != nullptr)
        {


            cout << "For this " << this->name << " the duration is " << this->duration << "\n"; "\n";

        }
        
    }
  

    //[] operator
    int operator[](int index)
    {
        if (name != 0 && index >= 0 && index < strlen(this->name) + 1)
        {
            return name[index];
        }
        else throw exception("invalid index");
    }


     //! operator
    bool operator!() {
         if (this->duration == 0) {
             return false;
         }
         else return true;
     }

     //++operator preincrementation 

    Game& operator++()
     {
         this->duration++;

         return *this;
     }

    //++operator postincrementation
    Game operator++(int i) {
        Game copy = *this;
        this->duration++;
        return copy;

    }

    

    //+ operator
    Game& operator+(int x) {
        Game copy = *this;
        copy.duration =this->duration + x;
        return copy;
    }

    //== operator 
    bool operator==(const Game& game) {
        if (this->duration == game.duration && this->age == game.age && strcmp(this->name, game.name) == 0)
            return true;
        else return false;
    }

   
    friend istream& operator>>(istream& console, Game& game);
    friend ostream& operator<<(ostream& console, const Game& game);


    //<<operator
     friend ostream& operator<<(ostream& console, const Game& game) {


        if (game.name != nullptr) {

            console << "Game's name is : " << game.name << '\n';
        }
        console << "Your age :";
        console << "Your seat is : " << game.seat << '\n';
        console << "Your row is : " << game.row<< '\n';
      


        return console;
    }

    //>> operator
    friend istream& operator>>(istream& console, Game& game) {
        cout << "Game's name is :" << '\n';
        char buffer[100];
        console.getline(buffer, 100);
        console.clear();

        game.setName(buffer);


        cout << "Your age: ";
        console >> game.age;


        cout << "Your seat is: ";
        console >> game.seat;

        cout << "Your row is: ";
        console >> game.row;

       
        return console;


    }



};


// initializing static variables
int Game::extra = 15;



