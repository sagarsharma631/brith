/*
 *	DATE(DD/MM/YYYY) - 28/07/2018
 *
 */

#include"tree_base.hpp"

enum STATE{
	INVALID = 0,	// Root node of the tree is not yet created
	ROOT_CREATED = 1,
	DELETED = 2,
};

enum TRAVERSE_TYPE{
	TRAV_PRE = 0,
	TRAV_IN = 1,
	TRAV_POST = 2,
	TRAV_LVL = 3,
};

template<typename T>
struct node{
	private:
	node *m_left;
	T m_Value;
	node *m_right;
	// private constructor 
	node(T value, node *lft,node *rght):
		m_left(lft),
		m_Value(value),
		m_right(rght){
	}
	public:
	static node* getInstance(T value, node *lft = NULL, node *rght = NULL){
		node *tmpIns = new node(value,lft,rght);
		return tmpIns;
	}
	~node(){
		// please create a new logging system to log
		delete m_left;
		delete m_right;
	}
};

template<typename T>
class tree_base{
	private:
	STATE m_CurState;
	node<T> *m_proot;

	// Following variables are used for storing temporary stuff so always make sure to flush them before using them
	
	std::vector<T> m_vTempVec;
	uint8_t m_iTempInt;
	
	public:
	tree_base():m_CurState(INVALID), m_proot(NULL){
	}
	inline STATE getCurState() const{
		return m_CurState;
	}
	inline setCurState(STATE state){
		m_CurState = state;
	}
	inline virtual bool canInsert(){
		return m_CurState == STATE::ROOT_CREATED;
	}
	inline node<T>* getRoot() const{
		return m_proot;
	}

	inline void flushTempVec(){
		m_vTempVec.clear();
		return;
	}

	inline void flushTempInt(){
		m_iTempInt = 0x00;
		return;
	}

	/*	
	 *	This method will populate the argument vector with the temporary vector. Method takes a non_const lValue reference hence 
	 *
	 *	anonymous abjects or any other rValue cannot be sent to this method.
	 *
	 */
	void getTempVec(vector<T> &other) const{
		// need to make boundary checks and complete this method
		return;
	}

	// Pure virtual functions
	
	virtual void create_root(T value) = 0;

	virtual void where_to_insert(T value) = 0;

	/*
	 *	delete_tree(node<T> *) is made virtual because any derived tree may make use of any other type of node which may have
	 *
	 * 	different members and hence may need deallocation of other members as well or there can be a difference in traversal technique 
	 * 	as well for deletion. But for all cases which make use of this type of node following will suffice.
	 *
	 */
	virtual void delete_tree(node<T> *nd_ptr){
		if(nd_ptr == NULL)
			return;
		delete_tree(node->m_left);
		delete_tree(node->m_right);
		delete nd_ptr;

	}



	/*
	 * 	This method is not virtual because it has same functionality for all type of trees irrespective of what kind of nodes they
	 * 	
	 * 	make use of. First argument is the addrress of the root node.
	 */

	void traverse_tree(const node<T> *nd_ptr, TRAVERSE_TYPE trav){
		flushTempVec();		// flush the temporary vector before populating it
		switch(trav){
			case TRAV_PRE:
				trav_pre(nd_ptr);
				break;
			case TRAV_IN:
				trav_in(nd_ptr);
				break;
			case TRAV_POST:
				trav_post(nd_ptr);
				break;
			case TRAV_LVL:
				flushTempInt();
				trav_level(nd_ptr);
				break;
		}
	}

	/*
	 *	The set of following four traversal methods is again virtual because of the same reason mentioned above. A derived tree might
	 *
	 *	have a different type of node. For other trees the fowllowing methods will suffice.
	 *
	 */
	virtual void trav_in(const node<T> *nd_ptr){
		if(nd_ptr == NULL)
			return;
		trav_in(nd_ptr->m_left);
		m_vTempVec.push_back(nd_ptr->m_Value);
		trav_in(nd_ptr->m_right);
	}

	virtual void trav_pre(const node<T> *nd_ptr){
		if(nd_ptr == NULL)
			return;
		m_vTempVec.push_back(nd_ptr->m_Value);
		trav_pre(nd_ptr->m_left);
		trav_pre(nd_ptr->m_right);
	}

	virtual void trav_post(const node<T> *nd_ptr){
		if(nd_ptr == NULL)
			return;
		trav_post(node->m_left);
		trav_post(node->m_right);
		m_vTempVec.push_back(nd_ptr->m_Value);
	}

	virtual void trav_level(const node<T> *nd_ptr){
		if(nd_ptr == NULL)
			return;
		++m_iTempInt;
		m_vTempVec.push_back(nd_ptr->m_Value);
		trav_level(nd_ptr->m_left);
		trav_level(nd_ptr->m_right);
		--m_iTempInt;
	}

	// Virtual destructor
	virtual ~tree_base(){
		
	}
};

#endif
