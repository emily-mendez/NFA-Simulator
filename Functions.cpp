#include "Functions.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
using namespace std;

void Functions::readInputs(string fileName, string strInput) {
    ifstream infile(fileName);
    string line;
    string first; int state; string condition;
    while(getline(infile, line)) {
        stringstream ss(line);
        ss >> first;
        if(first == "state") {
            ss >> state >> condition;
            if(condition == "accept") acceptStates.insert(state);
            else if(condition == "start") {
                if(ss >> condition) acceptStates.insert(state);
                startState = state;
            }
            else if(condition == "acceptstart") {
                acceptStates.insert(state);
                startState = state;
            }
        } else {
            Transition trans;
            ss >> trans.start >> trans.input >> trans.final;
            transitions.push_back(trans);
        }
    }
    while(getline(infile, line)) {
        stringstream ss(line);
        ss >> first;
        Transition trans;
        ss >> trans.start >> trans.input >> trans.final;
        transitions.push_back(trans);
    }
    infile.close();
    for(int i = 0; i < strInput.size(); i++) {
        input.push(strInput[i]);
    }
}

void Functions::process() {
    currentStates = {startState};
    while(!input.empty()) {
        char currInput = input.front();
        input.pop();
        unordered_set<int> nextStates;
        for(int i = 0; i < transitions.size(); i++) {
            if(currentStates.count(transitions[i].start) && transitions[i].input == currInput) {
                nextStates.insert(transitions[i].final);
            }
        }
        currentStates = move(nextStates);
    }
    for(int state : currentStates) { 
        if(acceptStates.count(state) && reject) {
            reject = false;
            endStates.clear();
            endStates.push_back(state);
        } else if(acceptStates.count(state) || reject) {
            endStates.push_back(state);
        }
    }
}

void Functions::print() {
    if(endStates.empty()) {
        cout << "∅" << endl;
        return;
    }
    reject ? cout << "reject " : cout << "accept ";
    sort(endStates.begin(), endStates.end());
    for(int i = 0; i < endStates.size(); i++) {
        cout << endStates[i] << " ";
    }
    cout << endl;
}