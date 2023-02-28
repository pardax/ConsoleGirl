#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class TempResource
{
private:
	const string path_1 = "shaking_1.txt";
	const string path_2 = "shaking_2.txt";
	const string path_3 = "shaking_3.txt";

	vector<string> idle_1, idle_2, idle_3;

	static int g_nScreenIndex;
	static HANDLE g_hScreen[2];
	char* FPSTextInfo;
	char* ch;

	int _count = 0;

public:
	TempResource() {
		string temp;

		ifstream file_1(path_1);
		if (file_1.is_open()) {
			while (getline(file_1, temp)) {
				idle_1.push_back(temp);
			}
			file_1.close();
		}
		ifstream file_2(path_2);
		if (file_2.is_open()) {
			while (getline(file_2, temp)) {
				idle_2.push_back(temp);
			}
			file_2.close();
		}
		ifstream file_3(path_1);
		if (file_3.is_open()) {
			while (getline(file_3, temp)) {
				idle_3.push_back(temp);
			}
			file_3.close();
		}
	}

	void ScreenFlipping()
	{
		SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
		g_nScreenIndex = !g_nScreenIndex;
	}

	void ScreenClear()
	{
		COORD Coor = { 0, 0 };
		DWORD dw;
		FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 25, Coor, &dw);
	}

	void ScreenRelease()
	{
		CloseHandle(g_hScreen[0]);
		CloseHandle(g_hScreen[1]);
	}

	void ScreenPrint(int x, int y, char* string)
	{
		DWORD dw;
		COORD CursorPosition = { x, y };
		SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
		WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
	}

	void Render()
	{
		char text[] = "бс";
		char text1[] = "бсбс";

		ScreenClear();

		if (_count == 0) {
			ch = text;
			sprintf(FPSTextInfo, ch);
			_count++;
		}
		else if (_count == 1) {
			ch = text1;
			sprintf(FPSTextInfo, ch);
			_count = 0;
		}

		ScreenPrint(0, 0, FPSTextInfo);

		ScreenFlipping();
	}

};
//int main()