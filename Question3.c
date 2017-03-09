#include<stdio.h>

void main(){


//The machine does not have an change providing operation


char input,state;
char input_arr[3][10]={"0c","5c","10c"};
int input_val[3]= {0,5,10};
char state_arr[4][10]={"No coin","Sum is 5","Sum is 10","Vend"};
static int totat_sum=0;

input=input_arr[0];
state=state_arr[0];


switch(state){
	case state_arr[0]: printf("Current state is %s state\n",state_arr[0]);
				switch(input){
				case input_arr[0]: printf("You entered %s into the machine\n\t",input_arr[0]);
						   total_sum+= input_val[0];				
						   printf("Moving to the new state %s",state_arr[0]);
						   state=state_arr[0];
						   input=input_arr[rand()%4];
							break;	
				case input_arr[1]: printf("You entered %s into the machine\n\t",input_arr[1]);
						   total_sum+= input_val[1];				
						   printf("Moving to the new state %s",state_arr[1]);
							state=state_arr[1];
						   input=input_arr[rand()%4];
							break;
				case input_arr[2]: printf("You entered %s into the machine\n\t",input_arr[2]);
						   total_sum+= input_val[2];				
						   printf("Moving to the new state %s",state_arr[2]);
							state=state_arr[2];
						   input=input_arr[rand()%4];
							break;
					}
				break;
	case state_arr[1]:switch(input){
				case input_arr[0]: printf("You entered %s into the machine\n\t",input_arr[0]);
						   total_sum+= input_val[0];				
						   printf("Moving to the new state %s",state_arr[1]);
						   state=state_arr[1];
						   input=input_arr[rand()%4];
							break;	
				case input_arr[1]: printf("You entered %s into the machine\n\t",input_arr[1]);
						   total_sum+= input_val[1];				
						   printf("Moving to the new state %s",state_arr[2]);
							state=state_arr[2];
						   input=input_arr[rand()%4];
							break;
				case input_arr[2]: printf("You entered %s into the machine\n\t",input_arr[2]);
						   total_sum= input_val[0];
							printf("Here is your bottle of coke...\n\n\n\t");				
						   printf("Moving to the new state %s",state_arr[0]);
							state=state_arr[0];
						   input=input_arr[rand()%4];
							break;
					}
				break;
	case state_arr[2]:switch(input){
				case input_arr[0]: printf("You entered %s into the machine\n\t",input_arr[2]);
						   total_sum+= input_val[0];				
						   printf("Moving to the new state %s",state_arr[2]);
						   state=state_arr[2];
						   input=input_arr[rand()%4];
							break;	
				case input_arr[1]: printf("You entered %s into the machine\n\t",input_arr[1]);
						   total_sum= input_val[0];				
							printf("Here is your bottle of coke...\n\n\n\t");
						   printf("Moving to the new state %s",state_arr[0]);
							state=state_arr[0];
						   input=input_arr[rand()%4];
							break;
				case input_arr[2]: printf("You entered %s into the machine\n\t",input_arr[2]);
						   total_sum= input_val[1];
							printf("Here is your bottle of coke...\n\n\n\t");				
						   printf("Moving to the new state %s",state_arr[1]);
							state=state_arr[1];
						   input=input_arr[rand()%4];
							break;
				



					}
				break;	

}
























} 
