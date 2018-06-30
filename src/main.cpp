#include <stdio.h>
#include <iostream>
#include "cmdline.h"
#include "common.h"

using namespace std;

int main(int argc, char* argv[]){

    // if no argument is given, show the usage
    if(argc == 1) {
        cerr << "A cmdline tool demo that repeats the word you input. Usage: demo <--word> <--repeat>" << endl << "version " << VERSION_NUM << endl;
    }

    // setup how to parse the command line arguments
    cmdline::parser cmd;
    cmd.add<string>("word", 'w', "a word to repeat", true, "");
    cmd.add<int>("repeat", 'r', "how many times to repeat", true, 1);
    cmd.parse_check(argc, argv);

    // the the argument values
    string word = cmd.get<string>("word");
    int repeat = cmd.get<int>("repeat");

    // handle the exception of arguments
    if(repeat < 1) {
        // use cerr to make the error message to be output to STDERR
        cerr << "the repeat times (--repeat) cannot be less than 1" << endl;
        exit(-1);
    }
    if(repeat > 100) {
        cerr << "the repeat times (--repeat) cannot be greater than 100" << endl;
        exit(-1);
    }

    // implement it
    for(int i=0; i<repeat; i++) {
        // here we use cout to make it output it to STDOUT
        cout << word << endl;
    }

    return 0;
}