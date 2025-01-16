#include <stdio.h>
#include <Windows.h>

enum Color
{
	Black,
	DarkBlue,
	DarkGreen,
	DarkCyan,
	DarkRed,
	DarkMagenta,
	DarkYellow,
	Gray,
	DarkGray,
	Blue,
	Green,
	Cyan,
	Red,
	Magenta,
	Yellow,
	White,
};

void ChangeColor(Color color);
void SetPosition(int x, int y);
void HideCursor();

struct Obj
{
	int x;
	int y;
	Color color;
	const char* shape;

};

Obj player;
Obj enemy;

void KeyInput();


int main()
{
	HideCursor();

	player.x = 10;
	player.y = 10;
	player.color = Yellow;
	player.shape = "■";

	enemy.x = 20;
	enemy.y = 20;
	enemy.color = Magenta;
	enemy.shape = "■";

	while (true)
	{
		system("cls");

		KeyInput();

		SetPosition(enemy.x, enemy.y);
		ChangeColor(enemy.color);
		printf(enemy.shape);

		SetPosition(player.x, player.y);
		ChangeColor(player.color);
		printf(player.shape);
		Sleep(50);
	}

	return 0;
}

void KeyInput()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		player.x--;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		player.x++;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		player.y--;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		player.y++;
	}
}

void SetPosition(int x, int y) // 함수이름은 편한대로
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


//커서 보이는거 방지
void HideCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

//색깔 바꾸기
void ChangeColor(Color color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}