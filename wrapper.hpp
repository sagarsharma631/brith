/* 
<!-----------------------------------------------------------------------------------------------

This file contains


-------------------------------------------------------------------------------------------------!>

*/

#include<iostream>
#include<queue>
#define ENUM_BASE 0

enum ds_all{
	DS_START = ENUM_BASE,
	TREE_BS,
	TREE_HEAP,
	TREE_MIN_HEAP,
	TREE_MAX_HEAP,
	TREE_AVL,
	TREE_RED_BLACK,
	TREE_TOTNUM,
	DS_TOTNUM,		// number of references in enum
};

enum cmd_all{
	CMD_START = ENUM_BASE;
	CMD_CREATE,
	CMD_INSERT,
	CMD_DELETE,
	CMD_SEARCH,
	CMD_TRAVERSE_INORDER,
	CMD_TRAVERSE_PREORDER,
	CMD_TRAVERSE_POSTORDER,
	CMD_SORT,
	CMD_TOTNUM,
};

class wrapper{
	private:
	static wrapper *m_ptr; 
	wrapper(){
	}
	// generateCommandDispatch(command type, ds type used to generate command) const;
	bool generateCommandDispatch(const cmd_all &cmd, const ds_all &ds) const; 
	public:
	static wrapper* getInstance();
	auto create(const ds_all &what, bool &success);
	
	~wrapper(){
		delete m_ptr;
	}
};