#include "soundlib.h"

#define VOICEAZ 150
#define CHORDAZ 30
#define BASSAZ 90

#define DEBUG 1


double (*voice)(double) = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double) = oldCircleOfRa;

void intro(void);
void coro(void);
void estrofa(void);

short octave;

void song(void){
	coro();
	estrofa();
	cat();
	coro();
	cat();
	estrofa();
	cat();
	coro();
	cat();
	echo(10,0.25,4);
}

void intro(void){
	FORTE;
	//MEASURE # 1
	#ifdef DEBUG
	puts("Measure # 1");
	#endif
		//HARMONY
		chord(harmony,C,E,G,octave,0.75,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave,0.1875,CHORDAZ);
		appendChord(harmony,Db,F,A/2,octave,0.0625,CHORDAZ);
		//BASS
		interval(bass,C/2,C,octave-1,0.25,BASSAZ);
		appendInterval(bass,B/2,B,octave-2,0.25,BASSAZ);
		appendInterval(bass,A/2,A,octave-2,0.25,BASSAZ);
		appendInterval(bass,G/2,G,octave-2,0.25,BASSAZ);
	add();
	//MEASURE # 2
	#ifdef DEBUG
	puts("Measure # 2");
	#endif
		//HARMONY
		chord(harmony,C,E,G,octave,0.75,CHORDAZ);
		append(harmony,A,octave,0.1875,CHORDAZ);
		append(harmony,B,octave,0.0625,CHORDAZ);
		//BASS
		interval(bass,C/2,C,octave-1,0.25,BASSAZ);
		appendInterval(bass,B/2,B,octave-2,0.25,BASSAZ);
		appendInterval(bass,A/2,A,octave-2,0.25,BASSAZ);
		appendInterval(bass,G/2,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 3
	#ifdef DEBUG
	puts("Measure # 3");
	#endif
		//HARMONY
		fourChord(harmony,C,E,G,2*C,octave,0.75,CHORDAZ);
		appendChord(harmony,C,E,G/2,octave,0.25,CHORDAZ);
		//BASS
		interval(bass,C/2,C,octave-1,0.25,BASSAZ);
		appendInterval(bass,B/2,B,octave-2,0.25,BASSAZ);
		appendInterval(bass,A/2,A,octave-2,0.25,BASSAZ);
		appendInterval(bass,G/2,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 4
	#ifdef DEBUG
	puts("Measure # 4");
	#endif
		//VOICE
		chord(voice,B/2,F,G,octave,0.75,VOICEAZ);
		//HARMONY
		interval(harmony,D,D/2,octave-1,0.25,CHORDAZ);
		appendInterval(harmony,G,G/2,octave-2,0.25,CHORDAZ);
		appendInterval(harmony,G,G/2,octave-2,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,D,D/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,G,G/2,octave-2,0.25,BASSAZ);
		appendInterval(bass,G,G/2,octave-2,0.25,BASSAZ);
	add();
	cat();
}

void coro(void){
	PIANO;
	//MEASURE # 4
	#ifdef DEBUG
	puts("Measure # 4 (continued)");
	#endif
		//VOICE
		create(voice,C,octave,0.1875,VOICEAZ);
		append(voice,E,octave,0.0625,VOICEAZ);
		//HARMONY
		create(harmony,C,octave,0.1875,CHORDAZ);
		append(harmony,E,octave,0.0625,CHORDAZ);
	add();
	//MEASURE # 5
	#ifdef DEBUG
	puts("Measure # 5");
	#endif
		//VOICE
		create(voice,G,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.1875,VOICEAZ);
		append(voice,G,octave,0.0625,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		appendThree(voice,G,A,B,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,0.25,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.1875,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.0625,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.25,CHORDAZ);
		interval(harmony,C,E,octave,0.25,CHORDAZ);
		three(harmony,G,A,B,octave,0.25,CHORDAZ);
		add();
		cat();
	add();
		//BASS
		interval(bass,C/2,C,octave-1,0.25,BASSAZ);
		appendIntervalEstacato(bass,B/2,B,octave-2,0.25,BASSAZ);
		appendIntervalEstacato(bass,A/2,A,octave-2,0.25,BASSAZ);
		appendIntervalEstacato(bass,G/2,G,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 6
	#ifdef DEBUG
	puts("Measure # 6");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.1875,VOICEAZ);
		append(voice,E,octave,0.0625,VOICEAZ);
		//HARMONY
		fourChord(harmony,C,E,G,2*C,octave,0.5,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.25,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.1875,CHORDAZ);
		append(harmony,E,octave,0.0625,CHORDAZ);
	add();
		//BASS
		interval(bass,C/2,C,octave-1,0.25,BASSAZ);
		appendIntervalEstacato(bass,B/2,B,octave-2,0.25,BASSAZ);
		appendIntervalEstacato(bass,A/2,A,octave-2,0.25,BASSAZ);
		appendIntervalEstacato(bass,G/2,G,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 7
	#ifdef DEBUG
	puts("Measure # 7");
	#endif
		//VOICE
		create(voice,D,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.1875,VOICEAZ);
		append(voice,E,octave,0.0625,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.1875,VOICEAZ);
		append(voice,G,octave,0.0625,VOICEAZ);
		//HARMONY
		chord(harmony,F,B,2*D,octave-1,0.25,CHORDAZ);
		appendChord(harmony,G,B,2*E,octave-1,0.1875,CHORDAZ);
		appendChord(harmony,G,B,2*E,octave-1,0.0625,CHORDAZ);
		appendChord(harmony,A/2,C,A,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,D,G,octave,0.1875,CHORDAZ);
		append(harmony,G,octave,0.0625,CHORDAZ);
	add();
		//BASS
		interval(bass,G,G/2,octave-2,0.25,BASSAZ);
		append(bass,D,octave-2,0.25,BASSAZ);
		appendInterval(bass,G,G/2,octave-2,0.25,BASSAZ);
		appendInterval(bass,G,G/2,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 8
	#ifdef DEBUG
	puts("Measure # 8");
	#endif
		//VOICE
		create(voice,E,octave,0.1875,VOICEAZ);
		append(voice,D,octave,0.0625,VOICEAZ);
		append(voice,C,octave,0.5,VOICEAZ);
		append(voice,C,octave+1,0.1875,VOICEAZ);
		append(voice,C,octave+1,0.0625,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave,0.1875,CHORDAZ);
		appendInterval(harmony,G/2,D,octave,0.0625,CHORDAZ);
		appendInterval(harmony,E/2,E,octave,0.5,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.1875,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.0625,CHORDAZ);
	add();
		//BASS
		interval(bass,C,C/2,octave-1,0.25,BASSAZ);
		append(bass,G,octave,0.25,BASSAZ);
		append(bass,C,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 9
	#ifdef DEBUG
	puts("Measure # 9");
	#endif
		//VOICE
		create(voice,B,octave,0.25,VOICEAZ);
		append(voice,Bf,octave,0.1875,VOICEAZ);
		append(voice,Bf,octave,0.0625,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		append(voice,Af,octave,0.1875,VOICEAZ);
		append(voice,Af,octave,0.0625,VOICEAZ);
		//HARMONY
		fourChord(harmony,B/2,E,Af,B,octave,0.25,CHORDAZ);
		appendFourChord(harmony,Bf/2,D,G,Bf,octave,0.1875,CHORDAZ);
		appendFourChord(harmony,Bf/2,D,G,Bf,octave,0.0625,CHORDAZ);
		appendFourChord(harmony,A/2,D,Gf,A,octave,0.25,CHORDAZ);
		appendFourChord(harmony,Af/2,C,F,Af,octave,0.1875,CHORDAZ);
		appendFourChord(harmony,Af/2,C,F,Af,octave,0.0625,CHORDAZ);
	add();
		//BASS
		interval(bass,E,E/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,D,G/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,D,D/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,F/2,C,octave-1,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 10
	#ifdef DEBUG
	puts("Measure # 10");
	#endif
		//VOICE
		create(voice,G,octave,0.25,VOICEAZ);
		append(voice,C,octave+1,0.5,VOICEAZ);
		append(voice,A,octave,0.1875,VOICEAZ);
		append(voice,B,octave,0.0625,VOICEAZ);
		//HARMONY
		fourChord(harmony,G/2,C,E,G,octave,0.25,CHORDAZ);
		appendFourChord(harmony,C,E,G,2*C,octave+1,0.5,CHORDAZ);
		interval(harmony,C,Ds,octave,0.25,CHORDAZ);
		create(harmony,A,octave,0.1875,CHORDAZ);
		append(harmony,B,octave,0.0625,CHORDAZ);
		add();
		cat();
	add();
		//BASS
		interval(bass,C,C/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,B,B/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,A,A/2,octave-1,0.25,BASSAZ);
		append(bass,Gf,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 11
	#ifdef DEBUG
	puts("Measure # 11");
	#endif
		//VOICE
		create(voice,C,octave+1,0.25,VOICEAZ);
		append(voice,E,octave,0.1875,VOICEAZ);
		append(voice,A,octave,0.0625,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		appendThree(voice,F,E,D,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,2*C,octave,0.25,CHORDAZ);
		interval(harmony,Bf/2,Cs,octave,0.25,CHORDAZ);
		create(harmony,E,octave,0.1875,CHORDAZ);
		append(harmony,A,octave,0.0625,CHORDAZ);
		add();
		cat();
		appendChord(harmony,B/2,D,G,octave,0.25,CHORDAZ);
		appendChord(harmony,A,B,2*F,octave-1,0.25/3,CHORDAZ);
		appendChord(harmony,G,B,2*E,octave-1,0.25/3,CHORDAZ);
		appendChord(harmony,F,B,2*D,octave-1,0.25/3,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 12
	#ifdef DEBUG
	puts("Measure # 12");
	#endif
		//VOICE
		create(voice,C,octave,0.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,E,octave,0.1875,VOICEAZ);
		append(voice,G,octave,0.0625,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave-1,0.5,CHORDAZ);
		appendSilence(0.25);
		appendChord(harmony,G/2,C,E,octave,0.1875,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.0625,CHORDAZ);
	add();
		//BASS
		interval(bass,E,E/2,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,C,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 13
	#ifdef DEBUG
	puts("Measure # 13");
	#endif
		//VOICE
		create(voice,C,octave+1,0.25,VOICEAZ);
		append(voice,C,octave+1,0.1875,VOICEAZ);
		append(voice,C,octave+1,0.0625,VOICEAZ);
		append(voice,C,octave+1,0.1875,VOICEAZ);
		append(voice,B,octave,0.0625,VOICEAZ);
		append(voice,C,octave+1,0.1875,VOICEAZ);
		append(voice,D,octave+1,0.0625,VOICEAZ);
		//HARMONY
		fourChord(harmony,C,E,G,2*C,octave,0.25,CHORDAZ);
		appendFourChord(harmony,C,E,G,2*C,octave,0.1875,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.0625,CHORDAZ);
		appendFourChord(harmony,C,E,G,2*C,octave,0.1875,CHORDAZ);
		appendInterval(harmony,B/2,B,octave,0.0625,CHORDAZ);
		appendFourChord(harmony,C,E,G,2*C,octave,0.1875,CHORDAZ);
		appendInterval(harmony,D,2*D,octave,0.0625,CHORDAZ);
	add();
		//BASS
		interval(bass,C/2,C,octave-1,0.25,BASSAZ);
		appendInterval(bass,B/2,B,octave-2,0.25,BASSAZ);
		appendInterval(bass,A/2,A,octave-2,0.25,BASSAZ);
		appendInterval(bass,G/2,G,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 14
	#ifdef DEBUG
	puts("Measure # 14");
	#endif
		//VOICE
		create(voice,E,octave+1,0.375,VOICEAZ);
		append(voice,D,octave+1,0.125,VOICEAZ);
		append(voice,C,octave+1,0.25,VOICEAZ);
		append(voice,C,octave+1,0.1875,VOICEAZ);
		append(voice,C,octave+1,0.0625,VOICEAZ);
		//HARMONY
		chord(harmony,E,B,2*E,octave,0.375,CHORDAZ);
		appendChord(harmony,E,B,2*D,octave,0.125,CHORDAZ);
		appendChord(harmony,E,A,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,C,A,2*C,octave,0.1875,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.0625,CHORDAZ);
	add();
		//BASS
		interval(bass,Gs,Gs/2,octave-2,0.25,BASSAZ);
		appendInterval(bass,E,E/2,octave-2,0.25,BASSAZ);
		appendInterval(bass,A/2,A,octave-2,0.25,BASSAZ);
		appendInterval(bass,Af/2,Af,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 15
	#ifdef DEBUG
	puts("Measure # 15");
	#endif
		//VOICE
		create(voice,C,octave+1,0.25,VOICEAZ);
		append(voice,E,octave,0.1875,VOICEAZ);
		append(voice,A,octave,0.0625,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		appendThree(voice,F,E,D,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,Bf/2,Cs,E,octave,0.1875,CHORDAZ);
		append(harmony,A,octave,0.0625,CHORDAZ);
		appendChord(harmony,B/2,D,G,octave,0.25,CHORDAZ);
		appendChord(harmony,A,Bf,2*F,octave-1,0.25/3,CHORDAZ);
		appendChord(harmony,G,B,2*E,octave-1,0.25/3,CHORDAZ);
		appendChord(harmony,F,B,2*Db,octave,0.25/3,CHORDAZ);
	add();
		//BASS
		interval(bass,G,G/2,octave-2,0.25,BASSAZ);
		appendInterval(bass,G,G/2,octave-2,0.25,BASSAZ);
		appendInterval(bass,G,G/2,octave-2,0.25,BASSAZ);
		appendInterval(bass,G,G/2,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 16
	#ifdef DEBUG
	puts("Measure # 16");
	#endif
		//VOICE
		two(voice,C,2*C,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave-1,0.25,CHORDAZ);
		appendFourChord(harmony,C,E,G,2*C,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,C/2,octave-1,0.25,BASSAZ);
		append(bass,C,octave-2,0.25,BASSAZ);
	add();
	cat();
}

void estrofa(void){
	//MEASURE # 16
	#ifdef DEBUG
	puts("Measure # 16 (continued)");
	#endif
		//VOICE
		create(voice,G,octave,0.1875,VOICEAZ);
		append(voice,G,octave,0.0625,VOICEAZ);
		//HARMONY
		create(harmony,G,octave,0.1875,CHORDAZ);
		append(harmony,G,octave,0.0625,CHORDAZ);
	add();
	//MEASURE # 17
	#ifdef DEBUG
	puts("Measure # 17");
	#endif
		//VOICE
		create(voice,G,octave,0.25,VOICEAZ);
		appendSix(voice,G,2*D,2*C,B,A,B,octave,0.75,VOICEAZ);
		//HARMONY
		create(harmony,G,octave,0.375,CHORDAZ);
		interval(harmony,B/2,F,octave,0.25,CHORDAZ);
		appendInterval(harmony,B/2,F,octave,0.125,CHORDAZ);
		add();
		appendInterval(harmony,B,2*D,octave,0.125,CHORDAZ);

		four(harmony,2*C,B,A,B,octave,0.5,CHORDAZ);
		addFour(harmony,A,G,F,G,octave,0.5,CHORDAZ);
		create(harmony,Db,octave,0.5,CHORDAZ);
		add();
		cat();
	add();
		//BASS
		interval(bass,D,D/2,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 18
	#ifdef DEBUG
	puts("Measure # 18");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.1875,VOICEAZ);
		append(voice,G,octave,0.0625,VOICEAZ);
		//HARMONY
		create(harmony,C,octave,0.5,CHORDAZ);
		chord(harmony,E,C,G,octave,0.25,CHORDAZ);
		appendChord(harmony,E,C,G,octave,0.25,CHORDAZ);
		appendChord(harmony,E,C,G,octave,0.25,CHORDAZ);
		add();
		appendInterval(harmony,C,E,octave,0.1875,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.0625,CHORDAZ);
	add();
		//BASS
		interval(bass,D,D/2,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 19
	#ifdef DEBUG
	puts("Measure # 19");
	#endif
		//VOICE
		create(voice,G,octave,0.1875,VOICEAZ);
		append(voice,F,octave,0.0625,VOICEAZ);
		append(voice,F,octave,0.1875,VOICEAZ);
		append(voice,A,octave,0.0625,VOICEAZ);
		append(voice,A,octave,0.1875,VOICEAZ);
		append(voice,G,octave,0.0625,VOICEAZ);
		append(voice,D,octave,0.1875,VOICEAZ);
		append(voice,A,octave,0.0625,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave,0.1875,CHORDAZ);
		appendInterval(harmony,D,F,octave,0.0625,CHORDAZ);
		appendInterval(harmony,D,F,octave,0.1875,CHORDAZ);
		appendInterval(harmony,F,A,octave,0.0625,CHORDAZ);
		appendInterval(harmony,F,A,octave,0.1875,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.0625,CHORDAZ);
		appendInterval(harmony,G,B,octave,0.1875,CHORDAZ);
		appendInterval(harmony,F,A,octave,0.0625,CHORDAZ);
		create(harmony,B,octave-1,1.0,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,D,D/2,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 20
	#ifdef DEBUG
	puts("Measure # 20");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,F,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.1875,VOICEAZ);
		append(voice,G,octave,0.0625,VOICEAZ);
		//HARMONY
		interval(harmony,F,G,octave,0.375,CHORDAZ);
		appendInterval(harmony,Db,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.1875,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.0625,CHORDAZ);
		create(harmony,B,octave-1,0.5,CHORDAZ);
		append(harmony,G,octave-1,0.25,CHORDAZ);
		add();
	add();
		//BASS
		three(bass,G,E,A/2,octave-2,0.75,BASSAZ);
	add();
	cat();

	//MEASURE # 21
	#ifdef DEBUG
	puts("Measure # 21");
	#endif
		//VOICE
		create(voice,G,octave,0.25,VOICEAZ);
		appendSix(voice,G,2*E,2*D,B,A,B,octave,0.75,VOICEAZ);
		//HARMONY
		create(harmony,G,octave,0.375,CHORDAZ);
		interval(harmony,B/2,F,octave,0.25,CHORDAZ);
		appendInterval(harmony,B/2,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,B,2*D,octave,0.125,CHORDAZ);
		add();
		four(harmony,2*C,B,A,B,octave,0.5,CHORDAZ);
		addFour(harmony,A,G,F,G,octave,0.5,CHORDAZ);
		create(harmony,Db,octave,0.5,CHORDAZ);
		add();
		cat();
	add();
		//BASS
		interval(bass,D,D/2,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 22
	#ifdef DEBUG
	puts("Measure # 22");
	#endif
		//VOICE
		two(voice,2*C,G,octave,0.25,VOICEAZ);
		append(voice,E,octave+1,0.5,VOICEAZ);
		appendTwo(voice,D,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		silence(0.25);
		append(harmony,E,octave+1,0.5,CHORDAZ);
		chord(harmony,E,G,2*C,octave,0.125,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave,0.1875,CHORDAZ);
		appendChord(harmony,E,Gs,2*D,octave,0.0625,CHORDAZ);
		appendChord(harmony,E,A,2*C,octave,0.25,CHORDAZ);
		add();
		two(harmony,D,C,octave+1,0.25,CHORDAZ);
		addTwo(harmony,B,A,octave,0.25,CHORDAZ);
		create(harmony,E,octave,0.25,CHORDAZ);
		add();
		cat();
	add();
		//BASS
		interval(bass,C,C/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,C,C/2,octave-1,0.1875,BASSAZ);
		appendInterval(bass,B,B/2,octave-2,0.0625,BASSAZ);
		appendInterval(bass,A,A/2,octave-2,0.25,BASSAZ);
		appendInterval(bass,A,A/2,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 23
	#ifdef DEBUG
	puts("Measure # 23");
	#endif
		//VOICE
		create(voice,B,octave,0.125,VOICEAZ);
		appendTwo(voice,2*C,B,octave,0.125,VOICEAZ);
		append(voice,As,octave,0.125,VOICEAZ);
		append(voice,B,octave,0.125,VOICEAZ);
		append(voice,D,octave+1,0.25,VOICEAZ);
		append(voice,C,octave,0.1875,VOICEAZ);
		append(voice,A,octave,0.0625,VOICEAZ);
		//HARMONY
		create(harmony,B,octave,0.125,CHORDAZ);
		appendTwo(harmony,2*C,B,octave,0.125,CHORDAZ);
		append(harmony,As,octave,0.125,CHORDAZ);
		append(harmony,B,octave,0.125,CHORDAZ);
		append(harmony,D,octave+1,0.25,CHORDAZ);
		append(harmony,C,octave,0.1875,CHORDAZ);
		append(harmony,A,octave,0.0625,CHORDAZ);
		interval(harmony,D,G,octave,0.5,CHORDAZ);
		appendInterval(harmony,D,As,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		two(bass,D,D/2,octave-1,1.0,BASSAZ);

	add();
	cat();
	//MEASURE # 24
	#ifdef DEBUG
	puts("Measure # 24");
	#endif
		//VOICE
		create(voice,G,octave,0.25,VOICEAZ);
		appendSilence(0.5);
		append(voice,G,octave,0.1875,VOICEAZ);
		append(voice,G,octave,0.0625,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,D,G,octave,0.75,CHORDAZ);
		append(harmony,G,octave,0.1875,CHORDAZ);
		append(harmony,G,octave,0.0625,CHORDAZ);
	add();
		//BASS
		three(bass,G,G/2,G/2,octave-2,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 25
	#ifdef DEBUG
	puts("Measure # 25");
	#endif
		//VOICE
		create(voice,G,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.1875,VOICEAZ);
		append(voice,G,octave,0.0625,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.1875,VOICEAZ);
		append(voice,Af,octave,0.0625,VOICEAZ);
		//HARMONY
		create(harmony,G,octave,0.25,CHORDAZ);
		append(harmony,G,octave,0.1875,CHORDAZ);
		append(harmony,G,octave,0.0625,CHORDAZ);
		append(harmony,G,octave,0.25,CHORDAZ);
		append(harmony,G,octave,0.1875,CHORDAZ);
		append(harmony,Af,octave,0.0625,CHORDAZ);
		interval(harmony,Bf/2,Ef,octave,0.25,CHORDAZ);
		appendInterval(harmony,Bf/2,Ef,octave,0.25,CHORDAZ);
		appendInterval(harmony,Bf/2,Ef,octave,0.25,CHORDAZ);
		appendInterval(harmony,Bf/2,Ef,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,Ef,Ef/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,D,D/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,C,C/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,Bf,Bf/2,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 26
	#ifdef DEBUG
	puts("Measure # 26");
	#endif
		//VOICE
		create(voice,Bf,octave,0.25,VOICEAZ);
		append(voice,Ef,octave+1,0.5,VOICEAZ);
		append(voice,G,octave,0.1875,VOICEAZ);
		append(voice,Bf,octave,0.0625,VOICEAZ);
		//HARMONY
		chord(harmony,Ef,G,Bf,octave,0.25,CHORDAZ);
		appendFourChord(harmony,Ef,G,Bf,2*Ef,octave,0.5,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.1875,CHORDAZ);
		appendInterval(harmony,G,Bf,octave,0.0625,CHORDAZ);
	add();
		//BASS
		interval(bass,Ef,Ef/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,D,D/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,C,C/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,Bf,Bf/2,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 27
	#ifdef DEBUG
	puts("Measure # 27");
	#endif
		//VOICE
		create(voice,Bf,octave,0.1875,VOICEAZ);
		append(voice,Af,octave,0.0675,VOICEAZ);
		append(voice,Af,octave,0.1875,VOICEAZ);
		append(voice,C,octave+1,0.0675,VOICEAZ);
		append(voice,C,octave+1,0.1875,VOICEAZ);
		append(voice,B,octave,0.0675,VOICEAZ);
		append(voice,D,octave+1,0.1875,VOICEAZ);
		append(voice,C,octave+1,0.0675,VOICEAZ);
		//HARMONY
		create(harmony,Bf,octave,0.1875,CHORDAZ);
		append(harmony,Af,octave,0.0675,CHORDAZ);
		append(harmony,Af,octave,0.1875,CHORDAZ);
		append(harmony,C,octave+1,0.0675,CHORDAZ);
		append(harmony,C,octave+1,0.1875,CHORDAZ);
		append(harmony,B,octave,0.0675,CHORDAZ);
		append(harmony,D,octave+1,0.1875,CHORDAZ);
		append(harmony,C,octave+1,0.0675,CHORDAZ);
		create(harmony,G,octave,0.1875,CHORDAZ);
		append(harmony,F,octave,0.0675,CHORDAZ);
		append(harmony,F,octave,0.1875,CHORDAZ);
		append(harmony,Af,octave+1,0.0675,CHORDAZ);
		append(harmony,Af,octave+1,0.1875,CHORDAZ);
		append(harmony,G,octave,0.0675,CHORDAZ);
		append(harmony,Bf,octave+1,0.1875,CHORDAZ);
		append(harmony,Af,octave+1,0.0675,CHORDAZ);
		add();
		create(harmony,D,octave,1.0,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,F,F/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,Bf,Bf/2,octave-2,0.25,BASSAZ);
		appendInterval(bass,F,F/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,Bf,Bf/2,octave-2,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 28
	#ifdef DEBUG
	puts("Measure # 28");
	#endif
		//VOICE
		create(voice,Bf,octave,0.375,VOICEAZ);
		append(voice,Af,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.1875,VOICEAZ);
		append(voice,G,octave,0.0625,VOICEAZ);
		//HARMONY
		create(harmony,Bf,octave,0.375,CHORDAZ);
		append(harmony,Af,octave,0.125,CHORDAZ);
		append(harmony,G,octave,0.25,CHORDAZ);
		append(harmony,G,octave,0.1875,CHORDAZ);
		append(harmony,G,octave,0.0625,CHORDAZ);
		create(harmony,G,octave,0.375,CHORDAZ);
		append(harmony,F,octave,0.125,CHORDAZ);
		append(harmony,Ef,octave,0.25,CHORDAZ);
		add();
		create(harmony,Bf,octave-1,0.5,CHORDAZ);
		append(harmony,Bf,octave-1,0.25,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,Bf,Bf/2,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,C/2,octave-1,0.125,BASSAZ);
		appendInterval(bass,D,D/2,octave-1,0.125,BASSAZ);
		appendInterval(bass,Ef,Ef/2,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 29
	#ifdef DEBUG
	puts("Measure # 29");
	#endif
		//VOICE
		four(voice,Af,G,G,G,octave,0.5,VOICEAZ);
		appendFour(voice,Af,G,G,G,octave,0.5,VOICEAZ);
		//HARMONY
		four(harmony,Af,G,G,G,octave,0.5,CHORDAZ);
		appendFour(harmony,Af,G,G,G,octave,0.5,CHORDAZ);
		interval(harmony,B/2,F,octave,0.25,CHORDAZ);
		appendInterval(harmony,B/2,F,octave,0.25,CHORDAZ);
		appendInterval(harmony,B/2,F,octave,0.25,CHORDAZ);
		appendInterval(harmony,B/2,F,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,D,D/2,octave-1,0.25,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
		appendInterval(bass,D,D/2,octave-1,0.25,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 30
	#ifdef DEBUG
	puts("Measure # 30");
	#endif
		//VOICE
		create(voice,C,octave+1,0.375,VOICEAZ);
		append(voice,D,octave+1,0.125,VOICEAZ);
		append(voice,Ef,octave+1,0.25,VOICEAZ);
		append(voice,C,octave+1,0.1875,VOICEAZ);
		append(voice,C,octave+1,0.0625,VOICEAZ);
		//HARMONY
		fourChord(harmony,C,Ef,G,2*C,octave,0.375,CHORDAZ);
		appendChord(harmony,D,G,2*D,octave,0.125,CHORDAZ);
		appendChord(harmony,Ef,G,2*Ef,octave,0.25,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.1875,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.0625,CHORDAZ);
	add();
		//BASS
		interval(bass,Ef,Ef/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,D,D/2,octave,0.125,BASSAZ);
		appendInterval(bass,C,C/2,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 31
	#ifdef DEBUG
	puts("Measure # 31");
	#endif
		//VOICE
		create(voice,C,octave+1,0.25,VOICEAZ);
		append(voice,C,octave+1,0.1875,VOICEAZ);
		append(voice,C,octave+1,0.0625,VOICEAZ);
		append(voice,D,octave+1,0.25,VOICEAZ);
		append(voice,C,octave+1,0.1875,VOICEAZ);
		append(voice,C,octave+1,0.0625,VOICEAZ);
		//HARMONY
		fourChord(harmony,C,Ef,Af,2*C,octave,0.25,CHORDAZ);
		appendFourChord(harmony,C,Ef,Af,2*C,octave,0.1875,CHORDAZ);
		appendFourChord(harmony,C,Ef,Af,2*C,octave,0.0625,CHORDAZ);
		appendFourChord(harmony,D,Ef,Af,2*D,octave,0.25,CHORDAZ);
		appendFourChord(harmony,C,Ef,Af,2*C,octave,0.1875,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.0625,CHORDAZ);
	add();
		//BASS
		interval(bass,Af,Af/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,G,G/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,E,E/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,Ef,Ef/2,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 32
	#ifdef DEBUG
	puts("Measure # 32");
	#endif
		//VOICE
		create(voice,G,octave,0.25,VOICEAZ);
		appendSilence(0.5);
		appendTwo(voice,D,D,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,D,G,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,G,B,octave,0.125,CHORDAZ);
		appendChord(harmony,B/2,G,B,octave,0.125,CHORDAZ);
		appendChord(harmony,C,G,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,C,G,2*C,octave,0.125,CHORDAZ);
		appendFourChord(harmony,D,F,B,2*D,octave,0.125,CHORDAZ);
		appendFourChord(harmony,D,F,B,2*D,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,G,G/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,F,F/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,Ef,Ef/2,octave,0.25,BASSAZ);
		appendInterval(bass,D,D/2,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 33
	#ifdef DEBUG
	puts("Measure # 33");
	#endif
		//VOICE
		four(voice,Ef,C,B/2,C,octave+1,0.5,VOICEAZ);
		append(voice,D,octave+1,0.25,VOICEAZ);
		append(voice,C,octave+1,0.1875,VOICEAZ);
		append(voice,C,octave,0.0625,VOICEAZ);
		//HARMONY
		fourChord(harmony,Ef,G,2*C,Ef,octave,0.125,CHORDAZ);
		append(harmony,C,octave+1,0.125,CHORDAZ);
		appendChord(harmony,Ef,G,B,octave,0.125,CHORDAZ);
		append(harmony,C,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,D,Fs,2*C,2*D,octave,0.25,CHORDAZ);
		appendChord(harmony,C,Fs,2*C,octave,0.1875,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.0625,CHORDAZ);
	add();
		//BASS
		interval(bass,C,C/2,octave,0.5,BASSAZ);
		appendInterval(bass,A,A/2,octave-2,0.25,BASSAZ);
		appendInterval(bass,Af,Af/2,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 34
	#ifdef DEBUG
	puts("Measure # 34");
	#endif
		//VOICE
		create(voice,G,octave,0.75,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,D,G,octave,0.75,CHORDAZ);
	add();
		//BASS
		interval(bass,G,G/2,octave-2,0.25,BASSAZ);
		append(bass,D,octave,0.25,BASSAZ);
		append(bass,G,octave-3,0.25,BASSAZ);
	add();
	cat();
}



int main(int argc, char **argv){
	tempo=120;
	C = Ef;
	song();
	echo(10,0.3,4);
    appendSilence(2);
	puts("himno nacional mexicano.wav");
	exportToWav("Himno Nacional Mexicano.wav");
}
