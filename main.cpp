#include <locale>
#include <iomanip>
#include "politico.h"
#include "partido.h"
#include "leitura.h"
#include "eleicao.h"
#include "saida.h"

using namespace std;

int main(int argc, char** argv){
    locale localidade("pt_BR.UTF-8");
    cout.imbue(localidade);
    cout << fixed << setprecision(2);

    Leitura leitura;
    Saida saida;

    Eleicao* eleicao = new Eleicao(leitura, argv);

    eleicao->setNumVagas();
    
    eleicao->processaDadosPartidos();

    eleicao->setVotosTotais();
    eleicao->setVotosNominais();
    eleicao->setVotosLegenda();

    eleicao->geraRelatorios(saida);

    eleicao->libera();

    cout.imbue(locale());

    return 0;
}