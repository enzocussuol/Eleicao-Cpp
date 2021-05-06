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

void Eleicao::ordenaPoliticos(){
    this->politicos.sort(cmpVotosNominais);
}

void Eleicao::geraRelatorios(Saida* saida){
    saida->geraRelatorio1(this->numVagas);
    saida->geraRelatorio2(this->politicos, this->partidos, this->numVagas);
    saida->geraRelatorio3(this->politicos, this->partidos, this->numVagas);
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