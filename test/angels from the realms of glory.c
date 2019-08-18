#include "soundlib.h"


short octave = 0;

double (*test)(double)= oldEsoteric;


void song(int end){
	tempo=100;
	//MEASURE #1
	fourChord(test,C/2,C,E,G,octave,0.25,90);
	fourChord(test,C/2,G/2,C,E,octave,0.25,90);
	cat();
	//MEASURE #2
	fourChord(test,E/2,G/2,G,2*C,octave,0.25,90);
	fourChord(test,C/2,C,E,G,octave,0.25,90);
	cat();
	fourChord(test,G/2,C,G,2*E,octave,0.375,90);
	cat();
	fourChord(test,F/2,B/2,G,2*D,octave,0.125,90);
	cat();
	cat();
	//MEASURE #3
	fourChord(test,E/2,C,G,2*C,octave,0.25,90);
	fourChord(test,E/2,C,G,G,octave,0.25,90);
	cat();
	fourChord(test,F/2,A/2,C,A,octave,0.25,90);
	cat();
	fourChord(test,F/2,C,C,A,octave,0.25,90);
	cat();
	cat();
	//MEASURE #4
	fourChord(test,E/2,G/2,C,G,octave,0.25,90);
	fourChord(test,A/4,A/2,C,2*C,octave,0.25,90);
	cat();
	fourChord(test,B/4,G/2,D,G,octave,0.25,90);
	cat();
	fourChord(test,G/4,G/2,B/2,F,octave,0.25,90);
	cat();
	cat();
	//MEASURE #5
	fourChord(test,C/2,G/2,C,E,octave,0.5,90);
	fourChord(test,C,C,E,G,octave,0.25,90);
	cat();
	fourChord(test,G/2,C,C,E,octave,0.25,90);
	cat();
	cat();
	//MEASURE #6
	fourChord(test,E/2,G/2,G,2*C,octave,0.25,90);
	interval(test,G/2,G,octave,0.25,90);
	two(test,G,F,octave,0.25,90);
	two(test,E,Db,octave-1,0.25,90);
	add();
	add();
	cat();
	cat();
	fourChord(test,C/2,C,E,2*E,octave,0.375,90);
	fourChord(test,D/2,B/2,F,2*D,octave,0.125,90);
	cat();
	cat();
	//MEASURE #7
	fourChord(test,E/2,A/2,E,2*C,octave,0.25,90);
	fourChord(test,E/2,Gs/2,E,B,octave,0.25,90);
	cat();
	fourChord(test,A/2,A/2,E,2*C,octave,0.25,90);
	cat();
	fourChord(test,E/2,Gs/2,E,B,octave,0.25,90);
	cat();
	cat();
	//MEASURE # 8
	fourChord(test,C/2,E,E,A,octave,0.25,90);
	interval(test,A/4,E,octave,0.25,90);
	two(test,B,2*C,octave,0.25,90);
	two(test,D,C,octave,0.25,90);
	add();
	add();
	cat();
	fourChord(test,D/2,D,G,B,octave,0.25,90);
	cat();
	fourChord(test,D/2,C,Fs,A,octave,0.25,90);
	cat();
	cat();
	//MEASURE # 9
	fourChord(test,G/4,B/2,G,G,octave,0.25,90);
	fourChord(test,G/2,B/2,G,2*D,octave,0.375,90);
	fourChord(test,G/2,B/2,G,2*D,octave,0.125,90);
	cat();
	cat();
	cat();
	//MEASURE #10
	fourChord(test,G/2,D,G,B,octave,0.25,90);
	fourChord(test,G/2,B/2,G,2*D,octave,0.25,90);
	fourChord(test,C/2,C,G,2*E,octave,0.375,90);
	fourChord(test,C/2,Bf,E,2*D,octave,0.125,90);
	cat();
	cat();
	cat();
	cat();
	//MEASURE #11
	fourChord(test,F/2,A/2,F,2*C,octave,0.25,90);
	fourChord(test,F/2,C,F,A,octave,0.25,90);
	fourChord(test,Db/2,Db,A,2*F,octave,0.25,90);
	fourChord(test,E/2,G/2,G,2*E,octave,0.25,90);
	cat();
	cat();
	cat();
	cat();
	//MEASURE #12
	four(test,Db,C,C,B/2,octave-1,1.0,90);
	create(test,F,octave,0.25,90);
	appendTwo(test,E,F,octave,0.25,90);
	append(test,G,octave,0.375,90);
	append(test,F,octave,0.125,90);
	add();
	two(test,A,B,octave-1,0.25,90);
	appendThree(test,C,D,D,octave,0.75,90);
	add();
	two(test,F,G,octave-1,0.25,90);
	appendThree(test,A,G,G/2,octave-1,0.75,90);
	add();
	cat();
	//MEASURE #13
	if(end){
		fourChord(test,C/2,C,E,2*C,octave,2.0,90);
		gradual(1,0);
		cat();
	}
	else{
		fourChord(test,C/2,C,E,2*C,octave,0.5,90);
		cat();
	}
}

int main(int argc, char **argv){
	song(0);
	song(1);
	cat();
	echo(20,0.30,5);
	exportToWav("angels from the realms of glory.wav");
	system("totem \"angels from the realms of glory.wav\"");
}
