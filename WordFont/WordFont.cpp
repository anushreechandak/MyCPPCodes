// Filename: WordFont.cpp
// Description: This file describes the implementation of all the member functions
//              used in Wordfont.h
// author: Anushree Chandak

// include header files
#include "WordFont.h"
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<iterator>
using namespace std;

WordFont::WordFont(void)// empty constructor
{
}
// method takes every needed input from user and loop us through the program
void WordFont::start()
{
	char name[8]; // variable to input the word given by user
	word.resize(15 ,vector<char>(200,0)); // intialize the vector used to store the word.
	
	cout<<"Enter a word (5 letters or less) using a, e, i, o, u, c ,f ,j , h, l, n, p , t, s, z: ";
	cin>>name;
	cout<<"\nEnter the character you want us to use to draw the word: ";
	cin>>character; // take special character used to represent the word
	cout<<"\nEnter Font size (8-12) : ";
	cin>>font;// take the font size
	cout<<"\nEnter 1 for Bold and 0 for non-Bold :";
	cin>>bold;// user decides bold or non-bold character
	NoOfColumns(font); // decide no of columns based on fonts
	rows=column;// intialize rows equal to columns
	position=0; // intialize the position of first letter
	mid(); // decide the midpoint
	newcolumn=column; // intialize the total no of columns used to print the word
	// iterate 6 times a loop to draw the each letter
	for(int i=0;i<5;i++)
	{
		if(name[i]=='\0')// break if its end of the string
		{
			break;
		}
		draw(name[i]); // call the draw method
	    space(); // add space between existing and next letter
		position=position+1; // increase ppostion counter
		newcolumn=(column+1)*position; // increase total no of columns counter
		
	}
	
	print(); // print the whole word
}
// method add 1 to each font size and use it as columns and rows 
int WordFont::NoOfColumns(int f)
{
	if (f==8)
	{
		column=9;
	}
	else if(f==9)
	{
		column=10;
	}
	else if(f==10)
	{
		column=11;
	}
	else if(f==11)
	{
		column=12;
	}
	else if (f==12)
	{
		column=13;
	}
	return column;
}
// method chooses the appropriate draw letter method for given letters
void WordFont::draw(char w)
{
	switch(w)
	{
		case'a':
		case'A':
			drawA(position); // draw A
			break;
        case'e':
		case'E':
			drawE(position);// draw E
			break;
        case'i':
		case'I':
			drawI(position);// draw I
			break;
        case'o':
		case'O':
			drawO(position);// draw O
			break;
        case'u':
		case'U':
			drawU(position);//draw U
			break;
        case'h':
		case'H':
			drawH(position);// draw H
			break;
        case't':
		case'T':
			drawT(position);// draw T
			break;
        case'c':
		case'C':
			drawC(position);// draw C
			break;
		case'n':
		case'N':
			drawN(position);//draw N
			break;
        case'f':
		case'F':
			drawF(position);// draw Z
			break;
		case'l':
		case'L':
			drawL(position);// draw L
			break;
		case'p':
		case'P':
			drawP(position);// draw P
			break;
		case'j':
		case'J':
			drawJ(position);// draw J
			break;
		case's':
		case'S':
			drawS(position);// draw S
			break;
		case'z':
		case'Z':
			drawZ(position);// draw Z
			break;
		default: 
			cout<<"You have entered an invalid character!!"<<endl;
			break;
	}
}
// method prints the whole word
void WordFont::print()
{
	for(int i=0;i<rows;i++) // rows are always equal to font size
	{
		for(int j=0;j<newcolumn;j++)// columns increase according to the word length
		{
			cout<<word[i][j];
		}
		cout<<endl;
	}
}

// choose midpoint based on font size
int WordFont::mid()
{
	if((font%2)==0)
		midpoint=(font/2)-1;
	else
		midpoint=(font/2);
	return midpoint;
}
// method creats space at the end of the letter
void WordFont::space()
{
	
	if(newcolumn<200)
	{
	for(int i=0;i<rows;i++)
		word[i][newcolumn-1]=' ';
	}
}
// draw letter A
void WordFont::drawA(int p)
{
	
	int str=0,stop=font;
	//if position is not equal to zero then intialize start and stop points for columns
	if(p!=0)
		{
			//p=p+1;
			str=newcolumn+1; // start from 1 column after the space
			stop=str+font; // end after the fontsize starting from the new column defined above
		}
		if(bold==0)// if non-bold is selected
       
		{
			for(int i=0;i<font;i++) // rows are equal to fontsize
			{
				for(int j=str;j<stop;j++) // columns depends on the postion of the letter
				{
					if((i==0 || i==midpoint)&& j<stop) // draw row at midpoint and at top
						word[i][j]=character;
					else if ((j==str || j==stop-1)&& i<font)// draw column at start and end
						word[i][j]=character;
					else
						word[i][j]=' ';
					
				}
			}
			
		}
		else if(bold==1)
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 ||i==1|| i==midpoint || i==(midpoint+1))&& j<stop)//draw 2 lines at top and middle
						word[i][j]=character;
					else if ((j==str || j==str+1 || j==(stop-2) || j==(stop-1))&&i<font) // draw 2 columns at start and end
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
}
void WordFont::drawE(int p)
{
		
	int str=0,stop=font;
	
	if(p!=0)
		{
			
			str=newcolumn+1;
			stop=str+font;
		}
	if(bold==0)
       
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 || i==midpoint|| i==font-1)&&j<stop)// draw row at top,middle,end
						word[i][j]=character;
					else if (j==str&& i<font)// column at start
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
			
		}
		else if(bold==1)
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 || i==1 || i==(midpoint) || i==(midpoint+1)||(i==(font-1))||(i==(font-2)))&&j<stop)
						word[i][j]=character;
					else if ((j==str || j==str+1)&&i<font)
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
}
void WordFont::drawI(int p)
{
		
	int str=0,stop=font;
	
	if(p!=0)
		{
			//p=p+1;
			str=newcolumn+1;
			stop=str+font;
		}
	if(bold==0)
       
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 ||i==font-1)&&j<stop)// row at top and bottom
						word[i][j]=character;
					else if (j==str+midpoint && i<font)// column at midpoint
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
		else if(bold==1)
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 || i==1 || i==font-1|| i==font-2)&&j<stop)
						word[i][j]=character;
					else if ((j==str+midpoint || j==str+midpoint+1)&&i<font)
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
}
void WordFont::drawO(int p)
{
		
	int str=0,stop=font;
	
	if(p!=0)
		{
			//p=p+1;
			str=newcolumn+1;
			stop=str+font;
		}
	if(bold==0)
       
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 || i==font-1)&&j<stop)// row at top and bottom
						word[i][j]=character;
					else if ((j==str || j==stop-1) && i<font)// column at start and end
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
		else if(bold==1)
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 || i==1 || i==font-1 || i==font-2)&&j<stop)
						word[i][j]=character;
					else if ((j==str || j==str+1 || j==stop-1 || j==stop-2)&&i<font)
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
}
void WordFont::drawU(int p)
{
		
	int str=0,stop=font;
	
	if(p!=0)
		{
			//p=p+1;
			str=newcolumn+1;
			stop=str+font;
		}
	if(bold==0)
       
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if( i==font-1 &&j<stop)// row at bottom
						word[i][j]=character;
					else if ((j==str || j==stop-1) && i<font)// column at start and end
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
		else if(bold==1)
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==font-1||i==font-2)&&j<stop)
						word[i][j]=character;
					else if ((j==str || j==str+1 || j==stop-1 || j==stop-2)&&i<font)
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
}
void WordFont::drawH(int p)
{
		
	int str=0,stop=font;
	
	if(p!=0)
		{
			//p=p+1;
			str=newcolumn+1;
			stop=str+font;
		}
	if(bold==0)
       
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if(i==midpoint &&j<stop)// row at midpoint
						word[i][j]=character;
					else if ((j==str || j==stop-1) && i<font)//column at start and end
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
		else if(bold==1)
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==midpoint || i==midpoint+1)&&j<stop)
						word[i][j]=character;
					else if ((j==str || j==str+1 || j==stop-1 || j==stop-2)&&i<font)
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
}
void WordFont::drawT(int p)
{
		
	int str=0,stop=font;
	
	if(p!=0)
		{
			//p=p+1;
			str=newcolumn+1;
			stop=str+font;
		}
	if(bold==0)
       
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if(i==0 &&j<stop)// row at top
						word[i][j]=character;
					else if (j==midpoint+str && i<font)//column at midpoint
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
		else if(bold==1)
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 || i==1)&&j<stop)
						word[i][j]=character;
					else if ((j==str+midpoint || j==str+midpoint+1)&&i<font)
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
}
void WordFont::drawC(int p)
{
		
	int str=0,stop=font;
	
	if(p!=0)
		{
			//p=p+1;
			str=newcolumn+1;
			stop=str+font;
		}
	if(bold==0)
       
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 || i==font-1)&&j<stop)//row at top and bottom
						word[i][j]=character;
					else if (j==str && i<font)//column at start
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
		else if(bold==1)
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 || i==1 || i==font-1||i==font-2)&&j<stop)
						word[i][j]=character;
					else if ((j==str || j==str+1)&&i<font)
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
}
void WordFont::drawN(int p)
{
		
	int str=0,stop=font;
	
	if(p!=0)
		{
			//p=p+1;
			str=newcolumn+1;
			stop=str+font;
		}
	if(bold==0)
       
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if(i==j-str &&j<stop)//draw the diagonal line
						word[i][j]=character;
					else if ((j==str || j==stop-1) && i<font)//column at start and end
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
		else if(bold==1)
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==j-str || i==j-str-1) && j<stop)
						word[i][j]=character;
					else if ((j==str || j==str+1 || j==stop-1 || j==stop-2)&&i<font)
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
}
void WordFont::drawF(int p)
{
		
	int str=0,stop=font;
	
	if(p!=0)
		{
			//p=p+1;
			str=newcolumn+1;
			stop=str+font;
		}
	if(bold==0)
       
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 || i==midpoint)&&j<stop)//row at midpoint and top
						word[i][j]=character;
					else if (j==str && i<font)//column at start
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
		else if(bold==1)
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 || i==1 || i==midpoint || i==midpoint+1)&&j<stop)
						word[i][j]=character;
					else if ((j==str || j==str+1)&&i<font)
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
}
void WordFont::drawL(int p)
{
		
	int str=0,stop=font;
	
	if(p!=0)
		{
			//p=p+1;
			str=newcolumn+1;
			stop=str+font;
		}
	if(bold==0)
       
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if(i==font-1 && j<stop)//row at bottom
						word[i][j]=character;
					else if (j==str && i<font)//columnat start
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
		else if(bold==1)
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==font-1||i==font-2)&&j<stop)
						word[i][j]=character;
					else if ((j==str || j==str+1)&&i<font)
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
}
void WordFont::drawP(int p)
{
		
	int str=0,stop=font;
	
	if(p!=0)
		{
			//p=p+1;
			str=newcolumn+1;
			stop=str+font;
		}
	if(bold==0)
       
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 || i==midpoint) && j<stop)// row at top and midpoint
						word[i][j]=character;
					else if ((j==str || j==stop-1) && i<font)//column at start and end
						word[i][j]=character;
					else
						word[i][j]=' ';
					if(j>str && i>midpoint) // overwrite last half of the column with space
						word[i][j]=' ';
				}
			}
		}
		else if(bold==1)
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0||i==1 || i== midpoint || i==midpoint+1)&&j<stop)
						word[i][j]=character;
					else if ((j==str || j==str+1 || j==stop-1 || j==stop-2)&&i<font)
						word[i][j]=character;
					else
						word[i][j]=' ';
					if(j>str+1 && i>midpoint+1)
						word[i][j]=' ';
				}
			}
		}
}

void WordFont::drawJ(int p)
{
		
	int str=0,stop=font;
	
	if(p!=0)
		{
			//p=p+1;
			str=newcolumn+1;
			stop=str+font;
		}
	if(bold==0)
       
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 || i==font-1)  && j<stop)// row at top and bottom
						word[i][j]=character;
					
					else if (j==str+midpoint && i<font)//column at midpoint
						word[i][j]=character;
					else
						word[i][j]=' ';
					if(j>str+midpoint && i>midpoint)// overwrite last half of row with spaces
						word[i][j]=' ';
				}
			}
		}
		else if(bold==1)
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 || i==1 || i==font-1 || i==font-2)&&j<stop)
						word[i][j]=character;
					else if ((j==str+midpoint || j==str+midpoint+1)&&i<font)
						word[i][j]=character;
					else
						word[i][j]=' ';
					if(j>str+midpoint+1 && i>midpoint)
						word[i][j]=' ';
				}
			}
		}
}
void WordFont::drawS(int p)
{
		
	int str=0,stop=font;
	
	if(p!=0)
		{
			//p=p+1;
			str=newcolumn+1;
			stop=str+font;
		}
	if(bold==0)
       
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 || i==(midpoint)|| i==(font-1))&&j<stop)//row at top ,middle and bottom
						word[i][j]=character;
					else if ((j==str || j==stop-1) && i<font)//column at start and end
						word[i][j]=character;
					else
						word[i][j]=' ';
					if(i>midpoint&& i<=font-2 && j<str+midpoint )// overwrite bottom half of column at start with space
						word[i][j]=' ';
					if(i<midpoint&& i>=1 && j>str+midpoint )//overwrite top half of last column with space
						word[i][j]=' ';
				}
			}
		}
		else if(bold==1)
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 || i==1 || i==(midpoint) || i==(midpoint+1)||(i==(font-1))||(i==(font-2)))&&j<stop)
						word[i][j]=character;
					else if (((j==str || j==str+1 && j<=str+midpoint)||(j>=str+midpoint&& j==stop-1 || j==stop-2))&&i<font)
						word[i][j]=character;
					else
						word[i][j]=' ';
					if(i>midpoint+1 && i<font-2 && j<str+midpoint )
						word[i][j]=' ';
					if(i<midpoint&& i>1 && j>str+midpoint )
						word[i][j]=' ';
				}
			}
		}
}
void WordFont::drawZ(int p)
{
		
	int str=0,stop=font;
	
	if(p!=0)
		{
			//p=p+1;
			str=newcolumn+1;
			stop=str+font;
		}
	if(bold==0)
       
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0||i==font-1) &&j<stop)// row at top and bottom
						word[i][j]=character;
					else if (i<stop-1 && i==(stop-j-1) && j<stop)// diagonal line starting at the end
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
		else if(bold==1)
		{
			for(int i=0;i<font;i++)
			{
				for(int j=str;j<stop;j++)
				{
					if((i==0 || i==1 || i==font-1 || i==font-2)&&j<stop)
						word[i][j]=character;
					else if (i<stop-1 && i==(stop-j-1)|| i==(stop-j-2) && j<stop)
						word[i][j]=character;
					else
						word[i][j]=' ';
				}
			}
		}
}
