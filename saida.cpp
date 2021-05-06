#include "saida.h"

void Saida::geraRelatorio1(int numVagas){
    cout << "Número de vagas: " << numVagas << endl << endl;
}

void Saida::geraRelatorio2(list<Politico*> politicos, map<int, Partido*> partidos, int numVagas){
    cout << "Vereadores eleitos:" << endl;
    
    int i = 0;
    for(auto it = politicos.begin(); i < numVagas; ++it){
        if((*it)->getSituacao().compare("Eleito") == 0){
            cout << i + 1 << " - ";
            (*it)->imprimePolitico(partidos);
            i++;
        }
    }
    cout << endl;
}

void Saida::geraRelatorio3(list<Politico*> politicos, map<int, Partido*> partidos, int numVagas){
    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;

    int i = 0;
    for(auto it = politicos.begin(); i < numVagas; ++it){
        cout << i + 1 << " - ";
        (*it)->imprimePolitico(partidos);
        i++;
    }
    cout << endl;
}