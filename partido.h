#ifndef PARTIDO_H_
    #define PARTIDO_H_

    #include <iostream>
    #include <string>
    #include <list>
    #include "politico.h"

    using namespace std;

    class Partido{
        int votosLegenda;
        int votosTotais;
        int numEleitos;
        string nome;
        string sigla;
        list<Politico> politicos;
        Politico primeiroColocado;
        Politico ultimoColocado;

        public:

    };
#endif