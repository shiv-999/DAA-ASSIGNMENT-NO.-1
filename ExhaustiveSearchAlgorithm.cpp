#include <iostream>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <string>
#include <vector>
#include <timer.h>
#include <Project2.h>
using namespace std;

// the maximum weight
const int MAX_WEIGHT = 65536;

// the number of packages to examine
const int NUM_PACKAGES = 24;

int main()
{
	// declare variables
	Timer timer;
	Project2 proj2;
	ifstream infile;
	PackageStats access;
	vector<PackageStats> packages;
	vector<PackageStats> bestCombo;	
	int totPackages = 0;

	// open file & make sure it exists
	infile.open("knapsack_packages.txt");
	if(infile.fail())
	{
		cerr<<"nCant find file!n";
		exit(1);
	}

	// get the total number of packages from the file
	infile >> totPackages;	
	
	// make sure there are enough packages in the file
	assert(NUM_PACKAGES <= totPackages);
	
	// display stats
	cerr<<"n = "<<NUM_PACKAGES<<", W = "<<MAX_WEIGHT
		<<"nn-- Exhaustive Search Solution --nn";	
	
	// get the remaining info from the file
	//                      std::string        int             int
	for(int x=0; (infile >> access.name >> access.votes >> access.size)
		&& x < NUM_PACKAGES; ++x)
	{
		packages.push_back(access);
	}
	infile.close();

	// start the timer
	timer.Start();
	
	// find the best knapsack subset solution
	bestCombo = proj2.ExhaustiveKnapsack(packages, MAX_WEIGHT);
	
	// stop the timer
	timer.Stop();

	// display the best solution packages
	proj2.Display(bestCombo, bestCombo.size());

	// display the size and total votes
	cout<<"nTotal Size = "<<proj2.TotalSize(bestCombo)<<" -- Total Votes = "
		<<proj2.TotalVotes(bestCombo)<<endl;

	// display the elapsed time
	cout<<"nIt took "<<timer.Elapsed()*1000
		<<" clicks ("<<timer.Elapsed()<<" seconds)"<<endl;

	return 0;
}// http://programmingnotes.org/