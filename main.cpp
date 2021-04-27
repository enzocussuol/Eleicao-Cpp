#include "politico.h"
#include "partido.h"
#include "leitura.h"
#include "eleicao.h"
#include "saida.h"

using namespace std;

int main(int argc, char* argv[]){
    Leitura* leitura;
    Saida* saida;

    Eleicao* eleicao = new Eleicao(leitura->lePartidos(argv[1]), leitura->lePoliticos(argv[2]));

    return 0;
}