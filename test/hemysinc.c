#include "soundlib.h"


short octave = 0;

double (*test)(double)= oldEsoteric;


void song(int end){
	tempo=60;
	create(test,60,octave,15,0);
	create(test,7.5,octave,15,180);
	add();
}

int main(int argc, char **argv){
	song();
	exportToWav("hemysync tone.wav");
}
