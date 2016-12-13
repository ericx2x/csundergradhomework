
#include <iostream>
#include "UniversityPerson.h"
#include "Student.h"
#include "Employee.h"
#include "Academic.h"
#include "Administration.h"
#include "Faculty.h"
#include "Teaching.h"
#include "Support.h"
#include "UniversityDatabase.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main ()
{

	UniversityDatabase MainDB;
	UniversityPerson *newperson;

	int query = 0;

	cout << "Welcome to the University Database."
		 << endl;

	while (query != 4) {

		newperson = NULL;

			cout << endl
			<< "Please choose one of the following:"
			<< endl
			<< "(1) Lookup a person."
			<< endl
			<< "(2) Enter a person."
			<< endl
			<< "(3) Print the whole database."
			<< endl
			<< "(4) To quit."
			<< endl;

		cin >> query;

		if (query == 1) {

			int choice = 0;
			cout << "(1) Name or (2) ID" << endl;
			cin >> choice;

			if (choice == 1) {

				string name;

				cout << "Name: (First name only)" << endl;
				cin >> name;

				newperson = MainDB.get_user_Name (name);

				if (newperson != NULL) {
				cout << endl << "Info:" << endl << endl
					<< newperson->To_String() << endl << endl;
				}

			} else {
				
				string id;

				cout << "ID:" << endl;
				cin >> id;

				newperson  = MainDB.get_user_ID (id);

				if (newperson != NULL) {
				cout << endl << "Info:" << endl << endl
					<< newperson->To_String() << endl << endl;
				}

			}



		} else if (query == 2) {

			int type=0;

			cout << "Please choose one of the following:"
			<< endl
			<< "(1) Chancellor."
			<< endl
			<< "(2) Provost."
			<< endl
			<< "(3) Dean."
			<< endl
			<< "(4) Professor."
			<< endl
			<< "(5) Support Staff."
			<< endl
			<< "(6) Freshman."
			<< endl
			<< "(7) Sophomore."
			<< endl
			<< "(8) Junior."
			<< endl
			<< "(9) Senior."
			<< endl
			<< "(0) Graduate."
			<< endl;

			cin >> type;

			if (type == 1) { //chancellor

				string name, id, dept, sec;
				double pay;

				cout << "Name: (First name only)" << endl;
				cin >> name;

				cout << "ID:" << endl;
				cin >> id;

				cout << "Pay$:" << endl;
				cin >> pay;

				cout << "Department: (One word only)" << endl;
				cin >> dept;

				cout << "Secretary:" << endl;
				cin >> sec;

				newperson = new Chancellor(name, id, pay, dept, sec);
				MainDB.add_user (newperson);


			} else if (type == 2) { //provost

				string name, id, dept, sec;
				double pay;

				cout << "Name: (First name only)" << endl;
				cin >> name;

				cout << "ID:" << endl;
				cin >> id;

				cout << "Pay$:" << endl;
				cin >> pay;

				cout << "Department: (One word only)" << endl;
				cin >> dept;

				cout << "Secretary:" << endl;
				cin >> sec;

				newperson = new Provost(name, id, pay, dept, sec);
				MainDB.add_user (newperson);

			} else if (type == 3) {//Dean

				string name, id, dept, sec;
				double pay;

				cout << "Name: (First name only)" << endl;
				cin >> name;

				cout << "ID:" << endl;
				cin >> id;

				cout << "Pay$:" << endl;
				cin >> pay;

				cout << "Department: (One word only)" << endl;
				cin >> dept;

				cout << "Secretary:" << endl;
				cin >> sec;

				newperson = new Dean(name, id, pay, dept, sec);
				MainDB.add_user (newperson);

			} else if (type == 4) { //professor

				string name, id, dept, res, cl;
				double pay;

				cout << "Name: (First name only)" << endl;
				cin >> name;

				cout << "ID:" << endl;
				cin >> id;

				cout << "Pay$:" << endl;
				cin >> pay;

				cout << "Department: (One word only)" << endl;
				cin >> dept;

				cout << "Research:" << endl;
				cin >> res;

				cout << "Classes: (One word only)" << endl;
				cin >> cl;

				newperson = new Professor(name, id, pay, dept, res, cl);
				MainDB.add_user (newperson);

			} else if (type == 5) { //supp

				string name, id, bldg;
				double pay;

				cout << "Name: (First name only)" << endl;
				cin >> name;

				cout << "ID:" << endl;
				cin >> id;

				cout << "Pay$:" << endl;
				cin >> pay;

				cout << "Building of Work: (One word only)" << endl;
				cin >> bldg;

				newperson = new Support(name, id, pay, bldg);
				MainDB.add_user (newperson);

			} else if (type == 6) { //freshman

				string name, id, dept, maj, gy;
				double gpa;

				cout << "Name:(First name only)" << endl;
				cin >> name;

				cout << "ID:" << endl;
				cin >> id;

				cout << "GPA:" << endl;
				cin >> gpa;

				cout << "Major:(One word)" << endl;
				cin >> maj;

				cout << "Graduating Year:" << endl;
				cin >> gy;

				newperson = new Freshman(name, id, maj, gy, gpa);
				MainDB.add_user (newperson);

			} else if (type == 7) { //soph

				string name, id, dept, maj, gy;
				double gpa;

				cout << "Name:(First name only)" << endl;
				cin >> name;

				cout << "ID:" << endl;
				cin >> id;

				cout << "GPA:" << endl;
				cin >> gpa;

				cout << "Major:(One word)" << endl;
				cin >> maj;

				cout << "Graduating Year:" << endl;
				cin >> gy;

				newperson = new Sophomore(name, id, maj, gy, gpa);
				MainDB.add_user (newperson);

			} else if (type == 8) { //junior

				string name, id, dept, maj, gy;
				double gpa;

				cout << "Name:(First name only)" << endl;
				cin >> name;

				cout << "ID:" << endl;
				cin >> id;

				cout << "GPA:" << endl;
				cin >> gpa;

				cout << "Major:(One word)" << endl;
				cin >> maj;

				cout << "Graduating Year:" << endl;
				cin >> gy;

				newperson = new Junior(name, id, maj, gy, gpa);
				MainDB.add_user (newperson);

			} else if (type == 9) { //senior

				string name, id, dept, maj, gy;
				double gpa;

				cout << "Name:(First name only)" << endl;
				cin >> name;

				cout << "ID:" << endl;
				cin >> id;

				cout << "GPA:" << endl;
				cin >> gpa;

				cout << "Major:(One word)" << endl;
				cin >> maj;

				cout << "Graduating Year:" << endl;
				cin >> gy;

				newperson = new Senior(name, id, maj, gy, gpa);
				MainDB.add_user (newperson);

			} else { //graduate

				string name, id, dept, maj, gy;
				double gpa;

				cout << "Name:(First name only)" << endl;
				cin >> name;

				cout << "ID:" << endl;
				cin >> id;

				cout << "GPA:" << endl;
				cin >> gpa;

				cout << "Major:(One word)" << endl;
				cin >> maj;

				cout << "Graduating Year:" << endl;
				cin >> gy;

				newperson = new Graduate(name, id, maj, gy, gpa);
				MainDB.add_user (newperson);

			}



		} else if (query == 3) {

			cout << endl;

			MainDB.Print();

			cout << endl;


		} else {

			return 0;

		}


	}

	return 0;

}

