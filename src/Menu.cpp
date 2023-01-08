
#include "Menu.h"
#include "Data.h"
#include "overloads.h"
#include <iostream>
#include <ostream>
#include <set>

void Menu::Menu1() {
    Data data = Data();
    std::cout << "Introduza a Cidade, o Aeroporto ou as Coordenadas: " << std::endl;
    std::string x;
    std::string cidade;
    std::string aeroporto;
    std::string cidade2;
    std::string pais;
    std::getline(std::cin, x);
    if (x == "Cidade") {
        std::cout << "Nome da cidade: " << std::endl;
        std::getline(std::cin, cidade);
    } else if (x == "Aeroporto") {
        std::cout << "Nome do aeroporto: " << std::endl;
        std::getline(std::cin, aeroporto);
        cidade = data.getAirport(aeroporto).getCity() + " (" + data.getAirport(aeroporto).getCountry() + ')';
    } else if (x == "Coordenadas") {
        std::string Cord;
        std::cout << "Latitude: " << std::endl;
        std::getline(std::cin, Cord);
        double latitude1;
        latitude1 = std::stod(Cord);
        std::cout << "Longitude " << std::endl;
        Cord.clear();
        std::getline(std::cin, Cord);
        double longitude1;
        longitude1 = std::stod(Cord);
        double dist;
        double min_dist = UINT64_MAX;
        //O(N)
        for (auto i: data.getCityGraph().getNodes()) {
            dist = data.haversine(latitude1, longitude1, i.second.airports.front());
            if (dist < min_dist) {
                min_dist = dist;
                cidade = i.first;
            }
        }
    } else {
        std::cout << "Input invalido" << std::endl;
        Menu1();
        return;
    }

    x.clear();
    std::cout << "Introduza -> Cidade, Aeroporto ou Coordenadas: " << std::endl;
    std::getline(std::cin, x);
    if (x == "Cidade") {
        std::cout << "Nome da cidade: " << std::endl;
        std::getline(std::cin, cidade2);
    } else if (x == "Aeroporto") {
        std::cout << "Nome do aeroporto: " << std::endl;
        std::string aeroporto2;
        std::getline(std::cin, aeroporto2);
        cidade2 = data.getAirport(aeroporto2).getCity() + " (" + data.getAirport(aeroporto2).getCountry() + ')';

    } else if (x == "Coordenadas") {
        std::string Cord;
        std::cout << "Latitude: " << std::endl;
        std::getline(std::cin, Cord);
        double latitude;
        latitude = std::stod(Cord);
        std::cout << "Longitude " << std::endl;
        Cord.clear();
        std::getline(std::cin, Cord);
        double longitude;
        longitude = std::stod(Cord);
        double dist;
        double min_dist = UINT64_MAX;
        //O(N)
        for (auto i: data.getCityGraph().getNodes()) {
            dist = data.haversine(latitude, longitude,
                                  i.second.airports.front());
            if (dist < min_dist) {
                min_dist = dist;
                cidade2 = i.first;
            }
        }
    } else {
        std::cout << "Input invalido" << std::endl;
        Menu1();
        return;
    }

    std::string choice;
    std::cout << "Informacao desejada: " << std::endl;
    std::cout << "1 - Numero minimo de voos" << std::endl << "2 - Distancia minima percorrida" << std::endl;
    std::getline(std::cin, choice);
    if (choice == "1") {
    std::cout << "Com o minimo numero de voos o caminho deve ser feito por: ";
    auto out = data.getCityGraph().bfs(cidade, cidade2);
    for(auto s : out){ std::cout << s << " ";}
    std::cout << std::endl;
    std::cout << "Numero de voos:  " << out.size()-1 << std::endl;
    std::cout << "Aeroportos:"  << data.getCityGraph().citiesToAirports(out);

    }
    else if (choice == "2") {
        std::cout << "O caminho mais curto deve ser feito por: ";
        auto out = data.getCityGraph().djikstra(cidade, cidade2);
        std::cout << out.first << std::endl;
        std::cout << "A distancia percorrida entre as cidades e de: " << out.second << " km's." << std::endl;
    }
}

void Menu::Menu2(){
    Data data = Data();
    std::string x;
    std::cout << "Introduza o aeroporto: " << std::endl; //Quantos voos diferentes,
    // de quantas compainhas aereas, de quantos destinos, de quantos paises diferentes
    //Quantos aeroportos, cidades ou países são atingíveis usando um máximo de Y voos
    std::getline(std::cin, x);
    auto out = data.getGraph().getNodes().find(x);
    std::cout << "Pretende saber informacao sobre: " << std::endl << "1 - Locais atingiveis" << std::endl << "2 - Gerais" << std::endl;
    std::string c1;
    std::getline(std::cin, c1);
    if(c1 == "1"){
        std::cout << "De que forma:  " << std::endl << "1 - X numero de voos" << std::endl << "2 - X numero de kilometros" << std::endl;
        std::string c2;
        std::getline(std::cin, c2);
        if(c2 == "1"){
            std::cout << "Pretende limitar as empresas? (s/n)" << std::endl;
            std::string limit;
            std::getline(std::cin, limit);
            if(limit == "s"){
                std::unordered_set<std::string> comps;
                std::string coisa = " ";
                while(coisa!="0"){
                    std::getline(std::cin, coisa);
                    comps.insert(coisa);
                }
                std::cout << "Numero de voos: " << std::endl;
                std::string numv;
                std::getline(std::cin, numv);
                std::cout << data.getCityGraph().airportsBfs(
                        data.getAirport(x).getCity() + " (" + data.getAirport(x).getCountry() + ')', std::stoi(numv), comps);
            }
            else if(limit == "n") {
                std::cout << "Numero de voos: " << std::endl;
                std::string numv;
                std::getline(std::cin, numv);
                std::cout << data.getCityGraph().airportsBfs(
                        data.getAirport(x).getCity() + " (" + data.getAirport(x).getCountry() + ')', std::stoi(numv));
            }
        }
        else if(c2 == "2"){
            double km;
            std::string kms;
            std::string c3;
            std::cout << "Pretende limitar as empresas? (s/n)" << std::endl;
            std::getline(std::cin, c3);
            if(c3 == "s"){
                std::unordered_set<std::string> comps;
                std::string coisa = " ";
                while(coisa!="0"){
                    std::getline(std::cin, coisa);
                    comps.insert(coisa);
                }
                std::cout << "Numero de km's: " << std::endl;
                std::getline(std::cin, kms);
                km = std::stod(kms);
                std::cout << data.getCityGraph().airportsBfs(
                        data.getAirport(x).getCity() + " (" + data.getAirport(x).getCountry() + ')', km, comps);
            }
            if(c3 == "n"){
                std::cout << "Numero de km's: " << std::endl;
                std::getline(std::cin, kms);
                km = std::stod(kms);
                std::cout << data.getCityGraph().airportsBfs(
                        data.getAirport(x).getCity() + " (" + data.getAirport(x).getCountry() + ')', km);
            }
        }
    }
    else if(c1 == "2"){
        std::cout << "Do aeroporto " << x << " partem " << out->second.adj.size() << " voos." <<  std::endl;
        std::cout << "Com os destinos" << std::endl;
        for(auto j : out->second.adj){
            std::cout << j.dest << std::endl;
        }
        std::set<std::string> companhias;
        for(auto k : out->second.adj){
            companhias.insert(k.company);
        }
        std::cout << "De " << companhias.size() << " companhias aereas diferentes:" << std::endl;
        for(auto l : companhias){
            std::cout << l << std::endl;
        }

        std::set<std::string> paises;
        for(auto p : out->second.adj){ //second->adj airport
            paises.insert(data.getAirport(p.dest).getCountry());
        }
        std::cout << "De " << paises.size() << " paises diferentes. " << std::endl;

    }
}

