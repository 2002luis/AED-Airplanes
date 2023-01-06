#include <iostream>
#include <string.h>
#include "Graph.h"
#include "GraphC.h"
#include "Airport.h"
#include "overloads.h"
#include "Data.h"


int main() {

    /*
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

    testG.addFlight("BRUH","BRUH2","gay",5);
    testG.addFlight("BRUH","BRUH7","gay",10000);
    //testG.addFlight("BRUH","BRUH5","gay",50000);

    testG.addFlight("BRUH2","BRUH7","gay",1);

    testG.addFlight("BRUH3","BRUH7","gay",1);
    testG.addFlight("BRUH3","BRUH2","gay",1);

    testG.addFlight("BRUH4","BRUH3","gay",1);

    testG.addFlight("BRUH5","BRUH7","gay",1);

    testG.addFlight("BRUH6","BRUH7","gay",1);
    testG.addFlight("BRUH6","BRUH","gay",1);

    testG.addFlight("BRUH7","BRUH","gay",1);



    std::cout << testG;

    std::cout << testG.bfs("BRUH","BRUH7");

    testG.removeVisited();

    std::cout << testG.djikstra("BRUH","BRUH7").first;
    */

    /*
    GraphC testC;

    Airport c1("A1","","C1","",0,0),c2("A2","","C1","",0,0),
            c3("A3","","C2","",0,0),c4("A4","","C3","",0,0),
            c5("A5","","C4","",0,0);

    testC.addAirport(c1);
    testC.addAirport(c2);
    testC.addAirport(c3);
    testC.addAirport(c4);
    testC.addAirport(c5);

    testC.addFlight("A2","C1","A3","C2","SEXO");
    testC.addFlight("A3","C2","A5","C4","SEXO");
    testC.addFlight("A1","C1","A5","C4","SEXO",300);

    std::cout << testC << std::endl;

    std::cout << testC.bfs("C1","C4") << std::endl;
    std::cout << testC.citiesToAirports(testC.bfs("C1","C4")) << std::endl;



    std::cout << testC.djikstra("C1","C4").first << std::endl;
    std::cout << testC.citiesToAirports(testC.djikstra("C1","C4").first) << std::endl;
    */

    //READER TESTS

    Data data;
    Graph graph = data.getGraph();


    std::cout << graph << std::endl << graph.bfs("CD1","CD6") << graph.djikstra("CD1","CD6").first << graph.djikstra("CD1","CD6").second;

    GraphC graphCity = data.getCityGraph();

    std::cout << graphCity << std::endl << graphCity.bfs("Lourosa","Gotland") << graphCity.citiesToAirports(graphCity.bfs("Lourosa","Gotland")) << graphCity.djikstra("Lourosa","Gotland").first << graphCity.djikstra("Lourosa","Gotland").second << graphCity.citiesToAirports(graphCity.djikstra("Lourosa","Gotland").first);

    std::cout << std::endl << std::endl << graph.airportsBfs("CD1",2) << std::endl << graph.airportsDijkstra("CD1",6000);

    return 0;
}
