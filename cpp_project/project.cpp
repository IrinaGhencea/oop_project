#include <iostream>
#include <string>
#include "ticket.h"
#include "theater.h"
#include "game.h"
#include <fstream>

using namespace std;


int main() {

    //game

   
    char name[] = "game1";
    Game g1(name, "Arena Nationala", "24", "30", "Steaua-Dinamo", 15);

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

    /*Game g4 = g2 + 20;
    cout << g4.getDuration();*/

    
   
    Game g;
    cin >> g;

    cout << g;

    ofstream f1("game.txt");
    f1 << g1;
    f1.close();

    ifstream f2("game.txt");
    f2 >> g2;

  
    //theater
    char name1[] = "play1";

    Theater th(name1, 23, 25);

    th.showCapacity();

    int i[]{ 100, 200, 300 };

    Theater th2(name1, 20, 3, i);

    th2.showAvailability();

    Theater th3 = th2;

    Theater th4 = th3++;

    Theater th5 = ++th3;

    if (th5 == th4) {
        cout << "are equal";
    }
    else {
        cout << "not equal";
    }

   /* cout << th5[2];
    Theater th6 = th4 + th5;
    */
    Theater t;

    cin >> t;

    cout << t;

    ofstream f3("theater.txt");
    f3 << t;
    f3.close();

    ifstream f4("theater.txt");
    f4 >> t;

    //cinema
    string movies[]{ "Spiderman1", "Iron Man", "Thor" };

    Cinema c(name1, 67, 3, i, movies, 3);

    /*cin >> c;
    cout << c;*/


    //ticket
   
    char id []="767676";

    int price1[]{ 15, 20, 30 };

    Ticket ticket1(price1, "name","iaBilet", 5, 3, id);

    ticket1.showPrice();

    Ticket t2;

    Ticket t3=ticket1--;

    cout<<t3.getPrice();

    Ticket t4 = --ticket1;

    cout << t4.getPrice();

    cout << t3[1];
    
    if (t4 == t3) { 
        cout <<  "are equal.";
    }
    else {
        cout << " are not equal.";
    }


    cin >> t2;

    cout << t2;
    

    ofstream f5("ticket.txt");
    f5 << t4;
    f5.close();

    ifstream f6("ticket.txt");
    f6 >> t4;


    ArtisticEventInfo artisticEvent;
    SportsEventInfo sportsEvent;

    artisticEvent.displayEventType();
    sportsEvent.displayEventType();
  
}