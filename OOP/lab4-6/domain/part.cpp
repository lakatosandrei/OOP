#include "domain.h"
#include<iostream>
Part::Part(char* fname, char* lname, int* score)
{
	int	i;

	this->_fname = strdup(fname);
	this->_lname = strdup(lname);
	this->_score = (int *)malloc(sizeof(int) * 10);
	i = 0;
	while (i < 10)
	{
		this->_score[i] = score[i];
		i++;
	}
}

Part::Part(void)
{
	this->_fname = (char *)malloc(sizeof(char) * 40);
	this->_lname = (char *)malloc(sizeof(char) * 40);
	this->_score = (int *)malloc(sizeof(int) * 10);
}

Part::~Part(void)
{
	std::cout << "O intrat.\n" << this->_fname << "\n";
	free(this->_fname);
	free(this->_lname);
	free(this->_score);
}

std::istream&	operator>>(std::istream& in, Part* part)
{
	int	i;

	in.getline(part->_fname, 40, ';');
	in.getline(part->_lname, 40, ';');
	i = 0;
	while (i < 10)
	{
		in >> part->_score[i];
		i++;
	}
	in.ignore();
	return (in);
}

std::ostream&	operator<<(std::ostream& on, Part* part)
{
	double	average;

	average = part->getAverage();
	on << part->_fname << ' ' << part->_lname << ' ' << average;
	return (on);
}

void	Part::setFName(char* fname)
{
	free(this->_fname);
	this->_fname = strdup(fname);
}

void	Part::setLName(char* lname)
{
	free(this->_lname);
	this->_lname = strdup(lname);
}

void	Part::setScore(int* score)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		this->_score[i] = score[i];
		i++;
	}
}

double	Part::getAverage(void)
{
	int	i;
	double	s;

	s = 0;
	i = 0;
	while (i < 10)
	{
		s += this->_score[i];
		i++;
	}
	return (s / 10);
}
