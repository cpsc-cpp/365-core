#include <string>
#include <list>
#include <vector>
#include <memory>
#include <iostream>


using namespace std;

struct Node {
    size_t num;
    list<shared_ptr<Node>> nbrs;
    Node(size_t i = 0) : num{i} {}

    void print() {
        cout << "Node " << num << ": --> ";
        for(const auto &nbr : nbrs) {
            cout << nbr->num << " ";
        }
        cout << endl;
    }

    ~Node() {
        cout << "Deleting Node: " << num << " ..." << endl;
    }
};

// A DAG with a single source
struct DAG {
    shared_ptr<Node> source;
    vector<weak_ptr<Node>> nodes;

    void print() {
        for(const auto& node : nodes) {
            if(shared_ptr<Node> np = node.lock()) {
                np->print();
            }
        }
    }

    // remove an interior node
    void removeNode( size_t num ) {
        if( num == source->num)
            return;
        
        for(const auto& node : nodes) {
            if(shared_ptr<Node> np = node.lock()) {
                for(auto itr = np->nbrs.begin(); itr!= np->nbrs.end(); itr++) {
                    if( (*itr)->num == num) {
                        itr = np->nbrs.erase(itr);
                    }
                }
            }
        }
    }
};

DAG dag;
const size_t NUM = 4;

void buildGraph() {
    vector<shared_ptr<Node>> nodes;
    for(size_t i = 0; i < NUM; i++) {
        nodes.push_back( make_shared<Node>(i) );
    }

    for(size_t i = 0; i < NUM; i++) {
        for(size_t j = i+1; j < NUM; j++ ) {
            nodes[i]->nbrs.push_back( nodes[j] );
        }
    }

    // set weak pointers
    for(size_t i = 0; i < NUM; i++) {
        dag.nodes.push_back( nodes[i] );
    }

    // set the source
    dag.source = nodes[0];
}

int main() {
    buildGraph();
    dag.print();
    dag.removeNode( 3 );

    dag.print();
    // do some simple ops
}