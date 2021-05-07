#ifndef POLITICO_H_
    #define POLITICO_H_

    class Politico;

    #include <iostream>
    #include <sstream>
    #include <string>
    #include <vector>
    #include <map>
    #include "partido.h"

    using namespace std;

    class Politico{
        int numero;
        int votosNominais;
        string situacao;
        string nome;
        string nomeUrna;
        char sexo;
        int idade;
        string destinoVoto;
        int partido;

        public:
            Politico(const vector<string> vetcaracteristicas);
            Politico(const int numero,
                    const int votosNominais,
                    const string &situacao,
                    const string &nome,
                    const string &nomeUrna,
                    const int sexo,
                    const string &destinoVoto,
                    const int partido);
            int getNumero() const;
            int getVotosNominais() const;
            string getSituacao() const;
            string getNome() const;
            string getNomeUrna() const;
            int getSexo() const;
            void setIdade(string, string);
            int getIdade() const;
            string getDestinoVoto() const;
            int getPartido() const;
            void imprimePoliticoOriginal() const;
            void imprimePolitico(map<int, Partido*>) const;
            void libera();
    };

    bool cmpVotosNominais(Politico*, Politico*);
#endif