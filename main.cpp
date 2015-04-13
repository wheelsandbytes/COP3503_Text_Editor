#include "editor.h"

int main()
{
	Link item1;
	char sign='h';
	string filename1,filename2,str,str2;
	int num;
		cout<<"           *****************************************************"<<endl
		    <<"                                   欢迎使用文本编辑器            "<<endl
		    <<"           *****************************************************"<<endl;
	cout<<"请输入文件名<eg. file_in.txt>:";
	cin>>filename1;
	item1.setStart();
	item1.setEnd();
	item1.read_from_infile(filename1);
	system("CLS");
	do{
		switch(sign) {
		case '?':
		case 'h':
			cout <<"*****************************************************************"<<endl;
			cout <<"                         操作步骤                                  "<<endl;
                        cout << "         a:只替换某行的某个子字符串    c:改变一行的内容           " << endl
			     << "         d:删除指定的一行              f:根据输入的字符串查找行   " <<endl
			     << "         g:显示指定的一行              i:插入一行                 " <<endl
			     << "         r:读取文件                    k:保存文件                 "<<endl
                             << "         o:查找子串                    q:退出程序                 "<<endl
			     << "         m:新建文件                    v:查看所有                 "<<endl
			     << "         w:当前内容写入另外一个文件    x:清屏                     "<<endl
                             << "         l:总行数                                                "<<endl
		     	     <<"*****************************************************************"<<endl;
			break;
		case'x':
			system("CLS");
			break;
		case'o':
			cout<<"输入你想查找的子串:";
			cin>>str;
			item1.findinallstring(str);
			break;
		case'a':
			cout<<"请问你想修改第几行？： ";
			cin>>num;
			cout<<"请输入你要修改的子串";
			cin>>str;
			item1.changeonelinecharacter(num,str);
			break;

		case'c':
			cout<<"请问你想修改第几行？：";
			cin>>num;
			cout<<"请输入新字符串内容：";
			cin>>str;
			item1.changeline(num,str);
			break;
		case'd':
			cout<<"请问你想删掉第几行？:";
			cin>>num;
			item1.deleteoneline(num);
			item1.print();
			break;
		case'f':
			cout<<"请输入你想查找的字符串："<<endl;
			cin>>str;
			item1.findappointstring(str);
			break;
		case'g':
			cout<<"请输入行序号："<<endl;
			cin>>num;
			item1.setpos(num);
			item1.displayoneline();
			break;
		case'i':
			cout<<"请问你想插在第几行后面：";
			cin>>num;
			cout<<"请输入你要插入的字符串：";
			cin>>str;
			item1.insert(num,str);
			item1.print();
			break;
		case'l':
			item1.longlength();
			break;

		case'r':
			{
				item1.clear();
				item1.read_from_infile(filename1);
				item1.print();
			}
			break;
		case'v':
			item1.print();
			break;
		case'w':
			cout<<"请输入文件名<eg. file_in.txt>:";
	        cin>>filename2;
			item1.save_to_file(filename2);
			break;
		case'k':
			item1.save_to_file(filename1);
			break;
		case'm':
			char newfile[30];
			cout<<"请输入新建文件名:"<<endl;
			cin>>newfile;
	        break;
		default:
			cout<<"\n*** 不合法输入 ***\n"<<endl;
		}
		cout<<"please input command:";
		cin>>sign;
	}while (sign!='q');

	return 0;
	
}
