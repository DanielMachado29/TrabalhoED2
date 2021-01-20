#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>
#include <algorithm>    // std::swap
#include<climits>
#include <stdio.h>
#include <string.h>
// #include "Registro.cpp"
#include "Registro.h"
#define TAMANHOMAX 1431490

using namespace std;
using namespace std::chrono;

void leArquivo(Registro *r , int N)
{
    ifstream arq("brazil_covid19_cities.csv");
    if (!arq.is_open())
    {
        cout << "Problema ao abrir o Arquivo!" << endl;
        return;
    }
    string dataCompleta, estado, cidade;
    int casos, mortes;
    int codigoCidade; //// DUVIDA -> ISSO DEVERIA SER UM FLOAT???
    string linha, stringTemporaria1, stringTemporaria2, stringTemporaria3;
    int cont=0;
    while (getline(arq, linha))
    {
        stringstream ss(linha);
        getline(ss, dataCompleta, ',');
        r[cont].setDataCompleta(dataCompleta);
        getline(ss, estado, ',');
        r[cont].setEstado(estado);
        getline(ss, cidade, ',');
        r[cont].setCidade(cidade);
        getline(ss, stringTemporaria1, ',');
        istringstream(stringTemporaria1) >> codigoCidade; //// DUVIDA -> ISSO DEVERIA SER UM FLOAT???
        r[cont].setCodigoCidade(codigoCidade);
        getline(ss, stringTemporaria2, ',');
        istringstream(stringTemporaria2) >> casos;
        r[cont].setCasos(casos);
        getline(ss, stringTemporaria3, ',');
        istringstream(stringTemporaria3) >> mortes;
        r[cont].setMortes(mortes);

        //r[cont].imprime();
        if(cont>N)
        break;
        cont++;
        
        

    }
    cont--;
    cout << "terminei de ler papae" << endl;
    cout << "nesse arquivo , tem " << cont << " registros" <<endl;
    arq.close();
}


    
void bubbleSort(Registro *r, int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)
    // Os ultimos elementos de i já estão no lugar 
    for (j = 0; j < n-i-1; j++)  
        if (r[j].getCasos() > r[j+1].getCasos())  
            swap(r[j],r[j+1]);
}  
  
void printArray(Registro *r, int size)  
{    
    for (int i = 0; i < size; i++)  
        cout << r[i].getCidade() << " ";  
    cout << endl;  
}

void testeOrdenandoBubbleSort(Registro *r , int N){
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    leArquivo(r,N);
    cout<<"-----------------------------------------"<<endl;
    bubbleSort(r, N);
    printArray(r,N);
    cout<<"Fim da ordenacao com BubbleSort"<<endl;
    high_resolution_clock::time_point fim = high_resolution_clock::now();
    cout<< duration_cast<duration<double>>(fim-inicio).count()<<"s"<<endl;

}





// Funcao serve para Heapifyzar uma subarvore com raiz que tem indice i
// obs : i eh um indice , n eh o tamanho da heap
void heapify(Registro *registros , int n, int i)
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
                
void escreveArquivoSaida(Registro *r, int size)
{


   ofstream arq("dados1.csv");
   cout<<"Depois"<<endl;
    for(int i = 1; i <= size; i++)
    {
        arq << r[i].getDataCompleta() << " " << r[i].getEstado()<<" " <<r[i].getCidade() <<endl;
    }

    arq.close(); 
}

// Funcao principal para a heapSort
void heapSort(Registro *registros , int n)
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

void ordenandoComHeapSort(Registro *registros , int N){
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    leArquivo(registros,N);
    cout<<"-----------------------------------------"<<endl;
    heapSort(registros, N);
    high_resolution_clock::time_point fim = high_resolution_clock::now();
    //printArray(registros,N);
    escreveArquivoSaida(registros,N);
    cout<<"Fim da ordenacao com HeapSort"<<endl;
    cout<< duration_cast<duration<double>>(fim-inicio).count()<<"s"<<endl;

}



int main()
{
    int tamanhoN[] = {10000,50000,100000,500000,1000000,TAMANHOMAX};
    Registro *registros = new Registro[tamanhoN[5]];

    //testeOrdenandoBubbleSort(registros,tamanhoN[0]); // acima de 100.000 registros ja demora bastante

    ordenandoComHeapSort(registros,tamanhoN[5]);

    delete[] registros;
    

    return 0;
}