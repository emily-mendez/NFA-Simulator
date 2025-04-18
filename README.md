# NFA Simulator

Simulates the execution of a partial non deterministic finite automata (partial since there are
no epsilon transitions). 
Program reads the definition of the machine from a file (the first command line argument), with
the second command line argument being the string to simulate the machine running on (the input to the
automata). The output of the program is standard output. The output consists of
either: 1) the word "accept" followed by a blank space followed by the list of accept states (blank space
delimited) that the automata can end up in after reading in the input string (if there is a way for the
automata to end in an accept state after reading the input); or 2) the word "reject" followed by a blank
space followed by the list of states (blank space delimited) that the automata can end up in after reading
the string (if there is no way for the automata to end in an accept state after reading the input). 
