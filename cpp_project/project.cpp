#include <iostream>
#include <string>
#include "ticket.h"
#include "theater.h"
#include "game.h"

using namespace std;


int main() {
    Ticket event();

    //game

   
    char name[] = "game1";
    Game g1(name, "Arena Nationala", "24", "30", "Steaua-Dinamo");
    g1.showDetailsGame();
    Game g2(name, 130);
    g2.showDuration();
    cout << !g1 << "\n";
    cout << !g2 << "\n";
    Game g3;
    g3 = ++g2;
    cout << g3 << "\n";
    
   
    Game g;
    cin >> g;

    cout << g;
  
    //theater
    char name1[] = "play1";
    Theater th(name1, 23, 25);
    th.showCapacity();
    int i[]{ 100, 200, 300 };
    Theater th2(name, 20, 30, i);
    th2.showAvailability();

    Theater t;
    cin >> t;

    cout << t;

    //ticket
   
    char id[] = "764346426";
    int price1[]{ 15, 20, 25 };
    Ticket ticket1(price1, "name","iaBilet", 15, 200, id);
    ticket1.showPrice();
    Ticket t2;
    cin >> t2;

    cout << t2;
    return 0;
}