#ifndef ORDENADORES_H_INCLUDED
#define ORDENADORES_H_INCLUDED
#include "Registro.h"
#include <chrono>
using namespace std;

class Ordenadores
{
public:
    Ordenadores();
    ~Ordenadores();
    void mergeSort(Registro *registros, int inicio, int fim);
    void intercala(Registro *registros, int inicio, int meio, int fim);
    void heapSort(Registro *registros, int n);
    void heapify(Registro *registros, int n, int i);
    void quickSort(Registro *registros, int inicio, int fim);
    void shellSort(Registro *registros, int n);

    unsigned long int getQuantidadeTrocas()
    {
        return quantidadeTrocas;
    }
    unsigned long int getQuantidadeComparacoes()
    {
        return quantidadeComparacoes;
    }
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count(); //gerando numero aleatorio vai precisar dps

private:
    unsigned long int quantidadeComparacoes;
    unsigned long int quantidadeTrocas;
};

#endif
