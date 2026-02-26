#include "../include/FlotaRobots.h"
#include <conio.h>
#include <thread>
#include <chrono>

Robot::Robot(string s, int b){
    har.NoSerie=s;
    har.battery=b;
}
//Constructor 2(constructor overloading)
Robot::Robot(string s){
    har.NoSerie=s;
    har.battery=100;
}
Dron::Dron(string s,int b, float mh):Robot(s,b){
    maxHeight=mh;
}
IndustrialRobot::IndustrialRobot(string s, int b, float ml):Robot(s,b){
    maxLoad=ml;
} 

void RegisterRobot(NodoFlota*& cabeza){
    int opc,opcb,battery;
    float maxHeight, maxLoad;
    string noSerial;
    Robot* nuevoRobot = nullptr;
    cout<<"----REGISTER ROBOT---"<<endl;
    cout<<"1) Dron\t2) Industrial Robot\nOpcion: ";
    if(!(cin>>opc)){cin.clear();cin.ignore(1000,'\n');}
    switch(opc){
        case 1: {
            cout<<"---REGISTER NEW DRONE---"<<endl;
            cout<<"1) Nuevo de Fabrica\t2) Registrar Dron\nTu Dron es: ";cin>>opcb;
            cout<<"Altura maxima: ";cin>>maxHeight;
            cin.ignore();
            cout<<"Numero de serie: ";getline(cin,noSerial);
            if(opcb == 2) {cout<<"Nivel de bateria: ";cin>>battery;} 
            else cout<<"Bateria Registrada al 100%"<<endl;
            nuevoRobot=new Dron(noSerial,battery,maxHeight);
            break;
        }
        case 2: {
            cout<<"---REGISTER NEW INDUSTRIAL ROBOT---"<<endl;
             cout<<"1) Nuevo de Fabrica\t2) Registrar Brazo\nTu brazo es: ";cin>>opcb;
            cout<<"Carga maxima: ";cin>>maxLoad;
            cin.ignore();
            cout<<"Numero de serie: ";getline(cin,noSerial);
            if(opcb==2){cout<<"Nivel de bateria: ";cin>>battery;}
            else cout<<"Bateria Registrada al 100%"<<endl;
            nuevoRobot=new IndustrialRobot(noSerial,battery,maxLoad);
            break;
        }
        default:
            cout<<"Error: Opcion no valida"<<endl; return;
    }
    NodoFlota* nuevoNodo = new NodoFlota();
    nuevoNodo->robot = nuevoRobot;
    nuevoNodo->siguiente=cabeza;
    cabeza=nuevoNodo;

    cout<<"Robot registrado correctamente"<<endl;
}

void operateFleet(NodoFlota* cabeza){
    NodoFlota* actual = cabeza;
    while(actual!=nullptr){
        actual->robot->operar();
        actual=actual->siguiente;
    }
}

void releaseFleet(NodoFlota* cabeza){
    NodoFlota* actual=cabeza;
    while(actual != nullptr){
        NodoFlota* temporal = actual->siguiente;
        delete actual->robot;
        delete actual;
        actual=temporal;
    }

}