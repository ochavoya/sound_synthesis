#include "soundlib.h"
#define DEBUG 1

#define CHORDAZ 90
#define BASSAZ 90

double (*harmony)(double) = circleOfRa;
double (*bass)(double) = circleOfRa;

double fKey;
double aFlatKey;
double dFlatKey;
short octave = -1;


void song(void){
	C=fKey;
	PP;
	pedal();
	//MEASURE # 1
	#ifdef DEBUG
	puts("Measure # 1");
	#endif
		//HARMONY
		arpegioFour(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendArpegioFour(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendArpegioFour(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		//BASS
		arpegioFour(bass,C,G,2*E,4*F,octave-2,0.375,BASSAZ);
	add();
	//MEASURE # 2
	#ifdef DEBUG
	puts("Measure # 2");
	#endif
		//HARMONY
		arpegioFour(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		//BASS
		six(bass,0,B,A,G,A,B,octave-1,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 3 & 4
	#ifdef DEBUG
	puts("Measure # 3 & 4");
	#endif
		//HARMONY
		fourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		//BASS
		three(bass,A,B,A,octave-1,0.125,BASSAZ);
		append(bass,G,octave-1,0.625,BASSAZ);
		create(bass,C,octave-1,0.375,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 5
	#ifdef DEBUG
	puts("Measure # 5");
	#endif
		//HARMONY
		fourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		//BASS
		arpegioFour(bass,C,G,2*E,4*C,octave-2,0.375,BASSAZ);
	add();
	cat();
	releasePedal();		
	//MEASURE # 6
	#ifdef DEBUG
	puts("Measure # 6");
	#endif
		//HARMONY
		fourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		//BASS
		six(bass,0,B,A,G,A,B,octave-1,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 7 & 8
	#ifdef DEBUG
	puts("Measure # 7 & 8");
	#endif
		//HARMONY
		//HARMONY
		fourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		//BASS
		three(bass,A,B,A,octave-1,0.125,BASSAZ);
		append(bass,G,octave-1,0.625,BASSAZ);
		create(bass,C,octave-1,0.375,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 9
	#ifdef DEBUG
	puts("Measure # 9");
	#endif
		//HARMONY
		fourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		//BASS
		two(bass,D,E,octave-1,0.125,BASSAZ);
		append(bass,F,octave-1,0.125,BASSAZ);
		appendTwo(bass,F,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 10
	#ifdef DEBUG
	puts("Measure # 10");
	#endif
		//HARMONY
		fourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		//BASS
		create(bass,A,octave-1,0.1875,BASSAZ);
		appendThree(bass,B/2,D,B/2,octave,0.1875,BASSAZ);
	add();
	cat();
	//MEASURE # 11 & 12
	#ifdef DEBUG
	puts("Measure # 11 & 12");
	#endif
		//HARMONY
		fourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		pedal();
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		releasePedal();
		//BASS
		three(bass,A,B,A,octave-1,0.125,BASSAZ);
		append(bass,G,octave-1,0.25+0.375,BASSAZ);
	add();
	cat();

	//MEASURE # 13
	#ifdef DEBUG
	puts("Measure # 13");
	#endif
		//HARMONY
		fourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		//BASS
		two(bass,D,E,octave-1,0.125,BASSAZ);
		append(bass,F,octave-1,0.125,BASSAZ);
		appendTwo(bass,F,G,octave-1,0.125,BASSAZ);
		interval(bass,C,G,octave-2,0.125,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 14
	#ifdef DEBUG
	puts("Measure # 14");
	#endif
		//HARMONY
		fourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		//BASS
		create(bass,A,octave-1,0.125,BASSAZ);
		appendTwo(bass,B,2*E,octave-1,0.125,BASSAZ);
		appendTwo(bass,2*D,B,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 15 & 16
	#ifdef DEBUG
	puts("Measure # 15 & 16");
	#endif
		//HARMONY
		fourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		pedal();
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		releasePedal();
		//BASS
		three(bass,A,B,A,octave-1,0.125,BASSAZ);
		append(bass,G,octave-1,0.625,BASSAZ);
	add();
	cat();
	PIANO;
	pedal();
	//MEASURE # 17
	#ifdef DEBUG
	puts("Measure # 17");
	#endif
		//HARMONY
		fourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		//BASS
		arpegioFour(bass,C,G,2*E,4*F,octave-2,0.375,BASSAZ);
	add();
	cat();

	//MEASURE # 18
	#ifdef DEBUG
	puts("Measure # 18");
	#endif
		//HARMONY
		fourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		//BASS
		six(bass,0,B,A,G,A,B,octave-1,0.375,BASSAZ);
	add();
	cat();

	//MEASURE # 19 & 20
	#ifdef DEBUG
	puts("Measure # 19");
	#endif
		//HARMONY
		fourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		//BASS
		three(bass,A,B,A,octave-1,0.125,BASSAZ);
		append(bass,G,octave-1,0.625,BASSAZ);
		create(bass,C,octave-1,0.375,BASSAZ);
		add();
	add();
	cat();

	//MEASURE # 21
	#ifdef DEBUG
	puts("Measure # 21");
	#endif
		//HARMONY
		fourChord(harmony,G,Bf,2*Ef,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,Bf,2*Ef,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,Bf,2*Ef,2*G,octave,0.125,CHORDAZ);
		//BASS
		arpegioFour(bass,Af,Bf,2*G,2*Ef,octave-2,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 22
	#ifdef DEBUG
	puts("Measure # 22");
	#endif
		//HARMONY
		fourChord(harmony,G,Bf,2*Ef,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,Bf,2*Ef,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,Bf,2*Ef,2*G,octave,0.125,CHORDAZ);
		//BASS
		six(bass,0,D,C,Bf/2,C,D,octave,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 23 & 24
	#ifdef DEBUG
	puts("Measure # 23 & 24");
	#endif
		//HARMONY
		fourChord(harmony,G,Bf,2*Ef,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,Bf,2*Ef,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,Bf,2*Ef,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,Bf,2*Ef,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,Bf,2*Ef,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,Bf,2*Ef,2*G,octave,0.125,CHORDAZ);
		//BASS
		three(bass,C,D,C,octave,0.125,BASSAZ);
		append(bass,Bf,octave,0.625,BASSAZ);
	add();
	cat();
	//MEASURE # 25
	#ifdef DEBUG
	puts("Measure # 25");
	#endif
		releasePedal();
		//HARMONY
		fourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*F,2*G,octave,0.125,CHORDAZ);
		//BASS
		two(bass,D,E,octave-1,0.125,BASSAZ);
		append(bass,F,octave-1,0.125,BASSAZ);
		appendTwo(bass,G,A,octave-1,0.125,BASSAZ);
		create(bass,G,octave-1,0.125,BASSAZ);
		add();
	add();
	cat();
/*

	//MEASURE # 26
	#ifdef DEBUG
	puts("Measure # 26");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 27
	#ifdef DEBUG
	puts("Measure # 27");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 28
	#ifdef DEBUG
	puts("Measure # 28");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 29
	#ifdef DEBUG
	puts("Measure # 29");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 30
	#ifdef DEBUG
	puts("Measure # 30");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 31
	#ifdef DEBUG
	puts("Measure # 31");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 32
	#ifdef DEBUG
	puts("Measure # 32");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 33
	#ifdef DEBUG
	puts("Measure # 33");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 34
	#ifdef DEBUG
	puts("Measure # 34");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 35
	#ifdef DEBUG
	puts("Measure # 35");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 36
	#ifdef DEBUG
	puts("Measure # 36");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 37
	#ifdef DEBUG
	puts("Measure # 37");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 38
	#ifdef DEBUG
	puts("Measure # 38");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 39
	#ifdef DEBUG
	puts("Measure # 39");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 40
	#ifdef DEBUG
	puts("Measure # 40");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 41
	#ifdef DEBUG
	puts("Measure # 41");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 42
	#ifdef DEBUG
	puts("Measure # 42");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 43
	#ifdef DEBUG
	puts("Measure # 43");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 44
	#ifdef DEBUG
	puts("Measure # 44");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 45
	#ifdef DEBUG
	puts("Measure # 45");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 46
	#ifdef DEBUG
	puts("Measure # 46");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 47
	#ifdef DEBUG
	puts("Measure # 47");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 48
	#ifdef DEBUG
	puts("Measure # 48");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 49
	#ifdef DEBUG
	puts("Measure # 49");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 50
	#ifdef DEBUG
	puts("Measure # 50");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 51
	#ifdef DEBUG
	puts("Measure # 51");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 52
	#ifdef DEBUG
	puts("Measure # 52");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 53
	#ifdef DEBUG
	puts("Measure # 53");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 54
	#ifdef DEBUG
	puts("Measure # 54");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 55
	#ifdef DEBUG
	puts("Measure # 55");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 56
	#ifdef DEBUG
	puts("Measure # 56");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 57
	#ifdef DEBUG
	puts("Measure # 57");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 58
	#ifdef DEBUG
	puts("Measure # 58");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 59
	#ifdef DEBUG
	puts("Measure # 59");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 60
	#ifdef DEBUG
	puts("Measure # 60");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 61
	#ifdef DEBUG
	puts("Measure # 61");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 62
	#ifdef DEBUG
	puts("Measure # 62");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 63
	#ifdef DEBUG
	puts("Measure # 63");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 64
	#ifdef DEBUG
	puts("Measure # 64");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 65
	#ifdef DEBUG
	puts("Measure # 65");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 66
	#ifdef DEBUG
	puts("Measure # 66");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 67
	#ifdef DEBUG
	puts("Measure # 67");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 68
	#ifdef DEBUG
	puts("Measure # 68");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 69
	#ifdef DEBUG
	puts("Measure # 69");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 70
	#ifdef DEBUG
	puts("Measure # 70");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 71
	#ifdef DEBUG
	puts("Measure # 71");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 72
	#ifdef DEBUG
	puts("Measure # 72");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 73
	#ifdef DEBUG
	puts("Measure # 73");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 74
	#ifdef DEBUG
	puts("Measure # 74");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 75
	#ifdef DEBUG
	puts("Measure # 75");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 76
	#ifdef DEBUG
	puts("Measure # 76");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 77
	#ifdef DEBUG
	puts("Measure # 77");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 78
	#ifdef DEBUG
	puts("Measure # 78");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 79
	#ifdef DEBUG
	puts("Measure # 79");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 80
	#ifdef DEBUG
	puts("Measure # 80");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 81
	#ifdef DEBUG
	puts("Measure # 81");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 82
	#ifdef DEBUG
	puts("Measure # 82");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 83
	#ifdef DEBUG
	puts("Measure # 83");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 84
	#ifdef DEBUG
	puts("Measure # 84");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 85
	#ifdef DEBUG
	puts("Measure # 85");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 86
	#ifdef DEBUG
	puts("Measure # 86");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 87
	#ifdef DEBUG
	puts("Measure # 87");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 88
	#ifdef DEBUG
	puts("Measure # 88");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 89
	#ifdef DEBUG
	puts("Measure # 89");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 90
	#ifdef DEBUG
	puts("Measure # 90");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 91
	#ifdef DEBUG
	puts("Measure # 91");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 92
	#ifdef DEBUG
	puts("Measure # 92");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 93
	#ifdef DEBUG
	puts("Measure # 93");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 94
	#ifdef DEBUG
	puts("Measure # 94");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 95
	#ifdef DEBUG
	puts("Measure # 95");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 96
	#ifdef DEBUG
	puts("Measure # 96");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 97
	#ifdef DEBUG
	puts("Measure # 97");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 98
	#ifdef DEBUG
	puts("Measure # 98");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 99
	#ifdef DEBUG
	puts("Measure # 99");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 100
	#ifdef DEBUG
	puts("Measure # 100");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 101
	#ifdef DEBUG
	puts("Measure # 101");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 102
	#ifdef DEBUG
	puts("Measure # 102");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 103
	#ifdef DEBUG
	puts("Measure # 103");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 104
	#ifdef DEBUG
	puts("Measure # 104");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 105
	#ifdef DEBUG
	puts("Measure # 105");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 106
	#ifdef DEBUG
	puts("Measure # 106");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 107
	#ifdef DEBUG
	puts("Measure # 107");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 108
	#ifdef DEBUG
	puts("Measure # 108");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 109
	#ifdef DEBUG
	puts("Measure # 109");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 110
	#ifdef DEBUG
	puts("Measure # 110");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 111
	#ifdef DEBUG
	puts("Measure # 111");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 112
	#ifdef DEBUG
	puts("Measure # 112");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 113
	#ifdef DEBUG
	puts("Measure # 113");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 114
	#ifdef DEBUG
	puts("Measure # 114");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 115
	#ifdef DEBUG
	puts("Measure # 115");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 116
	#ifdef DEBUG
	puts("Measure # 116");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 117
	#ifdef DEBUG
	puts("Measure # 117");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 118
	#ifdef DEBUG
	puts("Measure # 118");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 119
	#ifdef DEBUG
	puts("Measure # 119");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 120
	#ifdef DEBUG
	puts("Measure # 120");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 121
	#ifdef DEBUG
	puts("Measure # 121");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 122
	#ifdef DEBUG
	puts("Measure # 122");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 123
	#ifdef DEBUG
	puts("Measure # 123");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 124
	#ifdef DEBUG
	puts("Measure # 124");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 125
	#ifdef DEBUG
	puts("Measure # 125");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 126
	#ifdef DEBUG
	puts("Measure # 126");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 127
	#ifdef DEBUG
	puts("Measure # 127");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 128
	#ifdef DEBUG
	puts("Measure # 128");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 129
	#ifdef DEBUG
	puts("Measure # 129");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 130
	#ifdef DEBUG
	puts("Measure # 130");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 131
	#ifdef DEBUG
	puts("Measure # 131");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 132
	#ifdef DEBUG
	puts("Measure # 132");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 133
	#ifdef DEBUG
	puts("Measure # 133");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 134
	#ifdef DEBUG
	puts("Measure # 134");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 135
	#ifdef DEBUG
	puts("Measure # 135");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 136
	#ifdef DEBUG
	puts("Measure # 136");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 137
	#ifdef DEBUG
	puts("Measure # 137");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 138
	#ifdef DEBUG
	puts("Measure # 138");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 139
	#ifdef DEBUG
	puts("Measure # 139");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 140
	#ifdef DEBUG
	puts("Measure # 140");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 141
	#ifdef DEBUG
	puts("Measure # 141");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 142
	#ifdef DEBUG
	puts("Measure # 142");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 143
	#ifdef DEBUG
	puts("Measure # 143");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 144
	#ifdef DEBUG
	puts("Measure # 144");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 145
	#ifdef DEBUG
	puts("Measure # 145");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 146
	#ifdef DEBUG
	puts("Measure # 146");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 147
	#ifdef DEBUG
	puts("Measure # 147");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 148
	#ifdef DEBUG
	puts("Measure # 148");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 149
	#ifdef DEBUG
	puts("Measure # 149");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 150
	#ifdef DEBUG
	puts("Measure # 150");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 151
	#ifdef DEBUG
	puts("Measure # 151");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 152
	#ifdef DEBUG
	puts("Measure # 152");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 153
	#ifdef DEBUG
	puts("Measure # 153");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 154
	#ifdef DEBUG
	puts("Measure # 154");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 155
	#ifdef DEBUG
	puts("Measure # 155");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 156
	#ifdef DEBUG
	puts("Measure # 156");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 157
	#ifdef DEBUG
	puts("Measure # 157");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 158
	#ifdef DEBUG
	puts("Measure # 158");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 159
	#ifdef DEBUG
	puts("Measure # 159");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 160
	#ifdef DEBUG
	puts("Measure # 160");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 161
	#ifdef DEBUG
	puts("Measure # 161");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 162
	#ifdef DEBUG
	puts("Measure # 162");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 163
	#ifdef DEBUG
	puts("Measure # 163");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 164
	#ifdef DEBUG
	puts("Measure # 164");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
	//MEASURE # 165
	#ifdef DEBUG
	puts("Measure # 165");
	#endif
		//HARMONY
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		(harmony,,octave,,CHORDAZ);
		//BASS
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
		(bass,,octave,,BASSAZ);
	add();
	cat();
*/
}

int main(int argc,char **argv){
	fKey = F;
	dampingTime = 0.5;
	tempo=104;
	song();
//	echo(10,0.25,4);
	puts("Writing wav file: granada.wav");
	exportToWav("granada.wav");
}
