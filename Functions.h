#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Transition {
    int start;
    char input;
    int final;
};

class Functions {
    public:
        void readInputs(string fileName, string strInput);
        void process();
        void print();
    private:
        unordered_set<int> acceptStates;
        vector<Transition> transitions;
        int startState;
        queue<char> input;
        vector<int> endStates;
        bool reject = true;
        unordered_set<int> currentStates;
};

#endif 