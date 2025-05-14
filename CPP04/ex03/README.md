# ELEMENTARY MATERIA

Features:

## AMateria Class (Abstract)
- Ice
- Cure

### Materia Class (Concrete)
- Virtual Function Behavior:
  - Ice: "* shoots an ice bolt at <name> *"
  - Cure: "* heals <name>'s wounds *"

## ICharacter (Interface)
### Character (Concrete)

## IMateriaSource (Interface)
- For storing and cloning a new materia

### MateriaSource (Concrete):
- Has a pointer array of 4 AMateria
- learnMateria(AMateria*): clones (using the Materia's own function)
- createMateria(std::string const &): returns a copy according to the type

## Floor 
- memory management for unequipped classes
- can only add (at this stage)
- floor items cannot be used later