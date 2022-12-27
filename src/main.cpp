#include <iostream>
#include <string.h>
#include "Graph.h"
#include "Airport.h"
#include "overloads.h"



int main() {
    Graph testG;
    Airport a1("BRUH","","","",3,3),a2("BRUH2","","","",3,3),a3("BRUH3","","","",3,3),
            a4("BRUH4","","","",3,3), a5("BRUH5","","","",3,3);
    testG.addAirport(a1);
    testG.addAirport(a2);
    testG.addAirport(a3);
    testG.addAirport(a4);
    testG.addAirport(a5);
    testG.addFlight("BRUH","BRUH2","gay");
    testG.addFlight("BRUH2","BRUH3","gay");
    testG.addFlight("BRUH3","BRUH5","gay");
    testG.addFlight("BRUH","BRUH5","gay");

    std::cout << testG;

    //std::cout << testG.bfs("BRUH","BRUH5");
    std::list<std::string> path = testG.bfs("BRUH","BRUH5");
    std::cout << std::endl;
    for(auto i : path){
        std::cout << i << ' ';
    }




    return 0;
}
