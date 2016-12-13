// Eric Lima
// Project 2

#include <iostream>
#include <string>
#include "UniversityDatabase.h"
#include "UniversityPerson.h"
#include "underAdministration.h"
#include "underTeaching.h"
#include "Research.h"
#include "Teaching.h"
#include "Administration.h"
#include "Faculty.h"
#include "underSupport.h"
#include "Academic.h"
#include "Support.h"
#include "underStudent.h"
#include "Alumnus.h"
#include "Employee.h"
#include "Student.h"
#include "Hourly.h"

using std::cout;
using std::cin;
using std::endl;

void add_person_interface (UniversityDatabase *udb);

int main (int argc, char *argv[]) {

  UniversityDatabase udb;
  
  int option = 0;

  do {

    cout << "University Database" << endl;
    cout << "1: Add/overwrite person" << endl;
    cout << "2: Lookup by name" << endl;
    cout << "3: Lookup by ID number" << endl;
    cout << "4: Delete a person" << endl;
    cout << "5: List all people" << endl;
    cout << "6: Exit" << endl;
    cout << ">";

    cin >> option;

    cout << endl;

    std::string name, id;//input for lookup

    switch (option) {

    case 1:
      add_person_interface (&udb);

      break;

    case 2:
      cout << "Name: ";
      cin >> name;
      cout << (udb.lookup_name(name)) -> toString() << endl;
      break;

    case 3:
      cout << "ID Number: ";
      cin >> id;
      cout << (udb.lookup_id(id)) -> toString() << endl;
      break;

    case 4:
      cout << "ID of the person to delete: " << endl;
      cin >> id;
      cout << "\"" << (udb.lookup_id(id)) -> getName() << "\" deleted.\n" << endl;
      udb.remove (id);
      break;

    case 5:
      udb.printList();
      break;

    case 6:
      // exit
      break;

    default:
      cout << "Invalid option";
      break;
    }

  } while (option != 6);


  return 0;
}


void add_person_interface (UniversityDatabase *udb) {

  UniversityPerson *up;
  int option;

  cout << "Add Person" << endl;
  cout << " 1: Administration - Chancellor" << endl;
  cout << " 2: Administration - Provost" << endl;
  cout << " 3: Administration - Dean" << endl;
  cout << " 4: Administration - Chair" << endl;
  cout << " 5: Faculty - Research" << endl;
  cout << " 6: Teaching - Instructor" << endl;
  cout << " 7: Teaching - Associate Professor" << endl;
  cout << " 8: Teaching - Assistant Professor" << endl;
  cout << " 9: Teaching - Professor" << endl;
  cout << "10: Teaching - Professor Emeritus" << endl;
  cout << "11: Employee - Hourly" << endl;
  cout << "12: Support - Administrative" << endl;
  cout << "13: Support - Custodial" << endl;
  cout << "14: Student - Freshman" << endl;
  cout << "15: Student - Sophomore" << endl;
  cout << "16: Student - Junior" << endl;
  cout << "17: Student - Senior" << endl;
  cout << "18: Student - Graduate" << endl;
  cout << "19: University Person - Alumnus" << endl;
  cout << ">";

  cin >> option;
  cout << endl;

  // UniversityPerson data
  std::string name, IDnumber;
  cout << "Full name: ";
  cin >> name;
  cout << "ID Number: ";
  cin >> IDnumber;

  // Employee data
  if (option <= 13) {
    
    int wage;
    cout << "Wage: ";
    cin >> wage;

    // Academic data
    if (option <= 10) {

      std::string office;
      cout << "Office: ";
      cin >> office;

      // Administration data & creation
      if (option <= 4) {

	std::string secretary;
	cout << "Secretary: ";
	cin >> secretary;

	switch (option) {

	case 1:
	  up = new Chancellor (name, IDnumber, wage, office, secretary);
	  cout << "Chancellor added." << endl;
	  break;
	case 2:
	  up = new Provost (name, IDnumber, wage, office, secretary);
	  cout << "Provost added." << endl;
	  break;
	case 3:
	  up = new Dean (name, IDnumber, wage, office, secretary);
	  cout << "Dean added." << endl;
	  break;
	case 4:
	  up = new Chair (name, IDnumber, wage, office, secretary);
	  cout << "Chair added." << endl;
	  break;
	}
	udb -> addUniversityPerson (up);

      }

      // Faculty data
      else {
	
	std::string classroom;
	cout << "Classroom: ";
	cin >> classroom;

	if (option == 5) {
	  up = new Research (name, IDnumber, wage, office, classroom);
	  udb -> addUniversityPerson (up);
	  cout << "Research added." << endl;
	}

	// Teaching data
	else {

	  int nClasses;
	  cout << "Number of classes: ";
	  cin >> nClasses;

	  switch (option) {

	  case 6:
	    up = new Instructor (name, IDnumber, wage, office, classroom, nClasses);
	    cout << "Instructor added." << endl;
	    break;

	  case 7:
	    up = new AssociateProfessor (name, IDnumber, wage, office, classroom, nClasses);
	    cout << "Associate Professor added." << endl;
	    break;

	  case 8:
	    up = new AssistantProfessor (name, IDnumber, wage, office, classroom, nClasses);
	    cout << "Assistant Professor added." << endl;
	    break;

	  case 9:
	    up = new Professor (name, IDnumber, wage, office, classroom, nClasses);
	    cout << "Professor added." << endl;
	    break;

	  case 10:
	    up = new ProfessorEmeritus (name, IDnumber, wage, office, classroom, nClasses);
	    cout << "Professor Emeritus added." << endl;
	    break;
	  }
	  udb -> addUniversityPerson (up);

	}

      }

    }

    // Hourly
    else if (option == 11) {
      up = new Hourly (name, IDnumber, wage);
      cout << "Hourly added" << endl;
      udb -> addUniversityPerson (up);
    }

    // Support
    else {

      std::string building;
      cout << "Building: ";
      cin >> building;

      if (option == 12) {
	up = new Administrative (name, IDnumber, wage, building);
	cout << "Administrative added" << endl;
      }
      else {
	up = new Custodial (name, IDnumber, wage, building);
	cout << "Custodial added" << endl;
      }

      udb -> addUniversityPerson (up);

    }

  }

  // Student/Alum
  else {

    if (option <= 18) {

      float GPA;
      cout << "GPA: ";
      cin >> GPA;

      switch (option) {

      case 14:
	up = new Freshman (name, IDnumber, GPA);
	cout << "Freshman added" << endl;
	break;
	
      case 15:
	up = new Sophomore (name, IDnumber, GPA);
	cout << "Sophomore added" << endl;
	break;

      case 16:
	up = new Junior (name, IDnumber, GPA);
	cout << "Junior added" << endl;
	break;

      case 17:
	up = new Senior (name, IDnumber, GPA);
	cout << "Senior added" << endl;
	break;

      case 18:
	up = new Graduate (name, IDnumber, GPA);
	cout << "Graduate added" << endl;
	break;
      }
      udb -> addUniversityPerson (up);

    }

    // Alumnus
    else {

      up = new Alumnus (name, IDnumber);
      cout << "Alumnus added" << endl;
      udb -> addUniversityPerson (up);

    }


  }


  cout << endl;
}
