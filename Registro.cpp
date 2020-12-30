#include <iostream>
#include <fstream>
#include <string>
#include "Registro.h"


Registro::Registro(){
    dataCompleta="";
    estado="";
    cidade="";
    codigoCidade=-1;
    casos=-1;
    mortes=-1;
}

Registro::Registro(string dataCompleta, string estado, string cidade, int codigoCidade, int casos, int mortes){
    this->dataCompleta = dataCompleta;
    this->estado = estado;
    this->cidade = cidade;
    this->codigoCidade = codigoCidade;
    this->casos = casos;
    this->mortes = mortes;
}

Registro::~Registro(){}

//fazer um set  de data separado bunitim como int e tal sla

void Registro::setDataCompleta(string dataCompleta){
    this->dataCompleta = dataCompleta;
}
void Registro::setEstado(string estado){
    this->estado = estado;
}
void Registro::setCidade(string cidade){
    this->cidade = cidade;
}
void Registro::setCodigoCidade(int codigoCidade){
    this->codigoCidade = codigoCidade;
}
void Registro::setCasos(int casos){
    this->casos = casos;
}
void Registro::setMortes(int mortes){
    this->mortes = mortes;
}
void Registro::imprime(){
    cout<< ' ' <<dataCompleta <<' ' << estado <<' ' << cidade <<' ' << codigoCidade <<' ' << casos <<' ' << mortes <<endl;
}

string Registro::getDataCompleta(){
    return dataCompleta;
}
string Registro::getCidade(){
    return cidade;
}
string Registro::getEstado(){
    return estado;
}
int Registro::getCodigoCidade(){
    return codigoCidade;
}
int Registro::getCasos(){
    return casos;
}
int Registro::getMortes(){
    return mortes;
}