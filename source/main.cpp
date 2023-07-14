#include <iostream>
#include <fstream>
#include <string>
#include "tree.hpp"
#include "tree_node.hpp"

void task_2_1();
void task_2_2();
void task_2_3();
void reverseFiles(std::ifstream&, std::ofstream&);
void sortWords();
std::string lowerCase(std::string);

int main()
{
	//task_1
	//Tree tree;
	//tree.addValue("hello");
	//tree.addValue("hi");
	//tree.addValue("shalom");
	//tree.addValue("king");
	//tree.addValue("hellooo");
	//tree.addValue("HellO");
	//tree.addValue("HIIII");
	//tree.addValue("bye");
	//tree.addValue("yes");
	//cout << "The data (inorder): ";
	//tree.printInOrder(tree.getRoot());

	//task_2_1
	//task_2_1();

	//task_2_2
	//task_2_2();

	//task_2_3
	//task_2_3();

	//task_3
	sortWords();
	
	return 0;
}

void task_2_1()
{
	std::string fileName, line;
	std::cout << "Please enter the name of the file: ";
	std::cin >> fileName;
	std::ifstream file(fileName);

	if (file.is_open())
	{
		while (getline(file, line))
			std::cout << line << std::endl;

		file.close();
	}
	else
		std::cout << "Unable open this " << fileName << " file...";
}

void task_2_2()
{
	std::string input, output, word;
	char ch;
	std::cout << "Please enter name of input file (to read from): ";
	std::cin >> input;
	std::cout << "Please enter name of output file (to write in): ";
	std::cin >> output;
	std::ifstream inputFile(input);
	std::ofstream outputFile(output);
	
	if (inputFile.is_open() && outputFile.is_open())
	{
		//Considers spaces and new lines.
		while (inputFile.get(ch))
		{
			if (ch == ' ' || ch == '\n')
				outputFile << ch;
			else
			{
				inputFile.putback(ch);
				inputFile >> word;
				outputFile << word;
			}
		}
		outputFile.close();
		inputFile.close();
	}
	else
		std::cout << "Unable open one or both of the files: " << output << ", " << input << std::endl;
}

void task_2_3()
{
	std::string input, output, word;
	char ch;
	std::cout << "Enter name of input file (to read from): ";
	std::cin >> input;
	std::cout << "Enter name of output file (to write in): ";
	std::cin >> output;
	std::ifstream inputFile(input);
	std::ofstream outputFile(output);
	if (inputFile.is_open() && outputFile.is_open())
	{
		reverseFiles(inputFile, outputFile);
		inputFile.close();
		outputFile.close();
	}
	else
		std::cout << "Unable open one or both of the files: " << output << ", " << input << std::endl;
}

void reverseFiles(std::ifstream& inputFile, std::ofstream& outputFile)
{
	std::string word;
	if (inputFile >> word)
		reverseFiles(inputFile, outputFile);
	outputFile << word;
}


//task_3
void sortWords()
{
	std::string input, output, word;
	char ch;
	std::cout << "Enter name of input file (to read from): ";
	std::cin >> input;
	std::cout << "Enter name of output file (to write in), if you want to write to the console, please enter \".\": ";
	std::cin >> output;
	std::ifstream inputFile(input);
	
	Tree treeStrings;
	while (inputFile >> word)
		treeStrings.addValue(lowerCase(word));
	if(output != ".")
	{
		std::ofstream outputFile(output);
		treeStrings.printInOrder(treeStrings.getRoot(), outputFile);
	}
	else
		treeStrings.printInOrder(treeStrings.getRoot());
}

std::string lowerCase(std::string word)
{
	std::string newWord;
	for (char ch : word) {
		if ((ch > 64 && ch < 133) || (ch > 140 && ch < 173))
		{
			ch = tolower(ch);
			newWord += ch;
		}
	}
	return newWord;
}