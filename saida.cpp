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

void Saida::geraRelatorio4(list<Politico*> politicos, map<int, Partido*> partidos, int numVagas){
    cout << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;
    
    int i = 0;
    for(auto it = politicos.begin(); i < numVagas; ++it){
        if((*it)->getSituacao().compare("Eleito") != 0){
            cout << i + 1 << " - ";
            (*it)->imprimePolitico(partidos);
        }
        i++;
    }
    cout << endl;
}

void Saida::geraRelatorio5(list<Politico*> politicos, map<int, Partido*> partidos, int numVagas){
    cout << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;
    
    int i = 0;
    for(auto it = politicos.begin(); it != politicos.end(); ++it){
        if((*it)->getSituacao().compare("Eleito") == 0 & i > numVagas){
            cout << i + 1 << " - ";
            (*it)->imprimePolitico(partidos);
        }
        i++;
    }
    cout << endl;
}

void Saida::geraRelatorio6(list<Partido*> partidos){
    cout << "Votação dos partidos e número de candidatos eleitos:" << endl;

    int i = 0;
    for(auto it = partidos.begin(); it != partidos.end(); ++it){
        cout << i + 1 << " - ";
        (*it)->imprimePartido();
        i++;
    }
    cout << endl;
}