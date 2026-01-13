#include <string>
#include <iostream>
#include <list>


class Employee { 
    std::string first_name;
    int department;
public:
    Employee(const std::string& name, int dept) : 
        first_name{name}, department{dept} {}
    virtual void print() const;

    virtual ~Employee() { std::cout << "~Employee() called..." << std::endl;}
};

class Manager : public Employee {
    int level;
public:
    Manager(const std::string& name, int dept, int lvl) :
        Employee(name, dept), level{lvl} {} 
    void print() const; 
};

void Employee::print() const {
    std::cout << first_name << '\t' << department;
}

void Manager::print() const {
    Employee::print();
    std::cout << "\tlevel: " << level; 
}
