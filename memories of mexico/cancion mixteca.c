#include "soundlib.h"

#define VOICEAZ 150
#define CHORDAZ 30
#define BASSAZ 90

#define DEBUG 1


double (*voice)(double) = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double) = oldCircleOfRa;


short octave = 0;

void song(void);
void intro(void);
void chorus(short);

void song(void){
	intro();
	chorus(0);
	cat();
	chorus(1);
	cat();
}


void intro(void){
	MESSOFORTE;
	//MEASURE # 1
	#ifdef DEBUG
	puts("Measure # 1");
	#endif
		//HARMONY
		silence(0.125);
		appendChordMarcato(harmony,C,Ef,A,octave,0.125,CHORDAZ);
		appendChordEstacato(harmony,C,E,G,octave,0.125,CHORDAZ);
		//BASS
		create(bass,C,octave-1,0.125,BASSAZ);
		appendMarcato(bass,Gf,octave-1,0.125,BASSAZ);
		append(bass,G,octave-1,0.125,BASSAZ);
	add();
	//MEASURE # 2
	#ifdef DEBUG
	puts("Measure # 2");
	#endif
		//HARMONY
		silence(0.125);
		appendChord(harmony,B,F,G,octave,0.125,CHORDAZ);
		//BASS
		three(bass,G/2,G,G/2,octave-1,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 3
	#ifdef DEBUG
	puts("Measure # 3");
	#endif
		//HARMONY
		silence(0.125);
		appendChordMarcato(harmony,C,Ef,A,octave,0.125,CHORDAZ);
		appendChordEstacato(harmony,C,E,G,octave,0.125,CHORDAZ);
		//BASS
		create(bass,C,octave-1,0.125,BASSAZ);
		appendMarcato(bass,Gf,octave-1,0.125,BASSAZ);
		append(bass,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 4
	#ifdef DEBUG
	puts("Measure # 4");
	#endif
		//VOICE
		silence(0.25);
		PIANO;
		append(voice,G,octave,0.125,VOICEAZ);
		MESSOFORTE;
		//HARMONY
		silence(0.125);
		appendChord(harmony,B/2,G,F,octave,0.125,CHORDAZ);
		PIANO;
		append(harmony,G,octave,0.125,CHORDAZ);
		MESSOFORTE;
	add();
		//BASS
		three(bass,G,2*G,0,octave-2,0.375,BASSAZ);
		PIANO;
	add();
	cat();

	//MEASURE # 5
	#ifdef DEBUG
	puts("Measure # 5");
	#endif
		//VOICE
		three(voice,C,C,C,octave+1,0.375,VOICEAZ);
		//HARMONY
		three(harmony,C,C,C,octave+1,0.375,CHORDAZ);
		addInterval(harmony,E,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		three(bass,C,G,2*C,octave-2,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 6
	#ifdef DEBUG
	puts("Measure # 6");
	#endif
		//VOICE
		create(voice,C,octave+1,0.25,VOICEAZ);
		append(voice,B,octave,0.125,VOICEAZ);
		//HARMONY
		create(harmony,C,octave+1,0.25,CHORDAZ);
		append(harmony,B,octave,0.125,CHORDAZ);
		addInterval(harmony,E,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		three(bass,E,G,2*C,octave-1,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 7
	#ifdef DEBUG
	puts("Measure # 7");
	#endif
		//VOICE
		three(voice,A,A,G,octave,0.375,VOICEAZ);
		//HARMONY
		three(harmony,A,A,G,octave,0.375,CHORDAZ);
		interval(harmony,C,E,octave,0.375,CHORDAZ);
		add();
	add();
		//BASS
		two(bass,C,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 8
	#ifdef DEBUG
	puts("Measure # 8");
	#endif
		//VOICE
		create(voice,A,octave,0.25,VOICEAZ);
		append(voice,C,octave+1,0.125,VOICEAZ);
		//HARMONY
		create(harmony,A,octave,0.25,CHORDAZ);
		append(harmony,C,octave+1,0.125,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		two(bass,G,2*G,octave-2,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 9
	#ifdef DEBUG
	puts("Measure # 9");
	#endif
		//VOICE
		create(voice,B,octave,0.375,VOICEAZ);
		//HARMONY
		create(harmony,B,octave,0.375,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,D,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,D,F,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 10
	#ifdef DEBUG
	puts("Measure # 10");
	#endif
		//VOICE
		create(voice,F,octave,0.375,VOICEAZ);
		//HARMONY
		create(harmony,F,octave,0.375,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,B,2*D,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,B,2*D,octave-1,0.125,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 11
	#ifdef DEBUG
	puts("Measure # 11");
	#endif
		//HARMONY
		chord(harmony,Db,F,B,octave+1,0.375,CHORDAZ);
		//BASS
		create(bass,D,octave-1,0.125,BASSAZ);
		appendMarcato(bass,Gf,octave-1,0.125,BASSAZ);
		append(bass,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 12
	#ifdef DEBUG
	puts("Measure # 12");
	#endif
		//VOICE
		silence(0.25);
		append(voice,G,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,G,B,2*F,octave,0.25,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,G,2*G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 13
	#ifdef DEBUG
	puts("Measure # 13");
	#endif
		//VOICE
		three(voice,B,B,B,octave,0.375,VOICEAZ);
		//HARMONY
		three(harmony,B,B,B,octave,0.375,CHORDAZ);
		addThree(harmony,G,G,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		interval(bass,D,2*D,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 14
	#ifdef DEBUG
	puts("Measure # 14");
	#endif
		//VOICE
		create(voice,B,octave,0.25,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,G,B,octave,0.25,CHORDAZ);
		appendInterval(harmony,F,A,octave,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,G,2*G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 15
	#ifdef DEBUG
	puts("Measure # 15");
	#endif
		//VOICE
		three(voice,A,G,F,octave,0.375,VOICEAZ);
		//HARMONY
		three(harmony,A,G,F,octave,0.375,CHORDAZ);
		addThree(harmony,F,E,Db,octave,0.375,CHORDAZ);
	add();
		//BASS
		create(bass,D,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 16
	#ifdef DEBUG
	puts("Measure # 16");
	#endif
		//VOICE
		create(voice,G,octave,0.25,VOICEAZ);
		append(voice,F,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave,0.25,CHORDAZ);
		appendInterval(harmony,Db,F,octave,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,G,2*G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 17
	#ifdef DEBUG
	puts("Measure # 17");
	#endif
		//VOICE
		create(voice,A,octave,0.375,VOICEAZ);
		//HARMONY
		create(harmony,A,octave,0.375,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-1,0.25,BASSAZ);
	add();
	cat();


	//MEASURE # 18
	#ifdef DEBUG
	puts("Measure # 18");
	#endif
		//VOICE
		create(voice,E,octave,0.375,VOICEAZ);
		//HARMONY
		create(harmony,E,octave,0.375,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,G,2*C,octave-1,0.125,CHORDAZ);
		appendInterval(harmony,G,2*C,octave-1,0.125,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 19 & 20
	#ifdef DEBUG
	puts("Measure # 19 & 20");
	#endif
		//VOICE
		silence(0.625);
		append(voice,G,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,C,A,octave+1,0.375,CHORDAZ);
		appendInterval(harmony,C,E,octave+1,0.25,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-1,0.125,BASSAZ);
		appendMarcato(bass,Gf,octave-1,0.125,BASSAZ);
		append(bass,G,octave-1,0.125,BASSAZ);
		appendTwo(bass,G,2*G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 21
	#ifdef DEBUG
	puts("Measure # 21");
	#endif
		//VOICE
		three(voice,E,E,E,octave+1,0.375,VOICEAZ);
		//HARMONY
		three(harmony,E,E,E,octave+1,0.375,CHORDAZ);
		addThree(harmony,G,G,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		three(bass,C,G,G,octave-1,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 22
	#ifdef DEBUG
	puts("Measure # 22");
	#endif
		//VOICE
		create(voice,E,octave+1,0.25,VOICEAZ);
		append(voice,D,octave+1,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,G,2*E,octave,0.25,CHORDAZ);
		appendChord(harmony,E,Bf,D,octave,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,G,2*G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 23
	#ifdef DEBUG
	puts("Measure # 23");
	#endif
		//VOICE
		three(voice,C,C,Bf/2,octave+1,0.375,VOICEAZ);
		//HARMONY
		chord(harmony,E,A,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,E,A,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,E,A,Bf,octave,0.125,CHORDAZ);
	add();
		//BASS
		three(bass,C,G,G,octave-1,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 24
	#ifdef DEBUG
	puts("Measure # 24");
	#endif
		//VOICE
		create(voice,C,octave+1,0.25,VOICEAZ);
		append(voice,Bf,octave,0.125,VOICEAZ);
		//HARMONY
		create(harmony,C,octave+1,0.25,CHORDAZ);
		append(harmony,Bf,octave,0.125,CHORDAZ);
		interval(harmony,E,G,octave,0.375,CHORDAZ);
		add();
	add();
		//BASS
		two(bass,C,C/2,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 25
	#ifdef DEBUG
	puts("Measure # 25");
	#endif
		//VOICE
		create(voice,Db,octave+1,0.375,VOICEAZ);
		//HARMONY
		create(harmony,Db,octave+1,0.375,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,F,A,octave,0.125,CHORDAZ);
		appendInterval(harmony,F,A,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,F,2*F,octave,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 26 & 27
	#ifdef DEBUG
	puts("Measure # 26 & 27");
	#endif
		//VOICE
		create(voice,A,octave,0.5,VOICEAZ);
		appendSilence(0.125);
		append(voice,A,octave,0.125,VOICEAZ);
		//HARMONY
		create(harmony,A,octave,0.5,CHORDAZ);
		appendSilence(0.125);
		append(harmony,A,octave,0.125,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,C,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,F,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendInterval(harmony,C,F,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-1,0.125,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,F,2*F,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 28
	#ifdef DEBUG
	puts("Measure # 28");
	#endif
		//VOICE
		three(voice,D,C,A/2,octave+1,0.375,VOICEAZ);
		//HARMONY
		three(harmony,D,C,A/2,octave+1,0.375,CHORDAZ);
		addInterval(harmony,Ef,A,octave,0.375,CHORDAZ);
	add();
		//BASS
		interval(bass,Gf,2*Gf,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 29
	#ifdef DEBUG
	puts("Measure # 29");
	#endif
		//VOICE
		create(voice,G,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.125,CHORDAZ);
	add();
		//BASS
		three(bass,G,2*G,0,octave-2,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 30
	#ifdef DEBUG
	puts("Measure # 30");
	#endif
		//VOICE
		three(voice,G,B,A,octave,0.375,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave,0.125,CHORDAZ);
		appendTwo(harmony,B,A,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,Cs,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 31
	#ifdef DEBUG
	puts("Measure # 31");
	#endif
		//VOICE
		create(voice,G,octave,0.25,VOICEAZ);
		append(voice,Db,octave,0.125,VOICEAZ);
		//HARMONY
		create(harmony,G,octave,0.25,CHORDAZ);
		append(harmony,Db,octave,0.125,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,B,2*F,octave-1,0.25,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,D,octave-1,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 32
	#ifdef DEBUG
	puts("Measure # 32");
	#endif
		//VOICE
		create(voice,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		//HARMONY
		create(harmony,F,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.125,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,G,B,octave-1,0.25,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 33
	#ifdef DEBUG
	puts("Measure # 33");
	#endif
		//VOICE
		create(voice,D,octave,0.375,VOICEAZ);
		//HARMONY
		chord(harmony,F,B,2*D,octave-1,0.375,CHORDAZ);
	add();
		//BASS
		three(bass,C,Gf,G,octave-2,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 34
	#ifdef DEBUG
	puts("Measure # 34");
	#endif
		//VOICE
		create(voice,C,octave,0.375,VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave-1,0.375,CHORDAZ);
	add();
		//BASS
		three(bass,C,B/2,A/2,octave-1,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 35
	#ifdef DEBUG
	puts("Measure # 35");
	#endif
		//VOICE
		silence(0.25);
		append(voice,G,octave,0.125,VOICEAZ);
		//HARMONY
		silence(0.25);
		append(harmony,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,G,2*G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 36
	#ifdef DEBUG
	puts("Measure # 36");
	#endif
		//VOICE
		three(voice,B,B,2*D,octave,0.375,VOICEAZ);
		//HARMONY
		three(harmony,B,B,2*D,octave,0.375,CHORDAZ);
		interval(harmony,D,F,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,F,2*F,octave-2,0.125,BASSAZ);
	add();
	cat();

}

void chorus(short end){
	//MEASURE # 37, 38 & 39
	#ifdef DEBUG
	puts("Measure # 37, 38 & 39");
	#endif
		//VOICE
		create(voice,G,octave+1,1.0,VOICEAZ);
		append(voice,C,octave,0.125,VOICEAZ);
		//HARMONY
		fourChord(harmony,G,B,2*D,2*G,octave,1.0,CHORDAZ);
		appendInterval(harmony,A,C,octave,0.125,CHORDAZ);
	add();
		//BASS
		arpegio(bass,G,2*D,2*B,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-1,0.125,BASSAZ);
		append(bass,B,octave-1,0.125,BASSAZ);
		append(bass,D,octave,0.125,BASSAZ);
		appendTwo(bass,G,G/2,octave-1,0.25,BASSAZ);
	add();
	//MEASURE # 40
	#ifdef DEBUG
	puts("Measure # 40");
	#endif
		//VOICE
		three(voice,2*C,B,A,octave,0.375,VOICEAZ);
		//HARMONY
		three(harmony,2*C,B,A,octave,0.375,CHORDAZ);
		addThree(harmony,A,G,F,octave,0.375,CHORDAZ);
	add();
		//BASS
		three(bass,D,G,G/2,octave-1,0.375,BASSAZ);
	add();
	cat();

	//MEASURE # 41
	#ifdef DEBUG
	puts("Measure # 41");
	#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		three(bass,C,E,G,octave-1,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 42
	#ifdef DEBUG
	puts("Measure # 42");
	#endif
		//VOICE
		create(voice,E,octave,0.375,VOICEAZ);
		//HARMONY
		create(harmony,E,octave,0.375,CHORDAZ);
	add();
		//BASS
		three(bass,C,B/2,A/2,octave,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 43
	#ifdef DEBUG
	puts("Measure # 43");
	#endif
		//VOICE
		silence(0.25);
		append(voice,G,octave,0.125,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendInterval(harmony,E,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		three(bass,G,E,C,octave-1,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 44
	#ifdef DEBUG
	puts("Measure # 44");
	#endif
		//VOICE
		three(voice,B,B,2*D,octave,0.375,VOICEAZ);
		//HARMONY
		three(harmony,B,B,2*D,octave,0.375,CHORDAZ);
		interval(harmony,Db,F,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 45, 46 & 47
	#ifdef DEBUG
	puts("Measure # 45, 46 & 47");
	#endif
		//VOICE
		create(voice,G,octave+1,0.125,VOICEAZ);
		append(voice,F,octave+1,0.875,VOICEAZ);
		append(voice,C,octave+1,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,B,2*E,2*G,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,A,2*F,octave,0.875,CHORDAZ);
		appendInterval(harmony,A,2*C,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-1,0.125,BASSAZ);
		appendThree(bass,B,B,2*Db,octave,0.375,BASSAZ);
		append(bass,G,octave,0.125,BASSAZ);
		append(bass,F,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 48
	#ifdef DEBUG
	puts("Measure # 48");
	#endif
		//VOICE
		three(voice,C,B/2,A/2,octave,0.375,VOICEAZ);
		//HARMONY
		three(harmony,C,B/2,A/2,octave,0.375,CHORDAZ);
		addThree(harmony,A,G,F,octave,0.375,CHORDAZ);
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave,0.125,BASSAZ);
	add();
	cat();

	//MEASURE # 49, 50 & 51
	#ifdef DEBUG
	puts("Measure # 49, 50 & 51");
	#endif
		//VOICE
		three(voice,B,A,G,octave,0.375,VOICEAZ);
		append(voice,E,octave,0.625,VOICEAZ);
		//HARMONY
		three(harmony,B,A,G,octave,0.375,CHORDAZ);
		addThree(harmony,G,F,E,octave,0.375,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.625,CHORDAZ);
	add();
		//BASS
		silence(0.125);
		appendTwo(bass,F,A,octave-1,0.25,BASSAZ);
		appendThree(bass,B,A,G,octave-1,0.375,BASSAZ);
		appendThree(bass,E,D,C,octave-1,0.375,BASSAZ);
		create(bass,C,octave-1,0.75,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 52
	#ifdef DEBUG
	puts("Measure # 52");
	#endif
		//VOICE
		silence(0.25);
		append(voice,G,octave,0.125,VOICEAZ);
		//HARMONY
		silence(0.25);
		append(harmony,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		three(bass,B,A,G,octave-2,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 53
	#ifdef DEBUG
	puts("Measure # 53");
	#endif
		//VOICE
		three(voice,E,E,E,octave+1,0.375,VOICEAZ);
		//HARMONY
		three(harmony,E,E,E,octave+1,0.375,CHORDAZ);
		addThree(harmony,G,G,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		three(bass,C,G,G,octave-1,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 54
	#ifdef DEBUG
	puts("Measure # 54");
	#endif
		//VOICE
		create(voice,E,octave+1,0.25,VOICEAZ);
		append(voice,D,octave+1,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,G,2*E,octave,0.25,CHORDAZ);
		appendChord(harmony,E,Bf,2*D,octave,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,G,2*G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 55 & 56
	#ifdef DEBUG
	puts("Measure # 55 & 56");
	#endif
		//VOICE
		three(voice,C,C,Bf/2,octave+1,0.375,VOICEAZ);
		append(voice,C,octave+1,0.25,VOICEAZ);
		append(voice,Bf,octave,0.125,VOICEAZ);
		//HARMONY
		three(harmony,C,C,Bf/2,octave+1,0.375,CHORDAZ);
		addThree(harmony,A,A,G,octave,0.375,CHORDAZ);
		appendInterval(harmony,A,2*C,octave,0.25,CHORDAZ);
		appendInterval(harmony,G,2*Bf,octave,0.125,CHORDAZ);
		create(harmony,E,octave,0.625,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,C,2*C,octave,0.125,BASSAZ);
		appendSilence(0.25);
		appendTwo(bass,E,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 57
	#ifdef DEBUG
	puts("Measure # 57");
	#endif
		//VOICE
		create(voice,Db,octave+1,0.375,VOICEAZ);
		//HARMONY
		create(harmony,Db,octave+1,0.375,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,F,A,octave,0.125,CHORDAZ);
		appendInterval(harmony,F,A,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,F,2*F,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 58 & 59
	#ifdef DEBUG
	puts("Measure # 58 & 59");
	#endif
		//VOICE
		create(voice,A,octave,0.5,VOICEAZ);
		appendSilence(0.125);
		append(voice,A,octave,0.125,VOICEAZ);
		//HARMONY
		create(harmony,A,octave,0.5,CHORDAZ);
		appendSilence(0.125);
		append(harmony,A,octave,0.125,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,C,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,F,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-1,0.125,BASSAZ);
		appendSilence(0.25);
		appendTwo(bass,F,2*F,octave-2,0.25,BASSAZ);
	add();
	cat();
	if(!end){
	//MEASURE # 60
	#ifdef DEBUG
	puts("Measure # 60");
	#endif
		//VOICE
		three(voice,D,C,A/2,octave+1,0.375,VOICEAZ);
		//HARMONY
		three(harmony,Db,C,A/2,octave+1,0.375,CHORDAZ);
		addThree(harmony,F,E,C,octave+1,0.375,CHORDAZ);
		interval(harmony,Ef,A,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,Gf,2*Gf,octave-2,0.125,BASSAZ);
	add();
	cat();
	}else{
	#ifdef DEBUG
	puts("Measure # 60");
	#endif
		//VOICE
		create(voice,D,octave+1,0.1875,VOICEAZ);
		append(voice,C,octave+1,0.0625,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		//HARMONY
		create(harmony,D,octave+1,0.1875,CHORDAZ);
		append(harmony,C,octave+1,0.0625,CHORDAZ);
		append(harmony,A,octave,0.125,CHORDAZ);
		addThree(harmony,F,E,C,octave+1,0.375,CHORDAZ);
		interval(harmony,Ef,A,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,Gf,2*Gf,octave-2,0.125,BASSAZ);
	add();
	cat();
	}
	//MEASURE # 61
	#ifdef DEBUG
	puts("Measure # 61");
	#endif
		//VOICE
		create(voice,G,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,E,G,octave,0.25,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,G,G/2,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 62
	#ifdef DEBUG
	puts("Measure # 62");
	#endif
		//VOICE
		three(voice,G,B,A,octave,0.375,VOICEAZ);
		//HARMONY
		three(harmony,G,B,A,octave,0.375,CHORDAZ);
		create(harmony,E,octave,0.375,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,Cs,2*Cs,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 63
	#ifdef DEBUG
	puts("Measure # 63");
	#endif
		//VOICE
		create(voice,G,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		//HARMONY
		create(harmony,G,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.125,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,F,B/2,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,D,D/2,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 64
	#ifdef DEBUG
	puts("Measure # 64");
	#endif
		//VOICE
		create(voice,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		//HARMONY
		create(harmony,F,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.125,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,G,B,octave-1,0.125,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 65
	#ifdef DEBUG
	puts("Measure # 65");
	#endif
		//VOICE
		create(voice,D,octave,0.375,VOICEAZ);
		//HARMONY
		create(harmony,D,octave,0.375,CHORDAZ);
		addThree(harmony,B,B,B,octave,0.375,CHORDAZ);
		addThree(harmony,F,F,F,octave,0.375,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	if(!end){
	//MEASURE # 66
	#ifdef DEBUG
	puts("Measure # 66");
	#endif
		//VOICE
		create(voice,C,octave,0.375,VOICEAZ);
		//HARMONY
		chord(harmony,C,G/2,E/2,octave,0.375,CHORDAZ);
	add();
		//BASS
		three(bass,2*C,A,Af,octave-2,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 67
	#ifdef DEBUG
	puts("Measure # 67");
	#endif
		//VOICE
		silence(0.25);
		append(voice,G,octave,0.125,VOICEAZ);
		//HARMONY
		silence(0.25);
		append(harmony,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		two(bass,G,2*G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 68
	#ifdef DEBUG
	puts("Measure # 68");
	#endif
		//VOICE
		three(voice,B,B,2*D,octave,0.375,VOICEAZ);
		//HARMONY
		three(harmony,B,B,2*D,octave,0.375,CHORDAZ);
		addInterval(harmony,Db,F,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,G,2*G,octave,0.375,BASSAZ);
	add();
	cat();
	}else{
	//MEASURE # 69 & 70
	#ifdef DEBUG
	puts("Measure # 69 & 70");
	#endif
		//VOICE
		create(voice,C,octave,0.375,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChordMarcato(harmony,B/2,G,F,octave,0.125,CHORDAZ);
		appendFourChordMarcato(harmony,C,E,G,2*C,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendChordMartelato(bass,C,G,2*E,octave-2,0.125,BASSAZ);
	add();
	cat();
	}
}

int main(int argc, char **argv){
	tempo=75;
	C=Bf/2;
	song();
	echo(10,0.3,4);
    appendSilence(2);
	puts("Writing wav file: cancion mixteca.wav");
	exportToWav("Canción Mixteca.wav");
}
