#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

struct Zodiak {
    string full_name;
    string zodiac_sign;
    int birth_date[3];
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Zodiak people[3];

    for (int i = 0; i < 3; i++) {
        cout << "Введіть прізвище та ім'я: ";
        getline(cin, people[i].full_name);

        cout << "Введіть знак Зодіаку: ";
        getline(cin, people[i].zodiac_sign);

        cout << "Введіть рік народження: ";
        cin >> people[i].birth_date[0];

        cout << "Введіть місяць народження (1-12): ";
        cin >> people[i].birth_date[1];

        cout << "Введіть день народження (1-31): ";
        cin >> people[i].birth_date[2];

        cin.ignore();
    }

    sort(begin(people), end(people), [](const Zodiak& a, const Zodiak& b) {
        return a.birth_date[0] < b.birth_date[0];
        });

    string search_surname;
    cout << "Введіть прізвище для пошуку: ";
    getline(cin, search_surname);

    bool found = false;
    for (const auto& person : people) {
        if (person.full_name.find(search_surname) == 0 &&
            person.full_name.size() > search_surname.size() &&
            person.full_name[search_surname.size()] == ' ') {
            cout << "Інформація про людину:" << endl;
            cout << "Прізвище та ім'я: " << person.full_name << endl;
            cout << "Знак Зодіаку: " << person.zodiac_sign << endl;
            cout << "Дата народження: " << person.birth_date[2] << "."
                << person.birth_date[1] << "."
                << person.birth_date[0] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Такої людини немає." << endl;
    }

    return 0;
}