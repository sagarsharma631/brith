/*
 *	DATE(DD/MM/YYYY) - 28/07/2018
 *
 */


#ifndef TREE_BASE_H
#define TREE_BASE_H

#include<iostream>
#include<vector>

enum STATE{
	ROOT_CREATED = 0x00,
	DELETED = 0x01,
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
	public:
	tree_base(){
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

	void flushTempVec() const{
		m_vTempVec.clear();
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
	 *	The set of following four traversal methods is again virtual because of the same reason mentioned above. A derived tree might
	 *
	 *	have a different type of node. For other trees the fowllowing methods will suffice.
	 *
	 */
	virtual void trav_in(node<T> *nd_ptr){
		flushTempVec();
		if(nd_ptr == NULL)
			return;
		trav_in(nd_ptr->m_left);
		m_vTempVec.push_back(nd_ptr->m_Value);
		trav_in(nd_ptr->m_right);
	}

	virtual void trav_pre(node<T> *nd_ptr){
		flushTempVec();
		if(nd_ptr == NULL)
			return;
		m_vTempVec.push_back(nd_ptr->m_Value);
		trav_pre(nd_ptr->m_left);
		trav_pre(nd_ptr->m_right);
	}

	virtual void trav_post(node<T> *nd_ptr){
		flushTempVec();
		if(nd_ptr == NULL)
			return;
		trav_post(node->m_left);
		trav_post(node->m_right);
		m_vTempVec.push_back(nd_ptr->m_Value);
	}

	virtual void trav_level(node<T> *nd_ptr){
	}

	// Virtual destructor
	virtual ~tree_base(){
		
	}
};

#endif
