#include <iostream>
#include <string.h>
#include "Graph.h"
#include "Airport.h"
#include "overloads.h"



int main() {
    Graph testG;
    Airport a1("BRUH","","","",3,3),a2("BRUH2","","","",3,3),a3("BRUH3","","","",3,3);
    testG.addAirport(a1);
    testG.addAirport(a2);
    testG.addAirport(a3);
    testG.addFlight("BRUH","BRUH2","gay");
    testG.addFlight("BRUH3","BRUH","gay");

    std::cout << testG;





    return 0;
}
