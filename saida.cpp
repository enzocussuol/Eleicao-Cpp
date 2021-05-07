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

void Saida::geraRelatorio7(list<Partido*> partidos){
    cout << "Primeiro e último colocados de cada partido:" << endl;

    int i = 0;
    for(auto it = partidos.begin(); it != partidos.end(); ++it){
        Politico* primeiroColocado = (*it)->getPrimeiroColocado();
        Politico* ultimoColocado = (*it)->getUltimoColocado();

        if(primeiroColocado == NULL | ultimoColocado == NULL) break;

        int votosPrimeiroColocado = primeiroColocado->getVotosNominais();
        int votosUltimoColocado = ultimoColocado->getVotosNominais();

        if(votosPrimeiroColocado > 0 & votosUltimoColocado > 0){
            cout << i + 1 << " - ";

            cout << (*it)->getSigla() << " - ";
            cout << (*it)->getNumero() << ", ";

            cout << primeiroColocado->getNomeUrna() << " (";
            cout << primeiroColocado->getNumero() << ", ";
            cout << votosPrimeiroColocado << " votos) / ";

            cout << ultimoColocado->getNomeUrna() << " (";
            cout << ultimoColocado->getNumero() << ", ";
            cout << votosUltimoColocado << " votos)" << endl;
        }
        i++;
    }
    cout << endl;
}

void Saida::geraRelatorio8(list<Politico*> politicos, int numVagas){
    cout << "Eleitos, por faixa etária (na data da eleição):" << endl;

    int ate30 = 0;
    int de30ate40 = 0;
    int de40ate50 = 0;
    int de50ate60 = 0;
    int maior60 = 0;

    int i = 0;
    for(auto it = politicos.begin(); i < numVagas; ++it){
        if((*it)->getSituacao().compare("Eleito") == 0){
            int idade = (*it)->getIdade();
            if(idade < 30) ate30++;
            else if(idade >= 30 && idade < 40) de30ate40++;
            else if(idade >= 40 && idade < 50) de40ate50++;
            else if(idade >= 50 && idade < 60) de50ate60++;
            else if(idade >= 60) maior60++;
            
            i++;
        }
    }

    float p1 = (float)ate30/numVagas;
    p1 *= 100;
    float p2 = (float)de30ate40/numVagas;
    p2 *= 100;
    float p3 = (float)de40ate50/numVagas;
    p3 *= 100;
    float p4 = (float)de50ate60/numVagas;
    p4 *= 100;
    float p5 = (float)maior60/numVagas;
    p5 *= 100;

    cout << "      Idade < 30: " << ate30 << " (" << p1 << "%)" << endl;
    cout << "30 <= Idade < 40: " << de30ate40 << " (" << p2 << "%)" << endl;
    cout << "40 <= Idade < 50: " << de40ate50 << " (" << p3 << "%)" << endl;
    cout << "50 <= Idade < 60: " << de50ate60 << " (" << p4 << "%)" << endl;
    cout << "60 <= Idade     : " << maior60 << " (" << p5 << "%)" << endl;

    cout << endl;
}

void Saida::geraRelatorio9(list<Politico*> politicos, int numVagas){
    cout << "Eleitos por sexo:" << endl;

    int feminino = 0;
    int masculino = 0;

    int i = 0;
    for(auto it = politicos.begin(); i < numVagas; ++it){
        if((*it)->getSituacao().compare("Eleito") == 0){
            if((*it)->getSexo() == 'F') feminino++;
            else masculino++;
            
            i++;
        }
    }

    float p1 = (float)feminino/numVagas;
    p1 *= 100;
    float p2 = (float)masculino/numVagas;
    p2 *= 100;

    cout << "Feminino:  " << feminino << " (" << p1 << "%)" << endl;
    cout << "Masculino: " << masculino << " (" << p2 << "%)" << endl;

    cout << endl;
}

void Saida::geraRelatorio10(int votosTotais, int votosNominais, int votosLegenda){
    cout << "Total de votos válidos:    " << votosTotais << endl;

    float p1 = (float)votosNominais/votosTotais;
    p1 *= 100;
    float p2 = (float)votosLegenda/votosTotais;
    p2 *= 100;

    cout << "Total de votos nominais:   " << votosNominais << " (" << p1 << "%)" << endl;
    cout << "Total de votos de Legenda: " << votosLegenda << " (" << p2 << "%)" << endl;
}