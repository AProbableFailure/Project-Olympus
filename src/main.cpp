/*
	Compilation Error Checklist :
		- check tasks.json -g flag to make sure all folder paths are there

*/

#define _USE_MATH_DEFINES
#include "Core/Game.h"

#include <iostream>

Game *game = nullptr;

int main(int argc, char* argv[]) {
	std::cout << "Hello World!" << std::endl;
	std::cin.get();
	return 0;
}
