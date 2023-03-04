#include <iostream>
using namespace std;
class String
{
protected:
    string value;

public:
    String()
    {
        cout << "String()\n";
        cout << this->value << "\n";
    }
    String(string value)
    {
        this->value = value;
        cout << "String(string value)\n";
        cout << this->value << "\n";
    }
    String(String &string_2)
    {
        this->value = string_2.value;
        cout << "String(String &string_2)\n";
        cout << this->value << "\n";
    }
    void operator=(String &string_2)
    {
        cout << "operator=(String &string_2)\n";
        this->value = string_2.value;
        cout << this->value << "\n";
    }
    int lenght()
    {
        cout << "lenght()\n";
        for (int element_number = 0;; ++element_number)
        {
            if (!this->value[element_number])
            {
                return element_number;
            }
        }
    }
    void reset()
    {
        this->value = "";
        cout << "reset()\n";
        cout << this->value << "\n";
    }
    ~String() { cout << "~String()\n"; }
    string operator+(String &string_2)
    {
        cout << "string operator+(String &string_2)\n";
        return this->value + string_2.value;
    }
    void operator+=(String &string_2)
    {
        cout << "string operator+=(String &string_2)\n";
        value += string_2.value;
        cout << this->value << "\n";
    }
    bool operator==(String &string_2)
    {
        cout << "bool operator==(String &string_2)\n";
        return (this->value == string_2.value);
    }
    bool operator!=(String &string_2)
    {
        cout << "bool operator!=(String &string_2)\n";
        return (this->value != string_2.value);
    }
};

class Bit_string : public String
{
public:
    Bit_string() { std::cout << "Bit_string()\n"; }
    Bit_string(string add_value)
    {
        this->value = add_value;
        cout << "Bit_string(string add_value)\n";
        string new_value;
        // new_value с значением которое будет зависеть от value
        for (int element_number = 0; this->value[element_number]; ++element_number)
        //проверка каждого символа строки
        {
            if ((this->value[element_number] == '0' && new_value[0]) || (this->value[element_number] == '1'))
            {
                new_value += this->value[element_number];
                //прибавление знака к новому значению
            }
            else
            {
                new_value = "";
            }
        }
        this->value = new_value;
        cout << this->value << "\n";
    }
    Bit_string(Bit_string &other_string)
    {
        cout << "Bit_string(Bit_string &other_string)";
        this->value = other_string.value;
        cout << this->value << "\n";
    }
    void operator=(Bit_string &other_string)
    {
        this->value = other_string.value;
        cout << this->value << "\n";
    }
    ~Bit_string() { cout << "~Bit_string()\n"; }
    int operator+(Bit_string &other_string)
    {
        cout << "operator+(Bit_string &other_string)\n";
        int string_start = -1;
        int other_string_start = -1;
        while (this->value[string_start] || string_start == -1)
        {
            string_start++;
        }
        while (other_string.value[other_string_start] || other_string_start == -1)
        {
            other_string_start++;
        }
        string new_value;
        char memory = '0';
        while (other_string_start != -1 && string_start != -1)
        {

            if (other_string_start != -1 && string_start != -1)
            {

                if (other_string.value[other_string_start] == '0' && value[string_start] == '0' && memory == '0')
                {
                    new_value += '0';
                }

                else if (other_string.value[other_string_start] == '0' && value[string_start] == '0' && memory == '1')
                {
                    new_value += '1';
                    new_value += '1';
                    memory = '0';
                }

                else if (other_string.value[other_string_start] == '1' && value[string_start] == '1' && memory == '0')
                {
                    new_value += '0';
                    memory = '1';
                }

                else if (other_string.value[other_string_start] == '1' && value[string_start] == '1' && memory == '1')
                {
                    new_value += '1';
                }

                else if (((other_string.value[other_string_start] == '1' && value[string_start] == '0') || (other_string.value[other_string_start] == '0' && value[string_start] == '1')) && memory == '0')
                {
                    new_value += '1';
                }

                else if (((other_string.value[other_string_start] == '1' && value[string_start] == '0') || (other_string_start == '0' && string_start == '1')) && memory == '1')
                {
                    new_value += '0';
                }
                --other_string_start;
                --string_start;
            }
        }

        while (string_start != -1)
        {
            if (memory == '0')
            {
                new_value += value[string_start];
                --string_start;
            }
            else if (memory == '1')
            {
                if (value[string_start] == '0')
                {
                    new_value += '1';
                    memory = '0';
                    --string_start;
                }
                else if (value[string_start] == '1')
                {
                    new_value += '0';
                    --string_start;
                }
            }
        }
        while (other_string_start != -1)
        {
            if (memory == '0')
            {
                new_value += other_string.value[other_string_start];
                --other_string_start;
            }
            else if (memory == '1')
            {
                if (other_string.value[other_string_start] == '0')
                {
                    new_value += '1';
                    memory = '0';
                    --other_string_start;
                }
                else if (other_string.value[other_string_start] == '1')
                {
                    new_value += '0';
                    --other_string_start;
                }
            }
        }
        if (memory == '1')
        {
            new_value += '1';
        }
        int return_value = 0;
        for (int bit_number = 0, bit_value = 1; new_value[bit_number]; bit_number++)
        {
            if (new_value[bit_number] == '0')
            {
                return_value += 0;
            }
            else if (new_value[bit_number] == '1')
            {
                return_value += bit_value;
            }
            bit_value *= 2;
        }
        return return_value;
    }
    void operator+=(Bit_string &other_string)
    {
        cout << "operator+=(Bit_string &other_string)\n";
        int string_start = -1;
        int other_string_start = -1;
        while (this->value[string_start] || string_start == -1)
        {
            string_start++;
        }
        while (other_string.value[other_string_start] || other_string_start == -1)
        {
            other_string_start++;
        }
        string new_value;
        char memory = '0';
        while (other_string_start != -1 && string_start != -1)
        {

            if (other_string_start != -1 && string_start != -1)
            {

                if (other_string.value[other_string_start] == '0' && value[string_start] == '0' && memory == '0')
                {
                    new_value += '0';
                }

                else if (other_string.value[other_string_start] == '0' && value[string_start] == '0' && memory == '1')
                {
                    new_value += '1';
                    new_value += '1';
                    memory = '0';
                }

                else if (other_string.value[other_string_start] == '1' && value[string_start] == '1' && memory == '0')
                {
                    new_value += '0';
                    memory = '1';
                }

                else if (other_string.value[other_string_start] == '1' && value[string_start] == '1' && memory == '1')
                {
                    new_value += '1';
                }

                else if (((other_string.value[other_string_start] == '1' && value[string_start] == '0') || (other_string.value[other_string_start] == '0' && value[string_start] == '1')) && memory == '0')
                {
                    new_value += '1';
                }

                else if (((other_string.value[other_string_start] == '1' && value[string_start] == '0') || (other_string_start == '0' && string_start == '1')) && memory == '1')
                {
                    new_value += '0';
                }
                --other_string_start;
                --string_start;
            }
        }

        while (string_start != -1)
        {
            if (memory == '0')
            {
                new_value += value[string_start];
                --string_start;
            }
            else if (memory == '1')
            {
                if (value[string_start] == '0')
                {
                    new_value += '1';
                    memory = '0';
                    --string_start;
                }
                else if (value[string_start] == '1')
                {
                    new_value += '0';
                    --string_start;
                }
            }
        }
        while (other_string_start != -1)
        {
            if (memory == '0')
            {
                new_value += other_string.value[other_string_start];
                --other_string_start;
            }
            else if (memory == '1')
            {
                if (other_string.value[other_string_start] == '0')
                {
                    new_value += '1';
                    memory = '0';
                    --other_string_start;
                }
                else if (other_string.value[other_string_start] == '1')
                {
                    new_value += '0';
                    --other_string_start;
                }
            }
        }
        if (memory == '1')
        {
            new_value += '1';
        }
        int new_value_element = 0;
        int add_element = 0;
        while (new_value[new_value_element + 1])
        {
            new_value_element++;
        }
        while (new_value_element != -1)
        {
            this->value[add_element] = new_value[new_value_element];
            new_value_element--;
            add_element++;
        }
        this->value[add_element] = '\0';
    }
    bool operator==(Bit_string &other_string) { return (this->value == other_string.value); }
    bool operator!=(Bit_string &other_string) { return (this->value != other_string.value); }
};
int main()
{
    String test_1;
    String test_2("hello");
    String test_3 = test_2;
    test_3 = test_2;
    std::cout << (test_3 == test_2) << '\n';
    std::cout << (test_3 == test_1) << '\n';
    std::cout << (test_3 != test_2) << '\n';
    std::cout << (test_3 != test_1) << '\n';
    std::cout << (test_3.lenght()) << '\n';
    std::cout << (test_3 + test_3) << '\n';
    test_1 = test_2;
    test_3 += test_3;
    std::cout << (test_1 == test_3) << '\n';
    test_3.reset();
    std::cout << test_3.lenght() << '\n';

    Bit_string test_4;

    Bit_string test_5("100");
    Bit_string test_6("100");
    Bit_string test_7("");

    std::cout << test_5 + test_6 << '\n';
    test_5 += test_6;
    std::cout << test_5 + test_7 << '\n';
}