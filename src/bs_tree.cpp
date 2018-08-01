#include"tree_base.hpp"
#include<initializer_list>

enum state_mach{
	VEC_CREATED = 1,	// vector is created but bs_init is not called or root is not created as of now.
	VEC_VALID = 2,
	TREE_VALID = 3, // here the root has been created and tree is ready for more insertions
	TREE_DESTROYED = 4, // this state means that tree is no more valid
};

// Need to delete the following structure after minor modifications to new one
/*template<typename T>
struct tree_node{
	tree_node *LEFT;
	T value;
	tree_node *RIGHT;
	static tree_node<T>* getInstance(){
		tree_node<T> *ptr = new tree_node<T>();
		return ptr;
	}
	tree_node(tree_node<T> *lptr = NULL, tree_node<T> *rptr = NULL) : LEFT(lptr), RIGHT(rptr){
	}
	struct tree_node<T>& operator=(const struct tree_node<T> &other){
		this->value = other.value;
		return *this;
	}
	bool operator>(const struct tree_node<T> &other){
		return this->value > other.value;
	}
	bool operator<(const struct tree_node<T> &other){
		return this->value < other.value;
	}
};*/

template<typename T>
class bs_tree : public tree_base{
	public:
	static bs_tree* getInstance(){
		bs_tree *tptr = new bs_tree<T>; 
		return tptr;	
	}
	// This function might not be used now as vector itself contains a constructor containing initializer_list parameter
	static std::vector<T>* cnv_to_vec(std::initializer_list<T> &il){
		std::vector<T> *hptr = new vector<T>(il.size());
		for(auto i : il){
			hptr->push_back(i);
		}
		return hptr;
	}	

	// superfluous method, won't be used, but kept for just in case needed 
	explicit bs_tree(int size = 0){
		m_vptr = new vector<T>(size);
		bs_init();
	}

	// Constructor accepts a universal reference
	bs_tree(const T &&value){
		node<T>* nd_ptr = convert_to_node(value);
		create_root(*nd_ptr);
		//m_vptr = new vector<T>(std::move(vec));	// will call the move constructor of vector
	}	
	
	// Copy constructor is not allowed as copying a complete tree would be very expensive
	bs_tree(const bs_tree<T> &other) = delete;

	/*
	 *  Move semantics is allowed. The following parameter is an r-value reference not a universal reference because it does not do a type
	 *  
	 *  deduction for the type of reference, the type of reference is fixed as type deducted class variable.
	 *
	 * */
	bs_tree(bs_tree<T> &&other){
		if(*this == other)
			return;
		bs_tree<T> *ptr = new bs_tree<T>(other.m_vptr);
		ptr = &other;
		// need to make the other pointer as null otherwise might lead to two pointers pointing to same object.	
	}

	node<T>* convert_to_node(const T &&value){
		node<T>*nd_ptr = node<T>::getInstance(value, NULL, NULL);
		return nd_ptr;
	}
	
	/*
	 *	The following function will create root from the first element of the vector
	 *
	 */
	bool create_root(const node<T> &nd_ref){
		bool retVal = true;
		if(getCurState() == INVALID){
			m_proot = &nd_ref;
		}
		else{
			retVal = false;
		}
		return retVal;
	}

	bs_tree(std::vector<T> *vptr) = delete;

	~bs_tree(){
		
	}
};
