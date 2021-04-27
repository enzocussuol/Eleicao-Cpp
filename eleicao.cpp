#include "eleicao.h"

Eleicao::Eleicao(map<int, Partido*> partidos, list<Politico*> politicos){
    this->partidos = partidos;
    this->politicos = politicos;
}