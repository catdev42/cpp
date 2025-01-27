#include "MateriaSource.h"
#include "AMateria.h"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        _materiaLearned[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; i++) {
        if (other._materiaLearned[i]) {
            _materiaLearned[i] = other._materiaLearned[i]->clone();
        } else {
            _materiaLearned[i] = NULL;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this == &other) return *this;
    for (int i = 0; i < 4; i++) {
        delete _materiaLearned[i];
        if (other._materiaLearned[i]) {
            _materiaLearned[i] = other._materiaLearned[i]->clone();
        } else {
            _materiaLearned[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        delete _materiaLearned[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; i++) {
        if (!_materiaLearned[i]) {
            _materiaLearned[i] = m->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (_materiaLearned[i] && _materiaLearned[i]->getType() == type) {
            return _materiaLearned[i]->clone();
        }
    }
    return NULL;
}
