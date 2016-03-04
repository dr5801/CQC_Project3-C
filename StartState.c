#include "C_STATE.h"

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