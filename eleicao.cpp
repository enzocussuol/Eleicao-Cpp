#include "eleicao.h"

Eleicao::Eleicao(map<int, Partido*> partidos, list<Politico*> politicos){
    this->partidos = partidos;
    this->politicos = politicos;
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