#include <string>
#include <iostream>
using namespace std;
int main()
{
	string text;
	cin >> text;
	int sum = 0;
	int count = 0;
	int BigCount = 0;
	bool CorrectWord = true;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] >= 91)
			count++;
		if (text[0] < 91)
			CorrectWord = false;
		if (text[i] < 91)
			BigCount++;
	}
	if (count > 1  )
	{
		CorrectWord = false;
	}
	if (BigCount == text.length())
	{
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] <= 90)
				text[i] += 32;
		}	
		CorrectWord = false;
	}
	for (int i = 0; i < text.length()&&CorrectWord; i++)
	{
		if (text[0] >= 97)
			text[0] -= 32;
		if (text[i+1] <= 90)
			text[i+1] += 32;
	}
	cout << text;
}
