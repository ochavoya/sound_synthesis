#include "soundlib.h"

#define VOICEAZ 150
#define CHORDAZ 30
#define BASSAZ 90

#define DEBUG 1

double (*voice)(double) = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double) = oldCircleOfRa;

double eFlatKey, cKey;

short octave = 0;

void bassPattern(short octave,double x, double y , double z, double u){
	create(bass,x,octave,0.375,BASSAZ);
	append(bass,y,octave,0.125,BASSAZ);
	append(bass,z,octave,0.25,BASSAZ);
	append(bass,u,octave,0.25,BASSAZ);
}

void bassPatternBis(short octave,double x, double y , double z, double u,double v){
	create(bass,x,octave,0.375,BASSAZ);
	append(bass,y,octave,0.125,BASSAZ);
	append(bass,z,octave,0.25,BASSAZ);
	append(bass,u,octave,0.125,BASSAZ);
	append(bass,v,octave,0.125,BASSAZ);
}

void intro(void){
	C = cKey;
	FORTE;
	//MEASURE # 1
	#ifdef DEBUG
	puts("Measure # 1");
	#endif
		//HARMONY
		silence(0.25);
		appendTwo(harmony,E,G,octave,0.25,CHORDAZ);
		appendIntervalMarcato(harmony,E,2*C,octave,0.25,CHORDAZ);
		two(harmony,C,D,octave+1,0.25,CHORDAZ);
		create(harmony,E,octave,0.25,CHORDAZ);
		add();
		CRESCENDO;
		cat();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendChordMarcato(bass,C,E,G,octave,0.25,BASSAZ);
		appendSilence(0.25);
		appendChord(bass,C,E,G,octave,0.25,BASSAZ);
	add();
	//MEASURE # 2
	#ifdef DEBUG
	puts("Measure # 2 & 3");
	#endif
		//HARMONY
		chordMarcato(harmony,G/2,C,E,octave+1,1.25,CHORDAZ);
		appendTwo(harmony,C,C,octave+1,0.25,CHORDAZ);
		appendChord(harmony,E,Bf,2*D,octave,0.25,CHORDAZ);
		appendTwo(harmony,C,E,octave+1,0.25,CHORDAZ);		 
		//BASS
		intervalMarcato(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendTwo(bass,G,A,octave-1,0.25,BASSAZ);
		four(bass,B/2,C,D,Ds,octave,0.5,BASSAZ);
		CRESCENDO;
		append(bass,E,octave,0.5,BASSAZ);
		appendInterval(bass,C,Bf,octave-1,0.5,BASSAZ);
		cat();
	add();
	cat();
	//MEASURE # 4 & 5
	#ifdef DEBUG
	puts("Measure # 4 & 5");
	#endif
		//HARMONY
		create(harmony,Db,octave+1,0.5,CHORDAZ);
		append(harmony,C,octave+1,0.75,CHORDAZ);
		interval(harmony,F,A,octave,1.25,CHORDAZ);
		add();
		appendInterval(harmony,F,A,octave,0.125,CHORDAZ);
		appendInterval(harmony,G,B,octave,0.125,CHORDAZ);
		appendInterval(harmony,A,2*C,octave,0.25,CHORDAZ);
		appendInterval(harmony,G,B,octave,0.125,CHORDAZ);
		appendInterval(harmony,F,A,octave,0.125,CHORDAZ);
		//BASS
		marcato(bass,F,octave-2,0.25,BASSAZ);
		six(bass,C,D,F,G,Af,A,octave-1,0.75,BASSAZ);
		CRESCENDO;
		cat();
		marcato(bass,Db,octave,1.0,BASSAZ);
		cat();
	add();
	cat();
	//MEASURE # 6 & 7
	#ifdef DEBUG
	puts("Measure # 6 & 7");
	#endif
		//HARMONY
		interval(harmony,E,2*C,octave,0.25,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		appendInterval(harmony,Db,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.75,CHORDAZ);
		appendInterval(harmony,Db,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.125,CHORDAZ);
		two(harmony,B,2*Db,octave,0.25,CHORDAZ);
		create(harmony,F,octave,0.25,CHORDAZ);
		add();
		cat();
		//BASS
		marcato(bass,G,octave-1,0.75,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.75,BASSAZ);
		appendInterval(bass,G,2*D,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 8
	#ifdef DEBUG
	puts("Measure # 8");
	#endif
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.625,CHORDAZ);
		appendSilence(0.375);
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendTwoEstacato(bass,G,G,octave,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
	add();
	cat();
}

void start(void){
	MESSOFORTE;
	C = eFlatKey;
	//MEASURE # 9
	#ifdef DEBUG
	puts("Measure # 9");
	#endif
		//HARMONY
		silence(0.5);
		appendChord(harmony,E,A,2*C,octave-1,0.5,CHORDAZ);
		//BASS
		bassPattern(octave-3,A,2*E,2*A,2*E);
	add();

	//MEASURE # 10
	#ifdef DEBUG
	puts("Measure # 10");
	#endif
		//HARMONY
		silence(0.5);
		appendChord(harmony,E,A,2*C,octave-1,0.5,CHORDAZ);
		//BASS
		bassPattern(octave-3,A,2*E,2*A,2*E);
	add();
	cat();

	//MEASURE # 11
	#ifdef DEBUG
	puts("Measure # 11");
	#endif
		//VOICE 
		four(voice,0,C,C,D,octave,1.0,VOICEAZ);
		//HARMONY
		four(harmony,0,C,C,D,octave,1.0,CHORDAZ);
		addFour(harmony,0,A,A,B,octave-1,1.0,CHORDAZ);
	add();
		//BASS
		bassPattern(octave-3,A,2*E,2*A,2*E);
	add();
	cat();

	//MEASURE # 12
	#ifdef DEBUG
	puts("Measure # 12");
	#endif
		//VOICE 
		create(voice,E,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		//HARMONY
		create(harmony,E,octave,0.125,CHORDAZ);
		append(harmony,E,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.125,CHORDAZ);
		append(harmony,F,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.25,CHORDAZ);
		create(harmony,C,octave,0.125,CHORDAZ);
		append(harmony,C,octave,0.25,CHORDAZ);
		append(harmony,C,octave,0.125,CHORDAZ);
		append(harmony,Db,octave,0.25,CHORDAZ);
		append(harmony,C,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		bassPattern(octave-3,A,2*E,2*A,2*E);
	add();
	cat();
	//MEASURE # 13
	#ifdef DEBUG
	puts("Measure # 13");
	#endif
		//VOICE 
		create(voice,F,octave,0.25,CHORDAZ);
		append(voice,E,octave,0.375,CHORDAZ);
		three(voice,A/2,C,E,octave,0.375,CHORDAZ);
		cat();
		//HARMONY
		create(harmony,F,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.375,CHORDAZ);
		three(harmony,A/2,C,E,octave,0.375,CHORDAZ);
		CRESCENDO;
		cat();
		create(harmony,Db,octave,0.25,CHORDAZ);
		append(harmony,C,octave,0.375,CHORDAZ);
		add();
	add();
		//BASS
		bassPattern(octave-3,A,2*E,2*A,2*E);
	add();
	cat();

	//MEASURE # 14
	#ifdef DEBUG
	puts("Measure # 14");
	#endif
		//VOICE 
		create(voice,C,octave+1,0.125,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		append(voice,Db,octave,0.125,VOICEAZ);
		append(voice,C,octave,0.125,VOICEAZ);
		//HARMONY
		create(harmony,C,octave+1,0.125,CHORDAZ);
		append(harmony,B,octave,0.25,CHORDAZ);
		append(harmony,A,octave,0.125,CHORDAZ);
		append(harmony,E,octave,0.25,CHORDAZ);
		append(harmony,Db,octave,0.125,CHORDAZ);
		append(harmony,C,octave,0.125,CHORDAZ);
		create(harmony,E,octave+1,0.125,CHORDAZ);
		append(harmony,D,octave,0.25,CHORDAZ);
		append(harmony,C,octave,0.125,CHORDAZ);
		append(harmony,C,octave,0.25,CHORDAZ);
		append(harmony,B,octave,0.125,CHORDAZ);
		append(harmony,A,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		bassPattern(octave-1,A/2,C,E,E/2);
		silence(0.5);
		append(bass,A,octave-1,0.25,BASSAZ);
		add();
	add();
	cat();

	//MEASURE # 15
	#ifdef DEBUG
	puts("Measure # 15");
	#endif
		//VOICE 
		create(voice,B,octave-1,0.625,VOICEAZ);
		appendThree(voice,B,B,2*C,octave-1,0.375,VOICEAZ);
		//HARMONY
		create(harmony,B,octave-1,0.625,CHORDAZ);
		appendThree(harmony,B,B,2*C,octave-1,0.375,CHORDAZ);
		create(harmony,Gs,octave-1,0.625,CHORDAZ);
		appendThree(harmony,Gs,Gs,A,octave-1,0.375,CHORDAZ);
		add();
	add();
		//BASS
		bassPattern(octave-2,Gs,B,2*D,E/2);
		silence(0.5);
		append(bass,E,octave,0.25,BASSAZ);
		add();
	add();
	cat();

	//MEASURE # 16
	#ifdef DEBUG
	puts("Measure # 16");
	#endif
		//VOICE 
		create(voice,D,octave,0.125,VOICEAZ);
		append(voice,D,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		appendTwo(voice,F,E,octave,0.5,VOICEAZ);
		//HARMONY
		create(harmony,D,octave,0.125,CHORDAZ);
		append(harmony,D,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.125,CHORDAZ);
		appendTwo(harmony,F,E,octave,0.5,CHORDAZ);
		create(harmony,B,octave-1,0.125,CHORDAZ);
		append(harmony,B,octave-1,0.25,CHORDAZ);
		append(harmony,C,octave,0.125,CHORDAZ);
		appendTwo(harmony,Db,C,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		bassPattern(octave-1,Gs/2,D,E,E/2);
	add();
	cat();

	//MEASURE # 17 & 18
	#ifdef DEBUG
	puts("Measure # 17 & 18");
	#endif
		//VOICE 
		create(voice,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.375,VOICEAZ);
		appendFour(voice,B,B,A,Gs,octave,0.5,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		append(voice,D,octave,0.25,VOICEAZ);
		//HARMONY
		create(harmony,F,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.375,CHORDAZ);
		create(harmony,Gs,octave-1,0.625,CHORDAZ);
		add();
		four(harmony,B,B,A,Gs,octave,0.5,CHORDAZ);
		append(harmony,E,octave,0.25,CHORDAZ);
		four(harmony,D,D,C,D,octave,0.5,CHORDAZ);
		append(harmony,B,octave-1,0.25,CHORDAZ);
		add();
		DECRESCENDO;
		cat();
		create(harmony,E,octave,0.125,CHORDAZ);
		append(harmony,E,octave,0.25,CHORDAZ);
		append(harmony,D,octave,0.25,CHORDAZ);
		create(harmony,Gs,octave-1,0.125,CHORDAZ);
		append(harmony,Gs,octave-1,0.25,CHORDAZ);
		append(harmony,B,octave-1,0.25,CHORDAZ);
		add();
		cat();
	add();
		//BASS
		bassPattern(octave-1,B/2,D,E,E/2);
		bassPattern(octave-1,B/2,D,E,E/2);
		cat();
	add();
	cat();

	//MEASURE # 19
	#ifdef DEBUG
	puts("Measure # 19");
	#endif
		//VOICE 
		create(voice,C,octave,0.625,VOICEAZ);
		appendThree(voice,C,C,D,octave,0.375,VOICEAZ);
		//HARMONY
		create(harmony,C,octave,0.625,CHORDAZ);
		appendThree(harmony,C,C,D,octave,0.375,CHORDAZ);
		create(harmony,A,octave-1,0.625,CHORDAZ);
		appendThree(harmony,A,A,B,octave-1,0.375,CHORDAZ);
		add();
	add();
		//BASS
		bassPattern(octave-2,A,2*C,2*E,E);
	add();
	cat();

	//MEASURE # 20
	#ifdef DEBUG
	puts("Measure # 20");
	#endif
		//VOICE
		create(voice,E,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		//HARMONY
		create(harmony,E,octave,0.125,CHORDAZ);
		append(harmony,E,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.125,CHORDAZ);
		append(harmony,F,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.25,CHORDAZ);
		create(harmony,C,octave,0.125,CHORDAZ);
		append(harmony,C,octave,0.25,CHORDAZ);
		append(harmony,C,octave,0.125,CHORDAZ);
		append(harmony,D,octave,0.25,CHORDAZ);
		append(harmony,C,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		bassPattern(octave-2,A,2*C,E,E);
	add();
	cat();

	//MEASURE # 21
	#ifdef DEBUG
	puts("Measure # 21");
	#endif
		//VOICE 
		create(voice,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.375,VOICEAZ);
		appendThree(voice,A/2,C,E,octave,0.375,VOICEAZ);
		//HARMONY
		create(harmony,F,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.375,CHORDAZ);
		three(harmony,A/2,C,E,octave,0.375,CHORDAZ);
		CRESCENDO; cat();
		create(harmony,Db,octave,0.25,CHORDAZ);
		append(harmony,C,octave,0.375,CHORDAZ);
		add();
	add();
		//BASS
		bassPattern(octave-2,A,2*C,E,E);
	add();
	cat();

	//MEASURE # 22
	#ifdef DEBUG
	puts("Measure # 22");
	#endif
		//VOICE 
		create(voice,C,octave+1,0.125,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		appendTwo(voice,F,E,octave,0.25,VOICEAZ);
		//HARMONY
		create(harmony,C,octave+1,0.125,CHORDAZ);
		append(harmony,B,octave,0.25,CHORDAZ);
		append(harmony,A,octave,0.125,CHORDAZ);
		append(harmony,G,octave,0.25,CHORDAZ);
		appendTwo(harmony,F,E,octave,0.25,CHORDAZ);
		create(harmony,E,octave,0.125,CHORDAZ);
		append(harmony,D,octave,0.25,CHORDAZ);
		append(harmony,C,octave,0.125,CHORDAZ);
		append(harmony,Bf,octave-1,0.25,CHORDAZ);
		appendTwo(harmony,As,G,octave,0.25,CHORDAZ);
		add();

	add();
		//BASS
		create(bass,A,octave-2,0.125,BASSAZ);
		append(bass,B,octave-2,0.25,BASSAZ);
		append(bass,C,octave-1,0.125,BASSAZ);
		appendTwo(bass,Cs,A/2,octave-1,0.5,BASSAZ);
	add();
	cat();

	//MEASURE # 23
	#ifdef DEBUG
	puts("Measure # 23");
	#endif
		//VOICE 
		create(voice,Db,octave,0.625,VOICEAZ);
		appendThree(voice,Db,Db,E,octave,0.375,VOICEAZ);
		//HARMONY
		create(harmony,Db,octave,0.625,CHORDAZ);
		appendThree(harmony,Db,Db,E,octave,0.375,CHORDAZ);
		create(harmony,F,octave-1,0.625,CHORDAZ);
		appendThree(harmony,A,A,A,octave-1,0.375,CHORDAZ);
		add();
	add();
		//BASS
		bassPattern(octave-2,Db,A,2*E,A);
	add();
	cat();

	//MEASURE # 24
	#ifdef DEBUG
	puts("Measure # 24");
	#endif
		//VOICE 
		create(voice,F,octave,0.125,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		append(voice,F,octave,0.125,VOICEAZ);
		appendTwo(voice,B,Gs,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,A/2,Db,F,octave,0.125,CHORDAZ);
		appendChord(harmony,A/2,Db,F,octave,0.25,CHORDAZ);
		appendChord(harmony,A/2,Db,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,Gf,B,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,Gs,octave,0.25,CHORDAZ);
	add();
		//BASS
		chord(bass,Db,A,2*F,octave-2,0.5,BASSAZ);
		appendInterval(bass,Ef,2*Ef,octave-2,0.25,BASSAZ);
		appendInterval(bass,D,2*D,octave-2,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 25
	#ifdef DEBUG
	puts("Measure # 25");
	#endif
		//VOICE 
		create(voice,A,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.375,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,F,octave,0.125,VOICEAZ);
		//HARMONY
		create(harmony,A,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.375,CHORDAZ);
		append(harmony,E,octave,0.125,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
		append(harmony,F,octave,0.125,CHORDAZ);

		create(harmony,A,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.375,CHORDAZ);
		append(harmony,C,octave,0.375,CHORDAZ);

		add();

	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.375,BASSAZ);
		append(bass,E,octave-1,0.125,BASSAZ);
		append(bass,A,octave-1,0.25,BASSAZ);
		append(bass,E,octave-2,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 26
	#ifdef DEBUG
	puts("Measure # 26");
	#endif
		//VOICE 
		create(voice,E,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		append(voice,D,octave,0.125,VOICEAZ);
		append(voice,C,octave,0.25,VOICEAZ);
		append(voice,B,octave-1,0.25,VOICEAZ);
		//HARMONY
		create(harmony,E,octave,0.125,CHORDAZ);
		append(harmony,E,octave,0.25,CHORDAZ);
		append(harmony,D,octave,0.125,CHORDAZ);
		append(harmony,E,octave,0.25,CHORDAZ);
		append(harmony,B,octave-1,0.25,CHORDAZ);

		create(harmony,B,octave-1,0.125,CHORDAZ);
		append(harmony,B,octave-1,0.25,CHORDAZ);
		append(harmony,Gs,octave-1,0.125,CHORDAZ);
		append(harmony,Gs,octave-1,0.25,CHORDAZ);
		add();

	add();
		//BASS
		bassPattern(octave-1,Gs/2,E,E,E/2);
	add();
	cat();
	C = cKey;
	//MEASURE # 27
	#ifdef DEBUG
	puts("Measure # 27");
	#endif
		//VOICE 
		create(voice,C,octave,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave-1,1.0,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-1,0.25,BASSAZ);
		appendTwoEstacato(bass,G,G,octave-2,0.25,BASSAZ);
		appendTwoMarcato(bass,G,G,octave-2,0.5,BASSAZ);
	add();
	cat();
}

void repeat(short end){
	C = cKey;
	MESSOFORTE;
	//MEASURE # 28
	#ifdef DEBUG
	puts("Measure # 28");
	#endif
		//VOICE 
		silence(0.25);
		appendSix(voice,E,G,C,0,2*C,2*D,octave,0.75,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendTwo(harmony,E,G,octave,0.25,CHORDAZ);
		appendIntervalMartelato(harmony,E,2*C,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		create(harmony,E,octave,0.25,CHORDAZ);
		addTwo(harmony,C,D,octave+1,0.25,CHORDAZ);
		CRESCENDO;
		cat();
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendChordMarcato(bass,C,E,G,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		appendChordEstacato(bass,C,E,G,octave-1,0.25,BASSAZ);
	add();
	//MEASURE # 29 & 30
	#ifdef DEBUG
	puts("Measure # 29 & 30");
	#endif
		//VOICE 
		create(voice,E,octave+1,1.25,VOICEAZ);
		appendTwo(voice,C,C,octave+1,0.25,VOICEAZ);
		append(voice,C,octave+1,0.25,VOICEAZ);
		appendTwo(voice,B,A,octave,0.25,VOICEAZ);
		//HARMONY
		chordMartelato(harmony,G/2,C,E,octave+1,1.25,CHORDAZ);

		two(harmony,C,C,octave+1,0.25,CHORDAZ);
		append(harmony,C,octave+1,0.25,CHORDAZ);
		appendTwo(harmony,B,A,octave,0.25,CHORDAZ);
		two(harmony,G,G,octave,0.25,CHORDAZ);
		append(harmony,G,octave,0.25,CHORDAZ);
		appendTwo(harmony,F,E,octave,0.25,CHORDAZ);
		add();
		cat();
	add();
		//BASS
		intervalMarcato(bass,C,C/2,octave-1,0.25,CHORDAZ);
		six(bass,G,A,B,2*C,2*D,2*Ds,octave-1,0.75,CHORDAZ);
		CRESCENDO;
		cat();
		appendMarcato(bass,E,octave,0.75,CHORDAZ);
		appendTwo(bass,D,C,octave,0.25,CHORDAZ);
	add();
	cat();

	//MEASURE # 31 & 32
	#ifdef DEBUG
	puts("Measure # 31 & 32");
	#endif
		//VOICE 
		create(voice,F,octave,1.25,VOICEAZ);
		appendSix(voice,D,F,B,0,B,2*C,octave,0.75,VOICEAZ);
		//HARMONY
		create(harmony,F,octave,1.25,CHORDAZ);
		appendSix(harmony,D,F,B,0,B,2*C,octave,0.75,CHORDAZ);

		four(harmony,0,D,Cs,C,octave,1.0,CHORDAZ);
		append(harmony,B/2,octave,0.25,CHORDAZ);
		appendSilence(0.25);
		append(harmony,D,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		append(harmony,F,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,G,octave-2,0.375,BASSAZ);
		append(bass,D,octave-1,0.125,BASSAZ);
		appendTwo(bass,G,D,octave-1,0.5,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		appendChord(bass,F,G,B,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		appendChord(bass,G,B,2*D,octave-1,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 33 & 34
	#ifdef DEBUG
	puts("Measure # 33 & 34");
	#endif
		//VOICE 
		create(voice,D,octave+1,1.25,VOICEAZ);
		appendTwo(voice,C,C,octave+1,0.25,VOICEAZ);
		append(voice,C,octave+1,0.25,VOICEAZ);
		appendTwo(voice,B,A,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,F,B,2*D,octave,1.25,CHORDAZ);
		two(harmony,C,C,octave+1,0.25,CHORDAZ);
		append(harmony,C,octave+1,0.25,CHORDAZ);
		appendTwo(harmony,B,A,octave,0.25,CHORDAZ);
		two(harmony,A,A,octave+1,0.25,CHORDAZ);
		append(harmony,A,octave+1,0.25,CHORDAZ);
		append(harmony,F,octave,0.25,CHORDAZ);
		add();
		cat();

	add();
		//BASS
		interval(bass,G,2*G,octave-2,0.25,BASSAZ);
		appendSix(bass,G,A,B,2*C,2*D,2*E,octave-1,0.75,CHORDAZ);
		appendMartelato(bass,F,octave,0.75,CHORDAZ);
		append(bass,D,octave,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 35 & 36
	#ifdef DEBUG
	puts("Measure # 35 & 36");
	#endif
		//VOICE 
		create(voice,E,octave,1.25,VOICEAZ);
		appendTwo(voice,E,G,octave,0.25,VOICEAZ);
		append(voice,C,octave+1,0.125,VOICEAZ);
		appendSilence(0.125);
		appendTwo(voice,C,D,octave+1,0.25,VOICEAZ);
		//HARMONY
		create(harmony,E,octave,1.25,CHORDAZ);
		silence(0.25);
		appendTwo(harmony,C,C,octave,0.25,CHORDAZ);
		append(harmony,C,octave,0.25,CHORDAZ);
		appendTwo(harmony,B,A,octave-1,0.25,CHORDAZ);
		append(harmony,E,octave-1,0.25,CHORDAZ);
		add();
		appendTwo(harmony,E,G,octave,0.25,CHORDAZ);
		appendIntervalMartelato(harmony,E,2*C,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		two(harmony,C,D,octave+1,0.25,CHORDAZ);
		create(harmony,E,octave,0.25,CHORDAZ);
		add();
		cat();
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendChordMarcato(bass,C,E,G,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		appendChordEstacato(bass,C,E,G,octave-1,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 37 & 38
	#ifdef DEBUG
	puts("Measure # 37 & 38");
	#endif
		//VOICE 
		create(voice,E,octave+1,1.25,VOICEAZ);
		appendTwo(voice,C,C,octave+1,0.25,VOICEAZ);
		append(voice,D,octave+1,0.25,VOICEAZ);
		appendTwo(voice,C,E,octave+1,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,G/2,C,E,octave+1,1.25,CHORDAZ);
		appendTwo(harmony,C,C,octave+1,0.25,CHORDAZ);
		appendChord(harmony,E,Bf,2*D,octave,0.25,CHORDAZ);
		appendTwo(harmony,C,E,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		intervalMartelato(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendSix(bass,G,A,B,2*C,2*D,2*Ds,octave-1,0.75,BASSAZ);
		appendMartelato(bass,E,octave,0.5,BASSAZ);
		appendInterval(bass,C,Bf,octave-1,0.5,BASSAZ);
	add();
	cat();

	//MEASURE # 39 & 40
	#ifdef DEBUG
	puts("Measure # 39 & 40");
	#endif
		//VOICE 
		create(voice,Db,octave+1,0.5,VOICEAZ);
		append(voice,C,octave+1,0.75,VOICEAZ);
		appendTwo(voice,A,B,octave,0.25,VOICEAZ);
		append(voice,C,octave+1,0.25,VOICEAZ);
		appendTwo(voice,B,A,octave,0.25,VOICEAZ);
		//HARMONY
		create(harmony,Db,octave+1,0.5,CHORDAZ);
		append(harmony,C,octave+1,0.75,CHORDAZ);
		appendTwo(harmony,A,B,octave,0.25,CHORDAZ);
		append(harmony,C,octave+1,0.25,CHORDAZ);
		appendTwo(harmony,B,A,octave,0.25,CHORDAZ);
		interval(harmony,F,A,octave,1.25,CHORDAZ);
		appendTwo(harmony,F,G,octave,0.25,CHORDAZ);
		append(harmony,A,octave+1,0.25,CHORDAZ);
		appendTwo(harmony,G,F,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		marcato(bass,F,octave-2,0.25,BASSAZ);
		appendSix(bass,C,Db,F,G,Gs,A,octave-1,0.75,BASSAZ);
		appendMartelato(bass,Db,octave,1.0,BASSAZ);
	add();
	cat();


	//MEASURE # 41 & 42
	#ifdef DEBUG
	puts("Measure # 41 & 42");
	#endif
		//VOICE 
		create(voice,C,octave+1,0.25,VOICEAZ);
		appendTwo(voice,E,F,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.5,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,G,F,octave,0.25,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		appendTwo(voice,B,2*D,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave,0.25,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		appendInterval(harmony,Db,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.75,CHORDAZ);
		appendInterval(harmony,Db,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.125,CHORDAZ);
		appendInterval(harmony,F,A,octave,0.25,CHORDAZ);
		create(harmony,F,octave,0.25,CHORDAZ);
		two(harmony,B,2*D,octave,0.25,CHORDAZ);
		add();
		cat();
	add();
		//BASS
		marcato(bass,G,octave-1,0.75,BASSAZ);
		appendEstacato(bass,G,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.75,BASSAZ);
		appendInterval(bass,G,2*D,octave-2,0.25,BASSAZ);
	add();
	cat();

	if(!end){
	//MEASURE # 43
	#ifdef DEBUG
	puts("Measure # 43");
	#endif
		//VOICE 
		create(voice,C,octave+1,0.625,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.625,CHORDAZ);
		CRESCENDO;
	add();
		//BASS
		intervalMartelato(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,B,octave-2,0.125,BASSAZ);
		appendMartelato(bass,D,octave-1,0.125,BASSAZ);
		append(bass,C,octave-1,0.125,BASSAZ);
		CRESCENDO;
		martelato(bass,E,octave-1,0.125,BASSAZ);
		append(bass,D,octave-1,0.125,BASSAZ);
		appendMartelato(bass,F,octave-1,0.125,BASSAZ);
		append(bass,E,octave-1,0.125,BASSAZ);
		DECRESCENDO;
		cat();
	add();
	cat();
	}
	else{
	//MEASURE # 44
	#ifdef DEBUG
	puts("Measure # 44");
	#endif
		//VOICE 
		create(voice,C,octave+1,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,1.0,CHORDAZ);
		appendChordMartelato(harmony,E,G,2*C,octave,0.5,CHORDAZ);
	add();
		//BASS
		intervalMartelato(bass,C,2*C,octave-2,1.0,BASSAZ);
		appendIntervalMartelato(bass,C,2*C,octave-2,0.5,BASSAZ);
	add();
	cat();
	}
}

void song(void){
	intro();
	start();
	cat();
	repeat(0);
	cat();
	repeat(1);
	cat();
}

int main(int argc, char **argv){
	tempo=90;
	cKey = C;
	eFlatKey = Ef;
	song();
	echo(10,0.3,4);
    appendSilence(2);
	puts("Writing wav file... donde estas corazon.wav");
	exportToWav("Dónde Estás Corazón.wav");
}
