#include <stdio.h>
#include <Windows.h>

void SetPosition(int x, int y);

struct Obj
{
	int x;
	int y;
	const char* shape;

};

Obj player;

void KeyInput();


int main()
{

	player.x = 10;
	player.y = 10;
	player.shape = "옷";

	while (true)
	{
		system("cls");

		KeyInput();

		SetPosition(player.x, player.y);
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
