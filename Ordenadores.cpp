#include "Ordenadores.h"
using namespace std;
#include <random>
#include <chrono>
Ordenadores::Ordenadores()
{
    quantidadeComparacoes = 0;
    quantidadeTrocas =0;
}

Ordenadores::~Ordenadores() {}

void Ordenadores::intercala(Registro* registros,int inicio, int meio, int fim)
{
    //int numComparacao, numTroca;//
    int i,j,k;
    int n1 = meio-inicio+1; //tamanho do vetor temporario L
    int n2 = fim - meio; //tamanho do vetor temporario R

    // cria vetores temporarios
    Registro * L = new Registro[n1];
    Registro * R = new Registro[n2];


    //copia os dados para as arrays L e R
    for (i = 0; i < n1; i++)
        L[i] = registros[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = registros[meio + 1 + j];

    //Junta os vetores temporarios no vetor principal
    i = 0; // index inicial para a primeira subarray
    j = 0; // index inicial para a segunda subarray
    k = inicio; // index inicial para a merge subarray
    while (i < n1 && j < n2)
    {
        //numComparacao++;
        if (L[i].getCidade() <= R[j].getCidade())
        {
            //numTroca++;;
            registros[k] = L[i];
            i++;
        }
        else
        {
            //numTroca++;
            registros[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[ ]
    while (i < n1)
    {
        //numTroca++;
        registros[k] = L[i];
        i++;
        k++;
    }
    // Copia os elementos restantes de R[ ]
    while (j < n2)
    {
        //numTroca++;
        registros[k] = R[j];
        j++;
        k++;
    }
    delete [] L;
    delete [] R;
}

void Ordenadores::mergeSort(Registro* registros, int inicio, int fim)
{
    int meio;

    if(inicio < fim)
    {
        meio = (inicio + fim)/2;
        mergeSort(registros, inicio, meio);
        mergeSort(registros, meio+1, fim );
        intercala(registros, inicio, meio, fim);
    }

}
// Funcao serve para Heapifyzar uma subarvore com raiz que tem indice i
// obs : i eh um indice , n eh o tamanho da heap
void Ordenadores::heapify(Registro *registros , int n, int i)
{
	int maior = i;       // Maior eh iniciado como raiz
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	if (l < n && registros[l].getEstado() > registros[maior].getEstado())
		maior = l;

	if (r < n && registros[r].getEstado() > registros[maior].getEstado())
		maior = r;

	// caso a maior nao seja igual a raiz mais por ter sido trocada
	if (maior != i) {
		swap(registros[i], registros[maior]);

		// vai descendo
		heapify(registros, n, maior);
	}
}

// Funcao principal para a heapSort
void Ordenadores::heapSort(Registro *registros , int n)
{
	// Constroi a heap maxima dentro do array
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(registros, n, i);

	// Vai ordenando um por um e parando de verificar oq ja esta ordenado
	for (int i = n - 1; i > 0; i--) {
		// manda a raiz atual que eh o maior valor para o final
		swap(registros[0], registros[i]);

		// rearranja a heap
		heapify(registros, i, 0);
	}
}