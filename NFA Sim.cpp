#include <iostream>
#include <stdio.h> 
#include "Functions.h"
using namespace std;

int main(int argc, char *argv[]) {
    Functions f;
    f.readInputs(argv[1], argv[2]);
    f.process();
    f.print();
}