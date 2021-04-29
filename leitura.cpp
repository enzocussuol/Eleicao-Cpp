#include "leitura.h"

map<int, Partido*> Leitura::lePartidos(string arquivo){
    map<int, Partido*> novoMapa;

    cout << "Ainda irei implementar a leitura dos partidos" << endl;

    return novoMapa;
}

list<Politico*> Leitura::lePoliticos(string arquivo){
    list<Politico*> novaLista;

    fstream fin;
    fin.open(arquivo, ios::in);
    
    vector<string> row;
    string line, word, temp;
    
    int i = 0;

    while(fin >> temp){
        row.clear();

        getline(fin, line);
        stringstream s(line);
        while(getline(s, word, ', ')){
            row.push_back(word);
        }
        cout << row[0];
        //novaLista[i] inserir
        
        i++;
    }


    cout << "Ainda irei implementar a leitura dos politicos" << endl;

    return novaLista;
}