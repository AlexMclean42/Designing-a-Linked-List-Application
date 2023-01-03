//
//  hydro.cpp
//  Created by Alex Mclean on 2022-11-24.
//

#include "hydro.h"
#include <iostream>
using namespace std;
#include "list.h"
#include <fstream>

int main(void) {
    FlowList x;
    int numRecords;
    displayHeader();
    pressEnter();
    numRecords = readData(x);
    int quit = 0;
    while(1){
        switch(menu()){
            case 1:
                display(x);
                pressEnter();
                break;
            case 2:
                addData(x, numRecords);
                pressEnter();
                break;
            case 3:
                saveData(x);
                pressEnter();
                break;
            case 4:
                removeData(x);
                pressEnter();
                break;
            case 5:
                cout << "\nProgram terminated!\n\n";
                quit = 1;
                break;
            default:
                cout << "\nNot a valid input.\n";
                pressEnter();
    }
    if(quit == 1) break;
    }
}

void displayHeader(){
    cout << "Program: Flow Studies Fall 2022\nVersion: 1.0\nProduced by: Alex McLean\n";
}

void pressEnter(){
    cout << "\n<<<Press Enter to Continue>>>>\n";
    cin.get();
}

int readData(FlowList &x){
    ListItem k;
    int i=0;
    ifstream inObj;
    inObj.open ("/Users/alexmclean/Desktop/ENSF_337/flow.txt");
    if (! inObj) {
        cout << "Error: cannot open the file" << endl;
        exit(1);
    }
    while(inObj >> k.year >> k.flow) {
        x.insert(k);
        i++;
    }
    inObj.close();
    return i;
}

int menu(){
    cout << "Please select on the following operations\n    1. Display flow list, and the average.\n    2. Add data.\n    3. Save data into the file\n    4. Remove data\n    5. Quit\n    Enter your choice (1, 2, 3, 4, of 5):\n";
    int y;
    cin >> y;
    return y;
}

void display(FlowList &x){
    ListItem t;
    double c = 0;
    int i = 0;
    ifstream inObj;
    inObj.open ("/Users/alexmclean/Desktop/ENSF_337/flow.txt");
    if (! inObj) {
        cout << "Error: cannot open the file" << endl;
        exit(1);
    }
    cout << "Year       Flow (in billions of cubic meters)" << endl;
    cout << "----       ----------------------------------" << endl;
    x.print();
    while(inObj >> t.year >> t.flow) {
        c = c + t.flow;
        i++;
    }
    double avg = average(c, i);
    cout << "The annual average of the flow is: " << avg << " billions of cubic meter" << endl;
    inObj.close();
    
}

double average(double c, int i){
    int avg;
    avg = c/i;
    return avg;
}


int addData(FlowList &x, int numRecords){
    ListItem t;
    cout << "Please enter a year: ";
    cin >> t.year;
    int a;
    double b;
    ifstream inObj;
    inObj.open ("/Users/alexmclean/Desktop/ENSF_337/flow.txt");
    if (! inObj) {
        cout << "Error: cannot open the file" << endl;
        exit(1);
    }
    while(inObj >> a >> b) {
        if(t.year == a){
            cout << "Error: duplicate data." << endl;
            return numRecords;
        }
    }
    cout << "Please enter the flow: ";
    cin >> t.flow;
    x.insert(t);
    cout << "New record inserted successfully." << endl;
    return numRecords++;

}
void saveData(FlowList &x){
    x.print2();
    }

void removeData(FlowList &x){
    ListItem t;
    cout << "Please enter the year that you want to remove: ";
    cin >> t.year;
    int a;
    double b;
    ifstream inObj;
    inObj.open ("/Users/alexmclean/Desktop/ENSF_337/flow.txt");
    if (! inObj) {
        cout << "Error: cannot open the file" << endl;
        exit(1);
    }
    while(inObj >> a >> b) {
        if(t.year == a){
            x.remove(t);
            cout << "Record was successfully removed." << endl;
            return;
        }
    }
    cout << "Error: No such a data" << endl;
    return;
}
