#include <locale>
#include "politico.h"
#include "partido.h"
#include "leitura.h"
#include "eleicao.h"
#include "saida.h"

using namespace std;

int main(int argc, char* argv[]){
    Leitura* leitura;
    Saida* saida;

    Eleicao* eleicao = new Eleicao(leitura, argv);

    // map<int, Partido*> partidos = eleicao->getPartidos();
    // list<Politico*> politicos = eleicao->getPoliticos();

    // for(auto it = partidos.begin(); it != partidos.end(); ++it){
    //     it->second->imprimePartido();
    // }

    // cout << "===================================================" << endl;

    // for(auto it = politicos.begin(); it != politicos.end(); ++it){
    //     (*it)->imprimePolitico();
    // }

    eleicao->ordenaPoliticos();

    eleicao->setNumVagas();

    eleicao->geraRelatorios(saida);

    eleicao->libera();

    return 0;
}