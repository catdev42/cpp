#ELEMENTARY MATERIA

Features:

AMateria Class (Abstract)
	- Ice
	- Cure
	Virtual Function Behavior:
		Ice: "* shoots an ice bolt at <name> *"
		Cure: "* heals <name>’s wounds *"

ICharacter (Interface)
	Character (Concrete)

IMateriaSource (Interface)
	- for storing and cloning a new materia?

MateriaSource (Concrete):
	- has a pointer array of 4 AMateria
	- learnMateria(AMateria*): clones (using the Materia's own function)
	- createMateria(std::string const &): returns a copy according to the type