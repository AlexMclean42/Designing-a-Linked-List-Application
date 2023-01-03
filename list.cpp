//
//  list.cpp
//  Lab8_C
//
//  Created by Alex Mclean on 2022-11-23.
//


#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"
#include <fstream>


FlowList::FlowList(): headM(0)
{
}

FlowList::~FlowList()
{
    destroy();
}

void FlowList::print() const
{
    if (headM != 0) {
        for (const Node *p = headM->next; p != 0; p = p->next){
            cout << "" << p->item.year;
            cout << "         " << p->item.flow;
            cout << "\n";

        }
    }
}

void FlowList::print2() const
{
    ofstream outObj ("/flow.txt");
    if (outObj.is_open()){
        if (headM != 0) {
            for (const Node *p = headM->next; p != 0; p = p->next){
                outObj << setw(1) << p->item.year << setw(15) << p->item.flow << endl;
            }
            outObj.close();
        }
        else{
            cout << "Unable to open file";
            }
            cout << "Data are saved into the file." << endl;
    }
}


void FlowList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;

    if (headM == 0 || itemA.year <= headM->item.year ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && itemA.year > after->item.year) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}

void FlowList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == 0 || itemA.year < headM->item.year)
        return;

    Node *doomed_node = 0;
    if (itemA.year == headM->item.year) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA.year > maybe_doomed->item.year) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        // point three
    }
        if (maybe_doomed == 0)
            return;
        if (itemA.year == maybe_doomed->item.year) {
            doomed_node = maybe_doomed;
            before->next = doomed_node->next;
        }
    }
}

void FlowList::destroy()
{
}


