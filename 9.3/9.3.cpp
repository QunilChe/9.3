#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <fstream>
#include <Windows.h>

using namespace std;

struct Base
{
    int number;
    int room;
    int persons;
    char** name;
public:
    Base() { number = room = persons = 0; }
    void set_base();
    void show_base();
    void delete_base();
    void search_number();
    void search_name();
    void search_room();
};

void Base::set_base()
{
    int x = 20;
    int N;
    
    cout << "Persons: ";
    cin >> persons;
    cin.clear();
    cin.sync();
    name = new char* [persons];

    for (int i = 0; i != persons; i++)
    {
        name[i] = new char[x];
    }

    for (int i = 0; i != persons; i++)
    {
        cin >> name[i];
    }

    cout << "Room: ";
    cin >> room;
    cout << "Number: ";
    cin >> number;

}

void Base::show_base()
{
    cout << "Room: " << room << endl;
    cout << "Number: " << number << endl;
    cout << "Staff: " << endl;
    for (int i = 0; i != persons; i++)
    {
        cout << "Name: " << name[i] << endl;
    }
}

void Base::delete_base()
{
    cout << "Deleting base...\n";
    for (int i = 0; i != this->persons; i++)
    {
        delete[] name[i];
    }
    delete[] name;

    cout << "Delete status: Ok\n";
}

void Base::search_room()
{
    int r;
    cout << "Room: ";
    cin >> r;
    if (room == r)
        cout << number << endl;
}

void Base::search_name()
{
    char n[20];
    cin >> n;
    for (int i = 0; i != persons; i++)
    {
        if (!strcmp(name[i], n))
            cout << "Tel: " << number << endl;
    }
}

void Base::search_number()
{
    int n;
    cout << "Tel: ";
    cin >> n;
    if (number == n)
    {
        cout << "Room: " << room << endl;
        cout << "Staff: " << endl;
        for (int i = 0; i != persons; i++)
            cout << name[i] << endl;
    }
}

void set_base(Base* p, int size)
{
    for (int i = 0; i != size; i++)
    {
        p[i].set_base();
    }
}

void show_base(Base* p, int size)
{
    for (int i = 0; i != size; i++)
    {
        p[i].show_base();
    }
}

void delete_base(Base* p, int size)
{
    for (int i = 0; i != size; i++)
    {
        p[i].delete_base();
    }
}

int change_base(Base* p, int pos, int size)
{
    if (pos > size)
    {
        cout << "error: Corrupted data!\n";
        return 1;
    }
    cout << "Changing base: " << pos << endl;
    p[pos].set_base();
    return 0;
}

void search_room(Base* p, int size)
{
    for (int i = 0; i != size; i++)
        p[i].search_room();
}

void search_name(Base* p, int size)
{
    for (int i = 0; i != size; i++)
    {
        p[i].search_name();
    }
}

void search_number(Base* p, int size)
{
    for (int i = 0; i != size; i++)
        p[i].search_number();
}

int main()
{
    SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
    int size;
cout << "vvedit N: "; cin >> size;
int x = 20;

    Base* base;
    base = new Base[size];

    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних з клавіатури" << endl;
        cout << " [2] - вивід даних на екран" << endl;
        cout << " [3] - за номером телефону номер приміщення і список людей" << endl;
        cout << " [4] - за номером приміщення номер телефону" << endl;
        cout << " [5] - за прізвищем службовця видає телефону і номер приміщення" << endl;
        cout << " [0] - вихід та завершення роботи програми" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        cout << endl << endl << endl;

        switch (menuItem)
        {
        case 1:
            set_base(base, size);
            break;
        case 2:
            show_base(base, size);
            break;
        case 3:
            search_number(base, size);
            break;
        case 4:
            search_room(base, size);
            break;
        case 5:
            search_name(base, size);
            break;
        case 6:
            char fname[100]; // ім'я першого файлу
            cout << "enter file name 1: "; cin >> fname;
            ofstream file(fname);
            vector<Base> s;
            for (int i = 0; i < s.size(); ++i)
                file << s[i].number << " " << s[i].room << " " << s[i].persons << " " << s[i].name << "\n";
            file.close();
            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення! "
                "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menuItem != 0);
    

  return 0;
}
