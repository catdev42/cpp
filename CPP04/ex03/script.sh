#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <ClassName>"
    exit 1
fi

CLASS_NAME=$1
if [ -f "${CLASS_NAME}.cpp" ]; then
    echo "${CLASS_NAME}.cpp already exists"
    exit 1
fi

cat > ${CLASS_NAME}.cpp << EOL
#include "${CLASS_NAME}.hpp"
#include <iostream>

/* Default constructor */
${CLASS_NAME}::${CLASS_NAME}() : type("${CLASS_NAME}")
{
    std::cout << "${CLASS_NAME} default constructor" << std::endl;
    return;
}

/* Parametrized constructor */
${CLASS_NAME}::${CLASS_NAME}(/*PARAMETER*/) : type("${CLASS_NAME}")
{
    std::cout << "${CLASS_NAME} parametrized constructor" << std::endl;
    return;
}

/* Copy constructor */
${CLASS_NAME}::${CLASS_NAME}(${CLASS_NAME} const &src)
{
    std::cout << "${CLASS_NAME} copy constructor" << std::endl;
    /*TODO*/;
    return;
}

/* Assignment operator */
${CLASS_NAME} &${CLASS_NAME}::operator=(${CLASS_NAME} const &rhs)
{
    std::cout << "${CLASS_NAME} copy assignment operator" << std::endl;
    if (this != &rhs)
    {
      /*TODO*/;
    }
    return *this;
}

/* Destructor */
${CLASS_NAME}::~${CLASS_NAME}()
{
    std::cout << "${CLASS_NAME} destructor" << std::endl;
    return;
}

/* Getters */
//Example: std::string ${CLASS_NAME}::getType() const { return type; }

/* Stream operator overload */
std::ostream &operator<<(std::ostream &o, const ${CLASS_NAME} &infile)
{
    o << std::endl;
    return o;
}
EOL

echo "Generated ${CLASS_NAME}.cpp with template code"