#ifndef REPOSITORY1_H
# define REPOSITORY1_H

# include "../domain/part.h"
# include <iostream>
# include <fstream>
# include <vector>
# include <unistd.h>
# include <fcntl.h>
# include <algorithm>

class Repository {
	private:
		std::vector<Part*>*	_partList;
		void	readFromFile(void);
	public:
		Repository(void);
		~Repository(void);
		void			pushPart(Part* part);
		void			modifyPart(Part* part, int poz);
		void			deletePart(int poz);
		std::vector<Part*>*	getPart(void) {return (this->_partList); }
};

#endif
