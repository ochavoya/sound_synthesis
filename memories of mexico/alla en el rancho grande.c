#include "soundlib.h"

#define VOICEAZ 150
#define CHORDAZ 30
#define BASSAZ 90


double (*voice)(double)   = oldEsoteric;
double (*harmony)(double) = oldCircleOfRa;
double (*bass)(double)    = oldCircleOfRa;

short octave = 0;

void repeat(short end){
	double storeVolume;
	MESSOFORTE;
	//MEASURE # 1 2 
		//VOICE
		create(voice,G,octave,1.0,VOICEAZ);
		//HARMONY
		silence(0.125);
		appendChord(harmony,G/2,C,E,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,G/2,Bf/2,F,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,G/2,B,F,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,G/2,B,F,octave,0.125,CHORDAZ);
		//BASS
	add();
		interval(bass,C,C/2,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,Cs,Cs/2,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,D,D/2,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	//MEASURE # 3 4
		//VOICE
		create(voice,G,octave,0.875,VOICEAZ);
		//HARMONY
		silence(0.125);
		appendChord(harmony,G/2,C,E,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,G/2,Bf/2,F,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,G/2,B,F,octave,0.125,CHORDAZ);
	add();
		//BASS
		interval(bass,C,C/2,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,Cs,Cs/2,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
		appendInterval(bass,D,D/2,octave-1,0.125,BASSAZ);
		appendSilence(0.125);
	add();
	cat();
		PIANO;
		//VOICE
		create(voice,G,octave-1,0.125,VOICEAZ);
		//HARMONY
		create(harmony,G,octave-1,0.125,CHORDAZ);
	add();
	cat();
	//MEASURE # 5
		//VOICE
		storeVolume = volume;
		volume *= 0.75 ;
		four(voice,G,G,G,F,octave,0.5,VOICEAZ);
		volume = storeVolume;
		addFour(voice,E,E,E,Db,octave,0.5,VOICEAZ);
		//HARMONY
		four(harmony,E,E,E,Db,octave,0.5,CHORDAZ);
		addFour(harmony,G,G,G,F,octave-1,0.5,CHORDAZ);
	add();
		//BASS
		four(bass,C,G,G/2,G,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 6
		//VOICE
		storeVolume = volume;
		volume *= 0.75;
		create(voice,F,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.25,VOICEAZ);
		append(voice,A,octave,0.125,VOICEAZ);
		volume = storeVolume;

		create(voice,Db,octave,0.125,VOICEAZ);
		append(voice,C,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.125,VOICEAZ);

		add();
		//HARMONY
		create(harmony,Db,octave,0.125,CHORDAZ);
		append(harmony,C,octave,0.25,CHORDAZ);
		append(harmony,E,octave,0.125,CHORDAZ);

		create(harmony,F,octave-1,0.125,CHORDAZ);
		append(harmony,E,octave-1,0.25,CHORDAZ);
		append(harmony,G,octave-1,0.125,CHORDAZ);
		add();
	add();
		//BASS
		four(bass,C,G,G/2,G,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 7
		//VOICE
		storeVolume = volume;
		four(voice,A,G,A,Bf,octave,0.5,VOICEAZ);
		volume = storeVolume;
		addFour(voice,F,E,F,Gf,octave,0.5,VOICEAZ);
		//HARMONY
		four(harmony,F,E,F,Gf,octave,0.5,CHORDAZ);
		addFour(harmony,A,G,A,Bf,octave-1,0.5,CHORDAZ);
	add();
		//BASS
		four(bass,C,G,G/2,G,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 8 9
		//VOICE
		storeVolume = volume;
		three(voice,B,F,F,octave,0.75,VOICEAZ);
		volume = storeVolume;
		create(voice,G,octave,0.25,VOICEAZ);
		append(voice,B,octave-1,0.5,VOICEAZ);
		appendSilence(0.125);
		append(voice,G,octave-1,0.125,VOICEAZ);
		add();
		//HARMONY
		silence(0.5);
		storeVolume = volume;
		appendTwo(harmony,G,B/2,octave+1,0.5,CHORDAZ);
		volume = storeVolume;
		interval(harmony,B/2,G,octave,0.25,CHORDAZ);
		appendInterval(harmony,F,B,octave-1,0.5,CHORDAZ);
		appendSilence(0.125);
		appendInterval(harmony,F,G,octave-1,0.125,CHORDAZ);
		add();
	add();
		//BASS
		four(bass,D,G,G/2,G,octave-2,0.5,BASSAZ);
		appendFour(bass,D,G,G/2,G,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 10
		//VOICE
		four(voice,A,G,Gf,G,octave,0.5,VOICEAZ);
		//HARMONY
		four(harmony,A,G,Gf,G,octave,0.5,CHORDAZ);
		four(harmony,F,F,0,F,octave-1,0.5,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,Db,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,B,octave-2,0.125,BASSAZ);
		append(bass,G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,B,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 11
		//VOICE
		create(voice,F,octave,0.125,VOICEAZ);
		append(voice,D,octave,0.25,VOICEAZ);
		append(voice,G,octave-1,0.125,VOICEAZ);
		//HARMONY
		create(harmony,F,octave,0.125,CHORDAZ);
		append(harmony,D,octave,0.25,CHORDAZ);
		append(harmony,G,octave-1,0.125,CHORDAZ);
		create(harmony,A,octave-1,0.125,CHORDAZ);
		append(harmony,F,octave-1,0.25,CHORDAZ);
		append(harmony,F,octave-1,0.125,CHORDAZ);
		add();
	add();
		//BASS
		create(bass,Db,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,B,octave-2,0.125,BASSAZ);
		append(bass,G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,B,octave-2,0.125,BASSAZ);
	add();
	cat();

	//MEASURE # 12
		//VOICE
		four(voice,A,G,A,G,octave-1,0.5,VOICEAZ);
		//HARMONY
		four(harmony,A,G,A,G,octave-1,0.5,CHORDAZ);
		addFour(harmony,F,F,F,F,octave-1,0.5,CHORDAZ);
	add();
		//BASS
		create(bass,Db,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,B,octave-2,0.125,BASSAZ);
		append(bass,G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,B,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 13
		//VOICE
		create(voice,E,octave,0.125,VOICEAZ);
		append(voice,C,octave,0.25,VOICEAZ);
		append(voice,G,octave-1,0.125,VOICEAZ);
		//HARMONY
		interval(harmony,G/2,E,octave,0.125,CHORDAZ);
		appendInterval(harmony,E/2,C,octave,0.25,CHORDAZ);
		appendInterval(harmony,E,G,octave-1,0.125,CHORDAZ);
	add();
		//BASS
		create(bass,Db,octave-2,0.125,BASSAZ);
		appendInterval(bass,G,B,octave-2,0.125,BASSAZ);
		append(bass,G,octave-3,0.125,BASSAZ);
		appendInterval(bass,G,B,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 14
		//VOICE
		four(voice,A,G,E,G,octave-1,0.5,VOICEAZ);
		//HARMONY
		four(harmony,A,G,E,G,octave-1,0.5,CHORDAZ);
		create(harmony,E,octave-1,0.125,CHORDAZ);
		add();
	add();
		//BASS
		four(bass,C,G,G/2,G,octave-2,0.5,BASSAZ);
	add();
	cat();

	//MEASURE # 15 16
		//VOICE
		create(voice,C,octave,0.25,VOICEAZ);
		append(voice,E,octave,0.25+FERMATA(0.125),VOICEAZ);
		DECRESCENDO;
		appendThree(voice,G/2,C,E,octave,0.375,VOICEAZ);
		//HARMONY
		interval(harmony,C,E/2,octave,0.25,CHORDAZ);
		appendInterval(harmony,G/2,E,octave,0.25+FERMATA(0.125),CHORDAZ);
		appendThree(harmony,G/2,C,E,octave,0.375,CHORDAZ);
	add();
		//BASS
		four(bass,C,G,G/2,G,octave-2,0.5,BASSAZ);
		appendInterval(bass,G,G/2,octave-2,FERMATA(0.125),BASSAZ);
	add();
	cat();

	//MEASURE # 17
		//VOICE
		create(voice,G,octave,0.5,VOICEAZ);
		storeVolume = volume;
		volume *= 0.75;
		create(voice,E,octave,0.5,VOICEAZ);
		add();
		volume = storeVolume;
		//HARMONY
		create(harmony,G,octave,0.5,CHORDAZ);
		silence(0.125);
		appendChord(harmony,G/2,C,E,octave,0.125,CHORDAZ);
		appendSilence(0.125);
		appendChord(harmony,G/2,C,E,octave,0.125,CHORDAZ);
		add();
	add();
		//BASS
		interval(bass,C,2*C,octave-2,0.125,BASSAZ);
		appendSilence(0.125);
		append(bass,G,octave-2,0.125,BASSAZ);
	add();
	cat();
	//MEASURE # 18
		//VOICE
		two(voice,F,E,octave,0.5,VOICEAZ);
		storeVolume = volume;
		volume *= 0.75;
		addTwo(voice,Db,C,octave,0.5,VOICEAZ);
		volume=storeVolume;
		//HARMONY
		chord(harmony,G/2,D,F,octave,0.25,CHORDAZ);
		appendChord(harmony,G/2,D,F,octave,0.25,CHORDAZ);
	add();
		//BASS
		four(bass,C,G,G/2,G,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 19 20
		//VOICE
		create(voice,G,octave,0.125,VOICEAZ);
		storeVolume = volume;
		volume *= 0.75 ;
		create(voice,B,octave-1,0.125,VOICEAZ);
		volume = storeVolume;
		add();
		appendInterval(voice,F,B,octave-1,0.5,VOICEAZ);
		appendThree(voice,G/2,B/2,D,octave,0.375,VOICEAZ);
		//HARMONY
		interval(harmony,B/2,G,octave,0.125,CHORDAZ);
		appendInterval(harmony,F,B,octave-1,0.5,CHORDAZ);
		appendThree(harmony,G/2,B/2,D,octave,0.375,CHORDAZ);
	add();
		//BASS
		four(bass,D,G,G/2,G,octave-2,0.5,BASSAZ);
		appendFour(bass,D,G,G/2,G,octave-2,0.5,BASSAZ);
	add();
	cat();

	//MEASURE # 21 22
		//VOICE
		create(voice,B,octave,0.5,VOICEAZ);
		appendTwo(voice,A,G,octave,0.5,VOICEAZ);
		storeVolume = volume;
		volume *= 0.75 ;
		create(voice,G,octave,0.5,VOICEAZ);
		appendTwo(voice,F,E,octave,0.5,VOICEAZ);
		volume = storeVolume;
		add();
		//HARMONY
		chord(harmony,B/2,G,B,octave,0.5,CHORDAZ);
		appendChord(harmony,A/2,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,G/2,E,G,octave,0.25,CHORDAZ);
	add();
		//BASS
		four(bass,D,G,G/2,G,octave-2,0.5,BASSAZ);
		appendFour(bass,D,G,G/2,G,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 23 24
		//VOICE
		create(voice,F,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.5,VOICEAZ);
		appendThree(voice,G/2,C,E,octave,0.375,VOICEAZ);
		storeVolume = volume;
		volume *= 0.75 ;
		create(voice,Db,octave,0.125,VOICEAZ);
		append(voice,C,octave,0.5,VOICEAZ);
		volume = storeVolume;
		add();
		//HARMONY
		chord(harmony,G/2,D,F,octave,0.125,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave,0.5,CHORDAZ);
		appendThree(harmony,G/2,C,E,octave,0.375,CHORDAZ);
	add();
		//BASS
		four(bass,C,G,G/2,G,octave-2,0.5,BASSAZ);
		appendFour(bass,C,G,G/2,G,octave-2,0.5,BASSAZ);
	add();
	cat();
	//MEASURE # 25
		//VOICE
		create(voice,G,octave,0.5,VOICEAZ);
		storeVolume = volume;
		volume *= 0.75;
		create(voice,E,octave,0.5,VOICEAZ);
		volume = storeVolume;
		add();
		//HARMONY
		chord(harmony,G/2,E,G,octave,0.5,CHORDAZ);
	add();
		//BASS
		four(bass,C,G,G/2,G,octave-2,0.5,BASSAZ);
	add();
	cat();

	//MEASURE # 26
		//VOICE
		two(voice,F,E,octave,0.5,VOICEAZ);
		storeVolume = volume;
		volume *= 0.75;
		two(voice,D,C,octave,0.5,VOICEAZ);
		volume = storeVolume;
		add();
		//HARMONY
		chord(harmony,G/2,D,F,octave,0.25,CHORDAZ);
		appendChord(harmony,G/2,F,E,octave,0.25,CHORDAZ);
	add();
		//BASS
		four(bass,C,G,G/2,G,octave-2,0.5,BASSAZ);
	add();
	cat();

	//MEASURE # 27 28
		//VOICE
		create(voice,G,octave,0.125,VOICEAZ);
		append(voice,B,octave-1,0.5,VOICEAZ);
		storeVolume = volume;
		volume *= 0.75;
		create(voice,B,octave-1,0.125,VOICEAZ);
		append(voice,F,octave-1,0.125,VOICEAZ);
		volume=storeVolume;
		add();
		appendThree(voice,G/2,B/2,D,octave,0.375,VOICEAZ);
		//HARMONY
		interval(harmony,G,B/2,octave,0.125,CHORDAZ);
		appendInterval(harmony,F,B,octave-1,0.5,CHORDAZ);
		appendThree(harmony,G/2,B/2,D,octave,0.375,CHORDAZ);
	add();
		//BASS
		//BASS
		four(bass,D,G,G/2,G,octave-2,0.5,BASSAZ);
		appendFour(bass,D,G,G/2,G,octave-2,0.5,BASSAZ);
	add();
	cat();

	//MEASURE # 29 30 31
		//VOICE
		create(voice,B,octave,0.5,VOICEAZ);
		appendTwo(voice,A,G,octave,0.5,VOICEAZ);
		append(voice,F,octave,0.125,VOICEAZ);
		append(voice,E,octave,0.375,VOICEAZ);
		storeVolume = volume;
		volume *= 0.75;
		create(voice,G,octave,0.5,VOICEAZ);
		appendTwo(voice,F,E,octave,0.5,VOICEAZ);
		append(voice,D,octave,0.125,VOICEAZ);
		append(voice,C,octave,0.375,VOICEAZ);
		volume = storeVolume;
		add();
		//HARMONY
		chord(voice,B/2,G,B,octave,0.5,CHORDAZ);
		appendChord(harmony,B/2,F,A,octave,0.25,CHORDAZ);
		appendChord(harmony,B/2,E,G,octave,0.25,CHORDAZ);
		appendChord(harmony,G/2,D,G,octave,0.125,CHORDAZ);
		appendChord(harmony,G/2,C,E,octave,0.375,CHORDAZ);
	add();
		//BASS
		four(bass,D,G,G/2,G,octave-2,0.5,BASSAZ);
		appendFour(bass,D,G,G/2,G,octave-2,0.5,BASSAZ);
		appendFour(bass,C,G,G/2,G,octave-2,0.5,BASSAZ);
	add();
	cat();

	if(end){
		fourChord(harmony,C,E,G,2*C,octave,0.125,CHORDAZ);
		chord(bass,C,G,2*E,octave-2,0.125,BASSAZ);
		add();
		cat();
	}

}

void song(void){
	repeat(0);
	repeat(0);
	cat();
	repeat(1);
	cat();
}

int main(int argc, char **argv){

	tempo=110;
	C = F;

	song();

	echo(10,0.3,4);
    appendSilence(2);

	puts("Writing wav file: alla en el rancho grande.wav");
	exportToWav("Allá en el Rancho Grande.wav");

}
