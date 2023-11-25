#include <iostream>
#include <string>
#include "ticket.h"
#include "theater.h"
#include "game.h"

using namespace std;


int main() {
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

    

    Theater t;
    cin >> t;

    cout << t;

    //ticket
    Ticket t2;
    cin >> t2;

    cout << t2;
    Ticket event();
    return 0;
}