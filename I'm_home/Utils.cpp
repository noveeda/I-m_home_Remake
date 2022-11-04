#include "Utils.h"

#pragma warning(disable: 6031 6387)

#define CCI CONSOLE_CURSOR_INFO

// x, y 좌표로 커서 이동
void gotoxy(int x, int y)
{
	COORD pos = { 2 * x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 설정한 위치에 color 색상의 문자 출력
void DrawChar(int x, int y, char c)
{
	Colors	color;
	char	ch[3];
	HANDLE	outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	switch ((Object_Type)c)
	{
		case Object_Type::WALL:		color = Colors::WHITE;		strcpy_s(ch, 3, "■");  break;
		case Object_Type::STREET:	color = Colors::ORIGINAL;	strcpy_s(ch, 3, "□");  break;
		case Object_Type::DRUNKEN:	color = Colors::GREEN;		strcpy_s(ch, 3, "Ｄ"); break;
		case Object_Type::COP:		color = Colors::RED;		strcpy_s(ch, 3, "Ｃ"); break;
		case Object_Type::PUB:		color = Colors::PLUM;		strcpy_s(ch, 3, "Ｐ"); break;
		case Object_Type::HOME:		color = Colors::YELLOW;		strcpy_s(ch, 3, "Ｈ"); break;
	}

	
	gotoxy(x, y);
	SetConsoleTextAttribute(outputHandle, (WORD)color);
	printf("%s", ch);
	SetConsoleTextAttribute(outputHandle, (WORD)Colors::ORIGINAL);
}

/// <summary>
/// invisible이 true면 비가시화 false면 가시화 한다.
/// </summary>
/// <param name="invisible">커서 비가시성 여부</param>
void CursorSettings(bool invisible)
{
	CCI cci;
	cci.dwSize = 1;
	cci.bVisible = invisible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

/// <summary>
/// 커서의 크기, 가시성을 설정한다
/// </summary>
/// <param name="cursorSize">커서의 사이즈</param>
/// <param name="invisible">커서 비가시성 여부</param>
void CursorSettings(int cursorSize, bool invisible)
{
	CCI cci;
	cci.dwSize	 = cursorSize;
	cci.bVisible = invisible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
