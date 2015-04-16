#include "editor.h"
#include "string.h"
#include <cstdlib>

void mainmenu(){

	system("clear");
			cout << "================================================" <<endl;
			cout << "                    Commands                    " <<endl;
            cout << "a: Modify part of a line       c: Modify line   " <<endl
			     << "d: Remove a line               f: Find line     " <<endl
			     << "g: Display line                i: Insert line   " <<endl
			     << "r: Read file                   k: Save file     " <<endl
                 << "o: Find part of a line         q: Exit          " <<endl
			     << "m: Create file                 v: Display all   " <<endl
			     << "w: Cover file content          x: Clean all     " <<endl
                 << "l: Display length                               " <<endl
                 <<"=================================================" <<endl<<endl;
            cout <<"-------------------------------------------------" <<endl
            	 <<"               Current State of File             " <<endl
            	 <<"                                                 " <<endl;

            
}


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

			system("clear");
			cout << "================================================" <<endl;
			cout << "                    Commands                    " <<endl;
            cout << "a: Modify part of a line       c: Modify line   " <<endl
			     << "d: Remove a line               f: Find line     " <<endl
			     << "g: Display line                i: Insert line   " <<endl
			     << "r: Read file                   k: Save file     " <<endl
                 << "o: Find part of a line         q: Exit          " <<endl
			     << "m: Create file                 v: Display all   " <<endl
			     << "w: Cover file content          x: Clean all     " <<endl
                 << "l: Display length                               " <<endl
                 <<"=================================================" <<endl;
            cout <<"-------------------------------------------------" <<endl
            	 <<"               Current State of File             " <<endl
            	 <<"                                                 " <<endl;

            link.print();
			break;
		case'x':
			system("CLS");
			mainmenu();
			link.print();
			break;
		case'o':
			cout << "Enter string: ";
			cin >> str_1;
			link.findinallstring(str_1);
			mainmenu();
			link.print();
			break;
		case'a':
			cout << "Enter line number: ";
			cin >> num;
            cout << endl;
			cout << "Enter string: ";
			cin >> str_1;
            cout << endl;
			link.changeonelinecharacter(num,str_1);
			mainmenu();
			link.print();
			break;

		case'c':
			cout << "Enter line number: ";
			cin >> num;
            cout << endl;
			cout << "Enter string: ";
			cin >> str_1;
            cout << endl;
			link.changeline(num,str_1);
			mainmenu();
			link.print();
			break;
		case'd':
			cout << "Enter line number: ";
			cin >> num;
            cout << endl;
			link.deleteoneline(num);
			link.print();
			mainmenu();
			link.print();
			break;
		case'f':
			cout << "Enter string: ";
			cin >> str_1;
            cout << endl;
			link.findappointstring(str_1);
			mainmenu();
			link.print();
			break;
		case'g':
			cout << "Enter line number";
			cin >> num;
            cout << endl;
			link.setpos(num);
			link.displayoneline();
			mainmenu();
			link.print();
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
			mainmenu();
			link.print();
			break;
		case'l':
			link.longlength();
			mainmenu();
			link.print();
			break;

		case'r':
			{
				link.clear();
				link.read_from_infile(file_name_1);
				link.print();
			}
			mainmenu();
			link.print();
			break;
		case'v':
			link.print();
			mainmenu();
			link.print();
			break;
		case'w':
			cout << "Enter file name: ";
	        cin >> file_name_2;
            cout << endl;
			link.save_to_file(file_name_2);
			mainmenu();
			link.print();
			break;
		case'k':
			link.save_to_file(file_name_1);
			mainmenu();
			link.print();
			break;
		case'm':
			char new_file[30];
			cout << "Enter file name: ";
			cin >> new_file;
            cout << endl;
            mainmenu();
            link.print();
	        break;
		default:
			cout << "Invalid command" << endl;
		}
		cout <<"Command:";
		cin >> input;

	}while (input != 'q');

	return 0;
}
