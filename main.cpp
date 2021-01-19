#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <chrono>
#include <sstream>

#include <climits>
#include <algorithm> 
#include <cstring>
#include <ctime>

#include <ratio>   // std::swap
#include "Registro.cpp"
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
    cout<<"aisdjaosid"<<endl;

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

int  particiona(Registro *r,int *__restrict menor,int *__restrict maior){
        

        
        int meio = (*menor + *maior)/2;
    
        Registro a = r[*menor];
        Registro b = r[meio];
        Registro c = r[*maior];

                string st1 = a.getEstado();
                char ch1[a.getEstado().size()];
                strcpy(ch1,st1.c_str());

                string st2 =b.getEstado();
                
                char ch2[b.getEstado().size()];
                strcpy(ch2,st2.c_str());
                
                 string st3 =c.getEstado();
                char ch3[c.getEstado().size()];
                strcpy(ch3,st3.c_str());

                
        int medianaIndice; //índice da mediana
       
        if(strcmp(ch1,ch2)>0){
            if((strcmp(ch2,ch3)>0)){
                //a < b && b < c
                medianaIndice = meio;
            }else{                
                if(strcmp(ch1,ch3)>0){
                    //a < c && c <= b
                    medianaIndice = *maior;
                }else{
                    //c <= a && a < b
                    medianaIndice =* menor;
                }
            }
        }else{
            if(strcmp(ch3,ch2)>0){
                //c < b && b <= a
                medianaIndice = meio;
            }else{
                if(strcmp(ch3,ch1)>0){
                    //b <= c && c < a
                    medianaIndice = *maior;
                }else{
                    //b <= a && a <= c
                    medianaIndice = *menor;
                }
            }
        }
        //coloca o elemento da mediana no fim para poder usar o Quicksort de Cormen
        
        swap(r[medianaIndice],r[*maior]);
      
        
    Registro pivo=r[*maior];

    int i=*menor-1;

  
       
        for(int j=*menor; j<=*maior-1; j++){

                
                string st1 = r[j].getEstado();
                char ch1[r[j].getEstado().size()];
                strcpy(ch1,st1.c_str());

                string st2 =pivo.getEstado();
                
                char ch2[pivo.getEstado().size()];
                strcpy(ch2,st2.c_str());

                int ret;
                ret = strcmp(ch1,ch2);

                
              

              if(ret<0||ret==0){
                  
                  
                    i++;
                    swap(r[i],r[j]);
                  }
                
               
                
            }
        

        //coloca o pivô na posição de ordenação
        swap(r[i+1],r[*maior]);
        
       
        return i + 1; 


 


}

void quickSort(Registro *r,int  menor,int   maior){

    /*
    Após o particionamento do vetor temos dois grupo internos:
        Do lado esquerdo do pivô com valores menores 
        Do lado direito do pivô com valores maiores.
        O pivô já está na posição correta do vetor ordenado 

    Se ordenarmos cada um desses grupos, temos no final um vetor totalmente ordenado.
    Como ordená-los? 
        Utilizando as chamadas recursivas para particionar cada um desses lados.
        Se o subvetor contém somente um elemento, este é o critério de parada para as chamadas recursivas


    */
   

    if(menor<maior){

        //Tamanho do subArray
        

      
        
        int pi=particiona(r,&menor,&maior);
       

        quickSort(r,menor,pi-1);
        quickSort(r,pi+1,maior);

    }

}


 
    

void bubbleSort(Registro *r, int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++){
    // Os ultimos elementos de i já estão no lugar 
    for (j = 0; j < n-1; j++)  {
        
                string st1 = r[j].getEstado();
                char ch1[r[j].getEstado().size()];
                strcpy(ch1,st1.c_str());

                string st2 =r[j+1].getEstado();
                
                char ch2[r[j+1].getEstado().size()];
                strcpy(ch2,st2.c_str());



              

                int ret;
                ret = strcmp(ch2,ch1);

                
                
              if(ret>0||ret==0){
               
                swap(r[j],r[j+1]); 
            }

    }
}
        /*
        if (r[j].getCasos() > r[j+1].getCasos())  
            swap(r[j],r[j+1]);  
            */
}  
  
void printArray2(Registro *r, int size)  
{    
    /*
    for (int i = 0; i < size; i++)  
        cout << r[i].getEstado()<<" " <<r[i].getCidade() << " "<<" "<<endl;
          
    cout << endl;
    */

   ofstream arq("dados1.csv");
   cout<<"Depois";
    for(int i = 1; i <= 1000000; i++)
    {
        arq << r[i].getEstado()<<" " <<r[i].getCidade() << " "<<" "<<endl;
    }

    arq.close(); 
}

  
void printArray1(Registro *r, int size)  
{    
    /*
    for (int i = 0; i < size; i++)  
        cout << r[i].getEstado()<<" " <<r[i].getCidade() << " "<<" "<<endl;
          
    cout << endl;
    */

   ofstream arq("dados2.csv");
    cout<<"antes";
    for(int i = 1; i <= 1000000; i++)
    {
        arq << r[i].getEstado()<<" " <<r[i].getCidade() << " "<<" "<<endl;
    }

    arq.close(); 
}

void testeOrdenandoBubbleSort(Registro *r , int N){
    leArquivo(r,N);
    cout<<"-----------------------------------------"<<endl;
    
     
    /*
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    bubbleSort(r, N);
    high_resolution_clock::time_point fim = high_resolution_clock::now();
    cout<< duration_cast<duration<double>>(fim-inicio).count()<<"s"<<endl;
    
    printArray1(r,N); 
    */
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    
    quickSort(r,0,N-1);
    high_resolution_clock::time_point fim = high_resolution_clock::now();
    cout<< duration_cast<duration<double>>(fim-inicio).count()<<"s"<<endl;
    printArray2(r,N);
    
    cout<<"teste completo"<<endl;

}

int main()
{
    int tamanhoN[] = {10000,50000,100000,500000,1000000};
    Registro *r = new Registro[tamanhoN[0]];
    testeOrdenandoBubbleSort(r,tamanhoN[0]); // acima de 100.000 registros ja demora bastante
    delete[] r;
    return 0;
}
