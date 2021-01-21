#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>

using namespace std;

class Registro
{
private:
    string dataCompleta, estado, cidade;
    //int dia, mes, ano ;
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
};