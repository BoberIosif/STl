#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

void displayInfo(std::vector<int> v);
void displayVector(std::vector<int> v);

int main()
{
	std::vector<int> v1(5);
	displayInfo(v1);
	displayVector(v1);
	for (int i = 0; i < 7; i++)
	{
		v1.push_back(10 * (i + 1));
	}
	displayInfo(v1);
	displayVector(v1);

	// 2-> access to elements
	// ----------------------
	v1.front() = 555;
	v1.back() = 777;
	std::cout << "\n> First element: " << v1.front()<< std::endl;
	std::cout << " Second element: " << v1[1] << std::endl;
	std::cout << " Last element: " << v1.back() << std::endl;
	std::cout << " 6-th element: " << v1[5] << std::endl;
	//std::cout << " NextLast element: " << v1[v1.size()] << std::endl;

	try
	{
		std::cout << "\n> First element: " << v1.at(0) << std::endl;
		std::cout << " Second element: " << v1.at(1) << std::endl;
		std::cout << " Last element: " << v1.at(v1.size() - 1) << std::endl;
		std::cout << " 6-th element: " << v1.at(5) << std::endl;
		std::cout << " NextLast element: " << v1.at(v1.size()) << std::endl;
	}
	catch (const std::out_of_range& err)
	{
		std::cerr << " Out of range Exception :  " << err.what() << std::endl;
	}

	// 3-> iterator vector

	std::vector<int>::iterator iter;
	iter = v1.begin();
	std::cout << "\n> 1-st element: " <<  *iter << std::endl;
	iter = v1.end() - 1;
	std::cout << "\n> Last element: " << *iter << std::endl;

	for (iter = v1.begin(); iter != v1.end(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	// 4. -> Methods-modificators

	v1.insert(v1.begin(), 333);
	displayInfo(v1);
	displayVector(v1);

	v1.insert(v1.begin() + 7, 444);
	displayInfo(v1);
	displayVector(v1);

	v1.erase(v1.begin() + 6);
	displayInfo(v1);
	displayVector(v1);

	v1.erase(v1.begin() + 7, v1.end() - 1);
	/*v1.erase(v1.begin() + 7);
	v1.erase(v1.begin() + 7);
	v1.erase(v1.begin() + 7);
	v1.erase(v1.begin() + 7);*/
	displayInfo(v1);
	displayVector(v1);

	v1.resize(v1.size() + 5);
	displayInfo(v1);
	displayVector(v1);

	v1.clear();
	displayInfo(v1);
	displayVector(v1);

	return 0;
}

void displayInfo(std::vector<int> v)
{
	if (v.empty()) {
		std::cout << " This vector is empty!" << std::endl;
	}
	else
	{
		std::cout << " This vecror is not empty! " << std::endl;
	}
	std::cout << "size of vector is - " << v.size() << " elements" << std::endl;
	//std::cout << "MaxSize of vector is - " << v.max_size() << " elements" << std::endl;
	std::cout << "Capacity of vector is - " << v.capacity() << " elements" << std::endl;
}

void displayVector(std::vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}
