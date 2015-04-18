#include "editor.h"
#include "string.h"
#include <cstdlib>

void mainmenu(){

	system("clear");
			cout << "================================================" <<endl;
			cout << "                    Commands                    " <<endl;
            cout << "a: Modify part of a line       i: Modify line   " <<endl
			     << "b: Remove a line               j: Find line     " <<endl
			     << "c: Display line                k: Insert line   " <<endl
			     << "d: Read file                   l: Save file     " <<endl
                 << "e: Find part of a line         m: Display all   " <<endl
			     << "f: Create file                 n: Delete all    " <<endl
			     << "g: Cover file content                           " <<endl
                 << "h: Display length              x: Exit          " <<endl
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
        //Modify Part of a Line
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

		//Remove a line
		case'b':
			cout << "Enter line number: ";
			cin >> num;
            cout << endl;
			link.deleteoneline(num);
			link.print();
			mainmenu();
			link.print();
			break;
		
		//Dislay Line
		case'c':
			cout << "Enter line number";
			cin >> num;
            cout << endl;
			link.setpos(num);
			link.displayoneline();
			mainmenu();
			link.print();
			break;

		//Read File
		case'd':
			{
				link.clear();
				link.read_from_infile(file_name_1);
				link.print();
			}
			mainmenu();
			link.print();
			break;

		//Find Part of a line
		case'e':
			cout << "Enter string: ";
			cin >> str_1;
			link.findinallstring(str_1);
			mainmenu();
			link.print();
			break;

		//Create file
		case'f':
			char new_file[30];
			cout << "Enter file name: ";
			cin >> new_file;
            cout << endl;
            mainmenu();
            link.print();
	        break;

	    //Cover File Content
	    case'g':
			cout << "Enter file name: ";
	        cin >> file_name_2;
            cout << endl;
			link.save_to_file(file_name_2);
			mainmenu();
			link.print();
			break;

		//Display Length
		case'h':
			link.longlength();
			mainmenu();
			link.print();
			break;

		//modify line
		case'i':
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

		//find line
		case'j':
			cout << "Enter string: ";
			cin >> str_1;
            cout << endl;
			link.findappointstring(str_1);
			mainmenu();
			link.print();
			break;

		//insert line
		case'k':
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

		//save file
		case'l':
			link.save_to_file(file_name_1);
			mainmenu();
			link.print();
			break;
		
		//display all
		case'm':
			link.print();
			mainmenu();
			link.print();
			break;

		//delete all
		case'n':
			system("CLS");
			mainmenu();
			link.print();
			break;

		case 'h':

			system("clear");
			mainmenu();
            link.print();
			break;
	
		default:
			cout << "Invalid command" << endl;
		}
		cout <<"Command:";
		cin >> input;

	}while (input != 'x');

	return 0;
}
