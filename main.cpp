#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>
#include <algorithm> // std::swap
#include<climits>
#include <stdio.h>
#include <string.h>
#include "Ordenadores.h"
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
    int codigoCidade;
    string linha, stringTemporaria1, stringTemporaria2, stringTemporaria3;
    int cont=0;
    getline(arq,linha);
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
        istringstream(stringTemporaria1) >> codigoCidade;
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
    cout << "Arquivo com "<< cont << " registros lido com sucesso!" << endl;
    arq.close();
}
              
void escreveArquivoSaida(Registro *r, int size)
{
   ofstream arq("brazil_covid19_cities_processado.csv");
   cout<<"Escrevendo arquivo de saida..."<<endl;
    for(int i = 1; i <= size; i++)
    {
        arq << r[i].getDataCompleta() << " " << r[i].getEstado()<<" " <<r[i].getCidade() <<endl;
    }

    arq.close(); 
}



void ordenandoComHeapSort(Registro *registros , int N){
    Ordenadores *ord = new Ordenadores();
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    leArquivo(registros,N);
    cout<<"-----------------------------------------------"<<endl;
    ord->heapSort(registros, N);
    high_resolution_clock::time_point fim = high_resolution_clock::now();
    //printArray(registros,N);
    escreveArquivoSaida(registros,N);
    cout<<"Fim da ordenacao com HeapSort"<<endl;
    cout<< duration_cast<duration<double>>(fim-inicio).count()<<"s"<<endl;

}



void ordenandoComMergeSort(Registro *registros , int N){
    Ordenadores *ord = new Ordenadores();
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    leArquivo(registros,N);
    cout<<"-----------------------------------------------"<<endl;
    ord->mergeSort(registros,0, N-1);
    high_resolution_clock::time_point fim = high_resolution_clock::now();
    //printArray(registros,N);
    escreveArquivoSaida(registros,N);
    cout<<"Fim da ordenacao com mergeSort"<<endl;
    cout<< duration_cast<duration<double>>(fim-inicio).count()<<"s"<<endl;

}

int main()
{
    // Para rodar o programa :
    //  g++ -o teste -O3 *.cpp
    // ./teste

    int tamanhoN[] = {10000,50000,100000,500000,1000000,TAMANHOMAX};
    Registro *registros = new Registro[tamanhoN[5]];

    //ordenandoComHeapSort(registros,tamanhoN[5]);

    ordenandoComMergeSort(registros,tamanhoN[5]);

    delete[] registros;
    

    return 0;
}