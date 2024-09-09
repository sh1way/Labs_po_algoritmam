#include <iostream>
using namespace std;

int main() {
	struct student{
		string surname;
		string name;
		int age;
		string group;
		string faculty;
	};

	student student1;

	student1.surname = "Ivanov";
	student1.name = "Ivan";
	student1.age = 19;
	student1.group = "23vvv9";
	student1.faculty = "fvt";

	student student2;

	student2.surname = "Sidorov";
	student2.name = "Pavel";
	student2.age = 24;
	student2.group = "20ODD1";
	student2.faculty = "med";

	student student3;

	student3.surname = "Salfetka";
	student3.name = "Marina";
	student3.age = 18;
	student3.group = "24vas2";
	student3.faculty = "ped";

	student student4;

	student4.surname = "Kuznecova";
	student4.name = "Anna";
	student4.age = 4;
	student4.group = "19dot2";
	student4.faculty = "fite";

	int search;

	cout << "Select search surname/name [1/2]: ";
	cin >> search;

	string target;

	if (search == 1)
	{
		cout << "Enter surname: ";
		cin >> target;

		if (student1.surname == target)
		{
			cout << "Student:\n" << student1.surname << "\n" << student1.name << "\n" << student1.age << "\n" << student1.group << "\n" << student1.faculty;
		}
		else if (student2.surname == target)
		{
			cout << "Student:\n" << student2.surname << "\n" << student2.name << "\n" << student2.age << "\n" << student2.group << "\n" << student2.faculty;
		}
		else if (student3.surname == target)
		{
			cout << "Student:\n" << student3.surname << "\n" << student3.name << "\n" << student3.age << "\n" << student3.group << "\n" << student3.faculty;
		}
		else if (student4.surname == target)
		{
			cout << "Student:\n" << student4.surname << "\n" << student4.name << "\n" << student4.age << "\n" << student4.group << "\n" << student4.faculty;
		}
		else if (student1.surname != target || student2.surname != target || student3.surname != target || student4.surname != target)
		{
			cout << "Student not found";
		}

		return 0;
	}
	else if (search == 2) 
	{
		cout << "Enter name: ";
		cin >> target;

		if (student1.name == target)
		{
			cout << "Student:\n" << student1.surname << "\n" << student1.name << "\n" << student1.age << "\n" << student1.group << "\n" << student1.faculty;
		}
		else if (student2.name == target)
		{
			cout << "Student:\n" << student2.surname << "\n" << student2.name << "\n" << student2.age << "\n" << student2.group << "\n" << student2.faculty;
		}
		else if (student3.name == target)
		{
			cout << "Student:\n" << student3.surname << "\n" << student3.name << "\n" << student3.age << "\n" << student3.group << "\n" << student3.faculty;
		}
		else if (student4.name == target)
		{
			cout << "Student:\n" << student4.surname << "\n" << student4.name << "\n" << student4.age << "\n" << student4.group << "\n" << student4.faculty;
		}
		else if (student1.name != target || student2.name != target || student3.name != target || student4.name != target)
		{
			cout << "Student not found";
		}
		
		return 0;
	}
	else if (search != 1 || search != 2) 
	{
		cout << "Enter 1 or 2, it s sposob search";
	}


	return 0;
}