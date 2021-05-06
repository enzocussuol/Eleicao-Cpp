#include "politico.h"

Politico::Politico(const int numero, const int votosNominais, const string &situacao, const string &nome, const string &nomeUrna, const int sexo, const string &destinoVoto, const int partido){
    this->numero = numero;
    this->votosNominais = votosNominais;
    this->situacao = situacao;
    this->nome = nome;
    this->nomeUrna = nomeUrna;
    this->sexo = sexo;
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

void Politico::setIdade(string dataeleicao, string datanasc){
    string aux;

    vector<int> veteleicao;
    stringstream elect(dataeleicao);
    while(getline(elect, aux, '/')){
        veteleicao.push_back(stoi(aux));
    }

    vector<int> vetnascimento;
    stringstream nasc(datanasc);
    while(getline(nasc, aux, '/')){
        vetnascimento.push_back(stoi(aux));
    }

    int idade = veteleicao[2] - vetnascimento[2] - 1;
    if(vetnascimento[1] < veteleicao[1]){
        idade += 1;
    }else if(vetnascimento[1] == veteleicao[1] && vetnascimento[0] < veteleicao[0]){
        idade += 1;
    }

    this->idade = idade;
}

int Politico::getIdade() const{
    return this->idade;
}

string Politico::getDestinoVoto() const{
    return this->destinoVoto;
}

int Politico::getPartido() const{
    return this->partido;
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
        if(first->getIdade() > second->getIdade()) return true;
        return false;
    }
}