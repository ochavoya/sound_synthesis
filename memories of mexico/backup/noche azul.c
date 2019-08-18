#include "soundlib.h"

#define VOICEAZ 150
#define CHORDAZ 30
#define BASSAZ 90

#define DEBUG 1


double (*voice)(double) = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double) = oldCircleOfRa;

double aFlatKey,fKey;

short octave = 0;

void intro(void){
	FORTE;
	C=aFlatKey;
	//MEASURE # 1
	#ifdef DEBUG
	puts("Measure # 1");
	#endif
		//HARMONY
		chordMartelato(harmony,A,2*C,2*E,octave,0.25,CHORDAZ);
		appendFour(harmony,E,A,G,E,octave+1,0.5,CHORDAZ);
		//BASS
		chordMartelato(bass,A/2,C,E,octave,0.25,BASSAZ);
		appendFour(bass,E,A,G,E,octave,0.5,BASSAZ);
	add();
	//MEASURE # 2
	#ifdef DEBUG
	puts("Measure # 2");
	#endif
		//HARMONY
		chordMartelato(harmony,A,2*Db,2*F,octave,0.25,CHORDAZ);
		//BASS
		chordMartelato(bass,A/2,Db,F,octave,0.25,BASSAZ);
		appendIntervalMarcato(bass,Db,2*Db,octave-1,0.25,BASSAZ);
		appendEstacato(bass,A,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
	add();
	cat();
	//MEASURE # 3
	#ifdef DEBUG
	puts("Measure # 3");
	#endif
		//HARMONY
		chordMartelato(harmony,E,Gs,B,octave,0.25,CHORDAZ);
		appendFour(harmony,B/2,E,D,B/2,octave,0.5,CHORDAZ);
		//BASS
		chordMartelato(bass,E/2,B,D,octave,0.25,BASSAZ);
		appendFour(bass,B/2,E,D,B/2,octave,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 4
	#ifdef DEBUG
	puts("Measure # 4");
	#endif
		//HARMONY
		chordMartelato(harmony,E,A,2*C,octave,0.25,CHORDAZ);
		//BASS
		intervalMartelato(bass,A/2,C,octave,0.25,BASSAZ);
		appendIntervalMarcato(bass,A,2*A,octave-2,0.25,BASSAZ);
		appendMarcato(bass,E,octave-1,0.25,CHORDAZ);
	add();
	cat();
	//MEASURE # 5
	#ifdef DEBUG
	puts("Measure # 5");
	#endif
		//HARMONY
		chordMartelato(harmony,Ef,G,Bf,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendFour(harmony,Bf,2*E,Bf,G,octave,0.5,CHORDAZ);
		//BASS
		intervalMartelato(bass,Ef,2*Ef,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendFour(bass,Bf,2*E,Bf,G,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 6
	#ifdef DEBUG
	puts("Measure # 6");
	#endif
		//HARMONY
		chordMartelato(harmony,Db,F,A,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendFour(harmony,A,2*Db,A,F,octave,0.5,CHORDAZ);
		//BASS
		intervalMartelato(bass,Db,2*Db,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendFour(bass,A,2*Db,A,F,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 7 & 8
	#ifdef DEBUG
	puts("Measure # 7 & 8");
	#endif
		//HARMONY
		create(harmony,G,octave,0.75+FERMATA(0.75),CHORDAZ);
		silence(0.25);
		appendInterval(harmony,D,F,octave,0.25,CHORDAZ);
		appendInterval(harmony,D,E,octave,0.25,CHORDAZ);
		appendSilence(0.25);
		appendInterval(harmony,D,E,octave,FERMATA(0.75)-0.25,CHORDAZ);
		add();
		//BASS
		interval(bass,E,2*E,octave-2,0.75,BASSAZ);
		appendInterval(bass,E,2*E,octave-2,FERMATA(0.75),BASSAZ);
		DECRESCENDO;
	add();
	cat();
	PIANO;
	//MEASURE # 9
	#ifdef DEBUG
	puts("Measure # 9");
	#endif
		//VOICE
		create(voice,A,octave,0.75,VOICEAZ);
		//HARMONY
		create(harmony,A,octave,0.75,CHORDAZ);
		silence(0.25);
		appendIntervalMartelato(harmony,C,E,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,C,2*C,octave-1,0.5,BASSAZ);
		appendEstacato(bass,E,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 10
	#ifdef DEBUG
	puts("Measure # 10");
	#endif
		//VOICE
		three(voice,Gs,A,2*C,octave,0.75,VOICEAZ);
		//HARMONY
		create(harmony,Gs,octave,0.25,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.25,CHORDAZ);
		append(harmony,C,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,A,2*A,octave-2,0.25,BASSAZ);
		appendSilence(0.25);
		append(bass,E,octave-1,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 11 & 12
	#ifdef DEBUG
	puts("Measure # 11 & 12");
	#endif
		//VOICE
		two(voice,B,Gs,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.75,VOICEAZ);
		//HARMONY
		interval(harmony,D,B,octave,0.125,CHORDAZ);
		append(harmony,Gs,octave,0.125,CHORDAZ);
		appendChord(harmony,E,D,Gs/2,octave,0.5,CHORDAZ);
		appendSilence(0.25);
		appendFour(harmony,Ef,E,Gs,A,octave,0.5,CHORDAZ);
	add();
		//BASS
		create(bass,E,octave-2,0.5,BASSAZ);
		append(bass,B,octave-2,0.25,BASSAZ);
		appendInterval(bass,E,2*E,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 13
	#ifdef DEBUG
	puts("Measure # 13");
	#endif
		//VOICE
		create(voice,B,octave,0.75,VOICEAZ);
		//HARMONY
		create(harmony,B,octave,0.75,CHORDAZ);
		silence(0.25);
		appendChordMartelato(harmony,D,E,Gs,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,E,2*E,octave-2,0.5,BASSAZ);
		append(bass,B,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 14
	#ifdef DEBUG
	puts("Measure # 14");
	#endif
		//VOICE
		three(voice,As,B,2*D,octave,0.75,VOICEAZ);
		//HARMONY
		chord(harmony,Cs,G,As,octave,0.25,CHORDAZ);
		appendChord(harmony,D,Gs,B,octave,0.25,CHORDAZ);
		appendChord(harmony,F,B,2*D,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,E,2*E,octave-2,0.25,BASSAZ);
		appendSilence(0.25);
		append(bass,Gs,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 15 & 16
	#ifdef DEBUG
	puts("Measure # 15 & 16");
	#endif
		//VOICE
		two(voice,C,B/2,octave+1,0.25,VOICEAZ);
		append(voice,A,octave,0.75,VOICEAZ);
		//HARMONY
		chord(harmony,E,A,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,D,Gs,B,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.5,CHORDAZ);
		appendSilence(0.25);
		appendFour(harmony,Gs,A,2*C,2*D,octave,0.5,CHORDAZ);
	add();
		//BASS
		create(bass,A,octave-2,0.25,BASSAZ);
		appendSilence(0.25);
		appendTwo(bass,E,E,octave-2,0.25,BASSAZ);
		append(bass,A,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 17
	#ifdef DEBUG
	puts("Measure # 17");
	#endif
		//VOICE
		create(voice,E,octave+1,0.75,VOICEAZ);
		//HARMONY
		chord(harmony,A,2*C,2*E,octave,0.75,CHORDAZ);
	add();
		//BASS
		interval(bass,A,2*A,octave-2,0.25,BASSAZ);
		appendChordMartelato(bass,A/2,C,E,octave,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,E,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 18
	#ifdef DEBUG
	puts("Measure # 18");
	#endif
		//VOICE
		create(voice,Ds,octave+1,0.25,VOICEAZ);
		append(voice,E,octave+1,0.375,VOICEAZ);
		append(voice,A,octave+1,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,A,C,Ds,octave,0.25,CHORDAZ);
		append(harmony,E,octave+1,0.375,CHORDAZ);
		append(harmony,A,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,A,2*A,octave-2,0.25,BASSAZ);
		appendChord(bass,A/2,C,E,octave,0.5,BASSAZ);
	add();
	cat();

	//MEASURE # 19 & 20
	#ifdef DEBUG
	puts("Measure # 19 & 20");
	#endif
		//VOICE
		two(voice,A,Gs,octave+1,0.25,VOICEAZ);
		append(voice,E,octave,1.0,VOICEAZ);
		//HARMONY
		interval(harmony,A,2*A,octave,0.125,CHORDAZ);
		append(harmony,Gs,octave+1,0.125,CHORDAZ);
		appendChord(harmony,Gs,2*D,2*E,octave,1.25,CHORDAZ);
	add();
		//BASS
		chord(bass,B/2,D,F,octave,0.125,BASSAZ);
		appendSilence(0.125);
		appendFourEstacato(bass,E,0,E/2,0,octave,0.5,BASSAZ);
		appendTwo(bass,C,C,octave,0.25,BASSAZ);
		appendFourEstacato(bass,E,0,E/2,0,octave,0.5,BASSAZ);		
	add();
	cat();
	//MEASURE # 21 & 22
	#ifdef DEBUG
	puts("Measure # 21 & 22");
	#endif
		//VOICE
		two(voice,F,E,octave+1,0.25,VOICEAZ);
		append(voice,B,octave,1.0,VOICEAZ);
		//HARMONY
		two(harmony,F,E,octave,0.25,CHORDAZ);
		append(harmony,B,octave,1.25,CHORDAZ);
		create(harmony,Gs,octave,1.5,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,B,D,octave,0.125,BASSAZ);
		appendSilence(0.125);
		appendFourEstacato(bass,E,0,B/2,0,octave,0.5,BASSAZ);
		appendTwo(bass,C,C,octave-1,0.25,BASSAZ);
		appendFourEstacato(bass,E,0,E/2,0,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 23 & 24
	#ifdef DEBUG
	puts("Measure # 23 & 24");
	#endif
		//VOICE
		two(voice,E,D,octave+1,0.25,VOICEAZ);
		append(voice,A,octave,0.75,VOICEAZ);
		//HARMONY
		two(harmony,E,D,octave,0.25,CHORDAZ);
		append(harmony,A,octave,0.625,CHORDAZ);
		append(harmony,E,octave+1,0.125,CHORDAZ);
		appendChordMarcato(harmony,A,2*C,2*Ef,octave,0.125,CHORDAZ);
		append(harmony,E,octave+1,0.125,CHORDAZ);
		appendChordMarcato(harmony,Gs,B,2*D,octave,0.125,CHORDAZ);
		append(harmony,C,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,A,octave-2,0.25,BASSAZ);
		appendChord(bass,A/2,C,E,octave,0.25,BASSAZ);
		append(bass,E,octave-1,0.25,BASSAZ);
		appendInterval(bass,A,2*A,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendFourMartelato(bass,E,0,E,0,octave,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 25
	#ifdef DEBUG
	puts("Measure # 25");
	#endif
		//VOICE
		create(voice,A,octave,0.75,VOICEAZ);
		//HARMONY
		create(harmony,A,octave,0.75,CHORDAZ);
		silence(0.25);
		appendIntervalMartelato(harmony,C,E,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,A,2*A,octave-2,0.5,BASSAZ);
		appendEstacato(bass,E,octave-1,0.25,BASSAZ);		
	add();
	cat();
	//MEASURE # 26
	#ifdef DEBUG
	puts("Measure # 26");
	#endif
		//VOICE
		three(voice,Gs,A,2*C,octave,0.75,VOICEAZ);
		//HARMONY
		create(harmony,Gs,octave,0.25,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.25,CHORDAZ);
		append(harmony,C,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,A,2*A,octave-2,0.25,BASSAZ);
		appendSilence(0.25);
		append(bass,E,octave-1,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 27 & 28
	#ifdef DEBUG
	puts("Measure # 27 & 28");
	#endif
		//VOICE
		two(voice,B,Gs,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.75,VOICEAZ);
		//HARMONY
		interval(harmony,D,B,octave,0.125,CHORDAZ);
		append(harmony,Gs,octave,0.125,CHORDAZ);
		appendChord(harmony,Gs/2,D,E,octave,0.5,CHORDAZ);
		appendSilence(0.25);
		appendFour(harmony,Ds,E,Gs,A,octave,0.5,CHORDAZ);
	add();
		//BASS
		create(bass,E,octave-2,0.5,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		appendInterval(bass,E,2*E,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 29
	#ifdef DEBUG
	puts("Measure # 29");
	#endif
		//VOICE
		create(voice,B,octave,0.75,VOICEAZ);
		//HARMONY
		create(harmony,B,octave,0.75,CHORDAZ);
		silence(0.25);
		appendChordMartelato(harmony,D,E,Gs,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,E,E,octave-2,0.5,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 30
	#ifdef DEBUG
	puts("Measure # 30");
	#endif
		//VOICE
		three(voice,Bf,B,D,octave,0.75,VOICEAZ);
		//HARMONY
		chord(harmony,Cs,G,Bf,octave,0.25,CHORDAZ);
		appendChord(harmony,D,G,B,octave,0.25,CHORDAZ);
		appendChord(harmony,F,B,2*D,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,E,2*E,octave-2,0.25,BASSAZ);
		appendSilence(0.25);
		append(bass,Gs,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 31 & 32
	#ifdef DEBUG
	puts("Measure # 31 & 32");
	#endif
		//VOICE
		two(voice,C,B/2,octave,0.25,VOICEAZ);
		append(voice,A,octave,0.75,VOICEAZ);
		//HARMONY
		chord(harmony,E,A,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,D,Gs,B,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.5,CHORDAZ);
		appendSilence(0.25);
		appendFour(harmony,Gs,A,2*C,2*D,octave,0.5,CHORDAZ);
	add();
		//BASS
		create(bass,A,octave-2,0.25,BASSAZ);
		appendFour(bass,0,F,E,C,octave-1,0.5,BASSAZ);
		append(bass,A,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 33
	#ifdef DEBUG
	puts("Measure # 33");
	#endif
		//VOICE
		create(voice,E,octave+1,0.75,VOICEAZ);
		//HARMONY
		chord(harmony,A/2,C,E,octave,0.75,CHORDAZ);
	add();
		//BASS
		interval(bass,A,2*A,octave-2,0.25,BASSAZ);
		appendChordMartelato(bass,A/2,C,E,octave,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,E,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 34
	#ifdef DEBUG
	puts("Measure # 34");
	#endif
		//VOICE
		three(voice,Ds,E,A,octave+1,0.75,VOICEAZ);
		//HARMONY
		chord(harmony,A,2*C,2*Ds,octave,0.25,CHORDAZ);
		append(harmony,E,octave+1,0.375,CHORDAZ);
		append(harmony,A,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,A,2*A,octave-2,0.25,BASSAZ);
		appendChord(bass,A/2,C,E,octave,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 35 & 36
	#ifdef DEBUG
	puts("Measure # 35 & 36");
	#endif
		//VOICE
		two(voice,A,F,octave+1,0.25,VOICEAZ);
		append(voice,D,octave+1,0.625,VOICEAZ);
		appendSilence(0.125);
		MESSOPIANO;
		appendFour(voice,D,C,B/2,C,octave+1,0.5,VOICEAZ);
		//HARMONY
		PIANO;
		two(harmony,A,F,octave+1,0.25,CHORDAZ);
		append(harmony,D+1,octave,0.625,CHORDAZ);
		create(harmony,A,octave,0.75+0.125,CHORDAZ);
		add();
		appendSilence(0.125);
		MESSOPIANO;		
		four(harmony,D,C,B/2,C,octave+1,0.5,CHORDAZ);
		interval(harmony,D,A,octave,0.5,CHORDAZ);
		add();
		cat();
	add();
		//BASS
		PIANO;
		chord(bass,A/2,C,E,octave,0.25,BASSAZ);
		appendSilence(0.25);
		append(bass,A,octave-1,0.25,BASSAZ);
		MESSOPIANO;
		appendInterval(bass,D,2*D,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 37
	#ifdef DEBUG
	puts("Measure # 37");
	#endif
		//VOICE
		two(voice,C,B/2,octave+1,0.25,VOICEAZ);
		append(voice,A,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,E,A,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,D,Gs,B,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.5,CHORDAZ);
	add();
		//BASS
		interval(bass,A,2*A,octave-2,0.5,BASSAZ);
		append(bass,E,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 38
	C=fKey;
	#ifdef DEBUG
	puts("Measure # 38");
	#endif
		//VOICE
		two(voice,D,C,octave,0.25,VOICEAZ);
		append(voice,B,octave-1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,F,B,2*D,octave-1,0.125,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave-1,0.125,CHORDAZ);
		appendChord(harmony,D,F,B,octave-1,0.5,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-3,0.5,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 39 & 40
	#ifdef DEBUG
	puts("Measure # 39 & 40");
	#endif
		//VOICE
		create(voice,E,octave,0.875,VOICEAZ);
		appendSilence(0.125);
		append(voice,G,octave-1,0.25,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		//HARMONY
		arpegioFour(harmony,E/2,G/2,C,E,octave,1.0,CHORDAZ);
		append(harmony,G,octave-1,0.25,CHORDAZ);
		appendChord(harmony,B/2,D,G,octave,0.25,CHORDAZ);
	add();
		//BASS
		silence(0.25);
		appendTwo(bass,G,A,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		create(bass,C,octave-2,0.75,BASSAZ);
		add();
		appendMartelato(bass,G,octave-3,0.25,BASSAZ);
	add();
	cat();
}

void chorus(short end){
	volume = ((PIANO)+(FORTE))/2;
	//MEASURE # 41
	#ifdef DEBUG
	puts("Measure # 41");
	#endif
		//VOICE
		create(voice,G,octave,0.5,VOICEAZ);
		appendTwo(voice,E,D,octave,0.25,VOICEAZ);
		//HARMONY
		create(harmony,G,octave,0.5,CHORDAZ);
		appendTwo(harmony,E,D,octave,0.25,CHORDAZ);
		grace(harmony,C,E,octave,0.75,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-2,0.25,BASSAZ);
		appendChordEstacato(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendThree(bass,0,G,0,octave-2,0.375,BASSAZ);
	add();
	//MEASURE # 42
	#ifdef DEBUG
	puts("Measure # 42");
	#endif
		//VOICE
		create(voice,D,octave,0.5,VOICEAZ);
		appendTwo(voice,C,A/2,octave,0.25,VOICEAZ);
		//HARMONY
		create(harmony,D,octave,0.5,CHORDAZ);
		interval(harmony,Gf,2*C,octave-1,0.125,CHORDAZ);
		append(harmony,A,octave,0.125,CHORDAZ);
		DECRESCENDO;
		cat();
	add();
		//BASS
		estacato(bass,E,octave-2,0.25,BASSAZ);
		appendSilence(0.25);
		append(bass,Ef,octave-2,0.125,BASSAZ);
		silence(0.25);
		appendIntervalMartelato(bass,E,G,octave-1,0.125,BASSAZ);
		add();
	add();
	cat();
	//MEASURE # 43 & 44
	#ifdef DEBUG
	puts("Measure # 43 & 44");
	#endif
		//VOICE
		create(voice,A,octave-1,0.625,VOICEAZ);
		appendSilence(0.125);
		append(voice,A,octave-1,0.25,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		//HARMONY
		create(harmony,A,octave,0.625,CHORDAZ);
		appendSilence(0.125);
		create(harmony,A,octave,0.25,CHORDAZ);
		appendChord(harmony,Db,F,A,octave,0.25,CHORDAZ);
		CRESCENDO;
		cat();
		silence(0.25);
		appendChordMartelato(harmony,Db,F,A,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,Db,octave-2,0.25,BASSAZ);
		appendIntervalMartelato(bass,Db,F,octave-1,0.125,BASSAZ);
		appendThree(bass,0,A,0,octave-2,0.125,BASSAZ);
		appendMartelato(bass,Db,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 45
	#ifdef DEBUG
	puts("Measure # 45");
	#endif
		//VOICE
		create(voice,A,octave,0.5,VOICEAZ);
		appendTwo(voice,F,E,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,F,A,octave,0.5,CHORDAZ);
		appendTwo(harmony,F,E,octave,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,G,2*G,octave-3,0.25,BASSAZ);
		appendChordMartelato(bass,F,G,B,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 46
	#ifdef DEBUG
	puts("Measure # 46");
	#endif
		//VOICE
		create(voice,E,octave,0.5,VOICEAZ);
		appendTwo(voice,D,B/2,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,G,B,2*E,octave-1,0.5,CHORDAZ);
		appendTwo(harmony,D,B/2,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-3,0.25,BASSAZ);
		appendMartelato(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 47 & 48
	#ifdef DEBUG
	puts("Measure # 47 & 48");
	#endif
		//VOICE
		create(voice,G,octave,0.875,VOICEAZ);
		appendSilence(0.125);
		appendTwo(voice,G,A,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,0.875,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,B/2,F,G,octave,0.25,CHORDAZ);
		append(harmony,A,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.25,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
		append(bass,A,octave-1,0.125,BASSAZ);
		appendChordMartelato(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.25,BASSAZ);
		appendChordMartelato(bass,D,F,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 49
	#ifdef DEBUG
	puts("Measure # 49");
	#endif
		//VOICE
		create(voice,B,octave,0.5,VOICEAZ);
		appendTwo(voice,B,2*C,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,B,octave,0.5,CHORDAZ);
		appendChord(harmony,E,G,B,octave,0.125,CHORDAZ);
		append(harmony,C,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,E,2*E,octave-2,0.25,BASSAZ);
		appendChordMartelato(bass,E,G,B,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		appendIntervalEstacato(bass,E,2*E,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 50
	#ifdef DEBUG
	puts("Measure # 50");
	#endif
		//VOICE
		create(voice,A,octave,0.5,VOICEAZ);
		appendTwo(voice,A,B,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,C,Fs,A,octave,0.5,CHORDAZ);
		chord(harmony,C,Fs,A,octave,0.125,CHORDAZ);
		append(harmony,B,octave,0.125,CHORDAZ);
		DECRESCENDO;
		cat();
	add();
		//BASS
		interval(bass,Ef,2*Ef,octave-2,0.25,BASSAZ);
		appendChordMartelato(bass,E,Gf,A,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,Ef,2*Ef,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 51 & 52
	#ifdef DEBUG
	puts("Measure # 51 & 52");
	#endif
		//VOICE
		create(voice,G,octave,0.875,VOICEAZ);
		appendSilence(0.125);
		appendFour(voice,F,A,F,E,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,F,G,octave,1.0,CHORDAZ);
		four(harmony,F,A,F,E,octave,0.5,CHORDAZ);
		create(harmony,B/2,octave,0.125,CHORDAZ);
		add();
		cat();
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.25,BASSAZ);
		appendChordMartelato(bass,D,Fs,G,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendMartelato(bass,G,octave-2,0.25,BASSAZ);
		appendChordMarcato(bass,D,F,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 53 & 54
	#ifdef DEBUG
	puts("Measure # 53 & 54");
	#endif
		//VOICE
		create(voice,D,octave,1.0,VOICEAZ);
		appendFour(voice,D,G,E,D,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,F,B,2*D,octave-1,0.875,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,F,B,2*D,octave-1,0.125,CHORDAZ);
		appendThree(harmony,G,E,D,octave,0.375,CHORDAZ);
	add();
		//BASS
		intervalEstacato(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendSilence(0.125);
		appendFour(bass,G,Gs,A,Bf,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 55 & 56
	#ifdef DEBUG
	puts("Measure # 55 & 56");
	#endif
		//VOICE
		create(voice,A,octave-1,0.875,VOICEAZ);
		appendSilence(0.125);
		appendTwo(voice,G,2*G,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,A,octave-1,1.0,CHORDAZ);
		append(harmony,G,octave-1,0.25,CHORDAZ);
		appendChord(harmony,B,2*Ef,2*G,octave-1,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.25,BASSAZ);
		appendFour(bass,B/2,C,Ef,E,octave-2,0.5,BASSAZ);
		appendThree(bass,A,G,G/2,octave-2,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 57
	#ifdef DEBUG
	puts("Measure # 57");
	#endif
		//VOICE
		create(voice,G,octave,0.5,VOICEAZ);
		appendTwo(voice,E,D,octave,0.25,VOICEAZ);
		//HARMONY
		create(harmony,G,octave,0.5,CHORDAZ);
		appendTwo(harmony,E,D,octave,0.25,CHORDAZ);
		grace(harmony,C,E,octave,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-2,0.25,BASSAZ);
		appendChordEstacato(bass,C,E,G,octave-1,0.125,BASSAZ);
		appendThree(bass,0,G,0,octave-2,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 58
	#ifdef DEBUG
	puts("Measure # 58");
	#endif
		//VOICE
		create(voice,D,octave,0.5,VOICEAZ);
		appendTwo(voice,C,A/2,octave,0.25,VOICEAZ);
		//HARMONY
		create(harmony,D,octave,0.5,CHORDAZ);
		interval(harmony,Gf,2*C,octave-1,0.125,CHORDAZ);
		append(harmony,A,octave-1,0.125,CHORDAZ);
		DECRESCENDO;
		cat();
		silence(0.25);
		appendIntervalMartelato(harmony,E,G,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		estacato(bass,E,octave-2,0.25,BASSAZ);
		appendSilence(0.25);
		appendEstacato(bass,Ef,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 59 & 60
	#ifdef DEBUG
	puts("Measure # 59 & 60");
	#endif
		//VOICE
		create(voice,A,octave-1,0.875,VOICEAZ);
		appendSilence(0.125);
		appendTwo(voice,G,2*G,octave-1,0.5,VOICEAZ);
		//HARMONY
		create(harmony,A,octave-1,0.875,CHORDAZ);
		appendSilence(0.125);
		create(harmony,A,octave-1,0.25,CHORDAZ);
		appendChord(harmony,Db,F,A,octave,0.25,CHORDAZ);
		CRESCENDO;
		cat();
		silence(0.25);
		appendChordMartelato(harmony,Db,F,A,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,Db,octave-2,0.25,BASSAZ);
		appendIntervalMartelato(bass,Db,F,octave-1,0.125,BASSAZ);
		appendThreeEstacato(bass,0,G,0,octave-2,0.375,BASSAZ);
		append(bass,Db,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 61
	#ifdef DEBUG
	puts("Measure # 61");
	#endif
		//VOICE
		create(voice,A,octave,0.5,VOICEAZ);
		appendTwo(voice,F,E,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,F,A,octave,0.5,CHORDAZ);
		two(harmony,F,E,octave,0.25,CHORDAZ);
		DECRESCENDO;
		cat();
	add();
		//BASS
		interval(bass,G,2*G,octave-3,0.25,BASSAZ);
		appendChordMartelato(bass,F,G,B,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 62
	#ifdef DEBUG
	puts("Measure # 62");
	#endif
		//VOICE
		create(voice,E,octave,0.5,VOICEAZ);
		appendTwo(voice,D,B/2,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,G,B,2*E,octave-1,0.5,CHORDAZ);
		appendTwo(harmony,D,B/2,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-3,0.25,BASSAZ);
		appendMartelato(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();

	//MEASURE # 63 & 64
	#ifdef DEBUG
	puts("Measure # 63 & 64");
	#endif
		//VOICE
		create(voice,G,octave,0.875,VOICEAZ);
		appendSilence(0.125);
		appendTwo(voice,G,A,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,0.875,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,B/2,F,G,octave,0.25,CHORDAZ);
		append(harmony,A,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.25,BASSAZ);
		appendChord(bass,C,E,G,octave-1,0.125,BASSAZ);
		append(bass,A,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,C,octave-2,0.25,BASSAZ);
		appendChordMartelato(bass,D,F,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 65
	#ifdef DEBUG
	puts("Measure # 65");
	#endif
		//VOICE
		create(voice,B,octave,0.5,VOICEAZ);
		appendTwo(voice,B,2*C,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,B,octave,0.5,CHORDAZ);
		chord(harmony,E,G,B,octave,0.125,CHORDAZ);
		append(harmony,C,octave+1,0.125,CHORDAZ);
		CRESCENDO;
		cat();
	add();
		//BASS
		interval(bass,E,2*E,octave-3,0.25,BASSAZ);
		appendChordMartelato(bass,E,G,B,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		appendIntervalEstacato(bass,E,2*E,octave,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 66
	#ifdef DEBUG
	puts("Measure # 66");
	#endif
		//VOICE
		create(voice,A,octave,0.5,VOICEAZ);
		appendTwo(voice,A,B,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,C,Fs,A,octave,0.5,CHORDAZ);
		chord(harmony,C,Fs,A,octave,0.125,CHORDAZ);
		append(harmony,B,octave,0.125,CHORDAZ);
		DECRESCENDO;
		cat();
	add();
		//BASS
		interval(bass,Ef,2*Ef,octave-2,0.25,BASSAZ);
		appendChordMartelato(bass,Ef,F,A,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,Ef,2*Ef,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 67 & 68
	#ifdef DEBUG
	puts("Measure # 67 & 68");
	#endif
		//VOICE
		create(voice,G,octave,0.875,VOICEAZ);
		appendSilence(0.125);
		appendFour(voice,F,A,F,E,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,F,G,octave,1.0,CHORDAZ);
		intervalMarcato(harmony,B/2,F,octave,0.125,CHORDAZ);
		appendThree(harmony,A,F,E,octave,0.375,CHORDAZ);
		DECRESCENDO;
		cat();
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.25,BASSAZ);
		appendChordMartelato(bass,D,F,G,octave,0.125,BASSAZ);
		appendSilence(0.125);
		appendIntervalEstacato(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendMartelato(bass,G,octave-2,0.25,BASSAZ);
		appendChordMarcato(bass,D,F,G,octave,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 69 & 70
	#ifdef DEBUG
	puts("Measure # 69 & 70");
	#endif
		//VOICE
		create(voice,D,octave,0.875,VOICEAZ);
		appendSilence(0.125);
		appendThree(voice,D,G,E,octave,0.375,VOICEAZ);
		create(voice,D,octave,0.125,VOICEAZ);
		volume/=2;
		create(voice,G,octave,0.125,VOICEAZ);
		volume*=2;
		add();
		cat();
		//HARMONY
		chord(harmony,F,B,D,octave,1.0,CHORDAZ);
		volume/=2;
		create(harmony,D,octave,0.5,CHORDAZ);
		volume*=2;
		create(harmony,B,octave-1,0.5,CHORDAZ);
		add();
		silence(0.125);
		appendThree(harmony,G,E,D,octave,0.375,CHORDAZ);
		add();
		cat();
	add();
		//BASS
		intervalEstacato(bass,G,2*G,octave-3,0.125,BASSAZ);
		appendSilence(0.125);
		appendFour(bass,G,Gs,A,Bf,octave-2,0.5,BASSAZ);
		append(bass,B,octave-2,0.25,BASSAZ);
		appendInterval(bass,G,2*F,octave-2,0.5,BASSAZ);
	add();
	cat();
	if(!end){
	//MEASURE # 71 & 72
	#ifdef DEBUG
	puts("Measure # 71 & 72");
	#endif
		//VOICE
		create(voice,C,octave,0.875,VOICEAZ);
		appendSilence(0.125);
		appendInterval(voice,G,2*G,octave-1,0.5,VOICEAZ);
		//HARMONY
		interval(harmony,E/2,C,octave,0.5,CHORDAZ);
		appendChordMartelato(harmony,C,E,A,octave,0.125,CHORDAZ);
		appendSilence(0.375);
		append(harmony,G,octave-1,0.25,CHORDAZ);
		appendChord(harmony,B/2,Ds,G,octave,0.25,CHORDAZ);
		two(harmony,A,C,octave-1,0.5,CHORDAZ);
		CRESCENDO;
		add();
	add();
		//BASS
		interval(bass,C,2*C,octave-3,0.25,BASSAZ);
		appendChordMartelato(bass,C,E,G,octave,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,G,2*G,octave-3,0.75,BASSAZ);
	add();
	cat();
	}else{
	//MEASURE # 73 & 74
	#ifdef DEBUG
	puts("Measure # 73 & 74");
	#endif
		//VOICE
		volume /= 2;
		create(voice,E,octave+1,1.0,VOICEAZ);
		volume *= 2;
		create(voice,C,octave+1,1.0,VOICEAZ);
		add();		
		//HARMONY
		create(harmony,C,octave,1.0,CHORDAZ);
		appendFourChordMartelato(harmony,C,E,G,2*C,octave,0.125,CHORDAZ);
		two(harmony,A,G,octave-1,0.5,CHORDAZ);
		create(harmony,E,octave,0.5,CHORDAZ);
		add();
		CRESCENDO;
		interval(harmony,D,F,octave-2,0.25,CHORDAZ);
		appendInterval(harmony,E,C,octave-1,0.25,CHORDAZ);
		DECRESCENDO;
		cat();
		add();
	add();
		//BASS
		silence(0.125);
		append(bass,Fs,octave-2,0.125,BASSAZ);
		four(bass,G,Gs,A,Bf,octave-2,0.5,BASSAZ);
		CRESCENDO;
		cat();
		append(bass,G,octave-2,0.25,BASSAZ);
		appendMartelato(bass,G,octave-2,0.125,BASSAZ);
		create(bass,C,octave-2,1.0,BASSAZ);
		appendMartelato(bass,C,octave-2,0.125,BASSAZ);
		add();
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
	aFlatKey = Af/2;
	fKey = F;
	C = aFlatKey;
	song();
	echo(10,0.3,4);

	puts("Writing wav file: noche azul.wav");
	exportToWav("Noche Azul.wav");
}
