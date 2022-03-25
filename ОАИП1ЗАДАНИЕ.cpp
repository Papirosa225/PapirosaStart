#include <iostream>
#include <ctime>
using namespace std;
void FillArr(int arr[], int length);
void RemoteX(int arr[], int x, int length);
int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    int length, x;
    cout << "Введите количество чисел= ";
    cin >> length;
    int* arr = new int[length];  
    for (int i = 0; i < 6; i++)
    {  
        FillArr(arr, length);
        cout << "Введите число для удаления = ";
        cin >> x;
        RemoteX(arr, x, length);
    }
    delete[]arr;
}
void FillArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand() % 10;
    }
    for (int i = 0; i < length; i++)
    {
        cout << arr[i]<< '\t';
    }
    cout << endl;
}
void RemoteX(int arr[], int x, int length)
{
    int count = 0;
    for (int i = 0,j=0; i < length; i++)
    {
        if (arr[i] != x)
        {
            count++;
        }      
    }
    cout <<"Длинна массива= " << count<< endl;
    int* buffer = new int[count];
    cout << "Массив после удаления "<< endl;
    for (int i = 0,j=0; i < length; i++)
    {
        if (arr[i] != x)
        {
            buffer[j]=arr[i];
            cout << buffer[j]<< '\t';
            j++;
        }
    }
    delete[]buffer;
    cout << endl<<endl;
}