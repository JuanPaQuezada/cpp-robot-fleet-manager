/*+----------------------------------------------------------------------------+
# | Author.......: Juan Pablo Quezada Jimenez <qjuanpablo21@gmail.com>
# | First release: February 18th, 2026
# | Last update..: February 18th, 2026
# | WhatIs.......: Robots Classifier system - Main
# +----------------------------------------------------------------------------++*/
// ------------------------- Instructions -----------------------
// TODO: 

// ------------ Resources / Documentation involved -------------
// Wrapping in C++: https://nachtimwald.com/2017/08/18/wrapping-c-objects-in-c/
// ------------------------- Libraries -------------------------
#include <iostream>
#include <conio.h>
#include <windows.h>

// ------------------------- Functions -------------------------
using namespace std;

struct Hardware{
    string noSerie;
    int nivelBateria;
};

class Robot{
    protected:
        Hardware har;
    public:
        Robot(string,int);
        virtual void operar()=0;
        virtual ~Robot(){};
};

Robot::Robot(string s, int b){
    har.noSerie = s;
    har.nivelBateria = b;
}

class Dron: public Robot{
    private:
        float alturaMaxima;
    public:
        Dron(string,int,float);
        void operar() override{
            cout<<"El dron "<<har.noSerie<<" esta volonado a "<<alturaMaxima<<" metros con bateria al "<<har.nivelBateria<<"%"<<endl;
        }
};



Dron::Dron(string s, int b, float hmax):Robot(s, b){
    alturaMaxima=hmax;
}

class IndustrialRobots : public Robot{
    private:
        float cargaMaxima;
    public:
        IndustrialRobots(string,int,float);
        virtual void operar(){
            cout<<"El brazo "<<har.noSerie<<" esta ensamblando piezas soportando "<<cargaMaxima<<" kg"<<endl;
        }
};
IndustrialRobots::IndustrialRobots(string s, int b, float cmax):Robot(s,b){
    cargaMaxima=cmax;
}
struct NodoFlota{
    Robot* robot;
    NodoFlota* siguiente;
};

void operarFlota(NodoFlota* cabeza){
    NodoFlota* actual = cabeza;
    while(actual != nullptr){
        actual->robot->operar();
        actual = actual->siguiente;
    }
}

void RegistrarRobot(NodoFlota*& cabeza){
    int op, bateria;
    float altura, carga;
    string serie;
    Robot* nuevoRobot;
    cout<<"---ROBOTS---"<<endl;
    cout<<"1) Dron\n2) Robot industrial\n Opcion: ";
    if(!(cin>>op)){cin.clear();cin.ignore(1000,'\n');}
    switch(op){
        case 1:{
            cout<<"---REGISTRO DE DRON---"<<endl;
            cout<<"Altura Maxima en metros: ";cin>>altura;
            cin.ignore();
            cout<<"Numero de serie: ";getline(cin,serie);
            cout<<"Bateria: ";cin>>bateria;
            nuevoRobot=new Dron(serie, bateria, altura);
            break;
        }
        case 2:{
            cout<<"---REGISTROS DE ROBOT INDUSTRIAL---"<<endl;
            cout<<"Carga maxima: ";cin>>carga;
            cin.ignore();
            cout<<"Numero de serie: ";getline(cin,serie);
            cout<<"Bateria: ";cin>>bateria;
            nuevoRobot=new IndustrialRobots(serie, bateria, carga);
            break;
        }
        default: cout<<"Opcion no valida"<<endl; return;
    }
    NodoFlota* nuevoNodo = new NodoFlota();
    nuevoNodo->robot = nuevoRobot;
    nuevoNodo->siguiente=cabeza;
    cabeza=nuevoNodo;

    cout<<">> Robot registrado en la stock con exito"<<endl;
}

void liberarFlota(NodoFlota* cabeza){
    NodoFlota* actual = cabeza;
    while(actual!=nullptr){
        NodoFlota* temporal=actual->siguiente;
        delete actual->robot;
        delete actual;
        actual=temporal;
    }
}
// ------------------------- Variables -------------------------

// --------------------------- Code ----------------------------
int main(){
    int opc;
    NodoFlota* cabeza = nullptr;
    do{
        system("cls");
        cout<<"1) Registrar\t2) Operar\t3) Salir\nQue opcion quieres: ";
        if(!(cin>>opc)){
            cin.clear();
            cin.ignore(1000, '\n');
        }
        switch(opc){
            case 1: 
                RegistrarRobot(cabeza);
                system("pause");
                break;
            case 2:
                operarFlota(cabeza);
                system("pause");
                break;
            case 3:
                cout<<"Apagando sistema...";
                liberarFlota(cabeza);
                break;
            default:
                cout<<"Opcion invalida"<<endl;
        }
    }while(opc!=3);

    return 0;
}