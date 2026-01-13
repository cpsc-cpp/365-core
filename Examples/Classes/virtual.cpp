#include "virtual.h"

using namespace std;

int main() {
    Employee e { "Alpha", 365};
    Manager m { "Bravo", 365, 2 };

    list<Employee*> lst {&e, &m};
    for(auto emp : lst) {
        emp->print();
        cout << endl;
    }
}
