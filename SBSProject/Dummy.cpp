#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include <conio.h>

static int g_nScreenIndex;
static HANDLE g_hScreen[2];

char* Buffer;

char idle1[12500], idle2[12500], idle3[12500];

using namespace std;
void LoadText() {
    string shakingPath_1 = "shaking1.txt";
    string shakingPath_2 = "shaking2.txt";
    string shakingPath_3 = "shaking3.txt";
    string shakingPath_4 = "shaking4.txt";
    
    string temp;
    string end = "\n";
    ifstream file_1(shakingPath_1);
    if (file_1.is_open()) {
        while (getline(file_1, temp)) {
            strcat(idle1, temp.c_str());
            strcat(idle1, end.c_str());
        }
        file_1.close();
    }
    ifstream file_2(shakingPath_2);
    if (file_2.is_open()) {
        while (getline(file_2, temp)) {
            strcat(idle2, temp.c_str());
            strcat(idle2, end.c_str());
        }
        file_2.close();
    }
    ifstream file_3(shakingPath_3);
    if (file_3.is_open()) {
        while (getline(file_3, temp)) {
            strcat(idle3, temp.c_str());
            strcat(idle3, end.c_str());
        }
        file_3.close();
    }
}
void ScreenInit()
{
    CONSOLE_CURSOR_INFO cci;

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
    FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 64 * 200, Coor, &dw);
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

int _count = 0;
char* temp;
char* ch;

void Render()
{

    ScreenClear();

    
	if (_count == 0) {
        ch = idle1;
		sprintf(Buffer, ch);
		_count++;
	}
	else if (_count == 1) {
        ch = idle2;
		sprintf(Buffer, ch);
		_count = 0;
    }
    else if (_count == 2) {
        ch = idle3;
        sprintf(Buffer, ch);
        _count = 0;
    }
    Sleep(100);

    ScreenPrint(0, 0, Buffer);

    ScreenFlipping();
}

void Release()
{   
    delete[] Buffer;
}

char* buff;

int main()
{
    
    //memset(FPSTextInfo, '\0', 128 * sizeof(char));

    //Starting Menu
    bool chk = true;
    int startIndex = 0;

    cout << "Just Talk" << '\n';
    cout << "Start◀" << '\n';
    cout << "Exit" << '\n';

    while (chk) {
        char c = _getch();
        switch(c) {
            case 'H':
                startIndex = 0;
                system("cls");
                cout << "Just Talk" << '\n';
                cout << "Start◀" << '\n';
                cout << "Exit" << '\n';
                break;
            case 'P':
                startIndex = 1;
                system("cls");
                cout << "Just Talk" << '\n';
                cout << "Start" << '\n';
                cout << "Exit◀" << '\n';
                break;
            case ' ':
                if (startIndex == 0) {
                    system("cls");
                    chk = false;
                    break;

                }
                else if (startIndex == 1) {
                    break;
                }
        }
    }

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &cfi);
    //cfi.FontWeight = 700;
    cfi.dwFontSize.X = 8;
    cfi.dwFontSize.Y = 8;
    SetCurrentConsoleFontEx(hOut, NULL, &cfi);
    system("mode con:cols=201 lines=65");

    cout << "(Wating)";
    Sleep(5000);
    system("cls");

    Buffer = new char[13000];
    ScreenInit();
    LoadText();

    while (1)
    {
        Render();
    }

    Release();
    ScreenRelease();

    return 0;
}