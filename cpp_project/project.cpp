#include <iostream>
#include <string>
#include "ticket.h"
#include "theater.h"
#include "game.h"
#include <fstream>

using namespace std;


int main() {

    ////ticket

    string id= "767676";

    int price1[]{ 15, 20, 30 };

    Ticket ticket1(price1, "your name", "iaBilet", 14, 3, id);

    ticket1.showPrice();

    Ticket t2=ticket1;

    Ticket t3 = ticket1--;


    Ticket t4 = --ticket1;

  

    cout << t3[1];

    if (t2== t3) {
        cout << "The prices are the same."<<endl;
    }
    else {
        cout << " The prices are not the same."<<endl;
    }

    ticket1.priceWithDiscount(5);
    ticket1.showPrice();


    ArtisticEventInformation artisticEvent;
    SportsEventInformation sportsEvent;

    artisticEvent.showEventCategory();
    sportsEvent.showEventCategory();

    cin >> t2;

    cout << t2;

    t2.saveInBfile();

    ticket1.readFromBfile();

    ofstream f5("Ticket.txt");
    f5 << ticket1;
    f5.close();

    ifstream f6("Ticket.txt");
    f6 >> t2;


    cout << ticket1 << endl;
    cout << t2 << endl;


    //game

   
    char name[] = "football game";
    Game g1(name, "Arena Nationala", "24A", "30", "Steaua-Dinamo", 15);

    g1.showDetailsGame();

    Game g2(name, 130, 15);
    g2.showDuration();

    cout << !g1 << "\n";
    cout << !g2 << "\n";

    Game g3=g2++;
    cout << g3.getDuration()<<"\n";
    g3 = ++g2;
    cout << g3.getDuration()<<"\n";

   

    cout << g3[1];

    Game g5 = g1;

   /* Game g4 = g2 + 20;
    cout << "Duration :"<<g4.getDuration();*/

    
   
    Game g;
    cin >> g;

    cout << g;

    g1.saveInBfileg();
    g5.readFromBfileg();

    ofstream f1("Game.txt");
    f1 << g1;
    f1.close();

    ifstream f2("Game.txt");
    f2 >> g5;


    Game football;
    football.showGameType();
    FootballGame typeFootball;
    typeFootball.showGameType();
  


    //theater
    

    Theater th("O noapte furtunoasa", 23, 25);

    th.showCapacity();

    int i[]{ 50, 100, 150 };

    Theater th2("The phantom of the opera", 20, 3, i);

    th2.showAvailability();

    Theater th3 = th2;

    Theater th4 = th3++;

    Theater th5 = ++th3;

    if (th5 == th4) {
        cout << "The prices are equal"<<endl;
    }
    else {
        cout << "The prices are not equal"<<endl;
    }

    cout << th5[2]<<endl;
    Theater th6 = th4 + th5;
    
    Theater t;


    string movies[]{ "Spiderman", "Iron Man", "Thor" };

    Cinema c("Marvel", 67, 3, i, movies, 3);




    cin >> th3;

    cout << th3;


    th3.saveInBfileth();
    th2.readFromBfileth();
    ofstream f3("Theater.txt");
    f3 << th2;
    f3.close();


    ifstream f4("Theater.txt");
    f4 >> th3;
    f4.close(); 

    cout << th2 << endl;
    cout << th3 << endl;


    //cinema
   

    cin >> c;
    cout << c;


 

   
  
}