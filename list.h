//
//  list.h
//  Lab8_C
//
//  Created by Alex Mclean on 2022-11-23.
//

#ifndef list_h
#define list_h
#include <stdio.h>

struct ListItem {
    int year;
    double flow;
};

struct Node {
    ListItem item;
    Node *next;
};

class FlowList {
public:
    FlowList();
    ~FlowList();

    void insert(const ListItem& itemA);
    void remove(const ListItem& itemA);

    void print() const;
    void print2() const;
    
private:
    Node *headM;
    void destroy();
    // List becomes copy of source.
};
#endif
