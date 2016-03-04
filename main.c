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

enum inputType GetInputType(char input);

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

int sign;
double value;
double point;
char character;
enum states currentState;

int main(int argc, char **argv) {
	currentState = start;
	enum inputType entries;
	int (* stateFunction)(void);
	char *input = argv[1];
	int lengthOfInput = strlen(input);
	int i;
	input[lengthOfInput] ='\0';
	for(i = 0;i<=lengthOfInput;i++){
		int strLen = strlen(*argv);	
		character = input[i];
		printf("Input char = %c  ", character,currentState);
		stateFunction = state[currentState];
		entries = stateFunction();
	}
	printf("The calculated value is: %f\n",value);
	return 0;
}


enum inputType GetInputType(char input){
	enum inputType result;
	if(isdigit(input)){
		result = isDigit;
	}else if(input == '+'){
		result = isPosSign;
	}else if(input == '-'){
		result = isNegSign;
	}else if(input == '.'){
		result = isPoint;
	}else if(input == '\0'){
		result = isTerminator;
	}else{
		result = isInvalid;
	}
	return result;
}
	
int StartState(){
	printf("In Start state with input of %c\n", character);
	enum inputType iType = GetInputType(character);
	if(iType == isDigit){
		sign = 1;
		value = character-'0';
		currentState = integer;
	}else if(iType == isPosSign){
		sign = 1;
		currentState = integer;
	}else if(iType == isNegSign){
		sign = -1;
		currentState = integer;
	}else if(iType == isPoint){
		point = .1;
		currentState = decimal;
	}else if(iType == isTerminator){
		value = 0;
		currentState = end;
	}else{
		printf("Invalid character: %c\n",character);
		value =0;
		currentState = end;
	}
}
int IntegerState(){
	printf("In integer state with input of %c\n", character);
	enum inputType iType = GetInputType(character);
	if(iType == isDigit){
		value = (value*10)+character-'0';
		currentState = integer;
	}else if(iType == isPosSign){
		printf("Invalid character: %c\n",character);
		value = 0;
		currentState = end;
	}else if(iType == isNegSign){
		printf("Invalid character: %c\n",character);
		value = 0;
		currentState = end;
	}else if(iType == isPoint){
		point = .1;
		currentState = decimal;
	}else if(iType == isTerminator){
		value = sign * value;
		currentState = end;
	}else{	
		printf("Invalid character: %c\n",character);
		value =0;
		currentState = end;
	}
}
int DecimalState(){
	printf("In decimal state with input of %c\n", character);
	enum inputType iType = GetInputType(character);
	if(iType == isDigit){
		value += point * (character-'0');
		point /= 10;
		currentState = decimal;
	}else if(iType == isPosSign){	
		printf("Invalid character: %c\n",character);
		value = 0;
		currentState = end;
	}else if(iType == isNegSign){
		printf("Invalid character: %c\n",character);
		value = 0;
		currentState = end;
	}else if(iType == isPoint){
		printf("Invalid character: %c\n",character);
		value = 0;
		currentState = end;
	}else if(iType == isTerminator){
		value = sign * value;
		currentState = end;
	}else{
		printf("Invalid character: %c\n",character);
		value =0;
		currentState = end;
	}
}

int EndState(){

}

