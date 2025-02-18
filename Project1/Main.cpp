
// Vectors and Arrays
// Alex Freimuth

#include <iostream>
#include <conio.h>
#include <vector> // add vectors
#include <string> // add string
#include <fstream> // add file i/o

using namespace std;

void PrintNumbers(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i];
		if (i < size - 1) cout << ", ";
	}
}

int main()
{
	cout << "Write what you want. \n";
	string line;
	getline(cin, line);
	cout << line << "\n\n";

	string filePath = "C:\\Temp\\Bla.txt";
	ofstream ofs(filePath);
	//ofs.open(filePath);
	if (ofs)
	{
		ofs << line << "\n\n";
		ofs << "Alex";
		ofs.close(); // remember to close the stream
	}

	ifstream ifs(filePath);
	if (ifs)
	{
		while (getline(ifs, line))
		{
			cout << line << "\n"	;
		}


		ifs.close(); // close the stream so it wont crash on future use
	}

	// array on stack
	const int SIZE = 5;
	int nums[SIZE] = { 1, 2, 3, 4, 5 };

	PrintNumbers(nums, SIZE);

	// array on heap
	int size = 0;
	cout << "\nhow many?: ";
	cin >> size;
	int* heapNums = new int[size];
	PrintNumbers(heapNums, size);

	// vectors
	vector<int> moreNums;
	int temp = 0;
	char another = 'y';

	while (true)
	{
		cout << "\nAdd a number to the vector: ";
		cin >> temp;
		moreNums.push_back(temp);

		cout << "Another? (y): ";
		cin >> another;
		if (another != 'y') break;
	}

	// 'bad' way
	for (int i = 0; i < moreNums.size(); i++)
	{
		cout << moreNums[i];
		if (i < moreNums.size() - 1) cout << ", ";
	}

	cout << "\n\n";

	// "old" but fast way
	vector<int>::iterator it = moreNums.begin();
	for (; it != moreNums.end(); it++)
	{
		cout << *it; // dereference the iterator
		cout << ", ";
	}

	cout << "\n\n";

	// "new"-ish way
	for (const int& n : moreNums)
	{
		cout << n << ", ";
	}

	// strings
	char name[] = "Alex";
	string sName = name;// = "Alex";

	//sName.c_str() // onvert to c-style string

	string lastName;
	cout << "\n Give a last name: ";
	cin >> lastName;

	string fullName = sName + " " + lastName;
	cout << fullName;


	(void)_getch();
	return 0;
}
