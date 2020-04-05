/*

AUTHOR - SAGAR SHARMA

DATE(DD/MM/YYYY) - 10/02/2020

This class is abstracts the normal 2D array, this will be use full when passing 2D arrays to a function.

*/
template<typename T>
	class matrix {
	private:
		const int m_iRows;	// Once set cannot be changed
		const int m_iCols;	// Once set cannot be changed
		T** m_pMatrix;
		T* getBasePointer(int index) const{
			if (!isInRange(index)) {
				return NULL;
			}
			return m_pMatrix[index];
		}
	protected:
	public:
		matrix(int rows = 3, int cols = 3):m_iRows(rows),
			m_iCols(cols){
			m_pMatrix = new T* [m_iRows];
			for (int i = 0; i < m_iRows; ++i) {
				m_pMatrix[i] = new T[cols] {0};
			}
		}

		int getRows() const{
			return m_iRows;
		}

		int getCols() const {
			return m_iCols;
		}

		T* operator[](int index){
			return getBasePointer(index);
		}

		T* operator[](int index) const {
			return getBasePointer(index);
		}

		bool isInRange(const int &rows) const{
			return (rows >= 0 && rows < m_iRows);
		}

		~matrix() {
			// delete each array allocated.
			for (int index = 0; index < m_iRows; ++index) {
				delete[] m_pMatrix[index];
			}
		}
	};
