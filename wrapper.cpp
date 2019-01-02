#include"wrapper.hpp"
#include"command.hpp"

wrapper* wrapper::m_ptr = NULL;

wrapper* wrapper::getInstance(){
	if(!m_ptr){
		return m_ptr;
	}
	else{
		m_ptr = new wrapper();
		return m_ptr;
	}
}

bool wrapper::generateCommandDispatch(const ds_all &ds) const{
	switch(ds){
		case TREE_BS : 
			cmd_create<treeIF> *cmd  = new cmd_create<treeIF>(TREE_BS);
			break;
		case TREE_HEAP :
			cmd_create<treeIF> *cmd  = new cmd_create<treeIF>(TREE_HEAP);
			break;
		case TREE_MIN_HEAP : 
			cmd_create<treeIF> *cmd  = new cmd_create<treeIF>(TREE_MIN_HEAP);
			break;
		case TREE_MAX_HEAP : 
			cmd_create<treeIF> *cmd  = new cmd_create<treeIF>(TREE_MAX_HEAP);
			break;
		case TREE_AVL : 
			cmd_create<treeIF> *cmd  = new cmd_create<treeIF>(TREE_AVL);
			break;
		case TREE_RED_BLACK : 
			cmd_create<treeIF> *cmd  = new cmd_create<treeIF>(TREE_RED_BLACK);
			break;
		default:
	};
}

cmd_create* wrapper::create(const ds_all &what, bool &success){
	success false;
	if(what <=ENUM_BASE || what >= DS_TOTNUM){
		throw "INVALID INDEX";
	}
	else{
		success = true;
		generateCommandDispatch(what);
	}
}

