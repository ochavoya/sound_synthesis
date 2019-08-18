#include "soundlib.h"

#define CHORDAZ 135
#define BASSAZ 45
#define VOICEAZ 90


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
		fourChord(harmony,C,E,G,2*C,octave,FERMATA(0.375+0.0625),CHORDAZ);
		appendSilence(FERMATA(0.0625));
		appendTwo(harmony,G,Gf,octave+1,0.25,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,FERMATA(0.375),BASSAZ);
		appendInterval(bass,C,2*C,octave-2,FERMATA(0.0625),BASSAZ);
	add();
}

void firstRepeat(short end){
	FORTE;
	//MEASURE # 2
	#ifdef DEBUG
	puts("Measure # 2");
	#endif
		//HARMONY
		six(harmony,G,E,Ef,E,C,B/2,octave+1,0.75,CHORDAZ);
		//BASS
		six(bass,C,E,G,G/2,E,G,octave-1,0.75,BASSAZ);
	add();
	//MEASURE # 3 & 4
	#ifdef DEBUG
	puts("Measure # 3 & 4");
	#endif
		//HARMONY
		two(harmony,2*C,G,octave,0.25,CHORDAZ);
		appendSilence(0.25);
		two(harmony,E,F,octave,0.25,CHORDAZ);
		appendSix(harmony,G,A,B,2*C,2*D,2*E,octave,0.75,CHORDAZ);
		CRESCENDO;
		cat();
		//BASS
		four(bass,C,E,G,G/2,octave-1,0.5,BASSAZ);
		two(bass,D,G,octave-1,0.25,BASSAZ);
		appendSix(bass,C,E,G,G/2,E,G,octave-1,0.75,BASSAZ);
		CRESCENDO;
		cat();
	add();
	cat();

	//MEASURE # 5
	#ifdef DEBUG
	puts("Measure # 5");
	#endif
		//HARMONY
		create(harmony,F,octave+1,0.125,BASSAZ);
		append(harmony,D,octave+1,0.25,BASSAZ);
		appendSilence(0.125);
		appendTwo(harmony,F,E,octave+1,0.25,BASSAZ);
		//BASS
		six(bass,Db,B,G,G/2,B,G,octave-1,0.75,BASSAZ);
	add();
	cat();

	//MEASURE # 6
	#ifdef DEBUG
	puts("Measure # 6");
	#endif
		//HARMONY
		six(harmony,F,D,Cs,D,B/2,Bf/2,octave+1,0.75,CHORDAZ);
		//BASS
		six(bass,D,B,G,G/2,B,G,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 7
	#ifdef DEBUG
	puts("Measure # 7");
	#endif
		//HARMONY
		create(harmony,B,octave,0.125,CHORDAZ);
		append(harmony,G,octave,0.25,CHORDAZ);
		appendSilence(0.125);
		appendTwo(harmony,G,Gf,octave+1,0.25,CHORDAZ);
		//BASS
		six(bass,D,B,G,G/2,B,G,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 8
	#ifdef DEBUG
	puts("Measure # 8");
	#endif
		//HARMONY
		six(harmony,G,A,G,F,E,D,octave+1,0.75,CHORDAZ);
		//BASS
		six(bass,D,B,G,G/2,B,G,octave-1,0.75,BASSAZ);
	add();
	cat();
	if(!end){
	//MEASURE # 9
	#ifdef DEBUG
	puts("Measure # 9");
	#endif
		//HARMONY
		create(harmony,C,octave+1,0.125,CHORDAZ);
		appendSilence(0.375);
		appendTwo(harmony,G,Gf,octave+1,0.25,CHORDAZ);
		//BASS
		six(bass,C,E,G,G/2,E,G,octave-1,0.75,BASSAZ);
	add();
	cat();
	}
	else{
	//MEASURE # 10
	#ifdef DEBUG
	puts("Measure # 10");
	#endif
		//HARMONY
		create(harmony,C,octave+1,0.375,CHORDAZ);
		appendSilence(0.125);
		appendTwo(harmony,D,D,octave+1,0.25,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.375,BASSAZ);
	add();
	cat();
	}
}


void secondRepeat(short end){
	PIANO;
	//MEASURE # 11
	#ifdef DEBUG
	puts("Measure # 11");
	#endif
		//VOICE 
		create(voice,Gf,octave,0.75,VOICEAZ);
		//HARMONY
		six(harmony,2*D,A,A,A,2*C,2*C,octave,0.75,CHORDAZ);
	add();
		//BASS
		create(bass,Gf,octave-1,0.125,BASSAZ);
		appendInterval(bass,C,D,octave-1,0.125,BASSAZ);
		appendInterval(bass,C,D,octave-1,0.125,BASSAZ);
		append(bass,C,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,D,octave-1,0.125,BASSAZ);
		appendInterval(bass,C,D,octave-1,0.125,BASSAZ);

	add();
	//MEASURE # 12
	#ifdef DEBUG
	puts("Measure # 12");
	#endif
		//VOICE 
		create(voice,G,octave,0.75,VOICEAZ);
		//HARMONY
		create(harmony,C,octave+1,0.125,CHORDAZ);
		append(harmony,B,octave,0.375,CHORDAZ);
		appendTwo(harmony,D,D,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-1,0.125,BASSAZ);
		appendInterval(bass,B/2,C,octave-1,0.125,BASSAZ);
		appendInterval(bass,B/2,C,octave-1,0.125,BASSAZ);
		append(bass,C,octave-2,0.125,BASSAZ);
		appendInterval(bass,B/2,C,octave-1,0.125,BASSAZ);
		appendInterval(bass,B/2,C,octave-1,0.125,BASSAZ);	
	add();
	cat();
	//MEASURE # 13
	#ifdef DEBUG
	puts("Measure # 13");
	#endif
		//VOICE 
		create(voice,Gf,octave,0.75,VOICEAZ);
		//HARMONY
		six(harmony,2*C,A,A,A,2*C,2*C,octave,0.75,CHORDAZ);
	add();
		//BASS
		create(bass,Gf,octave-1,0.125,BASSAZ);
		appendInterval(bass,C,D,octave-1,0.125,BASSAZ);
		appendInterval(bass,C,D,octave-1,0.125,BASSAZ);
		append(bass,C,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,D,octave-1,0.125,BASSAZ);
		appendInterval(bass,C,D,octave-1,0.125,BASSAZ);		
	add();
	cat();
	//MEASURE # 14
	#ifdef DEBUG
	puts("Measure # 14");
	#endif
		//VOICE 
		create(voice,G,octave,0.75,VOICEAZ);
		//HARMONY
		create(harmony,C,octave+1,0.125,CHORDAZ);
		append(harmony,B,octave,0.375,CHORDAZ);
		appendTwo(harmony,D,D,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-1,0.125,BASSAZ);
		appendInterval(bass,B/2,C,octave-1,0.125,BASSAZ);
		appendInterval(bass,B/2,C,octave-1,0.125,BASSAZ);
		append(bass,C,octave-2,0.125,BASSAZ);
		appendInterval(bass,B/2,C,octave-1,0.125,BASSAZ);
		appendInterval(bass,B/2,C,octave-1,0.125,BASSAZ);	
	add();
	cat();
	//MEASURE # 15
	#ifdef DEBUG
	puts("Measure # 15");
	#endif
		//VOICE 
		create(voice,Gf,octave,0.75,VOICEAZ);
		//HARMONY
		two(harmony,2*D,A,octave,0.25,CHORDAZ);
		append(harmony,A,octave,0.25,CHORDAZ);
		appendTwo(harmony,D,D,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,Gf,octave-1,0.125,BASSAZ);
		appendInterval(bass,C,D,octave-1,0.125,BASSAZ);
		appendInterval(bass,C,D,octave-1,0.125,BASSAZ);
		append(bass,C,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,D,octave-1,0.125,BASSAZ);
		appendInterval(bass,C,D,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 16
	#ifdef DEBUG
	puts("Measure # 16");
	#endif
		//VOICE 
		create(voice,G,octave,0.75,VOICEAZ);
		//HARMONY
		create(harmony,C,octave+1,0.125,CHORDAZ);
		append(harmony,B,octave,0.375,CHORDAZ);
		appendTwo(harmony,D,D,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-1,0.125,BASSAZ);
		appendInterval(bass,B/2,C,octave-1,0.125,BASSAZ);
		appendInterval(bass,B/2,C,octave-1,0.125,BASSAZ);
		append(bass,C,octave-2,0.125,BASSAZ);
		appendInterval(bass,B/2,C,octave-1,0.125,BASSAZ);
		appendInterval(bass,B/2,C,octave-1,0.125,BASSAZ);	
	add();
	cat();
	//MEASURE # 17
	#ifdef DEBUG
	puts("Measure # 17");
	#endif
		//HARMONY
		six(harmony,D,E,D,C,B/2,A/2,octave+1,0.75,CHORDAZ);
		//BASS
		create(bass,Gf,octave-1,0.125,BASSAZ);
		appendInterval(bass,C,D,octave-1,0.125,BASSAZ);
		appendInterval(bass,C,D,octave-1,0.125,BASSAZ);
		append(bass,C,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,D,octave-1,0.125,BASSAZ);
		appendInterval(bass,C,D,octave-1,0.125,BASSAZ);
	add();
	cat();
	if(!end){
	//MEASURE # 18
	#ifdef DEBUG
	puts("Measure # 18");
	#endif
		//HARMONY
		create(harmony,G,octave,0.25,CHORDAZ);
		appendSilence(0.25);
		appendTwo(harmony,D,D,octave+1,0.25,CHORDAZ);
		//BASS
		chord(bass,G,B,D,octave-2,0.25,BASSAZ);
	add();
	cat();
	}
	else{
	//MEASURE # 19
	#ifdef DEBUG
	puts("Measure # 19");
	#endif
		
		//HARMONY
		create(harmony,G,octave,0.25,CHORDAZ);
		appendSilence(0.25);
		FORTE;
		appendTwo(harmony,G,Gf,octave+1,0.25,CHORDAZ);		
		//BASS
		chord(bass,G,B,D,octave-2,0.25,BASSAZ);
	add();
	cat();
	}
}

void intermesso(void){
	FORTE;
	//MEASURE # 20
	#ifdef DEBUG
	puts("Measure # 20");
	#endif

		//HARMONY
		six(harmony,G,E,Ds,G,C,B/2,octave+1,0.75,CHORDAZ);
		//BASS
		six(bass,C,E,G,G/2,E,G,octave-1,0.75,BASSAZ);
	add();
	//MEASURE # 21
	#ifdef DEBUG
	puts("Measure # 21");
	#endif
		//HARMONY
		six(harmony,2*C,G,0,0,E,F,octave,0.75,CHORDAZ);
		//BASS
		six(bass,C,E,G,G/2,E,G,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 22
	#ifdef DEBUG
	puts("Measure # 22");
	#endif
		//HARMONY
		three(harmony,G,A,B,octave,0.375,CHORDAZ);
		appendThree(harmony,C,D,E,octave+1,0.375,CHORDAZ);
		//BASS
		six(bass,C,E,G,G/2,E,G,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 23
	#ifdef DEBUG
	puts("Measure # 23");
	#endif
		//HARMONY
		create(harmony,F,octave+1,0.125,CHORDAZ);
		append(harmony,D,octave+1,0.25,CHORDAZ);
		appendSilence(0.125);
		appendTwo(harmony,F,E,octave+1,0.25,CHORDAZ);
		//BASS
		six(bass,D,B,G,G/2,B,G,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 24
	#ifdef DEBUG
	puts("Measure # 24");
	#endif
		//HARMONY
		six(harmony,F,D,Cs,D,B/2,Bf/2,octave+1,0.75,CHORDAZ);
		//BASS
		six(bass,D,B,G,G/2,B,G,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 25
	#ifdef DEBUG
	puts("Measure # 25");
	#endif
		//HARMONY
		create(harmony,B,octave,0.125,CHORDAZ);
		append(harmony,G,octave,0.25,CHORDAZ);
		MESSOFORTE;
		appendSilence(0.125);
		appendTwo(harmony,G,Gf,octave+1,0.25,CHORDAZ);		
		//BASS
		FORTE;
		three(bass,D,B,G,octave-1,0.375,BASSAZ);
		MESSOFORTE;
		appendThree(bass,G/2,B,G,octave-1,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 26
	#ifdef DEBUG
	puts("Measure # 26");
	#endif
		//HARMONY
		six(harmony,G,A,G,F,E,D,octave+1,0.75,BASSAZ);
		//BASS
		six(bass,D,B,G,G/2,B,G,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 27
	#ifdef DEBUG
	puts("Measure # 27");
	#endif

		//HARMONY
		create(harmony,C,octave,0.125,CHORDAZ);
		appendSilence(0.25);
		appendInterval(harmony,D,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,D,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	cat();
}

void thirdRepeat(short end){
	MESSOPIANO;
	//MEASURE # 28
	#ifdef DEBUG
	puts("Measure # 28");
	#endif
		//HARMONY
		interval(harmony,E,G,octave,0.1875,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.0625,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.1875,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.0625,CHORDAZ);
		appendInterval(harmony,D,B,octave,0.1875,CHORDAZ);
		appendInterval(harmony,F,2*D,octave,0.0625,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-1,0.25,BASSAZ);
		appendChord(bass,G/2,C,E,octave-1,0.25,BASSAZ);
		appendChord(bass,G,B,2*F,octave-2,0.25,BASSAZ);
	add();
	//MEASURE # 29
	#ifdef DEBUG
	puts("Measure # 29");
	#endif
		//HARMONY
		interval(harmony,E,2*C,octave,0.375,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.1875,CHORDAZ);
		appendInterval(harmony,Db,F,octave,0.0625,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.25,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 30
	#ifdef DEBUG
	puts("Measure # 30");
	#endif
		//HARMONY
		interval(harmony,E,G,octave,0.1875,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.0625,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.1875,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.0625,CHORDAZ);
		appendInterval(harmony,D,B,octave,0.1875,CHORDAZ);
		appendInterval(harmony,F,2*D,octave,0.0625,CHORDAZ);
		//BASS
		interval(harmony,C,2*C,octave,0.25,BASSAZ);
		appendChord(harmony,G/2,C,E,octave-1,0.25,BASSAZ);
		appendChord(harmony,G,B,2*F,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 31
	#ifdef DEBUG
	puts("Measure # 31");
	#endif
		//HARMONY
		interval(harmony,E,2*C,octave,0.375,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,D,F,B,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,Bf,octave,0.125,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendThree(bass,C,D,E,octave-2,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 32
	#ifdef DEBUG
	puts("Measure # 32");
	#endif
		//HARMONY
		chord(harmony,C,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,A/2,C,F,octave,0.25,CHORDAZ);
		appendChord(harmony,A/2,C,G,octave,0.25,CHORDAZ);
		//BASS
		six(bass,F,2*F,A,2*F,2*C,2*F,octave-2,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 33
	#ifdef DEBUG
	puts("Measure # 33");
	#endif
		//HARMONY
		chord(harmony,C,F,A,octave,0.375,CHORDAZ);
		appendInterval(harmony,A,2*C,octave,0.125,CHORDAZ);
		appendInterval(harmony,G,B,octave,0.125,CHORDAZ);
		appendInterval(harmony,F,A,octave,0.125,CHORDAZ);
		//BASS
		six(bass,F,2*F,A,2*F,2*C,2*F,octave-2,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 34
	#ifdef DEBUG
	puts("Measure # 34");
	#endif
		//HARMONY
		chord(harmony,C,E,G,octave,0.25,CHORDAZ);
		appendChord(harmony,C,E,G/2,octave,0.25,CHORDAZ);
		appendChord(harmony,D,F,G/2,octave,0.25,CHORDAZ);
		//BASS
		six(bass,C,2*C,E,2*C,G,2*C,octave-2,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 35
	#ifdef DEBUG
	puts("Measure # 35");
	#endif
		//HARMONY
		chord(harmony,C,E,G,octave,0.375,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.125,CHORDAZ);
		appendChord(harmony,C,F,A,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.125,CHORDAZ);
		//BASS
		six(bass,C,2*C,E,2*C,G,2*C,octave-2,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 36
	#ifdef DEBUG
	puts("Measure # 36");
	#endif
		//HARMONY
		chord(harmony,G,B,2*F,octave-1,0.25,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave-1,0.25,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.25,CHORDAZ);
		//BASS
		six(bass,G,2*F,B,2*F,2*D,2*F,octave-2,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 37
	#ifdef DEBUG
	puts("Measure # 37");
	#endif
		//HARMONY
		chord(harmony,G,B,2*F,octave-1,0.375,CHORDAZ);
		appendInterval(harmony,B,2*D,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		appendInterval(harmony,Db,F,octave,0.125,CHORDAZ);
		//BASS
		six(bass,G,2*F,B,2*F,2*D,2*F,octave-2,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 38
	#ifdef DEBUG
	puts("Measure # 38");
	#endif
		//HARMONY
		six(harmony,G,A,G,F,E,D,octave,0.75,CHORDAZ);
		addSix(harmony,E,F,E,Db,C,B/2,octave,0.75,CHORDAZ);
		//BASS
		three(bass,G,D,E,octave-2,0.75,BASSAZ);
	add();
	cat();
	if(end){
	//MEASURE # 39
	#ifdef DEBUG
	puts("Measure # 39");
	#endif
		//HARMONY
		chord(harmony,G/2,C,E,octave,0.25,CHORDAZ);
		appendSilence(0.125);
		appendInterval(harmony,Db,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,Db,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.125,CHORDAZ);
		//BASS
		create(bass,C,octave-1,0.25,BASSAZ);
		append(bass,C,octave-2,0.125,BASSAZ);
	add();
	cat();
	}
	else{
	//MEASURE # 40
	#ifdef DEBUG
	puts("Measure # 40");
	#endif
		//HARMONY
		chord(harmony,G/2,C,E,octave,0.25,CHORDAZ);
		appendFourChordMartelato(harmony,C,E,G,2*C,octave,0.125,CHORDAZ);
		appendSilence(0.375);
		//BASS
		create(bass,C,octave-1,0.25,BASSAZ);
		appendMartelato(bass,C,octave-2,0.125,BASSAZ);
	add();
	cat();
	}
}


void secondIntermesso(void){
	FORTE;
	//MEASURE # 41
	#ifdef DEBUG
	puts("Measure # 41");
	#endif
		//HARMONY
		interval(harmony,E,G,octave,0.1875,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.0625,CHORDAZ);
		appendInterval(harmony,Ds,Gf,octave,0.1875,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.0625,CHORDAZ);
		appendInterval(harmony,G,A,octave,0.1875,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.0625,CHORDAZ);
		//BASS
		interval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	//MEASURE # 42
	#ifdef DEBUG
	puts("Measure # 42");
	#endif
		//HARMONY
		interval(harmony,E,G,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendIntervalMarcato(harmony,C,E,octave,0.5,VOICEAZ);
		//BASS
		interval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 43
	#ifdef DEBUG
	puts("Measure # 43");
	#endif
		//HARMONY
		interval(harmony,E,G,octave,0.1875,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.0625,CHORDAZ);
		appendInterval(harmony,Ds,Gf,octave,0.1875,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.0625,CHORDAZ);
		appendInterval(harmony,G,A,octave,0.1875,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.0625,CHORDAZ);
		//BASS
		interval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 44
	#ifdef DEBUG
	puts("Measure # 44");
	#endif
		//HARMONY
		interval(harmony,E,G,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendIntervalMarcato(harmony,D,F,octave,0.5,VOICEAZ);
		//BASS
		interval(bass,D,F,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,D,F,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,D,F,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);	add();
	cat();
	//MEASURE # 45
	MESSOPIANO;
	#ifdef DEBUG
	puts("Measure # 45");
	#endif
		//HARMONY
		interval(harmony,D,F,octave,0.1875,CHORDAZ);
		appendInterval(harmony,D,F,octave,0.0625,CHORDAZ);
		appendInterval(harmony,Cs,E,octave,0.1875,CHORDAZ);
		appendInterval(harmony,D,F,octave,0.0625,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.1875,CHORDAZ);
		appendInterval(harmony,D,F,octave,0.0625,CHORDAZ);
		//BASS
		interval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();

	//MEASURE # 46
	#ifdef DEBUG
	puts("Measure # 46");
	#endif
		//HARMONY
		interval(harmony,D,F,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendIntervalMarcato(harmony,B/2,D,octave,0.5,CHORDAZ);
		//BASS
		six(bass,G,2*G,B,2*G,2*D,2*G,octave-2,0.75,BASSAZ);
	add();
	cat();

	//MEASURE # 47
	#ifdef DEBUG
	puts("Measure # 47");
	#endif
		//HARMONY
		six(harmony,D,E,F,D,E,F,octave,0.75,CHORDAZ);
		addSix(harmony,B/2,C,D,B/2,C,D,octave,0.75,CHORDAZ);		
		//BASS
		create(bass,G,octave-2,0.25,BASSAZ);
		appendChord(bass,D,F,G,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 48
	#ifdef DEBUG
	puts("Measure # 48");
	#endif
		//HARMONY
		interval(harmony,E,G,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendIntervalMarcato(harmony,C,E,octave,0.5,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.1875,BASSAZ);
		append(bass,B,octave-2,0.0625,BASSAZ);
		appendFour(bass,2*C,G,E,D,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 49
	MESSOPIANO;
	#ifdef DEBUG
	puts("Measure # 49");
	#endif
		//HARMONY
		chord(harmony,G/2,E,G,octave+1,0.1875,CHORDAZ);
		appendChord(harmony,G/2,E,G,octave+1,0.0625,CHORDAZ);
		appendChord(harmony,Gf/2,Ds,Gf,octave+1,0.1875,CHORDAZ);
		appendChord(harmony,G/2,E,G,octave+1,0.0625,CHORDAZ);
		appendChord(harmony,A/2,F,A,octave+1,0.1875,CHORDAZ);
		appendChord(harmony,G/2,E,G,octave+1,0.0625,CHORDAZ);		
		//BASS
		interval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 50
	#ifdef DEBUG
	puts("Measure # 50");
	#endif
		//HARMONY
		chord(harmony,G/2,E,G,octave+1,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChordMarcato(harmony,E/2,C,E,octave+1,0.5,CHORDAZ);
		//BASS
		interval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 51
	#ifdef DEBUG
	puts("Measure # 51");
	#endif
		//HARMONY
		chord(harmony,G/2,G,E,octave+1,0.1875,CHORDAZ);
		appendChord(harmony,G/2,G,E,octave+1,0.0625,CHORDAZ);
		appendChord(harmony,Gf/2,Ds,Gf,octave+1,0.1825,CHORDAZ);
		appendChord(harmony,G/2,G,E,octave+1,0.0625,CHORDAZ);
		appendChord(harmony,A/2,F,A,octave+1,0.1825,CHORDAZ);
		appendChord(harmony,G/2,G,E,octave+1,0.0625,CHORDAZ);
		//BASS
		interval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,E,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();

	//MEASURE # 52
	#ifdef DEBUG
	puts("Measure # 52");
	#endif
		//HARMONY
		chord(harmony,G,E,G,octave+1,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChordMarcato(harmony,F/2,Db,F,octave+1,0.5,CHORDAZ);
		//BASS
		interval(bass,D,F,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,D,F,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,D,F,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();

	//MEASURE # 53
	#ifdef DEBUG
	puts("Measure # 53");
	#endif
		//HARMONY
		chord(harmony,F/2,D,F,octave+1,0.1875,CHORDAZ);
		appendChord(harmony,F/2,D,F,octave+1,0.0625,CHORDAZ);
		appendChord(harmony,E/2,Cs,E,octave+1,0.1825,CHORDAZ);
		appendChord(harmony,F/2,D,F,octave+1,0.0625,CHORDAZ);
		appendChord(harmony,G/2,E,G,octave+1,0.1825,CHORDAZ);
		appendChord(harmony,F/2,D,F,octave+1,0.0625,CHORDAZ);
		//BASS
		interval(bass,D,F,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,D,F,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,D,F,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 54
	#ifdef DEBUG
	puts("Measure # 54");
	#endif
		//HARMONY
		chord(harmony,F/2,D,F,octave+1,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChordMarcato(harmony,D/2,B/2,D,octave,0.5,CHORDAZ);
		//BASS
		interval(bass,D,F,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,D,F,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,D,F,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 55
	#ifdef DEBUG
	puts("Measure # 55");
	#endif
		//HARMONY
		six(harmony,D,E,F,G,A,B,octave,0.75,CHORDAZ);
		addSix(harmony,B/2,C,D,E,F,G,octave+1,0.75,CHORDAZ);
		addSix(harmony,D,E,F,G,A,B,octave+1,0.75,CHORDAZ);
		//BASS
		interval(bass,G/2,G,octave-2,0.25,BASSAZ);
		appendFourChord(bass,D,F,G,B,octave-1,0.25,BASSAZ);
		appendInterval(bass,G/2,G,octave-2,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 56
	#ifdef DEBUG
	puts("Measure # 56");
	#endif
		//HARMONY
		chordMartelato(harmony,C,E,2*C,octave+1,0.25,CHORDAZ);
		appendFourChordMarcato(harmony,C,E,G,2*C,octave,0.25,CHORDAZ);
		appendSilence(0.25);
		//BASS
		chordMartelato(bass,C,E,G,octave-1,0.25,BASSAZ);
		appendIntervalMarcato(bass,C,2*C,octave-2,0.25,BASSAZ);
	add();
	cat();
}


void fourthRepeat(short end){
	DOUBLEFORTE;
	//MEASURE # 57
	#ifdef DEBUG
	puts("Measure # 57");
	#endif
		//HARMONY
		four(harmony,E,2*C,B,A,octave,0.5,CHORDAZ);
		addFour(harmony,E,E,G,F,octave,0.5,CHORDAZ);
		appendInterval(harmony,D,B,octave,0.25,CHORDAZ);
		//BASS
		create(bass,C,octave-1,0.125,BASSAZ);
		appendInterval(bass,E,G,octave-1,0.125,BASSAZ);
		appendTwo(bass,G,G/2,octave-2,0.25,BASSAZ);
		appendChord(bass,F,G,B,octave-1,0.25,BASSAZ);
	add();
	//MEASURE # 58
	#ifdef DEBUG
	puts("Measure # 58");
	#endif
		//HARMONY
		interval(harmony,E,2*C,octave,0.5,CHORDAZ);
		appendInterval(harmony,G,B,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.125,CHORDAZ);
		//BASS
		create(bass,C,octave-1,0.125,BASSAZ);
		appendInterval(bass,E,G,octave-1,0.125,BASSAZ);
		appendTwo(bass,G,G/2,octave-2,0.25,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 59
	#ifdef DEBUG
	puts("Measure # 59");
	#endif
		//HARMONY
		interval(harmony,Gf,2*D,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.125,CHORDAZ);
		appendInterval(harmony,D,B,octave,0.25,CHORDAZ);
		appendInterval(harmony,D,A,octave,0.125,CHORDAZ);
		//BASS
		create(bass,D,octave-2,0.125,BASSAZ);
		appendFourChord(bass,D,Gf,A,2*C,octave-1,0.125,BASSAZ);
		appendFourChord(bass,D,Gf,A,2*C,octave-1,0.125,BASSAZ);
		append(bass,D,octave-2,0.125,BASSAZ);
		appendFourChord(bass,D,Gf,A,2*C,octave-1,0.125,BASSAZ);
		appendChord(bass,D,Gf,A,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 60
	#ifdef DEBUG
	puts("Measure # 60");
	#endif
		//HARMONY
		interval(harmony,B/2,G,octave,0.625,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.125,CHORDAZ);
		//BASS
		three(bass,G,B,2*D,octave-2,0.375,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 61
	#ifdef DEBUG
	puts("Measure # 61");
	#endif
		//HARMONY
		four(harmony,B,B,A,G,octave,0.5,CHORDAZ);
		addFour(harmony,G,G,F,E,octave,0.5,CHORDAZ);
		appendInterval(harmony,F,A,octave,0.25,CHORDAZ);
		//BASS
		create(bass,G,octave-2,0.125,BASSAZ);
		appendChord(bass,F,G,B,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,G,octave-3,0.125,BASSAZ);
		appendChord(bass,F,G,B,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 62
	#ifdef DEBUG
	puts("Measure # 62");
	#endif
		//HARMONY
		interval(harmony,G,B,octave,0.625,CHORDAZ);
		appendInterval(harmony,F,A,octave,0.125,CHORDAZ);
		//BASS
		create(bass,G,octave-2,0.125,BASSAZ);
		appendChord(bass,F,G,B,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,G,octave-3,0.125,BASSAZ);
		appendChord(bass,F,G,B,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 63
	#ifdef DEBUG
	puts("Measure # 63");
	#endif
		//HARMONY
		six(harmony,G,A,G,F,E,D,octave,0.75,CHORDAZ);
		addFour(harmony,B,0,0,B,octave-1,0.5,CHORDAZ);
		//BASS
		create(bass,G,octave-2,0.125,BASSAZ);
		appendChord(bass,G,F,B,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendChord(bass,G,F,B,octave-1,0.25,BASSAZ);
	add();
	cat();
	if(!end){
	//MEASURE # 64
	#ifdef DEBUG
	puts("Measure # 64");
	#endif
		//HARMONY
		chord(harmony,E,G,2*C,octave-1,0.5,CHORDAZ);
		appendSilence(0.125);
		append(harmony,G,octave,0.125,CHORDAZ);
		//BASS
		four(bass,2*C,G,E,C,octave-2,0.5,BASSAZ);
	add();
	cat();
	}
	else{
	//MEASURE # 65
	#ifdef DEBUG
	puts("Measure # 65");
	#endif
		//HARMONY
		chord(harmony,E,G,2*C,octave-2,0.125,CHORDAZ);
		//BASS
		create(bass,C,octave-1,0.125,BASSAZ);
	add();
	cat();
		PIANO;
		//HARMONY
		three(harmony,C,E,G,octave,0.375,CHORDAZ);		
		//BASS
	cat();
	}
}

void fifthRepeat(short end){
	MESSOPIANO;
	//MEASURE # 66
	#ifdef DEBUG
	puts("Measure # 66 & 67");
	#endif
		//HARMONY
		chord(harmony,C,E,2*C,octave,0.375,CHORDAZ);
		appendChord(harmony,C,E,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,D,F,B,octave,0.125,CHORDAZ);
		appendChord(harmony,D,F,B,octave,0.125,CHORDAZ);
		appendFourChord(harmony,C,E,G,Bf,octave,0.25,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.75,BASSAZ);
		append(bass,E,octave-1,0.25,BASSAZ);
	add();
	//MEASURE # 68
	#ifdef DEBUG
	puts("Measure # 68");
	#endif
		//HARMONY
		chord(harmony,A/2,F,A,octave,0.125,CHORDAZ);
		appendChord(harmony,A/2,F,A,octave,0.125,CHORDAZ);
		appendInterval(harmony,A/2,A,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.125,CHORDAZ);
		//BASS
		interval(bass,F,2*F,octave-2,0.25,BASSAZ);
		append(bass,Fs,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 69
	#ifdef DEBUG
	puts("Measure # 69");
	#endif
		//HARMONY
		chord(harmony,B/2,G,B,octave,0.375,CHORDAZ);
		appendChord(harmony,B/2,F,A,octave,0.125,CHORDAZ);
		//BASS
		create(bass,G,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 70
	#ifdef DEBUG
	puts("Measure # 70");
	#endif
		//HARMONY
		four(harmony,G,F,E,D,octave,0.5,CHORDAZ);
		addFour(harmony,B,B,B,B,octave-1,0.5,CHORDAZ);
		silence(0.25);
		appendTwo(harmony,G,F,octave-1,0.25,CHORDAZ);
		add();
		//BASS
		interval(bass,G,2*G,octave-3,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.25,BASSAZ);
	add();
	cat();
	if(!end){
	//MEASURE # 71
	#ifdef DEBUG
	puts("Measure # 71");
	#endif
		//HARMONY
		chord(harmony,E,G,2*C,octave-1,0.125,CHORDAZ);
		appendThree(harmony,C,E,G,octave,0.375,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
	add();
	cat();
	}
}

void thirdIntermesso(void){
	double start;
	MESSOPIANO;
	//MEASURE # 72
	#ifdef DEBUG
	puts("Measure # 72");
	#endif
		//HARMONY
		chord(harmony,E,G,2*C,octave-1,0.125,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave-1,0.125,CHORDAZ);
		PIANISSIMO;
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		appendInterval(harmony,D,B/2,octave,0.125,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
	add();
	//MEASURE # 73
	#ifdef DEBUG
	puts("Measure # 73");
	#endif
		//HARMONY
		four(harmony,E,E,E,D,octave,0.5,CHORDAZ);
		addFour(harmony,C,C,C,B/2,octave,0.5,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 74
	#ifdef DEBUG
	puts("Measure # 74");
	#endif
		//HARMONY
		interval(harmony,C,E,octave,0.25,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		appendInterval(harmony,D,F,octave,0.125,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 75
	#ifdef DEBUG
	puts("Measure # 75");
	#endif
		//HARMONY
		four(harmony,A,G,F,E,octave,0.5,CHORDAZ);
		addFour(harmony,F,E,D,C,octave,0.5,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 76
	#ifdef DEBUG
	puts("Measure # 76");
	#endif
		//HARMONY
		four(harmony,D,D,F,E,octave,0.5,CHORDAZ);
		addFour(harmony,B/2,B/2,D,C,octave,0.5,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 77
	#ifdef DEBUG
	puts("Measure # 77");
	#endif
		//HARMONY
		interval(harmony,D,F,octave,0.25,CHORDAZ);
		appendInterval(harmony,D,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	start=(double)(PIANISSIMO)/(MESSOFORTE);
	//MEASURE # 78
	#ifdef DEBUG
	puts("Measure # 78");
	#endif
		//HARMONY
		interval(harmony,D,F,octave,0.25,CHORDAZ);
		appendInterval(harmony,D,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.125,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	// cat(); ELIMINATED TO START CRESCENDO this cat(); APPEARS AFTER MEASSURE 80
	//MEASURE # 79
	#ifdef DEBUG
	puts("Measure # 79");
	#endif
		//HARMONY
		four(harmony,B,A,G,F,octave,0.5,CHORDAZ);
		addFour(harmony,G,F,E,D,octave,0.5,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 80
	#ifdef DEBUG
	puts("Measure # 80");
	#endif
		//HARMONY
		four(harmony,E,E,2*E,2*D,octave,0.5,CHORDAZ);
		addFour(harmony,C,C,2*C,B,octave,0.5,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	gradual(start,1);
	cat();
	start=(double)(MESSOFORTE)/(FORTE);
	//MEASURE # 81
	#ifdef DEBUG
	puts("Measure # 81");
	#endif
		//HARMONY
		four(harmony,E,E,E,D,octave+1,0.5,CHORDAZ);
		addFour(harmony,C,C,C,B/2,octave+1,0.5,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	//cat(); ELIMINATED TO START CRESCENDO this cat(); APPEARS AFTER MEASSURE 85
	//MEASURE # 82
	#ifdef DEBUG
	puts("Measure # 82");
	#endif
		//HARMONY
		interval(harmony,C,E,octave+1,0.25,CHORDAZ);
		appendInterval(harmony,C,E,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,D,F,octave+1,0.125,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 83
	#ifdef DEBUG
	puts("Measure # 83");
	#endif
		//HARMONY
		four(harmony,A,G,F,E,octave+1,0.5,CHORDAZ);
		addFour(harmony,F,E,D,C,octave+1,0.5,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 84
	#ifdef DEBUG
	puts("Measure # 84");
	#endif
		//HARMONY
		four(harmony,C,C,F,E,octave+1,0.5,CHORDAZ);
		addFour(harmony,A,A,2*D,2*C,octave,0.5,CHORDAZ);
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,D,2*D,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 85
	#ifdef DEBUG
	puts("Measure # 85");
	#endif
		//HARMONY
		interval(harmony,D,F,octave+1,0.25,CHORDAZ);
		appendInterval(harmony,D,F,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,C,E,octave+1,0.125,CHORDAZ);
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,D,2*D,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	gradual(start,1);
	cat();
	start=(double)(FORTE)/(DOUBLEFORTE);
	//MEASURE # 86
	#ifdef DEBUG
	puts("Measure # 86");
	#endif
		//HARMONY
		interval(harmony,D,F,octave+1,0.25,CHORDAZ);
		appendInterval(harmony,D,F,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,E,G,octave+1,0.125,CHORDAZ);
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,D,2*D,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	//cat(); ELIMINATED TO START CRESCENDO this cat(); APPEARS AFTER MEASSURE 88
	//MEASURE # 87
	#ifdef DEBUG
	puts("Measure # 87");
	#endif
		//HARMONY
		four(harmony,B,A,G,F,octave+1,0.5,CHORDAZ);
		addFour(harmony,G,F,E,D,octave+1,0.5,CHORDAZ);
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,D,2*D,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 88
	#ifdef DEBUG
	puts("Measure # 88");
	#endif
		//HARMONY
		four(harmony,E,E,E,G,octave+1,0.5,CHORDAZ);
		addFour(harmony,C,C,E/2,G/2,octave+1,0.5,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
	add();
	cat();
	gradual(start,1);
	cat();
	//MEASURE # 89
	#ifdef DEBUG
	puts("Measure # 89");
	#endif
		//HARMONY
		fourChordMarcato(harmony,C,E,A,2*C,octave+1,0.25,CHORDAZ);
		appendFourChordMarcato(harmony,C,E,A,2*C,octave+1,0.25,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-3,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 90
	#ifdef DEBUG
	puts("Measure # 90");
	#endif
		//HARMONY
		chord(harmony,D,Fs,A,octave+1,0.25,CHORDAZ);
		appendFourChord(harmony,F,A,2*C,2*F,octave,0.25,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 91
	#ifdef DEBUG
	puts("Measure # 91");
	#endif
		//HARMONY
		fourChord(harmony,G,B,D,2*G,octave,FERMATA(0.5),CHORDAZ);
		//BASS
		interval(bass,G,2*G,octave-3,FERMATA(0.5),BASSAZ);

	add();
	cat();
}

void sixthRepeat(void){
	FORTISSIMO;
	//MEASURE # 92
	#ifdef DEBUG
	puts("Measure # 92");
	#endif
		//HARMONY
		interval(harmony,G,2*E,octave,0.125,CHORDAZ);
		appendInterval(harmony,G,2*E,octave,0.0625,CHORDAZ);
		appendInterval(harmony,G,2*E,octave,0.0625,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	//MEASURE # 93
	#ifdef DEBUG
	puts("Measure # 93");
	#endif
		//HARMONY
		interval(harmony,G,2*E,octave,0.125,CHORDAZ);
		appendInterval(harmony,G,2*E,octave,0.0625,CHORDAZ);
		appendInterval(harmony,G,2*E,octave,0.0625,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 94
	#ifdef DEBUG
	puts("Measure # 94");
	#endif
		//HARMONY
		four(harmony,D,E,F,D,octave,0.25,CHORDAZ);
		addFour(harmony,D,E,F,D,octave,0.25,CHORDAZ);
		//BASS
		chord(bass,G,B,2*F,octave-2,0.125,BASSAZ);
		appendChord(bass,G,B,2*F,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 95
	#ifdef DEBUG
	puts("Measure # 95");
	#endif
		//HARMONY
		interval(harmony,G,2*E,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 96
	#ifdef DEBUG
	puts("Measure # 96");
	#endif
		//HARMONY
		interval(harmony,G,2*E,octave,0.125,CHORDAZ);
		appendInterval(harmony,G,2*E,octave,0.0625,CHORDAZ);
		appendInterval(harmony,G,2*E,octave,0.0625,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 97
	#ifdef DEBUG
	puts("Measure # 97");
	#endif
		//HARMONY
		interval(harmony,G,2*E,octave,0.125,CHORDAZ);
		appendInterval(harmony,G,2*E,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 98
	#ifdef DEBUG
	puts("Measure # 98");
	#endif
		//HARMONY
		four(harmony,D,E,F,D,octave,0.25,CHORDAZ);
		addFour(harmony,D,E,F,D,octave,0.25,CHORDAZ);
		//BASS
		chord(bass,G,B,2*F,octave-2,0.125,BASSAZ);
		appendChord(bass,G,B,2*F,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 99
	#ifdef DEBUG
	puts("Measure # 99");
	#endif
		//HARMONY
		interval(harmony,C,2*C,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	cat();
}

void diana(void){
	//MEASURE # 100
	#ifdef DEBUG
	puts("Measure # 100");
	#endif
		//HARMONY
		interval(harmony,G,2*G,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,A,2*A,octave-1,0.125,CHORDAZ);
		//BASS
		chord(bass,G,E,B,octave-2,0.125,BASSAZ);
		appendChord(bass,G,E,B,octave-2,0.125,BASSAZ);
	add();
	//MEASURE # 101
	#ifdef DEBUG
	puts("Measure # 101");
	#endif
		//HARMONY
		interval(harmony,B/2,B,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,G,E,B,octave-2,0.125,BASSAZ);
		appendChord(bass,G,E,B,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 102
	#ifdef DEBUG
	puts("Measure # 102");
	#endif
		//HARMONY
		interval(harmony,B,2*B,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,A,2*A,octave-1,0.125,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-2,0.125,BASSAZ);
		appendChord(bass,C,E,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 103
	#ifdef DEBUG
	puts("Measure # 103");
	#endif
		//HARMONY
		interval(harmony,D,2*D,octave,0.25,CHORDAZ);
		//BASS
		chord(bass,G,E,B,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 104
	#ifdef DEBUG
	puts("Measure # 104");
	#endif
		//HARMONY
		interval(harmony,G,2*G,octave,0.125,CHORDAZ);
		appendInterval(harmony,A,2*A,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,G,E,B,octave-2,0.125,BASSAZ);
		appendChord(bass,G,E,B,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 105
	#ifdef DEBUG
	puts("Measure # 105");
	#endif
		//HARMONY
		interval(harmony,B/2,B,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,G,E,B,octave-2,0.125,BASSAZ);
		appendChord(bass,G,E,B,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 106
	#ifdef DEBUG
	puts("Measure # 106");
	#endif
		//HARMONY
		interval(harmony,B,2*B,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,A,2*A,octave-1,0.125,CHORDAZ);
		//BASS
		chord(bass,D,Fs,2*C,octave-2,0.125,BASSAZ);
		appendChord(bass,D,Fs,2*C,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 107
	#ifdef DEBUG
	puts("Measure # 107");
	#endif
		//HARMONY
		interval(harmony,G,2*G,octave-1,0.25,CHORDAZ);
		//BASS
		chord(bass,G,E,B,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 108
	#ifdef DEBUG
	puts("Measure # 108");
	#endif
		//HARMONY
		interval(harmony,G,2*G,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,A,2*A,octave-1,0.125,CHORDAZ);
		//BASS
		chord(bass,G,E,B,octave-2,0.125,BASSAZ);
		appendChord(bass,G,E,B,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 109
	#ifdef DEBUG
	puts("Measure # 109");
	#endif
		//HARMONY
		interval(harmony,B,2*B,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,G,E,B,octave-2,0.125,BASSAZ);
		appendChord(bass,G,E,B,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 110
	#ifdef DEBUG
	puts("Measure # 110");
	#endif
		//HARMONY
		interval(harmony,B,2*B,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,A,2*A,octave-1,0.125,CHORDAZ);
		//BASS
		chord(bass,D,Fs,A,octave-2,0.125,BASSAZ);
		appendChord(bass,D,Fs,A,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 111
	#ifdef DEBUG
	puts("Measure # 111");
	#endif
		//HARMONY
		interval(harmony,D,2*D,octave,0.25,CHORDAZ);
		//BASS
		chord(bass,G,E,B,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 112
	#ifdef DEBUG
	puts("Measure # 112");
	#endif
		//HARMONY
		interval(harmony,G,2*G,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,A,2*A,octave-1,0.125,CHORDAZ);
		//BASS
		chord(bass,G,E,B,octave-2,0.125,BASSAZ);
		appendChord(bass,G,E,B,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 113
	#ifdef DEBUG
	puts("Measure # 113");
	#endif
		//HARMONY
		interval(harmony,B,2*B,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,G,E,B,octave-2,0.125,BASSAZ);
		appendChord(bass,G,E,B,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 114
	#ifdef DEBUG
	puts("Measure # 114");
	#endif
		//HARMONY
		interval(harmony,B,2*B,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,D,Fs,2*C,octave-2,0.125,BASSAZ);
		appendChord(bass,D,Fs,2*C,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 115
	#ifdef DEBUG
	puts("Measure # 115");
	#endif
		//HARMONY
		interval(harmony,G,2*G,octave-1,0.25,CHORDAZ);
		//BASS
		chord(bass,G,E,B,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 116
	#ifdef DEBUG
	puts("Measure # 116");
	#endif
		//HARMONY
		interval(harmony,G,2*G,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,2*E,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 117
	#ifdef DEBUG
	puts("Measure # 117");
	#endif
		//HARMONY
		interval(harmony,G,2*G,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,2*E,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 118
	#ifdef DEBUG
	puts("Measure # 118");
	#endif
		//HARMONY
		four(harmony,D,E,F,D,octave+1,0.25,CHORDAZ);
		addFour(harmony,D,E,F,D,octave,0.25,CHORDAZ);
		//BASS
		chord(bass,G,E,2*F,octave-2,0.125,BASSAZ);
		appendChord(bass,G,E,2*F,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 119
	#ifdef DEBUG
	puts("Measure # 119");
	#endif
		//HARMONY
		interval(harmony,E,2*E,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 120
	#ifdef DEBUG
	puts("Measure # 120");
	#endif
		//HARMONY
		interval(harmony,G,2*G,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,2*E,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-2,0.125,BASSAZ);
		appendChord(bass,C,E,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 121
	#ifdef DEBUG
	puts("Measure # 121");
	#endif
		//HARMONY
		interval(harmony,G,2*G,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,2*E,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 122
	#ifdef DEBUG
	puts("Measure # 122");
	#endif
		//HARMONY
		four(harmony,D,E,F,D,octave+1,0.25,CHORDAZ);
		addFour(harmony,D,E,F,D,octave,0.25,CHORDAZ);
		//BASS
		chord(bass,G,E,2*F,octave-2,0.125,BASSAZ);
		appendChord(bass,G,E,2*F,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 123
	#ifdef DEBUG
	puts("Measure # 123");
	#endif
		//HARMONY
		interval(harmony,C,2*C,octave,0.25,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 124
	#ifdef DEBUG
	puts("Measure # 124");
	#endif
		//HARMONY
		interval(harmony,G,2*G,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,2*E,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 125
	#ifdef DEBUG
	puts("Measure # 125");
	#endif
		//HARMONY
		interval(harmony,G,2*G,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,2*E,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 126
	#ifdef DEBUG
	puts("Measure # 126");
	#endif
		//HARMONY
		four(harmony,D,E,F,D,octave+1,0.25,CHORDAZ);
		addFour(harmony,D,E,F,D,octave,0.25,CHORDAZ);
		//BASS
		chord(bass,G,E,2*F,octave-2,0.125,BASSAZ);
		appendChord(bass,G,E,2*F,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 127
	#ifdef DEBUG
	puts("Measure # 127");
	#endif
		//HARMONY
		interval(harmony,E,2*E,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 128
	#ifdef DEBUG
	puts("Measure # 128");
	#endif
		//HARMONY
		interval(harmony,E,2*E,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 129
	#ifdef DEBUG
	puts("Measure # 129");
	#endif
		//HARMONY
		interval(harmony,E,2*E,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 130
	#ifdef DEBUG
	puts("Measure # 130");
	#endif
		//HARMONY
		four(harmony,F,G,A,B,octave+1,0.25,CHORDAZ);
		addFour(harmony,F,G,A,B,octave,0.25,CHORDAZ);
		//BASS
		chord(bass,G,E,2*F,octave-2,0.125,BASSAZ);
		appendChord(bass,G,E,2*F,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 131
	#ifdef DEBUG
	puts("Measure # 131");
	#endif
		//HARMONY
		interval(harmony,C,2*C,octave+1,0.125,CHORDAZ);
		appendSilence(0.125);
		//BASS
		chord(bass,C,E,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 132
	#ifdef DEBUG
	puts("Measure # 132");
	#endif
		//HARMONY
		fourChord(harmony,C,E,G,2*C,octave,0.5,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.5,BASSAZ);
	add();
	CRESCENDO;
	cat();
	FORTISSIMO;
	//MEASURE # 133
	#ifdef DEBUG
	puts("Measure # 133");
	#endif
		//HARMONY
		fourChordMartelato(harmony,C,E,G,2*C,octave,0.5,CHORDAZ);
		//BASS
		intervalMartelato(bass,C,2*C,octave-3,0.5,BASSAZ);
	add();
	cat();
}


void song(void){
	puts("intro");
 	intro();
	puts("first repeat");
	firstRepeat(0);
	cat();
	firstRepeat(1);
	cat();
	secondRepeat(0);
	cat();
	secondRepeat(1);
	cat();
	intermesso();
	cat();
	thirdRepeat(0);
	cat();
	thirdRepeat(1);
	cat();
	secondIntermesso();
	cat();
	fourthRepeat(0);
	cat();
	fourthRepeat(1);
	cat();
	fifthRepeat(0);
	cat();
	fifthRepeat(1);
	cat();
	thirdIntermesso();
	cat();
	sixthRepeat();
	cat();
	sixthRepeat();
	cat();
	diana();
	cat();
}


int main(int argc, char **argv){

	tempo=150;

	C = F;

	song();

	echo(10,0.3,4);


	puts("Writing wav file: jarabe tapatio.wav");

	exportToWav("Jarabe Tapatío.wav");

}
