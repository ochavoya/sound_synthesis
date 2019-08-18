#include "soundlib.h"

#define VOICEAZ 150
#define CHORDAZ 30
#define BASSAZ 90


#define DEBUG 1


double (*voice)(double) = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double) = oldCircleOfRa;


short octave = 0;

void intro(void){
	MESSOFORTE;
	//MEASURE # 1
		#ifdef DEBUG
		puts("Measure # 1");
		#endif
		//VOICE
		//HARMONY
		six(harmony,B,G,B,G,B,2*D,octave,0.75,CHORDAZ);
		addSix(harmony,F,0,F,0,F,0,octave,0.75,CHORDAZ);
		//BASS
		three(bass,D,G,D/2,octave,0.75,BASSAZ);
	add();
	//MEASURE # 2
		#ifdef DEBUG
		puts("Measure # 2");
		#endif
		//VOICE
		//HARMONY
		chord(harmony,A,B,2*F,octave,0.25,CHORDAZ);
		appendChord(harmony,F,B,2*D,octave,0.5,CHORDAZ);
		//BASS
		three(bass,D,G,D/2,octave,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 3
		#ifdef DEBUG
		puts("Measure # 3");
		#endif
		//VOICE
		//HARMONY
		six(harmony,G,A,G,F,E,D,octave+1,0.75,CHORDAZ);
		interval(harmony,B/2,F,octave+1,0.25,CHORDAZ);
		four(harmony,D,C,B/2,B/2,octave+1,0.5,CHORDAZ);
		addFour(harmony,B,A,G,F,octave+1,0.5,CHORDAZ);
		cat();
		add();
		//BASS
		three(bass,D,D/2,D,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 4
		#ifdef DEBUG
		puts("Measure # 4");
		#endif
		//VOICE
		silence(0.375);
		appendThree(voice,G,G,G,octave,0.375,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.25,CHORDAZ);	
		appendSilence(0.125);
		three(harmony,G,G,G,octave,0.375,CHORDAZ);
		addThree(harmony,B/2,C,D,octave,0.375,CHORDAZ);
		cat();
	add();
		//BASS
		create(bass,C,octave-1,0.25,BASSAZ);
		appendMarcato(bass,G,octave-1,0.125,BASSAZ);
		appendThree(bass,G,A,B,octave-1,0.375,BASSAZ);
	add();
	cat();
}

void repeat(short end){

	PIANO;

	//MEASURE # 5
		#ifdef DEBUG
		puts("Measure # 5");
		#endif
		//VOICE
		create(voice,C,octave+1,0.25,VOICEAZ);
		appendFour(voice,2*E,G,G,G,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,F,G,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,F,octave,0.125,CHORDAZ);
		appendInterval(harmony,D,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave,0.25,BASSAZ);
		appendFour(bass,G/2,E,D,C,octave,0.5,BASSAZ);
	add();
	//MEASURE # 6
		#ifdef DEBUG
		puts("Measure # 6");
		#endif
		//VOICE
		create(voice,C,octave+1,0.25,VOICEAZ);
		append(voice,E,octave+1,0.5,VOICEAZ);
		//HARMONY
		silence(0.25);
		append(harmony,E,octave+1,0.5,CHORDAZ);
		chord(harmony,E,G,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,C,2*C,octave-1,0.25,BASSAZ);
		appendSilence(0.125);
		appendMarcato(bass,G,octave-1,0.125,BASSAZ);
		appendMarcato(bass,G,octave-1,0.125,BASSAZ);
		appendMarcato(bass,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 7
		#ifdef DEBUG
		puts("Measure # 7");
		#endif
		//VOICE
		six(voice,2*C,2*C,B,B,A,A,octave,0.75,VOICEAZ);
		//HARMONY
		six(harmony,2*C,2*C,B,B,A,A,octave,0.75,CHORDAZ);
		interval(harmony,E,G,octave,0.25,CHORDAZ);
		appendInterval(harmony,C,G,octave,0.25,CHORDAZ);
		appendInterval(harmony,C,Gf,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,C,G,octave-1,0.25,BASSAZ);
		append(bass,E,octave-1,0.25,BASSAZ);
		append(bass,Ef,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 8
		#ifdef DEBUG
		puts("Measure # 8");
		#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		appendThree(voice,G,G,G,octave,0.375,VOICEAZ);
		//HARMONY
		create(harmony,G,octave,0.375,CHORDAZ);
		appendThree(harmony,G,G,G,octave,0.375,CHORDAZ);
		interval(harmony,B/2,F,octave,0.375,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,D,octave-1,0.25,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 9
		#ifdef DEBUG
		puts("Measure # 9");
		#endif
		//VOICE
		create(voice,B,octave,0.25,VOICEAZ);
		appendFour(voice,2*D,G,G,G,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,F,G,B,octave,0.25,CHORDAZ);
		appendChord(harmony,F,B,2*D,octave,0.125,CHORDAZ);
		appendThree(harmony,G,G,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		create(bass,D,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 10
		#ifdef DEBUG
		puts("Measure # 10");
		#endif
		//VOICE
		create(voice,B,octave,0.25,VOICEAZ);
		append(voice,D,octave+1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,F,G,B,octave,0.25,CHORDAZ);
		appendChord(harmony,F,B,2*D,octave,0.5,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-2,0.25,BASSAZ);
		appendFourMarcato(bass,0,G,G,G,octave-1,0.5,BASSAZ);
	add();
	cat();

	//MEASURE # 11
		#ifdef DEBUG
		puts("Measure # 11");
		#endif
		//VOICE
		six(voice,G,A,G,F,E,D,octave+1,0.75,VOICEAZ);
		//HARMONY
		six(harmony,G,A,G,F,E,D,octave+1,0.75,CHORDAZ);
		interval(harmony,B,2*F,octave,0.25,CHORDAZ);
		four(harmony,2*D,2*C,B,B,octave,0.5,CHORDAZ);
		addFour(harmony,B,A,G,F,octave,0.5,CHORDAZ);
		cat();
		add();
	add();
		//BASS
		three(bass,G,G/2,G,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 12
		#ifdef DEBUG
		puts("Measure # 12");
		#endif
		//VOICE
		create(voice,C,octave+1,0.25,VOICEAZ);
		appendFour(voice,0,G,G,G,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,C,octave,0.25,CHORDAZ);
		appendFour(harmony,0,G,G,G,octave,0.5,CHORDAZ);
	add();
		//BASS
		interval(bass,C,G,octave-1,0.25,BASSAZ);
		appendMarcato(bass,C,octave-1,0.125,BASSAZ);
	add();
	cat();

	//MEASURE # 13
		#ifdef DEBUG
		puts("Measure # 13");
		#endif
		//VOICE
		create(voice,C,octave+1,0.25,VOICEAZ);
		appendFour(voice,2*E,G,G,G,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave+1,0.125,CHORDAZ);
		appendThree(harmony,G,G,G,octave,0.375,CHORDAZ);
	add();		
		//BASS
		three(bass,C,G,G/2,octave-1,0.375,BASSAZ);
	add();
	cat();

	//MEASURE # 14
		#ifdef DEBUG
		puts("Measure # 14");
		#endif
		//VOICE
		create(voice,C,octave+1,0.25,VOICEAZ);
		append(voice,E,octave+1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave+1,0.5,CHORDAZ);
	add();
		//BASS
		six(bass,C,G,G/2,C,E,G,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 15
		#ifdef DEBUG
		puts("Measure # 15");
		#endif
		//VOICE
		six(voice,2*C,2*C,B,B,A,A,octave,0.75,VOICEAZ);
		//HARMONY
		six(harmony,2*C,2*C,B,B,A,A,octave,0.75,CHORDAZ);
		addSix(harmony,G,G,G,G,Gf,Gf,octave,0.75,CHORDAZ);
		two(harmony,E,E,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		three(bass,G,E,Ef,octave,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 16
		#ifdef DEBUG
		puts("Measure # 16");
		#endif
		//VOICE
		create(voice,G,octave,0.375,VOICEAZ);
		appendThree(voice,G,G,G,octave,0.375,VOICEAZ);
		//HARMONY
		interval(harmony,F,G,octave,0.375,CHORDAZ);
		appendThree(harmony,G,G,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		three(bass,D,G,G/2,octave-1,0.375,BASSAZ);
	add();
	cat();

	//MEASURE # 17
		//VOICE
		#ifdef DEBUG
		puts("Measure # 17");
		#endif
		create(voice,B,octave,0.25,VOICEAZ);
		appendFour(voice,2*D,G,G,G,octave,0.5,VOICEAZ);
		//HARMONY
		interval(harmony,F,B,octave,0.25,CHORDAZ);
		appendChord(harmony,F,B,2*D,octave,0.125,CHORDAZ);
		appendThree(harmony,G,G,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		three(bass,D,G,G/2,octave-1,0.375,BASSAZ);
	add();
	cat();

	//MEASURE # 18
		#ifdef DEBUG
		puts("Measure # 18");
		#endif
		//VOICE
		create(voice,B,octave,0.25,VOICEAZ);
		append(voice,D,octave+1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,F,G,B,octave,0.25,CHORDAZ);
		appendChord(harmony,F,B,2*D,octave,0.5,CHORDAZ);
	add();
		//BASS
		six(bass,D,G,G/2,B,D,G,octave-1,0.75,BASSAZ);
	add();
	cat();

	//MEASURE # 19
		#ifdef DEBUG
		puts("Measure # 19");
		#endif
		//VOICE
		six(voice,G,A,G,F,E,D,octave,0.75,VOICEAZ);
		//HARMONY
		six(harmony,G,A,G,F,E,D,octave+1,0.75,CHORDAZ);
		addSix(harmony,B,2*C,B,A,G,F,octave,0.75,CHORDAZ);
	add();
		//BASS
		three(bass,D,G,G/2,octave,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 20
		#ifdef DEBUG
		puts("Measure # 20");
		#endif
		//VOICE
		create(voice,C,octave+1,0.5,VOICEAZ);
		appendSilence(0.25);
		//HARMONY
		interval(harmony,E,2*C,octave,0.5,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave-1,0.25,BASSAZ);
		appendMarcato(bass,C,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 21
		MESSOFORTE;
		#ifdef DEBUG
		puts("Measure # 21");
		#endif
		//VOICE
		six(voice,C,G/2,C,G/2,C,E,octave+1,0.75,VOICEAZ);
		//HARMONY
		six(harmony,C,G/2,C,G/2,C,E,octave+1,0.75,CHORDAZ);
		addSix(harmony,E,0,E,0,E,0,octave,0.75,CHORDAZ);
	add();
		//BASS
		three(bass,C,G,2*C,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 22
		#ifdef DEBUG
		puts("Measure # 22");
		#endif
		//VOICE
		create(voice,G,octave+1,0.25,VOICEAZ);
		append(voice,E,octave+1,0.5,VOICEAZ);
		//HARMONY
		interval(harmony,C,G,octave,0.25,CHORDAZ);
		appendInterval(harmony,G/2,E,octave,0.5,CHORDAZ);
		silence(0.25);
		appendTwo(harmony,C,D,octave+1,0.5,CHORDAZ);
		add();
	add();
		//BASS
		three(bass,C,2*C,Bf,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 23
		#ifdef DEBUG
		puts("Measure # 23");
		#endif
		//VOICE
		six(voice,G,A,G,F,E,G,octave+1,0.75,VOICEAZ);		
		//HARMONY
		six(harmony,G,A,G,F,E,G,octave+1,0.75,CHORDAZ);
		interval(harmony,A,2*Cs,octave,0.5,CHORDAZ);
		appendInterval(harmony,G,2*Cs,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,A,octave-1,0.5,BASSAZ);
		append(bass,A,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 24
		#ifdef DEBUG
		puts("Measure # 24");
		#endif
		//VOICE
		create(voice,F,octave+1,0.25,VOICEAZ);
		append(voice,Db,octave+1,0.5,VOICEAZ);
		//HARMONY
		create(harmony,F,octave+1,0.25,CHORDAZ);
		append(harmony,Db,octave+1,0.5,CHORDAZ);
		three(harmony,Db,A/2,C,octave+1,0.75,CHORDAZ);
		addThree(harmony,A,F,F,octave,0.75,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,Db,octave-1,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 25
		#ifdef DEBUG
		puts("Measure # 25");
		#endif
		//VOICE
		six(voice,B,G,B,G,B,2*D,octave,0.75,VOICEAZ);
		//HARMONY
		six(harmony,B,G,B,G,B,2*D,octave,0.75,CHORDAZ);
		addSix(harmony,F,0,F,0,F,0,octave,0.75,CHORDAZ);
	add();
		//BASS
		three(bass,D,G,2*D,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 26
		#ifdef DEBUG
		puts("Measure # 26");
		#endif
		//VOICE
		create(voice,F,octave+1,0.25,VOICEAZ);
		append(voice,Db,octave+1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,F,G,2*F,octave,0.25,CHORDAZ);
		appendChord(harmony,F,B,2*Db,octave,0.5,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-1,0.5,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 27
		#ifdef DEBUG
		puts("Measure # 27");
		#endif
		//VOICE
		six(voice,G,A,G,F,E,D,octave+1,0.75,VOICEAZ);
		//HARMONY
		six(harmony,G,A,G,F,E,D,octave+1,0.75,CHORDAZ);
		interval(harmony,B,2*F,octave,0.25,CHORDAZ);
		four(harmony,D,G,B/2,B/2,octave+1,0.5,CHORDAZ);
		addFour(harmony,B,A,G,F,octave,0.5,CHORDAZ);
		cat();
		add();
	add();
		//BASS
		three(bass,G,G/2,G,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 28
		#ifdef DEBUG
		puts("Measure # 28");
		#endif
		//VOICE
		two(voice,E,C,octave+1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,G/2,C,E,octave+1,0.25,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave,0.25,CHORDAZ);
	add();
		//BASS
		two(bass,C,2*C,octave-1,0.5,BASSAZ);
		appendMarcato(bass,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 29
		#ifdef DEBUG
		puts("Measure # 29");
		#endif
		//VOICE
		six(voice,C,G/2,C,G/2,C,E,octave+1,0.75,VOICEAZ);
		//HARMONY
		chord(harmony,C,E,2*C,octave+1,0.125,CHORDAZ);
		append(harmony,G,octave+1,0.125,CHORDAZ);
		appendChord(harmony,C,E,2*C,octave+1,0.125,CHORDAZ);
		append(harmony,G,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,C,E,G,2*C,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,E,2*E,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendChord(bass,G/2,C,E,octave,0.25,BASSAZ);
		appendChord(bass,G/2,C,E,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 30
		#ifdef DEBUG
		puts("Measure # 30");
		#endif
		//VOICE
		create(voice,G,octave+1,0.25,VOICEAZ);
		append(voice,E,octave+1,0.5,VOICEAZ);
		//HARMONY
		silence(0.25);
		append(harmony,E,octave+2,0.5,CHORDAZ);
		fourChord(harmony,G/2,C,E,G,octave+2,0.25,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave+1,0.25,CHORDAZ);
		appendChord(harmony,E,Gs,2*D,octave+1,0.25,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,C,octave-1,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-1,0.25,BASSAZ);
		appendInterval(bass,Bf,2*Bf,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 31
		#ifdef DEBUG
		puts("Measure # 31");
		#endif
		//VOICE
		six(voice,G,A,G,F,E,G,octave+1,0.75,VOICEAZ);
		//HARMONY
		six(harmony,G,A,G,F,E,G,octave+1,0.75,CHORDAZ);
		six(harmony,G,A,G,F,E,G,octave+2,0.75,CHORDAZ);
		add();
		interval(harmony,Cs,E,octave+2,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,E,2*E,octave-2,0.25,BASSAZ);
		appendChord(bass,A/2,Cs,G,octave,0.25,BASSAZ);
		appendChord(bass,A/2,Cs,G,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 32
		#ifdef DEBUG
		puts("Measure # 32");
		#endif
		//VOICE
		create(voice,F,octave+1,0.25,VOICEAZ);
		append(voice,Db,octave+1,0.5,VOICEAZ);
		//HARMONY
		fourChord(harmony,F/2,A/2,Db,F,octave+2,0.25,CHORDAZ);
		appendFourChord(harmony,Db,F,A,Db,octave+1,0.5,CHORDAZ);
	add();
		//BASS
		create(bass,Db,octave-1,0.25,BASSAZ);
		appendChord(bass,A/2,Db,F,octave,0.25,BASSAZ);
		appendChord(bass,B/2,Db,F,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 33
		#ifdef DEBUG
		puts("Measure # 33");
		#endif
		//VOICE
		six(voice,B,G,B,G,B,2*D,octave,0.75,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,F,B,octave+1,0.125,CHORDAZ);
		append(harmony,G,octave+1,0.125,CHORDAZ);
		appendChord(harmony,B/2,F,B,octave+1,0.125,CHORDAZ);
		append(harmony,G,octave+1,0.125,CHORDAZ);
		appendChord(harmony,B/2,F,B,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,D,2*D,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.25,BASSAZ);
		appendChord(bass,G,B,2*F,octave-1,0.25,BASSAZ);
		appendChord(bass,G,B,2*F,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 34
		#ifdef DEBUG
		puts("Measure # 34");
		#endif
		//VOICE
		create(voice,F,octave+1,0.25,VOICEAZ);
		append(voice,Db,octave+1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,F,B,2*F,octave+1,0.25,CHORDAZ);
		appendFourChord(harmony,Db,F,B,2*Db,octave+1,0.5,CHORDAZ);
	add();
		//BASS
		interval(bass,G,2*G,octave-2,0.25,BASSAZ);
		appendChord(bass,G,B,2*F,octave-1,0.25,BASSAZ);
		appendChord(bass,G,B,2*F,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 35
		#ifdef DEBUG
		puts("Measure # 35");
		#endif
		//VOICE
		six(voice,G,A,G,F,E,D,octave+1,0.75,VOICEAZ);
		//HARMONY
		fourChord(harmony,G,B,2*D,G,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,A,2*A,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,G,B,2*D,G,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,F,2*F,octave+1,0.125,CHORDAZ);
		appendFourChord(harmony,E,G,B,2*E,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,D,2*D,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,G,2*G,octave-2,0.25,BASSAZ);
		appendChord(bass,G,B,2*F,octave-1,0.25,BASSAZ);
		appendChord(bass,G,B,2*F,octave-1,0.25,BASSAZ);
	add();
	cat();
	if(end){
	//MEASURE # 36
		#ifdef DEBUG
		puts("Measure # 36");
		#endif
		//VOICE
		create(voice,E,octave+1,0.25,VOICEAZ);
		append(voice,C,octave+1,0.125,VOICEAZ);
		appendSilence(0.125);
		//HARMONY
		fourChord(harmony,E,G,2*C,2*E,octave+1,0.25,CHORDAZ);
		appendFourChord(harmony,C,E,G,2*C,octave+1,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave,0.25,BASSAZ);
		append(bass,C,octave-1,0.125,BASSAZ);
	add();
	cat();
	}
	else{
	//MEASURE # 36
		#ifdef DEBUG
		puts("Measure # 36");
		#endif
		//VOICE
		create(voice,E,octave+1,0.25,VOICEAZ);
		append(voice,C,octave+1,0.125,VOICEAZ);
		appendThree(voice,G,G,G,octave,0.375,VOICEAZ);
		//HARMONY
		fourChord(harmony,E,G,2*C,2*E,octave+1,0.25,CHORDAZ);
		appendFourChord(harmony,C,E,G,2*C,octave+1,0.125,CHORDAZ);
		appendThree(harmony,G,G,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-1,0.25,BASSAZ);
		appendInterval(bass,C,2*C,octave-1,0.125,BASSAZ);
	add();
	cat();
	}
}

void coda(void){
	//MEASURE # 36
		#ifdef DEBUG
		puts("Measure # 36");
		#endif
		//VOICE
		three(voice,G,G,G,octave,0.375,VOICEAZ);
		//HARMONY
		three(harmony,G,G,G,octave,0.375,CHORDAZ);
	add();
		//BASS

	//MEASURE # 37
		#ifdef DEBUG
		puts("Measure # 37");
		#endif
		//VOICE
		create(voice,C,octave+1,0.25,VOICEAZ);
		append(voice,E,octave+1,0.125,VOICEAZ);
		appendThree(voice,G,G,G,octave,0.375,VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave,0.25,CHORDAZ);
		appendInterval(harmony,G,2*E,octave,0.125,CHORDAZ);
		appendThree(harmony,G,G,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		interval(bass,C,G,octave-2,0.25,BASSAZ);
		appendChord(bass,G/2,C,E,octave,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 38
		#ifdef DEBUG
		puts("Measure # 38");
		#endif
		//VOICE
		create(voice,C,octave+1,0.25,VOICEAZ);
		append(voice,E,octave+1,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.25,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave+1,0.5,CHORDAZ);
	add();
		//BASS
		interval(bass,C,G,octave-1,0.25,BASSAZ);
		appendChord(bass,G/2,C,E,octave,0.25,BASSAZ);
		appendChord(bass,G/2,C,E,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 39
		#ifdef DEBUG
		puts("Measure # 39");
		#endif
		//VOICE
		six(voice,2*C,2*C,B,B,A,A,octave,0.75,VOICEAZ);
		//HARMONY
		six(harmony,2*C,2*C,B,B,A,A,octave,0.75,CHORDAZ);
		create(harmony,G,octave,0.5,CHORDAZ);
		append(harmony,Gf,octave,0.25,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,E,octave-1,0.5,BASSAZ);
		append(bass,Ef,octave-1,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 40
		#ifdef DEBUG
		puts("Measure # 40");
		#endif
		//VOICE
		create(voice,G,octave,0.25,VOICEAZ);
		appendFour(voice,0,G,G,G,octave,0.5,VOICEAZ);
		//HARMONY
		create(harmony,G,octave,0.25,CHORDAZ);
		appendFour(harmony,0,G,G,G,octave,0.5,CHORDAZ);
		create(harmony,F,octave,0.25,CHORDAZ);
		add();		
	add();
		//BASS
		create(bass,D,octave-1,0.25,BASSAZ);
		appendChord(bass,G,B,2*F,octave-1,0.125,BASSAZ);		
	add();
	cat();

	//MEASURE # 41
		#ifdef DEBUG
		puts("Measure # 41");
		#endif
		//VOICE
		create(voice,B,octave,0.25,VOICEAZ);
		appendFour(voice,2*D,G,G,G,octave,0.5,VOICEAZ);
		//HARMONY
		interval(harmony,F,B,octave,0.25,CHORDAZ);
		appendChord(harmony,F,B,2*D,octave,0.125,CHORDAZ);
		appendThree(harmony,G,G,G,octave,0.375,CHORDAZ);
	add();
		//BASS
		create(bass,D,octave-1,0.25,BASSAZ);
		appendChord(bass,G,B,2*F,octave-1,0.125,BASSAZ);
	add();
	cat();

	//MEASURE # 42
		#ifdef DEBUG
		puts("Measure # 42");
		#endif
		//VOICE
		create(voice,B,octave,0.25,VOICEAZ);
		append(voice,D,octave,0.5,VOICEAZ);
		//HARMONY
		interval(harmony,F,B,octave,0.25,CHORDAZ);
		appendInterval(harmony,B,2*D,octave,0.5,CHORDAZ);
	add();
		//BASS
		interval(bass,G,2*G,octave-2,0.25,BASSAZ);
		appendChord(bass,G,B,2*F,octave-1,0.25,BASSAZ);
		appendChord(bass,G,B,2*F,octave-1,0.25,BASSAZ);
	add();
	cat();

	//MEASURE # 43
		#ifdef DEBUG
		puts("Measure # 43");
		#endif
		//VOICE
		six(voice,G,A,G,F,E,Db,octave+1,0.75,VOICEAZ);
		//HARMONY
		six(harmony,G,A,G,F,E,Db,octave+1,0.75,CHORDAZ);
		addSix(harmony,B,2*C,B,A,G,F,octave,0.75,CHORDAZ);
	add();
		//BASS
		six(bass,G,Gf,G,A,Bf,B,octave-1,0.75,BASSAZ);
	add();
	cat();
	//MEASURE # 44
		#ifdef DEBUG
		puts("Measure # 44");
		#endif
		//VOICE
		create(voice,C,octave+1,0.75,VOICEAZ);
		appendSilence(0.5);
		//HARMONY
		interval(harmony,E,2*C,octave,0.25,VOICEAZ);
		appendFourChord(harmony,C,E,G,2*C,octave+1,0.5,CHORDAZ);
	add();
		//BASS
		create(bass,C,octave,0.25,BASSAZ);
		appendChord(bass,C,G,2*E,octave-1,0.5,BASSAZ);
	add();
	cat();
}

void song(void){
	puts("intro");
 	intro();
	puts("repeat(0)");
	repeat(0);
	cat();
	puts("repeat(1)");
	repeat(1);
	cat();
	puts("coda");
	coda();
	cat();
}

int main(int argc, char **argv){

	tempo=104;

	C = G/2;

	song();

	echo(10,0.3,4);

    appendSilence(2);
	puts("Writing wav file... la cucaracha.wav");

	exportToWav("La Cucaracha.wav");

}
