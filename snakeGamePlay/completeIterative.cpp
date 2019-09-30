#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;

enum Direction {
	UP = 1,
	DOWN,
	RIGHT,
	LEFT,
};

bool canExit = false;
int height = 25;
int width = 100;
int snakeXCoord = 1;//width / 2;
int snakeYCoord = 1;//height / 2;
int fruitXCoord = (rand() % width <= 0) ? rand() % width + 1 : rand() % width - 1;
int fruitYCoord = (rand() % height <= 0) ? rand() % height - 1 : rand() % height + 1;
int currentScore = 0;
int currentMax = 0;
Direction keyDir;	// It stores the direction of key pressed.

struct snakeFull {
	int ch;	// stores what character to print i.e. "S" for snake head, "s" for snake tail.
	int xCoord;	// stores the xCoord
	int yCoord;	// stores the yCoord
	struct snakeFull *next;	// points to next element.
};
struct snakeFull *head;
struct snakeFull *lastSnake;	// This variable actually caches the pointer of last grid in the snake's tail.(I can omit one loop through this caching)
struct snakeFull *tempSnake;

struct snakeFull* createSnakeHead(bool ishead = true) {
	struct snakeFull *temp;
	temp = new struct snakeFull;
	temp->ch = (ishead) ? 83 : 115;
	temp->xCoord = 1;//snakeXCoord;
	temp->yCoord = 1;//snakeYCoord;
	temp->next = NULL;
	return temp;
}

void generateGrid() {
	system("CLS");
	cout << "SCORE : " << currentScore << " BEST : " << currentMax << endl;
	for (int i = 0;i < height; i++) {
		for (int j = 0;j < width;j++) {
			if (snakeXCoord == fruitXCoord && snakeYCoord == fruitYCoord) {
				cout << static_cast<char>(head->ch);
				fruitXCoord = (rand() % width <= 0) ? rand() % width + 1 : rand() % width - 1;
				fruitYCoord = (rand() % height <= 0) ? rand() % height + 1 : rand() % height - 1;
				/*fruitXCoord = rand() % width - 1;
				fruitYCoord = rand() % height + 1;*/
				currentScore += 5;
				currentMax = (currentScore > currentMax) ? currentScore : currentMax;
				lastSnake->next = createSnakeHead(false);
				lastSnake = lastSnake->next;
			}
			else if (i == head->yCoord && j == head->xCoord) {
				cout << static_cast<char>(head->ch);
			}
			// create grid lines
			else if (i == 0 || i == (height-1)) {
				cout << "*";
			}
			else if (j == 0 || j == (width-1)) {
				cout << "*";
			}
			else {
				cout << " ";
			}

			tempSnake = head->next;
			while (tempSnake != NULL) {
				if (i == tempSnake->yCoord && j == tempSnake->xCoord) {
					cout << "\b \b" << static_cast<char>(tempSnake->ch);
				}
				tempSnake = tempSnake->next;
			}

			if (i == fruitYCoord && j == fruitXCoord) {
				cout << "\b \bF";
			}
		}
		cout << endl;
	}
}

void userInput() {
	int ch;
	ch = _getch();
	if (ch == 0 || ch == 224) {
		ch = _getch();
	}
	switch (ch) {
		case 72:
		//case 119:
			keyDir = Direction::UP;
			//cout << "UP"<<endl;
			break;
		case 80:
		//case 115:
			keyDir = Direction::DOWN;
			//cout << "DOWN" << endl;
			break;
		case 77:
		//case 100:
			keyDir = Direction::RIGHT;
			//cout << "RIGHT" << endl;
			break;
		case 75:
		//case 97:
			keyDir = Direction::LEFT;
			//cout << "LEFT" << endl;
			break;
		default:
			canExit = true;
			break;
	}
}

void populateCoords(struct snakeFull *curr, struct snakeFull *prev) {
	if (curr == NULL) {
		return;
	}
	populateCoords(curr->next, curr);
	curr->xCoord = prev->xCoord;
	curr->yCoord = prev->yCoord;
}

// Increases and decreases the coordinates
void playCore() {
	// populate new coordinates for the snake
	populateCoords(head, head);

	switch (keyDir) {
	case Direction::DOWN:
		head->yCoord = ++snakeYCoord;
		break;
	case Direction::UP:
		head->yCoord = --snakeYCoord;
		break;
	case Direction::LEFT:
		head->xCoord = --snakeXCoord;
		break;
	case Direction::RIGHT:
		head->xCoord = ++snakeXCoord;
		break;
	}
	if (head->xCoord == -1 || head->xCoord == width || head->yCoord == -1 || head->yCoord == height) {
		canExit = true;
	}
}

void gameLoadOptions() {
	cout << "Please choose the option below" << endl;
}

int main(int argc, char *argv[]) {
	head = createSnakeHead();
	lastSnake = head;
	
	while(!canExit) {
		generateGrid();
		if (_kbhit()) {
			userInput();
		}
		playCore();
	}
	return 0;
}
