#include "grid.h"

grid* grid::m_grid = NULL;

grid* grid::getInstance() {
	if (!m_grid) {
		m_grid = new grid();
	}
	return m_grid;
}

void grid::flushIntTemp() {
	m_temp = 0;
	return;
}

void grid::setWidth(const int &width) {
	m_width = width;
}

int grid::getWidth() const{
	return m_width;
}

void grid::setHeight(const int &height) {
	m_Height = height;
}

int grid::getHeight() const {
	return m_Height;
}

// We do not send any X coordinate to this function because it calculates the X coordinate randomly.
void grid::setfruitXCoord() {
	//flushIntTemp();
	//m_temp = rand() % m_width;
	//m_fruitXCoord = (m_temp <= 0) ? m_temp + 1 : m_temp - 1;	// keep en eye for boundary conditions
	m_fruitXCoord = (rand() % m_width <= 0) ? rand() % m_width + 1 : rand() % m_width - 1;	// keep en eye for boundary conditions
	return;
}
int grid::getfruitXCoord() const {
	return m_fruitXCoord;
}

// We do not send any Y coordinate to this function because it calculates the Y coordinate randomly.
void grid::setfruitYCoord() {
	m_fruitYCoord = (rand() % m_Height <= 0) ? rand() % m_Height - 1 : rand() % m_Height + 1;	// keep en eye for boundary conditions
	return;
}
int grid::getfruitYCoord() const {
	return m_fruitYCoord;
}

void grid::setfruitchar(int ch) {
	m_fruitChar = ch;
	return;
}

int grid::getfruitchar() const {
	return m_fruitChar;
}

int grid::fetchBestScore() {
	utilityVar *temp = utilityVar::getInstance();
	return (temp->getCurrScore() > temp->getBestScore()) ? temp->getCurrScore() : temp->getBestScore();
}

void grid::createGrid(std::pair<int,int> cachedCoords[25][100]) {
	for (int i = 0;i < m_Height; ++i) {
		for (int j = 0;j < m_width; ++j) {
			cachedCoords[i][j] = std::make_pair(i, j);
		}
	}
}

grid::grid()
{
}


grid::~grid()
{
}
