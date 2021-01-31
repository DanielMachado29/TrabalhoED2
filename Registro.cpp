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
#include "Ordenadores.h"
using namespace std::chrono;

Registro::Registro()
{
    dataCompleta = "";
    estado = "";
    cidade = "";
    codigoCidade = -1;
    casos = -1;
    mortes = -1;
    visitado = false;
}

Registro::~Registro() {}

void Registro::transformaCasosAcumuladosEmCasosDiarios(Registro *registros, int N)
{
    Registro *aux = new Registro[N];
    for (int i = 0; i < N; i++)
    {
        aux[i] = registros[i];
    }
    for (int i = 1; i < N; i++)
    {
        if (aux[i].getCidade() == aux[i - 1].getCidade())
        {
            registros[i].setCasos(aux[i].getCasos() - aux[i - 1].getCasos());
        }
    }
    delete[] aux;
}

void Registro::escreveArquivoSaidaCsv(Registro *r, int size, string nomeSaidaArquivo)
{
    ofstream arq(nomeSaidaArquivo);
    cout << "Escrevendo arquivo de saida..." << endl;
    arq << "data,estado,nomeCidade,codigo,casos,mortes" << endl;
    for (int i = 1; i <= size; i++)
    {
        arq << r[i].getDataCompleta() << "," << r[i].getEstado() << "," << r[i].getCidade() << "," << r[i].getCodigoCidade() << "," << r[i].getCasos() << "," << r[i].getMortes() << endl;
    }
    arq.close();
}

void Registro::leArquivo(Registro *r, int N, string nomeArquivo)
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
    int cont = 0;
    getline(arq, linha); //pula primeira linha
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
        r[cont].setVisitado(false);

        if (cont > N)
            break;
        cont++;
    }
    cout << "Arquivo com " << cont << " registros lido com sucesso!" << endl;
    arq.close();
}

void Registro::selecionandoRegistrosAleatorios(Registro *registroPrincipal, Registro *registrosAux, int N)
{
    int somaIndex;
    int indexzada;
    for (int i = 0; i < N; i++)
    {
        somaIndex = rand() % 1000000 + 26412;
        while (somaIndex >= 1431490)
        {
            somaIndex = std::chrono::system_clock::now().time_since_epoch().count();
            somaIndex / (rand() % 1000000 + 26412);
        }
        indexzada = somaIndex * (rand() % 10 + 1);

        while (registroPrincipal[indexzada].getVisitado())
        {
            indexzada = indexzada + (rand() % 14 + 1);
        }

        registrosAux[i] = registroPrincipal[indexzada];
        registroPrincipal[indexzada].setVisitado(true);
    }
}

void Registro::preProcessamentoComMergeSort(Registro *registros, int N)
{
    Ordenadores *ord = new Ordenadores();
    string nomeArquivoEntrada;
    cout << "Por favor , digite o nome do arquivo para o Pre-Processamento dos dados." << endl;
    cin >> nomeArquivoEntrada;
    registros->leArquivo(registros, N, nomeArquivoEntrada);
    cout << "Realizando Pre-Processamento..." << endl;
    ord->mergeSortPreProcessamento(registros, 0, N);
    registros->transformaCasosAcumuladosEmCasosDiarios(registros, N);
    registros->escreveArquivoSaidaCsv(registros, N, "brazil_covid19_cities_processados.csv");
}

void Registro::setVisitado(bool visitado)
{
    this->visitado = visitado;
}

bool Registro::getVisitado()
{
    return visitado;
}

void Registro::setDataCompleta(string dataCompleta)
{
    this->dataCompleta = dataCompleta;
}
void Registro::setEstado(string estado)
{
    this->estado = estado;
}
void Registro::setCidade(string cidade)
{
    this->cidade = cidade;
}
void Registro::setCodigoCidade(int codigoCidade)
{
    this->codigoCidade = codigoCidade;
}
void Registro::setCasos(int casos)
{
    this->casos = casos;
}
void Registro::setMortes(int mortes)
{
    this->mortes = mortes;
}

string Registro::getDataCompleta()
{
    return dataCompleta;
}
string Registro::getCidade()
{
    return cidade;
}
string Registro::getEstado()
{
    return estado;
}
int Registro::getCodigoCidade()
{
    return codigoCidade;
}
int Registro::getCasos()
{
    return casos;
}
int Registro::getMortes()
{
    return mortes;
}