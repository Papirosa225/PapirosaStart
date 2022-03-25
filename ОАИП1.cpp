#include <iostream>
#include <windows.h>
using namespace std;
void UpCaseRus(char text[]);
int main()
{
	setlocale(LC_ALL,"ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char text[200];
	for (int i = 0; i < 6; i++)
	{
		cin.getline(text, 200);
		UpCaseRus(text);
		cout << endl;
	}
}
void UpCaseRus(char text[])
{
	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] > -33 && text[i] < 1 )
			text[i] -=32 ;
	}
	for (int i = 0; i < strlen(text); i++)
	{
		cout << text[i];
	}
}
