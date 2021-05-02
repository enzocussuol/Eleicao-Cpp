#ifndef ELEICAO_H_
    #define ELEICAO_H_

    #include <iostream>
    #include <string>
    #include <map>
    #include <list>
    #include "politico.h"
    #include "partido.h"

    using namespace std;

    class Eleicao{
        map<int, Partido*> partidos;
        list<Politico*> politicos;

        public:
            Eleicao(map<int, Partido*>, list<Politico*>);
            void libera();
    };
#endif