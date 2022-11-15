#include "Value.h"

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <memory.h>

#define CCI CONSOLE_CURSOR_INFO


void gotoxy(int x, int y);

void DrawChar(int x, int y, char c);

void CursorSettings(bool invisible);

void CursorSettings(int cursorSize, bool invisible);