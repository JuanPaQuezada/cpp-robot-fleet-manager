//Starting header guards
#ifndef FLOTAROBOTS_H
#define FLOTAROBOTS_H

#include <iostream>
#include <string>

using namespace std;

struct Hardware{
    string NoSerie;
    int battery;
};

class Robot{
    protected:
        Hardware har;
    public:
        //Constructor 1
        Robot(string, int);
        //Constructor 2
        Robot(string);
        virtual void operar() = 0;
        virtual  ~Robot(){}
};

class Dron: public Robot{
    private:
        float maxHeight;
    public:
        Dron(string,int,float);
        void operar() override{
            cout<<"Drone "<<har.NoSerie<<" can reach an altitude of  "<<maxHeight<<" meters with "<<har.battery<<"% battery left";
        }
};
class IndustrialRobot: public Robot{
    private:
        float maxLoad;
    public:
        IndustrialRobot(string,int,float);
        void operar() override{
            cout<<"Arm "<<har.NoSerie<<" is assembling parts bearing "<<maxLoad<<"kg with "<<har.battery<<" battery";
        }
};
struct NodoFlota{
    Robot* robot;
    NodoFlota* siguiente;
};
void RegisterRobot(NodoFlota*& cabeza);
void operateFleet(NodoFlota* cabeza);
void releaseFleet(NodoFlota* cabeza);

#endif