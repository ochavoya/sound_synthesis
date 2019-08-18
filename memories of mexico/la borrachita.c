#include "soundlib.h"

#define VOICEAZ 150
#define CHORDAZ 30
#define BASSAZ 90
#define DEBUG 1


double (*voice)(double) = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double) = oldCircleOfRa;

short octave = 0;

void intro(void){
	//MEASURE # 1
	#ifdef DEBUG
	puts("Measure # 1");
	#endif
		//HARMONY
		silence(0.25);
		four(harmony,E,G,E,G,0.5,octave+1,CHORDAZ);
		addFour(harmony,G,2*C,G,2*C,octave,0.5,CHORDAZ);
		//BASS
		create(bass,C,octave-2,0.75,BASSAZ);
		addThree(bass,0,G,G/2,octave-2,0.75,BASSAZ);
	add();
	//MEASURE # 2
	#ifdef DEBUG
	puts("Measure # 2");
	#endif
		//HARMONY
		interval(harmony,A,2*F,octave,0.125,CHORDAZ);
		appendInterval(harmony,B,2*G,octave,0.0625,CHORDAZ);
		appendInterval(harmony,A,2*F,octave,0.0625,CHORDAZ);
		appendInterval(harmony,G,2*E,octave,0.25,CHORDAZ);
		appendInterval(harmony,F,2*Db,octave,0.25,CHORDAZ);
		//BASS
		create(bass,D,octave-2,0.75,BASSAZ);
		addThree(bass,0,G,G/2,octave-2,0.75,BASSAZ);		
	add();
	cat();
	//MEASURE # 3
	#ifdef DEBUG
	puts("Measure # 3");
	#endif
		//HARMONY
		six(harmony,C,E,A,E,A,E,octave+1,0.75,CHORDAZ);
		addSix(harmony,E,G,2*C,G,2*C,G,octave,0.75,CHORDAZ);
		//BASS
		create(bass,C,octave-2,0.75,BASSAZ);
		addThree(bass,0,G,G/2,octave-2,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 4
	#ifdef DEBUG
	puts("Measure # 4");
	#endif
		//HARMONY
		interval(harmony,B,2*G,octave,0.125,CHORDAZ);
		three(harmony,F,G,F,octave+1,0.125,CHORDAZ);
		addThree(harmony,A,B,A,octave,0.125,CHORDAZ);
		cat();
		appendInterval(harmony,G,2*E,octave,0.25,CHORDAZ);
		appendInterval(harmony,F,2*D,octave,0.25,CHORDAZ);
		//BASS
		create(bass,D,octave-2,0.75,BASSAZ);
		addThree(bass,0,G,G/2,octave-2,0.75,BASSAZ);
	add();
	cat();
}


void start(void){
	PIANO;
	//MEASURE # 5
	#ifdef DEBUG
	puts("Measure # 5");
	#endif
		//HARMONY
		interval(harmony,E,2*C,octave,0.5,CHORDAZ);
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,CHORDAZ);
		appendTwo(bass,G,G/2,octave-2,0.5,CHORDAZ);
	add();
	//MEASURE # 6
	#ifdef DEBUG
	puts("Measure # 6");
	#endif
		//HARMONY
		interval(harmony,E,2*C,octave-1,0.5,CHORDAZ);
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,CHORDAZ);
		appendTwo(bass,G,G/2,octave-2,0.5,CHORDAZ);
	add();
	cat();
	//MEASURE # 7
	#ifdef DEBUG
	puts("Measure # 7");
	#endif
		//VOICE
		three(voice,0,G/2,C,octave,0.5,VOICEAZ);
		append(voice,E,octave,0.5/3,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		append(voice,F,octave,0.5/6,VOICEAZ);
		//HARMONY
		three(harmony,0,G/2,C,octave,0.5,CHORDAZ);
		append(harmony,E,octave,0.5/3,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.25,CHORDAZ);
		appendInterval(harmony,D,F,octave,0.5/6,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,CHORDAZ);
		appendTwo(bass,2*E,G/2,octave-2,0.5,CHORDAZ);				
	add();
	cat();
	//MEASURE # 8 & 9
	#ifdef DEBUG
	puts("Measure # 8 & 9");
	#endif
		//VOICE 
		create(voice,E,octave,1.25,VOICEAZ);
		appendSilence(0.125);
		append(voice,E,octave,0.125,VOICEAZ);
		appendGrace(voice,G,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave,1.375,CHORDAZ);
		create(harmony,E,octave,0.125,CHORDAZ);
		appendGrace(harmony,G,F,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.25,CHORDAZ);
		create(harmony,C,octave,0.125,CHORDAZ);
		appendTwo(harmony,D,C,octave,0.5,CHORDAZ);
		add();
		cat();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendGrace(bass,B,A,octave-1,0.25,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
		append(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,G,G,octave-2,0.5,BASSAZ);
	add();
	cat();


	//MEASURE # 10 & 11
	#ifdef DEBUG
	puts("Measure # 10 & 11");
	#endif
		//VOICE 
		create(voice,F,octave,0.5,VOICEAZ);
		append(voice,G,octave,0.75,VOICEAZ);
		appendThree(voice,A,A,A,octave,0.75,VOICEAZ);		
		//HARMONY
		interval(harmony,B/2,F,octave,0.5,CHORDAZ);
		appendInterval(harmony,B/2,G,octave,0.75,CHORDAZ);
		three(harmony,A,A,A,octave,0.75,CHORDAZ);
		addThree(harmony,F,F,F,octave,0.75,CHORDAZ);
		cat();
	add();
		//BASS
		create(bass,D,octave-2,0.5,BASSAZ);
		appendGrace(bass,Gf,G,octave-2,0.25,BASSAZ);
		append(bass,D,octave-2,0.25,BASSAZ);
		append(bass,G,octave-3,0.5,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 12 & 13
	#ifdef DEBUG
	puts("Measure # 12 & 13");
	#endif
		//VOICE 
		create(voice,A,octave,0.375,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.875,VOICEAZ);
		append(voice,F,octave,0.125,VOICEAZ);
		appendTwo(voice,F,F,octave,0.5,VOICEAZ);
		//HARMONY
		interval(harmony,F,A,octave,0.375,CHORDAZ);
		appendInterval(harmony,B/2,G,octave,0.125,CHORDAZ);
		appendInterval(harmony,B/2,G,octave,0.875,CHORDAZ);
		appendInterval(harmony,A/2,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,A/2,F,octave,0.25,CHORDAZ);
		appendInterval(harmony,A/2,F,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,Db,octave-2,0.5,BASSAZ);
		appendFour(bass,G/2,D,F,G,octave,0.25,BASSAZ);
		append(bass,Db,octave-2,0.25,BASSAZ);
		append(bass,G,octave-3,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,A,B,octave-2,0.5,BASSAZ);
	add();
	cat();

	//MEASURE # 14 & 15
	#ifdef DEBUG
	puts("Measure # 14 & 15");
	#endif
		//VOICE
		create(voice,E,octave,0.5,VOICEAZ);
		append(voice,C,octave,0.5,VOICEAZ);
		appendThree(voice,0,G/2,C,octave,0.5,VOICEAZ);
		append(voice,E,octave,0.5/3,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		append(voice,F,octave,0.25/3,VOICEAZ);
		//HARMONY
		interval(harmony,G/2,E,octave,0.5,CHORDAZ);
		create(harmony,C,octave,2.0/3,CHORDAZ);
		create(harmony,G/2,octave,0.5,CHORDAZ);
		add();
		cat();
		appendThree(harmony,G/2,C,E,octave,0.5,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.25,CHORDAZ);
		appendInterval(harmony,D,F,octave,0.25/3,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);
		append(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,E,octave-1,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);
		
	add();
	cat();

	//MEASURE # 16 & 17
	#ifdef DEBUG
	puts("Measure # 16 & 17");
	#endif
		//VOICE 
		create(voice,E,octave,1.375,VOICEAZ);
		appendThree(voice,C,D,E,octave,0.375,VOICEAZ);
		appendTwo(voice,F,G,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave,1.375,CHORDAZ);
		append(harmony,C,octave,0.125,CHORDAZ);
		four(harmony,D,E,F,G,octave,0.5,CHORDAZ);
		addFour(harmony,B/2,Bf/2,A/2,C,octave,0.5,CHORDAZ);
		CRESCENDO;
		cat();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendGrace(bass,B,A,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,C,octave-2,0.375,BASSAZ);
		append(bass,B,octave-2,0.125,BASSAZ);
		append(bass,B,octave-2,0.25,BASSAZ);
		append(bass,B,octave-2,0.25,BASSAZ);		
	add();
	cat();
	//MEASURE 18 & 19
	#ifdef DEBUG
	puts("Measure # 18 & 19");
	#endif
		//VOICE
		create(voice,A,octave,0.5,VOICEAZ);
		append(voice,C,octave+1,0.5+FERMATA(0.5/3),VOICEAZ);
		appendTwo(voice,A,B,octave,1.0/3,VOICEAZ);
		append(voice,C,octave+1,0.5/3,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ);
		append(voice,A,octave,1.0/12,VOICEAZ);
		//HARMONY
		create(harmony,A,octave,0.5,CHORDAZ);
		append(harmony,C,octave+1,0.5+FERMATA(0.5/3),CHORDAZ);
		appendTwo(harmony,A,B,octave,1.0/3,CHORDAZ);
		append(harmony,C,octave+1,0.5/3,CHORDAZ);
		append(harmony,B,octave,0.25,CHORDAZ);
		append(harmony,A,octave,1.0/12,CHORDAZ);
		create(harmony,F,octave,0.5,CHORDAZ);
		append(harmony,A,octave,0.5+FERMATA(0.5/3),CHORDAZ);
		appendTwo(harmony,F,G,octave,1.0/3,CHORDAZ);
		append(harmony,A,octave,0.5/3,CHORDAZ);
		append(harmony,G,octave,0.25,CHORDAZ);
		append(harmony,F,octave,1.0/12,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,F,octave-3,0.25,BASSAZ);
		appendTwo(bass,C,F,octave-2,0.25,BASSAZ);
		appendFour(bass,A/2,C,F,A,octave,0.5,BASSAZ);
		append(bass,C,octave,FERMATA(0.5/3)+1.0/3,BASSAZ);
	add();
	cat();

	//MEASURE # 20
	#ifdef DEBUG
	puts("Measure # 20");
	#endif
		//VOICE 
		three(voice,2*C,E,F,octave,0.5,VOICEAZ);
		append(voice,G,octave,1.0/6,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,1.0/12,VOICEAZ);
		//HARMONY
		three(harmony,2*C,E,F,octave,0.5,CHORDAZ);
		append(harmony,G,octave,1.0/6,CHORDAZ);
		append(harmony,F,octave,0.25,CHORDAZ);
		append(harmony,E,octave,1.0/12,CHORDAZ);

		three(harmony,E,C,Db,octave,0.5,CHORDAZ);
		append(harmony,E,octave,1.0/6,CHORDAZ);
		append(harmony,D,octave,0.25,CHORDAZ);
		append(harmony,C,octave,1.0/12,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,G,octave-3,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 21
	#ifdef DEBUG
	puts("Measure # 21");
	#endif
		//VOICE 
		four(voice,G,0,F,B/2,octave,1.0,VOICEAZ);
		//HARMONY
		interval(harmony,B/2,G,octave,0.25,CHORDAZ);
		appendSilence(0.25);
		interval(harmony,A/2,F,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,B,octave-1,0.25,CHORDAZ);
		DECRESCENDO;
		cat();
	add();
		//BASS
		four(bass,Db,0,G,G/2,octave-2,1.0,BASSAZ);
		
	add();
	cat();
	//MEASURE # 22
	#ifdef DEBUG
	puts("Measure # 22");
	#endif
		//VOICE 
		create(voice,C,octave,1.0,VOICEAZ);
		//HARMONY
		interval(voice,E,2*C,octave-1,1.0,VOICEAZ);
	add();
		//BASS
		create(bass,C,octave-3,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);
	add();
	cat();
}

void refrain(short end){
	MESSOFORTE;
	//MEASURE # 23
	#ifdef DEBUG
	puts("Measure # 23");
	#endif
		//VOICE 
		six(voice,0,G/2,C,E,D,C,octave,1.0,VOICEAZ);
		//HARMONY
		six(harmony,0,G/2,C,E,D,C,octave,1.0,CHORDAZ);
		addSix(harmony,0,0,0,C,B/2,A/2,octave,1.0,CHORDAZ);
		
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,E,octave-1,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 24 & 25
	#ifdef DEBUG
	puts("Measure # 24 & 25");
	#endif
		//VOICE 
		create(voice,B,octave-1,1.375,VOICEAZ);
		append(voice,C,octave,0.125,VOICEAZ);
		appendTwo(voice,A,B,octave-1,0.5,VOICEAZ);
		//HARMONY
		create(harmony,B,octave-1,1.375,CHORDAZ);
		append(harmony,C,octave,0.125,CHORDAZ);
		appendTwo(harmony,A,B,octave-1,0.5,CHORDAZ);
		create(harmony,G,octave-1,1.375,CHORDAZ);
		append(harmony,A,octave-1,0.125,CHORDAZ);
		appendTwo(harmony,F,G,octave-1,0.5,CHORDAZ);
		add();		
	add();
		//BASS
		create(bass,D,octave-2,0.5,BASSAZ);
		appendGrace(bass,F,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);
		append(bass,D,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 26 & 27
	#ifdef DEBUG
	puts("Measure # 26 & 27");
	#endif
		//VOICE 
		create(voice,G,octave-1,7.0/6,VOICEAZ);
		appendTwo(voice,E,F,octave,1.0/3,VOICEAZ);
		append(voice,G,octave,1.0/6,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,1.0/12,VOICEAZ);
		//HARMONY
		create(harmony,G,octave-1,7.0/6,CHORDAZ);
		appendTwo(harmony,E,F,octave,1.0/3,CHORDAZ);
		append(harmony,G,octave,1.0/6,CHORDAZ);
		append(harmony,F,octave,0.25,CHORDAZ);
		append(harmony,E,octave,1.0/12,CHORDAZ);
		create(harmony,E,octave-1,7.0/6,CHORDAZ);
		appendTwo(harmony,C,D,octave,1.0/3,CHORDAZ);
		append(harmony,E,octave,1.0/6,CHORDAZ);
		append(harmony,D,octave,0.25,CHORDAZ);
		append(harmony,C,octave,1.0/12,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendGrace(bass,B,A,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,E,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);

	add();
	cat();

	//MEASURE # 28 & 29
	#ifdef DEBUG
	puts("Measure # 28 & 29");
	#endif
		//VOICE 
		create(voice,G,octave,1.25,VOICEAZ);
		appendThree(voice,A,F,G,octave,0.75,VOICEAZ);
		//HARMONY
		create(harmony,G,octave,1.25,CHORDAZ);
		appendThree(harmony,A,F,G,octave,0.75,CHORDAZ);
		create(harmony,B/2,octave,1.25,CHORDAZ);
		appendThree(harmony,F,B/2,B/2,octave,0.75,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,D,octave-2,0.5,VOICEAZ);
		appendGrace(bass,Gf,G,octave-1,0.25,VOICEAZ);
		append(bass,D,octave-2,0.25,VOICEAZ);
		append(bass,G,octave-3,0.5,VOICEAZ);
		append(bass,D,octave-1,0.25,VOICEAZ);
		append(bass,G,octave-3,0.25,VOICEAZ);
	add();
	cat();

	//MEASURE # 30 & 31
	#ifdef DEBUG
	puts("Measure # 30 & 31");
	#endif
		//VOICE 
		create(voice,E,octave,7.0/6,VOICEAZ);
		appendThree(voice,G/2,C,E,octave,0.5,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		append(voice,F,octave,1.0/12,VOICEAZ);
		//HARMONY
		create(harmony,E,octave,7.0/6,CHORDAZ);
		appendThree(harmony,G/2,C,E,octave,0.5,CHORDAZ);
		append(harmony,G,octave,0.25,CHORDAZ);
		append(harmony,F,octave,1.0/12,CHORDAZ);

		create(harmony,C,octave,1.0,CHORDAZ);
		appendSilence(2.0/3);
		append(harmony,E,octave,0.25,CHORDAZ);
		append(harmony,D,octave,1.0/12,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendGrace(bass,B,A,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,E,octave-1,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 32 & 33
	#ifdef DEBUG
	puts("Measure # 32 & 33");
	#endif
		//VOICE 
		create(voice,E,octave,1.375,VOICEAZ);
		append(voice,C,octave,0.125,VOICEAZ);
		appendFour(voice,D,E,F,G,octave,0.5,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave,1.375,CHORDAZ);
		append(harmony,C,octave,0.125,CHORDAZ);
		four(harmony,D,E,F,G,octave,0.5,CHORDAZ);
		addFour(harmony,B,Bf,A,2*C,octave-1,0.5,CHORDAZ);
		CRESCENDO;
		cat();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendGrace(bass,B,A,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,C,octave-2,0.375,BASSAZ);
		append(bass,C,octave-1,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,C,octave-3,0.25,BASSAZ);		
	add();
	cat();
	//MEASURE # 34 & 35
	#ifdef DEBUG
	puts("Measure # 34 & 35");
	#endif
		//VOICE 
		create(voice,A,octave,0.5,VOICEAZ);
		append(voice,C,octave+1,0.5+FERMATA(0.5/3),VOICEAZ);
		appendTwo(voice,A,B,octave,1.0/3,VOICEAZ);
		appendGrace(voice,D,C,octave+1,0.5/3,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ);
		append(voice,A,octave,1.0/12,VOICEAZ);
		//HARMONY
		create(harmony,A,octave,0.5,CHORDAZ);
		append(harmony,C,octave+1,0.5+FERMATA(0.5/3),CHORDAZ);
		appendTwo(harmony,A,B,octave,1.0/3,CHORDAZ);
		appendGrace(harmony,D,C,octave+1,0.5/3,CHORDAZ);
		append(harmony,B,octave,0.25,VOICEAZ);
		append(harmony,A,octave,1.0/12,VOICEAZ);
		create(harmony,F,octave,0.5,CHORDAZ);
		append(harmony,A,octave,0.5+FERMATA(0.5/3),CHORDAZ);
		appendTwo(harmony,F,G,octave,1.0/3,CHORDAZ);
		appendGrace(harmony,B,A,octave,0.5/3,CHORDAZ);
		append(harmony,G,octave,0.25,VOICEAZ);
		append(harmony,F,octave,1.0/12,VOICEAZ);
		add();
	add();
		//BASS
		create(bass,F,octave-3,0.25,BASSAZ);
		appendTwo(bass,C,F,octave-2,0.25,BASSAZ);
		four(bass,A/2,C,F,A,octave-1,0.5,BASSAZ);
		CRESCENDO;
		cat();
		append(bass,C,octave,FERMATA(0.5/3),BASSAZ);
		appendTwo(bass,F,G,octave-1,1.0/3,BASSAZ);
		append(bass,A,octave-1,0.5/3,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
		append(bass,E,octave-1,1.0/12,BASSAZ);
	add();
	cat();

	//MEASURE # 36
	#ifdef DEBUG
	puts("Measure # 36");
	#endif
		//VOICE 
		three(voice,2*C,E,F,octave,0.5,VOICEAZ);
		append(voice,G,octave,0.5/3,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,1.0/12,VOICEAZ);
		//HARMONY
		three(harmony,2*C,E,F,octave,0.5,CHORDAZ);
		append(harmony,G,octave,0.5/3,CHORDAZ);
		append(harmony,F,octave,0.25,CHORDAZ);
		append(harmony,E,octave,1.0/12,CHORDAZ);
		three(harmony,E,C,Db,octave,0.5,CHORDAZ);
		append(harmony,E,octave,0.5/3,CHORDAZ);
		append(harmony,Db,octave,0.25,CHORDAZ);
		append(harmony,C,octave,1.0/12,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,G,octave-3,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 37
	#ifdef DEBUG
	puts("Measure # 37");
	#endif
		//VOICE 
		create(voice,G,octave,0.5,VOICEAZ);
		appendTwo(voice,F,B/2,octave,0.5,VOICEAZ);
		//HARMONY
		interval(harmony,B/2,G,octave,0.5,CHORDAZ);
		appendInterval(harmony,A/2,F,octave,0.25,CHORDAZ);
		appendInterval(harmony,F,B,octave-1,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,Db,octave-2,0.5,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 38
	#ifdef DEBUG
	puts("Measure # 38");
	#endif
		//VOICE 
		create(voice,C,octave,1.0,VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave-1,1.0,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 39
	#ifdef DEBUG
	puts("Measure # 39");
	#endif
		//VOICE 
		six(voice,0,G/2,C,E,D,C,octave,1.0,VOICEAZ);
		//HARMONY
		six(harmony,0,G/2,C,E,D,C,octave,1.0,CHORDAZ);
		addSix(harmony,0,0,0,2*C,B,A,octave-1,1.0,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,E,octave-1,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);

	add();
	cat();

	//MEASURE # 40 & 41
	#ifdef DEBUG
	puts("Measure # 40");
	#endif
		//VOICE 
		create(voice,B,octave-1,1.375,VOICEAZ);
		append(voice,C,octave,0.125,VOICEAZ);
		appendTwo(voice,A,B,octave-1,0.5,VOICEAZ);
		//HARMONY
		create(harmony,B,octave-1,1.375,CHORDAZ);
		append(harmony,C,octave,0.125,CHORDAZ);
		appendTwo(harmony,A,B,octave-1,0.5,CHORDAZ);
		create(harmony,G,octave-1,1.375,CHORDAZ);
		append(harmony,A,octave-1,0.125,CHORDAZ);
		appendTwo(harmony,F,G,octave-1,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,D,octave-2,0.5,BASSAZ);
		appendGrace(bass,F,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);
		append(bass,D,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 42 & 43
	#ifdef DEBUG
	puts("Measure # 42 & 43");
	#endif
		//VOICE 
		create(voice,G,octave-1,7.0/6,VOICEAZ);
		appendThree(voice,E,F,G,octave,0.5,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,1.0/12,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave-1,7.0/6,CHORDAZ);
		three(harmony,E,F,G,octave,0.5,CHORDAZ);
		addThree(harmony,C,D,E,octave,0.5,CHORDAZ);
		cat();
		appendInterval(harmony,Db,F,octave,0.25,CHORDAZ);
		appendInterval(harmony,C,E,octave,1.0/12,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendGrace(bass,B,A,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,E,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 44 & 45
	#ifdef DEBUG
	puts("Measure # 44 & 45");
	#endif
		//VOICE 
		create(voice,G,octave,1.25,VOICEAZ);
		appendThree(voice,A,F,G,octave,0.75,VOICEAZ);
		//HARMONY
		create(harmony,G,octave,1.25,CHORDAZ);
		appendThree(harmony,A,F,G,octave,0.75,CHORDAZ);
		create(harmony,B,octave-1,1.25,CHORDAZ);
		appendThree(harmony,F,B/2,B/2,octave,0.75,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,D,octave-2,0.5,BASSAZ);
		appendGrace(bass,A,G,octave-1,0.25,BASSAZ);
		append(bass,D,octave-2,0.25,BASSAZ);
		append(bass,G,octave-3,0.5,BASSAZ);
		append(bass,D,octave-1,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 46 & 47
	#ifdef DEBUG
	puts("Measure # 46 & 47");
	#endif
		//VOICE 
		create(voice,E,octave,7.0/6,VOICEAZ);
		appendThree(voice,G/2,C,E,octave,0.5,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		append(voice,F,octave,1.0/12,VOICEAZ);
		//HARMONY
		create(harmony,E,octave,7.0/6,CHORDAZ);
		appendThree(harmony,G/2,C,E,octave,0.5,CHORDAZ);
		append(harmony,G,octave,0.25,CHORDAZ);
		append(harmony,F,octave,1.0/12,CHORDAZ);
		create(harmony,C,octave,1.0,CHORDAZ);
		appendSilence(2.0/3);
		append(harmony,E,octave,0.25,CHORDAZ);
		append(harmony,D,octave,1.0/12,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendGrace(bass,B,A,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,E,octave-1,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 48 & 49
	#ifdef DEBUG
	puts("Measure # 48 & 49");
	#endif
		//VOICE 
		create(voice,E,octave,1.375,VOICEAZ);
		append(voice,C,octave,0.125,VOICEAZ);
		appendFour(voice,D,E,F,G,octave,0.5,VOICEAZ);
		//HARMONY
		create(harmony,E,octave,1.375,CHORDAZ);
		append(harmony,C,octave,0.125,CHORDAZ);
		create(harmony,C,octave,1.375,CHORDAZ);
		add();
		four(harmony,D,E,F,G,octave,0.5,CHORDAZ);
		addFour(harmony,B,Bf,A,2*C,octave-1,0.5,CHORDAZ);
		CRESCENDO;
		cat();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendGrace(bass,B,A,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,C,octave-2,0.375,BASSAZ);
		append(bass,C,octave-1,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 50 & 51
	#ifdef DEBUG
	puts("Measure # 50 & 51");
	#endif
		//VOICE 
		create(voice,A,octave,0.5,VOICEAZ);
		append(voice,C,octave+1,0.5+FERMATA(0.5/3),VOICEAZ);
		appendTwo(voice,A,B,octave,1.0/3,VOICEAZ);
		appendGrace(voice,D,C,octave+1,0.5/3,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ);
		append(voice,A,octave,1.0/12,VOICEAZ);
		//HARMONY
		create(harmony,A,octave,0.5,CHORDAZ);
		append(harmony,C,octave+1,0.5+FERMATA(0.5/3),CHORDAZ);
		appendTwo(harmony,A,B,octave,1.0/3,CHORDAZ);
		appendGrace(harmony,D,C,octave+1,0.5/3,CHORDAZ);
		append(harmony,B,octave,0.25,CHORDAZ);
		append(harmony,A,octave,1.0/12,CHORDAZ);
		create(harmony,F,octave,0.5,CHORDAZ);
		append(harmony,A,octave,0.5+FERMATA(0.5/3),CHORDAZ);
		appendTwo(harmony,F,G,octave,1.0/3,CHORDAZ);
		appendGrace(harmony,B,A,octave,0.5/3,CHORDAZ);
		append(harmony,G,octave,0.25,CHORDAZ);
		append(harmony,F,octave,1.0/12,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,F,octave-3,0.25,BASSAZ);
		appendTwo(bass,C,F,octave-2,0.25,BASSAZ);
		four(bass,A/2,C,F,A,octave-1,0.5,BASSAZ);
		CRESCENDO;
		cat();
		append(bass,C,octave,FERMATA(0.5/3),BASSAZ);
		appendThree(bass,F,G,A,octave-1,0.5,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
		append(bass,F,octave-1,1.0/12,BASSAZ);
	add();
	cat();

	//MEASURE # 52
	#ifdef DEBUG
	puts("Measure # 52");
	#endif
		//VOICE 
		three(voice,2*C,E,F,octave,0.5,VOICEAZ);
		append(voice,G,octave,0.5/3,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,1.0/12,VOICEAZ);
		//HARMONY
		three(harmony,2*C,E,F,octave,0.5,CHORDAZ);
		append(harmony,G,octave,0.5/3,CHORDAZ);
		append(harmony,F,octave,0.25,CHORDAZ);
		append(harmony,E,octave,1.0/12,CHORDAZ);
		three(harmony,E,C,D,octave,0.5,CHORDAZ);
		append(harmony,E,octave,0.5/3,CHORDAZ);
		append(harmony,D,octave,0.25,CHORDAZ);
		append(harmony,C,octave,1.0/12,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,G,octave-3,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 53
	#ifdef DEBUG
	puts("Measure # 53");
	#endif
		//VOICE 
		create(voice,G,octave,0.5,VOICEAZ);
		appendTwo(voice,F,B/2,octave,0.5,VOICEAZ);
		//HARMONY
		create(harmony,G,octave,0.5,CHORDAZ);
		appendTwo(harmony,F,B/2,octave,0.5,CHORDAZ);
		create(harmony,B/2,octave,0.5,CHORDAZ);
		appendTwo(harmony,A/2,F/2,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,D,octave-2,0.5,BASSAZ);
		appendTwo(bass,G,G/2,octave-2,0.5,BASSAZ);
	add();
	cat();
	if(!end){
	//MEASURE # 54
	#ifdef DEBUG
	puts("Measure # 54");
	#endif
		//VOICE 
		create(voice,C,octave,1.0,VOICEAZ);
		//HARMONY
		interval(harmony,C,E/2,octave,1.0,VOICEAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);
	add();
	cat();
	}
	else{
	//MEASURE # 55 & 56
	#ifdef DEBUG
	puts("Measure # 55");
	#endif
		//VOICE 
		create(voice,C,octave,1.0,VOICEAZ);
		//HARMONY
		interval(harmony,C,E/2,octave,1.0,VOICEAZ);
	add();
		intro();
	add();
	cat();
		
		FORTE;
		fourChordMartelato(harmony,C,E,G,2*C,octave,0.75,CHORDAZ);
		intervalMartelato(bass,C,C/2,octave-1,0.75,BASSAZ);		
	add();
	cat();
	}
}

void song(void){
	MESSOFORTE;
	puts("intro");
 	intro();
	puts("start");
	start();
	cat();
	puts("refrain(0)");
	refrain(0);
	cat();
	puts("refrain(1)");
	refrain(1);
	cat();
}


int main(int argc, char **argv){

	tempo=100;

	C = F;

	song();

	echo(10,0.3,4);
    appendSilence(2);
	puts("Writing wav file... la borrachita.wav");

	exportToWav("La Borrachita.wav");

}
