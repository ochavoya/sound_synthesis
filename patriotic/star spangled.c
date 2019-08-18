#include "soundlib.h"
#define DEBUG 1

#define VOICEAZ 75
#define CHORDAZ 135
#define BASSAZ 90

double (*voice)(double) = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double) = trumpet;//oldCircleOfRa;

short octave = 0;

double fKey;

void intro(void){
	FORTE;
	//MEASURE # 1
	#ifdef DEBUG
	puts("Measure # 1");
	#endif
		//HARMONY
		create(harmony,B/2,octave,0.125*3/2,CHORDAZ);
		append(harmony,B/2,octave,0.125/2,CHORDAZ);
		append(harmony,E,octave,0.25,CHORDAZ);
		appendSilence(0.125);
		append(harmony,B/2,octave,0.125/2,CHORDAZ);
		append(harmony,B/2,octave,0.125/2,CHORDAZ);
		append(harmony,E,octave,0.125,CHORDAZ);
		append(harmony,B,octave,0.125,CHORDAZ);
	//MEASURE # 2 3 4
	#ifdef DEBUG
	puts("Measure # 2 3 4");
	#endif
		//HARMONY
		silence(0.25);
		append(harmony,G,octave,2.75,CHORDAZ);
                silence(1.25);
		append(harmony,F,octave,1.75,CHORDAZ);
		add();

		//HARMONY
		interval(harmony,A/2,A,octave,0.125*3/2,CHORDAZ);
		appendInterval(harmony,A,G,octave,0.125/2,CHORDAZ);
		append(harmony,D,octave,0.25,CHORDAZ);
		appendSilence(0.125);
		appendTwo(harmony,A/2,A/2,octave,0.125,CHORDAZ);
		appendTwo(harmony,D,G,octave,0.25,CHORDAZ);

		appendInterval(harmony,G/2,G,octave,0.125*3/2,CHORDAZ);
		appendInterval(harmony,G/2,F,octave,0.125/2,CHORDAZ);
		append(harmony,C,octave,0.25,CHORDAZ);
		appendSilence(0.125);
		appendTwo(harmony,G/2,G/2,octave,0.125,CHORDAZ);
		appendTwo(harmony,C,F,octave,0.25,CHORDAZ);

		append(harmony,F,octave,0.125*3/2,CHORDAZ);
		append(harmony,Ef,octave,0.125/2,CHORDAZ);
		append(harmony,Ef,octave,0.75,CHORDAZ);

		//BASS
		silence(2);
		appendInterval(bass,F,2*F,octave-3,0.125*3/2,BASSAZ);
		appendInterval(bass,F,2*F,octave-3,0.125/2,BASSAZ);
		appendInterval(bass,Bf,2*Bf,octave-3,0.25,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,F,2*F,octave-3,0.125/2,BASSAZ);
		appendInterval(bass,F,2*F,octave-3,0.125/2,BASSAZ);
		appendInterval(bass,Bf,2*Bf,octave-3,0.125,BASSAZ);
		appendInterval(bass,Ef,2*Ef,octave-2,0.125,BASSAZ);
	add();
	add();
	cat();
        C = fKey;  // MODULATION 
	//MEASURE # 5
	#ifdef DEBUG
	puts("Measure # 5");
	#endif
		pedal();
		//HARMONY
		chord(harmony,G,B,2*D,octave,0.125,CHORDAZ);
		appendChord(harmony,Bf,D,F,octave,0.125,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.125,CHORDAZ);
		appendChord(harmony,E,A,2*C,octave,0.125,CHORDAZ);

		appendChord(harmony,G,B,2*D,octave,0.125/2,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.125/2,CHORDAZ);
		appendChord(harmony,Bf,D,F,octave,0.125/2,CHORDAZ);
		appendChord(harmony,Bf,D,F,octave,0.125/2,CHORDAZ);

		appendChord(harmony,Bf,D,F,octave,0.125,CHORDAZ);
		appendChord(harmony,E,A,2*C,octave,0.125,CHORDAZ);

		//BASS
		interval(bass,A,2*A,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-2,0.125,BASSAZ);
		appendInterval(bass,A,2*A,octave-2,0.125,BASSAZ);
		appendInterval(bass,Bf,2*Bf,octave-2,0.125,BASSAZ);

		appendInterval(bass,A,2*A,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-2,0.125,BASSAZ);
		appendInterval(bass,A,2*A,octave-2,0.125,BASSAZ);
		appendInterval(bass,Bf,2*Bf,octave-2,0.125,BASSAZ);

	add();
	cat();

	//MEASURE # 6
	#ifdef DEBUG
	puts("Measure # 6");
	#endif
		//HARMONY
		chord(harmony,C,E,G,octave+1,0.125*3/2,CHORDAZ);
		appendChord(harmony,C,E,G,octave+1,0.125/2,CHORDAZ);
		appendChord(harmony,Af/2,C,Ef,octave+1,0.5,CHORDAZ);
		appendChord(harmony,Bf,D,F,octave+1,0.25,CHORDAZ);
		//BASS
		interval(bass,F,2*F,octave-2,0.125*3/2,BASSAZ);
		appendInterval(bass,F,2*F,octave-2,0.125/2,BASSAZ);

		appendInterval(bass,Bf,2*Bf,octave-1,0.25,BASSAZ);

		appendIntervalMarcato(bass,Bf,2*Bf,octave-1,0.125/2,BASSAZ);
		appendIntervalMarcato(bass,Bf,2*Bf,octave-1,0.125/2,BASSAZ);
		appendIntervalMarcato(bass,Bf,2*Bf,octave-1,0.125/2,BASSAZ);
		appendIntervalMarcato(bass,Bf,2*Bf,octave-1,0.125/2,BASSAZ);

		appendIntervalMarcato(bass,C,2*C,octave-1,0.25,BASSAZ);
	add();
	cat();



	//MEASURE # 7
	#ifdef DEBUG
	puts("Measure # 7");
	#endif
		//HARMONY
		chord(harmony,C,E,G,octave+1,0.125,CHORDAZ);
		appendChord(harmony,Af/2,C,Ef,octave+1,0.25,CHORDAZ);
		appendChord(harmony,Bf,D,F,octave+1,0.125,CHORDAZ);

		appendChord(harmony,G/2,C,E,octave+1,0.5/3,CHORDAZ);
		appendChord(harmony,C,Ef,Af,octave+1,0.5/3,CHORDAZ);
		appendChord(harmony,D,F,Bf,octave+1,0.5/3,CHORDAZ);

		//BASS
		interval(bass,F,2*F,octave-1,0.125,BASSAZ);
		appendInterval(bass,Bf,2*Bf,octave-1,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-1,0.125/2,BASSAZ);

		appendInterval(bass,F,2*F,octave,0.5/3,BASSAZ);
		appendInterval(bass,Ef,2*Ef,octave,0.5/3,BASSAZ);
		appendInterval(bass,D,2*D,octave,0.5/3,BASSAZ);

	add();
	cat();
/*
	//MEASURE # 8
	#ifdef DEBUG
	puts("Measure # 8");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 9
	#ifdef DEBUG
	puts("Measure # 9");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	*/
}



void song(void){
	intro();

}


int main(int argc, char** argv){
	fKey = F/2;
	tempo=88;
	song();
	echo(10,0.3,4);
	puts("star spangled.wav");
	exportToWav("star spangled.wav");

}


