#ifndef _NODE_H_
#define _NODE_H_

class node
{
public:
	string element;
	node* pre;
	node* next;

public:
	node(){
		element = "";
		pre = NULL;
		next = NULL;
	}
	~node(){}
};



#endif
