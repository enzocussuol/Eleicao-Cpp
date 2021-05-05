#ifndef LEITURA_H_
    #define LEITURA_H_

    #include <iostream>
    #include <fstream>
    #include <sstream>
    #include <string>
    #include <map>
    #include <list>
    #include "politico.h"
    #include "partido.h"
    
    using namespace std;

    class Leitura{
        public:
            int calculaIdade(string dataeleicao, string datanascimento);
            map<int, Partido*> lePartidos(string arquivo);
            list<Politico*> lePoliticos(map<int, Partido*> partidos, string arquivo, string dataeleicao);
    };
#endif