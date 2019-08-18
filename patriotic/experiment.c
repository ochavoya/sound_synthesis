#include "soundlib.h"
#define DEBUG 1

#define LEFT_CHANNEL  0
#define RIGHT_CHANNEL 180
#define FRONT_CHANNEL 90

double (*voice)(double)   = oldEsoteric;


short octave = 0;


void doExperiment(){
    MESSOFORTE;
		create(oldEsoteric,C,octave,1.0,LEFT_CHANNEL );
        create(oldEsoteric,G,octave,1.0,RIGHT_CHANNEL);
	cat();
        appendSilence(1.0);
		create(oldEsoteric,C,octave,1.0,LEFT_CHANNEL );
        create(oldEsoteric,G,octave,1.0,RIGHT_CHANNEL);
	    add();
    cat();
        appendSilence(1.0);
		create(oldEsoteric,C,octave,1.0,FRONT_CHANNEL);
        create(oldEsoteric,G,octave,1.0,FRONT_CHANNEL);
	    add();
    cat();
}


int main(int argc, char** argv){

	doExperiment();
//	echo(10,0.3,4);
	puts("Writing wav file: experiment.wav");
	exportToWav("experiment.wav");

}


