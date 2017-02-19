// Filename: WordFont.h
// Description: This file defines all the member functions
//              and data members used in the class Wordfont
// author: Anushree Chandak

// include header files
#include<vector>
#include<string>
using namespace std;
class WordFont
{
public:
	WordFont(void); // empty constructor
	void start(); // method which will take all the input from user,
	             //  and will loop through the 
	
private:
	void print(); // prints the word
	int NoOfColumns(int);// decides no of columns based on fontsize
	int mid();// decides midpoint based on fontsize
	void space();// creats space at he end of the letter
	void draw(char);// calls the appropriate letter method to draw
	// 15 letter methods
	void drawA(int); // A
	void drawE(int); // E
	void drawI(int); // I
	void drawO(int); // O
	void drawU(int); // U
	void drawH(int); // H
	void drawT(int); // T
	void drawC(int); // C
	void drawN(int); // N
	void drawF(int); // F
	void drawL(int); // L
	void drawJ(int); // J
	void drawP(int); // P
	void drawS(int); // S
	void drawZ(int); // Z
	// private variables used int the program
	vector<vector<char>>word; // 2-D vector used to draw the word
	char character; 
	int newcolumn; // total no of columns 
	int column; // column for a 1 letter
	int rows;  // rows for the word 
	int position; // position of the letter in the word
	int bold; // bold or non-bold
	int font; // fontsize
	int midpoint; // midpoint of the letter
};
