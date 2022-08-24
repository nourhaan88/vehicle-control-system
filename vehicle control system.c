/*
 * project1.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Nourhan Ehab
 */

#include <stdio.h>


#define ON 1
#define OFF 0
int engine_state;
char x; //determine the system state
char y; //select option from menu
char z; //traffic light color
int w; //measured room temp
int speed;
int temperature,AC; //new set temperature
int engine_tmp_sensor,engine_cont,set_engine_temp;

void traffic_light(int light){
	if(light== 'G' || light== 'g'){
		speed=100;
	}
	else if(light == 'o' || light == 'O'){
		speed =30;
	}
	else if(light == 'r' || light== 'R'){
		speed =0;
	}
	else{
		printf("invalid data");
	}
}

void room_temp(int temp){
	if (temp <= 10 || temp>30){
		AC = ON;
		temperature=20;
	}
	else
		AC = OFF;
}

void engine_temp( int engn_temp){
	if(engn_temp < 100 || engn_temp >150){
		engine_cont = ON;
		set_engine_temp=125;
	}
	else
		engine_cont = OFF;

}
void turn_off(void){
	while ( (x != 'n') || (x!= 'N') ){
	printf("choose what to do\n o.turn off\nn.turn on\nq.quit\n");
	scanf(" %c",&x);

	}
	return;
}

int main(void){
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
printf("choose what to do\n o.turn off\nn.turn on\nq.quit\n");
scanf(" %c",&x);
switch(x){
case'q' :
case 'Q' :
	printf("quit the system");
	return 0;
	break;
case'o' :
case 'O' :
	engine_state = OFF;
	printf("turn off the system");
	turn_off();
	break;
case 'N' :
case 'n' :
	engine_state= ON;
printf("turn on the system");
break;
default :
 printf("invalid choice");

}
while (engine_state==ON){
printf("\n a.turn off the system\nb.set the traffic light color\n");
printf("c.set the room temperature\nd.set the engine temprture\ne.exit menu");
scanf(" %c",&y);
switch(y){
	case 'a' :
	case 'A' :
		turn_off();
		break;
	case 'b' :
	case 'B' :
		printf("please enter traffic light color");
		scanf(" %c",&z);
	traffic_light(z);

	break;
	case 'c' :
	case 'C' :
		printf("please enter traffic room temperature");
		scanf(" %d",&w);
		room_temp(w);

		break;
	case 'd' :
	case 'D' :
	printf("enter engine temperature");
	scanf(" %d", &engine_tmp_sensor);
	engine_temp( engine_tmp_sensor);

	break;


}
 if(y =='e'){
	 break;
 }
}
if (speed==30){
	AC = ON;
	temperature *=(5/4);
	temperature +=1;
	engine_cont = ON;
	set_engine_temp *=(5/4);
	set_engine_temp += 1;
}

printf("\n%d\n%d\n%d\n%d\n%d\n%d",engine_state,AC,speed,temperature,engine_cont,set_engine_temp);


return 0;
}
