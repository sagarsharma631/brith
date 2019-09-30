#include<iostream>
#include<windows.h>
#include<conio.h>
#include<utility>
#include"snake.h"
#include"grid.h"
#include"utilityVar.h"

#define GRID_HEIGHT 25 
#define GRID_WIDTH 100

using namespace std;

snake *snakeInstance = snake::getInstance();
grid *gridInstance = grid::getInstance();
utilityVar *utilityVarInstance = utilityVar::getInstance();
pair<int, int> cachedCoords[25][100];

void initgame(grid **gridInstance, snake **snakeInstance, utilityVar **utilityVarInstance) {
	*gridInstance = grid::getInstance();
	*snakeInstance = snake::getInstance();
	*utilityVarInstance = utilityVar::getInstance();
	// setting necessary variables before game starts
	if (*gridInstance && *snakeInstance && *utilityVarInstance) {
		(*gridInstance)->setHeight(GRID_HEIGHT);
		(*gridInstance)->setWidth(GRID_WIDTH);
		(*gridInstance)->setfruitchar(70);
		(*gridInstance)->setfruitXCoord();
		(*gridInstance)->setfruitYCoord();
		(*gridInstance)->createGrid(cachedCoords);
		(*snakeInstance)->setSnakeHead((*snakeInstance)->createSnakeNode(true));
		(*snakeInstance)->setLastSnakeNode((*snakeInstance)->getSnakeHead());
		(*utilityVarInstance)->setPauseStatus(false);
		(*utilityVarInstance)->setExitCase(false);
		(*utilityVarInstance)->setBestScore(0);
		(*utilityVarInstance)->setCurrScore(0);
		(*utilityVarInstance)->setKeyDir(Direction::NO_DIRECTION);
		(*utilityVarInstance)->setScoreIncrement(5);
		(*utilityVarInstance)->setCurrState(gameState::INIT);
	}
	else {
		throw("something went wrong");
	}
	return;
}

void userInput() {
	int ch;
	utilityVar *utilityVarInstance = utilityVar::getInstance();
	ch = _getch();
	if (ch == 0 || ch == 224) {
		ch = _getch();
	}
	switch (ch) {
	case 72:
		utilityVarInstance->setKeyDir(Direction::UP);
		break;
	case 80:
		utilityVarInstance->setKeyDir(Direction::DOWN);
		break;
	case 77:
		utilityVarInstance->setKeyDir(Direction::RIGHT);
		break;
	case 75:
		utilityVarInstance->setKeyDir(Direction::LEFT);
		break;
	case 112:
		utilityVarInstance->setPauseStatus(true);
		utilityVarInstance->setCurrState(gameState::PAUSED);
		break;
	case 120:
		utilityVarInstance->setPauseStatus(false);
		utilityVarInstance->setCurrState(gameState::PLAYING);
		_getch();
		break;
	default:
		utilityVarInstance->setExitCase(true);
		utilityVarInstance->setCurrState(gameState::EXIT);
		break;
	}
}

void populateCoords(struct snakeFull *curr, struct snakeFull *prev) {
	if (curr == NULL) {
		return;
	}
	populateCoords(curr->next, curr);
	curr->setXCoord(prev->getXCoord());
	curr->setYCoord(prev->getYCoord());
}

// Increases and decreases the coordinates
void playCore() {
	// populate new coordinates for the snake
	populateCoords(snakeInstance->getSnakeHead(), snakeInstance->getSnakeHead());

	switch (utilityVar::getInstance()->getKeyDir()) {
	case Direction::DOWN:
		snakeInstance->getSnakeHead()->setYCoord(snakeInstance->getSnakeHead()->getYCoord() + 1);
		break;
	case Direction::UP:
		snakeInstance->getSnakeHead()->setYCoord(snakeInstance->getSnakeHead()->getYCoord() - 1);
		//head->yCoord = --snakeYCoord;
		break;
	case Direction::LEFT:
		snakeInstance->getSnakeHead()->setXCoord(snakeInstance->getSnakeHead()->getXCoord() - 1);
		//head->xCoord = --snakeXCoord;
		break;
	case Direction::RIGHT:
		snakeInstance->getSnakeHead()->setXCoord(snakeInstance->getSnakeHead()->getXCoord() + 1);
		//head->xCoord = ++snakeXCoord;
		break;
	}
	if (snakeInstance->getSnakeHead()->getXCoord() == 0 || snakeInstance->getSnakeHead()->getXCoord() == gridInstance->getWidth() || snakeInstance->getSnakeHead()->getYCoord() == 0 || snakeInstance->getSnakeHead()->getYCoord() == gridInstance->getHeight()) {
		utilityVarInstance->setExitCase(true);
		utilityVarInstance->setCurrState(gameState::EXIT);
	}
}

void displayMyMenu() {
	system("CLS");
	cout << "1. PLAY - Press X" << endl;
	cout << "2. PAUSE - Press P" << endl;
	cout << "3. SAVE - Press S ( Current data overrides last saved data )" << endl;
	cout << "4. LOAD - Press L ( Loads last saved data )" << endl;
	cout << "5. EXIT - Press ESC" << endl;
	userInput();
	return;
}

void generateFruit() {
	if (snakeInstance->getSnakeHead()->getXCoord() == gridInstance->getfruitXCoord() && snakeInstance->getSnakeHead()->getYCoord() == gridInstance->getfruitYCoord()) {
		std::cout << static_cast<char>(snake::getInstance()->getSnakeHead()->getCharacter());
		// Randomly place a new fruit in the grid.
		gridInstance->setfruitXCoord();
		gridInstance->setfruitYCoord();
		// Incrementing the current score.
		utilityVarInstance->setCurrScore(utilityVarInstance->getCurrScore() + utilityVarInstance->getScoreIncrement());
		utilityVarInstance->setBestScore(gridInstance->fetchBestScore());
		snakeInstance->getLastSnakeNode()->next = snakeInstance->createSnakeNode(false);
		snakeInstance->setLastSnakeNode(snakeInstance->getLastSnakeNode()->next);
	}
}

void populateBoard() {
	system("CLS");
	std::cout << "SCORE : " << utilityVarInstance->getCurrScore() << " BEST : " << utilityVarInstance->getBestScore() << std::endl;
	for (int i = 0;i < GRID_HEIGHT; i++) {
		for (int j = 0;j < GRID_WIDTH;j++) {
			if (snakeInstance->getSnakeHead()->getXCoord() == gridInstance->getfruitXCoord() && snakeInstance->getSnakeHead()->getYCoord() == gridInstance->getfruitYCoord()) {
				std::cout << static_cast<char>(snake::getInstance()->getSnakeHead()->getCharacter());
				generateFruit();
			}
			else if (i == snake::getInstance()->getSnakeHead()->getYCoord() && j == snake::getInstance()->getSnakeHead()->getXCoord()) {
				std::cout << static_cast<char>(snake::getInstance()->getSnakeHead()->getCharacter());
			}
			// create grid lines
			else if (i == 0 || i == (GRID_HEIGHT - 1)) {
				std::cout << "*";
			}
			else if (j == 0 || j == (GRID_WIDTH - 1)) {
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}

			struct snakeFull *tempSnake = snakeInstance->getSnakeHead()->next;
			while (tempSnake != NULL) {
				if (i == tempSnake->yCoord && j == tempSnake->xCoord) {
					std::cout << "\b \b" << static_cast<char>(tempSnake->ch);
				}
				tempSnake = tempSnake->next;
			}

			if (i == gridInstance->getfruitYCoord() && j == gridInstance->getfruitXCoord()) {
				std::cout << "\b \b" << static_cast<char>(gridInstance->getfruitchar());
			}
		}
		std::cout << std::endl;
	}
}

int main(int argc, char *argv[]) {
	// setUp required before starting game.
	grid *gridInstance = NULL;
	snake *snakeInstance = NULL;
	utilityVar *utilityVarInstance = NULL;
	try
	{
		initgame(&gridInstance, &snakeInstance, &utilityVarInstance);
	}
	catch (...) {
		cout << "something went wrong" << endl;
		return 0;
	}

	//while (!utilityVarInstance->getExitCase()) {
	//	if (!utilityVarInstance->getPauseStatus()) {
	//		gridInstance->createGrid();
	//		if (_kbhit()) {
	//			userInput();
	//		}
	//		playCore();
	//	}
	//	else {
	//		displayMyMenu();
	//	}
	//}

	while (utilityVarInstance->getCurrState() != gameState::EXIT) {
		if (utilityVarInstance->getCurrState() != gameState::PAUSED && utilityVarInstance->getCurrState() != gameState::INIT) {
			populateBoard();
			generateFruit();
			if (_kbhit()) {
				userInput();
			}
			playCore();
		}
		else {
			displayMyMenu();
		}
	}

	return 0;
}
