#include "politico.h"
#include "partido.h"
#include "leitura.h"
#include "eleicao.h"
#include "saida.h"

using namespace std;

int main(int argc, char* argv[]){
    Leitura* leitura;
    Saida* saida;

    cout << teste << endl;
    
    list<Politico*> politicos = leitura->lePoliticos(argv[1]);

    politicos.sort(comparePoliticoVotos);


    for(auto it = politicos.begin(); it != politicos.end(); ++it){
        (*it)->imprimePolitico();
    }
    //Eleicao* eleicao = new Eleicao(leitura->lePartidos(argv[1]), leitura->lePoliticos(argv[2]));

    //geraRelatorios(eleicao);

    return 0;
}