#include "soundlib.h"

#define CHORDAZ 135
#define BASSAZ 45
#define VOICEAZ 90


#define DEBUG 1


double (*voice)(double) = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double) = oldCircleOfRa;


short octave = 0;

void first(void){
	//MEASURE # 1
	#ifdef DEBUG
	puts("Measure # 1");
	#endif
		//HARMONY
		silence(0.125);
		appendChord(harmony,E,G,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,E,G,B,octave,0.125,CHORDAZ);
		appendChord(harmony,E,G,Bf,octave,0.125,CHORDAZ);
		//BASS
		silence(0.125);
		appendThree(bass,2*C,B,Bf,octave-1,0.375,BASSAZ);
	add();
}

void head(void){
	//MEASURE # 2
	#ifdef DEBUG
	puts("Measure # 2");
	#endif
		//HARMONY
		chord(harmony,C,F,A,octave,0.125,CHORDAZ);
		appendChord(harmony,C,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,A/2,C,F,octave,0.125,CHORDAZ);
		//BASS
		arpegio(bass,F,2*C,2*A,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
	add();
	//MEASURE # 3
	#ifdef DEBUG
	puts("Measure # 3");
	#endif
		//HARMONY
		four(harmony,A,2*C,B,A,octave,0.5,CHORDAZ);
		addFour(harmony,F,A,G,F,octave,0.5,CHORDAZ);
		addFour(harmony,C,C,C,C,octave,0.5,CHORDAZ);
		//BASS
		interval(bass,F,2*F,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,F,2*F,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 4 & 5
	#ifdef DEBUG
	puts("Measure # 4 & 5");
	#endif
		//HARMONY
		interval(harmony,E,G,octave,0.25,CHORDAZ);
		append(harmony,G,octave,0.375,CHORDAZ);
		silence(0.125);
		appendChord(harmony,G/2,C,E,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,G/2,C,E,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,B/2,G,B,octave,0.125,CHORDAZ);
		appendChord(harmony,A/2,F,A,octave,0.125,CHORDAZ);
		appendChord(harmony,G/2,E,G,octave,0.125,CHORDAZ);
		add();
		//BASS
		interval(bass,C/2,C,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,C/2,C,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 6
	#ifdef DEBUG
	puts("Measure # 6");
	#endif
		//HARMONY
		chord(harmony,A/2,Db,F,octave,0.125,CHORDAZ);
		appendChord(harmony,A,B,2*F,octave-1,0.25,CHORDAZ);
		appendChord(harmony,F,B,2*D,octave-1,0.125,CHORDAZ);
		//BASS
		interval(bass,Db,2*Db,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 7
	#ifdef DEBUG
	puts("Measure # 7");
	#endif
		//HARMONY
		four(harmony,F,A,G,F,octave,0.5,CHORDAZ);
		addFour(harmony,B/2,F,E,D,octave,0.5,CHORDAZ);
		addFour(harmony,A,B,B,B,octave-1,0.5,CHORDAZ);
		//BASS
		interval(bass,D/2,D,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 8
	#ifdef DEBUG
	puts("Measure # 8");
	#endif
		//HARMONY
		chord(harmony,G/2,C,E,octave,0.125,CHORDAZ);
		appendThree(harmony,G,2*C,A,octave,0.375,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendThree(bass,G,2*C,A,octave-1,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 9
	#ifdef DEBUG
	puts("Measure # 9");
	#endif
		//HARMONY
		create(harmony,G,octave,0.125,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,E,G,B,octave,0.125,CHORDAZ);
		appendChord(harmony,E,G,Bf,octave,0.125,CHORDAZ);
		//BASS
		create(bass,G,octave-1,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 10
	#ifdef DEBUG
	puts("Measure # 10");
	#endif
		//HARMONY
		chord(harmony,C,F,A,octave,0.125,CHORDAZ);
		appendChord(harmony,C,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,A/2,C,F,octave,0.125,CHORDAZ);
		//BASS
		interval(bass,F,2*F,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,C,2*C,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 11
	#ifdef DEBUG
	puts("Measure # 11");
	#endif
		//HARMONY
		chord(harmony,C,F,A,octave,0.125,CHORDAZ);
		appendChord(harmony,C,A,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,D,G,B,octave,0.125,CHORDAZ);
		appendChord(harmony,C,F,A,octave,0.125,CHORDAZ);
		//BASS
		interval(bass,F,2*F,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,F,2*F,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 12 & 13
	#ifdef DEBUG
	puts("Measure # 12 & 13");
	#endif
		//HARMONY
		create(harmony,G,octave,0.25,CHORDAZ);
		append(harmony,G,octave,0.375,CHORDAZ);
		silence(0.125);
		appendChord(harmony,G/2,C,E,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,G/2,C,E,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,C,A,B,octave,0.125,CHORDAZ);
		appendChord(harmony,C,A,B,octave,0.125,CHORDAZ);
		appendChord(harmony,C,F,A,octave,0.125,CHORDAZ);
		add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 14
	#ifdef DEBUG
	puts("Measure # 14");
	#endif
		//VOICE
		//HARMONY
		chord(harmony,A/2,Db,F,octave,0.125,CHORDAZ);
		appendChord(harmony,A/2,B/2,F,octave,0.25,CHORDAZ);
		appendChord(harmony,F/2,B/2,D,octave,0.125,CHORDAZ);
		//BASS
		interval(bass,Db,2*Db,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 15
	#ifdef DEBUG
	puts("Measure # 15");
	#endif
		//VOICE
		//HARMONY
		chord(harmony,A/2,B/2,F,octave,0.125,CHORDAZ);
		appendChord(harmony,B/2,F,A,octave,0.125,CHORDAZ);
		appendChord(harmony,B/2,E,G,octave,0.125,CHORDAZ);
		appendChord(harmony,B/2,D,F,octave,0.125,CHORDAZ);
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
}

void tail(void){
	//MEASURE # 16
	#ifdef DEBUG
	puts("Measure # 16");
	#endif
		//HARMONY
		chord(harmony,G/2,C,E,octave,0.125,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,C,E,G,octave,0.125,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	//MEASURE # 17
	#ifdef DEBUG
	puts("Measure # 17");
	#endif
		//HARMONY
		silence(0.125);
		appendChord(harmony,G/2,C,E,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,G/2,C,E,octave,0.125,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 18
	#ifdef DEBUG
	puts("Measure # 18");
	#endif
		//HARMONY
		silence(0.125);
		appendChord(harmony,G/2,C,E,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,G/2,C,E,octave,0.125,CHORDAZ);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 19
	#ifdef DEBUG
	puts("Measure # 19");
	#endif
		//VOICE
		silence(0.25);
		append(voice,G,octave,0.1875,VOICEAZ);
		append(voice,F,octave,0.0625,VOICEAZ);
		//HARMONY
		silence(0.125);
		appendChord(harmony,G/2,C,E,octave,0.125,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.1875,CHORDAZ);
		appendInterval(harmony,Db,F,octave,0.0625,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 20
	#ifdef DEBUG
	puts("Measure # 20");
	#endif
		//VOICE
		create(voice,E,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 21
	#ifdef DEBUG
	puts("Measure # 21");
	#endif
		//VOICE
		two(voice,A,G,octave,0.5,VOICEAZ);
		//HARMONY
		two(harmony,A,G,octave,0.5,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 22
	#ifdef DEBUG
	puts("Measure # 22");
	#endif
		//VOICE
		create(voice,C,octave+1,0.125,VOICEAZ);
		append(voice,C,octave+1,0.25,VOICEAZ);
		append(voice,B,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave,0.25,CHORDAZ);
		appendInterval(harmony,G,B,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 23
	#ifdef DEBUG
	puts("Measure # 23");
	#endif
		//VOICE
		two(voice,A,G,octave,0.5,VOICEAZ);
		//HARMONY
		two(harmony,A,G,octave,0.5,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();

	//MEASURE # 24
	#ifdef DEBUG
	puts("Measure # 24");
	#endif
		//VOICE
		create(voice,E,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.25,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 25
	#ifdef DEBUG
	puts("Measure # 25");
	#endif
		//VOICE
		two(voice,F,E,octave,0.5,VOICEAZ);
		//HARMONY
		two(harmony,F,E,octave,0.5,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,A/2,C,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendInterval(harmony,G,Bf,octave-1,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,Cs,2*Cs,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 26 & 27
	#ifdef DEBUG
	puts("Measure # 26 & 27");
	#endif
		//VOICE
		create(voice,G,octave,0.625,VOICEAZ);
		appendThree(voice,D,D,E,octave,0.375,VOICEAZ);
		//HARMONY
		create(harmony,G,octave,0.625,CHORDAZ);
		silence(0.125);
		four(harmony,B/2,C,Cs,D,octave,0.5,CHORDAZ);
		addFour(harmony,G,A,Bf,B,octave-1,0.5,CHORDAZ);
		cat();
		appendChord(harmony,F/2,B/2,D,octave,0.125,CHORDAZ);
		appendChord(harmony,F/2,B/2,D,octave,0.125,CHORDAZ);
		appendChord(harmony,G/2,B/2,E,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendThree(bass,D,Ef,E,octave-1,0.375,BASSAZ);
		appendInterval(bass,G,2*F,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 28
	#ifdef DEBUG
	puts("Measure # 28");
	#endif
		//VOICE
		create(voice,F,octave,0.125,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,A/2,B/2,F,octave,0.125,CHORDAZ);
		appendChord(harmony,A/2,B/2,F,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,F,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 29
	#ifdef DEBUG
	puts("Measure # 29");
	#endif
		//VOICE
		two(voice,A,G,octave,0.5,VOICEAZ);
		//HARMONY
		two(harmony,A,G,octave,0.5,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,B/2,F,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendInterval(harmony,B/2,F,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 30
	#ifdef DEBUG
	puts("Measure # 30");
	#endif
		//VOICE
		create(voice,B,octave,0.125,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,F,B,octave,0.125,CHORDAZ);
		appendChord(harmony,B/2,F,B,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,F,A,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 31
	#ifdef DEBUG
	puts("Measure # 31");
	#endif
		//VOICE
		two(voice,G,F,octave,0.5,VOICEAZ);
		//HARMONY
		two(harmony,G,F,octave,0.5,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,B/2,F,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendInterval(harmony,A,B,octave-1,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 32
	#ifdef DEBUG
	puts("Measure # 32");
	#endif
		//VOICE
		create(voice,B,octave,0.125,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,F,B,octave,0.125,CHORDAZ);
		appendChord(harmony,B/2,F,B,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,F,A,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,D,D*D,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,D,D*D,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 33
	#ifdef DEBUG
	puts("Measure # 33");
	#endif
		//VOICE
		two(voice,G,F,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,E,G,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,D,F,octave,0.25,CHORDAZ);
	add();
		//BASS
		create(bass,G,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 34 & 35
	#ifdef DEBUG
	puts("Measure # 34 & 35");
	#endif
		//VOICE
		create(voice,E,octave,0.625,VOICEAZ);
		appendSilence(0.125);
		append(voice,G,octave,0.1875,VOICEAZ);
		append(voice,F,octave,0.0625,VOICEAZ);
		//HARMONY
		chord(harmony,G/2,C,E,octave,0.625,CHORDAZ);
		appendSilence(0.125);
		appendInterval(harmony,F,G,octave,0.1875,CHORDAZ);
		appendInterval(harmony,Db,F,octave,0.0625,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendFour(bass,2*C,B,A,G,octave,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 36
	#ifdef DEBUG
	puts("Measure # 36");
	#endif
		//VOICE
		create(voice,E,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 37
	#ifdef DEBUG
	puts("Measure # 37");
	#endif
		//VOICE
		two(voice,A,G,octave,0.5,VOICEAZ);
		//HARMONY
		grace(harmony,B,A,octave,0.25,CHORDAZ);
		append(harmony,G,octave,0.25,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();

	//MEASURE # 38
	#ifdef DEBUG
	puts("Measure # 38");
	#endif
		//VOICE
		create(voice,C,octave+1,0.125,VOICEAZ);
		append(voice,C,octave+1,0.25,VOICEAZ);
		append(voice,B,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,E,G,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave,0.25,CHORDAZ);
		appendInterval(harmony,G,B,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 39
	#ifdef DEBUG
	puts("Measure # 39");
	#endif
		//VOICE
		two(voice,A,G,octave,0.5,VOICEAZ);
		//HARMONY
		two(harmony,A,G,octave,0.5,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendInterval(harmony,C,E,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 40
	#ifdef DEBUG
	puts("Measure # 40");
	#endif
		//VOICE
		create(voice,E,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,C,E,octave,0.125,CHORDAZ);
		appendInterval(harmony,C,E,octave,0.25,CHORDAZ);
		appendChord(harmony,C,E,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 41
	#ifdef DEBUG
	puts("Measure # 41");
	#endif
		//VOICE
		two(voice,F,A,octave,0.5,VOICEAZ);
		//HARMONY
		two(harmony,F,A,octave,0.5,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,A/2,C,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendInterval(harmony,G,Bf,octave-1,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.25,BASSAZ);
		appendInterval(bass,Cs,2*Cs,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 42 & 43
	#ifdef DEBUG
	puts("Measure # 42 & 43");
	#endif
		//VOICE
		create(voice,G,octave,0.625,VOICEAZ);
		appendThree(voice,D,D,E,octave,0.375,VOICEAZ);
		//HARMONY
		create(harmony,G,octave,0.625,CHORDAZ);
		silence(0.125);
		four(harmony,B/2,C,Cs,D,octave,0.5,CHORDAZ);
		addFour(harmony,G,A,Bf,B,octave,0.5,CHORDAZ);
		cat();
		appendChord(harmony,F/2,B/2,D,octave,0.125,CHORDAZ);
		appendChord(harmony,F/2,B/2,D,octave,0.125,CHORDAZ);
		appendChord(harmony,G/2,B/2,E,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendThree(bass,D,Ef,E,octave,0.375,BASSAZ);
		appendInterval(bass,G,2*F,octave-2,0.125,BASSAZ);
	add();
	cat();

	//MEASURE # 44
	#ifdef DEBUG
	puts("Measure # 44");
	#endif
		//VOICE
		create(voice,F,octave,0.125,VOICEAZ);
		append(voice,F,octave,0.25,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,A/2,B/2,F,octave,0.125,CHORDAZ);
		appendChord(harmony,A/2,B/2,F,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,F,G,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 45
	#ifdef DEBUG
	puts("Measure # 45");
	#endif
		//VOICE
		two(voice,A,G,octave,0.5,VOICEAZ);
		//HARMONY
		two(harmony,A,G,octave,0.5,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,B/2,F,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendInterval(harmony,B/2,F,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 46
	#ifdef DEBUG
	puts("Measure # 46");
	#endif
		//VOICE
		create(voice,B,octave,0.125,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,F,B,octave,0.125,CHORDAZ);
		appendChord(harmony,B/2,F,B,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,F,A,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 47
	#ifdef DEBUG
	puts("Measure # 47");
	#endif
		//VOICE
		two(voice,G,A,octave,0.5,VOICEAZ);
		//HARMONY
		two(harmony,G,A,octave,0.5,CHORDAZ);
		silence(0.125);
		appendInterval(harmony,B/2,F,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendInterval(harmony,A/2,B/2,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 48
	#ifdef DEBUG
	puts("Measure # 48");
	#endif
		//VOICE
		create(voice,B,octave,0.125,VOICEAZ);
		append(voice,B,octave,0.25,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,F,B,octave,0.125,CHORDAZ);
		appendChord(harmony,B/2,F,B,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,F,A,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,D,2*D,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,D,2*D,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 49
	#ifdef DEBUG
	puts("Measure # 49");
	#endif
		//VOICE
		two(voice,G,F,octave,0.5,VOICEAZ);
		//HARMONY
		chord(harmony,B/2,E,G,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,D,F,octave,0.25,CHORDAZ);
	add();
		//BASS
		three(bass,G,0,G,octave-2,0.375,BASSAZ);
	add();
	cat();
	//MEASURE # 50 & 51
	#ifdef DEBUG
	puts("Measure # 50 & 51");
	#endif
		//VOICE
		create(voice,E,octave,0.625,VOICEAZ);
		//HARMONY
		chord(harmony,G/2,C,E,octave,0.625,CHORDAZ);
		appendChord(harmony,E,G,2*C,octave,0.125,CHORDAZ);
		appendChord(harmony,E,G,B,octave,0.125,CHORDAZ);
		appendChord(harmony,E,G,Bf,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendFour(bass,G,F,A,B,octave,0.5,BASSAZ);
	add();
	cat();
}

void coda(void){
	//MEASURE # 52
	#ifdef DEBUG
	puts("Measure # 52");
	#endif
		//HARMONY
		chord(harmony,G/2,C,E,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,B/2,F,G,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-1,0.125,BASSAZ);
	add();
	//MEASURE # 53
	#ifdef DEBUG
	puts("Measure # 53");
	#endif
		//HARMONY
		fourChord(harmony,C,E,G,2*C,octave,0.125,CHORDAZ);
		//BASS
		chord(bass,C,G,2*E,octave-2,0.125,BASSAZ);
	add();
	cat();
}

void song(void){
	first();
	head();
	cat();
	tail(); cat();
	head(); cat();
	tail(); cat();
	head(); cat();
	coda(); cat();

}



int main(int argc, char **argv){

	tempo=110;

	C = Ef;

	song();

	echo(10,0.3,4);


	puts("Writing wav file: las gaviotas.wav");

	exportToWav("Las Gaviotas.wav");

}
