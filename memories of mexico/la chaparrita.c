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
	double start;
	PIANO;
	//MEASURE # 1
	#ifdef DEBUG
	puts("Measure # 1");
	#endif
		//VOICE
		silence(0.125);
		append(voice,G,octave,0.125,VOICEAZ);
		appendFour(voice,C,E,Db,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		silence(0.125);
		append(harmony,G,octave,0.125,CHORDAZ);
		four(harmony,C,E,Db,C,octave+1,0.25,CHORDAZ);
		addFour(harmony,E,G,F,E,octave,0.25,CHORDAZ);
		cat();
	add();
		//BASS
		create(bass,C,octave-1,0.5,BASSAZ);
		create(bass,C,octave-1,0.25,BASSAZ);
		appendTwo(bass,G,G/2,octave,0.25,BASSAZ);
		add();
	add();

}


void repeat(short end){
	double start;
	PIANO;
	//MEASURE # 2 & 3
	#ifdef DEBUG
	puts("Measure # 2 & 3");
	#endif
		//VOICE
		create(voice,E,octave+1,0.25,VOICEAZ);
		append(voice,E,octave+1,0.375,VOICEAZ);
		append(voice,Db,octave+1,0.125,VOICEAZ);
		appendFour(voice,E,F,E,Ef,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,G,2*E,octave,0.25,CHORDAZ);
		appendInterval(harmony,G,2*E,octave,0.375,CHORDAZ);
		appendInterval(harmony,F,2*Db,octave,0.125,CHORDAZ);
		four(harmony,E,F,E,Ef,octave,0.25,CHORDAZ);
		addFour(harmony,G,A,G,Gf,octave,0.25,CHORDAZ);
		cat();
	add();
		//BASS
		create(bass,G,octave-1,0.125,BASSAZ);
		appendTwo(bass,G,G,octave-1,0.125,BASSAZ);
		appendGrace(bass,B,A,octave-1,0.0625,BASSAZ);
		appendThree(bass,Af,G,G/2,octave-1,0.1875,BASSAZ);
		append(bass,G,octave-2,0.1875,BASSAZ);
		append(bass,C,octave-1,0.0625,BASSAZ);
		appendFour(bass,G,2*C,G,G/2,octave,0.25,BASSAZ);
	add();

	//MEASURE # 4 & 5
	#ifdef DEBUG
	puts("Measure # 4 & 5");
	#endif
		//VOICE
		create(voice,E,octave+1,0.25,VOICEAZ);
		append(voice,C,octave+1,0.375,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		appendFour(voice,C,E,Db,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,G,2*E,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.375,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
		four(harmony,C,E,Db,C,octave,0.25,CHORDAZ);
		addFour(harmony,E,G,F,E,octave,0.25,CHORDAZ);
		cat();
	add();
		//BASS
		create(bass,G,octave-1,0.125,BASSAZ);
		appendTwo(bass,G,G,octave-1,0.125,BASSAZ);
		appendGrace(bass,B,A,octave-1,0.0625,BASSAZ);
		appendThree(bass,Af,G,G/2,octave-1,0.1875,BASSAZ);
		append(bass,G,octave-2,0.1875,BASSAZ);
		append(bass,C,octave-1,0.0625,BASSAZ);
		appendTwo(bass,G,G/2,octave,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 6 & 7
	#ifdef DEBUG
	puts("Measure # 6 & 7");
	#endif
		//VOICE
		create(voice,E,octave+1,0.25,VOICEAZ);
		append(voice,D,octave+1,0.375,VOICEAZ);
		append(voice,D,octave+1,0.125,VOICEAZ);
		appendFour(voice,E,D,C,B/2,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,G,2*E,octave,0.25,CHORDAZ);
		appendInterval(harmony,F,2*D,octave,0.375,CHORDAZ);
		appendInterval(harmony,F,2*D,octave,0.125,CHORDAZ);
		four(harmony,E,D,C,B/2,octave,0.25,CHORDAZ);
		addFour(harmony,G,F,E,D,octave,0.25,CHORDAZ);
		cat();
	add();
		//BASS
		create(bass,B,octave-2,0.25,BASSAZ);
		appendGrace(bass,F,G,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,D,octave-1,0.25,BASSAZ);
		appendGrace(bass,F,G,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();

	//MEASURE # 8 & 9
	#ifdef DEBUG
	puts("Measure # 8 & 9");
	#endif
		//VOICE
		create(voice,C,octave+1,0.625,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		appendFour(voice,C,E,Db,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave,0.625,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
		four(harmony,C,E,Db,C,octave,0.25,CHORDAZ);
		addFour(harmony,E,G,F,E,octave,0.25,CHORDAZ);
		cat();
	add();
		//BASS
		create(bass,C,octave-1,0.1875,BASSAZ);
		append(bass,G,octave-1,0.0625,BASSAZ);
		appendTwo(bass,G,G/2,octave-1,0.25,BASSAZ);
		create(bass,C,octave-1,0.5,BASSAZ);
		create(bass,C,octave-1,0.25,BASSAZ);
		appendTwo(bass,G,G/2,octave-1,0.25,BASSAZ);
		add();
		cat();
	add();
	cat();
	//MEASURE # 10 & 11
	#ifdef DEBUG
	puts("Measure # 10 & 11");
	#endif
		//VOICE
		create(voice,E,octave+1,0.25,VOICEAZ);
		append(voice,E,octave+1,0.375,VOICEAZ);
		append(voice,Db,octave+1,0.125,VOICEAZ);
		appendFour(voice,E,F,E,Ef,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,G,2*E,octave,0.25,CHORDAZ);
		appendInterval(harmony,G,2*E,octave,0.375,CHORDAZ);
		appendInterval(harmony,F,2*Db,octave,0.125,CHORDAZ);
		four(harmony,E,F,E,Ef,octave+1,0.25,CHORDAZ);
		addFour(harmony,G,A,G,Gf,octave,0.25,CHORDAZ);
		cat();
	add();
		//BASS
		create(bass,C,octave-1,0.125,BASSAZ);
		appendTwo(bass,G,G,octave-1,0.125,BASSAZ);
		appendGrace(bass,B,A,octave-1,0.0625,BASSAZ);
		appendThree(bass,Af,G,G/2,octave-1,0.1875,BASSAZ);
		append(bass,Db,octave-1,0.1875,BASSAZ);
		append(bass,G,octave-1,0.0625,BASSAZ);
		appendFour(bass,G,2*C,G,G/2,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 12 & 13
	#ifdef DEBUG
	puts("Measure # 12 & 13");
	#endif
		//VOICE
		create(voice,E,octave+1,0.25,VOICEAZ);
		append(voice,C,octave+1,0.375,VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		appendFour(voice,C,E,Db,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,G,2*E,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,2*C,octave,0.375,CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
		four(harmony,C,E,Db,C,octave,0.25,CHORDAZ);
		addFour(harmony,E,G,F,E,octave,0.25,CHORDAZ);
		cat();
	add();
		//BASS
		create(bass,C,octave-1,0.125,BASSAZ);
		appendTwo(bass,G,G,octave-1,0.125,BASSAZ);
		appendGrace(bass,B,A,octave-1,0.0625,BASSAZ);
		appendThree(bass,Af,G,G/2,octave-1,0.1875,BASSAZ);
		append(bass,C,octave-1,0.1875,BASSAZ);
		append(bass,G,octave-1,0.0625,BASSAZ);
		appendTwo(bass,G,G/2,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 14 & 15
	#ifdef DEBUG
	puts("Measure # 14 & 15");
	#endif
		//VOICE
		create(voice,E,octave+1,0.25,VOICEAZ);
		append(voice,Db,octave+1,0.375,VOICEAZ);
		append(voice,Db,octave+1,0.125,VOICEAZ);
		appendFour(voice,E,D,G,B/2,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,G,2*E,octave,0.25,CHORDAZ);
		appendInterval(harmony,F,2*Db,octave,0.375,CHORDAZ);
		appendInterval(harmony,G,2*Db,octave,0.125,CHORDAZ);
		four(harmony,E,D,G,B/2,octave+1,0.25,CHORDAZ);
		addFour(harmony,G,F,E,D,octave,0.25,CHORDAZ);
		cat();
	add();
		//BASS
		create(bass,B,octave-2,0.25,BASSAZ);
		appendGrace(bass,Gf,G,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
		append(bass,D,octave-1,0.25,BASSAZ);
		appendGrace(bass,Gf,G,octave-1,0.125,BASSAZ);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();

	//MEASURE # 16 & 17
	start = (PIANO)/(FORTE);
	PIANO;
	#ifdef DEBUG
	puts("Measure # 16 & 17");
	#endif
		//VOICE		
		create(voice,C,octave+1,0.625,VOICEAZ);
		FORTE;
		two(voice,C,C,octave+1,0.125,VOICEAZ);
		appendFour(voice,D,C,B/2,C,octave+1,0.25,VOICEAZ);
		gradual(start,1);
		cat();
		//HARMONY
		PIANO;
		interval(harmony,E,2*C,octave,0.625,CHORDAZ);
		appendTwo(harmony,C,C,octave+1,0.125,CHORDAZ);
		FORTE;
		four(harmony,D,C,B/2,C,octave+1,0.25,CHORDAZ);
		gradual(start,1);
		cat();
	add();
		//BASS
		create(bass,C,octave-1,0.1875,BASSAZ);
		append(bass,G,octave-1,0.0625,BASSAZ);
		appendTwo(bass,G,G/2,octave-1,0.25,BASSAZ);
		append(bass,C,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 18 & 19
	#ifdef DEBUG
	puts("Measure # 18 & 19");
	#endif
		//VOICE
		create(voice,F,octave+1,0.25,VOICEAZ);
		append(voice,A,octave+1,0.375,VOICEAZ);
		append(voice,C,octave+1,0.125,VOICEAZ);
		appendFour(voice,D,C,B/2,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,A,2*F,octave,0.25,CHORDAZ);
		appendArpegioFour(harmony,A/2,C,F,A,octave+1,0.375,CHORDAZ);
		append(harmony,C,octave+1,0.125,CHORDAZ);
		appendInterval(harmony,F,Db,octave,0.0625,CHORDAZ);
		appendThree(harmony,C,B/2,C,octave+1,0.1875,CHORDAZ);
	add();
		//BASS
		create(bass,F,octave-2,0.25,BASSAZ);
		six(bass,F,E,F,C,A/2,G/2,octave-1,0.25,BASSAZ);
		chord(bass,A/2,C,F,octave,0.25/6,BASSAZ);
		add();
		cat();
		append(bass,F,octave-2,0.25,BASSAZ);
		appendInterval(bass,Af,2*Af,octave-2,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 20 & 21
	start=(PIANO)/(FORTE);
	#ifdef DEBUG
	puts("Measure # 20 & 21");
	#endif
		//VOICE
		create(voice,E,octave+1,0.25,VOICEAZ);
		append(voice,G,octave+1,0.375,VOICEAZ);
		create(voice,G,octave,0.125,VOICEAZ);
		appendFour(voice,C,E,Db,C,octave+1,0.25,VOICEAZ);
		gradual(1,start);
		cat();
		//HARMONY
		chord(harmony,G/2,C,E,octave+1,0.25,CHORDAZ);
		appendArpegioFour(harmony,G/2,C,E,G,octave+1,0.375,CHORDAZ);
		create(harmony,G,octave,0.125,CHORDAZ);
		four(harmony,C,E,Db,C,octave+1,0.25,CHORDAZ);
		addFour(harmony,E,G,F,E,octave,0.25,CHORDAZ);
		cat();
		gradual(1,start);
		cat();
	add();
		//BASS
		interval(bass,G,2*G,octave-2,0.25,BASSAZ);
		interval(bass,C,E,octave,0.25/6,BASSAZ);
		six(bass,G,B,2*C,G,F,E,octave-1,0.25,BASSAZ);
		add();
		cat();
		create(bass,C,octave-1,0.25,BASSAZ);
		appendTwo(bass,G,G/2,octave-1,0.25,BASSAZ);
		gradual(1,start);
		cat();
	add();
	cat();
	//MEASURE # 22 & 23
	PIANO;
	#ifdef DEBUG
	puts("Measure # 22 & 23");
	#endif
		//VOICE
		create(voice,E,octave+1,0.25,VOICEAZ);
		append(voice,Db,octave+1,0.375,VOICEAZ);
		appendTwo(voice,Db,Db,octave+1,0.125,VOICEAZ);
		appendFour(voice,E,Db,C,B/2,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,G,2*E,octave,0.25,CHORDAZ);
		appendInterval(harmony,F,2*Db,octave,0.375,CHORDAZ);
		appendInterval(harmony,F,2*Db,octave,0.0625,CHORDAZ);
		appendInterval(harmony,F,2*Db,octave,0.0625,CHORDAZ);
		four(harmony,E,Db,C,B/2,octave,0.25,CHORDAZ);
		addFour(harmony,G,F,E,D,octave,0.25,CHORDAZ);
		cat();
		silence(0.25);
		appendTwo(harmony,G,2*G,octave-2,0.25,CHORDAZ);
		add();
		
	add();
		//BASS
		create(bass,E,octave-1,0.25,BASSAZ);
		appendGrace(bass,Gf,G,octave-1,0.0625,BASSAZ);
		appendThree(bass,F,D,B/2,octave-1,0.1875,BASSAZ);
		append(bass,G,octave-2,0.25,BASSAZ);
		append(bass,G,octave-1,0.25,BASSAZ);
	add();
	cat();
	//MEASURE # 24
	if(end){
	#ifdef DEBUG
	puts("Measure # 24");
	#endif
		//VOICE
		create(voice,C,octave+1,0.125,VOICEAZ);
		appendSilence(0.125);
		append(voice,E,octave+1,FERMATA(0.125),VOICEAZ);
		append(voice,D,octave+1,FERMATA(0.125),VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave,0.25,CHORDAZ);
		appendArpegioTwo(harmony,G,2*E,octave,0.0625,CHORDAZ);
		appendArpegioTwo(harmony,Gf,2*E,octave,FERMATA(0.125)-0.0625,CHORDAZ);
		appendArpegio(harmony,F,G,2*D,octave,FERMATA(0.125),CHORDAZ);
	add();
		//BASS
		interval(bass,C,G,octave-1,0.25,BASSAZ);
		appendInterval(bass,C,G,octave-1,0.0625,BASSAZ);
		appendInterval(bass,D,A,octave-1,FERMATA(0.125)-0.0625,BASSAZ);
		appendChord(bass,G,2*D,2*B,octave-2,FERMATA(0.125),BASSAZ);
	add();
	cat();
	}
	else{
		//VOICE
		create(voice,C,octave+1,0.125,VOICEAZ);
		appendSilence(0.125);
		append(voice,E,octave+1,0.125,VOICEAZ);
		append(voice,D,octave+1,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave,0.25,CHORDAZ);
		appendArpegioTwo(harmony,G,2*E,octave,0.0625,CHORDAZ);
		appendArpegioTwo(harmony,Gf,2*E,octave,0.0625,CHORDAZ);
		appendArpegio(harmony,F,G,2*D,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,G,octave-1,0.25,BASSAZ);
		appendInterval(bass,C,G,octave-1,0.0625,BASSAZ);
		appendInterval(bass,D,A,octave-1,0.0625,BASSAZ);
		appendChord(bass,G,2*D,2*B,octave-2,0.125,BASSAZ);
	add();
	cat();
	}
	if(!end){
	//MEASURE # 25
	#ifdef DEBUG
	puts("Measure # 25");
	#endif
		//VOICE
		create(voice,C,octave+1,FERMATA(0.125),VOICEAZ);
		append(voice,G,octave,0.125,VOICEAZ);
		appendFour(voice,C,E,Db,C,octave+1,0.25,VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave,FERMATA(0.125),CHORDAZ);
		append(harmony,G,octave,0.125,CHORDAZ);
		four(harmony,C,E,Db,C,octave+1,0.25,CHORDAZ);
		addFour(harmony,E,G,F,E,octave,0.25,CHORDAZ);
		cat();
	add();
		//BASS
		interval(bass,C,G,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		appendTwo(bass,G,G/2,octave-1,0.25,BASSAZ);
	add();
	cat();
	}else{
	//MEASURE # 26
	#ifdef DEBUG
	puts("Measure # 26");
	#endif
		//VOICE
		create(voice,C,octave+1,FERMATA(0.25),VOICEAZ);
		//HARMONY
		interval(harmony,E,2*C,octave,FERMATA(0.25),CHORDAZ);
		appendArpegioFour(harmony,C,E,G,2*C,octave+1,0.25,CHORDAZ);
	add();
		//BASS
		interval(bass,C,G,octave-1,FERMATA(0.25),BASSAZ);
		appendChord(bass,C,G,2*E,octave+1,0.25,BASSAZ);
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
	tempo=50;
	C = G/2;
	song();
	echo(10,0.3,4);
    appendSilence(2);
	puts("Writing wav file: la chaparrita.wav");
	exportToWav("La Chaparrita.wav");
}
