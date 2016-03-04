/**
 * Drew Rife and Brad Olah
 *
 * Holds transition table for the state machine
 */
#ifndef C_STATE_H
#define C_STATE_H

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
enum inputType {isNegSign,isPosSign, isDigit, isPoint, isTerminator, isInvalid};

struct transition{
	enum states thisState;
	enum inputType action;
	enum states nextState;
};

enum inputType GetInputType(char input); // what the user enters

/**
 * transition table
 */
static const struct transition change_state[] = {
	{start, isPosSign, integer},
	{start, isNegSign, integer},
	{start, isDigit, integer},
	{start, isPoint, decimal},
	{start, isTerminator, end},
	{start, isInvalid, end},
	{integer, isPosSign, end},
	{integer, isNegSign, end},
	{integer, isDigit, integer},
	{integer, isPoint, decimal},
	{integer, isTerminator, end},
	{integer, isInvalid, end},
	{decimal, isPosSign, end},
	{decimal, isNegSign, end},
	{decimal, isDigit, decimal},
	{decimal, isPoint, end},
	{decimal, isTerminator, end},
	{decimal, isInvalid, end}
};

int sign;  // the sign of the input
double value;  // the calculated result from input
double point;  // determines whether there is a decimal or not
char character;  // the input character
enum states currentState;  // the current state of the machine is in

#endif // C_STATE_H