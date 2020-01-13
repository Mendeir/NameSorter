#include <iostream>
#include <string>
#include <algorithm>

int getNameLength();
void getNames(int nameLength, std::string *names);
void displayNames(int nameLength, std::string *names);
void swapNames(std::string *firstName, std::string *secondName);
void sortNames(int nameLength, std::string *names);

int main()
{
	//initialization
	int nameLength = getNameLength();
	std::string* names;

	//dynamically allocate arrays
	names = new std::string[nameLength];

	std::cout << '\n';

	//get input of names
	getNames(nameLength, names);

	//sort names
	sortNames(nameLength, names);

	std::cout << '\n';

	//display names
	displayNames(nameLength, names);

}

int getNameLength()
{
	int nameLength;

	std::cout << "How many names would you like to enter? ";
	std::cin >> nameLength;

	return nameLength;

}

void getNames(int nameLength, std::string* names)
{
	for (int counter = 0; counter < nameLength; ++counter)
	{
		std::cout << "Enter name #" << counter + 1 << ": ";
		std::cin >> names[counter];
	}
}

void displayNames(int nameLength, std::string* names)
{
	for (int counter = 0; counter < nameLength; ++counter)
	{
		std::cout << "Name #" << counter + 1 << ": ";
		std::cout << names[counter];
		std::cout << '\n';
	}
}

void swapNames(std::string* firstName, std::string* secondName)
{
	std::string temp = *firstName;
	*firstName = *secondName;
	*secondName = temp;
}


void sortNames(int nameLength, std::string* names)
{
	int smallestIndex;

	//uses selection sort to sort names
	for (int counter = 0; counter < nameLength - 1; ++counter)
	{
		smallestIndex = counter;

		for (int counter1 = counter + 1; counter1 < nameLength; ++counter1)
		{
			if (names[smallestIndex] > names[counter1])
			{
				smallestIndex = counter1;
			}
		}
		swapNames(&names[counter], &names[smallestIndex]);

	}
}