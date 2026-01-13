/**
 * @file IntList.cpp
 * @brief Implementation of a basic singly-linked list
 *  
 * A singly-linked list accessible at the head.
 * 
 */

#include <iostream>
#include <cstring>

#include "IntList.h" 

using namespace std;

void addToHead( List& list, int32_t data ) {
    // create a new link
    Link* link = new Link { nullptr, data };

    if ( list.size == 0 ) {
        // handle an empty list
        list.head = link;
    } else {
        // handle a non-empty list
        link->next = list.head;
        list.head = link; 
    }
    list.size++;
}

void deleteFromHead( List& list ) {
    if(list.size > 0) {
        if (list.size == 1) {
            delete list.head;
            list.head = nullptr; 
        } else {
            Link* ahead = list.head->next;
            delete list.head;
            list.head = ahead;
        }
        list.size--;
    }
}

// Forward declaration of function
Link* reverse_rec(Link* head);

// wrapper function that calls the recursive function after a size check
void reverse(List& list) {
    if(list.size > 1) {
        list.head = reverse_rec(list.head);
    }
}

// Recursively reverse a list
Link* reverse_rec(Link* head) {
    if (head->next == nullptr) {
        return head;
    } else {
        Link* newHead = reverse_rec(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
}

// Sort an integer list in-place via selection sort.
// Swaps values, without altering the link structure.
void sort(List& list) {
    if(list.size > 1) {
        // outer loop to select sublists
        for(Link* start = list.head; start->next != nullptr; start = start->next) {
            Link* minLink = start;
            // find minimum in sublist
            for(Link* cur = start->next; cur != nullptr; cur = cur->next) {
                if (cur->data < minLink->data) {
                    minLink =  cur;
                }
            }
            //swap data value if necessary
            if( minLink != start ) {
                int32_t min = minLink->data;
                minLink->data = start->data;
                start->data = min;
            }
        }   
    }
}


void clear( List& list ) {
    for(size_t i = 0; i < list.size; i++ ) {
        deleteFromHead( list );
    }
}

void print( const List& list ) {
    cout << "{";
    for( Link* link = list.head; link != nullptr; link = link->next ) {
        cout << link->data << ", ";
    }
    cout << "}" << endl;
}

int main() {
    List list {nullptr, 0};
    
    cout << "Adding and reversing: " << endl;
    print( list );
    for(size_t i = 0; i < 10; i++) {
        addToHead( list, i );
        reverse(list);
        print( list );
        reverse( list );
    }
    cout << endl << "Incremental deletions:" << endl;
    for(size_t i = 0; i < 10; i++ ) {
        deleteFromHead( list );
        print( list ); 
    }

    cout << endl << "Sorting: " << endl;
    // Test sorting
    for(size_t i = 0; i < 10; i++ ) {
        addToHead( list, i%5);
        sort(list);
        print( list ); 
    }

    // clear list for cleanup
    clear(list);

}