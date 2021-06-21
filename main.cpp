#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>
#include <algorithm> // std::swap
#include <climits>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include "Ordenadores.h"
//
#define TAMANHOMAX 1431490
#define NOMEARQUIVODATASET "brazil_covid19_cities.csv"

using namespace std;
using namespace std::chrono;

void criaArquivoSaidaTxt(string nomeArquivo){
    ofstream arq(nomeArquivo);
    arq.close();
}


void ordenaTesteQuick(Registro *registros, int N){
    Ordenadores *ord = new Ordenadores();
    ord->quickSort(registros, 0, N);
    cout<<"Ordenado por QuickSort :"<<endl;
    registros->exibeRegistros(registros,N);
    cout<<endl;
}
void ordenaTesteShell(Registro *registros, int N){
    Ordenadores *ord = new Ordenadores();
    ord->shellSort(registros, N);
    cout<<"Ordenado por ShellSort :"<<endl;
    registros->exibeRegistros(registros,N);
    cout<<endl;
}
/////////////////////

void ordenaTesteMergeArquivo(Registro *r, int N,string nomeArquivo){
    ofstream arq;
    arq.open(nomeArquivo, ios::ate| ios::out | ios::in);
    Ordenadores *ord = new Ordenadores();
    ord->mergeSort(r, 0, N);
    arq<<"Ordenado por MergeSort :"<<endl;
    if(r[0].getDataCompleta()!=""){
        for (int i = 0; i <(N); i++)
        {
            arq << r[i].getDataCompleta() << "," << r[i].getEstado() << "," << r[i].getCidade() << "," << r[i].getCodigoCidade() << "," << r[i].getCasos() << "," << r[i].getMortes() << endl;
        }
    }else{
        for (int i = 1; i <(N+1); i++)
        {
            arq << r[i].getDataCompleta() << "," << r[i].getEstado() << "," << r[i].getCidade() << "," << r[i].getCodigoCidade() << "," << r[i].getCasos() << "," << r[i].getMortes() << endl;
        }
    }
    arq<<endl;

}
void ordenaTesteQuickArquivo(Registro *r, int N,string nomeArquivo){
    ofstream arq;
    arq.open(nomeArquivo, ios::ate| ios::out | ios::in);
    Ordenadores *ord = new Ordenadores();
    ord->quickSort(r, 0, N);
    arq<<"Ordenado por QuickSort :"<<endl;
    if(r[0].getDataCompleta()!=""){
        for (int i = 0; i <(N); i++)
        {
            arq << r[i].getDataCompleta() << "," << r[i].getEstado() << "," << r[i].getCidade() << "," << r[i].getCodigoCidade() << "," << r[i].getCasos() << "," << r[i].getMortes() << endl;
        }
    }else{
        for (int i = 1; i <(N+1); i++)
        {
            arq << r[i].getDataCompleta() << "," << r[i].getEstado() << "," << r[i].getCidade() << "," << r[i].getCodigoCidade() << "," << r[i].getCasos() << "," << r[i].getMortes() << endl;
        }
    }
    arq<<endl;
}
void ordenaTesteShellArquivo(Registro *r, int N,string nomeArquivo){
    ofstream arq;
    arq.open(nomeArquivo, ios::ate| ios::out | ios::in);
    Ordenadores *ord = new Ordenadores();
    ord->shellSort(r, N);
    arq<<"Ordenado por ShellSort :"<<endl;
    if(r[0].getDataCompleta()!=""){
        for (int i = 0; i <(N); i++)
        {
            arq << r[i].getDataCompleta() << "," << r[i].getEstado() << "," << r[i].getCidade() << "," << r[i].getCodigoCidade() << "," << r[i].getCasos() << "," << r[i].getMortes() << endl;
        }
    }else{
        for (int i = 1; i <(N+1); i++)
        {
            arq << r[i].getDataCompleta() << "," << r[i].getEstado() << "," << r[i].getCidade() << "," << r[i].getCodigoCidade() << "," << r[i].getCasos() << "," << r[i].getMortes() << endl;
        }
    }
    arq<<endl;
}

/////////////////////

void ordenandoComMergeSort(Registro *registros, int N,string nomeArquivo)
{
    ofstream arq;// ("a:lista.dat", ios::ate | ios::out | ios::in)
    arq.open(nomeArquivo, ios::ate| ios::out | ios::in);
    Ordenadores *ord = new Ordenadores();
    int mediaComparacao = 0;
    int mediaTrocas = 0;
    double mediaTempo = 0;
    int M=5;
    arq <<"Ordenando com Merge sort para "<<N<<" registros: "<<endl;
    for (int i = 0; i < M; i++)
    {
        high_resolution_clock::time_point inicio = high_resolution_clock::now();
        ord->mergeSort(registros, 0, N);
        high_resolution_clock::time_point fim = high_resolution_clock::now();
        arq << "Exececucao " << i+1 << " : "<< endl;
        arq << "Tempo: " << duration_cast<duration<double>>(fim - inicio).count() << "s.   " ;
        arq << "Comparacoes: " << ord->getQuantidadeComparacoes()<< ".   ";
        arq << "Trocas: " << ord->getQuantidadeTrocas()<< ".   "<<endl;
        mediaTempo = mediaTempo + (duration_cast<duration<double>>(fim - inicio).count());
        mediaComparacao = mediaComparacao + ord->getQuantidadeComparacoes();
        mediaTrocas = mediaTrocas + ord->getQuantidadeTrocas();
    }
    arq<<endl;

    arq << "Media de Tempo em 5 execs: " << mediaTempo / 5 << endl;
    arq << "Media de Comparacao em 5 execs: " << mediaComparacao / 5 << endl;
    arq << "Media de Trocas em 5 execs: " << mediaTrocas / 5 << endl;
    arq <<"---------------------------------------------------------------------------------------"<<endl;
    arq.close();
    //escreveArquivoSaida(registros,N,"brazil_covid19_cities_processados.csv");
}

void ordenandoComQuickSort(Registro *registros, int N,string nomeArquivo)
{
    ofstream arq;// ("a:lista.dat", ios::ate | ios::out | ios::in)
    arq.open(nomeArquivo, ios::ate| ios::out | ios::in);
    Ordenadores *ord = new Ordenadores();
    int mediaComparacao = 0;
    int mediaTrocas = 0;
    double mediaTempo = 0;
    int M=5;
    arq <<"Ordenando com Quick sort  para "<<N<<" registros: "<<endl;
    for (int i = 0; i < M; i++)
    {
        high_resolution_clock::time_point inicio = high_resolution_clock::now();
        ord->quickSort(registros, 0, N);
        high_resolution_clock::time_point fim = high_resolution_clock::now();
        arq << "Exececucao " << i+1 << " : "<< endl;
        arq << "Tempo: " << duration_cast<duration<double>>(fim - inicio).count() << "s.   " ;
        arq << "Comparacoes: " << ord->getQuantidadeComparacoes()<< ".   ";
        arq << "Trocas: " << ord->getQuantidadeTrocas()<< ".   "<<endl;
        mediaTempo = mediaTempo + (duration_cast<duration<double>>(fim - inicio).count());
        mediaComparacao = mediaComparacao + ord->getQuantidadeComparacoes();
        mediaTrocas = mediaTrocas + ord->getQuantidadeTrocas();
    }
    arq<<endl;

    arq << "Media de Tempo em 5 execs: " << mediaTempo / 5 << endl;
    arq << "Media de Comparacao em 5 execs: " << mediaComparacao / 5 << endl;
    arq << "Media de Trocas em 5 execs: " << mediaTrocas / 5 << endl;
    arq <<"---------------------------------------------------------------------------------------"<<endl;
    arq.close();
}
void ordenandoComShellSort(Registro *registros, int N, string nomeArquivo)
{
    ofstream arq;// ("a:lista.dat", ios::ate | ios::out | ios::in)
    arq.open(nomeArquivo, ios::ate| ios::out | ios::in);
    Ordenadores *ord = new Ordenadores();
    int mediaComparacao = 0;
    int mediaTrocas = 0;
    double mediaTempo = 0;
    int M=5;
    arq <<"Ordenando com Shell sort para "<<N<<" registros: "<<endl;
    for (int i = 0; i < M; i++)
    {
        high_resolution_clock::time_point inicio = high_resolution_clock::now();
        ord->shellSort(registros, N);
        high_resolution_clock::time_point fim = high_resolution_clock::now();
        arq << "Exececucao " << i+1 << " : "<< endl;
        arq << "Tempo: " << duration_cast<duration<double>>(fim - inicio).count() << "s.   " ;
        arq << "Comparacoes: " << ord->getQuantidadeComparacoes()<< ".   ";
        arq << "Trocas: " << ord->getQuantidadeTrocas()<< ".   "<<endl;
        mediaTempo = mediaTempo + (duration_cast<duration<double>>(fim - inicio).count());
        mediaComparacao = mediaComparacao + ord->getQuantidadeComparacoes();
        mediaTrocas = mediaTrocas + ord->getQuantidadeTrocas();
    }
    arq<<endl;

    arq << "Media de Tempo em 5 execs: " << mediaTempo / 5 << endl;
    arq << "Media de Comparacao em 5 execs: " << mediaComparacao / 5 << endl;
    arq << "Media de Trocas em 5 execs: " << mediaTrocas / 5 << endl;
    arq <<"---------------------------------------------------------------------------------------"<<endl;
    arq.close();
}

int menu()
{
    int men = -1;
    int volta = 0;
    int tamanhoN[] = {10000, 50000, 100000, 500000, 1000000, TAMANHOMAX};
    Registro *registros = new Registro[tamanhoN[5]];
    Registro *registrosAux = new Registro[tamanhoN[5]];
    while (men != 4)
    {
        cout << "===============Menu===============" << endl;
        cout << "[1]->Pre-processamento dos dados" << endl;
        cout << "[2]->Modulo de Teste" << endl;
        cout << "[3]->Analise dos algoritmos de ordenacao" << endl;
        cout << "[4]->Finzalizar execucao" << endl;
        cin >> men;
        switch (men)
        {
        case 1:
            registros->preProcessamentoComMergeSort(registros, tamanhoN[5]);
            break;
        case 2:

            cout << "===============Modulo de Teste===============" << endl;
            cout << "[1]->Testar o pre-processamento dos dados" << endl;
            cout << "[2]->Testar a importacao de N registros aleatorios" << endl;
            cout << "[3]->Testar Cada um dos algoritmos de ordenacao" << endl;
            cin >> men;

            if (men == 1)
            {
                cout << "[1]->Saida no Console do Teste N=10" << endl;
                cout << "[2]->Saida em Arquivo do Teste N=100" << endl;
                cin >> men;
                if (men == 1)
                {
                    registros->exibeRegistrosPreProcessados(registros, 10);
                    break;
                }
                if (men == 2)
                {
                    registros->escreveArquivoSaidaCsv(registros, 100, "moduloDeTestePreProcessamento.csv");
                    break;
                }
            }
            if (men == 2)
            {
                cout << "[1]->Saida no Console do Teste N=10" << endl;
                cout << "[2]->Saida em Arquivo do Teste N=100" << endl;
                cin >> men;
                if (men == 1)
                {
                    registros->selecionandoRegistrosAleatorios(registros, registrosAux, 10);
                    registros->exibeRegistros(registrosAux, 10);
                    break;
                }
                if (men == 2)
                {
                    registros->selecionandoRegistrosAleatorios(registros, registrosAux, 100);
                    registros->escreveArquivoSaidaCsv(registrosAux, 100, "moduloDeTesteImportacaoRegistrosAleatorios.csv");
                }
            }
            if (men == 3)
            {
                cout << "[1]->Saida no Console do Teste N=10" << endl;
                cout << "[2]->Saida em Arquivo do Teste N=100" << endl;
                cin >> men;
                if (men == 1)
                {
                    registros->selecionandoRegistrosAleatorios(registros, registrosAux, 10);
                    ordenaTesteMerge(registrosAux,10);
                    registros->selecionandoRegistrosAleatorios(registros, registrosAux, 10);
                    ordenaTesteQuick(registrosAux,10);
                    registros->selecionandoRegistrosAleatorios(registros, registrosAux, 10);
                    ordenaTesteShell(registrosAux,10);

                    break;
                }
                if (men == 2)
                {
                    criaArquivoSaidaTxt("moduloDeTesteOrdenacaoCadaUmDosAlgoritmos.txt");
                    registros->selecionandoRegistrosAleatorios(registros, registrosAux, 100);
                    ordenaTesteMergeArquivo(registrosAux,100,"moduloDeTesteOrdenacaoCadaUmDosAlgoritmos.txt");
                    registros->selecionandoRegistrosAleatorios(registros, registrosAux, 100);
                    ordenaTesteQuickArquivo(registrosAux,100,"moduloDeTesteOrdenacaoCadaUmDosAlgoritmos.txt");
                    registros->selecionandoRegistrosAleatorios(registros, registrosAux, 100);
                    ordenaTesteShellArquivo(registrosAux,100,"moduloDeTesteOrdenacaoCadaUmDosAlgoritmos.txt");
                }
            }
            break;
        case 3:
            criaArquivoSaidaTxt("saida.txt");
            for(int i = 0 ; i<5 ;i++){
                registros->selecionandoRegistrosAleatorios(registros, registrosAux, tamanhoN[i]);
                ordenandoComMergeSort(registrosAux,tamanhoN[i],"saida.txt");
                registros->selecionandoRegistrosAleatorios(registros, registrosAux, tamanhoN[i]);
                ordenandoComQuickSort(registrosAux,tamanhoN[i],"saida.txt");
                registros->selecionandoRegistrosAleatorios(registros, registrosAux, tamanhoN[i]);
                ordenandoComShellSort(registrosAux,tamanhoN[i],"saida.txt");
            }
            break;
        case 4:
            return 0;
            break;
            
        }
    }
    return 0;
}

int main()
{
    menu();
    return 0;
}

//  g++ -o teste -O3 *.cpp
// ./teste
