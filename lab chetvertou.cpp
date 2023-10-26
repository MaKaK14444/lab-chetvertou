#include <iostream>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");

    cout << "\n[+] Программа лабораторных" << endl;
    cout << "\n[*] Введите номер задания" << endl;
    cout << "\n[1] - последовательности целых чисел." << endl;
    cout << "\n[2] - Найдите сумму  1+2+3+…+n." << endl;
    cout << "\n[3] - Написать программу, которая выводит количество чисел в массиве." << endl;
    cout << "\n[4] -  В программе задан одномерный массив X c n элементами." << endl;
    cout << "\n[5] - отсортировать список участников олимпиады." << endl;
    cout << "\n[6] - Напишите программу перевода числа из одной системы счисления в другую." << endl;
    int variant;
    cin >> variant;
    const int max = 10;
    int count = 0;
    int little = 0;
    int massive[max];

    switch (variant) {
    case 1:
        cout << "Введите последовательность из 10 целых чисел: " << endl;
        int i = 0;
        while (i < max)
        {
            cin >> massive[i];
            i++;
        }
        little = massive[i];
        for (i = 0; i < max; ++i)
        {
            if (massive[i] < little)
                little = massive[i];
        }
        for (i = 0; i < max; ++i)
        {
            if (massive[i] == little)
                count++;
        }
        cout << ("Наименьшее введённое число:         ", little, "\n", "Встретилось: ", count, "раз") << endl;
        return 0;
        break;
    case 2:
        cout << "vvedite predel: ";
        int predel, c = 0; cin >> predel;
        for (int i = 0; i <= (predel); i++)
        {
            c += i;
        }
        cout << c;
        return 0;
        break;
    case 3:
        cout << "Введите размер массива: ";
        int n, sum = 0;
        cin >> n;
        int* a = new int[n];
        cout << "Запишите элементы массива:" << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " элемент: ";
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            if (a[i] % 3 == 0) {
                sum += a[i];
            }
        }
        cout << "Сумма элементов кратных 3 = " << sum << endl;
        delete[] a;
        return 0;

    case 4:
        const int N = 5;
        int a[N], max = -1000000000, min = 1000000000;
        cout << "Введите значение элементов: " << endl;
        for (int i = 0; i < N; i++)
            cin >> a[i];
        for (int i = 1; i < N; i++)
            if (a[i] > max)
                max = a[i];
        for (int i = 0; i < N; i++)
            if (a[i] < min)
                min = a[i];
        cout << "Минимальный элемент массива: " << min << endl;
        cout << "Максимальный элемент массива: " << max << endl;
        system("PAUSE >> null");
        return 0;
        break;

    case 5:
        int n; // Количество участников
        cout << "Введите количество участников: ";
        cin >> n;

        int* id = new int[n]; // Массив идентификационных номеров
        int* score = new int[n]; // Массив набранных баллов

        // Ввод идентификационного номера и набранных баллов для каждого участника
        for (int i = 0; i < n; i++) {
            cout << "Введите идентификационный номер и количество баллов для участника " << i + 1 << ": ";
            cin >> id[i] >> score[i];
        }

        // Сортировка участников по количеству набранных ими баллов (сортировка пузырьком)
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (score[j] < score[j + 1]) {
                    // Поменять местами идентификационные номера и количества баллов
                    int tempId = id[j];
                    int tempScore = score[j];
                    id[j] = id[j + 1];
                    score[j] = score[j + 1];
                    id[j + 1] = tempId;
                    score[j + 1] = tempScore;
                }
            }
        }

        // Вывод отсортированного списка участников
        cout << "Отсортированный список участников:\n";
        for (int i = 0; i < n; i++) {
            cout << "Участник " << i + 1 << ": " << "ID: " << id[i] << ", Баллы: " << score[i] << "\n";
        }

        delete[] id;
        delete[] score;

        return 0;

    case 6:
        string num;
        int baseFrom, baseTo;

        cout << "Введите число: ";
        cin >> num;

        cout << "Введите исходную систему счисления: ";
        cin >> baseFrom;

        cout << "Введите целевую систему счисления: ";
        cin >> baseTo;

        int decNum = 0; // Число в десятичной системе счисления
        int power = 1; // Текущая степень

        // Перевод числа в десятичную систему счисления
        for (int i = num.length() - 1; i >= 0; i--) {
            int digit;
            if (num[i] >= '0' && num[i] <= '9') {
                digit = num[i] - '0';
            }
            else if (num[i] >= 'A' && num[i] <= 'Z') {
                digit = num[i] - 'A' + 10;
            }
            else if (num[i] >= 'a' && num[i] <= 'z') {
                digit = num[i] - 'a' + 10;
            }
            else {
                cout << "Ошибка: неверное число!" << endl;
                return 0;
            }

            if (digit >= baseFrom) {
                cout << "Ошибка: неверное число!" << endl;
                return 0;
            }

            decNum += digit * power;
            power *= baseFrom;
        }

        // Перевод числа из десятичной системы счисления в новую систему
        string result = "";
        while (decNum > 0) {
            int digit = decNum % baseTo;
            if (digit < 10) {
                result = to_string(digit) + result;
            }
            else {
                result = char(digit - 10 + 'A') + result;
            }
            decNum /= baseTo;
        }

        cout << "Результат: " << result << endl;
        return 0;
    }
}

