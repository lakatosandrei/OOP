#ifndef REPOSITORY1_H
# define REPOSITORY1_H

# include "../utils/vector.h"
# include "../domain/part.h"
# include <iostream>
# include <vector>
# include <unistd.h>
# include <fcntl.h>

class Repository {
	private:
		std::vector<Part>*	_partList;
		void	readFromFile(void);
	public:
		Repository(void) {};
		void	modifyRepository(std::vector<Part>* partList);
		std::vector<Part>*	getPart(void) {return (this->_partList); }
		~Repository(void) {};
};

#endif
