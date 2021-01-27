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
    int tamVetL = meio-inicio+1; //tamanho do vetor temporario L
    int tamVetR = fim - meio; //tamanho do vetor temporario R

    // cria vetores temporarios
    Registro * L = new Registro[tamVetL];
    Registro * R = new Registro[tamVetR];


    //copia os dados para as arrays L e R
    for (i = 0; i < tamVetL; i++)
        L[i] = registros[inicio + i];
    for (j = 0; j < tamVetR; j++)
        R[j] = registros[meio + 1 + j];

    //Junta os vetores temporarios no vetor principal
    i = 0; // index inicial para a primeira subarray
    j = 0; // index inicial para a segunda subarray
    k = inicio; // index inicial para a merge subarray

    while (i < tamVetL && j < tamVetR)
    {
        // se cidade de L vier antes da cidade de R
        if (L[i].getEstado() < R[j].getEstado())
        {
            registros[k] = L[i];
            i++;
            k++;
            continue;
        }
        if (L[i].getEstado() == R[j].getEstado())
        {
            if(L[i].getCidade() < R[j].getCidade()){
                registros[k] = L[i];
                i++;
                k++;
                continue;
            }
            
        }
        if (L[i].getEstado() == R[j].getEstado() && L[i].getCidade() == R[j].getCidade())
        {
            if(L[i].getDataCompleta() < R[j].getDataCompleta()){
                registros[k] = L[i];
                i++;
                k++;
                continue;
            }
            
        }
        //else
        //{
            
            registros[k] = R[j];
            j++;
        //}


        k++;
    }

    // Copia os elementos restantes de L[ ]
    while (i < tamVetL)
    {
        
        registros[k] = L[i];
        i++;
        k++;
    }
    // Copia os elementos restantes de R[ ]
    while (j < tamVetR)
    {
        
        registros[k] = R[j];
        j++;
        k++;
    }
    delete [] L;
    delete [] R;
}

void Ordenadores::mergeSort(Registro* registros, int indexInicio, int indexFim)
{
    
    if(indexFim > indexInicio)
    {
        int meio = (indexInicio + indexFim)/2;      // pega o meio como parametro de index para as duas metades 
        mergeSort(registros, indexInicio, meio);   // na primeira metade ele vira o indexFim
        mergeSort(registros, meio+1, indexFim );  //na segunda metade ele+1 vira o indexInicio
        intercala(registros, indexInicio, meio, indexFim);
    }
    else return;

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