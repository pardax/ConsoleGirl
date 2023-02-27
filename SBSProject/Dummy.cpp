#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <ctime>
#include <string>

static int g_nScreenIndex;
static HANDLE g_hScreen[2];
int g_numofFPS;
clock_t CurTime, OldTime;
char* FPSTextInfo;

using namespace std;

void ScreenInit()
{
    CONSOLE_CURSOR_INFO cci;

    // ȭ�� ���� 2���� �����.
    g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    // Ŀ���� �����.
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


string a[3] ={ "��" , "���" , "����" };
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

    if (CurTime - OldTime >= 1000) // ��� �ڵ�
    {
        if (_count == 0) {
            ch = new char[a[0].length() + 1];
            ch[a[0].length()] = '\n';
            copy(a[0].begin(), a[0].end(), ch);
            sprintf(FPSTextInfo, ch);
            _count++;
        }
        else if (_count == 1) {
            ch = new char[a[1].length() + 1];
            ch[a[1].length()] = '\n';
            copy(a[1].begin(), a[1].end(), ch);
            sprintf(FPSTextInfo, ch);
            _count = 0;
        }

        //fpsTextinfo�� 
        OldTime = CurTime;
        g_numofFPS = 0;
    }

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
    FPSTextInfo = new char[128];
    memset(FPSTextInfo, '\0', 128 * sizeof(char));

    ScreenInit();

    OldTime = clock(); // �ð��� �����Ѵ�. 1�ʸ��� �����Ѵ�.

    while (1)
    {
        CurTime = clock();
        Render();
    }

    Release();
    ScreenRelease();
    
    return 0;
}