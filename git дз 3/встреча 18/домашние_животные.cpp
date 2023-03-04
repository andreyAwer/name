#include <iostream>
using namespace std;
class Pet
{
protected:
    string name;
    //имя
    unsigned int power;
    //сила
};
class Parrot : public Pet
{
public:
    Parrot(string name, unsigned int power)
    {
        this->name = name;
        this->power = power;
        std::cout << name << ' ' << power << '\n';
    }
};
class Dog : public Pet
{
public:
    Dog(string name, unsigned int power)
    {
        this->name = this->name;
        this->power = this->power;
        std::cout << name << ' ' << power << '\n';
    }
};
class Cat : public Pet
{
public:
    Cat(string name, unsigned int power)
    {
        this->name = name;
        this->power = power;
        std::cout << this->name << ' ' << this->power << '\n';
    }
};
int main()
{
    Dog test_1("sada_1", 1);
    Cat test_2("sada_2", 2);
    Parrot test_3("sada_3", 3);
}