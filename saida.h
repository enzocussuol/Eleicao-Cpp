#ifndef SAIDA_H_
    #define SAIDA_H_

    #include <iostream>
    #include <string>
    #include <map>
    #include <list>
    #include "politico.h"
    #include "partido.h"

    using namespace std;

    class Saida{
        public:
            void geraRelatorio1(int);
            void geraRelatorio2(list<Politico*>, map<int, Partido*>, int);
            void geraRelatorio3(list<Politico*>, map<int, Partido*>, int);
    };
#endif