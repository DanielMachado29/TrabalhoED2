#include "Ordenadores.h"
#include <random>
#include <chrono>

using namespace std;
Ordenadores::Ordenadores()
{
    quantidadeComparacoes = 0;
    quantidadeTrocas = 0;
}

Ordenadores::~Ordenadores() {}

void Ordenadores::intercalaPreProcessamento(Registro *registros, int inicio, int meio, int fim)
{

    int i, j, k;
    //tamanho do registro temp
    int tamVetL = meio - inicio + 1;
    int tamVetR = fim - meio;

    Registro *L = new Registro[tamVetL];
    Registro *R = new Registro[tamVetR];

    //copia para os vetores de regristro temp
    for (i = 0; i < tamVetL; i++)
        L[i] = registros[inicio + i];
    for (j = 0; j < tamVetR; j++)
        R[j] = registros[meio + 1 + j];

    //Junta os vetores temporarios no vetor principal
    i = 0;
    j = 0;
    k = inicio; // index  p fazer merge

    while (i < tamVetL && j < tamVetR)
    {
        // se estado de L vier antes do estado de R
        quantidadeComparacoes++;
        if (L[i].getEstado() < R[j].getEstado())
        {
            quantidadeTrocas++;
            registros[k] = L[i];
            i++;
            k++;
            continue;
        }
        quantidadeComparacoes++;
        if (L[i].getEstado() == R[j].getEstado())
        {
            if (L[i].getCidade() < R[j].getCidade())
            {
                quantidadeTrocas++;
                registros[k] = L[i];
                i++;
                k++;
                continue;
            }
        }
        quantidadeComparacoes++;
        if (L[i].getEstado() == R[j].getEstado() && L[i].getCidade() == R[j].getCidade())
        {
            if (L[i].getDataCompleta() < R[j].getDataCompleta())
            {
                quantidadeTrocas++;
                registros[k] = L[i];
                i++;
                k++;
                continue;
            }
        }
        quantidadeTrocas++;
        registros[k] = R[j];
        j++;
        k++;
    }

    while (i < tamVetL)
    {
        quantidadeTrocas++;
        registros[k] = L[i];
        i++;
        k++;
    }
    while (j < tamVetR)
    {
        quantidadeTrocas++;
        registros[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void Ordenadores::mergeSortPreProcessamento(Registro *registros, int indexInicio, int indexFim)
{

    if (indexFim > indexInicio)
    {
        int meio = (indexInicio + indexFim) / 2;  // pega o meio como parametro de index para as duas metades
        mergeSortPreProcessamento(registros, indexInicio, meio);  // na primeira metade ele vira o indexFim
        mergeSortPreProcessamento(registros, meio + 1, indexFim); //na segunda metade ele+1 vira o indexInicio
        intercalaPreProcessamento(registros, indexInicio, meio, indexFim);
    }
    else
        return;
}

void Ordenadores::intercala(Registro *registros, int inicio, int meio, int fim)
{

    int i, j, k;
    //tamanho do registro temp
    int tamVetL = meio - inicio + 1;
    int tamVetR = fim - meio;

    Registro *L = new Registro[tamVetL];
    Registro *R = new Registro[tamVetR];

    //copia para os vetores de regristro temp
    for (i = 0; i < tamVetL; i++)
        L[i] = registros[inicio + i];
    for (j = 0; j < tamVetR; j++)
        R[j] = registros[meio + 1 + j];

    //Junta os vetores temporarios no vetor principal
    i = 0;
    j = 0;
    k = inicio; // index  p fazer merge

    while (i < tamVetL && j < tamVetR)
    {
        // se estado de L vier antes do estado de R
        quantidadeComparacoes++;
        if (L[i].getCasos() < R[j].getCasos())
        {
            quantidadeTrocas++;
            registros[k] = L[i];
            i++;
            k++;
            continue;
        }
        else{
            quantidadeTrocas++;
            registros[k] = R[j];
            j++;
            k++;
        }
        
    }

    while (i < tamVetL)
    {
        quantidadeTrocas++;
        registros[k] = L[i];
        i++;
        k++;
    }
    while (j < tamVetR)
    {
        quantidadeTrocas++;
        registros[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void Ordenadores::mergeSort(Registro *registros, int indexInicio, int indexFim)
{

    if (indexFim > indexInicio)
    {
        int meio = (indexInicio + indexFim) / 2;  // pega o meio como parametro de index para as duas metades
        mergeSort(registros, indexInicio, meio);  // na primeira metade ele vira o indexFim
        mergeSort(registros, meio + 1, indexFim); //na segunda metade ele+1 vira o indexInicio
        intercala(registros, indexInicio, meio, indexFim);
    }
    else
        return;
}

void Ordenadores::quickSort(Registro *registros, int inicio, int fim)
{
    int i, j;
    i = inicio;
    j = fim - 1;
    int meio = (inicio + fim) / 2;

    Registro a = registros[inicio];
    Registro b = registros[meio];
    Registro c = registros[fim];
    int medianaIndice;
    quantidadeComparacoes++;
    if (a.getCasos() < b.getCasos())
    {
        quantidadeComparacoes++;
        if (b.getCasos() < c.getCasos())
        {
            //a < b && b < c
            medianaIndice = meio;
        }
        else
        {       quantidadeComparacoes++;
            if (a.getCasos() < c.getCasos())
            {
                //a < c && c <= b
                medianaIndice = fim;
            }
            else
            {
                //c <= a && a < b
                medianaIndice = inicio;
            }
        }
    }
    else
    {   quantidadeComparacoes++;
        if (c.getCasos() < b.getCasos())
        {
            //c < b && b <= a
            medianaIndice = meio;
        }
        else
        {   quantidadeComparacoes++;
            if (c.getCasos() < a.getCasos())
            {
                //b <= c && c < a
                medianaIndice = fim;
            }
            else
            {
                //b <= a && a <= c
                medianaIndice = inicio;
            }
        }
    }

    Registro pivo = registros[medianaIndice];

    while (i <= j)
    {   quantidadeComparacoes++;
        while (registros[i].getCasos() < pivo.getCasos() && i < fim)
        {
            i++;
        }
        while (registros[j].getCasos() > pivo.getCasos() && j > inicio)
        {
            j--;
        }
        if (i <= j)
        {
            quantidadeTrocas++;
            swap(registros[i], registros[j]);
            i++;
            j--;
        }
    }
    if (j > inicio)
        quickSort(registros, inicio, j + 1);
    if (i < fim)
        quickSort(registros, i, fim);
}

void Ordenadores::shellSort(Registro *registros, int n)
{
    for (int zap = n / 2; zap > 0; zap /= 2)
    {
        for (int i = zap; i < n; i += 1)
        {
            quantidadeTrocas++;
            Registro temp = registros[i];
            int j;
            for (j = i; j >= zap && registros[j - zap].getCasos() > temp.getCasos(); j -= zap)
            {
                quantidadeComparacoes++;
                quantidadeTrocas++;
                registros[j] = registros[j - zap];
            }
            registros[j] = temp;
        }
    }
}