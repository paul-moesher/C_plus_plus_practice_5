//-----------------------------------------------------------------------------------------------------
// CS2010											Lab 7							Date:2/23/18
// Paul Moesher																		Class time: 10:30
// Purpose: To show the user information about different aera colleges.
// Input: None for the user
// Processing: The program will read the .txt doc and display the info.
//Outout: Each schools info will be displayed.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	// Declare Varables
	string school_name, location, most_expensive;
	int Enrollment, Tution = 0, highest;
	double avg, count = 0, Tution_total = 0;
	ifstream inFile;
	ofstream outFile;

	// Open file
	inFile.open("lab7.txt");
	if (!inFile)
	{
		cout << "Error can not open file"
		<< endl;
		exit(1);
	}

	outFile.open("lab7rpt.txt");
	outFile << "                                              Ohio Universities Report" << endl;
	outFile << "                                                   Paul Moesher" << endl;
	outFile << "School Name                   Location                                   Enrollment                          Tution" << endl;


	highest = Tution;
	most_expensive = school_name;
	
	while (!inFile.eof())
	{
		if (Tution > highest) {
			highest = Tution;
			most_expensive = school_name;	
		}

		inFile >> school_name;
		inFile >> location;
		inFile >> Enrollment;
		inFile >> Tution;
		outFile << left << setw(30) << school_name
			<< left << setw(30) << location
			<< right << setw(20) << Enrollment
			<< right << setw(30) << "$"
			<< left << setw(10) << Tution << endl;
		count++;
		Tution_total += Tution;
		avg = Tution_total / count;
	}  inFile.close();
	
	// Dispaly Reults 

	cout << "Number of schools: " 
		<< setw (5) << count << endl;
	cout << setprecision(2) << fixed;
	cout << "Average Tution: "  << avg << endl;
	cout << "The highest tution is $" << highest  << " this school is " << most_expensive <<  endl;

	outFile.open("lab7rpt.txt");
	outFile << "                                              Ohio Universities Report" << endl;
	outFile << "                                                   Paul Moesher" << endl;
	outFile << "School Name                   Location                                   Enrollment                          Tution" << endl;

}
