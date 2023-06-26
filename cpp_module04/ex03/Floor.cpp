#include "Floor.hpp"

Floor::Floor()
{
	for (int i = 0; i< 4; i++)
		this->floor[i] = 0;
}

Floor::Floor(Floor const &ob)
{
	for(int i = 0; i < 4; i++)
		this->floor[i] = ob.floor[i];
}

Floor &Floor::operator=(Floor const &ob)
{
	if (this != &ob)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->floor[i])
				delete this->floor[i];
			this->floor[i] = ob.floor[i];
		}
	}
	return *this;
}

Floor::~Floor()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->floor[i])
			delete this->floor[i];
	}
}

AMateria *Floor::getMateria(int idx) const
{
	for(int i = 0; i < 4; i++)
	{
		if (idx == i && this->floor[i])
			return this->floor[i];
	}
	return 0;
}

void Floor::setMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->floor[i])
		{
			this->floor[i] = m;
			return ;
		}
	}
}
