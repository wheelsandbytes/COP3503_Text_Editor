#include "editor.h"
#include "string.h"
#include <cstdlib>

void mainmenu(){

	system("clear");
			cout << "================================================" <<endl;
			cout << "                    Commands                    " <<endl;
            cout << "A: Modify part of a line       I: Modify line   " <<endl
			     << "B: Remove a line               J: Find line     " <<endl
			     << "C: Display line                K: Insert line   " <<endl
			     << "D: Read file                   L: Save file     " <<endl
                 << "E: Find part of a line         M: Display all   " <<endl
			     << "F: Create file                 N: Delete all    " <<endl
			     << "G: Cover file content                           " <<endl
                 << "H: Display length              X: Exit          " <<endl
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
        case'A':
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
		case'B':
			cout << "Enter line number: ";
			cin >> num;
            cout << endl;
			link.deleteoneline(num);
			link.print();
			mainmenu();
			link.print();
			break;
		
		//Dislay Line
		case'C':
			cout << "Enter line number";
			cin >> num;
            cout << endl;
			link.setpos(num);
			link.displayoneline();
			mainmenu();
			link.print();
			break;

		//Read File
		case'D':
			{
				link.clear();
				link.read_from_infile(file_name_1);
				link.print();
			}
			mainmenu();
			link.print();
			break;

		//Find Part of a line
		case'E':
			cout << "Enter string: ";
			cin >> str_1;
			link.findinallstring(str_1);
			mainmenu();
			link.print();
			break;

		//Create file
		case'F':
			char new_file[30];
			cout << "Enter file name: ";
			cin >> new_file;
            cout << endl;
            mainmenu();
            link.print();
	        break;

	    //Cover File Content
	    case'G':
			cout << "Enter file name: ";
	        cin >> file_name_2;
            cout << endl;
			link.save_to_file(file_name_2);
			mainmenu();
			link.print();
			break;

		//Display Length
		case'H':
			link.longlength();
			mainmenu();
			link.print();
			break;

		//modify line
		case'I':
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
		case'J':
			cout << "Enter string: ";
			cin >> str_1;
            cout << endl;
			link.findappointstring(str_1);
			mainmenu();
			link.print();
			break;

		//insert line
		case'K':
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
		case'L':
			link.save_to_file(file_name_1);
			mainmenu();
			link.print();
			break;
		
		//display all
		case'M':
			link.print();
			mainmenu();
			link.print();
			break;

		//delete all
		case'N':
			system("CLS");
			mainmenu();
			link.print();
			break;

		case 'h':

			system("clear");
			mainmenu()
            link.print();
			break;
	
		default:
			cout << "Invalid command" << endl;
		}
		cout <<"Command:";
		cin >> input;

	}while (input != 'X');

	return 0;
}
