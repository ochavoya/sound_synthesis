#include "soundlib.h"

#define VOICEAZ 150
#define CHORDAZ 30
#define BASSAZ 90

#define DEBUG 1


double (*voice)(double) = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double) = oldCircleOfRa;

double eFlatKey,cKey;

short octave = 0;

void intro(void){
	MESSOFORTE;
	double start;
	//MEASURE # 1
	#ifdef DEBUG
	puts("Measure # 1");
	#endif
		//HARMONY
		silence(0.25);
		appendFourChordMartelato(harmony,G/2,A/2,C,E,octave,0.125,CHORDAZ);
		appendFourChordEstacato(harmony,G/2,A/2,C,E,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendFourChordMartelato(harmony,G/2,A/2,C,E,octave,0.125,CHORDAZ);
		appendFourChordEstacato(harmony,G/2,A/2,C,E,octave,0.25,CHORDAZ);
		//BASS
		create(bass,C,octave-2,0.25,BASSAZ);
		appendMartelato(bass,G,octave-2,0.125,BASSAZ);
		appendEstacato(bass,G,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendMartelato(bass,G,octave-2,0.125,BASSAZ);
		appendEstacato(bass,G,octave-2,0.25,BASSAZ);
	add();
	//MEASURE # 2
	#ifdef DEBUG
	puts("Measure # 2");
	#endif
		//HARMONY
		silence(0.25);
		appendFourChordMartelato(harmony,G/2,A/2,C,E,octave,0.125,CHORDAZ);
		appendFourChordEstacato(harmony,G/2,A/2,C,E,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendFourChordMartelato(harmony,G/2,A/2,C,E,octave,0.125,CHORDAZ);
		appendFourChordEstacato(harmony,G/2,A/2,C,E,octave,0.25,CHORDAZ);
		//BASS
		create(bass,C,octave-2,0.25,BASSAZ);
		appendMartelato(bass,G,octave-2,0.125,BASSAZ);
		appendEstacato(bass,G,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendMartelato(bass,G,octave-2,0.125,BASSAZ);
		appendEstacato(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 3
	MESSOPIANO;
	#ifdef DEBUG
	puts("Measure # 3");
	#endif
		//VOICE
		create(voice,C,octave+1,1.0,VOICEAZ);
		//HARMONY
		arpegioFour(harmony,C,E,G,2*C,octave,1.0,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.25,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,B,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 4
	#ifdef DEBUG
	puts("Measure # 4");
	#endif
		//VOICE
		create(voice,G,octave,1.0,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,G,octave,1.0,CHORDAZ);
	add();
		//BASS
		create(bass,E,octave-1,0.25,BASSAZ);
		appendEstacato(bass,G,octave-1,0.125,BASSAZ);
		append(bass,E,octave-1,0.25,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 5
	#ifdef DEBUG
	puts("Measure # 5");
	#endif
		//VOICE
		create(voice,A,octave,1.0,VOICEAZ);
		//HARMONY
		arpegioFour(harmony,A/2,C,E,A,octave,1.0,CHORDAZ);
	add();
		//BASS
		create(bass,A,octave-3,0.25,BASSAZ);
		append(bass,C,octave-2,0.125,BASSAZ);
		append(bass,E,octave-2,0.25,BASSAZ);
		appendEstacato(bass,G,octave-2,0.125,BASSAZ);
		append(bass,A,octave-2,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 6 & 7
	#ifdef DEBUG
	puts("Measure # 6 & 7");
	#endif
		//VOICE
		create(voice,E,octave,1.25,VOICEAZ);
		appendSilence(0.125);
		appendTwo(voice,E,G,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		append(voice,D,octave,0.125,VOICEAZ);
		//HARMONY
		arpegio(harmony,A/2,C,E,octave,1.0,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave,0.25,CHORDAZ);
		appendSilence(0.125);
		append(harmony,E,octave,0.125,CHORDAZ);
		appendInterval(harmony,B/2,G,octave,0.125,CHORDAZ);
		appendInterval(harmony,G/2,E,octave,0.25,CHORDAZ);
		appendInterval(harmony,F/2,D,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-1,0.25,BASSAZ);
		appendEstacato(bass,E,octave-1,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		appendEstacato(bass,C,octave-1,0.125,BASSAZ);
		append(bass,A,octave-2,0.25,BASSAZ);
		append(bass,G,octave,0.375,BASSAZ);
		appendTwo(bass,G,2*G,octave-3,0.25,BASSAZ);
		append(bass,A,octave-2,0.25,BASSAZ);
		append(bass,B,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 8 & 9
	#ifdef DEBUG
	puts("Measure # 8 & 9");
	#endif
		//VOICE
		create(voice,C,octave,1.5,VOICEAZ);
		//HARMONY
		interval(harmony,E/2,C,octave,1.5,CHORDAZ);
	add();
		//BASS
		four(bass,C,G,A,E,octave-2,0.5,BASSAZ);
		appendTwoMartelato(bass,G,G/2,octave-2,0.5,BASSAZ);
		append(bass,C,octave-2,0.25,BASSAZ);
		appendTwo(bass,A,E,octave-2,0.25,BASSAZ);
		appendTwoMartelato(bass,G,G/2,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 10 & 11
	#ifdef DEBUG
	puts("Measure # 10 & 11");
	#endif
		//VOICE
		create(voice,Db,octave,1.25,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		appendTwo(voice,Db,E,octave,0.25,VOICEAZ);
		append(voice,A,octave-1,0.25,VOICEAZ);
		//HARMONY
		arpegioFour(harmony,F,A,B,Db,octave,1.25,CHORDAZ);
		appendChord(harmony,G/2,B/2,E,octave,0.25,CHORDAZ);
		appendInterval(harmony,A/2,Db,octave,0.125,CHORDAZ);
		append(harmony,C,octave,0.125,CHORDAZ);
		appendChord(harmony,Db,F,A,octave-1,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,Db,octave-2,0.25,BASSAZ);
		append(bass,A,octave-2,0.125,BASSAZ);
		append(bass,B,octave-2,0.25,BASSAZ);
		append(bass,A,octave-2,0.125,BASSAZ);
		append(bass,F,octave-2,0.25,BASSAZ);
		appendFour(bass,Db,G,A,B,octave-2,1.0,BASSAZ);
	add();
	cat();
	//MEASURE # 12 & 13
	#ifdef DEBUG
	puts("Measure # 12 & 13");
	#endif
		//VOICE
		create(voice,C,octave,1.5,VOICEAZ);
		//HARMONY
		interval(harmony,E/2,C,octave,1.5,CHORDAZ);
	add();
		//BASS
		four(bass,C,G,A,E,octave-2,0.5,BASSAZ);
		appendTwoMartelato(bass,G,G/2,octave-2,0.5,BASSAZ);
		append(bass,C,octave-2,0.25,BASSAZ);
		appendTwo(bass,A,E,octave-2,0.25,BASSAZ);
		appendTwoMartelato(bass,G,G/2,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 14 & 15
	#ifdef DEBUG
	puts("Measure # 14 & 15");
	#endif
		//VOICE
		create(voice,Db,octave,1.25,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		appendTwo(voice,D,C,octave,0.25,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		//HARMONY
		arpegioFour(harmony,Gf,A,C,Db,octave,1.25,CHORDAZ);
		append(harmony,E,octave,0.25,CHORDAZ);
		appendChord(harmony,Gf,A,D,octave,0.125,CHORDAZ);
		append(harmony,C,octave,0.125,CHORDAZ);
		append(harmony,A,octave-1,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,Db,octave-2,0.375,BASSAZ);
		append(bass,A,octave-2,0.125,BASSAZ);
		appendTwoMartelato(bass,C,G/2,octave-1,0.5,BASSAZ);
		append(bass,Db,octave-2,0.375,BASSAZ);
		append(bass,A,octave-2,0.125,BASSAZ);
		appendTwoEstacato(bass,C,Db/2,octave-1,0.5,BASSAZ);
	add();
	cat();

	//MEASURE # 16 & 17
	start=(double)(MESSOFORTE)/(DOUBLEFORTE);
	C=cKey;
	#ifdef DEBUG
	puts("Measure # 16 & 17");
	#endif
		//VOICE
		create(voice,F,octave,1.25,VOICEAZ);
		//HARMONY
		chordMarcato(harmony,Af/2,Db,F,octave,0.375,CHORDAZ);
		append(harmony,A,octave-1,0.125,CHORDAZ);
		appendFour(harmony,Bf,B,2*C,2*Cs,octave-1,0.5,CHORDAZ);
		appendFour(harmony,D,Ef,E,F,octave,0.5,CHORDAZ);
		appendChord(harmony,G,B,2*E,octave,0.25,CHORDAZ);
		appendChord(harmony,F,B,2*D,octave,0.125,CHORDAZ);
		appendSilence(0.125);
	add();
		//BASS
		interval(bass,B,B/2,octave-2,0.375,BASSAZ);
		appendSilence(0.625+0.5);
		appendInterval(bass,G,G/2,octave-1,0.375,BASSAZ);
	add();
	gradual(start,1);
	cat();
}


void repeat(short end){
	double temporal;
	volume = ((MESSOPIANO)+ (MESSOFORTE))/2;
	C = cKey;
	//MEASURE # 18 & 19
	#ifdef DEBUG
	puts("Measure # 18 & 19");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		append(voice,A,octave,0.75,VOICEAZ);
		appendTwo(voice,G,A,octave,0.25,VOICEAZ);
		appendSilence(0.125);
		append(voice,C,octave+1,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.5,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.75,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		append(harmony,C,octave+1,0.125,CHORDAZ);
		appendChordMartelato(harmony,C,E,A,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendMartelato(bass,C,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		appendMartelato(bass,G,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,C,octave-2,0.25,BASSAZ);
		appendTwo(bass,G,2*C,octave-2,0.25,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendMartelato(bass,C,octave-1,0.25,BASSAZ);
	add();

	//MEASURE # 20 & 21
	#ifdef DEBUG
	puts("Measure # 20 & 21");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		append(voice,A,octave,0.75,VOICEAZ);
		appendFour(voice,G,A,0,2*C,octave,0.5,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.5,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.75,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		append(harmony,C,octave+1,0.125,CHORDAZ);
		appendChordMartelato(harmony,C,E,G,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendMartelato(bass,C,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		appendMartelato(bass,G,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,C,octave-2,0.25,BASSAZ);
		appendTwo(bass,G,2*C,octave-2,0.25,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendMartelato(bass,C,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 22 & 23
	#ifdef DEBUG
	puts("Measure # 22 & 23");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		append(voice,A,octave,0.75,VOICEAZ);
		appendTwo(voice,A,G,octave,0.25,VOICEAZ);
		appendSilence(0.125);
		append(voice,C,octave+1,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,2*C,octave,0.5,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.75,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,2*C,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		append(harmony,C,octave+1,0.125,CHORDAZ);
		appendChordMartelato(harmony,C,E,A,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendMartelato(bass,C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendMartelato(bass,G,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,C,octave-2,0.25,BASSAZ);
		appendTwo(bass,G,2*C,octave-2,0.25,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 24 & 25
	#ifdef DEBUG
	puts("Measure # 24");
	#endif
		//VOICE
		create(voice,Db,octave+1,1.25,VOICEAZ);
		//HARMONY
		fourChordEstacato(harmony,F,A,B,2*Db,octave,0.25,CHORDAZ);
		appendSilence(0.25);
		temporal=volume;
		DOUBLEFORTE;
		appendFourChordMarcato(harmony,F,A,B,2*Db,octave,0.125,CHORDAZ);
		appendFourChordEstacato(harmony,F,A,B,2*Db,octave,0.125,CHORDAZ);
		appendSilence(0.25);
		appendFourChordMarcato(harmony,F,A,B,2*Db,octave,0.125,CHORDAZ);
		appendMarcato(harmony,D,octave+1,0.125,CHORDAZ);
		appendThree(harmony,D,0,B/2,octave,0.375,CHORDAZ);
		appendEstacato(harmony,G,octave-1,0.25,CHORDAZ);
		gradual(1.5/1.25,1.5/1.25);
	add();
		//BASS
		volume=temporal;
		arpegioEstacatoMartelato(bass,G,2*D,2*B,octave-2,0.25,BASSAZ);
		appendSilence(0.25);
		arpegio(bass,G,2*D,2*B,octave-2,0.25,BASSAZ);
		MARCATO; cat();
		arpegioEstacato(bass,G,2*D,2*B,octave-2,0.25,BASSAZ);
		cat();
		appendSilence(0.25);
		arpegio(bass,G,2*D,2*B,octave-2,0.25,BASSAZ);
		MARCATO;
		cat();
		appendMarcato(bass,F,octave-1,0.125,BASSAZ);
		append(bass,Db,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,B,octave-2,0.125,BASSAZ);
		estacatoMartelato(bass,G,octave-2,0.25,BASSAZ);
		cat();
	add();
	cat();


	//MEASURE # 26 & 27
	#ifdef DEBUG
	puts("Measure # 26 & 27");
	#endif
		//VOICE
		create(voice,B,octave,0.5,VOICEAZ);
		append(voice,A,octave,0.75,VOICEAZ);
		appendFour(voice,G,A,0,C,octave,0.5,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,D/2,F,B,octave,0.5,CHORDAZ);
		appendChord(harmony,F,A,B/2,octave,0.75,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
		appendChord(harmony,F,A,B/2,octave,0.125,CHORDAZ);
		appendTwo(harmony,0,C,octave+1,0.25,CHORDAZ);
		appendChordMartelato(harmony,F,A,B/2,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-2,0.375,BASSAZ);
		append(bass,D,octave-1,0.125,BASSAZ);
		appendFourEstacato(bass,F,0,D,0,octave-1,0.5,BASSAZ);
		appendMartelato(bass,G,octave-2,0.25,BASSAZ);
		appendFour(bass,D,G/2,0,D,octave-1,0.5,BASSAZ);
		appendMartelato(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 28 & 29
	#ifdef DEBUG
	puts("Measure # 28 & 29");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		append(voice,A,octave,0.75,VOICEAZ);
		appendFour(voice,G,A,0,2*C,octave,0.5,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.5,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.75,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.125,CHORDAZ);
		appendTwo(harmony,0,C,octave+1,0.25,CHORDAZ);
		appendChordMartelato(harmony,C,E,A,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendFourMartelato(bass,C,0,G/2,0,octave-1,0.5,BASSAZ);
		appendEstacatoMartelato(bass,C,octave-2,0.25,BASSAZ);
		appendFour(bass,G,2*C,0,G,octave-2,0.5,BASSAZ);
		appendMartelato(bass,C,octave-1,0.25,BASSAZ);		
	add();
	cat();

	//MEASURE # 30 & 31
	#ifdef DEBUG
	puts("Measure # 30 & 31");
	#endif
		//VOICE
		create(voice,E,octave+1,0.5,VOICEAZ);
		append(voice,D,octave+1,0.75,VOICEAZ);
		appendFour(voice,A,B,0,C,octave,0.5,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,Gf,2*C,2*E,octave,0.5,CHORDAZ);
		appendChord(harmony,Gf,2*C,2*D,octave,0.75,CHORDAZ);
		append(harmony,A,octave,0.125,CHORDAZ);
		appendChord(harmony,D,Gf,B,octave,0.125,CHORDAZ);
		appendTwo(harmony,0,C,octave,0.25,CHORDAZ);
		appendChordMartelato(harmony,D,Gf,A,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,D,octave-2,0.375,BASSAZ);
		append(bass,A,octave-2,0.125,BASSAZ);
		appendThree(bass,D,A/2,D/2,octave,0.75,BASSAZ);
		appendSilence(0.125);
		appendChordMartelato(bass,D,Gf,2*C,octave,0.125,BASSAZ);
		appendSilence(0.25);
		appendChordMartelato(bass,D,Gf,2*C,octave,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 32 & 33
	#ifdef DEBUG
	puts("Measure # 32 & 33");
	#endif
		//VOICE
		create(voice,D,octave+1,1.125,VOICEAZ);
		//HARMONY
		chord(harmony,F,B,D,octave,0.25,CHORDAZ);
			chord(harmony,D,Gf,G,octave,0.125,CHORDAZ);
			append(harmony,A,octave,0.125,CHORDAZ);
			DECRESCENDO;
		cat();
		appendSilence(0.125);
			chord(harmony,E,G,As,octave,0.125,CHORDAZ);
			appendEstacato(harmony,B,octave,0.25,CHORDAZ);
			DECRESCENDO;
			cat();
			chordMartelato(harmony,G,Bf,2*Cs,octave,0.125,CHORDAZ);
			appendEstacato(harmony,D,octave+1,0.125,CHORDAZ);
			DECRESCENDO;
			cat();
		appendSilence(0.125);
		chord(harmony,B/2,Ds,F,octave+1,0.375,CHORDAZ);
		SFORSANDO;
		cat();
		appendSilence(0.25);
	add();
		//BASS
		arpegio(bass,G,2*D,2*G,octave-2,0.25,BASSAZ);
			martelato(bass,G,octave-1,0.125,BASSAZ);
			appendEstacato(bass,C,octave,0.125,BASSAZ);
			DECRESCENDO;
		cat();
		appendSilence(0.125);
			martelato(bass,C,octave,0.125,BASSAZ);
			appendMarcato(bass,D,octave,0.125,BASSAZ);
			DECRESCENDO;
		cat();
			martelato(bass,C,octave,0.125,BASSAZ);
			appendMarcato(bass,D,octave,0.125,BASSAZ);
			DECRESCENDO;
		cat();
		appendSilence(0.5);
		appendIntervalEstacatoMartelato(bass,G,2*G,octave-2,0.125,BASSAZ);
	add();
	cat();

	//MEASURE # 34 & 35
	#ifdef DEBUG
	puts("Measure # 34 & 35");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		append(voice,A,octave,0.75,VOICEAZ);
		appendFour(voice,G,A,0,2*C,octave,0.5,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.5,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.75,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.125,CHORDAZ);
		appendTwo(harmony,0,2*C,octave,0.25,CHORDAZ);
		appendChordMartelato(harmony,C,E,A,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave,0.125,BASSAZ);
		appendFourMartelato(bass,C,0,G/2,0,octave-2,0.5,BASSAZ);
		appendMartelato(bass,C,octave-2,0.25,BASSAZ);
		appendFour(bass,G,2*C,0,G,octave-2,0.5,BASSAZ);
		appendMartelato(bass,C,octave-2,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 36 & 37
	#ifdef DEBUG
	puts("Measure # 36 & 37");
	#endif
		//VOICE
		create(voice,C,octave,0.5,VOICEAZ);
		append(voice,A,octave,0.75,VOICEAZ);
		appendFour(voice,G,A,0,2*C,octave,0.5,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.5,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.75,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.125,CHORDAZ);
		appendTwo(harmony,0,2*C,octave,0.25,CHORDAZ);
		appendChordMartelato(harmony,C,E,A,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave,0.125,BASSAZ);
		appendFourMartelato(bass,C,0,G/2,0,octave-2,0.5,BASSAZ);
		appendMartelato(bass,C,octave-2,0.25,BASSAZ);
		appendFour(bass,G,2*C,0,G,octave-2,0.5,BASSAZ);
		appendMartelato(bass,C,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 38 & 39
	#ifdef DEBUG
	puts("Measure # 38 & 39");
	#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		append(voice,A,octave,0.75,VOICEAZ);
		appendFour(voice,C,D,0,E,octave,0.5,VOICEAZ);
		append(voice,C,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.5,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.75,CHORDAZ);
		append(harmony,C,octave+1,0.125,CHORDAZ);
		appendChordMartelato(harmony,E,Bf,2*D,octave,0.125,CHORDAZ);
		appendTwo(harmony,0,E,octave+1,0.25,CHORDAZ);
		appendChordMartelato(harmony,E,Bf,C,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		appendFourMartelato(bass,C,0,G/2,0,octave,0.5,BASSAZ);
		append(bass,C,octave-2,0.25,BASSAZ);
		appendSilence(0.125);
		appendFourChord(bass,C,E,G,Bf,octave,0.125,BASSAZ);
		appendSilence(0.25);
		appendFourChord(bass,C,E,G,Bf,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 40 & 41
	#ifdef DEBUG
	puts("Measure # 40 & 41");
	#endif
		//VOICE
		create(voice,Db,octave,1.125,VOICEAZ);
		//HARMONY
		chord(harmony,F,A,Db,octave,1.125,CHORDAZ);
	add();
		//BASS
		create(bass,F,octave-2,0.25,BASSAZ);
		append(bass,A,octave-2,0.125,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
		append(bass,Db,octave-1,0.125,BASSAZ);
		append(bass,F,octave-1,0.25,BASSAZ);
		appendFour(bass,A,F,D,C,octave,1.0,BASSAZ);
	add();
	cat();
	mPP;
	//MEASURE # 42 & 43
	#ifdef DEBUG
	puts("Measure # 42 & 43");
	#endif
		//VOICE
		create(voice,E,octave+1,0.5,VOICEAZ);
		append(voice,D,octave+1,0.75,VOICEAZ);
		appendFour(voice,C,B/2,B/2,D,octave,0.5,VOICEAZ);
		append(voice,C,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,Af,B,E,octave,0.5,CHORDAZ);
		appendChord(harmony,F,Af,D,octave,0.75,CHORDAZ);
		append(harmony,C,octave+1,0.125,CHORDAZ);
		appendChord(harmony,F,Af,B,octave,0.25,CHORDAZ);
		append(harmony,D,octave,0.125,CHORDAZ);
		appendChord(harmony,F,Af,C,octave,0.25,CHORDAZ);

	add();
		//BASS
		create(bass,F,octave-2,0.375,BASSAZ);
		append(bass,C,octave-1,0.125,BASSAZ);
		appendThree(bass,F,C,F/2,octave-1,0.25,BASSAZ);
		append(bass,C,octave-1,0.125,BASSAZ);
		append(bass,F,octave-1,0.25,BASSAZ);
		append(bass,C,octave-1,0.125,BASSAZ);
		append(bass,F,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 44 & 45
	#ifdef DEBUG
	puts("Measure # 44 & 45");
	#endif
		//VOICE
		create(voice,A,octave,0.5,VOICEAZ);
		append(voice,G,octave,0.75,VOICEAZ);
		appendFour(voice,G,A,0,2*C,octave,0.5,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		//HARMONY
		arpegio(harmony,C,E,A,octave,0.5,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.75,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,A,octave,0.125,CHORDAZ);
		appendTwo(harmony,0,C,octave+1,0.25,CHORDAZ);
		appendChordMartelato(harmony,C,E,A,octave,0.25,CHORDAZ);

	add();
		//BASS
		create(bass,C,octave-2,0.375,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendTwo(bass,C,G/2,octave-1,0.5,BASSAZ);
		append(bass,C,octave-2,0.25,BASSAZ);
		appendFour(bass,G,2*C,0,G,octave-1,0.5,BASSAZ);
		appendMartelato(bass,C,octave-1,0.25,BASSAZ);
	add();
	cat();
	temporal=(mPP)/(MESSOFORTE);
	MESSOFORTE;
	//MEASURE # 46 & 47
	#ifdef DEBUG
	puts("Measure # 46 & 47");
	#endif
		//VOICE
		create(voice,E,octave+1,0.5,VOICEAZ);
		append(voice,D,octave,0.625,VOICEAZ);
		appendSilence(0.125);
		appendFour(voice,G,A,0,B,octave,0.5,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,Fs,C,E,octave,0.5,CHORDAZ);
		appendChord(harmony,Fs,C,D,octave,0.625,CHORDAZ);
		silence(0.125);
		append(harmony,G,octave,0.125,CHORDAZ);
		appendChord(harmony,B/2,F,A,octave,0.25,CHORDAZ);
		appendTwo(harmony,0,B,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,F,G,octave,0.25,CHORDAZ);
		CRESCENDO;
		cat();
	add();
		//BASS
		create(bass,D,octave-2,0.375,BASSAZ);
		append(bass,A,octave-2,0.125,BASSAZ);
		appendEstacato(bass,C,octave-1,0.25,BASSAZ);
		appendMarcato(bass,Af,octave-2,0.25,BASSAZ);
		appendEstacatoMartelato(bass,G,octave-2,0.125,BASSAZ);
		silence(0.25);
		appendIntervalEstacato(bass,G,2*D,octave-2,0.125,BASSAZ);
		appendSilence(0.25);
		appendIntervalEstacato(bass,G,2*D,octave-2,0.25,BASSAZ);
		cat();
	add();
	gradual(temporal,1);
	cat();

	if(!end){
	//MEASURE # 48 & 49
	#ifdef DEBUG
	puts("Measure # 48 & 49");
	#endif
		//VOICE
		create(voice,C,octave+1,1.5,VOICEAZ);
		//HARMONY
		arpegioFour(harmony,E,G,A,2*C,octave,0.25,CHORDAZ);
		appendArpegioFourMartelato(harmony,E,G,A,2*C,octave,0.125,CHORDAZ);
		appendFourChord(harmony,E,G,A,2*C,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		DECRESCENDO;
		fourChordMartelato(harmony,E,G,A,2*C,octave,0.125,CHORDAZ);
		appendFourChordEstacato(harmony,E,G,A,2*C,octave,0.25,CHORDAZ);
		DECRESCENDO;
		cat();
		appendArpegioFourEstacatoMartelato(harmony,E,G,A,2*C,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		MESSOPIANO;
		appendChordMarcato(harmony,F,A,B/2,octave,0.125,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
		appendChordMarcato(harmony,G,B,2*E,octave,0.25,CHORDAZ);
		appendChordEstacatoMartelato(harmony,F,B,2*D,octave,0.125,CHORDAZ);
		appendSilence(0.125);
	add();
		//BASS
		MESSOFORTE;
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.25);
		appendIntervalEstacato(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.25);
		CRESCENDO;
		appendIntervalEstacato(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendIntervalEstacatoMarcato(bass,C,2*C,octave-2,0.125,BASSAZ);
		MESSOPIANO;
		appendSilence(0.125);
		appendInterval(bass,G,2*D,octave-2,0.25,BASSAZ);
		appendInterval(bass,G,2*G,octave-2,0.25,BASSAZ);
		appendIntervalMartelato(bass,G,2*G,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
	add();
	cat();
	}
	else{
	//MEASURE # 50 & 51
	#ifdef DEBUG
	puts("Measure # 50 & 51");
	#endif
		//VOICE
		create(voice,C,octave+1,1+FERMATA(1.0),VOICEAZ);
		//HARMONY
		arpegioFour(harmony,E,G,A,2*C,octave,0.25,CHORDAZ);
		appendArpegioFourMartelato(harmony,E,G,A,2*C,octave,0.125,CHORDAZ);
		appendArpegioFour(harmony,E,G,A,2*C,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendFourChordMartelato(harmony,E,G,A,2*C,octave,0.125,CHORDAZ);
		appendFourChordEstacato(harmony,E,G,A,2*C,octave,0.25,CHORDAZ);
		fourChord(harmony,E,G,A,2*C,octave,FERMATA(1.0),CHORDAZ);
		create(harmony,E,octave+1,FERMATA(1.0),CHORDAZ);
		add();
		cat();
	add();
		//BASS
		MESSOFORTE;
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendChord(bass,C,G,2*C,octave-2,FERMATA(1.0),BASSAZ);
	add();
	cat();
	}
}


void song(void){
	intro();
	repeat(0);
	cat();
	repeat(1);
	cat();
}



int main(int argc, char **argv){

	tempo=110;
	eFlatKey = Ef;
	cKey = C;
	C = eFlatKey;
	song();
	echo(10,0.3,4);

	puts("Writing wav file: negra consentida.wav");
	exportToWav("Negra Consentida.wav");

}
