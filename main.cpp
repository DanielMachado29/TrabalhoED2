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
#define NOMEARQUIVODATASET "brazil_covid19_cities.csv"

using namespace std;
using namespace std::chrono;

void leArquivo(Registro *r , int N , string nomeArquivo)
{

    ifstream arq(nomeArquivo);
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
    cout << "Arquivo " << nomeArquivo<< " com "<<cont << " registros lido com sucesso!" << endl;
    arq.close();
}

void transformaCasosAcumuladosEmCasosDiarios(Registro *registros , int N){

    for(int i=1 ; i<N ; i++){
         
        if(registros[i].getCidade() == registros[i-1].getCidade()){
            registros[i].setCasos(registros[i].getCasos() - registros[i-1].getCasos());
        } 
    }
}
              
void escreveArquivoSaida(Registro *r, int size,string nomeSaidaArquivo)
{
   ofstream arq(nomeSaidaArquivo);
   cout<<"Escrevendo arquivo de saida..."<<endl;
    arq << "data,estado,nomeCidade,codigo,casos,mortes" << endl;
    for(int i = 1; i <= size; i++)
    {
        arq << r[i].getDataCompleta() << "," << r[i].getEstado()<<"," <<r[i].getCidade() <<","<<r[i].getCodigoCidade() <<
        "," <<r[i].getCasos()<<"," <<r[i].getMortes()<<endl;
    }
    arq.close(); 
}



// void ordenandoComHeapSort(Registro *registros , int N){
//     Ordenadores *ord = new Ordenadores();
//     high_resolution_clock::time_point inicio = high_resolution_clock::now();
//     leArquivo(registros,N,NOMEARQUIVODATASET);
//     cout<<"-----------------------------------------------"<<endl;
//     ord->heapSort(registros, N);
//     high_resolution_clock::time_point fim = high_resolution_clock::now();
//     //printArray(registros,N);
//     escreveArquivoSaida(registros,N,"brazil_covid19_cities_processado.csv");
//     cout<<"Fim da ordenacao com HeapSort"<<endl;
//     cout<< duration_cast<duration<double>>(fim-inicio).count()<<"s"<<endl;

// }



void ordenandoComMergeSort(Registro *registros , int N){
    Ordenadores *ord = new Ordenadores();
    
    leArquivo(registros,N,NOMEARQUIVODATASET);
    cout<<"----------------------------------------------------------------------"<<endl;
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    ord->mergeSort(registros,0, N);
    high_resolution_clock::time_point fim = high_resolution_clock::now();
    transformaCasosAcumuladosEmCasosDiarios(registros,N);
    escreveArquivoSaida(registros,N,"brazil_covid19_cities_processado.csv");
    cout<<"Fim da ordenacao com mergeSort"<<endl;
    cout<<"TESTE - Foram feitas: "<<ord->getQuantidadeComparacoes()<< " comparacoes , e " <<
    ord->getQuantidadeTrocas()<< " trocas."<<endl;
    cout<< duration_cast<duration<double>>(fim-inicio).count()<<"s"<<endl;

}

void ordenandoComQuickSort(Registro *registros , int N){
    Ordenadores *ord = new Ordenadores();
    leArquivo(registros,N,"brazil_covid19_cities_processado.csv");
    cout<<"----------------------------------------------------------------------"<<endl;
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    ord->quickSort(registros,0,N);
    high_resolution_clock::time_point fim = high_resolution_clock::now();
    //printArray(registros,N);
    escreveArquivoSaida(registros,N,"brazil_covid19_cities_processado_ETAPA2TESTE_QUICK.csv");
    cout<<"Fim da ordenacao com QuickSort"<<endl;
    cout<< duration_cast<duration<double>>(fim-inicio).count()<<"s"<<endl;

}
void ordenandoComRadix(Registro *registros , int N){
    Ordenadores *ord = new Ordenadores();
    
    leArquivo(registros,N,"brazil_covid19_cities_processado.csv");
    cout<<"----------------------------------------------------------------------"<<endl;
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    ord->radixsort(registros,N);
    high_resolution_clock::time_point fim = high_resolution_clock::now();
    //printArray(registros,N);
    //escreveArquivoSaida(registros,N);
    escreveArquivoSaida(registros,N,"brazil_covid19_cities_processado_ETAPA2TESTE_RADIX.csv");
    cout<<"Fim da ordenacao com RadixSort"<<endl;
    cout<< duration_cast<duration<double>>(fim-inicio).count()<<"s"<<endl;

}





int main()
{
    // Para rodar o programa :
    //  g++ -o teste -O3 *.cpp
    // ./teste

    int tamanhoN[] = {10000,50000,100000,500000,1000000,TAMANHOMAX};
    Registro *registros = new Registro[tamanhoN[4]];

    //ordenandoComHeapSort(registros,tamanhoN[5]);

    ordenandoComMergeSort(registros,tamanhoN[4]);
    ordenandoComQuickSort(registros,tamanhoN[4]);

    delete[] registros;
    

    return 0;
}

