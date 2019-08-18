#include "soundlib.h"

#define VOICEAZ 150
#define CHORDAZ 30
#define BASSAZ 90

#define DEBUG 1


double (*voice)(double) = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double) = oldCircleOfRa;


short octave = 0;

void intro(void);
void repeat(void);
void coda(void);


void start(void){
	FORTE;
	//MEASURE # 1
	#ifdef DEBUG
	puts("Measure # 1");
	#endif
		//HARMONY
		chord(harmony,F,A,2*Db,octave,1.0,CHORDAZ);
		//BASS
		create(bass,G,octave-3,0.375,BASSAZ);
		append(bass,D,octave-2,0.125,BASSAZ);
		appendTwo(bass,G,D,octave-2,0.5,BASSAZ);
	add();
	//MEASURE # 2
	#ifdef DEBUG
	puts("Measure # 2");
	#endif
		//HARMONY
		chord(harmony,F,B,2*D,octave,0.5/3,CHORDAZ);
		appendInterval(harmony,C,E,octave+1,0.5/3,CHORDAZ);
		appendInterval(harmony,A,2*C,octave,0.5/3,CHORDAZ);
		appendInterval(harmony,B,2*D,octave,0.25,CHORDAZ);
		appendInterval(harmony,G,B,octave,0.25,CHORDAZ);
		//BASS
		create(bass,G,octave-3,0.375,BASSAZ);
		append(bass,D,octave-2,0.125,BASSAZ);
		appendTwo(bass,G,D,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 3
	#ifdef DEBUG
	puts("Measure # 3");
	#endif
		//HARMONY
		interval(harmony,B/2,D,octave,0.5/3,CHORDAZ);
		appendInterval(harmony,D,E,octave,0.5/3,CHORDAZ);
		appendInterval(harmony,E,F,octave,0.5/3,CHORDAZ);
		appendInterval(harmony,F,A,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.25,CHORDAZ);
		//BASS
		create(bass,G,octave-3,0.375,BASSAZ);
		append(bass,D,octave-2,0.125,BASSAZ);
		appendTwo(bass,G,G/2,octave-2,0.5,BASSAZ);


	add();
	cat();
	//MEASURE # 4
	DOUBLEFORTE;
	#ifdef DEBUG
	puts("Measure # 4");
	#endif
		//HARMONY
		interval(harmony,E/2,C,octave,0.375,CHORDAZ);
		append(harmony,G,octave-2,0.125,CHORDAZ);
		appendIntervalMartelato(harmony,E/2,C,octave,0.25,CHORDAZ);
		appendEstacato(harmony,G,octave-1,0.25,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendIntervalMartelato(bass,C/2,C,octave-1,0.25,BASSAZ);
		appendEstacato(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
}



void repeat(void){
	MESSOFORTE;
	//MEASURE # 5
	#ifdef DEBUG
	puts("Measure # 5");
	#endif
		//HARMONY
		intervalMarcato(harmony,F,B,octave-1,0.375,CHORDAZ);
		append(harmony,G,octave-1,0.125,CHORDAZ);
		appendIntervalMartelato(harmony,F,B,octave-1,0.25,CHORDAZ);
		append(harmony,G,octave-1,0.25,CHORDAZ);
		//BASS
		interval(bass,D,2*D,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,Db,2*Db,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	//MEASURE # 6
	MESSOPIANO;
	#ifdef DEBUG
	puts("Measure # 6");
	#endif
		//HARMONY
		fourEstacato(harmony,B,B,B,G,octave-1,0.5,CHORDAZ);
		create(harmony,F,octave-1,0.375,CHORDAZ);
		append(harmony,G,octave-1,0.125,CHORDAZ);
		add();
		appendIntervalMartelato(harmony,F,B,octave-1,0.25,CHORDAZ);
		append(harmony,G,octave-1,0.25,CHORDAZ);
		//BASS
		interval(bass,Db/2,Db,octave-1,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendIntervalMartelato(bass,Db/2,Db,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 7 & 8
	PIANO;
	#ifdef DEBUG
	puts("Measure # 7 & 8");
	#endif
		//HARMONY
		interval(harmony,E/2,C,octave,1.5+FERMATA(0.25),CHORDAZ);
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,C,G/2,octave-1,0.5,BASSAZ);
		append(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,FERMATA(0.25),BASSAZ);
	add();
	cat();
	MESSOPIANO;
		//VOICE
		create(voice,G,octave,0.25,VOICEAZ);
		//HARMONY
		arpegio(harmony,C,E,G,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();


	//MEASURE # 9 & 10
	#ifdef DEBUG
	puts("Measure # 9 & 10");
	#endif
		//VOICE
		create(voice,G,octave,1+0.5/3,VOICEAZ);
		appendTwo(voice,E,F,octave,1.0/3,VOICEAZ);
		appendTwo(voice,G,A,octave,0.5,VOICEAZ);
		//HARMONY
		arpegio(harmony,C,E,G,octave,1+0.5/3,CHORDAZ);
		two(harmony,E,F,octave,1.0/3,CHORDAZ);
		addTwo(harmony,C,Db,octave,1.0/3,CHORDAZ);
		cat();
		two(harmony,G,A,octave,0.5,CHORDAZ);
		addTwo(harmony,E,F,octave,0.5,CHORDAZ);
		cat();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,C,G/2,octave-1,0.5,BASSAZ);
		append(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,C,G/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 11
	#ifdef DEBUG
	puts("Measure # 11");
	#endif
		//VOICE
		three(voice,B,2*C,A,octave,0.5,VOICEAZ);
		appendTwo(voice,B,G,octave,0.5,VOICEAZ);
		//HARMONY
		three(harmony,B,2*C,A,octave,0.5,CHORDAZ);
		appendTwo(harmony,B,G,octave,0.5,CHORDAZ);
		three(harmony,G,A,F,octave,0.5,CHORDAZ);
		appendTwo(harmony,G,E,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,C,G/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 12 & 13
	#ifdef DEBUG
	puts("Measure # 12 & 13");
	#endif
		//VOICE
		create(voice,F,octave,1.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,D,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,B/2,F,octave,0.75,CHORDAZ);
		appendFour(harmony,2*D,2*C,B,A,octave,0.25,CHORDAZ);
		append(harmony,G,octave,0.75,CHORDAZ);
		appendArpegio(harmony,F,B,2*D,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,E,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,D,G/2,octave-1,0.5,BASSAZ);
		append(bass,G,octave-3,0.375,BASSAZ);
		append(bass,D,octave-2,0.125,BASSAZ);
		appendTwo(bass,G,D,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 14 & 15
	#ifdef DEBUG
	puts("Measure # 14 & 15");
	#endif
		//VOICE
		create(voice,Db,octave+1,1+0.5/3,VOICEAZ);
		appendTwo(voice,E,C,octave+1,1.0/3,VOICEAZ);
		appendTwo(voice,D,B,octave+1,0.5,VOICEAZ);
		//HARMONY
		arpegio(harmony,F,B,2*D,octave,1+0.5/3,CHORDAZ);
		two(harmony,E,C,octave+1,1.0/3,CHORDAZ);
		addTwo(harmony,2*C,B,octave,1.0/3,CHORDAZ);
		cat();
		two(harmony,D,B/2,octave+1,0.5,CHORDAZ);
		addTwo(harmony,B,G,octave,0.5,CHORDAZ);
		cat();
	add();
		//BASS
		create(bass,G,octave-3,0.375,BASSAZ);
		append(bass,D,octave-2,0.125,BASSAZ);
		appendTwo(bass,G,D,octave-2,0.5,BASSAZ);
		append(bass,G,octave-3,0.375,BASSAZ);
		append(bass,D,octave-2,0.125,BASSAZ);
		appendTwo(bass,G,D,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 16
	#ifdef DEBUG
	puts("Measure # 16");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5/3,VOICEAZ);
		appendDoubleGrace(voice,D,C,B/2,octave+1,0.5/3,VOICEAZ);
		append(voice,A,octave,0.5/3,VOICEAZ);
		append(voice,G,octave,0.375,VOICEAZ);
		append(voice,F,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,A,2*C,octave,0.5/3,CHORDAZ);
		doubleGrace(harmony,D,C,B/2,octave+1,0.5/3,CHORDAZ);
		create(harmony,G,octave,0.5/3,CHORDAZ);
		add();
		cat();
		appendInterval(harmony,F,A,octave,0.5/3,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.375,CHORDAZ);
		appendInterval(harmony,Db,F,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-3,0.375,BASSAZ);
		append(bass,D,octave-2,0.125,BASSAZ);
		appendTwo(bass,G,G/2,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 17 & 18
	#ifdef DEBUG
	puts("Measure # 17 & 18");
	#endif
		//VOICE
		create(voice,E,octave,1.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,G,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave,0.75,CHORDAZ);
		appendFour(harmony,G,F,E,D,octave+1,0.25,CHORDAZ);
		append(harmony,C,octave+1,0.75,CHORDAZ);
		arpegio(harmony,C,E,G,octave,0.25,CHORDAZ);
		cat();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,G,octave,0.25,BASSAZ);
		append(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,G,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 19 & 20
	#ifdef DEBUG
	puts("Measure # 19 & 20");
	#endif
		//VOICE
		create(voice,G,octave,1+0.5/3,VOICEAZ);
		appendTwo(voice,E,F,octave,1.0/3,VOICEAZ);
		appendTwo(voice,G,A,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,1.0+0.5/3,CHORDAZ);
		two(harmony,E,F,octave,1.0/3,CHORDAZ);
		addTwo(harmony,C,Db,octave,1.0/3,CHORDAZ);
		cat();
		two(harmony,G,A,octave,0.5,CHORDAZ);
		addTwo(harmony,E,F,octave,0.5,CHORDAZ);
		cat();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 21
	#ifdef DEBUG
	puts("Measure # 21");
	#endif
		//VOICE
		three(voice,B,2*C,A,octave,0.5,VOICEAZ);
		appendTwo(voice,B,G,octave,0.5,VOICEAZ);
		//HARMONY
		three(harmony,B,2*C,A,octave,0.5,CHORDAZ);
		appendTwo(harmony,B,G,octave,0.5,CHORDAZ);
		three(harmony,G,A,F,octave,0.5,CHORDAZ);
		appendTwo(harmony,G,E,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,G,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 22 & 23
	#ifdef DEBUG
	puts("Measure # 22 & 23");
	#endif
		//VOICE
		create(voice,F,octave,1.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,Db,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,F,B/2,octave,0.75,CHORDAZ);
		appendFour(harmony,D,C,B/2,A/2,octave+1,0.25,CHORDAZ);
		append(harmony,G,octave,0.75,CHORDAZ);
		appendArpegio(harmony,F,A,2*Db,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,Db,octave-2,0.125,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
		append(bass,Db,octave,0.25,BASSAZ);
		append(bass,G,octave-3,0.375,BASSAZ);
		append(bass,Db,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,Db,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 24 & 25
	#ifdef DEBUG
	puts("Measure # 24 & 25");
	#endif
		//VOICE
		create(voice,Db,octave,1+0.5/3,VOICEAZ);
		appendTwo(voice,E,C,octave+1,1.0/3,VOICEAZ);
		appendTwo(voice,Db,B/2,octave+1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,F,A,2*Db,octave,1+0.5/3,CHORDAZ);
		two(harmony,E,C,octave+1,1.0/3,CHORDAZ);
		appendTwo(harmony,Db,B/2,octave+1,0.5,CHORDAZ);
		two(harmony,C,A/2,octave+1,1.0/3,CHORDAZ);
		appendTwo(harmony,A,G,octave,0.5,CHORDAZ);
		add();
		cat();
	add();
		//BASS
		create(bass,G,octave-3,0.375,BASSAZ);
		append(bass,Db,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,Db,octave-2,0.25,BASSAZ);
		append(bass,G,octave-3,0.375,BASSAZ);
		append(bass,Db,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,Db,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 26
	#ifdef DEBUG
	puts("Measure # 26");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5/3,VOICEAZ);
		appendDoubleGrace(voice,D,C,B,octave+1,0.5/3,VOICEAZ);
		append(voice,A,octave,0.5/3,VOICEAZ);
		append(voice,G,octave,0.375,VOICEAZ);
		append(voice,F,octave,0.125,VOICEAZ);
		//HARMONY
		create(harmony,C,octave+1,0.5/3,CHORDAZ);
		appendDoubleGrace(harmony,D,C,B/2,octave+1,0.5/3,CHORDAZ);
		append(harmony,A,octave,0.5/3,CHORDAZ);
		append(harmony,G,octave,0.375,CHORDAZ);
		append(harmony,F,octave,0.125,CHORDAZ);
		three(harmony,A,F,G,octave,0.5,CHORDAZ);
		append(harmony,E,octave,0.375,CHORDAZ);
		append(harmony,Db,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,G,octave-3,0.375,BASSAZ);
		append(bass,D,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 27
	#ifdef DEBUG
	puts("Measure # 27");
	#endif
		//VOICE
		create(voice,E,octave,1.0,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave+1,0.75,CHORDAZ);
		appendFour(harmony,G,F,E,D,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 28
	#ifdef DEBUG
	puts("Measure # 28");
	#endif
		//VOICE
		three(voice,C,C,C,octave+1,0.5,VOICEAZ);
		appendTwo(voice,C,B/2,octave+1,0.5,VOICEAZ);
		//HARMONY
		three(harmony,C,C,C,octave+1,0.5,CHORDAZ);
		appendTwo(harmony,C,B/2,octave+1,0.5,CHORDAZ);
		silence(0.5/3);
		appendInterval(harmony,E,G,octave,0.5/3,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.5/3,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 29
	#ifdef DEBUG
	puts("Measure # 29");
	#endif
		//VOICE
		three(voice,D,D,C,octave+1,0.5,VOICEAZ);
		appendTwo(voice,B,A,octave,0.5,VOICEAZ);
		//HARMONY
		three(harmony,D,D,C,octave+1,0.5,CHORDAZ);
		appendTwo(harmony,B,A,octave,0.5,CHORDAZ);
		interval(harmony,E,G,octave,0.5,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 30 & 31
	#ifdef DEBUG
	puts("Measure # 30 & 31");
	#endif
		//VOICE
		doubleGrace(voice,A,B,A,octave,0.25,VOICEAZ);
		append(voice,G,octave,1.75,VOICEAZ);
		//HARMONY
		doubleGrace(harmony,A,B,A,octave,0.25,CHORDAZ);
		append(harmony,G,octave,1.75,CHORDAZ);
		create(harmony,A,octave,0.25,CHORDAZ);
		append(harmony,F,octave,1.75,CHORDAZ);
		add();
		silence(0.25);
		appendTwo(harmony,B,B,octave-1,0.5,CHORDAZ);
		appendThree(harmony,A,B,A,octave,0.25,CHORDAZ);
		appendInterval(harmony,G,B,octave-1,1.0,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,D,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,D,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,D,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,D,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		
	add();
	cat();
	//MEASURE # 32
	#ifdef DEBUG
	puts("Measure # 32");
	#endif
		//VOICE
		three(voice,B,B,B,octave,0.5,VOICEAZ);
		appendTwo(voice,B,A,octave,0.5,VOICEAZ);
		//HARMONY
		three(harmony,B,B,B,octave,0.5,CHORDAZ);
		appendTwo(harmony,B,A,octave,0.5,CHORDAZ);
		interval(harmony,D,F,octave,0.5,CHORDAZ);
		appendInterval(harmony,D,F,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,G,octave-2,0.375,BASSAZ);
		append(bass,D,octave-1,0.125,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
		append(bass,D,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 33
	#ifdef DEBUG
	puts("Measure # 33");
	#endif
		//VOICE
		three(voice,A,G,G,octave,0.5,VOICEAZ);
		appendTwo(voice,G,A,octave,0.5,VOICEAZ);
		//HARMONY
		three(harmony,A,G,G,octave,0.5,CHORDAZ);
		appendTwo(harmony,G,A,octave,0.5,CHORDAZ);
		interval(harmony,B/2,F,octave,0.5,CHORDAZ);
		appendInterval(harmony,B/2,F,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,G,octave-2,0.375,BASSAZ);
		append(bass,D,octave-1,0.125,BASSAZ);
		appendTwo(bass,G,D,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 34 & 35
	#ifdef DEBUG
	puts("Measure # 34 & 35");
	#endif
		//VOICE
		two(voice,G,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,1.75,VOICEAZ);
		//HARMONY
		two(harmony,G,F,octave,0.25,CHORDAZ);
		append(harmony,E,octave,1.75,CHORDAZ);
		two(harmony,E,Db,octave,0.25,CHORDAZ);
		append(harmony,C,octave,1.75,CHORDAZ);
		add();
		silence(0.75);
		appendThree(harmony,A,B,A,octave-1,0.25,CHORDAZ);
		append(harmony,G,octave,1.0,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,C,G/2,octave-1,0.5,BASSAZ);
		append(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,C,G/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 36
	#ifdef DEBUG
	puts("Measure # 36");
	#endif
		//VOICE
		three(voice,C,C,C,octave+1,0.5,VOICEAZ);
		append(voice,C,octave+1,0.375,VOICEAZ);
		append(voice,B,octave,0.125,VOICEAZ);
		//HARMONY
		three(harmony,C,C,C,octave+1,0.5,CHORDAZ);
		append(harmony,C,octave+1,0.375,CHORDAZ);
		append(harmony,B,octave,0.125,CHORDAZ);
		interval(harmony,E,G,octave,0.5,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,C,G/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 37
	#ifdef DEBUG
	puts("Measure # 37");
	#endif
		//VOICE
		three(voice,D,D,C,octave+1,0.5,VOICEAZ);
		appendTwo(voice,B,A,octave,0.5,VOICEAZ);
		//HARMONY
		three(harmony,D,D,C,octave+1,0.5,CHORDAZ);
		appendTwo(harmony,B,A,octave,0.5,CHORDAZ);
		interval(harmony,E,G,octave,0.5,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,C,G/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 38 & 39
	#ifdef DEBUG
	puts("Measure # 38 & 39");
	#endif
		//VOICE
		create(voice,A,octave,0.25,VOICEAZ);
		append(voice,G,octave,1.75,VOICEAZ);
		//HARMONY
		create(harmony,A,octave,0.25,CHORDAZ);
		append(harmony,G,octave,1.75,CHORDAZ);
		interval(harmony,F,B/2,octave,0.75,CHORDAZ);
		appendThree(harmony,A,B,A,octave-1,0.25,CHORDAZ);
		appendChord(harmony,G,B,2*G,octave-1,1.0,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,D,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,D,G/2,octave-1,0.5,BASSAZ);
		append(bass,D,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,D,G/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 40
	#ifdef DEBUG
	puts("Measure # 40");
	#endif
		//VOICE
		three(voice,B,B,B,octave,0.5,VOICEAZ);
		appendTwo(voice,B,A,octave,0.5,VOICEAZ);
		//HARMONY
		three(harmony,B,B,B,octave,0.5,CHORDAZ);
		appendTwo(harmony,B,A,octave,0.5,CHORDAZ);
		interval(harmony,D,G,octave,0.5,CHORDAZ);
		appendInterval(harmony,D,G,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,G,octave-2,0.375,BASSAZ);
		append(bass,D,octave-1,0.125,BASSAZ);
		appendTwo(bass,G,D,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 41
	#ifdef DEBUG
	puts("Measure # 41");
	#endif
		//VOICE
		three(voice,A,G,G,octave,0.5,VOICEAZ);
		appendTwo(voice,G,A,octave,0.5,VOICEAZ);
		//HARMONY
		three(harmony,A,G,G,octave,0.5,CHORDAZ);
		appendTwo(harmony,G,A,octave,0.5,CHORDAZ);
		interval(harmony,B/2,G,octave,0.5,CHORDAZ);
		appendInterval(harmony,B/2,G,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,G,octave-2,0.375,BASSAZ);
		append(bass,D,octave-1,0.125,BASSAZ);
		appendTwo(bass,G,D,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 42 & 43
	#ifdef DEBUG
	puts("Measure # 42 & 43");
	#endif
		//VOICE
		two(voice,G,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.75+0.5/3,VOICEAZ);
		appendTwo(voice,G,G,octave,1.0/3,VOICEAZ);
		appendThree(voice,G,A,Gf,octave,0.5,VOICEAZ);
		//HARMONY
		two(harmony,G,F,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.75+0.5/3,CHORDAZ);
		appendTwo(harmony,G,G,octave,1.0/3,CHORDAZ);
		appendThree(harmony,G,A,Gf,octave,0.5,CHORDAZ);
		two(harmony,E,Db,octave,0.25,CHORDAZ);
		append(harmony,C,octave,0.75+0.5/3,CHORDAZ);
		appendTwo(harmony,E,E,octave,1.0/3,CHORDAZ);
		appendThree(harmony,E,F,Ef,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,C,G/2,octave-1,0.5,BASSAZ);
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,C,G/2,octave-1,0.5,BASSAZ);
		cat();
	add();
	cat();
	//MEASURE # 44
	#ifdef DEBUG
	puts("Measure # 44");
	#endif
		//VOICE
		create(voice,G,octave,1.0,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave,0.75,CHORDAZ);
		appendFour(harmony,G,F,E,D,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,C,G/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 45
	#ifdef DEBUG
	puts("Measure # 45");
	#endif
		//VOICE
		three(voice,0,G,G,octave,0.5,VOICEAZ);
		appendThree(voice,G,G,A,octave,0.5,VOICEAZ);
		//HARMONY
		three(harmony,2*C,G,G,octave,0.5,CHORDAZ);
		appendThree(harmony,G,G,A,octave,0.5,CHORDAZ);
		three(harmony,0,E,E,octave,0.5,CHORDAZ);
		appendThree(harmony,E,E,F,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,C,G/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 46 & 47
	#ifdef DEBUG
	puts("Measure # 46 & 47");
	#endif
		//VOICE
		create(voice,B,octave,0.5,VOICEAZ);
		append(voice,D,octave+1,2.0/3,VOICEAZ);
		appendTwo(voice,E,C,octave+1,1.0/3,VOICEAZ);
		appendThree(voice,D,B/2,C,octave,0.5,VOICEAZ);
		//HARMONY
		create(harmony,B,octave,0.5,CHORDAZ);
		append(harmony,D,octave+1,2.0/3,CHORDAZ);
		appendTwo(harmony,E,C,octave,1.0/3,CHORDAZ);
		appendThree(harmony,D,B/2,C,octave,0.5,CHORDAZ);
		create(harmony,G,octave,0.5,CHORDAZ);
		append(harmony,B,octave,2.0/3,CHORDAZ);
		appendTwo(harmony,C,A/2,octave+1,1.0/3,CHORDAZ);
		appendThree(harmony,B,G,A,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.375,BASSAZ);
		append(bass,G,octave-1,0.125,BASSAZ);
		appendChord(bass,B/2,D,F,octave,0.25,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-2,0.375,BASSAZ);
		append(bass,G,octave-1,0.125,BASSAZ);
		appendChord(bass,B/2,D,F,octave,0.25,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);

	add();
	cat();
	//MEASURE # 48
	#ifdef DEBUG
	puts("Measure # 48");
	#endif
		//VOICE
		three(voice,A,B,2*C,octave,0.5,VOICEAZ);
		append(voice,E,octave+1,0.375,VOICEAZ);
		append(voice,D,octave+1,0.125,VOICEAZ);
		//HARMONY
		three(voice,A,B,2*C,octave,0.5,VOICEAZ);
		append(voice,E,octave+1,0.375,VOICEAZ);
		append(voice,D,octave+1,0.125,VOICEAZ);
		three(voice,F,G,A,octave,0.5,VOICEAZ);
		append(voice,C,octave+1,0.375,VOICEAZ);
		append(voice,B,octave,0.125,VOICEAZ);
		add();
	add();
		//BASS
		interval(bass,G,2*G,octave-2,0.375,BASSAZ);
		append(bass,G,octave-1,0.125,BASSAZ);
		appendChord(bass,B/2,D,F,octave,0.25,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 49
	#ifdef DEBUG
	puts("Measure # 49");
	#endif
		//VOICE
		three(voice,D,E,F,octave,0.5,VOICEAZ);
		append(voice,B,octave,0.375,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		//HARMONY
		three(voice,D,E,F,octave,0.5,VOICEAZ);
		append(voice,B,octave,0.375,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		three(voice,B/2,C,Db,octave,0.5,VOICEAZ);
		append(voice,G,octave,0.375,VOICEAZ);
		append(voice,F,octave,0.125,VOICEAZ);
		add();
	add();
		//BASS
		create(bass,G,octave-2,0.375,BASSAZ);
		append(bass,D,octave-1,0.125,BASSAZ);
		appendTwo(bass,G,G/2,octave-1,0.5,BASSAZ);
	add();
	cat();

	//MEASURE # 50
	#ifdef DEBUG
	puts("Measure # 50");
	#endif
		//VOICE
		create(voice,E,octave,1.0,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave,0.75,CHORDAZ);
		append(harmony,G,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 51
	#ifdef DEBUG
	puts("Measure # 51");
	#endif
		//VOICE
		three(voice,0,G,G,octave,0.5,VOICEAZ);
		appendThree(voice,G,A,Gf,octave,0.5,VOICEAZ);
		//HARMONY
		martelato(harmony,C,octave+1,0.5/3,CHORDAZ);
		appendTwo(harmony,G,G,octave,1.0/3,CHORDAZ);
		appendThree(harmony,G,A,Gf,octave,0.5,CHORDAZ);
		martelato(harmony,E,octave,0.5/3,CHORDAZ);
		appendTwo(harmony,E,F,octave,1.0/3,CHORDAZ);
		appendThree(harmony,E,F,Ds,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 52
	#ifdef DEBUG
	puts("Measure # 52");
	#endif
		//VOICE
		create(voice,G,octave,1.0,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave,0.75,CHORDAZ);
		appendFour(harmony,G,F,E,D,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 53
	#ifdef DEBUG
	puts("Measure # 53");
	#endif
		//VOICE
		three(voice,0,G,G,octave,0.5,VOICEAZ);
		appendThree(voice,G,G,A,octave,0.5,VOICEAZ);
		//HARMONY
		martelato(harmony,C,octave+1,0.5/3,CHORDAZ);
		appendTwo(harmony,G,G,octave,1.0/3,CHORDAZ);
		appendThree(harmony,G,G,A,octave,0.5,CHORDAZ);
		silence(0.5/3);
		appendTwo(harmony,E,E,octave,1.0/3,CHORDAZ);
		appendThree(harmony,E,E,F,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
//TESTED TILL HERE
	//MEASURE # 54 & 55
	#ifdef DEBUG
	puts("Measure # 54 & 55");
	#endif
		//VOICE
		create(voice,B,octave,0.5,VOICEAZ);
		append(voice,D,octave+1,2.0/3,VOICEAZ);
		append(voice,F,octave+1,0.5/2,VOICEAZ);
		append(voice,E,octave+1,0.5/6,VOICEAZ);
		appendThree(voice,D,E,C,octave+1,0.5,VOICEAZ);
		//HARMONY
		create(harmony,B,octave,0.5,CHORDAZ);
		append(harmony,D,octave+1,2.0/3,CHORDAZ);
		append(harmony,F,octave+1,0.5/2,CHORDAZ);
		append(harmony,E,octave+1,0.5/6,CHORDAZ);
		appendThree(harmony,D,E,C,octave+1,0.5,CHORDAZ);

		create(harmony,A,octave,0.5,CHORDAZ);
		append(harmony,B,octave,2.0/3,CHORDAZ);
		append(harmony,Db,octave+1,0.5/2,CHORDAZ);
		append(harmony,C,octave+1,0.5/6,CHORDAZ);
		appendThree(harmony,B,2*C,A,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,G,2*G,octave-2,0.375,BASSAZ);
		append(bass,G,octave-1,0.125,BASSAZ);
		appendChord(bass,B/2,D,F,octave,0.25,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 56
	#ifdef DEBUG
	puts("Measure # 56");
	#endif
		//VOICE
		create(voice,D,octave+1,0.5/3,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ); //Notice that 1/2 + 1/3 + 1/6 = 1
		append(voice,C,octave+1,0.5/6,VOICEAZ);
		append(voice,E,octave+1,1.0/3,VOICEAZ);
		append(voice,D,octave+1,0.5/3,VOICEAZ);
		//HARMONY
		create(harmony,D,octave+1,0.5/3,CHORDAZ);
		append(harmony,B,octave,0.25,CHORDAZ);
		append(harmony,C,octave+1,0.5/6,CHORDAZ);
		append(harmony,E,octave+1,1.0/3,CHORDAZ);
		append(harmony,D,octave+1,0.5/3,CHORDAZ);
		create(harmony,B,octave,0.5/3,CHORDAZ);
		append(harmony,G,octave,0.25,CHORDAZ);
		append(harmony,A,octave,0.5/6,CHORDAZ);
		append(harmony,C,octave+1,1.0/3,CHORDAZ);
		append(harmony,B,octave,0.5/3,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,G,2*G,octave-2,0.375,BASSAZ);
		append(bass,G,octave-1,0.125,BASSAZ);
		appendChord(bass,B/2,D,F,octave,0.25,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 57
	#ifdef DEBUG
	puts("Measure # 57");
	#endif
		//VOICE
		three(voice,D,E,F,octave,0.5,VOICEAZ);
		append(voice,A,octave,1.0/3,VOICEAZ);
		append(voice,G,octave,0.5/3,VOICEAZ);
		//HARMONY
		three(bass,D,E,F,octave,0.5,BASSAZ);
		append(bass,A,octave,1.0/3,BASSAZ);
		append(bass,G,octave,0.5/3,BASSAZ);
		three(bass,B/2,C,D,octave,0.5,BASSAZ);
		append(bass,F,octave,1.0/3,BASSAZ);
		append(bass,E,octave,0.5/3,BASSAZ);
		add();
	add();
		//BASS
		interval(bass,G,2*G,octave-2,0.375,BASSAZ);
		append(bass,G,octave-1,0.125,BASSAZ);
		appendChord(bass,B/2,D,F,octave,0.25,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 58
	#ifdef DEBUG
	puts("Measure # 58");
	#endif
		//VOICE
		create(voice,C,octave,1.0,VOICEAZ);
		//HARMONY
		interval(harmony,E/2,C,octave,0.375,CHORDAZ);
		append(harmony,G,octave-1,0.125,CHORDAZ);
		appendIntervalMartelato(harmony,E/2,C,octave,0.25,CHORDAZ);
		append(harmony,G,octave-1,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-1,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendIntervalMartelato(bass,C,2*C,octave,0.25,BASSAZ);
		append(bass,G,octave,0.25,BASSAZ);
	add();
	cat();
}

void coda(void){
	//MEASURE # 59
	MESSOPIANO;
	#ifdef DEBUG
	puts("Measure # 59");
	#endif
		//VOICE
		create(voice,B,octave,0.375,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,F,B,octave-1,0.375,CHORDAZ);
		append(harmony,G,octave-1,0.125,CHORDAZ);
		appendIntervalMartelato(harmony,F,B,octave-1,0.25,CHORDAZ);
		append(harmony,G,octave-1,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,Db,2*Db,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendIntervalMartelato(bass,Db,2*Db,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	//MEASURE # 60
	#ifdef DEBUG
	puts("Measure # 60");
	#endif
		//VOICE
		four(voice,B,B,B,B,octave,0.5,VOICEAZ);
		appendTwo(voice,B,G,octave,0.5,VOICEAZ);
		//HARMONY
		fourEstacato(harmony,B,B,B,G,octave,0.5,CHORDAZ);
		appendMartelato(harmony,B,octave,0.25,CHORDAZ);
		append(harmony,A,octave,0.25,CHORDAZ);
		create(harmony,F,octave,0.375,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
		appendMartelato(harmony,F,octave,0.25,CHORDAZ);
		append(harmony,G,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,Db,Db,octave,0.375,BASSAZ);
		append(bass,G,octave,0.125,BASSAZ);
		appendIntervalMartelato(bass,Db,Db,octave,0.25,BASSAZ);
		append(bass,G,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 61 & 62
	#ifdef DEBUG
	puts("Measure # 61 & 62");
	#endif
		//VOICE
		create(voice,C,octave,1.75,VOICEAZ);
		//HARMONY
		interval(harmony,E/2,C,octave,1.5,CHORDAZ);
		appendFourChordMartelato(harmony,C,E,G,2*C,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,C,octave-2,0.5,BASSAZ);
		appendChordMarcato(bass,C,G,2*C,octave-2,0.25,BASSAZ);
	add();
	cat();
}

int main(int argc, char **argv){
	tempo=105;
	C=D;
	start();
	repeat();
	cat();
	repeat();
	cat();
	coda();
	cat();
	echo(10,0.3,4);
    appendSilence(2);
	puts("Writing wav file: la paloma.wav");
	exportToWav("La Paloma.wav");
}
