#pragma once

int main();
int Random(int min, int max)
{
	return min + rand() % (max - min);
}
