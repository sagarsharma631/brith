template<typename T>
class cmd_base{
};


template<typename T>
class cmd_create : public cmd_base{
	private:
	cmd_all m_cmdType;
	ds_all m_dsType; 
	T* m_ds;	
	public:
	cmd_create(const ds_all what) : m_type(what){
	}
	cmd_create(const cmd_create &ref) = delete;
	cmd_create& operator=(const cmd_create &ref) = delete;
	~cmd_create(){
	}
};

template<typename T>
class cmd_traverse : public cmd_base{
	private:
	public:
	cmd_traverse(){
	}
	cmd_create(const cmd_create &ref) = delete;
	cmd_create& operator=(const cmd_create &ref) = delete;
	~cmd_travers(){
	}
};