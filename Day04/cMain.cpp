#include <stdio.h>
#include <Windows.h>

void SetPosition(int x, int y);

struct Obj
{
	int x;
	int y;
	const char* shape;

};

int main()
{
	Obj player;
	player.x = 10;
	player.y = 10;
	player.shape = "옷";

	while (true)
	{
		system("cls");
		SetPosition(player.x, player.y);
		printf(player.shape);
		Sleep(50);
	}

	return 0;
}

void SetPosition(int x, int y) // 함수이름은 편한대로
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
