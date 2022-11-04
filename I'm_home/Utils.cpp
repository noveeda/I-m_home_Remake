#include "Utils.h"

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
	Colors	color;
	char	ch[3];
	HANDLE	outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	switch ((Object_Type)c)
	{
		case Object_Type::WALL:		color = Colors::WHITE;		strcpy_s(ch, 3, "��");  break;
		case Object_Type::STREET:	color = Colors::ORIGINAL;	strcpy_s(ch, 3, "��");  break;
		case Object_Type::DRUNKEN:	color = Colors::GREEN;		strcpy_s(ch, 3, "��"); break;
		case Object_Type::COP:		color = Colors::RED;		strcpy_s(ch, 3, "��"); break;
		case Object_Type::PUB:		color = Colors::PLUM;		strcpy_s(ch, 3, "��"); break;
		case Object_Type::HOME:		color = Colors::YELLOW;		strcpy_s(ch, 3, "��"); break;
	}

	
	gotoxy(x, y);
	SetConsoleTextAttribute(outputHandle, (WORD)color);
	printf("%s", ch);
	SetConsoleTextAttribute(outputHandle, (WORD)Colors::ORIGINAL);
}

/// <summary>
/// invisible�� true�� �񰡽�ȭ false�� ����ȭ �Ѵ�.
/// </summary>
/// <param name="invisible">Ŀ�� �񰡽ü� ����</param>
void CursorSettings(bool invisible)
{
	CCI cci;
	cci.dwSize = 1;
	cci.bVisible = invisible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

/// <summary>
/// Ŀ���� ũ��, ���ü��� �����Ѵ�
/// </summary>
/// <param name="cursorSize">Ŀ���� ������</param>
/// <param name="invisible">Ŀ�� �񰡽ü� ����</param>
void CursorSettings(int cursorSize, bool invisible)
{
	CCI cci;
	cci.dwSize	 = cursorSize;
	cci.bVisible = invisible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
