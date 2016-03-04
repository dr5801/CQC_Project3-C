/**
 * Drew Rife and Brad Olah
 *
 * A state machine in C
 */
#include "C_STATE.h"

int main(int argc, char **argv) {
	currentState = start;
	enum inputType entries;
	int (* stateFunction)(void);
	char *input = argv[1];
	int lengthOfInput = strlen(input);
	int i;
	input[lengthOfInput]='\0';
	
	for(i = 0;i<=lengthOfInput;i++){	
		character = input[i];
		printf("Input char = %c \n", character);
		stateFunction = state[currentState];
		entries = stateFunction();
	}
	printf("\nThe calculated value is: %.2f\n",value);
	return 0;
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

int EndState(){}