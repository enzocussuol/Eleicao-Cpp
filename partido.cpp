#include "partido.h"

Partido::Partido(const int numero, const int votosLegenda, const string& nome, const string& sigla){
    this->numero = numero;
    this->votosLegenda = votosLegenda;
    this->nome = nome;
    this->sigla = sigla;
}

int Partido::getNumero() const{
    return this->numero;
}

int Partido::getVotosLegenda() const{
    return this->votosLegenda;
}

void Partido::setVotosTotais(){
    int votosNominais = 0;

    for(auto it = this->politicos.begin(); it != this->politicos.end(); ++it){
        votosNominais += (*it)->getVotosNominais();
    }

    this->votosTotais = votosNominais + this->votosLegenda;
}

int Partido::getVotosTotais() const{
    return this->votosTotais;
}

void Partido::setVotosNominais(){
    this->votosNominais = this->votosTotais - this->votosLegenda;
}

int Partido::getVotosNominais() const{
    return this->votosNominais;
}

void Partido::setNumEleitos(){
    this->numEleitos = 0;

    for(auto it = this->politicos.begin(); it != this->politicos.end(); ++it){
        if((*it)->getSituacao().compare("Eleito")) this->numEleitos++;
    }
}

int Partido::getNumEleitos() const{
    return this->numEleitos;
}

string Partido::getNome() const{
    return this->nome;
}

string Partido::getSigla() const{
    return this->sigla;
}

list<Politico*> Partido::getPoliticos() const{
    return this->politicos;
}

Politico* Partido::getPrimeiroColocado() const{
    return this->primeiroColocado;
}

Politico* Partido::getUltimoColocado() const{
    return this->ultimoColocado;
}

void Partido::adicionaPolitico(Politico* politico){
    this->politicos.push_back(politico);
}

void Partido::imprimePartido(){
    cout << this->sigla << " - ";
    cout << this->numero << ", ";
    cout << this->votosTotais << " votos (";
    cout << this->votosNominais << " nominais e ";
    cout << this->votosLegenda << " de legenda), ";
    cout << this->numEleitos << " candidatos eleitos" << endl;
}

void Partido::libera(){
    delete this;
}

bool cmpVotosTotais(Partido* first, Partido* second){
    int diferenca = first->getVotosTotais() - second->getVotosTotais();

    if(diferenca > 0) return true;
    else if(diferenca < 0) return false;
    else{
        if(first->getNumero() > second->getNumero()) return true;
        return false;
    }
}