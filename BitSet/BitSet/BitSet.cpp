// BitSet.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


int pow_of_two(int number);


    class BitSet {
    public:
        BitSet(int value);
        bool PushNum(const int& num, int index)
        {
            arr[index] = num;
            return 0;
        }

        void Reset(int index_arr)
        {
            arr[index_arr] = 0;
            
        }

        void Set(int index_arr)
        {
            arr[index_arr] = 1;

        }

        void printElements(int i)
        {
            std::cout << arr[i];
        }
        ~BitSet();

    private:
        int* arr;
        int value;

    };

    int main()
    {
        int size_of_elements;

        unsigned int num;
        std::cout << "Enter element\n";
        std::cin >> num;

        size_of_elements = pow_of_two(num);
        BitSet bit(size_of_elements);

        int index = 1;
        int binary = num % 2;
        bit.PushNum(num, 0);

        while (num >= 1)
        {
            binary = num % 2;
            bit.PushNum(binary, index);
            num /= 2;
            index++;
        }

        for (int i = index - 1; i >= 0; --i)
        {
            bit.Reset(i);
        }

        std::cout << "After Reset \n";
        for (int i = index - 1; i >= 0; --i)
        {
            bit.printElements(i);
        }


        std::cout << "After Set \n";
        for (int i = index - 1; i >= 0; --i)
        {
            bit.Set(i);
        }

        for (int i = index - 1; i >= 0; --i)
        {
            bit.printElements(i);
        }
        
        
        return 0;

    }


    BitSet::BitSet(const int value)
    {
        arr = new int[value];
    }


    BitSet::~BitSet()
    {
        delete[]arr;
    }


    int pow_of_two(int number)
    {
        int pow = 1;
        int count = 1;

        while (number >= pow)
        {
            pow *= 2;
            count++;
        }
        return count;
    }

   

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
