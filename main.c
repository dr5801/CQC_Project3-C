#include <stdio.h>
#include <stdlib.h>

int StartState();
int IntegerState();
int DecimalState();
int EndState();

int (* state[])(void) = {StartState, IntegerState, DecimalState, EndState};
enum states {start, integer, decimal, end};
enum input {isSign, isDigit, isPoint, isTerminator, isInvalid};

struct transition{
	enum states thisState;
	enum states nextState;
	enum input action;
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

int main(int argc, char *argv[]) {
	return 0;
}

int StartState(){}
int IntegerState(){}
int DecimalState(){}
int EndState(){}