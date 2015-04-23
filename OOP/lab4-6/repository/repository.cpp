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
	std::vector<Part*>::iterator	it;

	for(it = this->_partList->begin(); it != this->_partList->end() ; it++)
	{
		std::cout << *it << '\n';
		delete *it;
	}
	this->_partList->clear();
}

void	Repository::pushPart(Part* part)
{
	this->_partList->push_back(part);
}

void	Repository::modifyPart(Part* part, int poz)
{
	delete (*this->_partList)[poz];
	(this->_partList)->at(poz) = part;
}

void	Repository::deletePart(int poz)
{
	this->_partList->erase(this->_partList->begin() + poz);
}
