//Emerson Racca
//12/8/2021
//Final - Dice Rolling Tally

//Roll two 6 sided dice 50,000 times and keep track of the number of times each sum 2 - 12 occurs.
//
//1.  Build a regular c-type function that returns a random number between 2 - 12.  This will simulate a single roll of two dice.  
//Use the prototype:
//
//int rollDice(void);
//
//2. In the main, roll the dice 50,000 times and tally up the results in an array. 
//Let the index represent the number rolled and the value will represent the number of times that number has been rolled.  For example,
//
//a[2] = 1357
//a[3] = 2750
//...
//a[12] = 1481
//
//This array set-up will mean that the result 2 occurred 1,357 times and the outcome 3 was rolled 2,750 times.  
//These are just sample numbers, your results will vary.
//
//3. Use a for loop to print out the probability of each outcome 2 - 12.  
//That is,  use the formula  (number of times rolled) / (total number of rolls).  
//For example, with the example numbers in the array above,
//
//Probability of 2 = 1357/50000 = 0.027
//probability of 3 = 2750/50000 = 0.055
//... and so on.  Here are the true probabilities:  (Turn in one file, no user interaction, with separation.)


#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

int rollDice(void);

int main(void) {
	srand((unsigned int) time(0));
	int a[13];
	int result;

	cout << "Dice Rolling Tally" << endl;
	cout << "This app rolls two 6 sided dice 50,000 times and keeps track of the number of times each sum 2 - 12 occurs." << endl << endl;

	//initialize the array values
	for (int i = 0; i < 13; i++)
		a[i] = 0;

	for (int i = 0; i < 50000; i++) {
		result = rollDice();
		a[result] = a[result] + 1;
	}
		
	for (int i = 2; i < 13; i++)
		cout << left << "Probability of " << setw(2) << i << " = " << a[i] << "/50000 = " << setw(7) << 1.0 * a[i] / 50000 << " or " << 100.0 * a[i] / 50000 << "%" << endl;

	return 0;
}

int rollDice(void) {
	return ((1 + rand() % 6) + (1 + rand() % 6));
}