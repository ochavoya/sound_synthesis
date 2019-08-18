#include "soundlib.h"

#define VOICEAZ 150
#define CHORDAZ 30
#define BASSAZ 90

#define MODERATOASSAI 95
#define MOLTOMODERATO 76
#define ALLEGRO 120

#define DEBUG 1


double (*voice)(double) = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double) = oldCircleOfRa;

void intro(void);
void song(void);

short octave=0;

void intro(void){
	tempo = MODERATOASSAI;
	PIANO;
	//MEASURE # 1
	#ifdef DEBUG
	puts("Measure # 1");
	#endif
		//HARMONY
		silence(0.375);
		appendTwo(harmony,A,B,octave+1,0.125,CHORDAZ);
		//BASS
	//MEASURE # 2
	#ifdef DEBUG
	puts("Measure # 2");
	#endif
		//HARMONY
		grace(harmony,D,C,octave+2,0.125,CHORDAZ);
		appendTwo(harmony,B,A,octave+1,0.125,CHORDAZ);
		append(harmony,B,octave,0.125,CHORDAZ);
		appendTwo(harmony,A,B,octave+1,0.125,CHORDAZ);
		interval(harmony,F,2*D,octave,0.25,CHORDAZ);
		appendInterval(harmony,Fs,2*Ds,octave,0.25,CHORDAZ);
		create(harmony,A,octave,0.5,CHORDAZ);
		add();
		add();
	CRESCENDO;
	cat();

	//MEASURE # 3
	FORTE;
	#ifdef DEBUG
	puts("Measure # 3");
	#endif
		//HARMONY
		doubleGrace(harmony,A,B,A,octave+1,0.1875,CHORDAZ);
		append(harmony,G,octave,0.3125,CHORDAZ);
		addChord(harmony,G,2*C,2*E,octave,0.5,CHORDAZ);
	cat();

	//MEASURE # 4, 5 & 6
	#ifdef DEBUG
	puts("Measure # 4, 5 & 6");
	#endif
		//HARMONY
		silence(0.25);
		append(harmony,A,octave,0.1875,CHORDAZ);
		create(harmony,B,octave-1,0.0625,CHORDAZ);
		append(harmony,D,octave,0.125,CHORDAZ);
		DECRESCENDO;
		cat();
		appendChord(harmony,E/2,G/2,C,octave,0.0625,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave,0.0625,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.0625,CHORDAZ);
		chord(harmony,E,G,2*C,octave,0.0625,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave+1,0.0625,CHORDAZ);
		appendChord(harmony,C,E,G,octave+1,0.0625,CHORDAZ);
		appendFourChord(harmony,C,E,G,C,octave+1,FERMATA(0.125),CHORDAZ);
		DECRESCENDO;
		cat();


		//BASS
		fourChordMarcato(bass,G/2,D,F,B,octave-1,0.5,BASSAZ);
		silence(0.4375);
		silence(0.0625);
		appendChord(bass,C,G,2*C,octave-2,0.125,BASSAZ);
		DECRESCENDO;
		cat();
		add();
		appendThree(bass,G/2,C,E,octave-1,0.1875,BASSAZ);
		three(bass,G/2,C,E,octave,0.1875,BASSAZ);
		arpegio(bass,C,G,2*E,octave-1,FERMATA(0.125),BASSAZ);
		cat();
		DECRESCENDO;
		cat();
	add();
	appendSilence(0.375);
	cat();

}

void song(void){
	tempo=MOLTOMODERATO;
	MESSOFORTE;
	//MEASURE # 7 & 8
	#ifdef DEBUG
	puts("Measure # 7 & 8");
	#endif
		//VOICE
		create(voice,G,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.1875,VOICEAZ);
		appendThree(voice,G,G,G,octave,0.1875,VOICEAZ);
		append(voice,2*C,octave,0.1875,VOICEAZ);
		append(voice,A,octave,0.0625,VOICEAZ);
		appendTwo(voice,G,F,octave,0.25,VOICEAZ);
		//HARMONY
		fourChordMarcato(harmony,G/2,C,E,G,octave,1.0,CHORDAZ);
	add();
		//BASS
		intervalMarcato(bass,C,2*C,octave-2,1.0,BASSAZ);
	add();
	//MEASURE # 9 & 10
	#ifdef DEBUG
	puts("Measure # 9 & 10");
	#endif
		//VOICE
		create(voice,Cs,octave,0.25,VOICEAZ);
		append(voice,D,octave,0.5,VOICEAZ);
		//HARMONY
		interval(harmony,Gs,Cs,octave,0.25,CHORDAZ);
		interval(harmony,B,D,octave,0.25,CHORDAZ);
		create(harmony,F,octave-1,0.125,CHORDAZ);
		appendFour(harmony,D,F,G,B,octave-1,0.125,CHORDAZ);
		add();
		cat();
		four(harmony,D,F,G,B,octave,0.25,CHORDAZ);
		appendFour(harmony,D,F,G,A,octave+1,0.25,CHORDAZ);
		DECRESCENDO;
		cat();
		append(harmony,F,octave+2,0.125,CHORDAZ);
		appendSilence(0.125);
	add();
		//BASS
		create(bass,G,octave-2,0.5,BASSAZ);
		appendSilence(0.375);
		MESSOFORTE;
		appendInterval(bass,G,2*G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 11 & 12
	#ifdef DEBUG
	puts("Measure # 11 & 12");
	#endif
		//VOICE
		create(voice,G,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.1875,VOICEAZ);
		appendThree(voice,G,G,G,octave,0.1875,VOICEAZ);
		append(voice,2*C,octave,0.1875,VOICEAZ);
		append(voice,A,octave,0.0625,VOICEAZ);
		appendTwo(voice,G,F,octave,0.25,VOICEAZ);
		//HARMONY
		fourChordMarcato(harmony,G/2,C,E,G,octave,1.0,CHORDAZ);
	add();
		//BASS
		intervalMarcato(bass,C,2*C,octave-2,1.0,BASSAZ);
	add();
	cat();
//TESTED TILL HERE

	//MEASURE # 13 & 14
	#ifdef DEBUG
	puts("Measure # 13 & 14");
	#endif
		//VOICE
		create(voice,Cs,octave,0.1875,VOICEAZ);
		append(voice,D,octave,0.5625,VOICEAZ);
		appendSilence(0.1875);
		FORTE;
		append(voice,E,octave,0.0625,VOICEAZ);
		MESSOFORTE;
		//HARMONY
		chord(harmony,E/2,As/2,Cs,octave,0.1875,CHORDAZ);
		appendChord(harmony,F/2,B/2,D,octave,0.0625,CHORDAZ);
		appendChord(harmony,B/2,D,G,octave,0.0625,CHORDAZ);
		appendChord(harmony,D,F,B,octave,0.0625,CHORDAZ);
		appendChord(harmony,F,B,2*D,octave,0.0625,CHORDAZ);
		appendChord(harmony,D,F,B,octave+1,0.0625,CHORDAZ);
		appendInterval(harmony,G,2*G,octave,0.1875,CHORDAZ);
	add();
		//BASS
		interval(bass,G,G/2,octave-2,0.5,BASSAZ);
		appendArpegio(bass,G/2,D,F,octave,0.5,BASSAZ);
	add();
	cat();
	tempo = ALLEGRO;
	//MEASURE # 15
	#ifdef DEBUG
	puts("Measure # 15");
	#endif
		//VOICE
		create(voice,C,octave+1,0.1875,VOICEAZ);
		appendThree(voice,Gs,Gs,Gs,octave,0.1875,VOICEAZ);
		//HARMONY
		silence(0.125);
		appendFourChord(harmony,E,A,2*C,2*E,octave,0.125,CHORDAZ);
		appendFourChord(harmony,E,A,2*C,2*E,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,A,A/2,octave-1,0.125,BASSAZ);
		appendChord(bass,E,A,2*C,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 16
	#ifdef DEBUG
	puts("Measure # 16");
	#endif
		//VOICE
		create(voice,B,octave,0.1875,VOICEAZ);
		appendThree(voice,Gs,Gs,Gs,octave,0.1875,VOICEAZ);
		//HARMONY
		silence(0.125);
		appendFiveChord(harmony,E,Gf,B,2*D,2*E,octave,0.125,CHORDAZ);
		appendFiveChord(harmony,E,Gf,B,2*D,2*E,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,E,2*E,octave-2,0.125,BASSAZ);
		appendChord(bass,E,Gf,2*D,octave-1,0.125,BASSAZ);
	add();
	cat();

	//MEASURE # 17
	#ifdef DEBUG
	puts("Measure # 17");
	#endif
		//VOICE
		create(voice,G,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.375,VOICEAZ);
		appendSilence(FERMATA(0.125));
		append(voice,A,octave,0.125,VOICEAZ);
		//HARMONY
		silence(0.125);
		appendFourChord(harmony,E,A,2*C,2*E,octave,0.125,CHORDAZ);
		appendFourChord(harmony,A/2,C,E,A,octave+1,0.125,CHORDAZ);
		appendSilence(0.125);
		appendFourChord(harmony,A/2,C,E,A,octave+2,0.125,CHORDAZ);
		appendSilence(FERMATA(0.125)+0.125);
	add();
		//BASS
		interval(bass,A/2,A,octave-1,0.125,BASSAZ);
		appendChord(bass,E,A,2*C,octave-1,0.125,BASSAZ);
		appendChord(bass,A/2,C,E,octave,0.125,BASSAZ);
		appendChord(bass,C,E,A,octave,0.125,BASSAZ);
		appendSilence(FERMATA(0.125)+0.125);
	add();
	cat();
	//MEASURE # 18
	tempo = MODERATOASSAI ;
	#ifdef DEBUG
	puts("Measure # 18");
	#endif
		//VOICE
		create(voice,B,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		append(voice,Gs,octave,0.0625,VOICEAZ);
		append(voice,A,octave,0.0625,VOICEAZ);
		//HARMONY
		interval(harmony,D,2*D,octave,0.1875,CHORDAZ);
		appendInterval(harmony,Cs,2*Cs,octave,0.0625,CHORDAZ);
		appendInterval(harmony,C,2*C,octave,0.25,CHORDAZ);
		interval(harmony,F,G,octave,0.375,CHORDAZ);
		appendInterval(harmony,Db,F,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		arpegio(bass,Db,A,2*Gf,octave-2,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 19
	#ifdef DEBUG
	puts("Measure # 19");
	#endif
		//VOICE
		two(voice,B,A,octave,0.25,VOICEAZ);
		appendSilence(0.125);
		appendTwo(voice,Cs,D,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,C,Gf,B,octave,0.125,CHORDAZ);
		appendChord(harmony,C,F,A,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendTwo(harmony,Cs,D,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		append(bass,D,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 20, 21 & 22
	#ifdef DEBUG
	puts("Measure # 20, 21 & 22");
	#endif
		//VOICE
		create(voice,A,octave,0.25,VOICEAZ);
		append(voice,Af,octave,0.25,VOICEAZ);
		append(voice,G,octave,FERMATA(0.5),VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,G,A,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,As/2,E,As,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,F,B,octave,0.5,CHORDAZ);
		appendFourChord(harmony,A/2,C,E,A,octave+2,FERMATA(0.5)-0.25,CHORDAZ);
		appendTwo(harmony,G,A,octave,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,D,Cs,octave-1,0.5,BASSAZ);
		append(bass,D,octave-1,0.5,BASSAZ);
		create(bass,G,octave-2,1.0,BASSAZ);
		add();
		appendInterval(bass,G,2*D,octave,FERMATA(0.5)-0.25,BASSAZ);
	add();
	cat();
//TESTED TO THIS POINT
	//MEASURE # 23 & 24 (There were mistakes when the score was numerated)
	PIANO;
	#ifdef DEBUG
	puts("Measure # 23 & 24");
	#endif
		//VOICE
		create(voice,B,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,E/2,E,octave,0.5,CHORDAZ);
		appendInterval(harmony,Ef/2,Ef,octave,0.5,CHORDAZ);
		silence(0.25);
		interval(harmony,G/2,C,octave,0.25,CHORDAZ);
		CRESCENDO;
		appendSilence(0.25);
		cat();
		interval(harmony,G,B,octave-1,0.25,CHORDAZ);
		DECRESCENDO;
		cat();
		add();
	add();
		//BASS
		interval(bass,C,C/2,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,G,G/2,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 25 & 26
	#ifdef DEBUG
	puts("Measure # 25 & 26");
	#endif
		//VOICE
		create(voice,B,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,B,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,E,E/2,octave,0.5,CHORDAZ);
		appendInterval(harmony,G,G/2,octave,0.375,CHORDAZ);
		appendInterval(harmony,Fs,Fs/2,octave,0.125,CHORDAZ);
		silence(0.25);
		interval(harmony,G/2,C,octave,0.25,CHORDAZ);
		DECRESCENDO;
		cat();
		appendSilence(0.25);
		appendInterval(harmony,A/2,C,octave,0.25,CHORDAZ);
		add();
		silence(0.3125);
		volume/=2;
		appendThree(harmony,E,F,Gf,octave-1,0.1875,CHORDAZ);
		volume*=2;
		add();
	add();
		//BASS
		interval(bass,C,C/2,octave,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,E,E/2,octave,0.25,BASSAZ);
		appendInterval(bass,Ef,Ef/2,octave,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 27 & 28
	#ifdef DEBUG
	puts("Measure # 27 & 28");
	#endif
		//VOICE
		create(voice,A,octave,0.5,VOICEAZ);
		append(voice,B,octave-1,1.0,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,G,A,octave,0.25,VOICEAZ);
		//HARMONY
		silence(0.4375);
		append(harmony,E,octave+2,0.0625,CHORDAZ);
		appendInterval(harmony,A,2*Db,octave+1,0.1875,CHORDAZ);
		append(harmony,G,octave+2,0.0625,CHORDAZ);
		appendInterval(harmony,B,2*F,octave+1,0.1875,CHORDAZ);
		append(harmony,C,octave+2,0.0625,CHORDAZ);
		interval(harmony,F/2,F,octave,0.5,CHORDAZ);
		add();
		append(harmony,A,octave+1,0.125,CHORDAZ);
		appendChord(harmony,Db,F,A,octave+2,0.25,CHORDAZ);
		append(harmony,Bf,octave+1,0.125,CHORDAZ);
		appendChord(harmony,B/2,F,G,octave+2,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,D,D/2,octave-1,0.25,BASSAZ);
		chord(bass,G,B,2*F,octave-1,0.25,BASSAZ);
		DECRESCENDO;
		cat();
		appendInterval(bass,G,G/2,octave-2,0.25,BASSAZ);
		appendChord(bass,G,B,2*F,octave-1,0.25,BASSAZ);
		appendInterval(bass,D,D/2,octave-1,0.25,BASSAZ);
		appendChord(bass,G,B,2*F,octave-1,0.25,BASSAZ);
		appendInterval(bass,G,G/2,octave-2,0.25,BASSAZ);
		appendChord(bass,G,B,2*F,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 29
	#ifdef DEBUG
	puts("Measure # 29");
	#endif
		//VOICE
		create(voice,B,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		appendTwo(voice,G,A,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,F,F/2,octave,0.75,CHORDAZ);
		silence(0.25);
		interval(harmony,G,B,octave-1,0.25,CHORDAZ);
		CRESCENDO;
		cat();
		appendSilence(0.25);
		chord(harmony,G,B,2*F,octave-1,0.25,CHORDAZ);
		DECRESCENDO;
		cat();
		add();
	add();
		//BASS
		interval(bass,Db,Db/2,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,G,G/2,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 30
	#ifdef DEBUG
	puts("Measure # 30");
	#endif
		//VOICE
		create(voice,B,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		appendTwo(voice,G,B,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,F,F/2,octave,0.75,CHORDAZ);
		silence(0.25);
		interval(harmony,G,B,octave-1,0.25,CHORDAZ);
		CRESCENDO;
		cat();
		appendSilence(0.25);
		appendFourChord(harmony,Ds,G,B,2*Ds/2,octave-1,0.25,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,Db,Db/2,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,G,G/2,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 31 & 32
	#ifdef DEBUG
	puts("Measure # 31 & 32");
	#endif
		//VOICE
		create(voice,A,octave,0.5,VOICEAZ);
		append(voice,E,octave,1.0,VOICEAZ);
		appendSilence(0.5);
		appendTwo(voice,E,F,octave,0.25,VOICEAZ);
		//HARMONY
		fourChord(harmony,E/2,G/2,C,E,octave,0.25,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave,0.25,CHORDAZ);
		appendSilence(0.1875);
		append(harmony,E,octave+2,0.0625,CHORDAZ);
		appendInterval(harmony,E,B,octave,0.1875,CHORDAZ);
		append(harmony,E,octave+2,0.0625,CHORDAZ);
	add();
		//BASS
		interval(bass,C,C/2,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,G,G/2,octave-2,0.25,BASSAZ);
		appendChord(bass,G/2,C,E,octave,0.25,BASSAZ);
		appendArpegio(bass,C,G,2*E,octave-2,0.25,BASSAZ);
		appendChord(bass,G/2,C,E,octave,0.25,BASSAZ);
		appendInterval(bass,G,G/2,octave-2,0.25,BASSAZ);
		appendChord(bass,G/2,C,E,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 33
	#ifdef DEBUG
	puts("Measure # 33");
	#endif
		//VOICE
		create(voice,G,octave,0.125,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		appendTwo(voice,E,F,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,Bf/2,D,G,octave,0.0625,CHORDAZ);
		appendSilence(0.0625);
		appendChord(harmony,Bf/2,D,G,octave,0.0625,CHORDAZ);
		appendSilence(0.0625);
		appendChord(harmony,A/2,Cs,G,octave,0.0625,CHORDAZ);
		appendSilence(0.0625);
		appendChord(harmony,A/2,Cs,G,octave,0.0625,CHORDAZ);
	add();
		//BASS
		four(bass,E,0,E,0,octave-1,0.25,BASSAZ);
		addFour(bass,E,0,E,0,octave-2,0.25,BASSAZ);
		four(bass,A,0,A,0,octave-2,0.25,BASSAZ);
		addFour(bass,A,0,A,0,octave-3,0.25,BASSAZ);
		cat();
	add();
	cat();
	//MEASURE # 34
	#ifdef DEBUG
	puts("Measure # 34");
	#endif
		//VOICE
		create(voice,G,octave,0.125,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		appendTwo(voice,E,A,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,Bf/2,D,G,octave,0.125,CHORDAZ);
		appendSilence(0.0625);
		appendChord(harmony,Bf/2,D,G,octave,0.125,CHORDAZ);
		appendFourChordMarcato(harmony,A/2,Cs,E,A,octave,0.25,CHORDAZ);
		appendChord(harmony,Cs,E,A,octave,0.125,CHORDAZ);
		append(harmony,A,octave-1,0.25,CHORDAZ);
	add();
		//BASS
		four(bass,E,0,E,0,octave-1,0.25,BASSAZ);
		addFour(bass,E,0,E,0,octave-2,0.25,BASSAZ);
		four(bass,A,0,A,0,octave-2,0.25,BASSAZ);
		addFour(bass,A,0,A,0,octave-3,0.25,BASSAZ);
		cat();
	add();
	cat();
	//MEASURE # 35 & 36
	#ifdef DEBUG
	puts("Measure # 35 & 36");
	#endif
		//VOICE
		create(voice,E,octave,0.5,VOICEAZ);
		append(voice,Db,octave,1.0,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,A,B,octave,0.25,VOICEAZ);
		//HARMONY
		silence(0.1875);
		append(harmony,E,octave,0.0625,CHORDAZ);
		appendInterval(harmony,A,2*E,octave,0.1875,CHORDAZ);
		append(harmony,F,octave,0.0625,CHORDAZ);
		appendInterval(harmony,A,2*E,octave,0.125,CHORDAZ);
		appendChord(harmony,F,A,Ef,octave,0.25,CHORDAZ);
		appendChord(harmony,F,A,2*Db,octave,0.25,CHORDAZ);
		appendThree(harmony,A/2,A,F,octave,0.25,CHORDAZ);
		appendInterval(harmony,Db,F,octave,0.1875,CHORDAZ);
		create(harmony,A,octave-1,0.0625,CHORDAZ);
		appendChord(harmony,Db,F,A,octave,0.25,CHORDAZ);
		CRESCENDO;
		cat();
	add();
		//BASS
		interval(bass,Db,A,octave-2,0.25,BASSAZ);
		appendChord(bass,F,A,2*Db,octave-1,0.25,BASSAZ);
		appendInterval(bass,A,A/2,octave-2,0.25,BASSAZ);
		appendInterval(bass,F,A,octave-1,0.25,BASSAZ);
		append(bass,Db,octave-2,0.25,BASSAZ);
		appendInterval(bass,A,2*Db,octave-2,0.25,BASSAZ);
		append(bass,A,octave-3,0.25,BASSAZ);
		append(bass,A,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 37
	FORTE;
	#ifdef DEBUG
	puts("Measure # 37");
	#endif
		//VOICE
		create(voice,C,octave+1,0.125,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		append(voice,C,octave+1,0.25,VOICEAZ);
		appendTwo(voice,Gf,G,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,Gf,Gf/2,octave,1.0,CHORDAZ);
		silence(0.25);
		sixEstacato(harmony,D,0,D,0,D,0,octave,0.75,CHORDAZ);
		sixEstacato(harmony,C,0,C,0,C,0,octave,0.75,CHORDAZ);
		add();
		cat();
		add();
	add();
		//BASS
		fourEstacato(bass,A,0,A,0,octave-2,0.25,BASSAZ);
		fourEstacato(bass,A,0,A,0,octave-3,0.25,BASSAZ);
		add();
		fourEstacato(bass,A,0,A,0,octave-2,0.25,BASSAZ);
		fourEstacato(bass,A,0,A,0,octave-3,0.25,BASSAZ);
		add();
		cat();
	add();
	cat();

	//MEASURE # 38
	#ifdef DEBUG
	puts("Measure # 38");
	#endif
		//VOICE
		create(voice,A,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		append(voice,Gf,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		appendTwo(voice,Cs,D,octave,0.25,VOICEAZ);
		//HARMONY
		create(harmony,C,octave+1,1.0,CHORDAZ);
		create(harmony,C,octave,0.25,CHORDAZ);
		add();
		silence(0.0625);
		append(harmony,Gf,octave,0.0625,CHORDAZ);
		appendSilence(0.0625);
		appendInterval(harmony,Gf,A,octave,0.0625,CHORDAZ);
		appendSilence(0.0625);
		appendChord(harmony,C,Gf,A,octave,0.0625,CHORDAZ);
		appendSilence(0.0625);
		appendChord(harmony,C,Gf,A,octave,0.0625,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,A,octave-2,0.25,BASSAZ);
		appendChord(bass,D,Gf,2*C,octave-1,0.25,BASSAZ);
		appendInterval(bass,D,D/2,octave-1,0.25,BASSAZ);
		append(bass,D,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 39 & 40
	#ifdef DEBUG
	puts("Measure # 39 & 40");
	#endif
		//VOICE
		create(voice,A,octave,0.5,VOICEAZ);
		appendDoubleGrace(voice,G,A,G,octave,1.0,VOICEAZ);
		appendSilence(0.25);
		PIANO;
		appendTwo(voice,G,A,octave,0.25,VOICEAZ);
		FORTE;
		//HARMONY
		fourChord(harmony,A/2,Db,F,A,octave,0.25,CHORDAZ);
		appendFourChord(harmony,As/2,Db,F,As,octave,0.125,CHORDAZ);
		appendInterval(harmony,B/2,B,octave,0.3125,CHORDAZ);
		append(harmony,G,octave+1,0.0625,CHORDAZ);
		appendInterval(harmony,B,2*E,octave,0.1875,CHORDAZ);
		append(harmony,G,octave+1,0.0625,CHORDAZ);
		appendChord(harmony,G,B,2*E,octave,0.25,CHORDAZ);
		chord(harmony,Fs,As,2*Ds,octave,0.125,CHORDAZ);
		appendChord(harmony,F,A,2*Db,octave,0.25,CHORDAZ);
		append(harmony,G,octave+2,0.125,CHORDAZ);
		DECRESCENDO;
		cat();
		PIANO;
		append(harmony,G,octave+1,0.25,CHORDAZ);
		FORTE;
	add();
		//BASS
		create(bass,D,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		create(bass,G,octave-2,0.5,BASSAZ);
		add();
		appendInterval(bass,G,G/2,octave,0.25,BASSAZ);
		appendChord(bass,G,B,2*F,octave,0.25,BASSAZ);
		interval(bass,As,2*As,octave-2,0.25,BASSAZ);
		appendChord(bass,G,2*D,2*B,octave-2,0.25,BASSAZ);
		appendInterval(bass,B,2*B,octave-2,0.25,BASSAZ);
		DECRESCENDO;
		cat();
		PIANO;
		appendInterval(bass,G,2*G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 41
	#ifdef DEBUG
	puts("Measure # 41");
	#endif
		//VOICE
		create(voice,B,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		appendTwo(voice,G,A,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,E,2*E,octave-1,0.5,CHORDAZ);
		appendInterval(harmony,Ds,2*Ds,octave-1,0.5,CHORDAZ);
		silence(0.25);
		interval(harmony,G/2,C,octave,0.25,CHORDAZ);
		CRESCENDO;
		cat();
		appendInterval(harmony,G,B,octave-1,0.25,CHORDAZ);
		interval(harmony,G,B,octave-1,0.25,CHORDAZ);
		DECRESCENDO;
		cat();
		add();
	add();
		//BASS
		interval(bass,C,C/2,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,G,G/2,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 42, 43 & 44
	#ifdef DEBUG
	puts("Measure #42 43 & 44");
	#endif
		//VOICE
		create(voice,B,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		appendTwo(voice,G,B,octave,0.25,VOICEAZ);
		append(voice,A,octave,0.5,VOICEAZ);
		append(voice,B,octave-1,1.0,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,G,A,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,E/2,E,octave,0.5,CHORDAZ);
		silence(0.25);
		interval(harmony,G/2,C,octave,0.25,CHORDAZ);
		CRESCENDO;
		cat();
		add();
		appendFourChord(harmony,G/2,C,E,G,octave,0.25,CHORDAZ);
		appendInterval(harmony,Fs/2,Fs,octave,0.125,CHORDAZ);
		appendChord(harmony,F/2,C,F,octave,0.375,CHORDAZ);
		appendSilence(0.1875);
		append(harmony,G,octave,0.0625,CHORDAZ);
		appendChord(harmony,B,2*F,2*G,octave,0.125,CHORDAZ);
		appendChord(harmony,B,2*F,2*G,octave,0.25,CHORDAZ);
		append(harmony,G,octave+1,0.125,CHORDAZ);
		appendChord(harmony,B,2*F,2*G,octave+1,0.25,CHORDAZ);
		appendSilence(0.5);
		appendChord(harmony,G/2,C,G,octave,0.1875,CHORDAZ);
		appendInterval(harmony,Gf/2,Gf,octave,0.0625,CHORDAZ);
	add();
		//BASS
		interval(bass,C/2,C,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,E/2,E,octave-1,0.25,BASSAZ);
		appendInterval(bass,Ef/2,Ef,octave-1,0.25,BASSAZ);
		appendInterval(bass,D/2,D,octave-1,0.25,BASSAZ);
		appendChord(bass,G,B,2*D,octave-1,0.25,BASSAZ);
		appendInterval(bass,G/2,G,octave-2,0.25,BASSAZ);
		appendChord(bass,G,B,2*D,octave-1,0.25,BASSAZ);
		appendInterval(bass,D/2,D,octave-1,0.25,BASSAZ);
		appendChord(bass,G,B,2*D,octave-1,0.25,BASSAZ);
		appendInterval(bass,G/2,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 45
	#ifdef DEBUG
	puts("Measure # 45");
	#endif
		//VOICE
		create(voice,B,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		appendTwo(voice,G,A,octave,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,F/2,F,octave,0.75,CHORDAZ);
		silence(0.25);
		appendChord(harmony,G,B,2*D,octave-1,0.25,CHORDAZ);
		appendSilence(0.25);
		appendFourChord(harmony,F,B,2*D,2*G,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,D/2,D,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,G/2,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 46, 47 & 48
	#ifdef DEBUG
	puts("Measure # 46");
	#endif
		//VOICE
		create(voice,G,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		appendTwo(voice,G,A,octave,0.25,VOICEAZ);
		append(voice,A,octave,0.5,VOICEAZ);
		append(voice,E,octave,1.0,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,E,F,octave,0.25,VOICEAZ);
		//HARMONY
		silence(0.25);
		appendFourChord(harmony,B/2,F,G,B,octave,0.25,CHORDAZ);
		appendChord(harmony,D,G,2*D,octave,0.125,CHORDAZ);
		appendChord(harmony,Ds,G,2*Ds,octave,0.125,CHORDAZ);
		appendFourChord(harmony,E,G,2*C,2*E,octave,0.375,CHORDAZ);
		appendSilence(0.4375);
		append(harmony,E,octave+2,0.0625,CHORDAZ);
		appendInterval(harmony,E,B,octave+1,0.1875,CHORDAZ);
		append(harmony,E,octave+2,0.0625,CHORDAZ);
		appendInterval(harmony,E,B,octave+1,0.25,CHORDAZ);
		appendChord(harmony,Bf/2,E,Bf,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,A/2,C,E,A,octave,0.375,CHORDAZ);
	add();
		//BASS
		interval(bass,D/2,D,octave-1,0.25,BASSAZ);
		appendSilence(0.25);
		appendInterval(bass,G/2,G,octave-2,0.25,BASSAZ);
		appendChord(bass,F,G,B,octave-1,0.25,BASSAZ);
		appendInterval(bass,C/2,C,octave-1,0.25,BASSAZ);
		appendChord(bass,G/2,C,E,octave,0.25,BASSAZ);
		appendInterval(bass,G/2,G,octave,0.25,BASSAZ);
		appendChord(bass,G/2,C,E,octave,0.25,BASSAZ);
		appendInterval(bass,C/2,C,octave-1,0.25,BASSAZ);
		appendChord(bass,G/2,C,E,octave,0.25,BASSAZ);
		appendInterval(bass,G/2,G,octave-2,0.25,BASSAZ);
		appendChord(bass,E,G,2*C,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 49
	#ifdef DEBUG
	puts("Measure # 49");
	#endif
		//VOICE
		create(voice,G,octave,0.125,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);
		append(voice,G,octave,0.25,VOICEAZ);
		appendTwo(voice,G,A,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,Bf/2,D,G,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,Bf/2,D,G,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,A/2,Cs,G,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,A/2,Cs,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,E/2,E,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,E/2,E,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,A/2,A,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,A/2,A,octave,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 50
	#ifdef DEBUG
	puts("Measure # 50");
	#endif
		//VOICE
		create(voice,Bf,octave,0.125,VOICEAZ);
		append(voice,A,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		append(voice,Cs,octave+1,0.25,VOICEAZ);
		appendTwo(voice,A,A,octave,0.25,VOICEAZ);
		//HARMONY
		chord(harmony,Bf/2,D,G,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,Bf/2,D,G,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,A/2,Cs,G,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,A/2,Cs,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,E/2,E,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,E/2,E,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,A/2,A,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,A/2,A,octave,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 51 & 52
	#ifdef DEBUG
	puts("Measure # 51 & 52");
	#endif
		//VOICE
		create(voice,G,octave,0.5,VOICEAZ);
		append(voice,F,octave,1.0,VOICEAZ);
		appendSilence(0.25);
		appendTwo(voice,A,B,octave,0.25,VOICEAZ);
		//HARMONY
		silence(0.1875);
		append(harmony,A,octave-1,0.0625,CHORDAZ);
		appendInterval(harmony,C,A,octave,0.1875,CHORDAZ);
		append(harmony,A,octave,0.0625,CHORDAZ);
		appendInterval(harmony,D,A,octave,0.1875,CHORDAZ);
		append(harmony,A,octave,0.0625,CHORDAZ);
		append(harmony,D,octave+1,0.1875,CHORDAZ);
		appendInterval(harmony,F,A,octave,0.1875,CHORDAZ);
		appendChord(harmony,Db,F,A,octave+1,0.125,CHORDAZ);
		create(harmony,A,octave,0.25,CHORDAZ);
		appendSilence(0.25);
		CRESCENDO;
		cat();
	add();
		//BASS
		interval(bass,Db,A,octave-2,0.25,BASSAZ);
		append(bass,A,octave-1,0.25,BASSAZ);
		append(bass,A,octave-2,0.25,BASSAZ);
		appendChord(bass,F,A,Db,octave-1,0.25,BASSAZ);
		appendInterval(bass,Db/2,Db,octave-1,0.25,BASSAZ);
		chord(bass,F,A,2*Db,octave-1,0.25,BASSAZ);
		appendInterval(bass,A/2,A,octave,0.25,BASSAZ);
		appendChord(bass,F,A,2*Db,octave-1,0.25,BASSAZ);
		CRESCENDO;
		cat();
	add();
	cat();
//TESTED TILL HERE
	//MEASURE # 53
	FORTE;
	#ifdef DEBUG
	puts("Measure # 53");
	#endif
		//VOICE
		create(voice,C,octave+1,0.125,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ);
		appendTwo(voice,A,B,octave,0.25,VOICEAZ);
		appendThree(voice,A,B,2*C,octave,0.375,VOICEAZ);
		//HARMONY
		chord(harmony,A/2,C,Ds,octave,1.0,CHORDAZ);
	add();
		//BASS
		interval(bass,Fs,2*Fs,octave-2,1.0,BASSAZ);
	add();
	cat();
	//MEASURE # 54 & 55
	#ifdef DEBUG
	puts("Measure # 54 & 55");
	#endif
		//VOICE
		create(voice,A,octave,0.5,VOICEAZ);
		append(voice,G,octave,1.0,VOICEAZ);
		append(voice,A,octave,0.375,VOICEAZ);
		append(voice,B,octave-1,0.125,VOICEAZ);
		//HARMONY
		fourChord(harmony,A/2,C,E,A,octave,0.375,CHORDAZ);
		append(harmony,G,octave-1,0.125,CHORDAZ);
		appendFour(harmony,C,E,G,2*C,octave,0.25,CHORDAZ);
		appendFour(harmony,E,G,2*C,2*E,octave+1,0.25,CHORDAZ);
		create(harmony,G,octave+1,0.25,CHORDAZ);
		silence(0.0625);
		append(harmony,G,octave+2,0.1875,CHORDAZ);
		add();
		cat();
		appendSilence(0.25);
		appendChord(harmony,B/2,F,A,octave,0.375,CHORDAZ);
		appendInterval(harmony,B/2,B,octave,0.125,CHORDAZ);
	add();
		//BASS
		fourChord(bass,G/2,C,E,G,octave-1,1.0,BASSAZ);
		arpegioFour(bass,G/2,C,E,G,octave,0.25,BASSAZ);
		cat();
		appendSilence(0.25);
		appendChord(bass,G/2,C,E,octave,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 55 & 56
	#ifdef DEBUG
	puts("Measure #55 & 56");
	#endif
		//VOICE
		create(voice,D,octave,0.25,VOICEAZ);
		append(voice,C,octave,1.25,VOICEAZ);
		//HARMONY
		create(harmony,D,octave,0.25,CHORDAZ);
		appendFourChord(harmony,G/2,C,E,G,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,Gs,2*Gs,octave,0.125,CHORDAZ);
		appendInterval(harmony,A,2*A,octave,0.125,CHORDAZ);
		appendInterval(harmony,A,2*A,octave,0.25,CHORDAZ);
		appendChord(harmony,G,Ds,2*G,octave,0.125,CHORDAZ);
		appendChord(harmony,A/2,2*E,A,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,G,2*G,octave,0.125,CHORDAZ);
		appendChordMarcato(harmony,A/2,Ds,A,octave+1,0.25,CHORDAZ);
		appendChordMarcato(harmony,C,E,2*C,octave+1,1.0,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave+1,0.25,BASSAZ);
		appendIntervalMarcato(bass,G,2*G,octave-2,0.25,BASSAZ);
		appendIntervalMarcato(bass,C,2*C,octave-2,1.0,BASSAZ);
	add();
	cat();
}


int main(int argc, char **argv){
	dampingTime=0.75;
	intro();
	song();
	cat();
	echo(10,0.3,4);
    appendSilence(2);
	puts("Writing wav file: hastio.wav");
	exportToWav("Hastío.wav");
}
