#pragma once

#include<iostream>
#include"utilityVar.h"

struct snakeFull {
	int ch;	// stores what character to print i.e. "S" for snake head, "s" for snake tail.
	int xCoord;	// stores the xCoord
	int yCoord;	// stores the yCoord
	struct snakeFull *next;	// points to next element.
	
	void setCharacter(int ch) {
		this->ch = ch;
		return;
	}

	int getCharacter() const{
		return ch;
	}

	void setXCoord(int xCoord) {
		this->xCoord = xCoord;
		return;
	}


	int getXCoord() const {
		return this->xCoord;
	}

	void setYCoord(int yCoord) {
		this->yCoord = yCoord;
		return;
	}

	int getYCoord() const {
		return this->yCoord;
	}

};

//class snakeFullUtil {
//private:
//	static snakeFullUtil *m_utilPtr;
//	snakeFullUtil();
//	snakeFullUtil(const snakeFullUtil &other) = delete;
//public:
//	static snakeFullUtil* getInstance();
//	// setCharacter(ptr to node, ASCII value of character)
//	void setCharacter(snakeFull* ptr, int ch);
//	void setXCoord(snakeFull* ptr, int xCoord);
//	int getXCoord(snakeFull* ptr) const;
//	void setYCoord(snakeFull* ptr, int yCoord);
//	int getYCoord(snakeFull* ptr) const;
//	~snakeFullUtil();
//};

/*
	Below class is actually a linked list of multiple snakeFull nodes.
	As there will only be a single snake in the game for now, Hence made it singleton.
*/
class snake
{
private:
	static snake *m_snake;
	snake();
	snake(const snake &other) = delete;

	// Member Variables for this pointer.
	struct snakeFull *m_head;
	struct snakeFull *lastAddedNode;

public:
	static snake* getInstance();
	struct snakeFull* createSnakeNode(bool ishead = true, int snakeXCoord = 1, int snakeYCoord = 1);
	void setSnakeHead(struct snakeFull *snake);
	struct snakeFull* getSnakeHead() const;
	void setLastSnakeNode(struct snakeFull *snakeNode);
	struct snakeFull* getLastSnakeNode() const;
	~snake();
protected:

};

