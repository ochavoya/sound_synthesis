#include "soundlib.h"
#define DEBUG 1

#define VOICEAZ 75
#define CHORDAZ 135
#define BASSAZ 90

double (*voice)(double) = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double) = oldCircleOfRa;

short octave = 0;


void fine(){
	MESSOFORTE;
	//MEASURE # 27
	#ifdef DEBUG
	puts("Measure # 27");
	#endif
		//VOICE
		create(voice,D,octave,0.1875,VOICEAZ);
		append(voice,D,octave,0.0625,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		appendTwo(voice,G,G,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,G/2,B/2,D,octave,0.25,CHORDAZ);
		appendChord(harmony,G/2,B/2,D,octave,0.1875,CHORDAZ);
		append(harmony,G,octave,0.0625,CHORDAZ);
	add();
		//BASS
		create(bass,B,octave-3,0.25,BASSAZ);
		appendTwo(bass,2*B,B,octave-3,0.25,BASSAZ);
	add();
	//MEASURE # 28
	#ifdef DEBUG
	puts("Measure # 28");
	#endif
		//VOICE
		two(voice,B,B,octave,0.125,VOICEAZ);
		appendTwo(voice,D,0,octave+1,0.25,VOICEAZ);
		appendTwo(voice,C,B/2,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,D,G,octave,0.25,CHORDAZ);
		appendChord(harmony,D,G,B,octave,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,B,2*B,octave-3,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 29
	#ifdef DEBUG
	puts("Measure # 29");
	#endif
		//VOICE
		four(voice,C,C,A/2,F/2,octave+1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,C,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,F,A,2*C,octave,0.125,CHORDAZ);
		appendTwo(harmony,A,F,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,F,octave-2,0.25,BASSAZ);
		appendTwo(bass,A,F,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 30
	#ifdef DEBUG
	puts("Measure # 30");
	#endif
		//VOICE
		create(voice,G,octave,0.25,VOICEAZ);
		appendSilence(0.125);
		appendTwo(voice,E,E,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,0.1875,CHORDAZ);
		append(harmony,E,octave,0.0625,CHORDAZ);
		appendFour(harmony,C,D,E,F,octave,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,C,2*C,octave,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 31
	#ifdef DEBUG
	puts("Measure # 31");
	#endif
		//VOICE
		create(voice,D,octave,0.1875,VOICEAZ);
		append(voice,D,octave,0.0625,VOICEAZ);
		appendTwo(voice,G,G,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,D,G,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,D,G,octave,0.125,CHORDAZ);
		appendTwo(harmony,G,2*D,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,B,octave-3,0.25,BASSAZ);
		appendTwo(bass,B,B/2,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 32
	#ifdef DEBUG
	puts("Measure # 32");
	#endif
		//VOICE
		create(voice,B,octave,0.125,VOICEAZ);
		append(voice,B,octave,0.0625,VOICEAZ);
		append(voice,D,octave+1,0.25,VOICEAZ);
		append(voice,B,octave,0.0625,VOICEAZ);
		//HARMONY
		chord(harmony,G,B,2*D,octave,0.25,CHORDAZ);
		appendChord(harmony,D,G,B,octave,0.125,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,B/2,B,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 33
	#ifdef DEBUG
	puts("Measure # 33");
	#endif
		//VOICE
		three(voice,C,C,A/2,octave+1,0.375,VOICEAZ);
		appendTwo(voice,F,G,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,C,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,F,A,2*C,octave,0.125,CHORDAZ);
		append(harmony,F,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,A,octave-3,0.25,BASSAZ);
		appendTwo(bass,A,A/2,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 34
	#ifdef DEBUG
	puts("Measure # 34");
	#endif
		//VOICE
		create(voice,G,octave,0.125,VOICEAZ);
		appendTwo(voice,G,G,octave,0.125,VOICEAZ);
		appendTwo(voice,A,B,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,0.125,CHORDAZ);
		appendThree(harmony,E,F,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		four(bass,C,E,F,G,octave-2,0.5,BASSAZ);
		silence(0.125);
		appendThree(bass,E,F,G,octave-3,0.375,BASSAZ);
		add();
	add();
	gradual(1,8.0/7);
	cat();
	FORTE;
	//MEASURE # 35
	#ifdef DEBUG
	puts("Measure # 35");
	#endif
		//VOICE
		create(voice,C,octave+1,0.25,VOICEAZ);
		appendTwo(voice,E,0,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,A,octave,0.25,CHORDAZ);
		appendChord(harmony,E,A,2*C,octave,0.125,CHORDAZ);
		appendSilence(0.125);
	add();
		//BASS
		interval(bass,A,2*A,octave-3,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendTwo(bass,C,D,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 36
	#ifdef DEBUG
	puts("Measure # 36");
	#endif
		//VOICE
		create(voice,D,octave+1,0.125,VOICEAZ);
		append(voice,C,octave+1,0.0625,VOICEAZ);
		append(voice,C,octave+1,0.1875,VOICEAZ);
		appendTwo(voice,G,G,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,0.25,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,E,octave-2,0.25,BASSAZ);
		appendTwo(bass,E,E/2,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 37 & 38
	#ifdef DEBUG
	puts("Measure # 37 & 38");
	#endif
		//VOICE
		three(voice,A,A,G,octave,0.375,VOICEAZ);
		append(voice,F,octave,0.0625,VOICEAZ);
		append(voice,G,octave,0.0625+0.25,VOICEAZ);
		appendSilence(0.125);
		appendTwo(voice,D,E,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,C,F,A,octave,0.375,CHORDAZ);
		appendTwo(harmony,F,A,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.25+0.0625,CHORDAZ);
		appendThree(harmony,C,D,E,octave,0.1875,CHORDAZ);
	add();
		//BASS
		create(bass,F,octave-2,0.25,BASSAZ);
		appendTwo(bass,F,F/2,octave-1,0.25,BASSAZ);
		appendTwo(bass,E,2*E,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 39
	#ifdef DEBUG
	puts("Measure # 39");
	#endif
		//VOICE
		two(voice,F,F,octave,0.25,VOICEAZ);
		append(voice,A,octave,0.1875,VOICEAZ);
		append(voice,G,octave,0.0625,VOICEAZ);
		//HARMONY
		chord(harmony,A/2,C,F,octave,0.25,CHORDAZ);
		appendChord(harmony,C,F,A,octave,0.1875,CHORDAZ);
		append(harmony,G,octave,0.0625,CHORDAZ);
	add();
		//BASS
		create(bass,Db,octave-2,0.25,BASSAZ);
		appendTwo(bass,Db,D/2,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 40 & 55
	#ifdef DEBUG
	puts("Measure # 40 & 55");
	#endif
		//VOICE
		two(voice,G,2*C,octave,0.25,VOICEAZ);
		append(voice,C,octave+1,0.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,E,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,0.25,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.25,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,E,octave-2,0.25,BASSAZ);
		appendTwo(bass,2*E,E,octave,0.25,BASSAZ);
		append(bass,E,octave-2,0.25,BASSAZ);
		appendTwo(bass,2*E,E,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 56
	#ifdef DEBUG
	puts("Measure # 56");
	#endif
		//VOICE
		two(voice,F,G,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,A/2,C,F,octave,0.25,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,Db,2*Db,octave-2,0.25,BASSAZ);
		appendTwo(bass,E,2*E,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 57
	#ifdef DEBUG
	puts("Measure # 57");
	#endif
		//VOICE
		two(voice,A,B,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,C,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,D,G,B,octave,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,F,2*F,octave-2,0.25,BASSAZ);
		appendTwo(bass,G,D,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 58
	#ifdef DEBUG
	puts("Measure # 58");
	#endif
		//VOICE
		create(voice,C,octave+1,FERMATA(1.0),VOICEAZ);
		//HARMONY
		fourChord(harmony,C,E,G,2*C,octave,FERMATA(1.0),CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,FERMATA(1.0),BASSAZ);
	add();
	cat();
}


void start(void){
	MESSOPIANO;
	//MEASURE # 1
	#ifdef DEBUG
	puts("Measure # 1");
	#endif
		//HARMONY
		interval(harmony,E,2*C,octave,0.25+0.0625,CHORDAZ);
		appendThree(harmony,E,G,2*C,octave,0.1875,CHORDAZ);
		//BASS
		two(bass,C,G,octave-1,0.25,BASSAZ);
		append(bass,C,octave,0.25,BASSAZ);
	add();
	//MEASURE # 2
	#ifdef DEBUG
	puts("Measure # 2");
	#endif
		//HARMONY
		interval(harmony,D,B,octave,0.25+0.0625,CHORDAZ);
		appendThree(harmony,D,G,B,octave,0.1875,CHORDAZ);
		//BASS
		two(bass,C,G,octave-1,0.25,BASSAZ);
		append(bass,C,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 3
	#ifdef DEBUG
	puts("Measure # 3");
	#endif
		//HARMONY
		interval(harmony,C,A,octave,0.25+0.0625,CHORDAZ);
		appendThree(harmony,C,F,A,octave,0.1875,CHORDAZ);
		//BASS
		two(bass,C,F,octave-1,0.25,BASSAZ);
		append(bass,A,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 4
	#ifdef DEBUG
	puts("Measure # 4");
	#endif
		//HARMONY
		interval(harmony,A,2*C,octave,0.25,CHORDAZ);
		appendInterval(harmony,A,2*F,octave,0.25,CHORDAZ);
		//BASS
		two(bass,C,A,octave-1,0.25,BASSAZ);
		append(bass,C,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 5
	#ifdef DEBUG
	puts("Measure # 5");
	#endif
		//HARMONY
		interval(harmony,E,2*C,octave,0.375,CHORDAZ);
		appendTwo(harmony,C,D,octave+1,0.125,CHORDAZ);
		//BASS
		two(bass,C,G,octave,0.25,BASSAZ);
		append(bass,C,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 6
	#ifdef DEBUG
	puts("Measure # 6");
	#endif
		//HARMONY
		interval(harmony,D,B,octave,0.375,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
		//BASS
		two(bass,C,G,octave-1,0.25,BASSAZ);
		append(bass,C,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 7 & 8
	#ifdef DEBUG
	puts("Measure # 8");
	#endif
		//VOICE
		silence(0.5+0.375);
		appendTwo(voice,E,F,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,F,2*C,octave,0.5,CHORDAZ);
		appendInterval(harmony,F,2*C,octave,0.5,CHORDAZ);
	add();
		//BASS
		three(bass,C,F,A,octave-1,0.375,BASSAZ);
		append(bass,C,octave,0.625,BASSAZ);
	add();
	cat();
}

void intermesso(int end){
	MESSOPIANO;
	//MEASURE # 9 & 10
	#ifdef DEBUG
	puts("Measure # 9 & 10");
	#endif
		//VOICE
		three(voice,G,G,G,octave,0.375,VOICEAZ);
		append(voice,G,octave,0.0625,VOICEAZ);
		append(voice,G,octave,0.1875,VOICEAZ);
		appendTwo(voice,G,G,octave,0.125,VOICEAZ);
		volume/=2;
			append(voice,G,octave,0.125,VOICEAZ);
			appendTwo(voice,E,F,octave,0.125,VOICEAZ);
		volume*=2;
		silence(0.75);
		append(voice,G,octave,0.1875,VOICEAZ);
		append(voice,C,octave,0.0625,VOICEAZ);
		add();
		//HARMONY
		interval(harmony,G/2,E,octave,1.0,CHORDAZ);
	add();
		//BASS
		four(bass,C,G,2*D,G,octave-2,0.5,BASSAZ);
		appendTwo(bass,E,G/2,octave,0.5,BASSAZ);
	add();
	//MEASURE # 11 & 12
	#ifdef DEBUG
	puts("Measure # 11 & 12");
	#endif
		//VOICE
		three(voice,G,F,F,octave,0.375,VOICEAZ);
		append(voice,E,octave,0.0625,VOICEAZ);
		append(voice,F,octave,0.0625+0.25,VOICEAZ);
		appendSilence(0.125);
		appendTwo(voice,D,E,octave,0.0625,VOICEAZ);
		//HARMONY
		fourChord(harmony,C,F,G/2,A/2,octave,1.0,CHORDAZ);
	add();
		//BASS
		four(bass,C/2,C,F,C,octave-1,0.5,BASSAZ);
		appendTwo(bass,G,F,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 13 & 14
	#ifdef DEBUG
	puts("Measure # 13 & 14");
	#endif
		//VOICE
		create(voice,F,octave,0.125,VOICEAZ);
		append(voice,F,octave,0.0625,VOICEAZ);
		append(voice,F,octave,0.1875,VOICEAZ);
		append(voice,F,octave,0.0625,VOICEAZ);
		append(voice,F,octave,0.0625+0.25,VOICEAZ);
		silence(0.5);
		volume/=2;
		appendTwo(voice,F,F,octave,0.25,VOICEAZ);
		volume*=2;
		add();
		appendSilence(0.0625);
		appendThree(voice,Db,Db,E,octave,0.1875,VOICEAZ);
		//HARMONY
		fourChord(harmony,F/2,A/2,C,Db,octave,1.0,CHORDAZ);
	add();
		//BASS
		four(bass,Db,A,2*Db,A,octave-2,0.5,BASSAZ);
		appendTwo(bass,F,A/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 15
	#ifdef DEBUG
	puts("Measure # 15");
	#endif
		//VOICE
		create(voice,F,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.0625,VOICEAZ);
		append(voice,D,octave,0.0625+0.125,VOICEAZ);
		append(voice,C,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,F/2,D,octave,0.25,CHORDAZ);
		append(harmony,F,octave,0.25,CHORDAZ);
	add();
		//BASS
		four(bass,Bf,2*F,2*Bf,4*D,octave-3,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 16
	#ifdef DEBUG
	puts("Measure # 16");
	#endif
		//VOICE
		create(voice,D,octave,0.375,VOICEAZ);
		appendSilence(0.0625);
		append(voice,G,octave-1,0.0625,VOICEAZ);
		//HARMONY
		interval(harmony,B/2,G,octave,0.375,CHORDAZ);
		appendInterval(harmony,E/2,C,octave,0.0625,CHORDAZ);
		appendInterval(harmony,F/2,D,octave,0.0625,CHORDAZ);
	add();
		//BASS
		two(bass,G,D,octave-2,0.25,BASSAZ);
		append(bass,B,octave-1,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 17 & 18
	#ifdef DEBUG
	puts("Measure # 17 & 18");
	#endif
		//VOICE
		create(voice,G,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.0625,VOICEAZ);
		append(voice,G,octave,0.1875,VOICEAZ);
		append(voice,G,octave,0.0625,VOICEAZ);
		create(voice,G,octave,0.1875,VOICEAZ);
			silence(0.0625);
			volume/=1.5;
				appendTwo(voice,G,E,octave,0.25,VOICEAZ);
			volume*=1.5;
			add();
		cat();
		appendSilence(0.125);
		appendTwo(voice,E,F,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,G/2,E,octave,0.875,CHORDAZ);
		appendTwo(harmony,G,A,octave,0.125,CHORDAZ);
	add();
		//BASS
		four(bass,C,G,2*D,G,octave-2,0.5,BASSAZ);
		appendTwo(bass,E,G,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 19 & 20
	#ifdef DEBUG
	puts("Measure # 19 & 20");
	#endif
		//VOICE
		create(voice,G,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.0625,VOICEAZ);
		append(voice,G,octave,0.1875,VOICEAZ);
		append(voice,A,octave,0.0625,VOICEAZ);
		append(voice,E,octave,0.0625+0.25,VOICEAZ);
		appendSilence(0.125);
		appendTwo(voice,D,E,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,D,G,octave,0.75,CHORDAZ);
		appendInterval(harmony,D,B,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.125,CHORDAZ);
	add();
		//BASS
		four(bass,E,B,2*E,B,octave-2,0.5,BASSAZ);
		appendTwo(bass,G,B/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 21 & 22
	#ifdef DEBUG
	puts("Measure # 21 & 22");
	#endif
		//VOICE
		three(voice,F,F,F,octave,0.375,VOICEAZ);
		append(voice,F,octave,0.0625,VOICEAZ);
		append(voice,F,octave,0.0625+0.125,VOICEAZ);
		append(voice,F,octave,0.125,VOICEAZ);
		appendSilence(0.125);
		appendTwo(voice,E,Db,octave,0.125,VOICEAZ);
		silence(0.5);
		volume/=1.5;
			appendFour(voice,F,F,F,A,octave,0.25,VOICEAZ);
		volume*=1.5;
		add();
		//HARMONY
		chord(harmony,A/2,C,E,octave,0.5,CHORDAZ);
		appendInterval(harmony,C,A,octave,0.375,CHORDAZ);
		appendTwo(harmony,E,Db,octave,0.125,CHORDAZ);
	add();
		//BASS
		four(bass,E,A,2*Db,A,octave-2,0.5,BASSAZ);
		appendTwo(bass,F,A/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 23, 24, 25, 26
	#ifdef DEBUG
	puts("Measure # 23, 24, 25, 26");
	#endif
		//VOICE
		three(voice,E,A,A,octave,0.375,VOICEAZ);
		append(voice,A,octave,0.0625,VOICEAZ);
		append(voice,A,octave,0.0625+1+0.25,VOICEAZ);
		appendSilence(0.125);
		MESSOFORTE;
		appendTwo(voice,Db,Db,octave,0.125,VOICEAZ);
		//HARMONY
		MESSOPIANO;
		interval(harmony,C,E,octave,0.25,CHORDAZ);
		appendInterval(harmony,C,A,octave,0.25,CHORDAZ);
		appendInterval(harmony,C,A,octave,0.375,CHORDAZ);
		appendInterval(harmony,B/2,G,octave,0.125,CHORDAZ);
		appendInterval(harmony,A/2,F,octave,0.25,CHORDAZ);
		appendInterval(harmony,C,A,octave,0.25,CHORDAZ);
		appendInterval(harmony,F,2*C,octave,0.25,CHORDAZ);
	add();
		//BASS
		four(bass,A,2*F,2*A,4*C,octave-3,0.5,BASSAZ);
		appendTwo(bass,E,G/2,octave-1,0.5,BASSAZ);
		appendFour(bass,F/2,C,F,A,octave-1,0.5,BASSAZ);
		appendTwo(bass,C,F/2,octave,0.5,BASSAZ);
	add();
	cat();
	MESSOFORTE;
	//MEASURE # 27
	#ifdef DEBUG
	puts("Measure # 27");
	#endif
		//VOICE
		create(voice,D,octave,0.1875,VOICEAZ);
		append(voice,D,octave,0.0625,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		appendTwo(voice,G,G,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,G/2,B/2,D,octave,0.25,CHORDAZ);
		appendChord(harmony,G/2,B/2,D,octave,0.1875,CHORDAZ);
		append(harmony,G,octave,0.0625,CHORDAZ);
	add();
		//BASS
		create(bass,B,octave-3,0.25,BASSAZ);
		appendTwo(bass,2*B,B,octave-3,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 28
	#ifdef DEBUG
	puts("Measure # 28");
	#endif
		//VOICE
		two(voice,B,B,octave,0.125,VOICEAZ);
		appendTwo(voice,D,0,octave+1,0.25,VOICEAZ);
		appendTwo(voice,C,B/2,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,D,G,octave,0.25,CHORDAZ);
		appendChord(harmony,D,G,B,octave,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,B,2*B,octave-3,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 29
	#ifdef DEBUG
	puts("Measure # 29");
	#endif
		//VOICE
		four(voice,C,C,A/2,F/2,octave+1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,C,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,F,A,2*C,octave,0.125,CHORDAZ);
		appendTwo(harmony,A,F,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,F,octave-2,0.25,BASSAZ);
		appendTwo(bass,A,F,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 30
	#ifdef DEBUG
	puts("Measure # 30");
	#endif
		//VOICE
		create(voice,G,octave,0.25,VOICEAZ);
		appendSilence(0.125);
		appendTwo(voice,E,E,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,0.1875,CHORDAZ);
		append(harmony,E,octave,0.0625,CHORDAZ);
		appendFour(harmony,C,D,E,F,octave,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,C,2*C,octave,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 31
	#ifdef DEBUG
	puts("Measure # 31");
	#endif
		//VOICE
		create(voice,D,octave,0.1875,VOICEAZ);
		append(voice,D,octave,0.0625,VOICEAZ);
		appendTwo(voice,G,G,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,D,G,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,D,G,octave,0.125,CHORDAZ);
		appendTwo(harmony,G,2*D,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,B,octave-3,0.25,BASSAZ);
		appendTwo(bass,B,B/2,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 32
	#ifdef DEBUG
	puts("Measure # 32");
	#endif
		//VOICE
		create(voice,B,octave,0.125,VOICEAZ);
		append(voice,B,octave,0.0625,VOICEAZ);
		append(voice,D,octave+1,0.25,VOICEAZ);
		append(voice,B,octave,0.0625,VOICEAZ);
		//HARMONY
		chord(harmony,G,B,2*D,octave,0.25,CHORDAZ);
		appendChord(harmony,D,G,B,octave,0.125,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,B/2,B,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 33
	#ifdef DEBUG
	puts("Measure # 33");
	#endif
		//VOICE
		three(voice,C,C,A/2,octave+1,0.375,VOICEAZ);
		appendTwo(voice,F,G,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,C,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,F,A,2*C,octave,0.125,CHORDAZ);
		append(harmony,F,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,A,octave-3,0.25,BASSAZ);
		appendTwo(bass,A,A/2,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 34
	#ifdef DEBUG
	puts("Measure # 34");
	#endif
		//VOICE
		create(voice,G,octave,0.125,VOICEAZ);
		appendTwo(voice,G,G,octave,0.125,VOICEAZ);
		appendTwo(voice,A,B,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,0.125,CHORDAZ);
		appendThree(harmony,E,F,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		four(bass,C,E,F,G,octave-2,0.5,BASSAZ);
		silence(0.125);
		appendThree(bass,E,F,G,octave-3,0.375,BASSAZ);
		add();
	add();
	gradual(1,8.0/7);
	cat();
	FORTE;
	//MEASURE # 35
	#ifdef DEBUG
	puts("Measure # 35");
	#endif
		//VOICE
		create(voice,C,octave+1,0.25,VOICEAZ);
		appendTwo(voice,E,0,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,A,octave,0.25,CHORDAZ);
		appendChord(harmony,E,A,2*C,octave,0.125,CHORDAZ);
		appendSilence(0.125);
	add();
		//BASS
		interval(bass,A,2*A,octave-3,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendTwo(bass,C,D,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 36
	#ifdef DEBUG
	puts("Measure # 36");
	#endif
		//VOICE
		create(voice,D,octave+1,0.125,VOICEAZ);
		append(voice,C,octave+1,0.0625,VOICEAZ);
		append(voice,C,octave+1,0.1875,VOICEAZ);
		appendTwo(voice,G,G,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,0.25,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,E,octave-2,0.25,BASSAZ);
		appendTwo(bass,E,E/2,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 37 & 38
	#ifdef DEBUG
	puts("Measure # 37 & 38");
	#endif
		//VOICE
		three(voice,A,A,G,octave,0.375,VOICEAZ);
		append(voice,F,octave,0.0625,VOICEAZ);
		append(voice,G,octave,0.0625+0.25,VOICEAZ);
		appendSilence(0.125);
		appendTwo(voice,D,E,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,C,F,A,octave,0.375,CHORDAZ);
		appendTwo(harmony,F,A,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.25+0.0625,CHORDAZ);
		appendThree(harmony,C,D,E,octave,0.1875,CHORDAZ);
	add();
		//BASS
		create(bass,F,octave-2,0.25,BASSAZ);
		appendTwo(bass,F,F/2,octave-1,0.25,BASSAZ);
		appendTwo(bass,E,2*E,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 39
	#ifdef DEBUG
	puts("Measure # 39");
	#endif
		//VOICE
		two(voice,F,F,octave,0.25,VOICEAZ);
		append(voice,A,octave,0.1875,VOICEAZ);
		append(voice,G,octave,0.0625,VOICEAZ);
		//HARMONY
		chord(harmony,A/2,C,F,octave,0.25,CHORDAZ);
		appendChord(harmony,C,F,A,octave,0.1875,CHORDAZ);
		append(harmony,G,octave,0.0625,CHORDAZ);
	add();
		//BASS
		create(bass,Db,octave-2,0.25,BASSAZ);
		appendTwo(bass,Db,D/2,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 40 & 41
	#ifdef DEBUG
	puts("Measure # 40 & 41");
	#endif
		//VOICE
		two(voice,G,2*C,octave,0.25,VOICEAZ);
		append(voice,C,octave+1,0.5,VOICEAZ);
		appendTwo(voice,0,G,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,0.25,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.25,CHORDAZ);
		appendChord(harmony,2*C,E,G,octave,0.25,CHORDAZ);
		appendChord(harmony,2*C,E,G,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,E,octave-2,0.25,BASSAZ);
		appendTwo(bass,E,2*E,octave-2,0.25,BASSAZ);
		append(bass,E,octave-2,0.25,BASSAZ);
		appendTwo(bass,E,2*E,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 42
	#ifdef DEBUG
	puts("Measure # 42");
	#endif
		//VOICE
		create(voice,A,octave,0.1875,VOICEAZ);
		appendTwo(voice,C,C,octave+1,0.125,VOICEAZ);
		append(voice,C,octave+1,0.1875,VOICEAZ);
		//HARMONY
		chord(harmony,C,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,F,G,2*C,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,F,2*F,octave-3,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.25,BASSAZ);
	add();
	cat();
	if(!end){
	//MEASURE # 43, 44 & 45
	#ifdef DEBUG
	puts("Measure # 43, 44 & 45");
	#endif
		//VOICE
		create(voice,C,octave+1,1.5,VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave,0.25+0.0625,CHORDAZ);
		appendThree(harmony,E,G,2*C,octave,0.1875,CHORDAZ);
		appendInterval(harmony,D,B,octave,0.25+0.0625,CHORDAZ);
		appendThree(harmony,D,G,B,octave,0.1875,CHORDAZ);
		appendInterval(harmony,C,A,octave,0.25+0.0625,CHORDAZ);
		appendThree(harmony,C,F,A,octave,0.1875,CHORDAZ);
	add();
		//BASS
		two(bass,C,G,octave-1,0.25,BASSAZ);
		append(bass,C,octave,0.25,BASSAZ);
		two(bass,C,G,octave-1,0.25,BASSAZ);
		append(bass,C,octave,0.25,BASSAZ);
		cat();
		two(bass,C,F,octave-1,0.25,BASSAZ);
		append(bass,A,octave-1,0.25,BASSAZ);
		cat();
	add();
	cat();

	//MEASURE # 46
	#ifdef DEBUG
	puts("Measure # 46");
	#endif
		//HARMONY
		interval(harmony,A,2*F,octave,0.25,CHORDAZ);
		appendInterval(harmony,F,2*C,octave,0.25,CHORDAZ);
		//BASS
		two(bass,C,A,octave,0.25,BASSAZ);
		append(bass,C,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 47
	#ifdef DEBUG
	puts("Measure # 47");
	#endif
		//HARMONY
		interval(harmony,E,2*C,octave,0.375,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.0625,CHORDAZ);
		append(harmony,A,octave,0.0625,CHORDAZ);
		//BASS
		two(bass,C,G,octave,0.25,BASSAZ);
		append(bass,C,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 48
	#ifdef DEBUG
	puts("Measure # 48");
	#endif
		//HARMONY
		interval(harmony,E,B,octave,0.375,CHORDAZ);
		appendInterval(harmony,D,B,octave,0.0625,CHORDAZ);
		append(harmony,G,octave,0.0625,CHORDAZ);
		//BASS
		two(bass,C,G,octave,0.25,BASSAZ);
		append(bass,C,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 49 & 50
	#ifdef DEBUG
	puts("Measure # 49 & 50");
	#endif
		//VOICE
		silence(0.5+0.375);
		appendTwo(voice,E,F,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,C,A,octave,0.5,CHORDAZ);
		appendInterval(harmony,F,2*C,octave+1,0.5,CHORDAZ);
	add();
		//BASS
		three(bass,C,F,A,octave-1,0.375,BASSAZ);
		append(bass,C,octave,0.625,BASSAZ);
	add();
	gradual(1,6.0/7);
	cat();
	}
	else{
	//MEASURE # 51, 52, 53, & 54
	#ifdef DEBUG
	puts("Measure # 51, 52, 53, & 54");
	#endif
		//VOICE
		create(voice,Db,octave+1,0.125,VOICEAZ);
		append(voice,C,octave+1,1.625,VOICEAZ);
		appendSilence(0.125);
		appendTwo(voice,D,D,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,C,A,2*C,octave,0.25,CHORDAZ);

			grace(harmony,A,A,octave-1,0.25,CHORDAZ);
			grace(harmony,C,C,octave,0.25,CHORDAZ);
			grace(harmony,E,E,octave,0.25,CHORDAZ);
			add();
			add();
			cat();

			grace(harmony,C,C,octave,0.25,CHORDAZ);
			grace(harmony,E,E,octave,0.25,CHORDAZ);
			grace(harmony,A,A,octave,0.25,CHORDAZ);
			add();
			add();
			cat();

			grace(harmony,E,E,octave,0.25,CHORDAZ);
			grace(harmony,A,A,octave,0.25,CHORDAZ);
			grace(harmony,C,C,octave+1,0.25,CHORDAZ);
			add();
			add();
			cat();


		appendFourChord(harmony,C,F,A,2*C,octave,0.375,CHORDAZ);
		appendInterval(harmony,A,2*A,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,B,2*B,octave-1,0.125,CHORDAZ);
		appendFourChord(harmony,C,F,A,2*C,octave,0.25,CHORDAZ);
		appendFourChord(harmony,F,A,2*C,2*F,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,B,octave-3,0.25,BASSAZ);
		appendTwo(bass,2*A,B,octave-3,0.25,BASSAZ);
		appendTwo(bass,B,2*A,octave-3,0.5,BASSAZ);
		append(bass,F,octave-2,0.25,BASSAZ);
		appendTwo(bass,F,2*F,octave-2,0.25,BASSAZ);
		append(bass,F,octave-2,0.1875,BASSAZ);
		append(bass,C,octave-1,0.0625,BASSAZ);
		appendTwo(bass,F,C,octave,0.25,BASSAZ);
	add();
	cat();
	}
}

void song(void){
	start();
	intermesso(0); cat();
	intermesso(1); cat();
	fine(); cat();
}

int main(int argc, char** argv){

	song();
	echo(10,0.30,4);
	puts("Writing wav file: god bless the usa.wav");
	exportToWav("god bless the usa.wav");

}


