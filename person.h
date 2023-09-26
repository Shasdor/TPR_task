#ifndef PERSON_H
#define PERSON_H
#include <QString>


class Person
{
private:
    int k1,k2,k3;
public:
    Person(int, int , int );
    void change_k1( QString );
    void change_k2( QString );
    void change_k3( QString );

};

#endif // PERSON_H
