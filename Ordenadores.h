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
    void mergeSortPreProcessamento(Registro *registros, int inicio, int fim);
    void intercalaPreProcessamento(Registro *registros, int inicio, int meio, int fim);
    void mergeSort(Registro *registros, int inicio, int fim);
    void intercala(Registro *registros, int inicio, int meio, int fim);
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
    

private:
    unsigned long int quantidadeComparacoes;
    unsigned long int quantidadeTrocas;
};

#endif
