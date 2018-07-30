/*
 *	AUTHOR : SAGAR SHARMA
 *	DATE CREATED(DD/MM/YYYY) : 30/07/2018
 *
 */

#ifndef TREE_BASE_H
#define TREE_BASE_H

#include<iostream>
#include<vector>

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

	// Following variables are used for storing temporary stuff so always make sure to flush them before using them.
	
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

	void getTempVec(vector<T> &other) const;

	// Pure virtual functions

	virtual void create_root(T value) = 0;
	virtual void where_to_insert(T value) = 0;

	// Virtual functions

	virtual void delete_tree(node<T> *nd_ptr);
	void traverse_tree(const node<T> *nd_ptr, TRAVERSE_TYPE trav);
	virtual void trav_in(const node<T> *nd_ptr);
	virtual void trav_pre(const node<T> *nd_ptr);
	virtual void trav_post(const node<T> *nd_ptr);
	virtual void trav_level(const node<T> *nd_ptr);
	
	// Virtual destructor
	virtual ~tree_base(){
		
	}

	

};

#endif
