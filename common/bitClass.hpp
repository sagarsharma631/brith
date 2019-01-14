
class bitClass{
	private:
	// Member variables
	static bitClass *m_ptr;
	int m_mask;
	int m_digits;
	int m_bitsReq;
	bool *m_Array;	// base address of the array containing the set/unset bits
	// Methods
	bitClass(){
	}
	bitClass(const bitClass *ref) = delete;
	bitClass& operator=(const )
	bool maskDataInit();
	void calcDigits();
	void calcReqBits();
	bool isBitSet(const int &index);
	protected:
	public:
	static bitClass* getInstance(){
		if(m_ptr == NULL){
			m_ptr = new bitClass();
		}
		return m_ptr;
	}
	
	bool setMask(const int &mask);	// sets the mask
};
