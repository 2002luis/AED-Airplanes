#include <iostream>
#include <string.h>
#include "Graph.h"
#include "Airport.h"
#include "overloads.h"



int main() {
    Graph testG;
    Airport a1("BRUH","","","",3,3),a2("BRUH2","","","",3,3),a3("BRUH3","","","",3,3),
            a4("BRUH4","","","",3,3), a5("BRUH5","","","",3,3),
            a6("BRUH6","","","",3,3),a7("BRUH7","","","",3,3);
    testG.addAirport(a1);
    testG.addAirport(a2);
    testG.addAirport(a3);
    testG.addAirport(a4);
    testG.addAirport(a5);
    testG.addAirport(a6);
    testG.addAirport(a7);

    testG.addFlight("BRUH","BRUH2","gay",4);
    testG.addFlight("BRUH","BRUH5","gay",10000);

    testG.addFlight("BRUH2","BRUH3","gay",5);

    testG.addFlight("BRUH3","BRUH5","gay",2);

    //testG.addFlight("BRUH4","BRUH7","gay");

    testG.addFlight("BRUH5","BRUH7","gay",3);

    //testG.addFlight("BRUH6","BRUH5","gay");

    std::cout << testG;

    std::cout << testG.bfs("BRUH","BRUH5");

    testG.removeVisited();

    std::cout << testG.djikstra("BRUH","BRUH5").first;




    return 0;
}
