#include <ctime>
#include <chrono>
#include <time.h>
#include <iostream>
#include <math.h>
using namespace std;
using namespace chrono; int taskMenu()
{
    int variant;
    cout << "Выберите задание: " << endl;
    cout << "1) Создать целочисленный несортированный массив из 100 элементов\n"
        << "2) Отсортировать заданный в пункте 1 массив\n"
        << "3) Найти максимальный и минимальный элемент данного массива\n"
        << "4) Вывести среднее значение максимального и минимального\n"
        << "5) Вывести количество элементов в отсортированном массиве, которые меньше числа a\n"
        << "6) Вывести количество элементов в отсортированном массиве, которые больше числа b\n"
        << "7) Бинарный поиск\n"
        << "8) Смена элементов массива\n"
        << "9) ИДЗ Сортировка слиянием\n" << endl;
    cout << "Задание: ";
    cin >> variant;
    return variant;
}
void quicksort(int* arr, int  end, int begin)
{
    int mid;
    int f = begin;
    int l = end;
    mid = arr[(f + l) / 2];
    while (f < l)
    {
        while (arr[f] < mid) f++;
        while (arr[l] > mid) l--;
        if (f <= l)
        {
            swap(arr[f], arr[l]);
            f++;
            l--;
        }
    }
    if (begin < l) quicksort(arr, l, begin);
    if (f < end) quicksort(arr, end, f);
}
int binarySearch(int arr[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == value) {
            return mid;
        }

        if (arr[mid] > value) {
            return binarySearch(arr, value, start, mid - 1);
        }

        return binarySearch(arr, value, mid + 1, end);
    }

    return -100;
}
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


int main(int argc, char* argv[]) {
    while (true) {
        time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start1, end1;
        nanoseconds result1;
        setlocale(LC_ALL, "Russian");
        srand(time(0));
        int variant = taskMenu();
        const int N = 100;
        int randarr[N], randarr2[N];
        int maxrand = 99, minrand = -99;
        int begin = 0, end = N - 1;
        switch (variant) {
        case 1: {
            cout << "Случайный массив: ";
            for (int i = 0; i < N; ++i) {
                randarr[i] = rand() % (maxrand - minrand + 1) + minrand;
                cout << randarr[i] << " ";
                randarr2[i] = randarr[i];
            }
            cout << endl;
            cout << endl;
        }
              break;
        case 2: {
            cout << "Отсортированный случайный массив: ";
            auto start1 = steady_clock::now();
            quicksort(randarr, end, begin);
            auto end1 = steady_clock::now();
            auto result1 = duration_cast<nanoseconds>(end1 - start1);
            for (int i = 0; i < N; ++i) {
                cout << randarr[i] << " ";
            }
            cout << endl;
            cout << "Время сортировки: " << result1.count() << " наносекунд" << endl;
            cout << endl;
        }
              break;
        case 3: {
            int minarr, maxarr;
            cout << "Случайный массив: ";
            for (int i = 0; i < N; ++i) {
                randarr[i] = rand() % (maxrand - minrand + 1) + minrand;
                cout << randarr[i] << " ";
            }
            cout << endl;
            minarr = randarr[0];
            maxarr = randarr[0];
            auto start1 = steady_clock::now();
            for (int i = 0; i < N; i++) {
                if (randarr[i] < minarr) {
                    minarr = randarr[i];
                }
                if (randarr[i] > maxarr) {
                    maxarr = randarr[i];
                }
            }
            auto end1 = steady_clock::now();
            auto result1 = duration_cast<nanoseconds>(end1 - start1);
            quicksort(randarr, end, begin);
            cout << "Максимальный элемент несортированного массива: " << maxarr << endl << "Минимальный элемент несортированного массива: " << minarr << endl;
            cout << "Время поиска в несортированном массиве: " << result1.count() << " наносекунд" << endl;
            cout << endl;
            auto start = steady_clock::now();
            int minarrel = randarr[0];
            int maxarrel = randarr[N - 1];
            auto end = steady_clock::now();
            auto result = duration_cast<nanoseconds>(end - start);
            cout << "Максимальный элемент сортированного массива: " << maxarrel << endl << "Минимальный элемент сортированного массива: " << minarrel << endl;
            cout << "Время поиска в сортированном массиве: " << result.count() << " наносекунд" << endl;
            cout << endl;

        }
              break;
        case 4: {
            int mid, midsort, maxarrel, minarrel;
            int minarr, maxarr;
            int knesort = 0, ksort = 0;
            int value;
            cout << "Случайный массив: ";
            for (int i = 0; i < N; ++i) {
                randarr[i] = rand() % (maxrand - minrand + 1) + minrand;
                cout << randarr[i] << " ";
            }
            cout << endl;
            minarr = randarr[0];
            maxarr = randarr[0];
            auto start1 = steady_clock::now();
            for (int i = 0; i < N; ++i) {
                if (randarr[i] > maxarr) {
                    maxarr = randarr[i];
                }
                if (randarr[i] < minarr) {
                    minarr = randarr[i];
                }
            }
            mid = round((maxarr - minarr) / 2);
            cout << endl;
            cout << "Среднее значение максимального и минимального в несортированном массиве: " << mid << endl;
            for (int i = 0; i < N; i++) {
                if (randarr[i] == mid) {
                    cout << i << " - й элемент массива является его средним значением" << endl;
                    knesort += 1;
                }
            }
            auto end1 = steady_clock::now();
            auto result1 = duration_cast<nanoseconds>(end1 - start1);
            cout << "Количество элементов массива равных его среднему значению: " << knesort << endl;
            cout << "Время поиска: " << result1.count() << " наносекунд" << endl;
            cout << endl;
            cout << endl;
            quicksort(randarr, end, begin);
            cout << "Отсортированный случайный массив: ";
            for (int i = 0; i < N; ++i) {
                cout << randarr[i] << " ";
            }
            cout << endl;
            maxarrel = randarr[N - 1];
            minarrel = randarr[0];
            midsort = round((maxarrel - minarrel) / 2);
            cout << endl;
            cout << "Среднее значение максимального и минимального в сортированном массиве: " << midsort << endl;
            auto start2 = steady_clock::now();
            value = binarySearch(randarr, midsort, begin, end);
            if (value == -100) {
                cout << "В данном массиве нет элемента равного среднему" << endl;
            }
            else {
                for (int i = 0; i < N; i++) {
                    if (randarr[i] == value) {
                        cout << i << " - й элемент массива является его средним значением" << endl;
                        ksort += 1;
                    }
                }
            }
            auto end2 = steady_clock::now();
            auto result2 = duration_cast<nanoseconds>(end2 - start2);
            cout << "Количество элементов массива равных его среднему значению: " << ksort << endl;
            cout << "Время поиска: " << result2.count() << " наносекунд" << endl;
            cout << endl;
        }
              break;
        case 5: {
            int a;
            int counter = 0;
            cout << "Случайный массив: ";
            for (int i = 0; i < N; ++i) {
                randarr[i] = rand() % (maxrand - minrand + 1) + minrand;
                cout << randarr[i] << " ";
            }
            quicksort(randarr, end, begin);
            cout << endl;
            cout << "Введите значение числа a: ";
            cin >> a;
            cout << endl;
            cout << "Отсортированный случайный массив: ";
            for (int i = 0; i < N; ++i) {
                cout << randarr[i] << " ";
                if (a > randarr[i]) {
                    counter++;
                }
                else {
                    break;
                }
            }
            cout << endl;
            cout << "Количество элементов меньших " << a << ": " << counter << endl;
            cout << endl;
        }
              break;
        case 6: {
            int b;
            int counter = 0;
            cout << "Случайный массив: ";
            for (int i = 0; i < N; ++i) {

            
                    randarr[i] = rand() % (maxrand - minrand + 1) + minrand;
                cout << randarr[i] << " ";
            }
            quicksort(randarr, end, begin);
            cout << endl;
            cout << "Введите значение числа b: ";
            cin >> b;
            cout << endl;
            cout << "Отсортированный случайный массив: ";
            for (int i = 0; i < N; ++i) {
                cout << randarr[i] << " ";
                if (b < randarr[i]) {
                    counter++;
                }
                else {
                    break;
                }
            }
            cout << endl;
            cout << "Количество элементов больших " << b << ": " << counter << endl;
            cout << endl;
        }
              break;
        case 7: {
            int num, value;
            for (int i = 0; i < N; ++i) {
                randarr[i] = rand() % (maxrand - minrand + 1) + minrand;
            }
            quicksort(randarr, end, begin);
            cout << "Отсортированный массив: ";
            for (int i = 0; i < N; ++i) {
                cout << randarr[i] << " ";
            }
            cout << endl << "Введите число которое необходимо найти: ";
            cin >> num;
            cout << endl;
            auto start1 = steady_clock::now();
            value = binarySearch(randarr, num, begin, end);
            auto end1 = steady_clock::now();
            auto result1 = duration_cast<nanoseconds>(end1 - start1);
            auto start2 = steady_clock::now();
            for (int i = 0; i < N; ++i) {
                if (randarr[i] == num) {
                    value = randarr[i];
                    break;
                }
                else {
                    value = -100;
                }
            }
            if (value != -100) {
                cout << "Введённое число есть в отсортированном массиве" << endl;
            }
            else {
                cout << "Введённое число отсутствует" << endl;
            }
            auto end2 = steady_clock::now();
            auto result2 = duration_cast<nanoseconds>(end2 - start2);
            cout << endl;
            cout << "Время затраченное на Бинарный поиск: " << result1.count() << " наносекунд" << endl;
            cout << "Время затраченное на Поиск перебором: " << result2.count() << " наносекунд" << endl;
            cout << endl;

            
        }
              break;
        case 8: {
            int a, b;
            bool check = true;
            cout << "Случайный массив: ";
            for (int i = 0; i < N; ++i) {
                randarr[i] = rand() % (maxrand - minrand + 1) + minrand;
                cout << randarr[i] << " ";
            }
            cout << endl;
            cout << endl << "Введите индекс первого элемента(от 0 до 99): ";
            cin >> a;
            while (check) {
                if (a < 0 or a > 99) {
                    cout << "Несоответствие количеству элементов массива попробуйте ещё раз" << endl;
                    cout << "Введите индекс первого элемента(от 0 до 99): ";
                    cin >> a;
                    cout << endl;
                }
                else {
                    check = false;
                }
            }
            check = true;
            cout << endl << "Введите индекс второго элемента(от 0 до 99): ";
            cin >> b;
            while (check) {
                if (b < 0 or b > 99) {
                    cout << "Несоответствие количеству элементов массива попробуйте ещё раз" << endl;
                    cout << "Введите индекс второго элемента(от 0 до 99): ";
                    cin >> b;
                    cout << endl;
                }
                else {
                    check = false;
                }
            }
            auto start1 = steady_clock::now();
            swap(randarr[a], randarr[b]);
            auto end1 = steady_clock::now();
            auto result1 = duration_cast<nanoseconds>(end1 - start1);
            cout << endl << "Изменённый массив: ";
            for (int i = 0; i < N; ++i) {
                cout << randarr[i] << " ";
            }
            cout << endl;
            cout << "Время затраченное на смену мест: " << result1.count() << " наносекунд";
            cout << endl << endl;
        }
              break;
        case 9: {
            cout << "Случайный массив: ";
            for (int i = 0; i < N; ++i) {
                randarr[i] = rand() % (maxrand - minrand + 1) + minrand;
                cout << randarr[i] << " ";
                randarr2[i] = randarr[i];
            }
            auto start1 = steady_clock::now();
            mergeSort(randarr, 0, N - 1);
            auto end1 = steady_clock::now();
            auto result1 = duration_cast<nanoseconds>(end1 - start1);
            auto start2 = steady_clock::now();
            quicksort(randarr2, end, begin);
            auto end2 = steady_clock::now();
            auto result2 = duration_cast<nanoseconds>(end2 - start2);
            cout << endl << endl;
            cout << "Результат сортировки слиянием: ";
            for (int i = 0; i < N; ++i) {
                cout << randarr[i] << " ";
            }
            cout << endl << endl;
            cout << "Время затраченное на сортировку слиянием: " << result1.count() << " наносекунд" << endl;
            cout << "Время сортировки этого же массива быстрой сортировкой: " << result2.count() << " наносекунд" << endl << endl;
        }
              break;
        default:
            cout << "ОШИБКА: Некорректный ввод";
            exit(EXIT_FAILURE);
        }

    }
}