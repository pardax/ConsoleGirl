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

const int gameDelay = 10;

static int startingText = 0;
static int idleIndex = 0;
static int happyIndex = 0;
static int pieceIndex = 0;
static int pointingIndex = 0;
static int gameIndex = 0;

char* Buffer;

char idle1[12500], idle2[12500], idle3[12500], idle4[12500];
char trueIdle[12500];
char happy1[12500], happy2[12500], happy3[12500], happy4[12500];
char piece1[12500], piece2[12500], piece3[12500], piece4[12500], piece5[12500], piece6[12500], piece7[12500], piece8[12500], piece9[12500];
char pointing[12500];

using namespace std;
void LoadHappy() {
    string Path_1 = "happy1.txt";
    string Path_2 = "happy2.txt";
    string Path_3 = "happy3.txt";
    string Path_4 = "happy4.txt";
    string end = "\n";
    string temp;
}
void LoadPiece() {
    string Path_1 = "happy1.txt";
    string Path_2 = "happy2.txt";
    string Path_3 = "happy3.txt";
    string Path_4 = "happy4.txt";
    string end = "\n";
    string temp;
}
void LoadPointing() {
    string Path_1 = "happy1.txt";
    string Path_2 = "happy2.txt";
    string Path_3 = "happy3.txt";
    string Path_4 = "happy4.txt";
    string end = "\n";
    string temp;
}
void LoadIdle() {
    string Path_1 = "Idle.txt";
    string text1 = "\n\n   무슨 음식 좋아해?";
    string sText1 = "\n\n   ▶무슨 음식 좋아해?";
    string text2 = "\n\n\n   무엇이 특기야?";
    string sText2 = "\n\n\n   ▶무엇이 특기야?";
    string text3 = "\n\n\n   칭찬한다.";
    string sText3 = "\n\n\n   ▶칭찬한다.";
    string end = "\n";
    string temp;

    ifstream file_1(Path_1);
    if (file_1.is_open()) {
        while (getline(file_1, temp)) {
            strcat(trueIdle, temp.c_str());
            strcat(trueIdle, end.c_str());
        }
        switch (idleIndex) {
        case 0:
            strcat(trueIdle, sText1.c_str());
            strcat(trueIdle, text2.c_str());
            strcat(trueIdle, text3.c_str());
            break;
        case 1:
            strcat(trueIdle, text1.c_str());
            strcat(trueIdle, sText2.c_str());
            strcat(trueIdle, text3.c_str());
            break;
        case 2:
            strcat(trueIdle, text1.c_str());
            strcat(trueIdle, text2.c_str());
            strcat(trueIdle, sText3.c_str());
            break;
        }
        file_1.close();
    }
}

void LoadText() {
    string shakingPath_1 = "shaking1.txt";
    string shakingPath_2 = "shaking2.txt";
    string shakingPath_3 = "shaking3.txt";
    string shakingPath_4 = "shaking4.txt";
    
    string temp;
    string end = "\n";
    string sText1 = "\n\n\n   처음뵙겠습니다";
    string sText2 = "\n\n\n   이 게임은 간단하게 대화를 나누는 게임이에요";
    string sText3 = "\n\n\n   앞으로 잘 부탁드려요";
    ifstream file_1(shakingPath_1);
    if (file_1.is_open()) {
        while (getline(file_1, temp)) {
            strcat(idle1, temp.c_str());
            strcat(idle1, end.c_str());
        }
        switch (startingText) {
        case 0:
            strcat(idle1, sText1.c_str());
            break;
        case 1:
            strcat(idle1, sText2.c_str());
            break;
        case 2:
            strcat(idle1, sText3.c_str());
            break;
        }
        file_1.close();
    }
    ifstream file_2(shakingPath_2);
    if (file_2.is_open()) {
        while (getline(file_2, temp)) {
            strcat(idle2, temp.c_str());
            strcat(idle2, end.c_str());
        }
        switch (startingText) {
        case 0:
            strcat(idle2, sText1.c_str());
            break;
        case 1:
            strcat(idle2, sText2.c_str());
            break;
        case 2:
            strcat(idle2, sText3.c_str());
            break;
        }
        file_2.close();
    }
    ifstream file_3(shakingPath_3);
    if (file_3.is_open()) {
        while (getline(file_3, temp)) {
            strcat(idle3, temp.c_str());
            strcat(idle3, end.c_str());
        }
        switch (startingText) {
        case 0:
            strcat(idle3, sText1.c_str());
            break;
        case 1:
            strcat(idle3, sText2.c_str());
            break;
        case 2:
            strcat(idle3, sText3.c_str());
            break;
        }
        file_3.close();
    }
    ifstream file_4(shakingPath_4);
    if (file_4.is_open()) {
        while (getline(file_4, temp)) {
            strcat(idle4, temp.c_str());
            strcat(idle4, end.c_str());
        }
        switch (startingText) {
        case 0:
            strcat(idle4, sText1.c_str());
            break;
        case 1:
            strcat(idle4, sText2.c_str());
            break;
        case 2:
            strcat(idle4, sText3.c_str());
            break;
        }
        file_4.close();
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

int _count = 0;
char* temp;
char* ch;

void Render()
{
    ScreenClear();
    if (gameIndex == 0) {
	    if (_count == 0) {
            ch = idle1;
		    sprintf(Buffer, ch);
		    _count++;
	    }
	    else if (_count == 1) {
            ch = idle2;
		    sprintf(Buffer, ch);
		    _count++;
        }
        else if (_count == 2) {
            ch = idle3;
            sprintf(Buffer, ch);
            _count++;
        }
        else if (_count == 3) {
            ch = idle4;
            sprintf(Buffer, ch);
            _count = 0;
        }
    }
    else if (gameIndex == 1) {
        ch = trueIdle;
        sprintf(Buffer, ch);
    }

    Sleep(70);
    ScreenPrint(0, 0, Buffer);
    ScreenFlipping();
}

void CleanArray(int index) {
    if (index == 0) {
        idle1[0] = '\0';
        idle2[0] = '\0';
        idle3[0] = '\0';
        idle4[0] = '\0';
    }
    else if (index == 1) {
        trueIdle[0] = '\0';
    }

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
    int selectIndex = 0;

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
                    exit(3);
                    break;
                }
        }
    }

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &cfi);
    //cfi.FontWeight = 700;
    cfi.dwFontSize.X = 10;
    cfi.dwFontSize.Y = 10;
    SetCurrentConsoleFontEx(hOut, NULL, &cfi);
    system("mode con:cols=203 lines=65");

    cout << "(Wating)";
    Sleep(500);
    system("cls");

    Buffer = new char[13000];
    ScreenInit();

    bool started = false;
    while (1)
    {
        //Phase 1
        if (!started) {
            LoadText();
            for (int i = 0; i < gameDelay; i++)
            {
                Render();
            }
            CleanArray(0);
            startingText = 1;
            LoadText();
            for (int i = 0; i < gameDelay; i++)
            {
                Render();
            }
            CleanArray(0);
            startingText = 2;
            LoadText();
            for (int i = 0; i < gameDelay; i++)
            {
                Render();
            }
            CleanArray(0);
            gameIndex = 1;
            started = true;
        }
        //Phase 2
        LoadIdle();
        Render();

        while (1) {
            char c = _getch();
            switch (c) {
            case 'H':
                if (idleIndex == 0) {
                    CleanArray(1);
                    idleIndex = 2;
                    LoadIdle();
                    Render();
                }
                else if (idleIndex == 1) {
                    CleanArray(1);
                    idleIndex = 0;
                    LoadIdle();
                    Render();
                }
                else if (idleIndex == 2) {
                    CleanArray(1);
                    idleIndex = 1;
                    LoadIdle();
                    Render();
                }
                break;
            case 'P':
                if (idleIndex == 0) {
                    CleanArray(1);
                    idleIndex = 1;
                    LoadIdle();
                    Render();
                }
                else if (idleIndex == 1) {
                    CleanArray(1);
                    idleIndex = 2;
                    LoadIdle();
                    Render();
                }
                else if (idleIndex == 2) {
                    CleanArray(1);
                    idleIndex = 0;
                    LoadIdle();
                    Render();
                }
                break;
            case ' ':
                CleanArray(1);
                Render();
                break;
            }
        }

        //Phase 3
    }

    Release();
    ScreenRelease();

    return 0;
}