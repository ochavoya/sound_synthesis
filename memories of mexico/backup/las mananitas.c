#include "soundlib.h"

#define VOICEAZ 150
#define CHORDAZ 30
#define BASSAZ 90

#define DEBUG 1


double (*voice)(double) = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double) = oldCircleOfRa;


short octave = 0;


void song(void){
	PIANO;
	//MEASURE # 1
	#ifdef DEBUG
	puts("Measure # 1");
	#endif
		//HARMONY
		silence(0.5);
		appendTwo(harmony,G,G,octave,0.25,CHORDAZ);
		//BASS
	//MEASURE # 2
	#ifdef DEBUG
	puts("Measure # 2");
	#endif
		//HARMONY
		interval(harmony,E,2*C,octave,0.375,CHORDAZ);
		create(harmony,C,octave+1,0.125,CHORDAZ);
		appendTwo(harmony,B,2*C,octave,0.25,CHORDAZ);
		addInterval(harmony,E,G,octave,0.375,CHORDAZ);
		add();
		//BASS
		six(bass,C,G,2*C,2*C,B,2*C,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 3
	#ifdef DEBUG
	puts("Measure # 3");
	#endif
		//HARMONY
		four(harmony,Ef,E,G,B,octave+1,0.5,CHORDAZ);
		two(harmony,B,2*C,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.25,CHORDAZ);
		add();
		addTwo(harmony,G,2*C,octave,0.5,CHORDAZ);
		//BASS
		four(bass,Ef,E,G,B,octave,0.5,BASSAZ);
	add();
	CRESCENDO;
	cat();
		two(harmony,D,C,octave+2,0.25,CHORDAZ);
		addInterval(harmony,E,G,octave,0.25,CHORDAZ);
		//BASS
		two(bass,D,C,octave+1,0.25,BASSAZ);
	add();
	DECRESCENDO;
	cat();
	//MEASURE # 4
	#ifdef DEBUG
	puts("Measure # 4");
	#endif
		//HARMONY
		two(harmony,G,E,octave+1,0.25,CHORDAZ);
		addInterval(harmony,G,2*C,octave,0.25,CHORDAZ);
		//BASS
		interval(bass,E,2*C,octave-1,0.25,BASSAZ);
	add();
	cat();
	PP;
		//HARMONY
		two(harmony,A,F,octave+1,0.25,CHORDAZ);
		addInterval(harmony,A,2*Db,octave,0.25,CHORDAZ);
		appendChord(harmony,Db,F,A,octave,0.125,CHORDAZ);
		appendChord(harmony,F,B,2*D,octave,FERMATA(0.125),CHORDAZ);
		//BASS
		interval(bass,F,2*Db,octave-1,0.25,BASSAZ);
		appendInterval(bass,D,B,octave-1,0.125,BASSAZ);
		append(bass,D,octave-1,FERMATA(0.125),BASSAZ);
	add();
	cat();
	//MEASURE # 5
	#ifdef DEBUG
	puts("Measure # 5");
	#endif
		//HARMONY
		two(harmony,G,G,octave,0.5,CHORDAZ);
		addTwo(harmony,C,C,octave+1,0.5,CHORDAZ);
		//BASS
		two(bass,G,F,octave,0.5,BASSAZ);
		addTwo(bass,A,G,octave,0.5,BASSAZ);
		create(bass,C,octave-1,0.5,BASSAZ);
	add();
	cat();
	PIANO;
		//VOICE
		appendTwo(voice,G,G,octave,0.25,VOICEAZ);
		//HARMONY
		two(harmony,G,G,octave,0.25,CHORDAZ);
	add();
	cat();
	//MEASURE # 6
	#ifdef DEBUG
	puts("Measure # 6");
	#endif
		//VOICE
		create(voice,C,octave+1,0.375,VOICEAZ);
		appendThree(voice,C,B/2,C,octave,0.375,VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave,0.375,CHORDAZ);
		three(harmony,C,B/2,C,octave+1,0.375,CHORDAZ);
		addThree(harmony,E,D,E,octave,0.375,CHORDAZ);
		cat();
	add();
		//BASS
		two(bass,C,G,octave-1,0.25,BASSAZ);
		append(bass,A,octave-1,0.25,BASSAZ);
		appendTwo(bass,G,C,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 7
	#ifdef DEBUG
	puts("Measure # 7");
	#endif
		//VOICE
		create(voice,Db,octave+1,0.375,VOICEAZ);
		appendThree(voice,B/2,C,D,octave+1,0.375,VOICEAZ);
		//HARMONY
		interval(harmony,F,2*Db,octave,0.375,CHORDAZ);
		three(harmony,B/2,C,D,octave+1,0.375,CHORDAZ);
		addThree(harmony,E,F,G,octave,0.375,CHORDAZ);
		cat();
	add();
		//BASS
		two(bass,C,G,octave-1,0.25,BASSAZ);
		append(bass,F,octave-1,0.25,BASSAZ);
		appendTwo(bass,E,D,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 8
	#ifdef DEBUG
	puts("Measure # 8");
	#endif
		//VOICE
		create(voice,E,octave+1,0.375,VOICEAZ);
		appendThree(voice,C,D,E,octave,0.375,VOICEAZ);
		//HARMONY
		interval(harmony,G,2*E,octave,0.375,CHORDAZ);
		three(harmony,C,D,E,octave+1,0.375,CHORDAZ);
		addThree(harmony,G,F,D,octave,0.375,CHORDAZ);
		cat();
	add();
		//BASS
		six(bass,C,G,2*D,2*C,B,Bf,octave-1,0.75,BASSAZ);
	add();
	CRESCENDO;
	cat();
	//MEASURE # 9 & 10
	#ifdef DEBUG
	puts("Measure # 9 & 10");
	#endif
		//VOICE
		create(voice,F,octave+1,0.5,VOICEAZ);
		appendTwo(voice,F,F,octave+1,0.25,VOICEAZ);
		append(voice,E,octave+1,0.375,VOICEAZ);
		appendThree(voice,Db,C,B/2,octave+1,0.375,VOICEAZ);
		//HARMONY
		interval(harmony,A/2,F,octave+1,0.5,CHORDAZ);
		interval(harmony,A/2,F,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,G/2,E,octave+1,0.375,CHORDAZ);
		appendInterval(harmony,F/2,Db,octave+1,0.125,CHORDAZ);
		DECRESCENDO;
		cat();
		appendInterval(harmony,E/2,C,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,D,B,octave,0.125,CHORDAZ);
	add();
		//BASS
		chord(bass,F,2*C,2*A,octave-2,0.125,BASSAZ);
		appendThree(bass,Af,A,2*C,octave-1,0.375,CHORDAZ);
		two(bass,G,F,octave,0.25,CHORDAZ);
		appendFour(bass,E,C,A/2,G/2,octave,0.5,CHORDAZ);
		DECRESCENDO;
		cat();
		appendTwo(bass,G/2,G,octave-1,0.25,CHORDAZ);
	add();
	cat();
	//MEASURE # 11
	#ifdef DEBUG
	puts("Measure # 11");
	#endif
		//VOICE
		create(voice,Db,octave+1,0.25,VOICEAZ);
		appendFour(voice,C,B/2,C,D,octave,0.5,VOICEAZ);
		//HARMONY
		interval(harmony,F,2*Db,octave,0.25,CHORDAZ);
		four(harmony,C,B/2,C,D,octave+1,0.5,CHORDAZ);
		addFour(harmony,E,D,E,F,octave,0.5,CHORDAZ);
		cat();
	add();
		//BASS
		six(bass,C,G,2*C,Gs,A,F,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 12
	#ifdef DEBUG
	puts("Measure # 12");
	#endif
		//VOICE
		three(voice,E,F,B/2,octave+1,0.75,VOICEAZ);
		//HARMONY
		chord(harmony,D/2,Cs,E,octave+1,0.25,CHORDAZ);
		appendChord(harmony,A/2,Db,F,octave+1,0.25,CHORDAZ);
		appendChord(harmony,F,G,B,octave,0.25,CHORDAZ);
	add();
		//BASS
		chord(bass,A,2*E,4*Cs,octave-2,0.125,BASSAZ);
		appendThree(bass,E,D,A/2,octave,0.375,BASSAZ);
		appendTwo(bass,G,G/2,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 13
	#ifdef DEBUG
	puts("Measure # 13");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		appendTwo(voice,G,G,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.5,CHORDAZ);
		appendTwo(harmony,G,G,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		three(bass,C,Gf,G,octave-1,0.375,BASSAZ);
		append(bass,G,octave-2,0.375,BASSAZ);
	add();
	cat();

	//MEASURE # 14
	#ifdef DEBUG
	puts("Measure # 14");
	#endif
		//VOICE
		create(voice,C,octave,0.375,VOICEAZ);
		appendThree(voice,C,B/2,C,octave,0.375,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,2*C,octave+1,0.375,CHORDAZ);
		appendChord(harmony,C,E,2*C,octave+1,0.125,CHORDAZ);
		appendChord(harmony,B/2,C,B,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,2*C,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,A,octave-3,0.75,BASSAZ);
		gradual(0,1);
		two(bass,0,G,octave-1,0.25,BASSAZ);
		append(bass,E,octave,0.5,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 15
	#ifdef DEBUG
	puts("Measure # 15");
	#endif
		//VOICE
		create(voice,Db,octave+1,0.375,VOICEAZ);
		appendThree(voice,B/2,C,D,octave+1,0.375,VOICEAZ);
		//HARMONY
		chord(harmony,Db,F,2*Db,octave+1,0.375,CHORDAZ);
		appendChord(harmony,B/2,C,E,octave+1,0.375,CHORDAZ);
	add();
		//BASS
		create(bass,A,octave-3,0.75,BASSAZ);
		two(bass,0,G,octave-1,0.25,BASSAZ);
		append(bass,F,octave,0.5,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 16
	#ifdef DEBUG
	puts("Measure # 16");
	#endif
		//VOICE
		create(voice,E,octave+1,0.375,VOICEAZ);
		appendThree(voice,C,Db,E,octave,0.375,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*E,octave+1,0.375,CHORDAZ);
		appendChord(harmony,C,E,2*C,octave+1,0.125,CHORDAZ);
		appendChord(harmony,Db,F,2*Db,octave+1,0.125,CHORDAZ);
		appendChord(harmony,E,G,2*E,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,A,octave-3,0.75,BASSAZ);
		two(bass,0,G,octave-1,0.25,BASSAZ);
		append(bass,G,octave,0.5,BASSAZ);
		add();
	add();
	cat();

	//MEASURE # 17
	#ifdef DEBUG
	puts("Measure # 17");
	#endif
		//VOICE
		create(voice,F,octave+1,0.5,VOICEAZ);
		appendTwo(voice,F,F,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,F,A,2*F,octave+1,0.5,CHORDAZ);
		appendChord(harmony,F,A,2*F,octave+1,0.125,CHORDAZ);
		appendChord(harmony,F,A,2*F,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,A,octave-3,0.75,BASSAZ);
		two(bass,0,G,octave-1,0.25,BASSAZ);
		append(bass,A,octave,0.5,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 18
	#ifdef DEBUG
	puts("Measure # 18");
	#endif
		//VOICE
		create(voice,E,octave+1,0.375,VOICEAZ);
		appendThree(voice,D,C,B/2,octave+1,0.375,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*E,octave+1,0.375,CHORDAZ);
		appendChord(harmony,Db,F,2*Db,octave+1,0.125,CHORDAZ);
		appendChord(harmony,C,E,2*C,octave+1,0.125,CHORDAZ);
		appendChord(harmony,B/2,D,B,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,A,octave-3,0.75,BASSAZ);
		two(bass,0,G,octave-1,0.25,BASSAZ);
		append(bass,G,octave,0.5,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 19
	#ifdef DEBUG
	puts("Measure # 19");
	#endif
		//VOICE
		create(voice,Db,octave+1,0.375,VOICEAZ);
		appendFour(voice,C,B/2,C,Db,octave+1,0.375,VOICEAZ);
		//HARMONY
		chord(harmony,Db,F,2*Db,octave+1,0.25,CHORDAZ);
		appendChord(harmony,C,E,2*C,octave+1,0.125,CHORDAZ);
		appendChord(harmony,B/2,D,B,octave+1,0.125,CHORDAZ);
		appendChord(harmony,C,E,2*C,octave+1,0.125,CHORDAZ);
		appendChord(harmony,Db,F,2*Db,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,A,octave-3,0.75,BASSAZ);
		two(bass,0,G,octave-1,0.25,BASSAZ);
		append(bass,E,octave,0.5,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 20
	#ifdef DEBUG
	puts("Measure # 20");
	#endif
		//VOICE
		create(voice,E,octave+1,0.25,VOICEAZ);
		appendTwo(voice,F,B/2,octave+1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*E,octave+1,0.25,CHORDAZ);
		appendChord(harmony,F,A,2*F,octave+1,0.25,CHORDAZ);
		appendFourChord(harmony,B/2,F,G,B,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,A,octave-3,0.75,BASSAZ);
		two(bass,0,G,octave-1,0.25,BASSAZ);
		appendTwo(bass,A,G,octave,0.5,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 21
	#ifdef DEBUG
	puts("Measure # 21");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		append(voice,G,octave+1,0.25,VOICEAZ);
		//HARMONY
		fourChord(harmony,C,E,G,2*C,octave+1,0.5,CHORDAZ);
		appendInterval(harmony,E,G,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.75,BASSAZ);
		two(bass,0,G,octave-1,0.25,BASSAZ);
		append(bass,E,octave,0.5,BASSAZ);
		add();
	add();
	cat();

	//MEASURE # 22 & 23
	#ifdef DEBUG
	puts("Measure # 22 & 23");
	#endif
		//VOICE
		create(voice,F,octave+1,0.25,VOICEAZ);
		appendFour(voice,Db,Db,E,F,octave+1,0.5,VOICEAZ);
		appendThree(voice,G,E,G,octave+1,0.75,VOICEAZ);
		//HARMONY
		interval(harmony,Db,F,octave,0.25,CHORDAZ);
		four(harmony,D,D,E,F,octave,0.5,CHORDAZ);
		addFour(harmony,B,B,2*C,2*Db,octave,0.5,CHORDAZ);
		cat();
		appendInterval(harmony,E,G,octave+1,0.25,CHORDAZ);
		CRESCENDO;
		appendInterval(harmony,C,E,octave+1,0.25,CHORDAZ);
		appendInterval(harmony,E,G,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,Db,Db,octave,0.25,BASSAZ);
		appendTwo(bass,G,G/2,octave-1,0.5,BASSAZ);
		appendTwo(bass,D,D,octave-1,0.25,BASSAZ);
		appendTwo(bass,G,G/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 24 & 25
	#ifdef DEBUG
	puts("Measure # 24 & 25");
	#endif
		//VOICE
		create(voice,F,octave+1,0.25,VOICEAZ);
		appendFour(voice,D,D,E,F,octave+1,0.5,VOICEAZ);
		append(voice,G,octave+1,0.25,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,C,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,Db,F,octave+1,0.25,CHORDAZ);
		four(harmony,D,D,E,F,octave+1,0.5,CHORDAZ);
		addFour(harmony,B/2,B/2,C,Db,octave+1,0.5,CHORDAZ);
		cat();
		appendInterval(harmony,E,G,octave+1,0.25,CHORDAZ);
		CRESCENDO;
		appendSilence(0.25);
		addTwo(harmony,C,C,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,Db,Db,octave-1,0.25,BASSAZ);
		appendTwo(bass,G,G/2,octave-1,0.5,BASSAZ);
		appendTwo(bass,C,G,octave-1,0.25,BASSAZ);
		CRESCENDO;
		appendFour(bass,C,E,D,C,octave,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 26
	#ifdef DEBUG
	puts("Measure # 26");
	#endif
		//VOICE
		create(voice,A,octave+1,0.375,VOICEAZ);
		appendThree(voice,A,G,Gf,octave+1,0.375,VOICEAZ);
		//HARMONY
		fourChord(harmony,A/2,C,F,A,octave+1,0.375,CHORDAZ);
		appendInterval(harmony,C,F,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,C,G,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,C,Gf,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		chord(bass,F,2*Db,2*A,octave-2,0.125,BASSAZ);
		appendThree(bass,C,A,2*F,octave-1,0.375,BASSAZ);
		appendTwo(bass,F,Ef,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 27
	#ifdef DEBUG
	puts("Measure # 27");
	#endif
		//VOICE
		create(voice,G,octave+1,0.25,VOICEAZ);
		appendFour(voice,E,D,E,F,octave+1,0.5,VOICEAZ);
		//HARMONY
		interval(harmony,C,G,octave+1,0.25,CHORDAZ);
		four(harmony,E,D,E,F,octave+1,0.5,CHORDAZ);
		addFour(harmony,C,B/2,C,Db,octave+1,0.5,CHORDAZ);
		cat();
	add();
		//BASS
		two(bass,E,C,octave,0.25,BASSAZ);
		appendTwo(bass,G,G/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 28
	#ifdef DEBUG
	puts("Measure # 28");
	#endif
		//VOICE
		create(voice,G,octave+1,0.25,VOICEAZ);
		appendFour(voice,A,A,F,F,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,Cs,E,G,octave+1,0.25,CHORDAZ);
		appendChord(harmony,Db,F,A,octave+1,0.125,CHORDAZ);
		append(harmony,A,octave+1,0.125,CHORDAZ);
		appendChord(harmony,G/2,B/2,F,octave+1,0.125,CHORDAZ);
		append(harmony,F,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,A,2*E,octave-2,0.25,BASSAZ);
		append(bass,D,octave-1,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 29
	#ifdef DEBUG
	puts("Measure # 29");
	#endif
		//VOICE
		create(voice,E,octave+1,0.5,VOICEAZ);
		append(voice,G,octave+1,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,G/2,C,E,octave+1,0.5,CHORDAZ);
		appendInterval(harmony,E,G,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,C,C/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 30
	++tempo;
	#ifdef DEBUG
	puts("Measure # 30");
	#endif
		//VOICE
		create(voice,F,octave+1,0.25,VOICEAZ);
		appendFour(voice,D,D,E,F,octave+1,0.5,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave+1,0.25,CHORDAZ);
		four(harmony,D,D,E,F,octave+1,0.5,CHORDAZ);
		addFour(harmony,B/2,B/2,C,D,octave+1,0.5,CHORDAZ);
		cat();
	add();
		//BASS
		grace(bass,G/2,G,octave-1,0.125,BASSAZ);
		append(bass,Gs,octave-1,0.125,BASSAZ);
		appendTwo(bass,A,G,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 31
	++tempo;
	#ifdef DEBUG
	puts("Measure # 31");
	#endif
		//VOICE
		three(voice,G,E,G,octave+1,0.75,VOICEAZ);
		//HARMONY
		three(harmony,G,E,G,octave+1,0.375,CHORDAZ);
		addThree(harmony,E,C,E,octave+1,0.375,CHORDAZ);
	add();
		//BASS
		two(bass,B/2,G,octave-1,0.25,BASSAZ);
		appendTwo(bass,2*E,G,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 32
	++tempo;
	#ifdef DEBUG
	puts("Measure # 32");
	#endif
		//VOICE
		create(voice,F,octave+1,0.25,VOICEAZ);
		appendFour(voice,D,D,E,F,octave+1,0.5,VOICEAZ);
		//HARMONY
		interval(harmony,Db,F,octave+1,0.25,CHORDAZ);
		four(harmony,D,D,E,F,octave+1,0.5,CHORDAZ);
		addFour(harmony,B/2,B/2,C,Db,octave+1,0.5,CHORDAZ);
		cat();
	add();
		//BASS
		two(bass,E,G,octave-1,0.25,BASSAZ);
		appendTwo(bass,G/2,G,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 33
	++tempo;
	#ifdef DEBUG
	puts("Measure # 33");
	#endif
		//VOICE
		two(voice,G,0,octave+1,0.5,VOICEAZ);
		appendTwo(voice,C,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		two(harmony,E,G,octave+1,0.25,CHORDAZ);
		appendSilence(0.25);
		appendTwo(harmony,C,C,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,C,G,octave-1,0.25,BASSAZ);
		appendTwo(bass,G/2,G,octave-1,0.5,BASSAZ);
	add();
	cat();
	tempo-=4;
	//MEASURE # 34
	#ifdef DEBUG
	puts("Measure # 34");
	#endif
		//VOICE
		create(voice,A,octave+1,0.375,VOICEAZ);
		appendThree(voice,A,G,Gf,octave+1,0.375,VOICEAZ);
		//HARMONY
		chord(harmony,C,F,A,octave+1,0.375,CHORDAZ);
		three(harmony,A,G,Gf,octave+1,0.375,CHORDAZ);
		addThree(harmony,C,C,C,octave+1,0.375,CHORDAZ);
		cat();
	add();
		//BASS
		six(bass,F/2,C,A,2*F,2*E,2*Ef,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 35
	#ifdef DEBUG
	puts("Measure # 35");
	#endif
		//VOICE
		create(voice,G,octave+1,0.25,VOICEAZ);
		appendFour(voice,E,D,E,F,octave+1,0.5,VOICEAZ);
		//HARMONY
		interval(harmony,C,G,octave+1,0.25,CHORDAZ);
		four(harmony,E,D,E,F,octave+1,0.5,CHORDAZ);
		addFour(harmony,C,B/2,C,Db,octave+1,0.5,CHORDAZ);
		cat();
	add();
		//BASS
		two(bass,E,C,octave,0.25,BASSAZ);
		appendTwo(bass,G,G/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 36
	#ifdef DEBUG
	puts("Measure # 36");
	#endif
		//VOICE
		three(voice,G,A,F,octave+1,0.75,VOICEAZ);
		//HARMONY
		chord(harmony,Cs,E,G,octave+1,0.25,CHORDAZ);
		appendChord(harmony,Db,F,A,octave+1,0.25,CHORDAZ);
		appendChord(harmony,G,B,2*F,octave,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,A,2*E,octave-2,0.25,BASSAZ);
		appendTwo(bass,Db,G,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 37
	#ifdef DEBUG
	puts("Measure # 37");
	#endif
		//VOICE
		create(voice,E,octave+1,FERMATA(0.5),VOICEAZ);
		appendTwo(voice,G,G,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,G/2,C,E,octave+1,FERMATA(0.5),CHORDAZ);
		appendTwo(harmony,G,G,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-1,0.25,BASSAZ);
		append(bass,C,octave,FERMATA(0.5)-0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 38
	#ifdef DEBUG
	puts("Measure # 38");
	#endif
		//VOICE
		create(voice,C,octave+1,0.375,VOICEAZ);
		appendThree(voice,C,B/2,C,octave+1,0.375,VOICEAZ);
		//HARMONY
		interval(harmony,E/2,C,octave+1,0.375,CHORDAZ);
		appendInterval(harmony,E,C,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,D,B,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,C,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,C,G,octave-1,0.25,BASSAZ);
		append(bass,A,octave-1,0.25,BASSAZ);
		appendTwo(bass,G,G/2,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 39
	#ifdef DEBUG
	puts("Measure # 39");
	#endif
		//VOICE
		create(voice,Db,octave,0.375,VOICEAZ);
		appendThree(voice,B/2,C,D,octave+1,0.375,VOICEAZ);
		//HARMONY
		interval(harmony,F/2,Db,octave+1,0.375,CHORDAZ);
		appendInterval(harmony,D,B,octave,0.125,CHORDAZ);
		appendInterval(harmony,E/2,C,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,F/2,Db,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,C,G,octave-1,0.25,BASSAZ);
		append(bass,B,octave-1,0.25,BASSAZ);
		appendTwo(bass,A,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 40 & 41
	#ifdef DEBUG
	puts("Measure # 40 & 41");
	#endif
		//VOICE
		create(voice,E,octave+1,0.375,VOICEAZ);
		appendThree(voice,C,D,E,octave+1,0.375,VOICEAZ);
		append(voice,F,octave+1,0.5,VOICEAZ);
		appendTwo(voice,F,F,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,G/2,E,octave+1,0.375,CHORDAZ);
		appendInterval(harmony,E/2,C,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,F/2,Db,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,G/2,E,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,A/2,F,octave+1,0.5,CHORDAZ);
		CRESCENDO;
		interval(harmony,A/2,F,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,Af/2,F,octave+1,0.125,CHORDAZ);
		DECRESCENDO;
		cat();
	add();
		//BASS
		six(bass,C,G,2*D,2*C,B,Bf,octave-1,0.75,BASSAZ);
		appendChord(bass,F/2,C,A,octave-1,0.125,BASSAZ);
		CRESCENDO;
		appendThree(bass,Af,A,2*C,octave-1,0.375,BASSAZ);
		two(bass,G,F,octave,0.25,BASSAZ);
		DECRESCENDO;
		cat();
	add();
	cat();

	//MEASURE # 42
	#ifdef DEBUG
	puts("Measure # 42");
	#endif
		//VOICE
		create(voice,E,octave+1,0.375,VOICEAZ);
		appendThree(voice,D,C,B/2,octave+1,0.375,VOICEAZ);
		//HARMONY
		interval(harmony,G/2,E,octave+1,0.375,CHORDAZ);
		appendInterval(harmony,F/2,Db,octave+1,0.125,CHORDAZ);
		DECRESCENDO;
		appendChord(harmony,E,Af,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,D,G,B,octave,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,2*E,G,octave-1,0.25,BASSAZ);
		appendTwo(bass,Gs,E,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 43
	#ifdef DEBUG
	puts("Measure # 43");
	#endif
		//VOICE
		create(voice,D,octave+1,0.25,VOICEAZ);
		appendFour(voice,C,B/2,C,D,octave+1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,E,B,2*D,octave,0.25,CHORDAZ);
		appendChord(harmony,E,A,2*C,octave,0.125,CHORDAZ);
		append(harmony,B,octave+1,0.125,CHORDAZ);
		appendTwo(harmony,C,D,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,A,octave-1,0.25,BASSAZ);
		append(bass,A,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 44
	#ifdef DEBUG
	puts("Measure # 44");
	#endif
		//VOICE
		three(voice,E,F,B/2,octave+1,0.75,VOICEAZ);
		//HARMONY
		chord(harmony,G/2,Cs,E,octave+1,0.25,CHORDAZ);
		appendChord(harmony,A,C,E,octave+1,0.25,CHORDAZ);
		appendChord(harmony,F,G,B,octave,0.25,CHORDAZ);
	add();
		//BASS
		chord(bass,A/2,E,2*Cs,octave-1,0.125,BASSAZ);
		appendThree(bass,Bf,A,Db,octave-1,0.375,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 45
	#ifdef DEBUG
	puts("Measure # 45");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		appendSilence(0.25);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.5,CHORDAZ);
		appendTwo(harmony,G,G,octave,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,C,C/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 46
	#ifdef DEBUG
	puts("Measure # 46");
	#endif
		//HARMONY
		interval(harmony,E/2,C,octave+1,0.375,CHORDAZ);
		three(harmony,C,B/2,C,octave+1,0.375,CHORDAZ);
		addInterval(harmony,E,G,octave,0.375,CHORDAZ);
		cat();
		//BASS
		six(bass,C,G,2*C,2*C,B,2*C,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 47
	#ifdef DEBUG
	puts("Measure # 47");
	#endif
		//HARMONY
		two(harmony,Cs,D,octave+1,0.25,CHORDAZ);
		addTwo(harmony,B/2,C,octave+1,0.25,CHORDAZ);
		create(harmony,G,octave,0.25,CHORDAZ);
		add();
		CRESCENDO;
		two(harmony,G,2*C,octave+1,0.25,CHORDAZ);
		addInterval(harmony,C,E,octave,0.25,CHORDAZ);
		two(harmony,D,C,octave+2,0.25,CHORDAZ);
		addInterval(harmony,E,G,octave+1,0.25,CHORDAZ);
		cat();
		DECRESCENDO;
		cat();
		//BASS
		three(bass,Ds,E,G,octave,0.375,BASSAZ);
		CRESCENDO;
		three(bass,B/2,D,C,octave+1,0.375,BASSAZ);
		DECRESCENDO;
		cat();
	add();
	cat();
	//MEASURE # 48
	#ifdef DEBUG
	puts("Measure # 48");
	#endif
		//HARMONY
		two(harmony,G,E,octave+1,0.25,CHORDAZ);
		addInterval(harmony,G/2,C,octave+1,0.25,CHORDAZ);
		two(harmony,A,F,octave+1,0.25,CHORDAZ);
		addInterval(harmony,A,Db,octave,0.25,CHORDAZ);
		cat();
		appendChord(harmony,Db,F,A,octave,0.125,CHORDAZ);
		appendChord(harmony,G,B,2*E,octave,0.125,CHORDAZ);
		//BASS
		interval(bass,E/2,C,octave,0.25,BASSAZ);
		appendInterval(bass,F/2,Db,octave,0.25,BASSAZ);
		appendInterval(bass,Db,A,octave-1,0.125,BASSAZ);
		append(bass,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 49
	#ifdef DEBUG
	puts("Measure # 49");
	#endif
		//HARMONY
		interval(harmony,G/2,C,octave+1,0.25+FERMATA(0.25),CHORDAZ);
		create(harmony,F,octave,0.25,CHORDAZ);
		append(harmony,E,octave,FERMATA(0.25),CHORDAZ);
		add();
		//BASS
		create(bass,A,octave-1,0.25,BASSAZ);
		append(bass,G,octave-1,FERMATA(0.25),BASSAZ);
		create(bass,C,octave-1,0.25+FERMATA(0.25),BASSAZ);
		add();
	add();
	cat();
}


int main(int argc, char **argv){
	tempo=85;
	C=G/2;
	song();
	echo(10,0.3,4);

	puts("Writing wav file: las mananitas.wav");
	exportToWav("Las Mañanitas.wav");
}
