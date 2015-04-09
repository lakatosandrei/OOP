#ifndef CONTROLLER1_H
# define CONTROLLER1_H

# include "../utils/vector.h"
# include "../domain/part1.h"
# include "../repository/repository1.h"

# include <iostream>
# include <vector>

class Controller {
	private:
		Repository*	_rep;
	public:
		Controller(Repository* rep) {this->_rep = rep;}
		void	addPart(char* fname, char* lname, int* score);
		void	modifyPart(char *fname, char *lname, int *score, int poz);
		void	delPart(int poz);
		void	sort(int (*cmp)(Part, Part));
		void	filter(int (*filt)(Part, void *), void *info);
		~Controller(void) {delete this->_rep;}
};

#endif
