#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>
#include "Ordenadores.h"

using namespace std;

class Registro
{
private:
    string dataCompleta, estado, cidade;
    int casos, mortes, codigoCidade;

public:
    Registro(string dataCompleta, string estado, string cidade, int codigoCidade, int casos, int mortes);
    Registro();
    ~Registro();
    void setDataCompleta(string dataCompleta);
    void setEstado(string estado);
    void setCidade(string cidade);
    void setCodigoCidade(int codigoCidade);
    void setCasos(int casos);
    void setMortes(int mortes);
    string getDataCompleta();
    string getEstado();
    string getCidade();
    int getCodigoCidade();
    int getCasos();
    int getMortes();
    void imprime();
    void imprimeCidade(Registro *r, int size);
    void transformaCasosAcumuladosEmCasosDiarios(Registro *registros, int N);
    void escreveArquivoSaidaCsv(Registro *r, int size, string nomeSaidaArquivo);
    void leArquivo(Registro *r, int N, string nomeArquivo);
    void preProcessamentoComMergeSort(Registro *registros, int N);
};