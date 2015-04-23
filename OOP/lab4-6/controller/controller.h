#ifndef CONTROLLER1_H
# define CONTROLLER1_H

# include "../domain/part.h"
# include "../repository/repository.h"

# include <iostream>
# include <vector>

class Controller {
	private:
		Repository*	_rep;
	public:
		Controller(Repository* rep) {this->_rep = rep;}
		void			addPart(char* fname, char* lname, int* score);
		void			modifyPart(char *fname, char *lname, int *score, int poz);
		void			delPart(int poz);
		void			sort(int (*cmp)(void*, void*));
		std::vector<Part*>*	filter(int (*filt)(void*, void *), void *info);
		std::vector<Part*>*	getList(void);
		~Controller(void) {delete this->_rep;}
};

#endif
