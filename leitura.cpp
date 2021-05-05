#include "leitura.h"


int Leitura::calculaIdade(string dataeleicao, string datanasc){
    string aux;

    vector<int> veteleicao;
    stringstream elect(dataeleicao);
    while(getline(elect, aux, '/')){
        veteleicao.push_back(stoi(aux));
    }

    vector<int> vetnascimento;
    stringstream nasc(datanasc);
    while(getline(nasc, aux, '/')){
        vetnascimento.push_back(stoi(aux));
    }

    int idade = veteleicao[2] - vetnascimento[2] - 1;
    if(vetnascimento[1] < veteleicao[1]){
        idade += 1;
    }else if(vetnascimento[1] == veteleicao[1] && vetnascimento[0] < veteleicao[0]){
        idade += 1;
    }

    return idade;
}

map<int, Partido*> Leitura::lePartidos(string arquivo){
    map<int, Partido*> novoMapa;

    ifstream arquivoPartidos(arquivo);

    vector<string> vetPalavras;
    string linha, palavra;
    
    getline(arquivoPartidos, linha);
    while(getline(arquivoPartidos, linha)){
        stringstream aux(linha);
        vetPalavras.clear();

        while(getline(aux, palavra, ',')){
            vetPalavras.push_back(palavra);
        }

        Partido* novoPartido = new Partido(stoi(vetPalavras[0]), stoi(vetPalavras[1]), vetPalavras[2], vetPalavras[3]);

        novoMapa.insert({novoPartido->getNumero(), novoPartido});
    }

    return novoMapa;
}

list<Politico*> Leitura::lePoliticos(map<int, Partido*> partidos, string arquivo, string dataeleicao){
    list<Politico*> novaLista;

    ifstream arquivoPoliticos(arquivo);
    
    vector<string> vetPalavras;
    string linha, palavra;
    
    getline(arquivoPoliticos, linha);
    while(getline(arquivoPoliticos, linha)){
        stringstream aux(linha);
        vetPalavras.clear();

        while(getline(aux, palavra, ',')){
            vetPalavras.push_back(palavra);
        }

        if(vetPalavras[7].compare("Válido") == 0){
            Politico* novoPolitico = new Politico(stoi(vetPalavras[0]), stoi(vetPalavras[1]),
                                                vetPalavras[2],vetPalavras[3],
                                                vetPalavras[4],vetPalavras[5].at(0),
                                                calculaIdade(dataeleicao, vetPalavras[6]),vetPalavras[7], 
                                                stoi(vetPalavras[8]));
            novaLista.push_back(novoPolitico);

            Partido* partido = partidos.find(novoPolitico->getPartido())->second;
            partido->adicionaPolitico(novoPolitico);
        }
    }

    return novaLista;
}