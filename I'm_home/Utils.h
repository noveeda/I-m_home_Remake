#include <conio.h>
#include <stdbool.h>
#include <Windows.h>

#define CCI CONSOLE_CURSOR_INFO

void gotoxy(int x, int y);

void DrawChar(int x, int y, char c);

void CursorSettings(bool invisible);

void CursorSettings(int cursorSize, bool invisible);