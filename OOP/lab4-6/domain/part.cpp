#include "domain.h"

Part::Part(char* fname, char* lname, int* score) {
	int	i;

	this->_fname = strdup(fname);
	this->_lname = strdup(lname);
	this->_score = (int *)malloc(sizeof(int) * 10);
	i = 0;
	for (i = 0; i < 10 ; i++)
		this->_score[i] = score[i];
}

Part::~Part(void) {
	free(this->_fname);
	free(this->_lname);
	free(this->_score);
}

void	Part::setFName(char* fname) {
	if (this->_fname != 0)
		free(this->_fname);
	this->_fname = strdup(fname);
}

void	Part::setLName(char* lname) {
	if (this->_lname != 0)
		free(this->_lname);
	this->_lname = strdup(lname);
}

void	Part::setScore(int* score) {
	int	i;

	i = 0;
	for (i = 0; i < 10 ; i++)
		this->_score[i] = score[i];
}

double	Part::getAverage(void)
{
	int	i;
	int	s;

	s = 0;
	i = 0;
	while (i < 10)
		s += this->_score[i++];
	return ((double)s / 10);
}
