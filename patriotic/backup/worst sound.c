#include "soundlib.h"
#define DEBUG 1

#define VOICEAZ 75
#define CHORDAZ 135
#define BASSAZ 90

double (*voice)(double) = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double) = oldCircleOfRa;

short octave = -1;





int main(int argc, char** argv){


  interval(oldEsoteric,Fs,Gf,octave,5,0.5);


	echo(10,0.30,4);
	puts("worst sound.wav");
	exportToWav("worst sound.wav");

}


