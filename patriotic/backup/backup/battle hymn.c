#include "soundlib.h"
#define DEBUG 1

#define VOICEAZ 75
#define CHORDAZ 135
#define BASSAZ 90

double (*voice)(double) = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double) = oldCircleOfRa;

short octave = 0;

double eKey,fKey,gFlatKey,gKey,aKey,cKey;


void song(void){
	MESSOPIANO;
	C=eKey;
	//MEASURE # 2 & 3
	#ifdef DEBUG
	puts("Measure # 2 & 3");
	#endif
		//HARMONY
		silence(0.25);
		appendFour(harmony,C,G,2*C,2*G,octave-1,0.25,CHORDAZ);
		append(harmony,C,octave+1,1.5,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-3,1.5,BASSAZ);
		grace(bass,C,C,octave-2,0.5,BASSAZ);
		grace(bass,C,C,octave-3,0.5,BASSAZ);
		add();
		cat();
	add();

	//MEASURE # 4 & 5
	#ifdef DEBUG
	puts("Measure # 4 & 5");
	#endif
		//VOICE
		silence(1.75);
		append(voice,G,octave-1,0.25,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendFour(harmony,C,G,2*C,2*G,octave-1,0.25,CHORDAZ);
		append(harmony,C,octave+1,1.5,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-3,1.5,BASSAZ);
		grace(bass,C,C,octave-2,0.5,BASSAZ);
		grace(bass,C,C,octave-3,0.5,BASSAZ);
		add();
		cat();
	add();
	cat();

	//MEASURE # 6 & 7
	#ifdef DEBUG
	puts("Measure # 6 & 7");
	#endif
		//VOICE
		create(voice,G,octave-1,0.375,VOICEAZ);
		append(voice,G,octave-1,.125,VOICEAZ);
		append(voice,G,octave-1,0.375,VOICEAZ);
		append(voice,F,octave-1,0.125,VOICEAZ);
		appendTwo(voice,E,G,octave-1,0.5,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,C,D,octave,0.25,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendFour(harmony,C,G,2*C,2*G,octave-1,0.25,CHORDAZ);
		append(harmony,C,octave+1,1.5,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-3,1.5,BASSAZ);
		grace(bass,C,C,octave-2,0.5,BASSAZ);
		grace(bass,C,C,octave-3,0.5,BASSAZ);
		add();
		cat();
	add();
	cat();

	//MEASURE # 8 & 9
	#ifdef DEBUG
	puts("Measure # 8 & 9");
	#endif
		//VOICE
		create(voice,E,octave,0.375,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.375,VOICEAZ);
		append(voice,D,octave,0.125,VOICEAZ);
		append(voice,C,octave,0.5,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,C,B/2,octave,0.25,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendFour(harmony,C,G,2*C,2*G,octave-1,0.25,CHORDAZ);
		append(harmony,C,octave+1,1.5,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-3,1.5,BASSAZ);
		grace(bass,C,C,octave-2,0.5,BASSAZ);
		grace(bass,C,C,octave-3,0.5,BASSAZ);
		add();
		cat();
	add();
	cat();

	//MEASURE # 10 & 11
	#ifdef DEBUG
	puts("Measure # 10 & 11");
	#endif
		//VOICE
		create(voice,A,octave-1,0.375,VOICEAZ);
		append(voice,A,octave-1,0.125,VOICEAZ);
		append(voice,A,octave-1,0.375,VOICEAZ);
		append(voice,B,octave-1,0.125,VOICEAZ);
		appendTwo(voice,C,B/2,octave,0.5,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,C,A/2,octave,0.25,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendFour(harmony,C,F,2*C,2*F,octave-1,0.25,CHORDAZ);
		append(harmony,C,octave+1,1.5,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-3,1.5,BASSAZ);
		grace(bass,C,C,octave-2,0.5,BASSAZ);
		grace(bass,C,C,octave-3,0.5,BASSAZ);
		add();
		cat();
	add();
	cat();

	//MEASURE # 12 & 13
	#ifdef DEBUG
	puts("Measure # 12 & 13");
	#endif
		//VOICE
		create(voice,G,octave-1,0.375,VOICEAZ);
		append(voice,A,octave-1,0.125,VOICEAZ);
		append(voice,G,octave-1,0.375,VOICEAZ);
		append(voice,E,octave-1,0.125,VOICEAZ);
		append(voice,G,octave-1,0.5,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,G,G,octave-1,0.25,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendFour(harmony,C,G,2*C,2*G,octave-1,0.25,CHORDAZ);
		append(harmony,C,octave+1,1.5,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-3,1.5,BASSAZ);
		grace(bass,C,C,octave-2,0.5,BASSAZ);
		grace(bass,C,C,octave-3,0.5,BASSAZ);
		add();
		cat();
	add();
	cat();
	//MEASURE # 14 & 15
	#ifdef DEBUG
	puts("Measure # 14 & 15");
	#endif
		//VOICE
		create(voice,G,octave-1,0.375,VOICEAZ);
		append(voice,G,octave-1,0.125,VOICEAZ);
		append(voice,G,octave-1,0.375,VOICEAZ);
		append(voice,F,octave-1,0.125,VOICEAZ);
		appendTwo(voice,E,G,octave-1,0.5,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,C,D,octave,0.25,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendFour(harmony,C,G,2*C,2*G,octave-1,0.25,CHORDAZ);
		append(harmony,C,octave+1,1.5,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-3,1.5,BASSAZ);
		grace(bass,C,C,octave-2,0.5,BASSAZ);
		grace(bass,C,C,octave-3,0.5,BASSAZ);
		add();
		cat();
	add();
	cat();

	//MEASURE # 16 & 17
	#ifdef DEBUG
	puts("Measure # 16 & 17");
	#endif
		//VOICE
		create(voice,E,octave,0.375,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		append(voice,D,octave,0.25,VOICEAZ);
		append(voice,C,octave,0.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,C,octave,0.25,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendFour(harmony,C,G,2*C,2*G,octave-1,0.25,CHORDAZ);
		append(harmony,C,octave+1,1.5,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,1.5,BASSAZ);
		grace(bass,C,C,octave-2,0.5,BASSAZ);
		grace(bass,C,C,octave-3,0.5,BASSAZ);
		add();
		cat();
	add();
	cat();

	//MEASURE # 18 & 19
	#ifdef DEBUG
	puts("Measure # 18 & 19");
	#endif
		//VOICE
		create(voice,D,octave,0.5,VOICEAZ);
		append(voice,D,octave,0.5,VOICEAZ);
		append(voice,C,octave,0.5,VOICEAZ);
		append(voice,B/2,octave,0.5,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendFour(harmony,C,G,2*C,2*G,octave-1,0.25,CHORDAZ);
		append(harmony,C,octave+1,1.5,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-3,2.0,BASSAZ);
	add();
	cat();
	//MEASURE # 20 & 21
	#ifdef DEBUG
	puts("Measure # 20 & 21");
	#endif
		//VOICE
		create(voice,C,octave,1.0,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendFour(harmony,C,G,2*C,2*G,octave-1,0.25,CHORDAZ);
		append(harmony,C,octave+1,1.0,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-3,1.375,BASSAZ);
		appendInterval(bass,C,2*C,octave-3,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-3,0.5,BASSAZ);
	add();
	cat();
	MESSOFORTE;
		//VOICE
		silence(0.25);
		appendTwo(voice,G,G,octave-1,0.25,VOICEAZ);
		//HARMONY
		fourChord(harmony,C,E,G,2*C,octave,0.125,CHORDAZ);
		appendInterval(harmony,D,2*D,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,2*E,octave,0.125,CHORDAZ);
		appendInterval(harmony,G,2*G,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-3,0.5,BASSAZ);
	add();
	CRESCENDO;
	cat();
	C=fKey;
	//MEASURE # 22 & 23
	#ifdef DEBUG
	puts("Measure # 22 & 23");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.375,VOICEAZ);
		append(voice,F,octave,0.125,VOICEAZ);
		appendTwo(voice,E,G,octave,0.5,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,C,D,octave+1,0.25,VOICEAZ);
		//HARMONY
		fourChord(harmony,G/2,C,E,G,octave+2,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,C,E,G,octave,0.75,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,C,E,G,octave,0.25,CHORDAZ);
		appendFourChord(harmony,A/2,C,F,G,octave,0.5,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,C,2*C,octave-2,0.5,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 24
	#ifdef DEBUG
	puts("Measure # 24");
	#endif
		//VOICE
		create(voice,E,octave+1,0.375,VOICEAZ);
		append(voice,E,octave+1,0.125,VOICEAZ);
		create(voice,E,octave+1,0.375,VOICEAZ);
		append(voice,D,octave+1,0.125,VOICEAZ);
		cat();
		//HARMONY
		chord(harmony,C,E,G,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		chord(harmony,C,E,G,octave,0.75,CHORDAZ);
		cat();
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		interval(bass,C,2*C,octave-2,0.75,BASSAZ);
		cat();
	add();
	cat();
    //MEASURE # 25
    #ifdef DEBUG
    puts("Measure # 25");
    #endif
        //VOICE
        create(voice,C,octave+1,0.5,VOICEAZ);
        appendSilence(0.25);
        appendTwo(voice,2*C,B,octave,0.25,VOICEAZ);
        //HARMONY
        silence(0.25);
        append(harmony,C,octave+1,0.1875,CHORDAZ);
        append(harmony,C,octave+1,0.0625,CHORDAZ);
        appendTwo(harmony,C,C,octave+1,0.5,CHORDAZ);
        fourChord(harmony,A/2,C,F,G,octave,0.5,CHORDAZ);
        appendChord(harmony,C,E,G,octave,0.5,CHORDAZ);
        add();
    add();
        //BASS
        interval(bass,C,2*C,octave-2,0.125,BASSAZ);
        appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
        appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
        appendInterval(bass,C,2*C,octave-2,0.5,BASSAZ);
    add();
    cat();
    //MEASURE # 26 & 27
    #ifdef DEBUG
    puts("Measure # 26 & 27");
    #endif
        //VOICE
        create(voice,A,octave,0.375,VOICEAZ);
        append(voice,A,octave,0.125,VOICEAZ);
        append(voice,A,octave,0.375,VOICEAZ);
        append(voice,B,octave,0.125,VOICEAZ);
        appendTwo(voice,2*C,B,octave,0.5,VOICEAZ);
        appendSilence(0.25);
        appendTwo(voice,2*C,A,octave,0.25,VOICEAZ);
        //HARMONY
        fourChord(harmony,A/2,C,F,G,octave,0.125,CHORDAZ);
        appendSilence(0.125);
        appendFourChord(harmony,A/2,C,F,G,octave,0.75,CHORDAZ);
    add();
        //BASS
        interval(bass,C,2*C,octave-2,0.125,BASSAZ);
        appendSilence(0.125);
        appendInterval(bass,C,2*C,octave,0.75+0.125,BASSAZ);
        appendInterval(bass,C,2*C,octave,0.125,BASSAZ);
        appendInterval(bass,C,2*C,octave,0.25,BASSAZ);
        appendInterval(bass,C,2*C,octave,0.5,BASSAZ);
    add();
    cat();
	//MEASURE # 28
	#ifdef DEBUG
	puts("Measure # 28");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.375,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,C,E,G,octave,0.75,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,C,2*C,octave,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 29
	#ifdef DEBUG
	puts("Measure # 29");
	#endif
		//VOICE
		create(voice,G,octave,0.5,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,G,G,octave,0.25,VOICEAZ);
		//HARMONY
		silence(0.25);
		append(harmony,C,octave+1,0.1875,CHORDAZ);
		append(harmony,C,octave+1,0.0625,CHORDAZ);
		append(harmony,C,octave+1,0.1875,CHORDAZ);
		appendInterval(harmony,C,G,octave+1,0.0625,CHORDAZ);
		appendInterval(harmony,C,G,octave+1,0.25,CHORDAZ);
		chord(harmony,C,E,G,octave,0.5,CHORDAZ);
		appendChord(harmony,F,G,A,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 30 & 31
	#ifdef DEBUG
	puts("Measure # 30 & 31");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.375,VOICEAZ);
		append(voice,F,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,C,D,octave+1,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,C,E,G,octave,0.75,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,C,E,G,octave,0.25,CHORDAZ);
		appendFourChord(harmony,A/2,C,F,G,octave,0.5,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,C,2*C,octave-2,0.875,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 32
	#ifdef DEBUG
	puts("Measure # 32");
	#endif
		//VOICE
		create(voice,E,octave+1,0.375,VOICEAZ);
		append(voice,E,octave+1,0.125,VOICEAZ);
		append(voice,E,octave+1,0.375,VOICEAZ);
		append(voice,D,octave+1,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,E,A,B,octave,0.25,CHORDAZ);
		appendChord(harmony,E,A,B,octave,0.25,CHORDAZ);
		appendChord(harmony,E,Gs,B,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,D,E,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,B,2*B,octave-3,0.375,BASSAZ);
		appendInterval(bass,B,2*B,octave-3,0.125,BASSAZ);
		appendInterval(bass,B,2*B,octave-3,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 33
	#ifdef DEBUG
	puts("Measure # 33");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,E,A,2*C,octave,0.25,CHORDAZ);
		appendTwo(harmony,A,B,octave,0.25,CHORDAZ);
		appendChord(harmony,E,A,2*C,octave,0.125,CHORDAZ);
		appendThree(harmony,E,A,2*C,octave+1,0.375,CHORDAZ);
	add();
		//BASS
		interval(bass,A,2*A,octave-3,0.375,BASSAZ);
		appendInterval(bass,A,2*A,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 34
	#ifdef DEBUG
	puts("Measure # 34");
	#endif
		//VOICE
		create(voice,Db,octave+1,0.5,VOICEAZ);
		append(voice,Db,octave+1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,Db,A,2*Db,octave+1,0.25,CHORDAZ);
		appendChord(harmony,Db,A,2*Db,octave,0.25,CHORDAZ);
		appendChord(harmony,A/2,Db,2*Db,octave+1,0.25,CHORDAZ);
		appendFourChord(harmony,Db,Fs,A,2*Db,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,E,2*E,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,Fs,2*Fs,octave-2,0.375,BASSAZ);
		appendInterval(bass,Fs,2*Fs,octave-2,0.125,BASSAZ);
		appendInterval(bass,Fs,2*Fs,octave-2,0.25,BASSAZ);
		appendInterval(bass,Fs,2*Fs,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 35
	#ifdef DEBUG
	puts("Measure # 35");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		append(voice,B,octave,0.5,VOICEAZ);
		//HARMONY
		fourChord(harmony,F,A,2*C,2*F,octave+1,0.25,CHORDAZ);
		appendFourChord(harmony,F,A,2*C,2*F,octave,0.25,CHORDAZ);
		appendFourChord(harmony,F,A,2*C,2*F,octave+1,0.25,CHORDAZ);
		appendFourChord(harmony,G,B,2*D,2*G,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,G,2*G,octave-2,0.5,BASSAZ);
		appendInterval(bass,G,2*G,octave-2,0.5,BASSAZ);
	add();
	cat();
	C=gFlatKey;
	//MEASURE # 36
	#ifdef DEBUG
	puts("Measure # 36");
	#endif
		//VOICE
		create(voice,B,octave,1.0,VOICEAZ);
		//HARMONY
		fourChord(harmony,G,B,2*D,2*G,octave,0.25,CHORDAZ);
		appendChord(harmony,D,G,2*B,octave,0.25,CHORDAZ);
		fourChord(harmony,D,G,B,2*D,octave,0.25,CHORDAZ);
		appendFourChord(harmony,D,B,2*D,2*G,octave,0.25,CHORDAZ);
		CRESCENDO;
		cat();
	add();
		//BASS
		interval(bass,G,2*G,octave-2,0.375,BASSAZ);
		interval(bass,G,2*G,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-2,0.5,BASSAZ);
		CRESCENDO;
		cat();
	add();
	cat();
	//MEASURE # 37
	#ifdef DEBUG
	puts("Measure # 37");
	#endif
		//VOICE
		silence(0.75);
		appendTwo(voice,G,G,octave,0.25,VOICEAZ);
		//HARMONY
		fourChord(harmony,F,A,2*C,F,octave,0.25,CHORDAZ);
		interval(harmony,F,2*C,octave,0.125,CHORDAZ);
		appendInterval(harmony,A,2*G,octave,0.125,CHORDAZ);
		appendThree(harmony,A,G,F,octave,0.375,CHORDAZ);
		DECRESCENDO;
		cat();
	add();
		//BASS
		interval(bass,G,2*G,octave-2,1.0,BASSAZ);
	add();
	cat();
	//MEASURE # 38
	#ifdef DEBUG
	puts("Measure # 38");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.375,VOICEAZ);
		append(voice,F,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave,0.25,CHORDAZ);
		appendTwo(harmony,G/2,C,octave,0.25,CHORDAZ);
		appendTwo(harmony,E,G/2,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.125,CHORDAZ);
		appendInterval(harmony,Db,F,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-1,1.0,BASSAZ);
	add();
	cat();
	//MEASURE # 39
	#ifdef DEBUG
	puts("Measure # 39");
	#endif
		//VOICE
		two(voice,E,G,octave,0.25,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,C,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave,0.25,CHORDAZ);
		appendTwo(harmony,G/2,C,octave,0.25,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		appendThree(harmony,G/2,C,E,octave,0.375,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-1,1.0,BASSAZ);
	add();
	cat();
	//MEASURE # 40
	#ifdef DEBUG
	puts("Measure # 40");
	#endif
		//VOICE
		create(voice,E,octave+1,0.375,VOICEAZ);
		append(voice,E,octave+1,0.125,VOICEAZ);
		append(voice,E,octave+1,0.375,VOICEAZ);
		append(voice,D,octave+1,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave,0.25,CHORDAZ);
		appendFour(harmony,G/2,C,E,G/2,octave,0.5,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		appendInterval(harmony,D,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-1,1.0,BASSAZ);
	add();
	cat();
	//MEASURE # 41
	#ifdef DEBUG
	puts("Measure # 41");
	#endif
		//VOICE
		create(voice,G,octave+1,0.5,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,C,B/2,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,G,octave+1,0.25,CHORDAZ);
		appendInterval(harmony,C,E,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,Db,F,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,E,G,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		four(bass,C,G,2*C,2*D,octave-1,0.5,BASSAZ);
		appendTwo(bass,E,G,octave,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 42
	#ifdef DEBUG
	puts("Measure # 42");
	#endif
		//VOICE
		create(voice,A,octave,0.375,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.375,VOICEAZ);
		append(voice,B,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave+1,0.25,CHORDAZ);
		appendFour(harmony,C,F,A,C,octave,0.5,CHORDAZ);
		appendInterval(harmony,F,A,octave,0.125,CHORDAZ);
		appendInterval(harmony,G,B,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-1,0.125,BASSAZ);
		append(bass,A,octave-1,0.875,BASSAZ);
	add();
	cat();

	//MEASURE # 43
	#ifdef DEBUG
	puts("Measure # 43");
	#endif
		//VOICE
		two(voice,C,B/2,octave+1,0.5,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,C,A/2,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,A,2*C,octave,0.125,CHORDAZ);
		append(harmony,C,octave,0.125,CHORDAZ);
		appendInterval(harmony,G,B,octave,0.125,CHORDAZ);
		append(harmony,C,octave,0.125,CHORDAZ);
		appendInterval(harmony,A,2*C,octave,0.125,CHORDAZ);
		appendThree(harmony,C,F,A,octave,0.375,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-1,1.0,BASSAZ);
	add();
	cat();
	//MEASURE # 44
	#ifdef DEBUG
	puts("Measure # 44");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.375,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		//HARMONY
		four(harmony,G,0,G,A,octave,0.5,CHORDAZ);
		addFour(harmony,E,C,E,F,octave,0.5,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.25,CHORDAZ);
		appendTwo(harmony,D,E,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-1,1.0,BASSAZ);
	add();
	cat();

	//MEASURE # 45
	#ifdef DEBUG
	puts("Measure # 45");
	#endif
		//VOICE
		create(voice,G,octave,0.5,VOICEAZ);
		appendSilence(0.25);
		MESSOFORTE;
			appendTwo(voice,G,G,octave,0.25,VOICEAZ);
		MESSOPIANO;
		//HARMONY
		create(harmony,G,octave,0.25,CHORDAZ);
		appendInterval(harmony,C,D,octave,0.125,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
		MESSOFORTE;
			chord(harmony,B/2,D,G,octave,0.375,CHORDAZ);
			appendFourChord(harmony,G,B,D,2*D,octave,0.125,CHORDAZ);
			CRESCENDO;
		MESSOPIANO;
		cat();
	add();
		//BASS
		two(bass,G/2,D,octave-1,0.25,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
		MESSOFORTE;
		four(bass,G,D,G,G/2,octave,0.5,BASSAZ);
		CRESCENDO;
		cat();
	add();
	cat();
	C=gKey;
	//MEASURE # 46
	#ifdef DEBUG
	puts("Measure # 46");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.375,VOICEAZ);
		append(voice,F,octave,0.125,VOICEAZ);
		//HARMONY
		fourChord(harmony,G/2,C,E,G,octave+1,0.5,CHORDAZ);
		appendFourChord(harmony,C,E,G,2*C,octave+1,0.25,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+2,0.125,CHORDAZ);
		appendInterval(harmony,F,2*F,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		four(bass,G/2,E,G,2*C,octave-1,0.5,BASSAZ);
		append(bass,E,octave,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 47
	#ifdef DEBUG
	puts("Measure # 47");
	#endif
		//VOICE
		two(voice,E,G,octave,0.5,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,C,D,octave+1,0.25,VOICEAZ);
		//HARMONY
		fourChord(harmony,E,G,2*C,2*E,octave,0.375,CHORDAZ);
		appendInterval(harmony,G,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,D,G,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,C,2*C,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,C,2*C,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,C,2*C,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,G/2,E,octave-1,0.25,BASSAZ);
		append(bass,C,octave,0.25,BASSAZ);
		appendInterval(bass,F/2,F,octave-1,0.25,BASSAZ);
		appendInterval(bass,F/2,F,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 48
	#ifdef DEBUG
	puts("Measure # 48");
	#endif
		//VOICE
		create(voice,E,octave+1,0.375,VOICEAZ);
		append(voice,E,octave+1,0.125,VOICEAZ);
		append(voice,E,octave+1,0.375,VOICEAZ);
		append(voice,D,octave+1,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,E,B,2*E,octave+1,0.375,CHORDAZ);
		append(harmony,B,octave-1,0.125,CHORDAZ);
		append(harmony,B,octave,0.25,CHORDAZ);
		appendInterval(harmony,B/2,E,octave,0.125,CHORDAZ);
		append(harmony,B,octave,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,Gs/2,E,octave-1,0.25,BASSAZ);
		append(bass,Gs,octave-1,0.25,BASSAZ);
		two(bass,Gs/2,E,octave-1,0.25,BASSAZ);
		append(bass,Gs,octave-1,0.25,BASSAZ);
		cat();
	add();
	cat();
	//MEASURE # 49
	#ifdef DEBUG
	puts("Measure # 49");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,D,E,B,octave,0.25,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.25,CHORDAZ);
		appendFour(harmony,E,A,B,2*C,octave,0.25,CHORDAZ);
		appendFour(harmony,E,A,B,2*C,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,A/2,E,octave-1,0.25,BASSAZ);
		append(bass,A,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 50
	#ifdef DEBUG
	puts("Measure # 50");
	#endif
		//VOICE
		create(voice,Db,octave+1,0.5,VOICEAZ);
		append(voice,D,octave+1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,Db,A,2*Db,octave+1,0.375,CHORDAZ);
		appendInterval(harmony,Db,2*Db,octave,0.125,CHORDAZ);
		appendChord(harmony,Db,A,2*Db,octave,0.25,CHORDAZ);
		appendInterval(harmony,Db,2*Db,octave,0.125,CHORDAZ);
		appendInterval(harmony,A,2*A,octave,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,F,2*Db,octave-2,0.25,BASSAZ);
		append(bass,A,octave-1,0.25,BASSAZ);
		two(bass,Fs,2*Db,octave-2,0.25,BASSAZ);
		append(bass,A,octave-1,0.25,BASSAZ);
		cat();
	add();
	cat();
	//MEASURE # 51
	#ifdef DEBUG
	puts("Measure # 51");
	#endif
		//VOICE
		two(voice,C,B/2,octave+1,1.0,VOICEAZ);
		//HARMONY
		fourChord(harmony,A,C,2*F,2*A,octave,0.375,CHORDAZ);
		appendInterval(harmony,G,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*D,2*G,octave,0.25,CHORDAZ);
		appendFourChord(harmony,G,B,2*D,2*G,octave-1,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,G,D,octave-2,0.25,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-2,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 52 & 53
	#ifdef DEBUG
	puts("Measure # 52 & 53");
	#endif
		//VOICE
		create(voice,C,octave+1,1.75,VOICEAZ);
		//HARMONY
		silence(0.25);
		fourChordMarcato(harmony,G/2,C,F,G,octave+1,0.375,CHORDAZ); cat();
		fourChordMarcato(harmony,G/2,C,F,G,octave+1,0.0625,CHORDAZ); cat();
		fourChordMarcato(harmony,G/2,C,F,G,octave+1,0.0625,CHORDAZ); cat();
		fourChordMarcato(harmony,G/2,C,F,G,octave+1,0.125,CHORDAZ); cat();
		fourChordMarcato(harmony,G/2,C,F,G,octave+1,0.125,CHORDAZ); cat();
		fourChordMarcato(harmony,G/2,C,F,G,octave+1,0.1875,CHORDAZ); cat();
		fourChordMarcato(harmony,G/2,C,E,G,octave+1,0.0625,CHORDAZ); cat();
		fourChordMarcato(harmony,G/2,C,E,G,octave+1,0.25,CHORDAZ); cat();
		FORTE;
		four(harmony,E,D,C,G/2,octave+1,0.25,CHORDAZ);
		appendFour(harmony,C,D,E,G,octave,0.25,CHORDAZ);
		CRESCENDO;
		cat();
		MESSOFORTE;
	add();
		//BASS
		silence(0.25);
		chordMarcato(bass,G/2,C,F,octave,0.375,BASSAZ);
		appendChordMarcato(bass,G/2,C,F,octave,0.0625,BASSAZ);
		appendChordMarcato(bass,G/2,C,F,octave,0.0625,BASSAZ);
		appendChordMarcato(bass,G/2,C,F,octave,0.125,BASSAZ);
		appendChordMarcato(bass,G/2,C,F,octave,0.125,BASSAZ);
		appendChordMarcato(bass,G/2,C,F,octave,0.1875,BASSAZ);
		appendChordMarcato(bass,G/2,C,E,octave,0.0625,BASSAZ);
		appendChordMarcato(bass,G/2,C,E,octave,0.25,BASSAZ);
		cat();
		interval(bass,C,2*C,octave-2,1.5,BASSAZ);
		FORTE;
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,Bf,2*Bf,octave-3,0.25,BASSAZ);
		CRESCENDO;
		add();
	add();
	cat();
	C = aKey;
	//MEASURE # 54
	#ifdef DEBUG
	puts("Measure # 54");
	#endif
		//VOICE
		create(voice,G,octave,0.75,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		//HARMONY
		fourChord(harmony,G/2,C,E,G,octave+1,0.25,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,D,G,octave,0.25,CHORDAZ);
		appendFourChord(harmony,F,B,2*D,2*F,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,G,2*G,octave-3,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.25,BASSAZ);
		appendInterval(bass,F,2*F,octave-2,0.25,BASSAZ);
		appendInterval(bass,F,2*F,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 55
	#ifdef DEBUG
	puts("Measure # 55");
	#endif
		//VOICE
		four(voice,E,G,2*C,D,octave,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,G/2,C,E,octave+1,0.25,CHORDAZ);
		appendChord(harmony,G/2,C,G,octave+1,0.25,CHORDAZ);
		appendChord(harmony,F,A,2*C,octave+1,0.25,CHORDAZ);
		appendFourChord(harmony,G,G,B,2*D,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,E,2*E,octave-2,0.25,BASSAZ);
		appendInterval(bass,E,2*E,octave-2,0.25,BASSAZ);
		appendInterval(bass,F,2*F,octave-2,0.125,BASSAZ);
		appendInterval(bass,E,2*E,octave-2,0.125,BASSAZ);
		appendInterval(bass,D,2*D,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 56
	#ifdef DEBUG
	puts("Measure # 56");
	#endif
		//VOICE
		create(voice,E,octave,1.0,VOICEAZ);
		//HARMONY
		fourChord(harmony,E,G,2*C,E,octave,0.25,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.375,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.0625,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.0625,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		four(bass,C,C,C,C,octave-1,1.0,BASSAZ);
		addFour(bass,C,C,C,C,octave-2,1.0,BASSAZ);
	add();
	cat();

	//MEASURE # 57
	#ifdef DEBUG
	puts("Measure # 57");
	#endif
		//VOICE
		create(voice,C,octave+1,0.75,VOICEAZ);
		//HARMONY
		chord(harmony,C,F,G,octave+1,0.375,CHORDAZ);
		appendChord(harmony,C,F,G,octave+1,0.125,CHORDAZ);
		appendChord(harmony,C,E,G,octave+1,0.1875,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.0625,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 58
	#ifdef DEBUG
	puts("Measure # 58");
	#endif
		//VOICE
		create(voice,A,octave,0.75,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ);
		//HARMONY
		fourChord(harmony,A/2,C,F,A,octave+1,0.25,CHORDAZ);
		appendFourChord(harmony,C,G,A,2*C,octave,0.25,CHORDAZ);
		appendFourChord(harmony,F,A,2*C,2*F,octave,0.25,CHORDAZ);
		appendInterval(harmony,B/2,B,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 59
	#ifdef DEBUG
	puts("Measure # 59");
	#endif
		//VOICE
		four(voice,A,B/2,A,F,octave+1,1.0,VOICEAZ);
		//HARMONY
		fourChord(harmony,C,F,A,2*C,octave,0.25,CHORDAZ);
		appendInterval(harmony,B/2,B,octave,0.25,CHORDAZ);
		appendFourChord(harmony,C,F,A,2*C,octave,0.25,CHORDAZ);
		appendFourChord(harmony,F,A,2*C,2*F,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 60
	#ifdef DEBUG
	puts("Measure # 60");
	#endif
		//VOICE
		create(voice,E,octave+1,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,G,2*C,2*E,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.125,CHORDAZ);
		appendInterval(harmony,G,2*D,octave,0.125,CHORDAZ);
		appendInterval(harmony,2*C,2*E,octave,0.25,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 61
	#ifdef DEBUG
	puts("Measure # 61");
	#endif
		//VOICE
		create(voice,C,octave+1,0.75,VOICEAZ);
		//HARMONY
		fourChord(harmony,C,E,G,G/2,octave+1,0.75,CHORDAZ);
		appendFourChord(harmony,C,E,G,G/2,octave+1,0.1875,CHORDAZ);
		appendInterval(harmony,G,G/2,octave+1,0.0625,CHORDAZ);
		appendFourChord(harmony,G/2,C,2*F,2*G,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,G,2*G,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		three(bass,C,B/2,A/2,octave-1,0.25,BASSAZ);
		addThree(bass,C,B/2,A/2,octave-2,0.25,BASSAZ);
		cat();
		appendInterval(bass,G,2*G,octave-2,0.25,BASSAZ);
		appendInterval(bass,F,2*F,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 62
	#ifdef DEBUG
	puts("Measure # 62");
	#endif
		//VOICE
		create(voice,G,octave,0.75,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,G,2*C,2*G,octave,0.25,CHORDAZ);
		appendChord(harmony,G/2,C,G,octave,0.25,CHORDAZ);
		appendChord(harmony,C,G,2*C,octave,0.25,CHORDAZ);
		appendFourChord(harmony,F/2,C,D,F,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,E,2*E,octave-3,0.375,BASSAZ);
		appendInterval(bass,E,2*E,octave-2,0.125,BASSAZ);
		appendInterval(bass,E,2*E,octave-2,0.25,BASSAZ);
		appendInterval(bass,E,2*E,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 63
	#ifdef DEBUG
	puts("Measure # 63");
	#endif
		//VOICE
		four(voice,E,G,2*C,2*Db,octave,1.0,VOICEAZ);
		//HARMONY
		fourChord(harmony,E,G,2*C,2*E,octave,0.25,CHORDAZ);
		appendChord(harmony,D,G,2*D,octave,0.25,CHORDAZ);
		appendChord(harmony,E,A,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,Db,A,2*Db,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C/2,C,octave-1,0.25,BASSAZ);
		appendInterval(bass,B/2,B,octave-2,0.25,BASSAZ);
		appendInterval(bass,A/2,A,octave-2,0.125,BASSAZ);
		appendInterval(bass,G/2,G,octave-2,0.125,BASSAZ);
		appendInterval(bass,Db/2,Db,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 64
	#ifdef DEBUG
	puts("Measure # 64");
	#endif
		//VOICE
		create(voice,E,octave+1,1.0,VOICEAZ);
		//HARMONY
		fourChord(harmony,E,Gs,B,2*E,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,Gs,E,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,E,A,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,E,B,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,E,2*E,octave-3,0.375,BASSAZ);
		appendInterval(bass,E,2*E,octave-3,0.125,BASSAZ);
		appendInterval(bass,Fs,2*Fs,octave-3,0.25,BASSAZ);
		appendInterval(bass,Gs,2*Gs,octave-3,0.255,BASSAZ);
	add();
	cat();
	//MEASURE # 65
	#ifdef DEBUG
	puts("Measure # 65");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,B,octave,0.25,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.25,CHORDAZ);
		appendFourChord(harmony,A/2,C,E,A,octave,0.5,CHORDAZ);
	add();
		//BASS
		interval(bass,A,2*A,octave-3,0.375,BASSAZ);
		appendInterval(bass,A,2*A,octave-3,0.125,BASSAZ);
		appendInterval(bass,E,2*E,octave-3,0.25,BASSAZ);
		appendInterval(bass,E,2*E,octave-3,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 66
	#ifdef DEBUG
	puts("Measure # 66");
	#endif
		//VOICE
		create(voice,Db,octave+1,0.5,VOICEAZ);
		append(voice,Db,octave+1,0.5,VOICEAZ);
		//HARMONY
		fourChord(harmony,Db,F,A,2*Db,octave+1,0.25,CHORDAZ);
		appendFourChord(harmony,F/2,Db,F,A,octave,0.25,CHORDAZ);
		appendFourChord(harmony,Db,F,A,2*Db,octave,0.25,CHORDAZ);
		appendFourChord(harmony,Db,F,A,2*Db,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,E,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,F,F*2,octave-3,0.5,BASSAZ);
		appendInterval(bass,Db,Db*2,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 67
	#ifdef DEBUG
	puts("Measure # 67");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		append(voice,B,octave,0.5,VOICEAZ);
		//HARMONY
		fourChord(harmony,F,A,2*C,2*F,octave,0.25,CHORDAZ);
		appendFourChord(harmony,F,A,2*C,2*F,octave-1,0.25,CHORDAZ);
		appendFourChord(harmony,F,A,2*C,2*F,octave,0.25,CHORDAZ);
		appendFourChord(harmony,F,A,2*C,2*F,octave-1,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,G,2*G,octave-3,0.375,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 68 & 69
	#ifdef DEBUG
	puts("Measure # 68 & 69");
	#endif
		//VOICE
		create(voice,C,octave+1,2.0,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendFourChord(harmony,G/2,C,F,G,octave+1,0.375,CHORDAZ);
		appendFourChord(harmony,G/2,C,F,G,octave+1,0.0625,CHORDAZ);
		appendFourChord(harmony,G/2,C,F,G,octave+1,0.0625,CHORDAZ);
		appendFourChord(harmony,G/2,C,F,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,F,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,F,G,octave+1,0.1875,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.0625,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.5,CHORDAZ);
		C=cKey;
		four(harmony,C,D,E,F,octave+1,0.25,CHORDAZ);
		C=aKey;
		CRESCENDO;
		cat();
	add();
		//BASS
		silence(0.25);
		appendChord(bass,G/2,C,F,octave,0.375,BASSAZ);
		appendChord(bass,G/2,C,F,octave,0.0625,BASSAZ);
		appendChord(bass,G/2,C,F,octave,0.0625,BASSAZ);
		appendChord(bass,G/2,C,F,octave,0.125,BASSAZ);
		appendChord(bass,G/2,C,F,octave,0.125,BASSAZ);
		appendChord(bass,G/2,C,F,octave,0.1875,BASSAZ);
		appendChord(bass,G/2,C,F,octave,0.0625,BASSAZ);
		appendChord(bass,G/2,C,E,octave,0.25,BASSAZ);
		interval(bass,C,2*C,octave-2,1.5,BASSAZ);
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		C=cKey;
		appendInterval(bass,G,2*G,octave-3,0.25,BASSAZ);
		CRESCENDO;
		cat();
		add();
	add();
	cat();
	//MEASURE # 70, 71 & 72
	#ifdef DEBUG
	puts("Measure # 70, 71, & 72");
	#endif
		//HARMONY
		fourChord(harmony,G/2,C,E,G,octave+1,0.25,CHORDAZ);
		appendFourChord(harmony,E,G,2*C,2*E,octave,0.375,CHORDAZ);
		appendFourChord(harmony,E,G,2*C,2*E,octave,0.0625,CHORDAZ);
		appendFourChord(harmony,E,G,2*C,2*E,octave,0.0625,CHORDAZ);
		appendFourChord(harmony,E,G,2*C,2*E,octave,0.125,CHORDAZ);
		appendFourChord(harmony,E,G,2*C,2*E,octave,0.125,CHORDAZ);
		appendFourChord(harmony,E,G,2*C,2*E,octave,0.25,CHORDAZ);
		appendFourChord(harmony,D,G,B,2*D,octave,0.25,CHORDAZ);
		appendFourChord(harmony,C,G,A,C,octave,0.25,CHORDAZ);
		appendFourChord(harmony,D,G,B,2*D,octave,0.75,CHORDAZ);
		appendIntervalMarcato(harmony,G,2*G,octave,0.125,CHORDAZ);
		appendIntervalMarcato(harmony,G,2*G,octave,0.125,CHORDAZ);
		appendIntervalMarcato(harmony,G,2*G,octave,0.25,CHORDAZ);
		appendIntervalMarcato(harmony,G,2*G,octave,0.25,CHORDAZ);
		//BASS
		silence(0.25);
		appendInterval(bass,G/2,C,octave,0.375,BASSAZ);
		appendInterval(bass,G/2,C,octave,0.0625,BASSAZ);
		appendInterval(bass,G/2,C,octave,0.0625,BASSAZ);
		appendInterval(bass,G/2,C,octave,0.125,BASSAZ);
		appendInterval(bass,G/2,C,octave,0.125,BASSAZ);
		appendInterval(bass,G/2,C,octave,0.25,BASSAZ);
		interval(bass,G,2*G,octave-3,1.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.0625,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.0625,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.0625,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.0625,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.25,BASSAZ);
		appendIntervalMarcato(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendIntervalMarcato(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendIntervalMarcato(bass,G,2*G,octave-3,0.25,BASSAZ);
		appendIntervalMarcato(bass,G,2*G,octave-3,0.25,BASSAZ);
		add();
	add();
	cat();
	DOUBLEFORTE;
	//MEASURE # 73
	#ifdef DEBUG
	puts("Measure # 73");
	#endif
		//VOICE
		create(voice,G,octave,0.75,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		//HARMONY
		fourChord(harmony,C,E,G,2*C,octave+1,0.25,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave,0.0625,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave,0.0625,CHORDAZ);
		appendChord(harmony,D,G,2*D,octave,0.5,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,B,2*B,octave-3,0.25,BASSAZ);
		four(bass,B,B,B,B,octave-2,0.25,BASSAZ);
		addFour(bass,B,B,B,B,octave-2,0.25,BASSAZ);
		cat();
	add();
	cat();
	//MEASURE # 74
	#ifdef DEBUG
	puts("Measure # 74");
	#endif
		//VOICE
		four(voice,E,G,2*C,2*D,octave,1.0,VOICEAZ);
		//HARMONY
		fourChord(harmony,C,E,2*C,2*E,octave+1,0.25,CHORDAZ);
		appendChord(harmony,D,G,2*D,octave,0.25,CHORDAZ);
		appendChord(harmony,E,A,2*C,octave,0.25,CHORDAZ);
		appendFourChord(harmony,D,G,B,2*D,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,B,2*B,octave-3,0.125,BASSAZ);
		appendInterval(bass,B,2*B,octave-3,0.0625,BASSAZ);
		appendInterval(bass,B,2*B,octave-3,0.0625,BASSAZ);
		appendInterval(bass,A,2*A,octave-3,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 75
	#ifdef DEBUG
	puts("Measure # 75");
	#endif
		//VOICE
		create(voice,E,octave+1,1.0,VOICEAZ);
		//HARMONY
		chordMarcato(harmony,G,2*C,2*E,octave,0.0625,CHORDAZ);
		appendIntervalMarcato(harmony,B,2*D,octave,0.0625,CHORDAZ);
		appendIntervalMarcato(harmony,A,2*C,octave,0.0625,CHORDAZ);
		appendIntervalMarcato(harmony,B,2*D,octave,0.0625,CHORDAZ);
		appendChordMarcato(harmony,G,2*C,2*E,octave,0.375,CHORDAZ);
		appendChordMarcato(harmony,G,B,2*D,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.0625,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.0625,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
	add();
	cat();

	//MEASURE # 76
	#ifdef DEBUG
	puts("Measure # 76");
	#endif
		//VOICE
		create(voice,C,octave+1,0.75,VOICEAZ);
		//HARMONY
		chordMarcato(harmony,G,2*C,2*E,octave,0.125,CHORDAZ);
		appendChordMarcato(harmony,G,2*C,2*E,octave,0.0625,CHORDAZ);
		appendChordMarcato(harmony,G,2*C,2*E,octave,0.0625,CHORDAZ);
		appendChordMarcato(harmony,G,2*C,2*E,octave,0.375,CHORDAZ);
		appendChord(harmony,G,2*C,2*E,octave,0.0625,CHORDAZ);
		appendChord(harmony,G,2*C,2*E,octave,0.0625,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.125,CHORDAZ);
		appendChord(harmony,G,2*C,2*E,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.0625,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.0625,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 77
	#ifdef DEBUG
	puts("Measure # 77");
	#endif
		//VOICE
		create(voice,A,octave,0.75,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,A,2*C,2*F,octave,0.25,CHORDAZ);
		appendChord(harmony,C,F,A,octave,0.125,CHORDAZ);
		appendChord(harmony,C,F,A,octave,0.125/2,CHORDAZ);
		appendChord(harmony,C,F,A,octave,0.125/2,CHORDAZ);
		appendChord(harmony,C,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,C,F,A,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,F,2*F,octave-3,0.25,BASSAZ);
		appendInterval(bass,F,2*F,octave-3,0.25,BASSAZ);
		appendInterval(bass,F,2*F,octave-3,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 78
	#ifdef DEBUG
	puts("Measure # 78");
	#endif
		//VOICE
		four(voice,C,B/2,C,A/2,octave,1.0,VOICEAZ);
		//HARMONY
		fourChord(harmony,C,F,A,2*C,octave,0.25,CHORDAZ);
		appendInterval(harmony,B/2,B,octave,0.25,CHORDAZ);
		appendFourChord(harmony,C,F,A,2*C,octave,0.25,CHORDAZ);
		appendFourChord(harmony,F,A,2*C,2*F,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,Db,2*Db,octave-3,0.375,BASSAZ);
		appendInterval(bass,Db,2*Db,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.0625,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.0625,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 79
	#ifdef DEBUG
	puts("Measure # 79");
	#endif
		//VOICE
		two(voice,G,2*C,octave,1.0,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendChordMarcato(harmony,G,2*C,2*E,octave,0.0625,CHORDAZ);
		appendIntervalMarcato(harmony,B,2*D,octave,0.0625,CHORDAZ);
		appendIntervalMarcato(harmony,A,2*C,octave,0.0625,CHORDAZ);
		appendIntervalMarcato(harmony,B,2*D,octave,0.0625,CHORDAZ);
		appendChordMarcato(harmony,G,2*C,2*E,octave,0.375,CHORDAZ);
		appendChordMarcato(harmony,G,2*C,2*E,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,G,2*G,octave-3,0.375,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.0625,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.0625,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 80
	#ifdef DEBUG
	puts("Measure # 80");
	#endif
		//VOICE
		create(voice,G,octave,0.75,VOICEAZ);
		//HARMONY
		chordMarcato(harmony,G,B,2*D,octave,0.375,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.0625,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.0625,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.125,CHORDAZ);
		appendChord(harmony,G,B,2*D,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*D,2*G,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*D,2*G,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,G,2*G,octave-3,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125/2,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125/2,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 81
	#ifdef DEBUG
	puts("Measure # 81");
	#endif
		//VOICE
		create(voice,G,octave,0.75,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,G,2*G,octave,0.25,CHORDAZ);
		appendChord(harmony,D,G,2*D,octave,0.125,CHORDAZ);
		appendChord(harmony,D,G,2*D,octave,0.125/2,CHORDAZ);
		appendChord(harmony,D,G,2*D,octave,0.125/2,CHORDAZ);
		appendChord(harmony,D,G,2*D,octave,0.25,CHORDAZ);
		appendChord(harmony,D,G,2*D,octave-1,0.25,CHORDAZ);
	add();
		//BASS
		silence(0.25);
		appendInterval(bass,B,2*B,octave-3,0.125,BASSAZ);
		appendInterval(bass,B,2*B,octave-3,0.125/2,BASSAZ);
		appendInterval(bass,B,2*B,octave-3,0.125/2,BASSAZ);
		appendInterval(bass,B,2*B,octave-3,0.375,BASSAZ);
		appendInterval(bass,B,2*B,octave-3,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 82
	#ifdef DEBUG
	puts("Measure # 82");
	#endif
		//VOICE
		four(voice,E,G,2*C,2*Db,octave,1.0,VOICEAZ);
		//HARMONY
		fourChord(harmony,E,G,2*C,2*E,octave,0.25,CHORDAZ);
		appendChord(harmony,D,G,2*D,octave,0.25,CHORDAZ);
		appendFourChord(harmony,C,E,A,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,Db,A,2*Db,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,B,2*B,octave-3,0.25,BASSAZ);
		appendInterval(bass,A,2*A,octave-3,0.25,BASSAZ);
		appendInterval(bass,F,2*F,octave-3,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 83
	#ifdef DEBUG
	puts("Measure # 83");
	#endif
		//VOICE
		create(voice,E,octave+1,1.0,VOICEAZ);
		//HARMONY
		fourChord(harmony,E,Gs,B,2*E,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,2*E,octave,0.0625,CHORDAZ);
		appendInterval(harmony,E,2*E,octave,0.0625,CHORDAZ);
		appendChord(harmony,E,A,E,octave-1,0.25,CHORDAZ);
		appendChord(harmony,E,A,E,octave-1,0.25,CHORDAZ);
	add();
		//BASS
		four(bass,E,E,Fs,Gs,octave-2,1.0,BASSAZ);
		addFour(bass,E,E,Fs,Gs,octave-3,1.0,BASSAZ);
	add();
	cat();
	//MEASURE # 84
	#ifdef DEBUG
	puts("Measure # 84");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		appendSilence(0.25);
		append(voice,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		fourChord(harmony,E/2,A/2,C,E,octave,0.25,CHORDAZ);
		appendChord(harmony,E,A,2*C,octave,0.25,CHORDAZ);
		appendFourChord(harmony,E,A,2*C,2*E,octave,0.5,CHORDAZ);
	add();
		//BASS
		interval(bass,A,2*A,octave-3,0.375,BASSAZ);
		appendInterval(bass,A,2*A,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.0625,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.0625,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 85
	#ifdef DEBUG
	puts("Measure # 85");
	#endif
		//VOICE
		two(voice,Db,Db,octave+1,1.0,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendFourChordMarcato(harmony,Db,F,A,2*Db,octave,0.25,CHORDAZ);
		appendSilence(0.25);
		appendFourChordMarcato(harmony,F,A,2*Db,2*F,octave,0.25,CHORDAZ);
	add();
		//BASS
		silence(0.25);
		appendInterval(bass,F,2*F,octave-3,0.25,BASSAZ);
		appendSilence(0.25);
		appendIntervalMarcato(bass,Db,2*Db,octave-3,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 86
	#ifdef DEBUG
	puts("Measure # 86");
	#endif
		//VOICE
		two(voice,C,B/2,octave+1,1.0,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendFourChord(harmony,F,A,2*C,2*F,octave,0.25,CHORDAZ);
		appendFourChord(harmony,G,B,2*D,2*G,octave,0.5,CHORDAZ);
	add();
		//BASS
		silence(0.25);
		appendInterval(bass,G,2*G,octave-3,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.5,BASSAZ);
	add();
	cat();

	//MEASURE # 87
	#ifdef DEBUG
	puts("Measure # 87");
	#endif
		//VOICE
		create(voice,C,octave+1,1.0,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendChord(harmony,Ef,Af,2*C,octave,0.25,CHORDAZ);
		appendFourChord(harmony,Ef,Af,2*C,Ef,octave,0.375,CHORDAZ);
		appendFourChord(harmony,Ef,Af,2*C,Ef,octave,0.125,CHORDAZ);
	add();
		//BASS
		silence(0.25);
		six(bass,Af,G,F,Ef,D,C,octave-1,0.75,BASSAZ);
		addSix(bass,Af,G,F,Ef,D,C,octave-2,0.75,BASSAZ);
		cat();
	add();
	cat();
	//MEASURE # 88
	#ifdef DEBUG
	puts("Measure # 88");
	#endif
		//VOICE
		silence(0.25);
		appendThree(voice,Db,Db,Db,octave+1,0.75,VOICEAZ);
		//HARMONY
		fourChord(harmony,Db,F,Bf,2*Db,octave,0.25,CHORDAZ);
		appendFourChord(harmony,Bf/2,Db,F,Bf,octave,0.25,CHORDAZ);
		appendFourChord(harmony,Db,F,Bf,2*Db,octave,0.25,CHORDAZ);
		appendFourChord(harmony,F,Bf,2*Db,2*F,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,Bf,2*Bf,octave-3,1.0,BASSAZ);
	add();
	gradual(1.0,12.0/10);
	cat();
	FORTISSIMO;

	//MEASURE # 89, 90 & 91
	#ifdef DEBUG
	puts("Measure # 89, 90 & 91");
	#endif
		//VOICE
		create(voice,E,octave+1,3.0,VOICEAZ);
		//HARMONY
		interval(harmony,C,2*C,octave+1,0.25,CHORDAZ);
		appendFourChord(harmony,C,E,G,2*C,octave,0.25,CHORDAZ);
		appendFourChord(harmony,Df,Gf,Bf,2*Df,octave,0.5,CHORDAZ);
		appendFourChord(harmony,Ef,Af,C,2*Ef,octave,0.25,CHORDAZ);
		appendFourChord(harmony,F,Bf,2*Db,2*F,octave,0.5,CHORDAZ);
		appendFourChord(harmony,Ef,Af,C,2*Ef,octave,0.125,CHORDAZ);
		appendFourChord(harmony,F,Bf,2*Db,2*F,octave,0.125,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,1.0,CHORDAZ);
	add();
		//BASS
		silence(0.25);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendInterval(bass,C,2*C,octave-3,1.0,BASSAZ);
	add();
	cat();
	//MEASURE # 92
	#ifdef DEBUG
	puts("Measure # 92");
	#endif
		//HARMONY
		intervalMarcato(harmony,C,2*C,octave-1,0.125,CHORDAZ);
		intervalMarcato(harmony,C,2*C,octave-1,0.125,CHORDAZ); cat();
		intervalMarcato(harmony,C,2*C,octave-1,0.25,CHORDAZ); cat();
		//BASS
		intervalMarcato(harmony,C,2*C,octave-3,0.125,CHORDAZ);
		intervalMarcato(harmony,C,2*C,octave-3,0.125,CHORDAZ); cat();
		intervalMarcato(harmony,C,2*C,octave-3,0.25,CHORDAZ); cat();
	add();
	cat();
}




int main(int argc, char** argv){


	eKey=E;
	fKey=F/2;
	gFlatKey=Gf/2;
	gKey=G/2;
	aKey=A/2;
	cKey=C;
	tempo=108;

	song();
	echo(10,0.35,5);
	puts("battle hymn of the republic.wav");
	exportToWav("battle hymn of the republic.wav");

}


