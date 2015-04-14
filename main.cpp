#include "editor.h"

int main()
{
	Link link;
	char input = 'h';
	string file_name_1, file_name_2, str_1, str_2;
	int num;
    cout<< "=====================================================" <<endl
        << "            The editor has been activated            " <<endl
        << "=====================================================" <<endl;
	cout << "Enter file name: ";
	cin >> file_name_1;
	link.setStart();
	link.setEnd();
	link.read_from_infile(file_name_1);
	system("CLS");
	do{
		switch(input)
        {
		case '?':
		case 'h':
                
			cout << "================================================" <<endl;
			cout << "                    Commands                    " <<endl;
            cout << "a: Modify part of a line       c: Modify line   " << endl
			     << "d: Remove a line               f: Find line     " <<endl
			     << "g: Display line                  i: Insert line " <<endl
			     << "r: Read file                   k: Save file     " <<endl
                 << "o: Find part of a line         q: Exit          " <<endl
			     << "m: Create file                 v: Display all   " <<endl
			     << "w: Cover file content          x: Clean all     " <<endl
                 << "l: Display length                               " <<endl
                 <<"=================================================" <<endl;
			break;
		case'x':
			system("CLS");
			break;
		case'o':
			cout << "Enter string: ";
			cin >> str_1;
			link.findinallstring(str_1);
			break;
		case'a':
			cout << "Enter line number: ";
			cin >> num;
            cout << endl;
			cout << "Enter string: ";
			cin >> str_1;
            cout << endl;
			link.changeonelinecharacter(num,str_1);
			break;

		case'c':
			cout << "Enter line number: ";
			cin >> num;
            cout << endl;
			cout << "Enter string: ";
			cin >> str_1;
            cout << endl;
			link.changeline(num,str_1);
			break;
		case'd':
			cout << "Enter line number: ";
			cin >> num;
            cout << endl;
			link.deleteoneline(num);
			link.print();
			break;
		case'f':
			cout << "Enter string: ";
			cin >> str_1;
            cout << endl;
			link.findappointstring(str_1);
			break;
		case'g':
			cout << "Enter line number";
			cin >> num;
            cout << endl;
			link.setpos(num);
			link.displayoneline();
			break;
		case'i':
			cout << "Enter line number (preceeding): ";
			cin >> num;
            cout << endl;
			cout << "Enter string: ";
			cin >> str_1;
            cout << endl;
			link.insert(num,str_1);
			link.print();
			break;
		case'l':
			link.longlength();
			break;

		case'r':
			{
				link.clear();
				link.read_from_infile(filename1);
				link.print();
			}
			break;
		case'v':
			link.print();
			break;
		case'w':
			cout << "Enter file name: ";
	        cin >> filename2;
            cout << endl;
			link.save_to_file(filename2);
			break;
		case'k':
			link.save_to_file(filename1);
			break;
		case'm':
			char new_file[30];
			cout << "Enter file name: ";
			cin >> new_file;
            cout << endl;
	        break;
		default:
			cout << "Invalid command" << endl;
		}
		cout <<"Command:";
		cin >> input;
        
	}while (input! = 'q');

	return 0;
}
