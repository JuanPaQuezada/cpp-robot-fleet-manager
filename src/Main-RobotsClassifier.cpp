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
#include "../include/FlotaRobots.h"
#include <cstdlib>
#include <chrono>
#include <thread>

// ------------------------- Functions -------------------------

// ------------------------- Variables -------------------------

// --------------------------- Code ----------------------------
int main(){
    NodoFlota* cabeza=nullptr;
    int opc;
    do{
        system("cls");
        cout<<"1) Registrar\t2) Operar\t3) Salir\nOpcion: ";
        if(!(cin>>opc)){cin.clear();cin.ignore(1000,'\n');}
        system("cls");
        switch(opc){
            case 1: RegisterRobot(cabeza);break;
            case 2: operateFleet(cabeza);break;
            case 3:cout<<"saliendo..."<<endl;releaseFleet(cabeza);break;
            default: cout<<"Error: opcion no valida"<<endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    } while(opc!=3);

    system("pause");
    return 0;
}