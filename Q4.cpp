#include <iostream>
#include <cstdlib>
using namespace std;

int runningtotal = 0;

int blackJack(int one, int two)  //start of overloaded function 
{
	runningtotal = runningtotal + one + two; // running total is the sum of the first two draws
	cout << "Total: "<< runningtotal <<endl;
	if (runningtotal < 21) //sets restriction: if less than 21, return the sum
	{
		return runningtotal;
	}
	if (runningtotal > 21)// if greater than 21, return -1
	{
		return -1;
	}
	if (runningtotal == 21) // if equal to 21, return 21
	{
		return 21;
	}
}

int blackJack(int one) //one integer val
{
	return blackJack(one, 0);
}

int blackJack(char one, int two) //one char value and one intger val
{
    if (one == 'A')
    {
    	return blackJack(11, two); 
    }
    else {
    	return blackJack(10, two);
    }
}

int blackJack(int one, char two) //one int val and one integer
{
	return blackJack(two, one); 
}

int blackJack(char one, char two) //one char val and one char value
{
	 if (one == 'A')
    {
    	return blackJack(11, two);
    }
    else {
    	return blackJack(10, two);
    }
}

int blackJack(char one) // one char value
{
	return blackJack(one, 0);
}

char convert(int a) //converts number values 11-13 to letters A, Q, K, J
{
	if (a == 1)
	{
		return 'A';
	}
	if (a == 11)

	{
		return 'J';
	}
	if (a == 12)
	{
		return 'Q';
	}
	if (a == 13)
	{
		return 'K';
	}
}
int main() 
{
	int draw;
	int drawtwo;
	int total;
	char choice;

	srand (time(NULL));

	cout << "Welcome to EC327 Black Jack!"<<endl;
	draw = rand() % 13 + 1; //random number, starting at 1
	drawtwo = rand() % 13 + 1; //random number, starting at 1
	
	if (draw > 1 && draw < 11)
	{
		if (drawtwo >1 && drawtwo < 11) 
		{
			total = blackJack(draw, drawtwo); //number, number
		}
		else{
			total = blackJack(draw, convert(drawtwo)); //number, letter
		}
	}
	else{
		if (drawtwo >1 && drawtwo < 11) 
		{
			total = blackJack(convert(draw), drawtwo); //letter, number
		}
		else{
			total = blackJack(convert(draw), convert(drawtwo)); //letter, letter
		}
	}
	

	CHECK:
	if (total < 21 && total > 0)
	{
		cout << "Draw again (y/n): "; //prompts user to draw again
		cin >> choice;

		if (choice == 'n')
		{
			cout << "YOU QUIT WITH " << total << endl; //if you pick "n", exits game
			return 0;
		}
		
		draw = rand() % 13 + 1;
		if (draw >1 && draw < 11) 
		{
			total = blackJack(draw);
		}
		else{
			total = blackJack(convert(draw));
		}

		goto CHECK;
	}

	if (total == -1)
	{
		cout << "FAILED BLACKJACK" << endl;
		return 0;
	}

	if (total == 21)
	{
		cout << "WON BLACKJACK" << endl;
		return 0;
	}
}
