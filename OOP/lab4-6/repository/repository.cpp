#include "repository.h"

Repository::Repository(void)
{
	Part*		part;
	std::ifstream	fin("repPart", std::ifstream::in);

	this->_partList = new std::vector<Part*>();
	part = new Part();
	while (fin >> part)
	{
		this->_partList->push_back(part);
		part = new Part();
	}
	fin.close();
}

void	myfunction(Part* el)
{
	std::cout << el->getFName() << ' ';
}

Repository::~Repository(void)
{
	std::for_each (this->_partList->begin(), this->_partList->end(), myfunction);
}
