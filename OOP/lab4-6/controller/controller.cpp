#include "controller.h"

void			Controller::addPart(char* fname, char* lname, int* score)
{
	Part*	part = new Part(fname, lname, score);

	this->_rep->pushPart(part);
}

void			Controller::modifyPart(char* fname, char* lname, int* score, int poz)
{
	Part*	part = new Part(fname, lname, score);

	this->_rep->modifyPart(part, poz);
}

void			Controller::delPart(int poz)
{
	this->_rep->deletePart(poz);
}

void			Controller::sort(int (*cmp)(void*, void*))
{
	Part				*aux;
	std::vector<Part*>*		partList = this->_rep->getPart();
	std::vector<Part*>::iterator	it;

	it = partList->begin();
	while (it != partList->end())
	{
		std::vector<Part*>::iterator	jt;
		jt = partList->begin();
		while (jt != partList->end() - 1)
		{
			if ((*cmp)(*it, *jt) == 1)
			{
				aux = *it;
				*it = *jt;
				*jt = aux;
			}
			jt++;
		}
		it++;
	}
}

std::vector<Part*>*	Controller::filter(int (*filt)(void *, void *), void *info)
{
	std::vector<Part*>*		partList = this->_rep->getPart();
	std::vector<Part*>::iterator	it;
	std::vector<Part*>*		newList = new std::vector<Part*>();

	it = partList->begin();
	while (it != partList->end())
	{
		if ((*filt)(*it, info) == 1)
			newList->push_back(*it);
		it++;
	}
	return (newList);
}

std::vector<Part*>*	Controller::getList(void)
{
	return (this->_rep->getPart());
}
