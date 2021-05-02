#include "politico.h"
#include "partido.h"
#include "leitura.h"
#include "eleicao.h"
#include "saida.h"

using namespace std;

int main(int argc, char* argv[]){
    Leitura* leitura;
    Saida* saida;
    
    map<int, Partido*> partidos = leitura->lePartidos(argv[2]);
    list<Politico*> politicos = leitura->lePoliticos(partidos, argv[1]);

    Eleicao* eleicao = new Eleicao(partidos, politicos);

    eleicao->libera();

    return 0;
}