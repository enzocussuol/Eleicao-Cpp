#ifndef PARTIDO_H_
    #define PARTIDO_H_

    #include <iostream>
    #include <string>
    #include <list>
    #include "politico.h"

    using namespace std;

    class Partido{
        int numero;
        int votosLegenda;
        string nome;
        string sigla;
        list<Politico*> politicos;
        Politico* primeiroColocado;
        Politico* ultimoColocado;

        public:
            Partido(const int, const int, 
                    const string&, const string&);
            int getNumero() const;
            int getVotosLegenda() const;
            string getNome() const;
            string getSigla() const;
            list<Politico*> getPoliticos() const;
            Politico* getPrimeiroColocado() const;
            Politico* getUltimoColocado() const;
            void adicionaPolitico(Politico*);
            void imprimePartido();
            void libera();
    };
#endif