#include "person.h"

Person::Person(int k1,int k2, int k3)
{
    this->k1=k1;
    this->k2=k2;
    this->k3=k3;
}

void Person::change_k1( QString k1){
    this->k1=k1.toInt();
}
void Person::change_k2( QString k2){
    this->k2=k2.toInt();
}
void Person::change_k3( QString k3){
    this->k3=k3.toInt();

}


