#include "leitura.h"

map<int, Partido*> Leitura::lePartidos(string nomeArquivo){
    cout << nomeArquivo << endl;

    map<int, Partido*> novoMapa;

    ifstream arquivoPartidos;

    arquivoPartidos.exceptions(ifstream::badbit | ifstream::failbit);

    try{
        arquivoPartidos.open(nomeArquivo);

        vector<string> vetPalavras;
        string linha, palavra;
        
        getline(arquivoPartidos, linha);
        while(getline(arquivoPartidos, linha)){
            stringstream aux(linha);

            while(getline(aux, palavra, ',')){
                vetPalavras.push_back(palavra);
            }

            Partido* novoPartido = new Partido(stoi(vetPalavras[0]), stoi(vetPalavras[1]), vetPalavras[2], vetPalavras[3]);

            novoMapa.insert({novoPartido->getNumero(), novoPartido});
            vetPalavras.clear();
        }
        
        arquivoPartidos.close();
    }catch(ifstream::failure falha){
        cerr << "Excessao durante abertura/leitura/fechamento do arquivo de partidos" << endl;
        exit(EXIT_FAILURE);
    }

    return novoMapa;
}

list<Politico*> Leitura::lePoliticos(map<int, Partido*> partidos, string nomeArquivo, string dataEleicao){
    list<Politico*> novaLista;

    ifstream arquivoPoliticos;

    arquivoPoliticos.exceptions(ifstream::badbit | ifstream::failbit);

    try{
        arquivoPoliticos.open(nomeArquivo);

        vector<string> vetPalavras;
        string linha, palavra;

        getline(arquivoPoliticos, linha);
        while(getline(arquivoPoliticos, linha)){
            stringstream aux(linha);

            while(getline(aux, palavra, ',')){
                vetPalavras.push_back(palavra);
            }

            if(vetPalavras[7].compare("Válido") == 0){
                Politico* novoPolitico = new Politico(stoi(vetPalavras[0]), stoi(vetPalavras[1]),
                                                    vetPalavras[2],vetPalavras[3],
                                                    vetPalavras[4],vetPalavras[5].at(0),
                                                    vetPalavras[7], stoi(vetPalavras[8]));
                novoPolitico->setIdade(dataEleicao, vetPalavras[6]);

                novaLista.push_back(novoPolitico);

                Partido* partido = partidos.find(novoPolitico->getPartido())->second;
                partido->adicionaPolitico(novoPolitico);
                vetPalavras.clear();
            }
        }

        arquivoPoliticos.close();
    }catch(ifstream::failure falha){
        cerr << "Excessao durante abertura/leitura/fechamento do arquivo de politicos" << endl;
        exit(EXIT_FAILURE);
    }

    return novaLista;
}