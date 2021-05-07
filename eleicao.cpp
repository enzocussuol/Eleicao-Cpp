#include "eleicao.h"

Eleicao::Eleicao(Leitura leitura, char** argv){
    this->partidos = leitura.lePartidos(argv[2]);
    this->politicos = leitura.lePoliticos(partidos, argv[1], argv[3]);
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

void Eleicao::setVotosTotais(){
    this->votosTotais = 0;

    for(auto it = this->partidos.begin(); it != this->partidos.end(); ++it){
        this->votosTotais += it->second->getVotosTotais();
    }
}

int Eleicao::getVotosTotais() const{
    return this->votosTotais;
}

void Eleicao::setVotosNominais(){
    this->votosNominais = 0;

    for(auto it = this->partidos.begin(); it != this->partidos.end(); ++it){
        this->votosNominais += it->second->getVotosNominais();
    }
}

int Eleicao::getVotosNominais() const{
    return this->votosNominais;
}

void Eleicao::setVotosLegenda(){
    this->votosLegenda = this->votosTotais - this->votosNominais;
}

int Eleicao::getVotosLegenda() const{
    return this->votosLegenda;
}

void Eleicao::processaDadosPartidos(){
    for(auto it = this->partidos.begin(); it != this->partidos.end(); ++it){
        it->second->setVotosTotais();
        it->second->setVotosNominais();
        it->second->setNumEleitos();
        it->second->setPrimeiroColocado();
        it->second->setUltimoColocado();
    }
}

void Eleicao::ordenaPoliticos(){
    this->politicos.sort(cmpVotosNominais);
}

static void ordenaPartidos(list<Partido*>& partidos, bool (*f)(Partido*, Partido*)){
    partidos.sort(f);
}

static list<Partido*> preencheLista(map<int, Partido*> partidos){
    list<Partido*> novaLista;

    for(auto it = partidos.begin(); it != partidos.end(); ++it){
        novaLista.push_back(it->second);
    }

    return novaLista;
}

void Eleicao::geraRelatorios(Saida saida){
    this->ordenaPoliticos();

    saida.geraRelatorio1(this->numVagas);
    saida.geraRelatorio2(this->politicos, this->partidos, this->numVagas);
    saida.geraRelatorio3(this->politicos, this->partidos, this->numVagas);
    saida.geraRelatorio4(this->politicos, this->partidos, this->numVagas);
    saida.geraRelatorio5(this->politicos, this->partidos, this->numVagas);

    list<Partido*> partidos = preencheLista(this->partidos);

    ordenaPartidos(partidos, cmpVotosTotais);

    saida.geraRelatorio6(partidos);

    ordenaPartidos(partidos, cmpPrimeirosColocados);

    saida.geraRelatorio7(partidos);
    saida.geraRelatorio8(this->politicos, this->numVagas);
    saida.geraRelatorio9(this->politicos, this->numVagas);
    saida.geraRelatorio10(this->votosTotais, this->votosNominais, this->votosLegenda);
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