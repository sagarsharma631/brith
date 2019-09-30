#pragma once

// Following enum handles the direction of the keys pressed.s
enum Direction {
	NO_DIRECTION = 1,
	UP,
	DOWN,
	RIGHT,
	LEFT,
};

// Following enum handles the state of the game.
enum gameState {
	INIT = 1,
	LOAD,
	PLAYING,
	PAUSED,
	SAVE,
	EXIT,
};

class utilityVar
{
private:
	static utilityVar *m_ptr;
	bool m_canExit;		// exit game totally
	int m_currScore;	// current score
	int m_bestScore;	// best score
	int m_scoreIncrement;	// by how much amount the score should be incremented
	bool m_isPaused;	// pause game for a moment
	enum gameState m_currState;	// stores the current state of the game
	enum Direction m_keyDir;	// direction of the arrow key pressed
	utilityVar();
	utilityVar(const utilityVar &other) = delete;

public:
	static utilityVar* getInstance() {
		if (!m_ptr) {
			m_ptr = new utilityVar();
		}
		return m_ptr;
	}

	void setPauseStatus(bool ispaused = false) {
		m_isPaused = ispaused;
		return;
	}

	bool getPauseStatus() const {
		return m_isPaused;
	}

	void setCurrState(enum gameState currState) {
		m_currState = currState;
		return;
	}

	enum gameState getCurrState() const {
		return m_currState;
	}

	void setExitCase(bool var) {
		m_canExit = var;
		return;
	}

	bool canExit() const {
		return m_canExit;
	}

	void setScoreIncrement(int incr) {
		m_scoreIncrement = incr;
		return;
	}

	int getScoreIncrement() const {
		return m_scoreIncrement;
	}

	bool getExitCase() const {
		return m_canExit;
	}

	void setCurrScore(int score) {
		m_currScore = score;
		return;
	}

	int getCurrScore() const {
		return m_currScore;
	}

	void setBestScore(int score) {
		m_bestScore = score;
		return;
	}

	int getBestScore() const {
		return m_bestScore;
	}

	void setKeyDir(enum Direction dir) {
		m_keyDir = dir;
		return;
	}

	enum Direction getKeyDir() const {
		return m_keyDir;
	}

	~utilityVar();
};

