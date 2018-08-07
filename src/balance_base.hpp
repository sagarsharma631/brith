#ifndef BALANCE_BASE_H
#define BALANCE_BASE_H

enum ROTATION{
	SINGLE_LEFT_ROTATE = 0,
	SINGLE_RIGHT_ROTATE = 1,
	LEFT_RIGHT_ROTATE = 2,
	RIGHT_LEFT_ROTATE = 3,
};

/* The following node is balance tree specific. There is no need to make the member variables private as they would be used only internally.
 *
 * These variable would not be used by command manager. Making these variable private will need an extra overhead of creating get/set 
 *
 * methods for all the private variables.
 *
 */
template<typename T>
struct balance_node{
	balance_node<T> *m_pleft;
	T m_Value;
	balance_node<T> *m_pright;
	uint8_t m_iBalFac;	// Balance factor of the node
	uint8_t m_RightHt;	// Right height of the node
	uint8_t m_LeftHt;	// Left height of the node
	balance_node(balance_node<T> *left = NULL, balance_node<T> *right = NULL, T value, uint8_t factor = 0, uint8_t rtht = 0, uint8_t ltht = 0) : m_pleft(left),
		m_pright(right),
		m_Value(value),
		m_iBalFac(factor),
		m_RightHt(rtht),
		m_LeftHt(ltht){
	}
};

template<typename T>
class balance_base : public tree_base{
	private:
	public:
	
	// This method decides which rotation to do
	ROTATION which_rotation(){
	}

	uint8_t calc_balance_factor(node<T> *nd_ptr){
			
	}

	/*
	 *	This method returns the root node of the rotated sub tree. This root than gets attached to the node which called this method
	 *
	 *	due to increase in balance factor. 
	 *
	 */
	balance_node<T>* do_single_left(node<T> *nd_ptr){
		balance_node<T> *root;
		root = nd_ptr->m_pright;
		nd_ptr->m_pright = root->m_pleft;
		root->m_pleft = nd_ptr;
		return root;
	}

	balance_node<T>* do_single_right(node<T> *nd_ptr){
		balance_node<T> *root;
		root = nd_ptr->m_pleft;
		nd_ptr->m_pleft = root->m_pright;
		root->m_pright = nd_ptr;
		return root;
	}

	void do_left_right(node<T> *sub_root){
	}

	void do_right_left(node<T> *sub_root){
	}
	
};

#endif
