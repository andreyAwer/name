#include <iostream>
using namespace std;

template <typename T_1, typename T_2>
class Base
//в задании нужно писать base но я
//написал для читабельности иначе
{
protected:
    T_1 value_1;
    //для читабельности отделил номер и value
    //для читабельности отделил номер и T

    T_2 value_2;

public:
    Base() { std::cout << "Base()\n"; }
    ~Base() { std::cout << "~Base()\n"; }
    void add_values(T_1 add_1, T_2 add_2)
    {
        std::cout << "add_values(T_1 add_1, T2 add_2)\n";
        this->value_1 = add_1;
        this->value_2 = add_2;
    }
    void display() { std::cout << "display()\n"
                               << this->value_1 << '\n'
                               << this->value_2 << '\n'; }
};

template <typename T_3, typename T_4>
class Child_1 : public Base<signed long int, signed long long int>
//в задании нужно писать child но я
//написал для читабельности иначе
{
private:
    T_3 value_3;
    T_4 value_4;
    //содержит в себе
public:
    Child_1() { std::cout << "Child_1()\n"; }
    ~Child_1() { std::cout << "~Child_1()\n"; }
    void add_values(T_3 add_3, T_4 add_4)
    {
        std::cout << "add_values(T_3 add_3, T4 add_4)\n";
        this->value_3 = add_3;
        this->value_4 = add_4;
    }
    void display() { std::cout << "display()\n"
                               << this->value_3 << '\n'
                               << this->value_4 << '\n'; }
};

template <typename T_5, typename T_6>
class Child_2 : public Base<float, double>
{
private:
    T_5 *value_5=new T_5;
    T_6 *value_6=new T_6;
    //добавляет
public:
    Child_2() { std::cout << "Child_2()\n"; }
    ~Child_2()
    {
        std::cout << "~Child_2()\n";
        delete value_5;
        delete value_6;
    }
    void add_values(T_5 add_5, T_6 add_6)
    {
        std::cout << "add_values(T_5 add_5, T6 add_6)\n";
        *value_5 = add_5;
        *value_6 = add_6;
    }
};

int main()
{
    Base<bool, signed short int> test_1;
    test_1.add_values(false,5000);
    test_1.display();
    Child_1<signed long int, signed long long int> test_2;
    test_2.add_values(100000000,1000000000000000000);
    test_2.display();
    Child_2<float, double> test_3;
    test_3.add_values(0.3f,0.3);
    test_3.display();
}
