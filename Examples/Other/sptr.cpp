#include <memory>
#include <list>
#include "../Classes/virtual.h"


using namespace std;

int main() {
    auto emp = make_shared<Employee>("Alpha", 365);
    emp->print();
    cout << endl;

    // share with others
    list<shared_ptr<Employee>> lst;
    for(int i = 0; i < 3; i++)
        lst.push_back( shared_ptr<Employee> {emp}); // copy ok

    emp.reset(); // give up sharing

    cout << "Share count: " << lst.front().use_count() << endl;

    for(int i = 0; i < 3; i++) {
        cout << "Pop: " << i << endl;
        lst.pop_back();
    }

    cout << "End of program" << endl;
    return 0;
}

