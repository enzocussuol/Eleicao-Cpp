#ifndef PARTIDO_H_
    #define PARTIDO_H_

    class Partido;

    #include <iostream>
    #include <string>
    #include <list>
    #include "politico.h"

    using namespace std;

    class Partido{
        int numero;
        int votosLegenda;
        int votosTotais;
        int votosNominais;
        int numEleitos;
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
            void setVotosTotais();
            int getVotosTotais() const;
            void setVotosNominais();
            int getVotosNominais() const;
            void setNumEleitos();
            int getNumEleitos() const;
            string getNome() const;
            string getSigla() const;
            list<Politico*> getPoliticos() const;
            Politico* getPrimeiroColocado() const;
            Politico* getUltimoColocado() const;
            void adicionaPolitico(Politico*);
            void imprimePartido();
            void libera();
    };

    bool cmpVotosTotais(Partido*, Partido*);
#endif