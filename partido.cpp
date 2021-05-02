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
    cout << this->nome << endl;
    cout << "Politicos desse partido:" << endl;

    for(auto it = this->politicos.begin(); it != this->politicos.end(); ++it){
        (*it)->imprimePolitico();
    }
}

void Partido::libera(){
    delete this;
}