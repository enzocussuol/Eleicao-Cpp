#include "politico.h"

Politico::Politico(const int numero, const int votosNominais,const string &situacao,const string &nome,const string &nomeUrna, const int sexo,const string data,const string &destinoVoto,const int partido){
    this->numero = numero;
    this->votosNominais = votosNominais;
    this->situacao = situacao;
    this->nome = nome;
    this->nomeUrna = nomeUrna;
    this->sexo = sexo;
    //this->data =  vetcaracteristicas[6];
    this->destinoVoto = destinoVoto;
    this->partido = partido;
}

int Politico::getNumero()const{
    return this->numero;
}
int Politico::getVotosNominais() const{
    return this->votosNominais;
}
string Politico::getSituacao() const{
    return this->situacao;
}
string Politico::getNome() const{
    return this->nome;
}
string Politico::getNomeUrna() const{
    return this->nomeUrna;
}
int Politico::getSexo() const{
    return this->sexo;
}

// struct Politico::getData() const;
string Politico::getDestinoVoto() const{
    return this->destinoVoto;
}

int Politico::getPartido() const{
    return this->partido;
}

void Politico::imprimePolitico() const{
    cout << this->nome << endl;
}

void Politico::libera(){
    delete this;
}

bool comparePoliticoPartido(const Politico* first, const Politico* second){
  return first->getNumero() <= second->getNumero();
}

bool comparePoliticoVotos(const Politico* first, const Politico* second){
  return first->getVotosNominais() >= second->getVotosNominais();
}