#include "snake.h"

snake* snake::m_snake = NULL;

//snakeFullUtil* snakeFullUtil::m_utilPtr = NULL;
//
//snakeFullUtil* snakeFullUtil::getInstance() {
//	if (!m_utilPtr) {
//		m_utilPtr = new snakeFullUtil();
//	}
//	return m_utilPtr;
//}
//
//// setCharacter(ptr to node, ASCII value of character)
//void snakeFullUtil::setCharacter(snakeFull* ptr, int ch) {
//	ptr->ch = ch;
//	return;
//}
//
//void snakeFullUtil::setXCoord(snakeFull* ptr, int xCoord) {
//	ptr->xCoord = xCoord;
//	return;
//}
//
//
//int snakeFullUtil::getXCoord(snakeFull* ptr) const {
//	return ptr->xCoord;
//}
//
//void snakeFullUtil::setYCoord(snakeFull* ptr, int yCoord) {
//	ptr->yCoord = yCoord;
//	return;
//}
//
//int snakeFullUtil::getYCoord(snakeFull* ptr) const {
//	return ptr->yCoord;
//}
//
//snakeFullUtil::~snakeFullUtil() {
//
//}

snake* snake::getInstance() {
	if (!m_snake) {
		m_snake = new snake();
	}
	return m_snake;
}

struct snakeFull* snake::createSnakeNode(bool ishead, int snakeXCoord, int snakeYCoord) {
	struct snakeFull *temp;
	temp = new struct snakeFull;
	temp->ch = (ishead) ? 83 : 115;
	temp->xCoord = snakeXCoord;
	temp->yCoord = snakeYCoord;
	temp->next = NULL;
	if (ishead) {
		lastAddedNode = temp;
	}
	return temp;
}

void snake::setSnakeHead(struct snakeFull *head) {
	if (head) {
		m_head = head;
	}
}

void snake::setLastSnakeNode(struct snakeFull *snakeNode) {
	lastAddedNode = snakeNode;
}

struct snakeFull* snake::getSnakeHead() const {
	return m_head;
}

struct snakeFull* snake::getLastSnakeNode() const {
	return lastAddedNode;
}

snake::snake()
{
}


snake::~snake()
{
}
