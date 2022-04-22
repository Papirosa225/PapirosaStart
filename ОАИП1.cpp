#include <string>
#include <iostream>
using namespace std;
struct ATS
{
        string Data="Неизвестно";
        int Code = 0;
        string City ="Неизвестно";
        int Time=0;
        string Tarif = "Неизвестно";
        int tarif=0;
        int Number = 0;
};
enum Tarifs
{
    Students = 5,
    Budget=10,
    Bachelor=15
};
void AllTimeForCity(ATS Abonent[], int NumberOfCalls);
void MenuInformation(ATS Arr[],int NumberOfCalls);
void ShowInfo(ATS Abonent[],int i);
void ChooseTarif(ATS Abonent[], int i);
void Delete(ATS Abonent[], int NumberOfCalls);
void Sort(ATS Abonent[], int NumberOfCalls);
void EndMenu(ATS Abonent[], int NumberOfCalls);
int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите кол-во звонков: ";
    int NumberOfCalls, NumberOfAction = 0;
    cin >> NumberOfCalls;
    ATS* Abonent = new ATS[NumberOfCalls]{};
    MenuInformation(Abonent,NumberOfCalls);
    EndMenu(Abonent, NumberOfCalls);
}


    void AllTimeForCity(ATS Abonent[],int NumberOfCalls)
    {
        for (int i = 0; i < NumberOfCalls; i++)
        {
            cout << 1 + i << "-й звонок город:" << Abonent[i].City << endl;
        }
        cout << "\n\n";
        string RequiredCity;
        cin >> RequiredCity;
        int TimeSum = 0, CostSum = 0;
        for (int i = 0; i < NumberOfCalls; i++)
        {
            if (RequiredCity == Abonent[i].City)
            {
                TimeSum += Abonent[i].Time;
                CostSum += Abonent[i].Time * Abonent[i].tarif;
            }
        }
        cout << "Общая сумма времени вызова для этого города: " << TimeSum << "c " << "Общая сумма с учетом тарифа: " << CostSum << "монет";
    }
    void MenuInformation(ATS Abonent[], int NumberOfCalls)
    {
        int NumberOfAction;
        for (int i = 0; i < NumberOfCalls;)
        {
            cout << "Выберите номер операции:\n\n1-Установить город\n2-Установить время разговора\n3-Установить тариф\n4-Установить номер\n5-Установить код\n6-Установить дату\n7-Вывести информацию\n8-Закончить работу со звонком\n\n";
            cin >> NumberOfAction;
            switch (NumberOfAction)
            {
            case 1:
            {
                cout << "Введите город: ";
                cin >> Abonent[i].City;
                cout << endl;
                break;
            }
            case 2:
            {
                cout << "Введите время разговора: ";
                cin >> Abonent[i].Time;
                cout << endl;
                break;
            }
            case 3:
            {
                ChooseTarif(Abonent, i);
                break;
            }
            case 4:
            {
                cout << "Введите номер: ";
                cin >> Abonent[i].Number;
                cout << endl;
                break;
            }
            case 5:
            {
                cout << "Введите код: ";
                cin >> Abonent[i].Code;
                cout << endl;
                break;
            }
            case 6:
            {
                cout << "Введите дату: ";
                cin >> Abonent[i].Data;
                cout << endl;
                break;
            }
            case 7:
            {
                ShowInfo(Abonent, i);
                break;
            }
            case 8:
            {
                cout << "Окончание работы с данным разговором\n\n";
                i++;
                break;
            }
            default:
                cout << "Неправильный номер операции\n";
                break;
            }
        }
    }
    void ShowInfo(ATS Abonent[], int i)
    {
        cout << "Город: " << Abonent[i].City << "\nВремя разговора: " << Abonent[i].Time << "\nТариф: " << Abonent[i].Tarif << "\nНомер: " << Abonent[i].Number << "\nКод : " << Abonent[i].Code << "\nДата разговора : " << Abonent[i].Data << "\n\n";
    }
    void ChooseTarif(ATS Abonent[], int i)
    {
        cout << "Выберите тариф:\n1-Студенческий:5р\n2-Бюджентный:10р\n3-Холостяцкий:15р\n\n";
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
        {
            Abonent[i].Tarif = "Студенческий\n";
            Abonent[i].tarif = Students;
            break;
        }
        case 2:
        {
            Abonent[i].Tarif = "Бюджетный\n";
            Abonent[i].tarif = Budget;
            break;
        }
        case 3:
        {
            Abonent[i].Tarif = "Холостяцкий\n";
            Abonent[i].tarif = Bachelor;
            break;
        }
        default:
            cout << "Данный номер тарифа не существует\n";
            break;
        }
    }
    void EndMenu(ATS Abonent[], int NumberOfCalls)
    {
        int NumberOfAction;
        cout << "\n1-Общее время разговора для города\n2-Сортировка по одному полю\n3-Удаление по значению\n\n";
        cin >> NumberOfAction;
        switch (NumberOfAction)
        {
        case 1:
        {
            AllTimeForCity(Abonent, NumberOfCalls);
            break;
        }
        case 2:
            Sort(Abonent, NumberOfCalls);
            break;
        case 3:
            Delete(Abonent, NumberOfCalls);
            break;
        }
    }
    void Sort(ATS Abonent[], int NumberOfCalls)
    {
            int NumberOfAction;
            cout << "Выберите поле для сортировки\n1-Дата\n\n2-Город\n3-Время разговора\n4-Тариф\n\n";
            cin >> NumberOfAction;
            switch (NumberOfAction)
            {
            case 1: // Data Uncomplete
            {
                for (int i = 0; i < NumberOfCalls; i++)
                {
                    for (int j = 0; j < NumberOfCalls - 1; j++)
                    {
                        if ((char)(Abonent[j].Data[0]) + (char)(Abonent[j].Data[1]) + (char)(Abonent[j].Data[3]) + (char)(Abonent[j].Data[4]) + (char)(Abonent[j].Data[6]) + (char)(Abonent[j].Data[7]) + (char)(Abonent[j].Data[8]) + (char)(Abonent[j].Data[9]) > (char)(Abonent[j + 1].Data[0]) + (char)(Abonent[j + 1].Data[1]) + (char)(Abonent[j + 1].Data[3]) + (char)(Abonent[j + 1].Data[4]) + (char)(Abonent[j + 1].Data[6]) + (char)(Abonent[j + 1].Data[7]) + (char)(Abonent[j + 1].Data[8]) + (char)(Abonent[j + 1].Data[9]))
                        {
                            ATS Temporary = Abonent[j];
                            Abonent[j] = Abonent[j + 1];
                            Abonent[j + 1] = Temporary;
                        }
                    }
                }
                for (int i = 0; i < NumberOfCalls; i++)
                {
                    ShowInfo(Abonent, NumberOfCalls);
                }
                break;
            }
            case 3: //City Complete
            {
                for (int i = 0; i < NumberOfCalls; i++)
                {

                    for (int j = 0; j < NumberOfCalls - 1; j++)
                    {
                        if ((char)(Abonent[j].City[0]) > (char)(Abonent[j + 1].City[0]))
                        {
                            ATS Temporary = Abonent[j];
                            Abonent[j] = Abonent[j + 1];
                            Abonent[j + 1] = Temporary;
                        }
                    }
                }
                for (int i = 0; i < NumberOfCalls; i++)
                {
                    ShowInfo(Abonent, NumberOfCalls);
                }
                break;
            }
            case 4: //Time Complete
            {
                for (int i = 0; i < NumberOfCalls; i++) {
                    for (int j = 0; j < NumberOfCalls - 1; j++) {
                        if (Abonent[j].Time > Abonent[j + 1].Time)
                        {
                            ATS Temporary = Abonent[j];
                            Abonent[j] = Abonent[j + 1];
                            Abonent[j + 1] = Temporary;
                        }
                    }
                }
                for (int i = 0; i < NumberOfCalls; i++)
                {
                    ShowInfo(Abonent, NumberOfCalls - i - 1);
                }
                break;
            }
            case 5: //Tarif Complete
            {
                for (int i = 0; i < NumberOfCalls; i++) {
                    for (int j = 0; j < NumberOfCalls - 1; j++) {
                        if (Abonent[j].tarif > Abonent[j + 1].tarif)
                        {
                            ATS Temporary = Abonent[j];
                            Abonent[j] = Abonent[j + 1];
                            Abonent[j + 1] = Temporary;
                        }
                    }
                }
                for (int i = 0; i < NumberOfCalls; i++)
                {
                    ShowInfo(Abonent, NumberOfCalls - i - 1);
                }
                break;
            }
            }
    }
    void Delete(ATS Abonent[], int NumberOfCalls)
    {
            int NumberOfAction;
            cout << "Выберите поле для удаления\n1-Дата\n2-Код\n3-Город\n4-Время разговора\n5-Тариф\n6-Номер\n";
            cin >> NumberOfAction;
            switch (NumberOfAction)
            {
            case 1: // Data
            {
                string DeleteData;
                cout << "Введите дату которую хотите удалить: ";
                cin >> DeleteData;
                for (int i = 0; i < NumberOfCalls; i++)
                {
                    if (DeleteData == Abonent[i].Data)
                    {
                        Abonent[i].Data = "Удалено";
                        break;
                    }
                }
                ShowInfo(Abonent, NumberOfCalls);
                break;
            }
            case 2: //Code
            {
                int DeleteCode;
                cout << "Введите код которую хотите удалить: ";
                cin >> DeleteCode;
                for (int i = 0; i < NumberOfCalls; i++)
                {
                    if (DeleteCode == Abonent[i].Code)
                    {
                        Abonent[i].Code = 0;
                        break;
                    }
                }
                ShowInfo(Abonent, NumberOfCalls);
                break;
            }
            case 3: //City
            {
                string DeleteCity;
                cout << "Введите город которую хотите удалить: ";
                cin >> DeleteCity;
                for (int i = 0; i < NumberOfCalls; i++)
                {
                    if (DeleteCity == Abonent[i].City)
                    {
                        Abonent[i].City = "Удалено";
                        break;
                    }
                }
                ShowInfo(Abonent, NumberOfCalls);
                break;
            }
            case 4: //Time
            {
                int DeleteTime;
                cout << "Введите время разговора которое хотите удалить: ";
                cin >> DeleteTime;
                for (int i = 0; i < NumberOfCalls; i++)
                {
                    if (DeleteTime == Abonent[i].Time)
                    {
                        Abonent[i].Time = 0;
                        break;
                    }
                }
                ShowInfo(Abonent, NumberOfCalls);
                break;
            }
            case 5: //Tarif
            {
                string DeleteTarif;
                cout << "Введите тариф которуй хотите удалить: ";
                cin >> DeleteTarif;
                for (int i = 0; i < NumberOfCalls; i++)
                {
                    if (DeleteTarif == Abonent[i].Tarif)
                    {
                        Abonent[i].tarif = 0;
                        Abonent[i].Tarif = "Удалено";
                        break;
                    }
                }
                ShowInfo(Abonent, NumberOfCalls);
                break;
            }
            case 6: //Number
            {
                int DeleteNumber;
                cout << "Введите номер который хотите удалить: ";
                cin >> DeleteNumber;
                for (int i = 0; i < NumberOfCalls; i++)
                {
                    if (DeleteNumber == Abonent[i].Number)
                    {
                        Abonent[i].Number = 0;
                        break;
                    }
                }
                ShowInfo(Abonent, NumberOfCalls);
                break;
            }
            }
    }
