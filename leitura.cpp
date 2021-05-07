#include "leitura.h"

map<int, Partido*> Leitura::lePartidos(string nomeArquivo){
    map<int, Partido*> novoMapa;

    ifstream arquivoPartidos(nomeArquivo);
    if(!arquivoPartidos.is_open()){
        cout << "Erro ao abrir o arquivo de partidos" << endl;
        exit(EXIT_FAILURE);
    }
    
    vector<string> vetPalavras;
    string linha, palavra;
    
    getline(arquivoPartidos, linha);
    while(getline(arquivoPartidos, linha)){
        vetPalavras.clear();
        stringstream aux(linha);

        while(getline(aux, palavra, ',')){
            vetPalavras.push_back(palavra);
        }

        Partido* novoPartido = new Partido(stoi(vetPalavras[0]), stoi(vetPalavras[1]), regex_replace(vetPalavras[2], regex("^ +| +$|( ) +"), "$1"), regex_replace(vetPalavras[3], regex("^ +| +$|( ) +"), "$1"));

        novoMapa.insert({novoPartido->getNumero(), novoPartido});
    }
    
    return novoMapa;
}

list<Politico*> Leitura::lePoliticos(map<int, Partido*> partidos, string nomeArquivo, string dataEleicao){
    list<Politico*> novaLista;

    ifstream arquivoPoliticos(nomeArquivo);
    if(!arquivoPoliticos.is_open()){
        cout << "Erro ao abrir o arquivo de politicos" << endl;
        exit(EXIT_FAILURE);
    }

    vector<string> vetPalavras;
    string linha, palavra;

    getline(arquivoPoliticos, linha);
    while(getline(arquivoPoliticos, linha)){
        vetPalavras.clear();
        stringstream aux(linha);

        while(getline(aux, palavra, ',')){
            vetPalavras.push_back(palavra);
        }

        if(vetPalavras[7].compare("Válido") == 0){
            Politico* novoPolitico = new Politico(stoi(vetPalavras[0]),
                                                stoi(vetPalavras[1]),
                                                regex_replace(vetPalavras[2], regex("^ +| +$|( ) +"), "$1"),
                                                regex_replace(vetPalavras[3], regex("^ +| +$|( ) +"), "$1"),
                                                regex_replace(vetPalavras[4], regex("^ +| +$|( ) +"), "$1"),
                                                vetPalavras[5].at(0),
                                                regex_replace(vetPalavras[7], regex("^ +| +$|( ) +"), "$1"),
                                                stoi(vetPalavras[8]));
            novoPolitico->setIdade(dataEleicao, vetPalavras[6]);

            novaLista.push_back(novoPolitico);

            Partido* partido = partidos.find(novoPolitico->getPartido())->second;
            partido->adicionaPolitico(novoPolitico);
        }
    }

    return novaLista;
}