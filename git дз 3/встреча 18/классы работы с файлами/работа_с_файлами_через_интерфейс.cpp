#include <iostream>
#include <fstream>
using namespace std;
class Base
{
public:
    virtual void display(const char *path)
    {
        ifstream take_from_file_to;
        //куда будет отправлено то что взято из файла
        //будет описано после
        take_from_file_to.open(path);

        string file_string;
        //строка принимающая в себя строку файла

        while (!take_from_file_to.eof())
        {
            take_from_file_to >> file_string;
            cout << file_string << '\n';
        }
    };
    //в задании название функции с большой буквы
    //но тогда не будет разницы между видом класса и функции
    //вы вроде не просили писать функции с большой буквы
};
class Child_1 : public Base
{
public:
    void display(const char *path) final override
    {
        ifstream take_from_file_to;
        //куда будет отправлено то что взято из файла
        //будет описано после
        take_from_file_to.open(path);

        string file_string;
        //строка принимающая в себя строку файла

        while (!take_from_file_to.eof())
        {
            take_from_file_to >> file_string;
            for (int number = 0; file_string[number]; ++number)
            {
                cout << (int)file_string[number] << ' ';
            }
            cout << '\n';
        }
    }
};

class Child_2 : public Base
{
public:
    void display(const char *path) final override
    {
        ifstream take_from_file_to;
        //куда будет отправлено то что взято из файла
        //будет описано после
        take_from_file_to.open(path);

        string file_string;
        //строка принимающая в себя строку файла

        while (!take_from_file_to.eof())
        {
            take_from_file_to >> file_string;
            for (int number = 0; file_string[number]; ++number)
            {
                for (unsigned char bit_value = 128; bit_value; bit_value /= 2)
                {
                    if (file_string[number] >= bit_value)
                    {
                        cout << 1;
                        file_string[number] -= bit_value;
                    }
                    else
                    {
                        cout << 0;
                    }
                }
                cout << ' ';
            }
            cout << '\n';
        }
    }
};
int main()
{
    Base test_1;
    test_1.display("file.txt");
    Child_1 test_2;
    test_2.display("file.txt");
    Child_2 test_3;
    test_3.display("file.txt");
}
