#include "soundlib.h"
#define DEBUG 1

#define VOICEAZ 75
#define CHORDAZ 135
#define BASSAZ 90

double (*voice)(double) = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double) = trumpet; // oldCircleOfRa;

short octave = -1;

double aFlat;
double bFlat;

void intro(void){
	FORTE;
	//MEASURE # 1
	#ifdef DEBUG
	puts("Measure # 1");
	#endif
		//HARMONY
		fourChord(harmony,G,2*C,2*E,2*G,octave,0.375,CHORDAZ);
		appendFourChord(harmony,E,G,2*C,2*E,octave,0.125,CHORDAZ);
		appendFourChord(harmony,E,G,2*C,2*E,octave,0.25,CHORDAZ);
		appendFourChord(harmony,G,2*C,2*E,2*G,octave,0.25,CHORDAZ);
		//BASS
		interval(bass,G/2,G/4,octave,0.25,BASSAZ);
		appendInterval(bass,G/2,G/4,octave,0.5,BASSAZ);
		appendInterval(bass,G/2,G/4,octave,0.25,BASSAZ);
	add();
	//MEASURE # 2
	#ifdef DEBUG
	puts("Measure # 2");
	#endif
		//HARMONY
		fourChord(harmony,A,2*D,2*Fs,2*A,octave,0.375,VOICEAZ);
		appendFourChord(harmony,Fs,A,2*D,2*Fs,octave,0.125,VOICEAZ);
		appendFourChord(harmony,Fs,A,2*D,2*Fs,octave,0.25,VOICEAZ);
		appendFourChord(harmony,A,2*D,2*Fs,2*A,octave,0.25,VOICEAZ);
		//BASS
		interval(bass,G/2,G/4,octave,0.25,BASSAZ);
		appendInterval(bass,G/2,G/4,octave,0.5,BASSAZ);
		appendInterval(bass,G/2,G/4,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 3
	#ifdef DEBUG
	puts("Measure # 3");
	#endif
		//HARMONY
		fourChord(harmony,Bf,2*Ef,2*G,2*Bf,octave,0.375,CHORDAZ);
		appendFourChord(harmony,G,Bf,2*Ef,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,Bf,2*Ef,2*G,octave,0.25,CHORDAZ);
		appendFourChord(harmony,Bf,2*Ef,2*G,2*Bf,octave,0.25,CHORDAZ);
		//BASS
		interval(bass,G/2,G/4,octave,0.25,BASSAZ);
		appendInterval(bass,G/2,G/4,octave,0.5,BASSAZ);
		appendInterval(bass,G/2,G/4,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 4
	#ifdef DEBUG
	puts("Measure # 4");
	#endif
		//VOICE
		silence( 0.25 + FERMATA(0.5));
		MESSOPIANO;
		append(voice,G,octave,0.25,VOICEAZ);
		MESSOFORTE;
		//HARMONY
		fourChord(harmony,2*C,2*F,2*A,4*C,octave,0.5,CHORDAZ);
		appendFourChord(harmony,2*D,2*G,2*B,4*D,octave,FERMATA(0.5)-0.25,CHORDAZ);
		MESSOPIANO;
		append(harmony,G,octave,0.25,CHORDAZ);
		MESSOFORTE;
	add();
		//BASS
		interval(bass,G/2,G/4,octave,0.25,BASSAZ);
		appendInterval(bass,G/2,G/4,octave,0.25,BASSAZ);
		appendInterval(bass,G/2,G/4,octave,FERMATA(0.5),BASSAZ);
	add();
	cat();
	MESSOPIANO;
	//MEASURE # 5
	#ifdef DEBUG
	puts("Measure # 5");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,2*E,4*C,octave,0.125,CHORDAZ);
		append(harmony,2*G,octave,0.125,CHORDAZ);
		append(harmony,4*E,octave,0.25+0.125,CHORDAZ);
		appendThree(harmony,2*E,4*C,2*G,octave,0.375,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave,1.0,BASSAZ);
	add();
	cat();

	//MEASURE # 6
	#ifdef DEBUG
	puts("Measure # 6");
	#endif
		//VOICE
		create(voice,G,octave,0.25*1.5,VOICEAZ);
		append(voice,D,octave,0.125,VOICEAZ);
		append(voice,D,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,D,B,octave+1,0.125,CHORDAZ);
		append(harmony,G,octave+1,0.125,CHORDAZ);
		append(harmony,D,octave+2,0.25*1.5,CHORDAZ);
		append(harmony,D,octave+1,0.125,CHORDAZ);
		append(harmony,B,octave+1,0.125,CHORDAZ);
		append(harmony,G,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave,1.0,BASSAZ);
	add();
	cat();

	//MEASURE # 7
	#ifdef DEBUG
	puts("Measure # 7");
	#endif
		//VOICE
		four(voice,F,G,A,B,octave,1.0,VOICEAZ);
		//HARMONY
		interval(harmony,C,A,octave+1,0.125,CHORDAZ);
		append(harmony,F,octave+1,0.125,CHORDAZ);
                append(harmony,C,octave+2,0.375,CHORDAZ);
		appendThree(harmony,C,A,F,octave+1,0.375,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave,1.0,BASSAZ);
	add();
	cat();

	//MEASURE # 8
	#ifdef DEBUG
	puts("Measure # 8");
	#endif
		//VOICE
		create(voice,G,octave,0.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,G,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,D,B,octave+1,0.125,CHORDAZ);
		append(harmony,G,octave+1,0.125,CHORDAZ);
		append(harmony,D,octave+2,0.375,CHORDAZ);
		appendThree(harmony,D,B,G,octave+1,0.375,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave,1.0,BASSAZ);
	add();
	cat();

	//MEASURE # 9
	#ifdef DEBUG
	puts("Measure # 9");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave+1,0.125,CHORDAZ);
		append(harmony,G,octave+1,0.125,CHORDAZ);
		append(harmony,E,octave+2,0.375,CHORDAZ);
		appendThree(harmony,E,2*C,G,octave+1,0.375,CHORDAZ);
	add();
		//BASS
		interval(bass,G,2*G,octave-1,1.0,BASSAZ);
	add();
	cat();

	
	//MEASURE # 10
	#ifdef DEBUG
	puts("Measure # 10");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,Db,octave,0.125,VOICEAZ);
		append(voice,Db,octave,0.25,VOICEAZ);
		append(voice,Db,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,D,B,octave+1,0.125,CHORDAZ);
		append(harmony,G,octave+1,0.125,CHORDAZ);
		append(harmony,Db,octave+2,0.375,CHORDAZ);
		appendThree(harmony,Db,B,G,octave+1,0.375,CHORDAZ);
	add();
		//BASS
		interval(bass,G/2,G,octave,1.0,BASSAZ);
	add();
	cat();

	//MEASURE # 11
	#ifdef DEBUG
	puts("Measure # 11");
	#endif
		//VOICE
		four(voice,Cs,D,E,A/2,octave+1,1.0,VOICEAZ);
		//HARMONY
		interval(harmony,A,2*Cs,octave+1,0.125,CHORDAZ);
		append(harmony,E,octave,0.125,CHORDAZ);
		append(harmony,D,octave+2,0.25,CHORDAZ);
		appendFour(harmony,2*E,Fs,A,Fs,octave+1,0.5,CHORDAZ);
	add();
		//BASS
		create(bass,D,octave,1.0,BASSAZ);
		two(bass,G,Fs,octave,1.0,BASSAZ);
		add();
	add();
	cat();

	//MEASURE # 12
	#ifdef DEBUG
	puts("Measure # 12");
	#endif
		//VOICE
		create(voice,D,octave+1,0.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,G,octave,0.25,VOICEAZ);
		//HARMONY
		four(harmony,G,Db,Db,A/2,octave+1,0.5,CHORDAZ);
		four(harmony,2*D,A,A,F,octave+1,0.5,CHORDAZ);
                add();
		appendInterval(harmony,B,2*G,octave,0.5,CHORDAZ);
	add();
		//BASS
		interval(bass,G,2*F,octave-1,1.0,BASSAZ);
	add();
	CRESCENDO;
	cat();
}


void coda(void){

	//MEASURE # 54
	#ifdef DEBUG
	puts("Measure # 54");
	#endif
		//VOICE
		create(voice,C,octave+1,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,G,octave,0.125/2,CHORDAZ);
		appendInterval(harmony,C,G,octave,0.125/2,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.25*3/2,CHORDAZ);
		appendInterval(harmony,C,G,octave,0.125/2,CHORDAZ);
		appendInterval(harmony,C,G,octave,0.125/2,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-1,0.5,BASSAZ);
		appendInterval(bass,Bf,2*Bf,octave-2,0.5,BASSAZ);

	add();
	//MEASURE # 55
	#ifdef DEBUG
	puts("Measure # 55");
	#endif
		//HARMONY
		chord(harmony,G,B,2*D,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,D,G,octave+1,0.5,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.125,CHORDAZ);
		appendChord(harmony,B/2,D,G,octave+1,0.125,CHORDAZ);
		//BASS
		interval(bass,G,2*G,octave-2,0.25*3/2,BASSAZ);
		appendInterval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-2,0.25,BASSAZ);
		appendInterval(bass,D,2*D,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 56
	#ifdef DEBUG
	puts("Measure # 56");
	#endif
		//VOICE
		silence(0.75);
		append(voice,A,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,D,E,A,octave,0.125,CHORDAZ);
		appendThree(harmony,A/2,D,E,octave+1,0.25*3/2,CHORDAZ);
		append(harmony,Cs,octave,0.5,CHORDAZ);
	add();
		//BASS
		interval(bass,E,2*E,octave-2,1.0,BASSAZ);
	add();
        CRESCENDO;
	cat();
	C=bFlat;
	//MEASURE # 57
	#ifdef DEBUG
	puts("Measure # 57");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		appendTwo(voice,E,G,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,0.625,CHORDAZ);
		appendThree(harmony,D,E,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		four(bass,C,C,C,C,octave-1,1.0,BASSAZ);
		addFour(bass,C,C,C,C,octave-2,1.0,BASSAZ);
	add();
	cat();
	//MEASURE # 58
	#ifdef DEBUG
	puts("Measure # 58");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,D,octave,0.125,VOICEAZ);
		appendTwo(voice,D,E,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,D,G,octave,0.625,CHORDAZ);
		appendThree(harmony,B/2,D,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		four(bass,C,C,C,C,octave-1,1.0,BASSAZ);
		addFour(bass,C,C,C,C,octave-2,1.0,BASSAZ);
	add();
	cat();
	//MEASURE # 59
	#ifdef DEBUG
	puts("Measure # 59");
	#endif
		//VOICE
		four(voice,F,G,A,B,octave,1.0,VOICEAZ);
		//HARMONY
		fourChord(harmony,A/2,C,F,G,octave,0.625,CHORDAZ);
		appendThree(harmony,C,F,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		four(bass,C,C,C,C,octave-1,1.0,BASSAZ);
		addFour(bass,C,C,C,C,octave-2,1.0,BASSAZ);
	add();
	cat();
	//MEASURE # 60
	#ifdef DEBUG
	puts("Measure # 60");
	#endif
		//VOICE
		create(voice,G,octave,0.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,G,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,0.375,CHORDAZ);
		appendInterval(harmony,D,G,octave,0.125/2,CHORDAZ);
		appendInterval(harmony,D,G,octave,0.125/2,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.125*3/2,CHORDAZ);
		appendInterval(harmony,D,G,octave,0.125/2,CHORDAZ);
		appendInterval(harmony,D,G,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.5,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 61
	#ifdef DEBUG
	puts("Measure # 61");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,D,octave,0.125,VOICEAZ);
		appendTwo(voice,D,G,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,0.625,CHORDAZ);
		appendThree(harmony,D,E,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		four(bass,A,A,A,A,octave-2,1.0,BASSAZ);
		addFour(bass,A,A,A,A,octave-3,1.0,BASSAZ);
	add();
	cat();
	//MEASURE # 62
	#ifdef DEBUG
	puts("Measure # 62");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,D,octave,0.125,VOICEAZ);
		appendTwo(voice,D,2*D,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,D,G,octave,0.625,CHORDAZ);
		appendThree(harmony,D,G,A,octave,0.375,CHORDAZ);
	add();
		//BASS
		four(bass,D,D,D,D,octave-1,1.0,BASSAZ);
		addFour(bass,D,D,D,D,octave-2,1.0,BASSAZ);
	add();
	cat();
	//MEASURE # 63
	#ifdef DEBUG
	puts("Measure # 63");
	#endif
		//VOICE
		four(voice,Cs,D,E,A/2,octave+1,1.0,VOICEAZ);
		//HARMONY
		three(harmony,Cs,D,E,octave+1,0.75,CHORDAZ);
		interval(harmony,G,B,octave,0.5,CHORDAZ);
		appendInterval(harmony,Fs,A,octave,0.25,CHORDAZ);
		appendInterval(harmony,Fs,A,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.25,BASSAZ);
		appendInterval(bass,D,2*D,octave-2,0.25,BASSAZ);
		appendInterval(bass,D,2*D,octave-1,0.5,BASSAZ);
	add();
	cat();

	//MEASURE # 64
	#ifdef DEBUG
	puts("Measure # 64");
	#endif
		//VOICE
		create(voice,D,octave+1,0.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,G,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,D,G,B,octave,0.25,CHORDAZ);
		appendChord(harmony,D,Fs,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,F,G,2*D,octave,0.25,CHORDAZ);
		appendFourChord(harmony,G,B,2*D,2*G,octave,0.25,CHORDAZ);
	add();
		//BASS
		four(bass,G,A,B,G,octave-1,1.0,BASSAZ);
		four(bass,G,A,B,G,octave-2,1.0,BASSAZ);
		add();
	add();
	CRESCENDO;
	cat();
	FORTE;
	//MEASURE # 65
	#ifdef DEBUG
	puts("Measure # 65");
	#endif
		//VOICE
		create(voice,E,octave+1,0.375,VOICEAZ);
		append(voice,E,octave+1,0.125,VOICEAZ);
		append(voice,D,octave+1,0.25,VOICEAZ);
		append(voice,B,octave+1,0.25,VOICEAZ);
		//HARMONY
		fourChord(harmony,G/2,C,E,G,octave+1,0.25,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave,0.25,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.25,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.375,BASSAZ);
		append(bass,C,octave-1,0.125,BASSAZ);
		append(bass,A,octave-2,0.375,BASSAZ);
		append(bass,A,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 66
	#ifdef DEBUG
	puts("Measure # 66");
	#endif
		//VOICE
		create(voice,C,octave+1,0.375,VOICEAZ);
		append(voice,B,octave,0.125,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ);
		append(voice,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,A/2,C,F,octave,0.25,CHORDAZ);
		appendChord(harmony,F,A,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave+1,0.25,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.375,BASSAZ);
		appendInterval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendInterval(bass,E,2*E,octave-2,0.25,BASSAZ);
		append(bass,A,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 67
	#ifdef DEBUG
	puts("Measure # 67");
	#endif
		//VOICE
		four(voice,2*D,B,A,G,octave,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,A/2,C,F,octave+1,0.25,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.25,CHORDAZ);
		appendChord(harmony,F,A,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.375,BASSAZ);
		appendInterval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 68
	#ifdef DEBUG
	puts("Measure # 68");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,C,octave+1,0.25,VOICEAZ);
		//HARMONY
                silence(0.125);
		append(harmony,G,octave,0.125,CHORDAZ);
		appendTwo(harmony,C,G,octave+1,0.25,CHORDAZ);
		appendChord(harmony,G/2,C,G,octave+1,0.125,CHORDAZ);
		appendTwo(harmony,E,F,octave+1,0.125,CHORDAZ);
		appendChord(harmony,G/2,C,G,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.5,BASSAZ);
		appendInterval(bass,D,2*D,octave-2,0.25,BASSAZ);
		appendInterval(bass,E,2*E,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 69
	#ifdef DEBUG
	puts("Measure # 69");
	#endif
		//VOICE
		create(voice,C,octave+1,0.375,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		append(voice,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		fourChord(harmony,A/2,C,F,A,octave+1,0.125*3/2,CHORDAZ);
		appendFourChord(harmony,A/2,C,F,A,octave+1,0.125/2,CHORDAZ);
		appendFourChord(harmony,A/2,C,F,A,octave+1,0.5,CHORDAZ);
		appendChord(harmony,A/2,C,F,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,F,2*F,octave-2,0.125*3/2,BASSAZ);
		appendInterval(bass,F,2*F,octave-2,0.125/2,BASSAZ);
		appendInterval(bass,F,2*F,octave-2,0.5,BASSAZ);
		appendInterval(bass,Db,2*Db,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 70
	#ifdef DEBUG
	puts("Measure # 70");
	#endif
		//VOICE
		create(voice,C,octave+1,0.375,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		//HARMONY
		fourChord(harmony,G/2,C,D,G,octave+1,0.25,CHORDAZ);
		appendChord(harmony,G/2,C,D,octave+1,0.25,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.25,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,E,2*E,octave-2,0.375,BASSAZ);
		appendInterval(bass,E,2*E,octave-2,0.125,BASSAZ);
		append(bass,A,octave-2,0.375,BASSAZ);
		append(bass,A,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 71
	#ifdef DEBUG
	puts("Measure # 71");
	#endif
		//VOICE
		four(voice,A,2*C,G,2*D,octave,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,A/2,C,F,octave+1,0.25,CHORDAZ);
		appendChord(harmony,F,A,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.25,CHORDAZ);
		appendChord(harmony,F,A,2*C,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.375,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		append(bass,F,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 72 & 73
	#ifdef DEBUG
	puts("Measure # 72 & 73");
	#endif
		//VOICE
		create(voice,C,octave+1,1.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,E,A,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,E,A,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,A/2,C,E,octave+1,0.25,CHORDAZ);
		appendChord(harmony,E,A,2*C,octave,0.25,CHORDAZ);
		appendFourChord(harmony,A/2,C,E,A,octave+1,0.125*3/2,CHORDAZ);
		appendFourChord(harmony,A/2,C,E,A,octave,0.125/2,CHORDAZ);
		appendFourChord(harmony,A/2,C,E,A,octave,0.5,CHORDAZ);
		appendChord(harmony,E,A,2*C,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,A,octave-2,0.375,BASSAZ);
		append(bass,A,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,Fs,2*Fs,octave-2,0.125*3/2,BASSAZ);
		appendInterval(bass,Fs,2*Fs,octave-2,0.125/2,BASSAZ);
		appendInterval(bass,Fs,2*Fs,octave-2,0.5,BASSAZ);
		appendInterval(bass,Fs,2*Fs,octave-2,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 74
	#ifdef DEBUG
	puts("Measure # 74");
	#endif
		//VOICE
		create(voice,A,octave,0.5,VOICEAZ);
		append(voice,C,octave+1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,C,F,A,octave,0.5,CHORDAZ);
		appendChord(harmony,F,A,2*C,octave,0.5,CHORDAZ);
	add();
		//BASS
		four(bass,D,E,F,E,octave-1,0.5,BASSAZ);
		addFour(bass,D,E,F,E,octave-2,0.5,BASSAZ);
		four(bass,D,C,B/2,A/2,octave-1,0.5,BASSAZ);
		addFour(bass,D,C,B/2,A/2,octave-2,0.5,BASSAZ);
		cat();
	add();
	cat();
	//MEASURE # 75
	#ifdef DEBUG
	puts("Measure # 75");
	#endif
		//VOICE
		create(voice,G,octave,0.5,VOICEAZ);
		append(voice,D,octave+1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,D,G,B,octave,0.5,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.5,CHORDAZ);
	add();
		//BASS
		interval(bass,F,2*F,octave-3,0.25,BASSAZ);
		appendInterval(bass,F,2*F,octave-3,0.5,BASSAZ);
		appendInterval(bass,F,2*F,octave-3,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 76
	#ifdef DEBUG
	puts("Measure # 76");
	#endif
		//VOICE
		create(voice,C,octave+1,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,Ef,Af,2*C,octave,0.5,CHORDAZ);
		appendChord(harmony,Ef,Af,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,Af/2,C,2*Ef,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,Af,2*Af,octave-3,0.25,BASSAZ);
		appendInterval(bass,Af,2*Af,octave-2,0.125,BASSAZ);
		appendInterval(bass,Bf,2*Bf,octave-2,0.125,BASSAZ);
		four(bass,2*C,Bf,Af,G,octave-1,0.25,BASSAZ);
		addFour(bass,2*C,Bf,Af,G,octave-2,0.25,BASSAZ);
		cat();
	add();
	cat();
	//MEASURE # 77
	#ifdef DEBUG
	puts("Measure # 77");
	#endif
		//VOICE
		silence(0.25);
		append(voice,C,octave+1,0.25,VOICEAZ);
		append(voice,C,octave+1,0.375,VOICEAZ);
		append(voice,D,octave+1,0.125,VOICEAZ);
		//HARMONY
		fourChord(harmony,Af/2,C,D,F,octave,0.125*3/2,CHORDAZ);
		appendFourChord(harmony,Af/2,C,D,F,octave,0.125/2,CHORDAZ);
		appendFourChord(harmony,Af/2,C,D,F,octave,0.75,CHORDAZ);
	add();
		//BASS
		interval(bass,F,2*F,octave-2,0.125*3/2,BASSAZ);
		appendInterval(bass,F,2*F,octave-2,0.125,BASSAZ);
		appendInterval(bass,F,2*F,octave-2,0.75,BASSAZ);
	add();
	cat();

	//MEASURE # 78 & 79
	#ifdef DEBUG
	puts("Measure # 78 & 79");
	#endif
		DOUBLEFORTE;
		//VOICE
		interval(voice,C,E,octave+1,1.0+FERMATA(1.0),VOICEAZ);
		//HARMONY
		fourChord(harmony,G/2,C,E,G,octave+1,1.0,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave,FERMATA(1.0),CHORDAZ);
	add();
		//BASS
		interval(bass,C,E,octave,0.5,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,FERMATA(1.0),BASSAZ);
	add();
	cat();
}



void midPart(void){
	static int repeats=0;
	MESSOFORTE;
	//MEASURE # 13
	#ifdef DEBUG
	puts("Measure # 13");
	#endif
		//VOICE
		create(voice,E,octave+1,0.375,VOICEAZ);
		append(voice,E,octave+1,0.125,VOICEAZ);
		appendTwo(voice,D,C,octave+1,0.5,VOICEAZ);
		//HARMONY
		fourChord(harmony,E/2,C,E,G,octave+1,0.25,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave+1,0.25,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.25,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave+1,0.25,CHORDAZ);

	add();
		//BASS
		interval(bass,C,C/2,octave-1,0.375,BASSAZ);
		append(bass,C,octave-1,0.125,BASSAZ);
		appendInterval(bass,E,E/2,octave-1,0.375,BASSAZ);
		append(bass,E,octave-1,0.125,BASSAZ);
	add();
	//MEASURE # 14
	#ifdef DEBUG
	puts("Measure # 14");
	#endif
		//VOICE
		create(voice,C,octave+1,0.375,VOICEAZ);
		append(voice,B,octave,0.125,VOICEAZ);
		append(voice,B,octave,0.23,VOICEAZ);
                appendSilence(0.02);
		append(voice,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,A/2,C,F,octave+1,0.25,CHORDAZ);
		appendChord(harmony,C,F,A,octave+1,0.25,CHORDAZ);
		appendChord(harmony,D,G,B,octave+1,0.23,CHORDAZ);
                appendSilence(0.02);
		appendChord(harmony,C,F,A,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,D,D/2,octave-1,0.375,BASSAZ);
		appendInterval(bass,D,D/2,octave-1,0.125,BASSAZ);
		appendInterval(bass,G,G/2,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 15
	#ifdef DEBUG
	puts("Measure # 15");
	#endif
		//VOICE
		four(voice,2*D,B,A,G,octave,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,D,G,octave+1,0.25,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.25,CHORDAZ);
		appendChord(harmony,A/2,C,F,octave+1,0.25,CHORDAZ);
		appendChord(harmony,B/2,D,G,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,G,G/2,octave-1,0.375,BASSAZ);
		appendInterval(bass,G,G/2,octave-1,0.125,BASSAZ);
		appendInterval(bass,A,A/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,B,B/2,octave-1,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 16
	#ifdef DEBUG
	puts("Measure # 16");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
                appendSilence(0.25);
		append(voice,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		silence(0.125);
		appendChord(harmony,C,D,G/2,octave+1,0.125/2,CHORDAZ);
		appendChord(harmony,C,D,G/2,octave+1,0.125/2,CHORDAZ);
		appendChord(harmony,C,D,G/2,octave+1,0.125,CHORDAZ);
		appendChord(harmony,C,D,G,octave+1,0.125,CHORDAZ);
		appendChord(harmony,C,F,G,octave+1,0.125*3/2,CHORDAZ);
		appendChord(harmony,C,F,G,octave+1,0.125/2,CHORDAZ);
		appendChord(harmony,C,E,G,octave+1,0.125,CHORDAZ);
		appendChord(harmony,C,E,G,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		chord(bass,C,2*G,C,octave-1,0.5,BASSAZ);
		appendChord(bass,Db,A,Db*2,octave-2,0.125*3/2,BASSAZ);
		appendChord(bass,Db,A,Db*2,octave-2,0.125/2,BASSAZ);
		appendInterval(bass,E,E/2,octave-1,0.125,BASSAZ);
		appendInterval(bass,E,E/2,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 17
	#ifdef DEBUG
	puts("Measure # 17");
	#endif
		//VOICE
		create(voice,C,octave+1,0.25*3/2,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		appendTwo(voice,A,2*C,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,C,F,A,octave+1,0.25,CHORDAZ);
		appendInterval(harmony,A,2*F,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,G,2*E,octave+1,0.125,CHORDAZ);
		appendChord(harmony,E,F,2*C,octave+1,0.25,CHORDAZ);
		appendTwo(harmony,C,A,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-2,0.75,BASSAZ);
                appendSilence(0.25);
		four(bass,G/2,C,G,A,octave-1,0.5,BASSAZ);
		appendTwo(bass,C,D/2,octave,0.5,BASSAZ);
		add();
	add();
	cat();

	//MEASURE # 18
	#ifdef DEBUG
	puts("Measure # 18");
	#endif
		//VOICE
		create(voice,C,octave+1,0.25*3/2,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.23,VOICEAZ);
                appendSilence(0.02);
		append(voice,G,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave+1,0.25,CHORDAZ);
		appendInterval(harmony,E,2*C,octave+1,0.125,CHORDAZ);
                appendInterval(harmony,D,B,octave+1,0.125,CHORDAZ);
		appendChord(harmony,B/2,C,G,octave+1,0.25,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-2,0.75,BASSAZ);
		two(bass,G/2,E,octave-1,0.25,BASSAZ);
		append(bass,G,octave-1,0.5,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 19
	#ifdef DEBUG
	puts("Measure # 19");
	#endif
		//VOICE
		four(voice,A/2,C,G/2,Db,octave+1,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,A/2,C,F,octave+1,0.25,CHORDAZ);
		appendChord(harmony,F,A,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,D,G,B,octave,0.25,CHORDAZ);
		appendChord(harmony,F,A,2*Db,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,G,G/2,octave-1,0.25*3/2,BASSAZ);
		appendInterval(bass,G,G/2,octave-1,0.25/2,BASSAZ);
		appendInterval(bass,G,G/2,octave-1,0.25,BASSAZ);
		appendInterval(bass,G,G/2,octave-1,0.25/2,BASSAZ);
	add();
	cat();
	//MEASURE # 20
	#ifdef DEBUG
	puts("Measure # 20");
	#endif
		//VOICE
		create(voice,C,octave+1,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.375,CHORDAZ);
		append(harmony,D,octave,0.125,CHORDAZ);
		appendTwo(harmony,E,G,octave,0.25,CHORDAZ);
		append(harmony,C,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-1,1.0,BASSAZ);
		two(bass,C,G,octave-1,0.25,BASSAZ);
		append(bass,C,octave,0.75,BASSAZ);
                add();
	add();
	cat();
	//MEASURE # 21
	#ifdef DEBUG
	puts("Measure # 21");
	#endif
		//VOICE
		silence(0.75);
		append(voice,G,octave,0.25,VOICEAZ);
		//HARMONY
		fourChord(harmony,F,F,A,2*C,octave,1.0,CHORDAZ);
		silence(0.5);
		appendArpegioFive(harmony,2*C,A,G,F,C,octave+1,0.5,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,G,2*G,octave-2,1.0,BASSAZ);
	add();
	cat();


	//MEASURE # 22
	#ifdef DEBUG
	puts("Measure # 22");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		appendTwo(voice,E,G,octave,0.5,VOICEAZ);
		//HARMONY
		four(harmony,G,G,2*D,2*E,octave,0.5,CHORDAZ); //lower notes
		appendFour(harmony,E,G/2,C,E,octave+1,0.5,CHORDAZ);
		interval(harmony,D,E,octave,0.125,CHORDAZ); //upper notes first eighth
		add();
	add();
		//BASS
		chord(bass,C,G,2*C,octave-1,0.25,BASSAZ);
		appendChord(bass,C,G,2*C,octave-1,0.5,BASSAZ);
		appendChord(bass,C,G,2*C,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 23
	#ifdef DEBUG
	puts("Measure # 23");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,D,octave,0.125,VOICEAZ);
		append(voice,D,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		//HARMONY
		four(harmony,G,G,B,2*D,octave,0.5,CHORDAZ); //lower notes
		appendFour(harmony,G,G/2,B/2,E,octave+1,0.5,CHORDAZ);
		interval(harmony,B/2,D,octave+1,0.125,CHORDAZ);//upper notes first eight
		add();
	add();
		//BASS
		chord(bass,C,G,B,octave-1,0.25,BASSAZ);
		appendChord(bass,C,G,B,octave-1,0.5,BASSAZ);
		appendChord(bass,C,G,B,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 24
	#ifdef DEBUG
	puts("Measure # 24");
	#endif
		//VOICE
		four(voice,F,G,A,B,octave,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,A/2,C,F,octave+1,0.125,CHORDAZ);
		appendThree(harmony,A/2,C,F,octave+1,0.375,CHORDAZ);
		appendInterval(harmony,C,A,octave+1,0.125,CHORDAZ);
		append(harmony,F,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,B/2,G,octave+1,0.125,CHORDAZ);
		append(harmony,D,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		chord(bass,C,A,2*C,octave-1,0.25,BASSAZ);
		appendChord(bass,C,A,2*C,octave-1,0.5,BASSAZ);
		appendChord(bass,C,A,2*C,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 25
	#ifdef DEBUG
	puts("Measure # 25");
	#endif
		//VOICE
		create(voice,G,octave,0.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,G,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,G/2,D,E,octave+1,0.25,CHORDAZ);
		appendTwo(harmony,D,E,octave,0.25,CHORDAZ);
		appendChord(harmony,A/2,C,F,octave,0.5,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-1,0.125,BASSAZ);
		append(bass,G,octave-1,0.375,BASSAZ);
		create(bass,C,octave-1,0.5,BASSAZ);
		append(bass,G,octave-2,0.5,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 26
	#ifdef DEBUG
	puts("Measure # 26");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		appendTwo(voice,E,G,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,C,D,G,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,2*C,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,D,B,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,C,A,octave+1,0.25,CHORDAZ);
		appendChord(harmony,B/2,C,G,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,C,G,octave-1,0.25,BASSAZ);
		append(bass,C,octave,0.5,BASSAZ);
		create(bass,C,octave-1,0.75,BASSAZ);
		append(bass,A,octave-2,0.25,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 27
	#ifdef DEBUG
	puts("Measure # 27");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,D,octave,0.125,VOICEAZ);
		appendTwo(voice,D,2*D,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,A,B,2*D,octave,0.25,CHORDAZ);
		appendInterval(harmony,B,2*D,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,A,2*C,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,G,B,octave+1,0.25,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,D,B,octave-1,0.25,BASSAZ);
		append(bass,D,octave,0.75,BASSAZ);
		create(bass,D,octave-1,0.75,BASSAZ);
		append(bass,D,octave,0.25,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 28
	#ifdef DEBUG
	puts("Measure # 28");
	#endif
		//VOICE
		create(voice,Cs,octave+1,0.375,VOICEAZ);
		append(voice,D,octave+1,0.125,VOICEAZ);
		append(voice,E,octave+1,0.25,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,G,B,Cs*2,octave,0.25,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.25,CHORDAZ);
		appendChord(harmony,Fs,A,2*E,octave,0.25,CHORDAZ);
		appendInterval(harmony,Fs,A,octave,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,D,B,octave-1,0.25,BASSAZ);
		append(bass,D,octave,0.25,BASSAZ);
		create(bass,D,octave,0.5,BASSAZ);
		appendInterval(bass,D,Cs,octave,0.5,BASSAZ);
		add();
	add();
	cat();
	if(repeats++<2){
	//MEASURE # 29
	#ifdef DEBUG
	puts("Measure # 29");
	#endif
		//VOICE
		create(voice,D,octave+1,0.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,F,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,C,G,B,octave,0.25,CHORDAZ);
		appendChord(harmony,D,Fs,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,F,G,2*D,octave,0.25,CHORDAZ);
		appendFourChord(harmony,G,B,2*D,2*G,octave,0.25,CHORDAZ);
		//BASS
		interval(bass,G,2*G,octave-2,0.25,BASSAZ);
		appendInterval(bass,A,2*A,octave-2,0.25,BASSAZ);
		appendInterval(bass,B,2*B,octave-2,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-2,0.25,BASSAZ);
		add();
		CRESCENDO;
	add();
	cat();
	}
	else{
	   coda();
           cat();
	}
}





void song(void){
	C = aFlat ;
	intro() ;
	midPart();
	cat();
        midPart();
	cat();
	midPart();
	cat();
}



int main(int argc, char** argv){
	tempo = 100;
	aFlat= AFLAT * C ;
        bFlat= BFLAT * C ;
	song();
	echo(10,0.3,4);
	puts("america the beautiful.wav");
	exportToWav("america the beautiful.wav");
}
