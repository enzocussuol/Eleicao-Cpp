#ifndef ELEICAO_H_
    #define ELEICAO_H_

    #include <iostream>
    #include <string>
    #include <map>
    #include <list>
    #include "politico.h"
    #include "partido.h"
    #include "leitura.h"
    #include "saida.h"

    using namespace std;

    class Eleicao{
        map<int, Partido*> partidos;
        list<Politico*> politicos;

        int numVagas;

        public:
            Eleicao(Leitura*, char**);
            map<int, Partido*> getPartidos() const;
            list<Politico*> getPoliticos() const;
            void setNumVagas();
            int getNumVagas() const;
            void processaPartidos();
            void ordenaPoliticos();
            void geraRelatorios(Saida*);
            void libera();
    };
#endif