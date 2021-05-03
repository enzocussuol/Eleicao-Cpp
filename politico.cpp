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

void Politico::imprimePoliticoOriginal() const{
    cout << this->numero << ",";
    cout << this->votosNominais << ",";
    cout << this->situacao << ",";
    cout << this->nome << ",";
    cout << this->nomeUrna << ",";
    cout << this->sexo << ",";
    cout << "DATA" << ",";
    cout << this->destinoVoto << ",";
    cout << this->partido << endl;
}

void Politico::imprimePolitico(map<int, Partido*> partidos) const{
    cout << this->nome << " / ";
    cout << this->nomeUrna << " (";
    cout << partidos.find(this->partido)->second->getNome() << ", ";
    cout << this->votosNominais << " votos)" << endl;
}

void Politico::libera(){
    delete this;
}

bool cmpVotosNominais(Politico* first, Politico* second){
    int diferenca = first->getVotosNominais() - second->getVotosNominais();

    if(diferenca > 0) return true;
    else if(diferenca < 0) return false;
    else{
        // Implementar desempate com a idade dos politicos!
        return true; // (so pra tirar warning do compilador enquanto n implementa data)
    }
}