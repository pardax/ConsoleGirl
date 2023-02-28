#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>

static int g_nScreenIndex;
static HANDLE g_hScreen[2];

int g_numofFPS;
clock_t CurTime, OldTime;
char* FPSTextInfo;

char idle1[12500], idle2[12500], idle3[12500];

//vector<string> idle_1, idle_2, idle_3;

using namespace std;

void ScreenInit()
{
    string path_1 = "shaking_1.txt";
    string path_2 = "shaking_2.txt";
    string path_3 = "shaking_3.txt";

    CONSOLE_CURSOR_INFO cci;
    
    string temp;
    string end = "\n";
    ifstream file_1(path_1);
    if (file_1.is_open()) {
        while (getline(file_1, temp)) {
            strcat(idle1, temp.c_str());
            strcat(idle1, end.c_str());
        }
        file_1.close();
    }
    ifstream file_2(path_2);
    if (file_2.is_open()) {
        while (getline(file_2, temp)) {
            strcat(idle2, temp.c_str());
            strcat(idle2, end.c_str());
        }
        file_2.close();
    }
    ifstream file_3(path_3);
    if (file_3.is_open()) {
        while (getline(file_3, temp)) {
            strcat(idle3, temp.c_str());
            strcat(idle3, end.c_str());
        }
        file_3.close();
    }

    // 화면 버퍼 2개를 만든다.
    g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    // 커서를 숨긴다.
    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(g_hScreen[0], &cci);
    SetConsoleCursorInfo(g_hScreen[1], &cci);

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

void TempMethod() {
    cout << idle2;
}

char text[] = "■■";
char text1[] = "■■■";

char* temp;
int _count = 0;
/*
string str = "hello";
char* ch = new char[str.length() + 1];
ch[str.length()] = '\0';
copy(str.begin(), str.end(), ch);
*/
char* ch;

void Render()
{

    ScreenClear();

    
	if (_count == 0) {
        ch = idle1;
		sprintf(FPSTextInfo, ch);
		_count++;
	}
	else if (_count == 1) {
        ch = idle2;
		sprintf(FPSTextInfo, ch);
		_count = 0;
    }
    else if (_count == 2) {
        ch = idle3;
        sprintf(FPSTextInfo, ch);
        _count = 0;
    }
    /*
    if (CurTime - OldTime >= 1000) // 출력 코드
    {

        //fpsTextinfo에 
        OldTime = CurTime;
        g_numofFPS = 0;
    }*/
    Sleep(100);

    g_numofFPS++;
    ScreenPrint(0, 0, FPSTextInfo);

    ScreenFlipping();
}

void Release()
{   
    delete[] FPSTextInfo;
}

char* buff;

int main()
{
    /*
    string str = "hello";
    char* ch = new char[str.length() + 1];
    ch[str.length()] = '\0';
    copy(str.begin(), str.end(), ch);
    cout << ch;
    */
    g_numofFPS = 0;
    FPSTextInfo = new char[13000];
    //memset(FPSTextInfo, '\0', 128 * sizeof(char));
    ScreenInit();

    OldTime = clock(); // 시간을 측정한다. 1초마다 갱신한다.

    while (1)
    {
        CurTime = clock();
        Render();
    }

    Release();
    ScreenRelease();

    return 0;
}