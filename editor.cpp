#include "editor.h"
#include <fstream>
using namespace std;

/************************************************************************/
/* set start of the link                                                */
/************************************************************************/
bool Link::setStart()
{
	fence=head;
	rightcnt+=leftcnt;
	leftcnt=0;
	return true;
}

/************************************************************************/
/* set end of the link                                                  */
/************************************************************************/
bool Link::setEnd()
{
	tail = fence;
	leftcnt+=rightcnt;
	rightcnt=0;
	return true;
}

/************************************************************************/
/* init the link                                                        */
/************************************************************************/
void Link::init()
{
	fence=tail=head=new node;
	leftcnt=rightcnt=0;
}

/************************************************************************/
/* display the data to the screen.                                       */
/************************************************************************/
void Link::read_from_infile(string filename)
{
	string elem[100];
	int count = 0;
	ifstream infile(filename.c_str(),ios::in);
	if (!infile) 
	{
		cout<<"open error!"<<endl;
		exit(1);
	}
	char ch;
	while ((ch=infile.get()) != EOF) {
		if(ch != '\n')
		{
			elem[count] = elem[count] + ch;
		}
		else
		{
			append(elem[count]);
			count++;
		}
	}
	append(elem[count]);
	cout<<endl;
	infile.close();
}

/************************************************************************/
/* input the data to the file.                                          */
/************************************************************************/
void Link::save_to_file(string filename)
{
	node* temp;
	temp=head->next;
	ofstream outfile(filename.c_str(), ios::out);
	while (temp!=NULL) {
		outfile<<temp->element<<endl;
		temp=temp->next;
	}
	outfile.close();
}


/************************************************************************/
/* the insert member function is according the num to                   */
/*find the fence the insert to the next of the fence                    */
/************************************************************************/
bool Link::insert(int num,const string& item)
{
	setpos(num);
	node* temp=new node;
	temp->element=item;
	if (fence->next!=NULL) 
	{
		temp->next=fence->next;
		fence->next->pre=temp;
		fence->next=temp;
		temp->pre=fence;
	}
	else 
	{
		fence->next=temp;
		temp->pre=fence;
		tail=fence->next;
	}
	rightcnt++;
	return true;
}



/************************************************************************/
/*    append string to end of the list                                  */                                                     
/*     the list is doubly linked list                                   */
/************************************************************************/
bool Link::append(const string&item)  
{
	node* p;
	p=tail;
	tail=tail->next=new node;
	tail->element = item;
	tail->pre = p;
	rightcnt++; //Added to right
	return true;
}


/************************************************************************/
/* remove and return first string in right partition                    */
/************************************************************************/
bool Link::remove(string& it)
{
	if (fence->next==NULL) {   //empty right
		return false;
	}
	it=fence->next->element;    //remember value
	node* itemp=fence->next;     //remem link node
	if (itemp->next!=NULL) {
		itemp->next->pre=fence;
	}
	else
		tail=fence;         //reset tail
	fence->next=itemp->next;    //remove from the list
	delete itemp;                  //reclaim space
	rightcnt--;                  //remove from right
	return true;
}



/************************************************************************/
/* move fence one stepleft ,no change if left is empty                  */
/************************************************************************/
void Link::prev()
{
	if (fence!=head) {     //cannot back up from list head
		fence=fence->pre;
		leftcnt--;
		rightcnt++;
	}
}

/************************************************************************/
/* according you enter the number to find the fence                     */
/************************************************************************/
bool Link::setpos(int pos)
{
	fence=head;
	if (pos<0) {
		fence = head;
	}
	else if (pos>rightcnt+leftcnt) {
		for(int j=0; j<rightcnt+leftcnt; j++)
			fence = fence->next;
	}
	else{
		for (int i=0;i<pos;i++) {
			fence=fence->next;
		}
	}
	return true;
}

/************************************************************************/
/* print the all the node in the list                                   */
/************************************************************************/
void Link::print() const
{
	node* temp;
	int num=0;
	temp=head;
	while (temp!=tail->next) {
		if (num>0) {
			cout<<num<<" . ";
		}
		cout<< temp->element <<"  "<<endl;
		temp=temp->next;
		num++;
	}
	cout<<endl;
}

/************************************************************************/
/* to calculate the file include the number of the row                  */
/* to  calculate the number of the character                            */
/************************************************************************/
int Link::longlength()
{
	string actfor;
	node* temp;
	int length=-1,num=0;
	temp=head;
	while (temp!=NULL) {
		actfor=temp->element;
		num=num+actfor.length();
		length++;
		temp=temp->next;
	}
	cout<<"the file length is"<<length<<endl;

	cout<<"the number of the character is:"<<num<<endl;
	return length;
	
}
/************************************************************************/
/*               display one line                                       */
/************************************************************************/
bool Link::displayoneline()
{
	if (fence!=NULL && fence!=head) {
		cout<<fence->element<<endl;
	}
	else{
		cout<<"the present line is empty."<<endl;
	}
	return true;
}

/************************************************************************/
/* according your enter string to find the line number                  */
/* print the find number                                                */
/************************************************************************/
bool Link::findappointstring(string str)
{
	node* temp;
	int num=0;
	bool bo=true;
	temp=head->next;
	while (temp!=NULL) {
		num++;
		if (temp->element==str) {
			cout<<"Found"<<endl;
			cout<<"This is at line No."<<num<<"."<<endl;
			cout<<"the appointed is :"<<temp->element<<endl;
			bo=false;
		}
		temp=temp->next;
	}
	if (bo) {
		cout<<"Not exist"<<endl;
	}
	return true;
}



/************************************************************************/
/* delete one line according you enter the line number                  */
/************************************************************************/
bool Link::deleteoneline(int num)
{
	num=num-1;
	setpos(num);
	node* q;
//	if (fence->next==NULL) {
//		fence->next=NULL;
//		delete fence->next;
//	}
	if (fence==tail) {
		q=tail;
		tail=fence->pre;
		delete q;
	}
	else{
		node* p;
		p = fence->next;
		fence->next=fence->next->next;
		fence->next->pre=fence;
		delete p;
	}
	return true;

}
/************************************************************************/
/* according you enter line number to find the line                     */
/*replace the find line to you enter string                             */
/************************************************************************/
bool Link::changeline(int num,string& str)
{
	setpos(num);
	fence->element=str;
	return true;	
}




/************************************************************************/
/* change appointed line's character                                    */
/************************************************************************/
bool Link::changeonelinecharacter(int num,string& str)
{
	char m[256];
	char n[256];
	char z[256];
	int len=0;
	string str2;

	node* temp;
	setpos(num);
	temp=fence;	
	strcpy(m,str.c_str());	
	strcpy(n,temp->element.c_str());
	num=temp->element.find(m,0);

	if (temp->element.find(m,0) != string::npos) {
		cout<<"Re-enter the string(same length)";
		cin>>str2;
		while (str.length() != str2.length()) {
			cout<<"Wrong！Different length"<<endl;
			cout<<"Please re-enter:"<<endl;
			cout<<"Re-enter the string(same length):";
			cin>>str2;
		}
		len=str2.length();
		strcpy(z,str2.c_str());
		for (int j=0;j<len;j++) {
			n[num]=z[j];
			temp->element=n;
			num++;
		}
		cout<<"Succesfully saved！"<<endl;
	}
	else
		cout<<"No result."<<endl;
	return true;
}

/************************************************************************/
/* find the postation in the file and print it out                        */
/************************************************************************/
bool Link::findinallstring(string& str)
{
	char m[256];
	char n[256];
	int num=0;
	node* temp;
	temp=head;
	strcpy(m,str.c_str());
	while (temp->next!=NULL) 
	{
		temp=temp->next;
		num++;
		if (temp->element.find(m,0) != string::npos) {
			cout<<"No. "<<num<<" line"<<endl;
		}
		else
			cout<<"It's not in No. "<<num<<" line"<<endl;
	}
	return true;
}
void creatfile()
{
	char newfile[30];
	cout<<"Name for new file:"<<endl;
	cin>>newfile;
	fopen(newfile,"w+");
}
