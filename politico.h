#ifndef POLITICO_H_
    #define POLITICO_H_

    #include <iostream>
    #include <string>
    #include <vector>
    using namespace std;

    class Politico{
        private:
            int numero;
            int votosNominais;
            string situacao;
            string nome;
            string nomeUrna;
            char sexo;
            // Data
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
                    const string data,
                    const string &destinoVoto,
                    const int partido);
            
            int getNumero() const;
            int getVotosNominais() const;
            string getSituacao() const;
            string getNome() const;
            string getNomeUrna() const;
            int getSexo() const;
            // struct getData() const;
            string getDestinoVoto() const;
            int getPartido() const;
    
            void imprimePolitico() const;
    };
    
    bool comparePoliticoVotos(const Politico* first, const Politico* second);
    bool comparePoliticoPartido(const Politico* first, const Politico* second);

#endif