#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int StartState();
int IntegerState();
int DecimalState();
int EndState();

int (* state[])(void) = {StartState, IntegerState, DecimalState, EndState};
enum states {start, integer, decimal, end};
enum input {isSign, isDigit, isPoint, isTerminator, isInvalid};

struct transition{
	enum states thisState;
	enum input action;
	enum states nextState;
};

static const struct transition change_state[] = {
	{start, isSign, integer},
	{start, isDigit, integer},
	{start, isPoint, decimal},
	{start, isTerminator, end},
	{start, isInvalid, end},
	{integer, isDigit, integer},
	{integer, isPoint, decimal},
	{integer, isTerminator, end},
	{integer, isInvalid, end},
	{decimal, isDigit, decimal},
	{decimal, isTerminator, end},
	{decimal, isInvalid, end}
};

int sign;
int value;
double point;
char character;

int main(int argc, char **argv) {
	enum states currentState = start;
	enum input entries;
	int (* stateFunction)(void);

	do{
		static int i = 0;
		character = *argv[++i];
		stateFunction = state[currentState];
		entries = stateFunction();
	}while(end != currentState);
	
	return 0;
}

int StartState(){

}
int IntegerState(){}
int DecimalState(){}
int EndState(){}