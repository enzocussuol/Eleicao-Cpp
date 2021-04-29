#include "leitura.h"

map<int, Partido*> Leitura::lePartidos(string arquivo){
    map<int, Partido*> novoMapa;

    cout << "Ainda irei implementar a leitura dos partidos" << endl;

    return novoMapa;
}

list<Politico*> Leitura::lePoliticos(string arquivo){
    cout << arquivo << endl;

    list<Politico*> novaLista;

    ifstream arquivoPoliticos(arquivo);
    
    vector<string> vetpalavras;
    string linha, palavra, temp;
    
    int i = 0;

    getline(arquivoPoliticos, linha); //retirar lixo 
    while(getline(arquivoPoliticos, linha)){
        stringstream aux(linha);
        //cout << i << endl;
        vetpalavras.clear();

        //cout << linha << endl;

        while(getline(aux, palavra, ',')){
            vetpalavras.push_back(palavra);
            //cout << palavra << endl;
        }

        //Politico* novoPolitico = new Politico(vetpalavras);
        Politico* novoPolitico = new Politico(stoi(vetpalavras[0]), stoi(vetpalavras[1]),vetpalavras[2],vetpalavras[3],vetpalavras[4],vetpalavras[5].at(0),vetpalavras[6],vetpalavras[7], stoi(vetpalavras[8]));
        //novoPolitico->imprimePolitico();
        
        novaLista.push_back(novoPolitico);
        i++;
    }

    //cout << "Ainda irei implementar a leitura dos politicos" << endl;

    return novaLista;
}