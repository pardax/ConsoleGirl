#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <Windows.h>

using namespace std;

class Idle
{
private:
    const string path_1 = "shaking_1.txt";
    const string path_2 = "shaking_2.txt";
    const string path_3 = "shaking_3.txt";

	vector<string> idle_1, idle_2, idle_3;

	static int g_nScreenIndex;
	static HANDLE g_hScreen[2];
	int g_numofFPS;
	clock_t CurTime, OldTime;
	char* FPSTextInfo;

public:
    Idle() {
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
				idle_1.push_back(temp);
			}
			file_2.close();
		}
		ifstream file_3(path_1);
		if (file_3.is_open()) {
			while (getline(file_3, temp)) {
				idle_1.push_back(temp);
			}
			file_3.close();
		}
    }
	void ScreenInit() {
		CONSOLE_CURSOR_INFO cci;	

		//버퍼 생성
		g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

		cci.dwSize = 1;
		cci.bVisible = false;
		SetConsoleCursorInfo(g_hScreen[0], &cci);
		SetConsoleCursorInfo(g_hScreen[1], &cci);

	}

	void ScreenClear() {
		COORD coor = { 0,0 };
		DWORD dw;
		FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 40, coor, &dw);
	}

	void ScreenPrint(char* string) {
		DWORD dw;
		COORD cursorPos = { 0, 0 };
		SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], cursorPos);
		WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);

	}

	void JustPrint() {
		for (int i = 0; i < idle_1.size(); i++)
		{
			cout << idle_1[i] << '\n';
		}
	}

};
//int main()