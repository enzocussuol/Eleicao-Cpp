#include "eleicao.h"

Eleicao::Eleicao(Leitura* leitura, char** argv){
    this->partidos = leitura->lePartidos(argv[2]);
    this->politicos = leitura->lePoliticos(partidos, argv[1], argv[3]);
}

map<int, Partido*> Eleicao::getPartidos() const{
    return this->partidos;
}

list<Politico*> Eleicao::getPoliticos() const{
    return this->politicos;
}

void Eleicao::setNumVagas(){
    int numVagas = 0;

    for(auto it = this->politicos.begin(); it != this->politicos.end(); ++it){
        if((*it)->getSituacao().compare("Eleito") == 0){
            numVagas++;
        }
    }

    this->numVagas = numVagas;
}

int Eleicao::getNumVagas() const{
    return this->numVagas;
}

void Eleicao::processaPartidos(){
    for(auto it = this->partidos.begin(); it != this->partidos.end(); ++it){
        it->second->setVotosTotais();
        it->second->setVotosNominais();
        it->second->setNumEleitos();
    }
}

void Eleicao::ordenaPoliticos(){
    this->politicos.sort(cmpVotosNominais);
}

static void ordenaPartidos(list<Partido*>& partidos){
    partidos.sort(cmpVotosTotais);
}

static list<Partido*> preencheLista(map<int, Partido*> partidos){
    list<Partido*> novaLista;

    for(auto it = partidos.begin(); it != partidos.end(); ++it){
        novaLista.push_back(it->second);
    }

    return novaLista;
}

void Eleicao::geraRelatorios(Saida* saida){
    this->ordenaPoliticos();

    saida->geraRelatorio1(this->numVagas);
    saida->geraRelatorio2(this->politicos, this->partidos, this->numVagas);
    saida->geraRelatorio3(this->politicos, this->partidos, this->numVagas);
    saida->geraRelatorio4(this->politicos, this->partidos, this->numVagas);
    saida->geraRelatorio5(this->politicos, this->partidos, this->numVagas);

    list<Partido*> partidos = preencheLista(this->partidos);

    ordenaPartidos(partidos);

    saida->geraRelatorio6(partidos);
}

void Eleicao::libera(){
    for(auto it = this->partidos.begin(); it != this->partidos.end(); ++it){
        it->second->libera();
    }

    for(auto it = this->politicos.begin(); it != this->politicos.end(); ++it){
        (*it)->libera();
    }

    delete this;
}