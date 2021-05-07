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
            void geraRelatorio4(list<Politico*>, map<int, Partido*>, int);
            void geraRelatorio5(list<Politico*>, map<int, Partido*>, int);
            void geraRelatorio6(list<Partido*>);
            void geraRelatorio7(list<Partido*>);
            void geraRelatorio8(list<Politico*>, int);
            void geraRelatorio9(list<Politico*>, int);
            void geraRelatorio10(int, int, int);
    };
#endif