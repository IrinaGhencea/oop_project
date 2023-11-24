#include <iostream>
#include <string>
#include "ticket.h"
#include "theater.h"
#include "game.h"

using namespace std;


int main() {

    Game g1("game1", "address", "100", "2", "10", "Steaua-Dinamo");
    g1.showDetailsGame();
    Game g;
    cin >> g;

    cout << g;
  
    Theater t1("play1", "3", "12", "address","artist", 30);
    t1.showDetailsTheater();

    Theater t;
    cin >> t;

    cout << t;

    Ticket t1;
    cin >> t1;

    cout << t1;
    Ticket event();
    return 0;
}