  #ifndef _EDITOR_H_
#define _EDITOR_H_

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "node.h"




//Double-linked list link node with freelist support
class Link : public node{
private:
	node* head;
	node* tail;
	node* fence;
	int leftcnt;
	int rightcnt;

public:

	Link()
	{
		init();
	}
	~Link() {
		removeall(); //destructor
	}
	
	void clear(){
		removeall();
		init();
	}
	
	bool insert(int num,const string& item);
	bool deleteoneline(int num);
	bool append(const string& item);
	bool remove(string& it);
	bool changeline(int num,string& str);
	bool changeonelinecharacter(int num,string& str);
	bool findinallstring(string& str);
	bool setStart();
	bool setEnd();
	void prev();
	void next1()
	{
		if (fence!=tail) {    //don't move fence if right empty
			fence=fence->next;
			rightcnt--;
			leftcnt++;
		}
	}
	int leftlength() const{return leftcnt;}
	int rightlength() const{return rightcnt;}
	int longlength() ;
	bool displayoneline();
	bool findappointstring(string str);
	bool setpos(int pos);
	bool getValue(string& it) const {
		if(rightlength()==0)
			return false;
		it=fence->next->element;
		return true;
	}
	void print() const;
	void init() ;
	void removeall() {
		while(head != NULL)
		{
			fence = head;
			head = head->next;
			delete fence;
		}
	}
	//input the data to the inputfile.
    void save_to_file(string filename);
	//read the data from the file
	void read_from_infile(string filename);
};

#endif
