#pragma once
#include<iostream>
#include"snake.h"
#include "utilityVar.h"

class grid
{
private:
	static grid *m_grid;
	int m_width;
	int m_Height;
	int m_fruitXCoord;
	int m_fruitYCoord;
	int m_fruitChar;	// stores the ASCII value of fruit character
	int m_temp;	// This integer variable is used to store any integer type temporary values, Always flush this variable before using it anywhere.
	grid();
	grid(const grid &other) = delete;
	grid& operator=(const grid &other) = delete;

	// member functions
	inline void flushIntTemp();
public:
	static grid* getInstance();
	// set/get width of the grid
	void setWidth(const int &width);
	int getWidth() const;
	// set/get height of the grid
	void setHeight(const int &height);
	int getHeight() const;
	void createGrid(std::pair<int,int> cachedCoords[25][100]);	// This method creates and plots all the objects on the screen
	void setfruitchar(int ch);
	int getfruitchar() const;
	void setfruitXCoord();
	int getfruitXCoord() const;
	void setfruitYCoord();
	int getfruitYCoord() const;
	int fetchBestScore();
protected:
	~grid();
};

