#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

ifstream infp;

// Tokens names
enum Tokens {
    A_TOKEN, B_TOKEN, C_TOKEN, END_OF_INPUT, UNKNOWN
};

Tokens nextToken;
string lexeme;
char nextChar;
int errors = 0;  // counter for error messages
int line = 1;    // variable to keep track of the line number from the source code

// Function to display the token as a string
void prt(Tokens nt) {
    switch (nt) {
        case A_TOKEN: cout << "<A>"; break;
        case B_TOKEN: cout << "<B>"; break;
        case C_TOKEN: cout << "<C>"; break;
        case END_OF_INPUT: cout << "<END>"; break;
        case UNKNOWN: cout << "<UNKNOWN>"; break;
        default: cout << "<Unspecified token>"; break;
    }
}

// Error message display
void errMsg(string msg) {
    cout << "Error at line: " << line << ": " << msg << endl;
    errors++;
}

// Function to add nextChar to lexeme
void addChar(char nextChar) {
    lexeme += nextChar;
}

// Function to get next character
char getChar() {
    return infp.get();
}

// Function to get non-space character
char getNonSpaceChar() {
    char ch = ' ';
    while (isspace(ch)) {
        ch = getChar();
    }
    return ch;
}

// Tokenizer function
Tokens tokenizer() {
    lexeme = "";
    
    nextChar = getNonSpaceChar(); // Get the next non-space character

    if (nextChar == 'a') {
        addChar(nextChar);
        nextToken = A_TOKEN;
    }
    else if (nextChar == 'b') {
        addChar(nextChar);
        nextToken = B_TOKEN;
    }
    else if (nextChar == 'c') {
        addChar(nextChar);
        nextToken = C_TOKEN;
    }
    else if (nextChar == EOF) {
        nextToken = END_OF_INPUT;
        lexeme = "EOF";
    }
    else {
        nextToken = UNKNOWN; // Any other character is unknown
    }
    
    cout << "Token read:\t"; prt(nextToken);
    cout << " Lexeme: " << lexeme << endl;

    return nextToken;
}

// Main driver
int main() {
    infp.open("prg.in"); // Ensure the file exists in the same directory
    if (!infp) {
        cout << "ERROR OPENING FILE" << endl;
        errors++;
    } else {
        do {
            nextToken = tokenizer();
        } while (nextToken != END_OF_INPUT);
    }
    cout << "Total number of errors: " << errors << endl;
    return 0;
}
