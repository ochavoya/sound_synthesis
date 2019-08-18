#include "soundlib.h"

#define VOICEAZ 150
#define CHORDAZ 30
#define BASSAZ 90

#define DEBUG 1


double (*voice)(double) =esoteric;
double (*harmony)(double) = circleOfRa;
double (*bass)(double) = esoteric;


short octave = 0;

void intro(void);
void introRepeat(short);
void chorus(short);

void intro(void){
	//MEASURE # 1
	DOUBLEFORTE;
	#ifdef DEBUG
	puts("Measure # 1");
	#endif
		//HARMONY
		interval(harmony,E,G,octave,0.5,CHORDAZ);
		appendChord(harmony,B/2,E,G,octave,0.375,CHORDAZ);
		appendChord(harmony,B/2,E,G,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.5,BASSAZ);
		appendChord(bass,B/2,E,G,octave-1,0.375,BASSAZ);
		appendChord(bass,B/2,E,G,octave-1,0.125,BASSAZ);
	add();
	//MEASURE # 2
	#ifdef DEBUG
	puts("Measure # 2");
	#endif
		//HARMONY
		four(harmony,G,A,B,2*C,octave,1.0,CHORDAZ);
		create(harmony,E,octave,0.25,CHORDAZ);
		add();
		//BASS
		chord(bass,G/2,E,G,octave-1,0.5,BASSAZ);
		appendChord(bass,G/2,E,G,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 3 & 4
	#ifdef DEBUG
	puts("Measure # 3 & 4");
	#endif
		//HARMONY
		interval(harmony,F,A,octave,0.5,CHORDAZ);
		appendInterval(harmony,F,2*F,octave,4*0.5/3,CHORDAZ);
		appendTwo(harmony,E,D,octave+1,2*0.5/3,CHORDAZ);
		appendThree(harmony,2*C,B,A,octave,0.5,CHORDAZ);
		//BASS
		chord(bass,D,F,A,octave-1,0.5,BASSAZ);
		appendChord(bass,Cs,F,A,octave-1,0.25,BASSAZ);
		appendChord(bass,C,F,A,octave-1,0.25,BASSAZ);
		appendChord(bass,C,F,A,octave-1,0.25,BASSAZ);
		appendChord(bass,B/2,F,A,octave-1,0.25,BASSAZ);
		appendChord(bass,B/2,F,A,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 5
	#ifdef DEBUG
	puts("Measure # 5");
	#endif
		//HARMONY
		three(harmony,G,2*E,2*F,octave,0.5,CHORDAZ);
		addTwo(harmony,0,G,octave+1,1.0/3,CHORDAZ);
		appendThree(harmony,2*C,B,A,octave,0.5,CHORDAZ);
		//BASS
		chordMartelato(bass,G/2,C,E,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		appendChordMartelato(bass,G/2,C,E,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 6
	#ifdef DEBUG
	puts("Measure # 6");
	#endif
		//HARMONY
		three(harmony,B/2,F,G,octave+1,0.5,CHORDAZ);
		addTwo(harmony,0,A,octave+1,1.0/3,CHORDAZ);
		appendThree(harmony,F,E,D,octave,0.5,CHORDAZ);
		//BASS
		chordMartelato(bass,G,B,2*F,octave-2,0.25,BASSAZ);
		appendSilence(0.25);
		appendChordMartelato(bass,G,B,2*F,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 7
	#ifdef DEBUG
	puts("Measure # 7");
	#endif
		//HARMONY
		interval(harmony,E,2*C,octave,0.25,CHORDAZ);
		appendSilence(0.25);
		appendFourChord(harmony,C,E,G,2*C,octave,0.375,CHORDAZ);
		appendFourChord(harmony,C,E,G,2*C,octave,0.125,CHORDAZ);
		//BASS
		interval(bass,C,G,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,C,2*C,octave-2,0.375,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 8
	#ifdef DEBUG
	puts("Measure # 8");
	#endif
		//HARMONY
		fourChordMartelato(harmony,C,E,G,2*C,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		//BASS
		intervalMarcato(bass,C,2*C,octave-2,0.125,BASSAZ);
	add();
	cat();
	PIANO;
		//VOICE
		create(voice,G,octave-1,0.125,VOICEAZ);
		append(voice,C,octave,0.375,VOICEAZ);
		append(voice,D,octave,0.125,VOICEAZ);
		//HARMONY
		create(harmony,G,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,E,2*C,octave-1,0.375,CHORDAZ);
		appendInterval(harmony,G,2*D,octave-1,0.125,CHORDAZ);
	add();
	cat();
	introRepeat(0);
	cat();
	introRepeat(1);
	cat();
}

void introRepeat(short end){
	//MEASURE # 9
	#ifdef DEBUG
	puts("Measure # 9");
	#endif
		//VOICE
		create(voice,E,octave,0.875,VOICEAZ);
		append(voice,D,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave,0.875,CHORDAZ);
		append(harmony,D,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,E,G,octave-1,0.5,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	//MEASURE # 10
	#ifdef DEBUG
	puts("Measure # 10");
	#endif
		//VOICE
		four(voice,E,F,G,A,octave,1.0,VOICEAZ);
		//HARMONY
		four(harmony,E,F,G,A,octave,1.0,CHORDAZ);
		addFour(harmony,C,Db,E,F,octave,1.0,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendChord(bass,E,G,2*C,octave-1,0.5,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 11
	#ifdef DEBUG
	puts("Measure # 11");
	#endif
		//VOICE
		create(voice,A,octave,0.625,VOICEAZ);
		appendThree(voice,G,F,E,octave,0.375,VOICEAZ);
		//HARMONY
		interval(harmony,F,A,octave,0.625,CHORDAZ);
		three(harmony,G,F,E,octave,0.375,CHORDAZ);
		addThree(harmony,E,Db,C,octave,0.375,CHORDAZ);
		cat();
	add();
		//BASS
		create(bass,D,octave-2,0.25,BASSAZ);
		appendChord(bass,F,G,B,octave-1,0.5,BASSAZ);
		append(bass,G,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 12
	#ifdef DEBUG
	puts("Measure # 12");
	#endif
		//VOICE
		create(voice,D,octave,0.375,VOICEAZ);
		append(voice,G,octave-1,0.125,VOICEAZ);
		append(voice,C,octave,0.375,VOICEAZ);
		append(voice,D,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,B,2*D,octave-1,0.375,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,2*C,octave-1,0.375,CHORDAZ);
		appendInterval(harmony,G,2*D,octave-1,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,D,F,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 13
	#ifdef DEBUG
	puts("Measure # 13");
	#endif
		//VOICE
		create(voice,E,octave,0.75,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave,0.75,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,E,G,octave-1,0.5,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 14
	#ifdef DEBUG
	puts("Measure # 14");
	#endif
		//VOICE
		four(voice,Gf,G,A,G,octave,1.0,VOICEAZ);
		//HARMONY
		four(harmony,Gf,G,A,G,octave,1.0,CHORDAZ);
		addFour(harmony,Ef,E,F,E,octave,1.0,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendChord(bass,E,G,B,octave-1,0.5,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 15
	#ifdef DEBUG
	puts("Measure # 15");
	#endif
		//VOICE
		create(voice,D,octave,0.75,VOICEAZ);
		appendTwo(voice,F,E,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,B,2*D,octave-1,0.75,CHORDAZ);
		interval(harmony,D,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		cat();
	add();
		//BASS
		interval(bass,D,F,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		appendSilence(0.25);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 16
	#ifdef DEBUG
	puts("Measure # 16");
	#endif
		//VOICE
		create(voice,D,octave,0.25,VOICEAZ);
		appendSilence(0.125);
		append(voice,G,octave-1,0.125,VOICEAZ);
		append(voice,C,octave,0.375,VOICEAZ);
		append(voice,D,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,B/2,D,octave,0.25,CHORDAZ);
		appendSilence(0.125);
		append(harmony,G,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,E,2*C,octave-1,0.375,CHORDAZ);
		appendInterval(harmony,G,2*D,octave-1,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,D,F,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 17
	#ifdef DEBUG
	puts("Measure # 17");
	#endif
		//VOICE
		create(voice,E,octave,0.75,VOICEAZ);
		append(voice,D,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave,0.75,CHORDAZ);
		append(harmony,D,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,1.0,BASSAZ);
		silence(0.25);
		appendInterval(bass,E,G,octave-1,0.5,BASSAZ);
		appendInterval(bass,E,G,octave-1,0.25,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 18
	#ifdef DEBUG
	puts("Measure # 18");
	#endif
		//VOICE
		four(voice,C,2*C,2*C,B,octave,1.0,VOICEAZ);
		//HARMONY
		four(harmony,C,2*C,2*C,B,octave,1.0,CHORDAZ);
		silence(0.25);
		appendTwo(harmony,E,E,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,Bf,Bf,octave-2,1.0,BASSAZ);
		silence(0.25);
		appendChord(bass,E,G,2*C,octave-1,0.5,BASSAZ);
		appendChord(bass,E,G,2*C,octave-1,0.25,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 19
	#ifdef DEBUG
	puts("Measure # 19");
	#endif
		//VOICE
		create(voice,C,octave+1,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,E,A,2*C,octave,1.0,CHORDAZ);
	add();
		//BASS
		silence(0.25);
		appendChord(bass,E,G,2*C,octave-1,0.5,BASSAZ);
		appendChord(bass,E,G,2*C,octave-1,0.25,BASSAZ);
		interval(bass,A,2*A,octave-2,1.0,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 20
	#ifdef DEBUG
	puts("Measure # 20");
	#endif
		//VOICE
		four(voice,A,A,F,D,octave,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,C,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,C,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,2*Db,2*F,A,octave-1,0.25,CHORDAZ);
		appendInterval(harmony,Af,2*Db,octave-1,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,Db,2*Db,octave-2,0.5,BASSAZ);
		appendInterval(bass,F,2*F,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 21
	#ifdef DEBUG
	puts("Measure # 21");
	#endif
		//VOICE
		create(voice,E,octave,.5,VOICEAZ);
		append(voice,E,octave,0.375,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,E,2*C,2*E,octave,0.875,CHORDAZ);
		appendChord(harmony,G,2*E,2*G,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-2,1.0,BASSAZ);
		silence(0.25);
		appendChord(bass,E,G,2*C,octave-1,0.5,BASSAZ);
		appendChord(bass,E,G,2*C,octave-1,0.25,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 22
	#ifdef DEBUG
	puts("Measure # 22");
	#endif
		//VOICE
		four(voice,Gf,G,F,D,octave,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,Gf,2*Ds,2*Gf,octave,0.25,CHORDAZ);
		appendChord(harmony,G,2*E,2*G,octave,0.25,CHORDAZ);
		appendChord(harmony,F,2*Db,2*F,octave,0.25,CHORDAZ);
		appendChord(harmony,F,B,2*D,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-2,0.25,BASSAZ);
		appendChord(bass,F,G,B,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		appendChord(bass,F,G,B,octave-1,0.25,BASSAZ);
	add();
	cat();

	if(!end){
	//MEASURE # 23 & 24
	#ifdef DEBUG
	puts("Measure # 23 & 24");
	#endif
		//VOICE
		create(voice,C,octave,1.125,VOICEAZ);
		appendSilence(0.25);
		append(voice,G,octave-1,0.125,VOICEAZ);
		append(voice,C,octave,0.375,VOICEAZ);
		append(voice,Db,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave,0.25,CHORDAZ);
		appendTwo(harmony,E,F,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,F,G,octave,0.25,CHORDAZ);
		appendTwo(harmony,A,B,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.125,CHORDAZ);
		appendSilence(0.25);
		append(harmony,G,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,E,2*C,octave-1,0.375,CHORDAZ);
		appendInterval(harmony,F,2*Db,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,G,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,G,2*G,octave-2,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
	add();
	cat();
	}else{
	//MEASURE #23 & 25
	#ifdef DEBUG
	puts("Measure # 23 & 25");
	#endif
		//VOICE
		create(voice,C,octave,1.125,VOICEAZ);
		appendSilence(0.125);
		append(voice,G,octave,0.25,VOICEAZ);
		appendGrace(voice,B,A,octave,FERMATA(0.375),VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave,0.25,CHORDAZ);
		appendTwo(harmony,E,F,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,F,G,octave,0.25,CHORDAZ);
		appendTwo(harmony,A,B,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.125,CHORDAZ);
			grace(harmony,B,A,octave,FERMATA(0.375),CHORDAZ);
			grace(harmony,G,F,octave,FERMATA(0.375),CHORDAZ);
			add();
		cat();
		appendInterval(harmony,E,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,G,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,G,2*G,octave-2,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,C,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	}
}

void chorus(short end){
	MESSOPIANO;
	//MEASURE # 26
	#ifdef DEBUG
	puts("Measure # 26");
	#endif
		//VOICE
		create(voice,G,octave,0.5+1.0/6,VOICEAZ);
		appendTwo(voice,F,D,octave,1.0/3,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave,0.5+1.0/6,CHORDAZ);
		appendTwo(harmony,F,D,octave,1.0/3,CHORDAZ);
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.25,BASSAZ);
		appendChord(bass,F,G,B,octave-1,0.5,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	//MEASURE # 27
	#ifdef DEBUG
	puts("Measure # 27");
	#endif
		//VOICE
		create(voice,B,octave-1,0.25,VOICEAZ);
		appendTwo(voice,G,A,octave,0.25,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ);
		appendTwo(voice,C,D,octave+1,0.25,VOICEAZ);
		//HARMONY
		create(harmony,B,octave-1,0.25,CHORDAZ);
		appendTwo(harmony,G,A,octave,0.25,CHORDAZ);
		appendInterval(harmony,G,B,octave,0.25,CHORDAZ);
		appendInterval(harmony,A,2*C,octave,0.125,CHORDAZ);
		appendInterval(harmony,B,D,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,D,octave-2,0.25,BASSAZ);
		appendChord(bass,F,G,B,octave-1,0.5,BASSAZ);
		appendInterval(bass,G,2*G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 28
	#ifdef DEBUG
	puts("Measure # 28");
	#endif
		//VOICE
		create(voice,E,octave+1,0.75,VOICEAZ);
		append(voice,D,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave+1,0.75,CHORDAZ);
		appendInterval(harmony,G,2*D,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendChord(bass,C,E,2*C,octave-1,0.5,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 29
	#ifdef DEBUG
	puts("Measure # 29");
	#endif
		//VOICE
		create(voice,C,octave+1,0.375,VOICEAZ);
		append(voice,E,octave+1,0.125,VOICEAZ);
		append(voice,D,octave+1,0.375,VOICEAZ);
		append(voice,C,octave+1,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave,0.375,CHORDAZ);
		appendInterval(harmony,C,E,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,B,2*D,octave,0.375,CHORDAZ);
		appendInterval(harmony,A,2*C,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendChord(bass,C,E,2*C,octave-1,0.5,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 30 & 31
	#ifdef DEBUG
	puts("Measure # 30 & 31");
	#endif
		//VOICE
		doubleGrace(voice,C,D,C,octave+1,0.5,VOICEAZ);
		append(voice,B,octave,0.75,VOICEAZ);
		appendTwo(voice,A,B,octave,0.25,VOICEAZ);
		append(voice,C,octave,0.25,VOICEAZ);
		appendTwo(voice,B,A,octave,0.25,VOICEAZ);
		//HARMONY
		doubleGrace(harmony,C,D,C,octave+1,0.5,CHORDAZ);
		interval(harmony,F,A,octave,0.25,CHORDAZ);
		add();
		appendChord(harmony,E,F,B,octave,0.75,CHORDAZ);
		appendInterval(harmony,F,A,octave,0.125,CHORDAZ);
		appendInterval(harmony,G,B,octave,0.125,CHORDAZ);
		appendInterval(harmony,A,2*C,octave,0.25,CHORDAZ);
		appendInterval(harmony,G,B,octave,0.125,CHORDAZ);
		appendInterval(harmony,F,A,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,D,octave-2,0.25,BASSAZ);
		appendChord(bass,G,F,B,octave-1,0.5,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,D,octave-2,0.25,BASSAZ);
		appendChord(bass,G,F,B,octave-1,0.5,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 32
	#ifdef DEBUG
	puts("Measure # 32");
	#endif
		//VOICE
		create(voice,G,octave,0.75,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave,0.75,CHORDAZ);
		appendInterval(harmony,D,F,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendChord(bass,C,E,2*C,octave-1,0.5,BASSAZ);
		append(bass,G,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 33
	#ifdef DEBUG
	puts("Measure # 33");
	#endif
		//VOICE
		create(voice,E,octave,0.375,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.375,VOICEAZ);
		append(voice,Gf,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave,0.375,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.375,CHORDAZ);
		appendInterval(harmony,Ef,Gf,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendChord(bass,E,G,2*C,octave-1,0.5,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 34
	#ifdef DEBUG
	puts("Measure # 34");
	#endif
		//VOICE
		create(voice,G,octave,0.75,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave,0.75,CHORDAZ);
		appendInterval(harmony,D,F,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendChord(bass,E,G,2*C,octave-1,0.5,BASSAZ);
		appendChord(bass,E,G,2*C,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 35
	#ifdef DEBUG
	puts("Measure # 35");
	#endif
		//VOICE
		create(voice,E,octave,0.25,VOICEAZ);
		appendTwo(voice,E,F,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		appendTwo(voice,A,Bf,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave,0.25,CHORDAZ);
		appendTwo(harmony,E,F,octave,0.25,CHORDAZ);
		append(harmony,G,octave,0.25,CHORDAZ);
		appendTwo(harmony,A,Bf,octave,0.25,CHORDAZ);
	add();
		//BASS
		silence(0.25);
		appendInterval(bass,E,G,octave-1,0.5,BASSAZ);
		appendInterval(bass,E,G,octave-1,0.25,BASSAZ);
		create(bass,Bf,octave-2,1.0,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 36
	#ifdef DEBUG
	puts("Measure # 36");
	#endif
		//VOICE
		create(voice,C,octave+1,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,E,A,2*C,octave,1.0,CHORDAZ);
	add();
		//BASS
		silence(0.25);
		appendChord(bass,F,A,2*C,octave-1,0.5,BASSAZ);
		appendChord(bass,F,A,2*C,octave-1,0.25,BASSAZ);
		create(bass,A,octave-2,1.0,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 37
	#ifdef DEBUG
	puts("Measure # 37");
	#endif
		//VOICE
		four(voice,A,A,F,D,octave,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,C,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,C,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,A,2*C,2*E,octave-1,0.25,CHORDAZ);
		appendInterval(harmony,Af,D,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,Db,2*Db,octave-2,0.5,BASSAZ);
		appendInterval(bass,F,2*F,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 38
	#ifdef DEBUG
	puts("Measure # 38");
	#endif
		//VOICE
		create(voice,E,octave,0.75,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,E,2*C,2*E,octave,0.75,CHORDAZ);
		appendChord(harmony,G,2*E,2*G,octave,0.25,CHORDAZ);
	add();
		//BASS
		silence(0.25);
		appendChord(bass,E,G,2*C,octave-1,0.5,BASSAZ);
		appendChord(bass,E,G,2*C,octave-1,0.25,BASSAZ);
		create(bass,G,octave-2,1.0,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 39
	#ifdef DEBUG
	puts("Measure # 39");
	#endif
		//VOICE
		create(voice,Gf,octave,0.375,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,F,octave,0.375,VOICEAZ);
		append(voice,D,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,Gf,2*Ds,2*Gf,octave,0.375,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
		appendChord(harmony,F,2*D,2*F,octave,0.375,CHORDAZ);
		appendChord(harmony,F,B,2*D,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-2,0.25,BASSAZ);
		appendChord(bass,F,G,B,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		appendChord(bass,F,G,B,octave-1,0.25,BASSAZ);
	add();
	cat();
	if(!end){
	//MEASURE # 40 & 41
	#ifdef DEBUG
	puts("Measure # 40");
	#endif
		//VOICE
		create(voice,C,octave,1.125,VOICEAZ);
		appendSilence(0.125);
		append(voice,G,octave,0.25,VOICEAZ);
		appendGrace(voice,B,A,octave,FERMATA(0.375),VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave,0.25,CHORDAZ);
		appendTwo(harmony,D,E,octave,0.25,CHORDAZ);
		appendChord(harmony,A,F,2*G,octave,0.25,CHORDAZ);
		appendTwo(harmony,A,G,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.25,CHORDAZ);
			grace(harmony,B,A,octave,FERMATA(0.375),CHORDAZ);
			grace(harmony,G,F,octave,FERMATA(0.375),CHORDAZ);
			add();
		cat();
		appendInterval(harmony,E,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,G,2*G,octave-2,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,C,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	}else{
	//MEASURE # 42 & 43
	#ifdef DEBUG
	puts("Measure # 42 & 43");
	#endif
		//VOICE
		create(voice,C,octave,1.25,VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave,0.25,CHORDAZ);
		appendTwo(harmony,E,F,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,F,G,octave,0.25,CHORDAZ);
		appendTwo(harmony,A,B,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.25,CHORDAZ);
		appendSilence(0.25);
		appendFour(harmony,A,G,Gf,G,octave,0.5,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,G,2*G,octave-2,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
	add();
	cat();
	FORTE;
	//MEASURE # 44 & 45
	#ifdef DEBUG
	puts("Measure # 44 & 45");
	#endif
		//HARMONY
		interval(harmony,F,B,octave,1+0.5/3,CHORDAZ);
		appendTwo(harmony,F,G,octave,1.0/3,CHORDAZ);
		appendThree(harmony,F,E,D,octave,0.5,CHORDAZ);
		//BASS
		interval(bass,D,2*D,octave-2,0.5,BASSAZ);
		appendChord(bass,G,F,B,octave-1,0.375,BASSAZ);
		appendChord(bass,G,F,B,octave-1,0.125,BASSAZ);
		appendChord(bass,G,F,B,octave-1,0.5,BASSAZ);
		appendInterval(bass,B,2*G,octave-3,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 46 & 47
	#ifdef DEBUG
	puts("Measure # 46 & 47");
	#endif
		//HARMONY
		chord(harmony,C,E,A,octave,1.25,CHORDAZ);
		appendThree(harmony,E,D,C,octave,0.75,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave,0.5,BASSAZ);
		appendInterval(bass,E,G,octave,0.375,BASSAZ);
		appendInterval(bass,E,G,octave,0.125,BASSAZ);
		appendInterval(bass,E,G,octave,0.25,BASSAZ);
		appendThree(bass,A,G,F,octave,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 48 & 49
	#ifdef DEBUG
	puts("Measure # 48 & 49");
	#endif
		//HARMONY
		four(harmony,B/2,C,D,E,octave,1.0,CHORDAZ);
		appendThree(harmony,F,G,A,octave,0.75,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.25,CHORDAZ);
		//BASS
		four(bass,G,Gf,F,E,octave-1,1.0,BASSAZ);
		appendFour(bass,D,C,B/2,G/2,octave-1,1.0,BASSAZ);
	add();
	CRESCENDO;
	cat();
	//MEASURE # 50
	#ifdef DEBUG
	puts("Measure # 50");
	#endif
		//HARMONY
		interval(harmony,E,2*C,octave,0.25,CHORDAZ);
		appendSilence(0.25);
		appendFourChord(harmony,A/2,C,F,A,octave,0.375,CHORDAZ);
		appendFourChord(harmony,A/2,C,F,A,octave,0.125,CHORDAZ);
		//BASS
		create(bass,C,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,F,2*F,octave-2,0.375,BASSAZ);
		appendInterval(bass,F,2*F,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 51
	#ifdef DEBUG
	puts("Measure # 51");
	#endif
		//HARMONY
		fourChordMartelato(harmony,C,E,G,2*C,octave,0.25,CHORDAZ);
		//BASS
		intervalMartelato(bass,C,2*C,octave,0.25,BASSAZ);
	add();
	cat();
	}
}

void song(void){
	intro();
	chorus(0);
	cat();
	chorus(1);
	cat();
}

int main(int argc, char **argv){
	tempo=90;
	C = Ef;
	song();
	echo(10,0.3,4);
    appendSilence(2);
	puts("Writing wav file: la golondrina.wav");
	exportToWav("La Golondrina.wav");
}
