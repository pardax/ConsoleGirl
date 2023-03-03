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

const int gameDelay = 30;

static int startingText = 0;
static int idleIndex = 0;
static int happyIndex = 0;
static int pieceIndex = 0;
static int pointingIndex = 0;
static int gameIndex = 0;

static int happyCount = 0;
static int pointingCount = 0;
static int peaceCount = 0;

char* Buffer;

char buffer1[12500], buffer2[12500], buffer3[12500], buffer4[12500], buffer5[12500], buffer6[12500], buffer7[12500], buffer8[12500], buffer9[12500];

using namespace std;

#pragma region AnimationLoad
void LoadHappy() {
    string Path_1 = "happy1.txt";
    string Path_2 = "happy2.txt";
    string Path_3 = "happy3.txt";
    string Path_4 = "happy4.txt";
    string end = "\n";
    string temp;
    string text1 = "\n\n\n   감사해요!";
    string text2 = "\n\n\n   그렇게까지 말해주셔서 감사해요!";
    string text3 = "\n\n\n   부끄러워요!";
    ifstream file_1(Path_1);
	if (file_1.is_open()) {
		while (getline(file_1, temp)) {
			strcat(buffer1, temp.c_str());
			strcat(buffer1, end.c_str());
		}
		switch (happyCount) {
		case 0:
			strcat(buffer1, text1.c_str());
			break;
		case 1:
			strcat(buffer1, text2.c_str());
			break;
		case 2:
			strcat(buffer1, text3.c_str());
			break;
		}
		file_1.close();
    }
    ifstream file_2(Path_2);
    if (file_2.is_open()) {
        while (getline(file_2, temp)) {
            strcat(buffer2, temp.c_str());
            strcat(buffer2, end.c_str());
        }
        switch (happyCount) {
        case 0:
            strcat(buffer2, text1.c_str());
            break;

        case 1:
            strcat(buffer2, text2.c_str());
            break;
        case 2:
            strcat(buffer2, text3.c_str());
            break;
        }
        file_2.close();
    }
    ifstream file_3(Path_3);
    if (file_3.is_open()) {
        while (getline(file_3, temp)) {
            strcat(buffer3, temp.c_str());
            strcat(buffer3, end.c_str());
        }
        switch (happyCount) {
        case 0:
            strcat(buffer3, text1.c_str());
            break;
        case 1:
            strcat(buffer3, text2.c_str());
            break;
        case 2:
            strcat(buffer3, text3.c_str());
            break;

        }
        file_3.close();
    }
    ifstream file_4(Path_4);
    if (file_4.is_open()) {
        while (getline(file_4, temp)) {
            strcat(buffer4, temp.c_str());
            strcat(buffer4, end.c_str());
        }
        switch (happyCount) {
        case 0:
            strcat(buffer4, text1.c_str());
            break;

        case 1:
            strcat(buffer4, text2.c_str());
            break;
        case 2:
            strcat(buffer4, text3.c_str());
            break;

        }
        file_4.close();
    }

}
void LoadPiece() {
    string Path_1 = "peace1.txt";
    string Path_2 = "peace2.txt";
    string Path_3 = "peace3.txt";
    string Path_4 = "peace4.txt";
    string Path_5 = "peace5.txt";
    string Path_6 = "peace6.txt";
    string Path_7 = "peace7.txt";
    string Path_8 = "peace8.txt";
    string Path_9 = "peace9.txt";
    string end = "\n";
    string temp;
    string text1 = "\n\n\n   춤추고 노래하는 것을 좋아해요";
    ifstream file_1(Path_1);
    if (file_1.is_open()) {
        while (getline(file_1, temp)) {
            strcat(buffer1, temp.c_str());
            strcat(buffer1, end.c_str());
        }
        switch (peaceCount) {
        case 0:
            strcat(buffer1, text1.c_str());
            break;
        }
        file_1.close();
    }
    ifstream file_2(Path_2);
    if (file_2.is_open()) {
        while (getline(file_2, temp)) {
            strcat(buffer2, temp.c_str());
            strcat(buffer2, end.c_str());
        }
        switch (peaceCount) {
        case 0:
            strcat(buffer2, text1.c_str());
            break;
        }
        file_2.close();
    }
    ifstream file_3(Path_3);
    if (file_3.is_open()) {
        while (getline(file_3, temp)) {
            strcat(buffer3, temp.c_str());
            strcat(buffer3, end.c_str());
        }
        switch (peaceCount) {
        case 0:
            strcat(buffer3, text1.c_str());
            break;
        }
        file_3.close();
    }
    ifstream file_4(Path_4);
    if (file_4.is_open()) {
        while (getline(file_4, temp)) {
            strcat(buffer4, temp.c_str());
            strcat(buffer4, end.c_str());
        }
        switch (peaceCount) {
        case 0:
            strcat(buffer4, text1.c_str());
            break;
        }
        file_4.close();
    }
    ifstream file_5(Path_5);
    if (file_5.is_open()) {
        while (getline(file_5, temp)) {
            strcat(buffer5, temp.c_str());
            strcat(buffer5, end.c_str());
        }
        switch (peaceCount) {
        case 0:
            strcat(buffer5, text1.c_str());
            break;
        }
        file_5.close();
    }
    ifstream file_6(Path_6);
    if (file_6.is_open()) {
        while (getline(file_6, temp)) {
            strcat(buffer6, temp.c_str());
            strcat(buffer6, end.c_str());
        }
        switch (peaceCount) {
        case 0:
            strcat(buffer6, text1.c_str());
            break;
        }
        file_6.close();
    }
    ifstream file_7(Path_7);
    if (file_7.is_open()) {
        while (getline(file_7, temp)) {
            strcat(buffer7, temp.c_str());
            strcat(buffer7, end.c_str());
        }
        switch (peaceCount) {
        case 0:
            strcat(buffer7, text1.c_str());
            break;
        }
        file_7.close();
    }
    ifstream file_8(Path_8);
    if (file_8.is_open()) {
        while (getline(file_8, temp)) {
            strcat(buffer8, temp.c_str());
            strcat(buffer8, end.c_str());
        }
        switch (peaceCount) {
        case 0:
            strcat(buffer8, text1.c_str());
            break;
        }
        file_8.close();
    }
    ifstream file_9(Path_9);
    if (file_9.is_open()) {
        while (getline(file_9, temp)) {
            strcat(buffer9, temp.c_str());
            strcat(buffer9, end.c_str());
        }
        switch (peaceCount) {
        case 0:
            strcat(buffer9, text1.c_str());
            break;
        }
        file_9.close();
    }
}
void LoadPointing() {
    string Path_1 = "pointing.txt";
    string end = "\n";
    string text1 = "\n\n\n   야채가 많이 들어간 햄버거를 좋아해요";
    string text2 = "\n\n\n   가끔씩 피자를 시켜먹는 것을 좋아해요";
    string temp;
    ifstream file_1(Path_1);
    if (file_1.is_open()) {
        while (getline(file_1, temp)) {
            strcat(buffer1, temp.c_str());
            strcat(buffer1, end.c_str());
        }
        switch (pointingCount) {
        case 0:
            strcat(buffer1, text1.c_str());
            break;
        case 1:
            strcat(buffer1, text2.c_str());
            break;
        }
        file_1.close();
    }
}
void LoadIdle() {
    string Path_1 = "Idle.txt";
    string text1 = "\n\n   칭찬한다.";
    string sText1 = "\n\n   ▶칭찬한다.";
    string text2 = "\n\n\n   장점을 물어본다";
    string sText2 = "\n\n\n   ▶장점을 물어본다";
    string text3 = "\n\n\n   좋아하는 음식을 물어본다.";
    string sText3 = "\n\n\n   ▶좋아하는 음식을 물어본다.";
    string end = "\n";
    string temp;

    ifstream file_1(Path_1);
    if (file_1.is_open()) {
        while (getline(file_1, temp)) {
            strcat(buffer1, temp.c_str());
            strcat(buffer1, end.c_str());
        }
        switch (idleIndex) {
        case 0:
            strcat(buffer1, sText1.c_str());
            strcat(buffer1, text2.c_str());
            strcat(buffer1, text3.c_str());
            break;
        case 1:
            strcat(buffer1, text1.c_str());
            strcat(buffer1, sText2.c_str());
            strcat(buffer1, text3.c_str());
            break;
        case 2:
            strcat(buffer1, text1.c_str());
            strcat(buffer1, text2.c_str());
            strcat(buffer1, sText3.c_str());
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
            strcat(buffer1, temp.c_str());
            strcat(buffer1, end.c_str());
        }
        switch (startingText) {
        case 0:
            strcat(buffer1, sText1.c_str());
            break;
        case 1:
            strcat(buffer1, sText2.c_str());
            break;
        case 2:
            strcat(buffer1, sText3.c_str());
            break;
        }
        file_1.close();
    }
    ifstream file_2(shakingPath_2);
    if (file_2.is_open()) {
        while (getline(file_2, temp)) {
            strcat(buffer2, temp.c_str());
            strcat(buffer2, end.c_str());
        }
        switch (startingText) {
        case 0:
            strcat(buffer2, sText1.c_str());
            break;
        case 1:
            strcat(buffer2, sText2.c_str());
            break;
        case 2:
            strcat(buffer2, sText3.c_str());
            break;
        }
        file_2.close();
    }
    ifstream file_3(shakingPath_3);
    if (file_3.is_open()) {
        while (getline(file_3, temp)) {
            strcat(buffer3, temp.c_str());
            strcat(buffer3, end.c_str());
        }
        switch (startingText) {
        case 0:
            strcat(buffer3, sText1.c_str());
            break;
        case 1:
            strcat(buffer3, sText2.c_str());
            break;
        case 2:
            strcat(buffer3, sText3.c_str());
            break;
        }
        file_3.close();
    }
    ifstream file_4(shakingPath_4);
    if (file_4.is_open()) {
        while (getline(file_4, temp)) {
            strcat(buffer4, temp.c_str());
            strcat(buffer4, end.c_str());
        }
        switch (startingText) {
        case 0:
            strcat(buffer4, sText1.c_str());
            break;
        case 1:
            strcat(buffer4, sText2.c_str());
            break;
        case 2:
            strcat(buffer4, sText3.c_str());
            break;
        }
        file_4.close();
    }
}
#pragma endregion Animation Load

#pragma region Buffer Management
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
            ch = buffer1;
		    sprintf(Buffer, ch);
		    _count++;
	    }
	    else if (_count == 1) {
            ch = buffer2;
		    sprintf(Buffer, ch);
		    _count++;
        }
        else if (_count == 2) {
            ch = buffer3;
            sprintf(Buffer, ch);
            _count++;
        }
        else if (_count == 3) {
            ch = buffer4;
            sprintf(Buffer, ch);
            _count = 0;
        }
    }
    else if (gameIndex == 1) {
        ch = buffer1;
        sprintf(Buffer, ch);
    }
    else if (gameIndex == 2){ //happy
        if (_count == 0) {
            ch = buffer1;
            sprintf(Buffer, ch);
            _count++;
        }
        else if (_count == 1) {
            ch = buffer2;
            sprintf(Buffer, ch);
            _count++;
        }
        else if (_count == 2) {
            ch = buffer3;
            sprintf(Buffer, ch);
            _count++;
        }
        else if (_count == 3) {
            ch = buffer4;
            sprintf(Buffer, ch);
            _count = 0;
        }
    }
    else if (gameIndex == 3) {
        if (_count == 0) {
            ch = buffer1;
            sprintf(Buffer, ch);
            _count++;
        }
        else if (_count == 1) {
            ch = buffer2;
            sprintf(Buffer, ch);
            _count++;
        }
        else if (_count == 2) {
            ch = buffer3;
            sprintf(Buffer, ch);
            _count++;
        }
        else if (_count == 3) {
            ch = buffer4;
            sprintf(Buffer, ch);
            _count++;
        }
        else if (_count == 4) {
            ch = buffer5;
            sprintf(Buffer, ch);
            _count++;
        }
        else if (_count == 5) {
            ch = buffer6;
            sprintf(Buffer, ch);
            _count++;
        }
        else if (_count == 6) {
            ch = buffer7;
            sprintf(Buffer, ch);
            _count++;
        }
        else if (_count == 7) {
            ch = buffer8;
            sprintf(Buffer, ch);
            _count++;
        }
        else if (_count == 8) {
            ch = buffer9;
            sprintf(Buffer, ch);
        }
    }
    else if (gameIndex == 4) {
        ch = buffer1;
        sprintf(Buffer, ch);
    }
        

    Sleep(70);
    ScreenPrint(0, 0, Buffer);
    ScreenFlipping();
}

void CleanArray() {
	buffer1[0] = '\0';
	buffer2[0] = '\0';
	buffer3[0] = '\0';
	buffer4[0] = '\0';
	buffer5[0] = '\0';
	buffer6[0] = '\0';
	buffer7[0] = '\0';
	buffer8[0] = '\0';
	buffer9[0] = '\0';
}

void Release()
{   
    delete[] Buffer;
}
#pragma endregion Buffer Management

char* buff;

int main()
{
    //memset(FPSTextInfo, '\0', 128 * sizeof(char));
    bool chk = true;
    int startIndex = 0;
    int selectIndex = 0;

    cout << "Just Talk" << '\n';
    cout << "Start◀" << '\n';
    cout << "Exit" << '\n';

#pragma region Menu
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
#pragma endregion Menu

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &cfi);
    cfi.dwFontSize.X = 10;
    cfi.dwFontSize.Y = 10;
    SetCurrentConsoleFontEx(hOut, NULL, &cfi);
    system("mode con:cols=203 lines=65");

    cout << "(Wating)";
    Sleep(500);
    system("cls");

    Buffer = new char[13000];
    ScreenInit();

#pragma region GameLoop
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
            CleanArray();
            startingText = 1;
            LoadText();
            for (int i = 0; i < gameDelay; i++)
            {
                Render();
            }
            CleanArray();
            startingText = 2;
            LoadText();
            for (int i = 0; i < gameDelay; i++)
            {
                Render();
            }
            CleanArray();
            gameIndex = 1;
            started = true;
        }
        //Phase 2
        LoadIdle();
        Render();

        bool idlechk = true;
        while (idlechk) {
            char c = _getch();
            switch (c) {
            case 'H':
                if (idleIndex == 0) {
                    CleanArray();
                    idleIndex = 2;
                    LoadIdle();
                    Render();
                }
                else if (idleIndex == 1) {
                    CleanArray();
                    idleIndex = 0;
                    LoadIdle();
                    Render();
                }
                else if (idleIndex == 2) {
                    CleanArray();
                    idleIndex = 1;
                    LoadIdle();
                    Render();
                }
                break;
            case 'P':
                if (idleIndex == 0) {
                    CleanArray();
                    idleIndex = 1;
                    LoadIdle();
                    Render();
                }
                else if (idleIndex == 1) {
                    CleanArray();
                    idleIndex = 2;
                    LoadIdle();
                    Render();
                }
                else if (idleIndex == 2) {
                    CleanArray();
                    idleIndex = 0;
                    LoadIdle();
                    Render();
                }
                break;
            case ' ':
                CleanArray();
                //Render();
                idlechk = false;
                break;
            }
        }

        //Phase 3
        int random = rand() % 3;
        switch (idleIndex)
        {
		case 0: //칭찬
            gameIndex = 2;
            _count = 0;
            LoadHappy();
            for (int i = 0; i < gameDelay; i++)
            {
                Render();
            }
            CleanArray();
            gameIndex = 1;
            if (happyCount == 2) 
                happyCount = 0;
            else 
                happyCount++;
            
			break;
		case 1: //특기질문
            gameIndex = 3;
            _count = 0;
            LoadPiece();
            for (int i = 0; i < gameDelay; i++)
            {
                Render();
            }
            CleanArray();
            gameIndex = 1;
			break;
		case 2: //음식질문
            gameIndex = 4;
            LoadPointing();
            for (int i = 0; i < gameDelay; i++)
            {
                Render();
            }
            CleanArray();
            gameIndex = 1;
            if (pointingCount == 1)
                pointingCount = 0;
            else
                pointingCount++;
			break;
        }
    }
#pragma endregion GameLoop

    Release();
    ScreenRelease();

    return 0;
}