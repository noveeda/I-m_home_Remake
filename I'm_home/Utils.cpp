
#include "Utils.h"
#include "Value.h"

#pragma warning(disable: 6031 6387)

#define CCI CONSOLE_CURSOR_INFO

// x, y ��ǥ�� Ŀ�� �̵�
void gotoxy(int x, int y)
{
	COORD pos = { 2 * x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// ������ ��ġ�� color ������ ���� ���
void DrawChar(int x, int y, char c)
{
	short color = NULL;
	char ch[3];
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	switch (c)
	{
	case WALL:		color = WHITE;		strcpy_s(ch, 3, "��"); break;
	case STREET:	color = DARK_GRAY;	strcpy_s(ch, 3, "��"); break;
	case DRUNKEN:	color = GREEN;		strcpy_s(ch, 3, "��"); break;
	case COP:		color = RED;		strcpy_s(ch, 3, "��"); break;
	case PUB:		color = PINK;		strcpy_s(ch, 3, "��"); break;
	case HOME:		color = YELLOW;		strcpy_s(ch, 3, "��"); break;
	}

	
	gotoxy(x, y);
	SetConsoleTextAttribute(outputHandle, color);
	printf("%s", ch);
	SetConsoleTextAttribute(outputHandle, DEFAULT);
}

void CursorSettings(bool invisible)
{
	CCI cci;
	cci.dwSize = 1;
	cci.bVisible = invisible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void CursorSettings(int cursorSize, bool invisible)
{
	CCI cci;
	cci.dwSize	 = cursorSize;
	cci.bVisible = invisible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
