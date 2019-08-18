#define LINUX 1
#ifdef LINUX
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <linux/soundcard.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define RANDOMFLOAT ((double)random()/RAND_MAX)
#define MINIMUM(x,y) ((x)<(y)?(x):(y))
#define MAXIMUM(x,y) ((x)>(y)?(x):(y))
#define PI 3.141592653589793
#define DOSPI 2*PI
#define ENUMBER 2.718281828
#define ENUMBER2 7.389056099
#define GOLD 0.61803398875
#define MAXIMUM_STACK 16
#define EMPTY (stackPointer==-1)
#define FULL (stackPointer==MAXIMUM_STACK-1)
#define FORTISSIMO  volume=12
#define DOUBLEFORTE volume = 10
#define FORTE       volume=8
#define MESSOFORTE  volume = 7
#define MESSOPIANO  volume = 6
#define PIANO	    volume = 5
#define mPP	        volume = 4
#define PP	        volume = 3
#define PIANISSIMO  volume=2
#define CRESCENDO   gradual(0.5,1.25)
#define DECRESCENDO gradual(1.25,0.5)
#define MARCATO     gradual(1,0.25)
#define FERMATA(x)  1.5*(x)
#define SFORSANDO   gradual(0.75,1)


#ifdef PYTHAGORAS

#define CSHARP 	((double)  256/243)
#define DFLAT 	((double)  256/243)
#define DBEMOL	((double)  9/8)
#define DJUST	((double)  9/8)		//D
#define DSHARP 	((double)  32/27)
#define EFLAT 	((double)  32/27)
#define EJUST	((double)  81/64) 	//E
#define FJUST	((double)  4/3)		//F
#define FSHARP 	((double)  729/512)
#define GFLAT	((double)  729/512)
#define GJUST   ((double)  3/2)		//G
#define GSHARP	((double)  128/81)
#define AFLAT	((double)  128/81)
#define AJUST	((double)  27/16)	//A
#define ASHARP	((double)  16/9)
#define BFLAT   ((double)  16/9)
#define BJUST	((double)  243/128)	//B

#else
	#ifdef UNIFORM_TEMPERAMENT

		#define CSHARP	1.059463094
		#define DFLAT 	1.059463094
		#define DBEMOL	1.122462048
		#define DJUST  	1.122462048  	//D
		#define DSHARP 	1.189207115
		#define EFLAT	1.189207115 	// Eb
		#define EJUST 	1.259921050  	// E
		#define FJUST 	1.334839854  	// F
		#define FSHARP 	1.414213562
		#define GFLAT	1.414213562
		#define GJUST 	1.498307077	//G
		#define GSHARP	1.587401052
		#define AFLAT	1.587401052
		#define AJUST 	1.681792831	//A
		#define ASHARP 	1.781797436
		#define BFLAT 	1.781797436
		#define BJUST 	1.887748625	//B

	#else
		#define CSHARP	((double)16/15)
		#define DFLAT 	((double)16/15)
		#define DBEMOL	((double)10/9)
		#define DJUST  	((double)9/8)  	//D
		#define DSHARP 	((double)6/5)
		#define EFLAT	((double)6/5) 	// Eb
		#define EJUST 	((double)5/4)  	// E
		#define FJUST 	((double)4/3)  	// F
		#define FSHARP 	((double) 45/32)	//
		#define GFLAT	((double) 64/45) //
		#define GJUST 	((double)3/2)	//G
		#define GSHARP	((double)8/5)
		#define AFLAT	((double)8/5)
		#define AJUST 	((double)5/3)	//A
		#define ASHARP 	((double)16/9)
		#define BFLAT 	((double)9/5)
		#define BJUST 	((double)15/8)	//B
	#endif
#endif

#define Cs 	(CSHARP * C)
#define Df	(DFLAT * C)
#define Db 	(DBEMOL * C)
#define D 	(DJUST * C)
#define Ds	(DSHARP * C)
#define Ef	(EFLAT * C)
#define E	(EJUST * C)
#define F 	(FJUST * C)
#define Fs	(FSHARP * C)
#define Gf	(GFLAT * C)
#define G	(GJUST * C)
#define Gs 	(GSHARP * C)
#define Af	(GSHARP * C)
#define A	(AJUST	* C)
#define As	(ASHARP * C)
#define Bf	(BFLAT * C)
#define B	(BJUST * C)


typedef struct {
	double *left;
	double *right;
	unsigned long length;
} Tone;

// Los siguientes bloques se tienen que ir agregando en el archivo wav en el orden que
// aparecen enseguida, FUENTE: http://192.197.62.35/courses/ctec1631/WavFileFormat.html

typedef struct {
        char riff[4]; // "RIFF" (ASCII Characters)  Bytes 0 - 3
        unsigned int TotalLengthOfPackageToFollow;      //  Bytes 4 - 7
        char wave[4]; // "WAVE" (ASCII Characters)  Bytes 8 - 11
} RIFF_Chunk;

typedef struct {
	  char fmt[4];              // "fmt " (ASCII Characters)       Bytes 0  - 3
       int LengthOfFORMATChunk; // always 0x10                     Bytes 4  - 7
 short int Always0x01    ;      // always 0x01                     Bytes 8  - 9
 short int ChannelNumbers;      // (Always 0x01=Mono, 0x02=Stereo) Bytes 10 - 11
	   int SampleRate    ;      // (Binary, in Hz)                 Bytes 12 - 15
	   int BytesPerSecond;      //                                 Bytes 16 - 19
 short int BytesPerSample;      // 1=8 bit Mono, 2=8 bit Stereo or 16 bit Mono, 4=16 bit Stereo   Bytes 20 - 21
 short int BitsPerSample ;      // 8*BytesPerSample                Bytes 22 - 23
} FORMAT_Chunk;

typedef struct {
   char data[4];              // "data" (ASCII Characters)  Bytes 0 - 3
    int LengthOfDataToFollow; //                            Bytes 4 - 7
   //Data (Data Samples goes here)
} DATA_Chunk;


double C=264;
int SIZE=16;
int CHANNELS=2;
long RATE=192000;//44100;//
int DSP;
double SPEED=32000;
double volume=8;
int tempo = 80;
double meterUnit = 0.25;
int notesPerBar = 4 ;
double storeDampingTime;
double dampingTime = 1.0;
int damper = 0;
int actualOctave;
int actualNote;
short startTone=0;



double gaussian(double mean,double variance){
	double r;
	r=sqrt(-2*log(1-RANDOMFLOAT))*cos(DOSPI*RANDOMFLOAT);
	return mean+variance*r;
}


void memoryError(void){
    perror("Memory overflow");
    exit(1);
}

void freeTone(Tone *x){
    free(x->left);
    free(x->right);
    free(x);
}


/*******************************************************************************
********************************************************************************

	This function is in charge of sound synthesis. The wave profile
	is passed as a pointer to a function (which is supposed to take
	arguments in the (0,1) interval).

	The frequency of the sound is passed, altogether with the clock RATE
	of the sound card. There are thus two ways to measure time that have
	to be equivalent.

	The gamma variable and the corresponding operations is introduced to
	avoid umpleasant clicks between succesive tones.

	If the damper is set to true, the instrument will produce exponentially
	damped notes, with a characterstic time that can be configured. The default
	value is one second.

*********************************************************************************
*********************************************************************************/

Tone *makeTone(double (*wave)(double x),double freq,int octave,double duration,double azimuth){

	long index,length;
	double waveNumber;
	double gamma;
	double leftFactor, rightFactor;
	double amp,phase;

	double equalization = exp(1.1 * log (C/freq));

	startTone=1;

    	/*
        The zero octave is our reference (the octave that includes A440)
        to get the correct frequency (octave) we need to multiply freq times
        2^octave.
    	*/
	actualOctave = octave;

	azimuth = PI * azimuth/360;

	leftFactor = cos(azimuth);
	rightFactor = sin(azimuth);


	while(octave>0){
		freq *= 2; --octave;
	}

	while(octave<0){
		freq /= 2; ++octave;
	}

    	/*
    	Tempo is the number of beats per minute. So, 60/tempo is the time
    	for a beat. The meter unit tells us which note corresponds to one
    	beat (default 1/4). So, if the duration is 1/4, that means one meter
    	unit and the actual duration is one beat (60/tempo). If the duration
    	comes as 1/2, that means 2 meter units, and will be transformed to
    	120/tempo, which is what is done in the next line.
    	*/

	duration = (duration * 60) /(tempo * meterUnit);

	Tone *tone =(Tone *)calloc(1,sizeof(Tone));

	if(tone == NULL){
		memoryError();
	}

	length = (long)(duration * RATE);

	tone->length = length ;

	tone->left = (double *)calloc(length,sizeof(double));
	tone->right = (double *)calloc(length,sizeof(double));
	if(tone->left == NULL || tone->right == NULL ){
		memoryError();
	}

    	if(freq==0) return tone; /* silent */

	phase=(double)rand()/RAND_MAX;

	for(index = 0,gamma=1.0; index < length; ++index,gamma*=0.997){
		waveNumber = (double) freq * index / RATE + phase ;
		amp = equalization*(1-gamma)*volume*wave(waveNumber - (long) waveNumber);
		if(damper){
			amp *= exp(-((double)index / RATE)/dampingTime);
		}
		(tone->left)[index] = leftFactor * amp;
		(tone->right)[index] = rightFactor * amp;
	}

	for(index=length-1000,gamma=1.0;index < length;++index,gamma*=0.997){
		(tone->left)[index] *= gamma;
		(tone->right)[index] *= gamma;
	}

	return tone;
}


Tone *stack[MAXIMUM_STACK];
short stackPointer = -1;



void push(Tone *tone){
    if(FULL){
        perror("Stack overflow");
        exit(1);
    }
    ++stackPointer;
    stack[stackPointer]=tone;
}

Tone *pop(void){
    Tone *tone;
    if(EMPTY){
        perror("Stack underflow");
        exit(1);
    }
    tone=stack[stackPointer];
    --stackPointer;
    return tone;
}



void add(void){
    Tone *x = pop(),*y = pop();

    long xlength=x->length , ylength=y->length ,
	min = MINIMUM(xlength,ylength) , max=MAXIMUM(xlength,ylength) , index;

    if(xlength==max){
		for(index=0; index<min;++index){
			(x->left)[index]+=(y->left)[index];
			(x->right)[index]+=(y->right)[index];
		}
		freeTone(y);
	        push(x);
        }
        else{
            for(index=0;index<min;++index){
		(y->left)[index]+=(x->left)[index];
		(y->right)[index]+=(x->right)[index];
            }
	    freeTone(x);
	    push(y);
        }
}

/*******************************************************
********************************************************

    This function concatenates two waves. They have to
    be popped in reverse order to preserve temporal order.
    The first element poped from the stack is lost and
    the corresponding memory is returned to the operating
    system.

**********************************************************

**********************************************************/

void cat(void){
    Tone *y = pop(),*x = pop();
    long index,xlength = x->length , ylength = y->length
	,length = xlength + ylength;

    x->left = (double *)realloc(x->left, length*sizeof(double));
    x->right = (double *)realloc(x->right, length*sizeof(double));
    x->length = length;

    if(x->left==NULL || x->right==NULL){
	memoryError();
    }

    for(index=0;index<y->length;++index){
        (x->left)[xlength + index] = (y->left)[index];
	(x->right)[xlength + index] = (y->right)[index];
    }
    freeTone(y);
    push(x);
}

/******************************************************
	Function that duplicates the sound at the
	top of the stack and pushes in the copy.
********************************************************/

void clone(void){

	Tone *x = pop(),*y;

	long length = x->length,index;

	y = (Tone *)calloc(1,sizeof(Tone));

	if ( y == NULL){
		memoryError();
	}

	y->length = length;

	y->left = (double *)calloc(length, sizeof(double));
	y->right = (double *)calloc(length, sizeof(double));

	if( y->left==NULL || y->right==NULL){
		memoryError();
	}

	for(index = 0 ; index <length ; ++index){
		(y->left)[index] = (x->left)[index];
		(y->right)[index] = (x->right)[index];
	}
	push(x);
	push(y);
}

/******************************************************
	Function that (time) reverses the wave at the
	top of the stack and pushes the copy.
********************************************************/
void reverse(void){
	Tone *x = pop();
	long  length = x->length , low = 0 , high = length -1;
	double temporal;

	while(low < high){

		temporal = (x->left)[low];
		(x->left)[low++] = (x->left)[high];
		(x->left)[high--] = temporal;

		temporal = (x->right)[low];
		(x->right)[low++] = (x->right)[high];
		(x->right)[high--] = temporal;

	}
	push(x);
}

void gradual(double min,double max){

	Tone *x = pop();

	double a = (min - ENUMBER*max)/(1.0-ENUMBER2),

	b = (ENUMBER*max - ENUMBER2*min)/(1.0 - ENUMBER2),factor;

	long length = x->length , index;

	for( index=0 ; index<length ; ++index ){

		factor = exp((double)index/(length-1));

		(x->left)[index] *= (a*factor + b/factor);
		(x->right)[index] *= (a*factor + b/factor);
	}
	push(x);
}

void flip(void){
	Tone *x = pop();
	Tone *y = pop();
	push(x);
	push(y);
}

void scalarMult(double factor){
	Tone *x = pop();
	long i;
	for(i=0;i<x->length;++i){
		x->left[i] *= factor;
		x->right[i] *= factor;
	}
	push(x);
}




Tone *tune[MAXIMUM_STACK];

short storeReady = 0;

void initializeStore(void){
	int index;
	storeReady = 1;
	for(index = 0 ; index < MAXIMUM_STACK ; ++index){
		tune[index] = NULL;
	}
}

void store(short index){
	/************************************************

	Makes a copy of the top of the stack, pops it an
	stores in the tune array

	*************************************************/

	if( ! storeReady ){
		initializeStore();
	}
	if(tune[index] != NULL){
		freeTone(tune[index]);
	}
	clone();
	tune[index] = pop();

}

void recall(short index){

	/************************************************

	Pushes tune[index] to the stack, makes a copy and
	stores it in tune[index].

	*************************************************/

	if( ! storeReady ){
		memoryError();
		exit(1);
	}

	if(tune[index]==NULL){
		puts("Attempt to recall a NULL Tone.");
		exit(1);
	}

	push(tune[index]);

	clone();

	tune[index] = pop();
}



void clear(short index){
	if(!storeReady || tune[index]==NULL){
		return;
	}
	freeTone(tune[index]);
	tune[index]=NULL;
}

#ifdef LINUX

short setSound(void){
	unsigned size=SIZE,channels=CHANNELS,rate=RATE;
	unsigned sizeSet,channelsSet,rateSet;
	int status,uncompatible=0;
	srand(time(0));


		DSP=open("/dev/dsp",O_RDWR);

		status = ioctl(DSP,SOUND_PCM_WRITE_BITS,&size);
		status = ioctl(DSP,SOUND_PCM_WRITE_CHANNELS,&channels);
		status = ioctl(DSP,SOUND_PCM_WRITE_RATE,&rate);

		status = ioctl(DSP,SOUND_PCM_READ_BITS,&sizeSet);
		status = ioctl(DSP,SOUND_PCM_READ_CHANNELS,&channelsSet);
		status = ioctl(DSP,SOUND_PCM_READ_RATE,&rateSet);

		if(size!=sizeSet){
			printf("Unable to set bits number to %d\n",size);
			uncompatible=1;
		}

		if(channels!=channelsSet){
			printf("Unable to set channels number to %d\n",channels);
			uncompatible=1;
		}

		if(RATE!= rateSet){
			printf("Unable to set sample-RATE to %d\n/sec",rate);
			uncompatible=1;
		}

		if(uncompatible){
			perror("Get a real machine!");
			exit(1);
		}

	return 0;
}



void play(void){

    Tone *tone = pop();
    short int output;
    double leftScale=0,rightScale=0;
    long index,length;
    length = tone->length;

    for(index=0;index<length;++index){
	if(leftScale<abs((tone->left)[index])){
        	leftScale=abs((tone->left)[index]);
        	}
	if(rightScale<abs((tone->right)[index])){
        	rightScale=abs((tone->right)[index]);
        	}
	}


    for(index=0;index<tone->length;++index){
	output=(short int)rintf((tone->left)[index]/leftScale*SPEED);
	write(DSP,&output,2);
	output=(short int)rintf((tone->right)[index]/rightScale*SPEED);
	write(DSP,&output,2);
    }
    freeTone(tone);
}

#endif


//----------------------------------------------------
  int exportToWav(char *outFileName) { // Regresa 1 si tiene exito, si no, regresa 0
//----------------------------------------------------

    short int output;
    double leftScale=0,rightScale=0;
    long index,length;
    Tone *tone = pop();

    length = tone->length;

    for(index=0;index<length;++index){
	if(leftScale<abs((tone->left)[index])){
        	leftScale=abs((tone->left)[index]);
        	}
	if(rightScale<abs((tone->right)[index])){
        	rightScale=abs((tone->right)[index]);
        	}
	}

      RIFF_Chunk Riff  ;
      FORMAT_Chunk Format;
      DATA_Chunk Data  ;

      // Escribimos los valores de default de los Chunk's
      Riff.riff[0] = 'R';
      Riff.riff[1] = 'I';
      Riff.riff[2] = 'F';
      Riff.riff[3] = 'F';

      Riff.wave[0] = 'W';
      Riff.wave[1] = 'A';
      Riff.wave[2] = 'V';
      Riff.wave[3] = 'E';

      Format.LengthOfFORMATChunk = 0x10;
      Format.Always0x01 = 0x01;
      Format.fmt[0] = 'f';
      Format.fmt[1] = 'm';
      Format.fmt[2] = 't';
      Format.fmt[3] = ' ';

      Data.data[0] = 'd';
      Data.data[1] = 'a';
      Data.data[2] = 't';
      Data.data[3] = 'a';

      // Otorgamos los valores a los Chunk's

      Format.BytesPerSample = CHANNELS*SIZE/8;
      Format.BitsPerSample  = SIZE;

      Riff.TotalLengthOfPackageToFollow = sizeof(RIFF_Chunk)   +
    		                              sizeof(FORMAT_Chunk) +
    		                              sizeof(DATA_Chunk)   +
    		                              Format.BytesPerSample*tone->length - 8;

      Format.ChannelNumbers = CHANNELS;
      Format.SampleRate     = RATE;
      Format.BytesPerSecond = Format.BytesPerSample*RATE;

      Data.LengthOfDataToFollow = Format.BytesPerSample*tone->length;

      FILE* f = fopen (outFileName, "wb");
      if (f==NULL)
      {
         printf("No se puede crear el archivo %s\n",outFileName);
         return 0;
      }

      fwrite(&Riff  , sizeof(RIFF_Chunk  ), 1, f);
      fwrite(&Format, sizeof(FORMAT_Chunk), 1, f);
      fwrite(&Data  , sizeof(DATA_Chunk  ), 1, f);



    for(index=0;index<tone->length;++index){
	output=(short int)rintf((tone->left)[index]/leftScale*SPEED);
	fwrite(&output, sizeof(short int), 1, f);
	output=(short int)rintf((tone->right)[index]/rightScale*SPEED);
	fwrite(&output, sizeof(short int), 1, f);
    }
      freeTone(tone);
      fclose(f);
      return 1;
}



void create(double (*wave)(double x),double freq,int octave,double duration,double azimuth){
    push(makeTone(wave,freq,octave,duration,azimuth));
}

void silence(double duration){
	create(NULL,0,0,duration,0);
}

void appendSilence(double duration){
	silence(duration);
	cat();
}

void marcato(double (*instr)(double),double FREQ,short octave,double duration,double azimuth){
	create(instr,FREQ,octave,duration,azimuth);
	MARCATO;
}

void martelato(double (*instr)(double),double FREQ,short octave,double duration,double azimuth){
	volume*=1.5;
		create(instr,FREQ,octave,duration/2,azimuth); appendSilence(duration/2);
	volume/=1.5;
}

void estacato(double (*instr)(double),double FREQ,short octave,double duration,double azimuth){
	volume *=1.25;
	create(instr,FREQ,octave,duration*7/8,azimuth);
	appendSilence(duration/8);
	volume /=1.25;
}

void estacatoMarcato(double (*instr)(double),double FREQ,short octave,double duration,double azimuth){
	volume *=1.25;
	create(instr,FREQ,octave,duration*7/8,azimuth);
	appendSilence(duration/8);
	volume /=1.25;
	MARCATO;
}

void estacatoMartelato(double (*instr)(double),double FREQ,short octave,double duration,double azimuth){
	double temp = volume;
	volume *=1.5;
	create(instr,FREQ,octave,duration*7/8,azimuth);
	appendSilence(duration/8);
	volume = temp;
}


void append(double (*wave)(double x),double freq,int octave,double duration,double azimuth){
    create(wave,freq,octave,duration,azimuth);
    cat();
}



void appendMartelato(double (*instr)(double),double FREQ,short octave,double duration,double azimuth){
	volume*=1.5;
		create(instr,FREQ,octave,duration/2,azimuth); appendSilence(duration/2);
	volume/=1.5;
	cat();
}

void appendEstacato(double (*instr)(double),double FREQ,short octave,double duration,double azimuth){
	estacato(instr,FREQ,octave,duration,azimuth);
	cat();
}

void appendMarcato(double (*instr)(double),double FREQ,short octave,double duration,double azimuth){
	marcato(instr,FREQ,octave,duration,azimuth);
	cat();
}


void appendEstacatoMartelato(double (*instr)(double),double FREQ,short octave,double duration,double azimuth){
	double temp = volume;
	volume *=1.5;
	create(instr,FREQ,octave,duration*7/8,azimuth);
	appendSilence(duration/8);
	volume = temp;
	cat();
}

void appendEstacatoMarcato(double (*instr)(double),double FREQ,short octave,double duration,double azimuth){
	estacatoMarcato(instr,FREQ,octave,duration,azimuth);
	cat();
}




void intervalEstacatoMartelato(double (*instr)(double),double x,double y,short octave,double duration,double azimuth){
	estacatoMartelato(instr,x,octave,duration,azimuth);
	estacatoMartelato(instr,y,octave,duration,azimuth);
	add();
}


void appendIntervalEstacatoMartelato(double (*instr)(double),double x,double y,short octave,double duration,double azimuth){
	intervalEstacatoMartelato(instr,x,y,octave,duration,azimuth);
	cat();
}


void intervalEstacatoMarcato(double (*instr)(double),double x,double y,short octave,double duration,double azimuth){
	estacatoMarcato(instr,x,octave,duration,azimuth);
	estacatoMarcato(instr,y,octave,duration,azimuth);
	add();
}


void appendIntervalEstacatoMarcato(double (*instr)(double),double x,double y,short octave,double duration,double azimuth){
	intervalEstacatoMarcato(instr,x,y,octave,duration,azimuth);
	cat();
}




void two(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	duration = duration/2;
	create(instr,X,octave,duration,azimuth);
	append(instr,Y,octave,duration,azimuth);
}


void appendTwo(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	two(instr,X,Y,octave,duration,azimuth);
	cat();
}

void addTwo(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	two(instr,X,Y,octave,duration,azimuth);
	add();
}

void three(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	duration = duration/3;
	two(instr,X,Y,octave,2*duration,azimuth);
	append(instr,Z,octave,duration,azimuth);
}

void addThree(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	three(instr,X,Y,Z,octave,duration,azimuth);
	add();
}

void appendThree(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	three(instr,X,Y,Z,octave,duration,azimuth);
	cat();
}

void four(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	two(instr,X,Y,octave,duration/2,azimuth);
		two(instr,Z,W,octave,duration/2,azimuth);
	cat();
}



void appendFour(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	four(instr,X,Y,Z,W,octave,duration,azimuth);
	cat();
}

void addFour(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	four(instr,X,Y,Z,W,octave,duration,azimuth);
	add();
}

void six(double(*instr)(double),double u,double v,double w, double x,double y, double z,short octave,double duration,double azimuth){
	three(instr,u,v,w,octave,duration/2,azimuth);
	appendThree(instr,x,y,z,octave,duration/2,azimuth);
}

void addSix(double(*instr)(double),double u,double v,double w, double x,double y, double z,short octave,double duration,double azimuth){
	six(instr,u,v,w,x,y,z,octave,duration,azimuth);
	add();
}

void appendSix(double(*instr)(double),double u,double v,double w, double x,double y, double z,short octave,double duration,double azimuth){
	six(instr,u,v,w,x,y,z,octave,duration,azimuth);
	cat();
}

void sixEstacato(double(*instr)(double),double u,double v,double w, double x,double y, double z,short octave,double duration,double azimuth){
	estacato(instr,u,octave,duration/6,azimuth);
	estacato(instr,v,octave,duration/6,azimuth);
	cat();
	estacato(instr,w,octave,duration/6,azimuth);
	cat();
	estacato(instr,x,octave,duration/6,azimuth);
	cat();
	estacato(instr,y,octave,duration/6,azimuth);
	cat();
	estacato(instr,z,octave,duration/6,azimuth);
	cat();
}


void chord(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
		create(instr,Y,octave,duration,azimuth);
				create(instr,Z,octave,duration,azimuth);
	add();
	add();
}

void addChord(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	chord(instr,X,Y,Z,octave,duration,azimuth);
	add();
}

void appendChord(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	chord(instr,X,Y,Z,octave,duration,azimuth);
	cat();
}

void fourChord(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
		create(instr,Y,octave,duration,azimuth);
				create(instr,Z,octave,duration,azimuth);
					create(instr,W,octave,duration,azimuth);
	add();
	add();
	add();
}

void appendFourChord(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	fourChord(instr,X,Y,Z,W,octave,duration,azimuth);
	cat();
}

void fiveChord(double (*instr)(double),double X,double Y,double Z,double U,double V,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
		create(instr,Y,octave,duration,azimuth);
				create(instr,Z,octave,duration,azimuth);
					create(instr,U,octave,duration,azimuth);
						create(instr,V,octave,duration,azimuth);
	add();
	add();
	add();
	add();
}

void appendFiveChord(double (*instr)(double),double X,double Y,double Z,double U,double V,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
		create(instr,Y,octave,duration,azimuth);
				create(instr,Z,octave,duration,azimuth);
					create(instr,U,octave,duration,azimuth);
						create(instr,V,octave,duration,azimuth);
	add();
	add();
	add();
	add();
	cat();
}

void addFourChord(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	fourChord(instr,X,Y,Z,W,octave,duration,azimuth);
	add();
}

void fourChordEstacato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	estacato(instr,X,octave,duration,azimuth);
		estacato(instr,Y,octave,duration,azimuth);
				estacato(instr,Z,octave,duration,azimuth);
					estacato(instr,W,octave,duration,azimuth);
	add();
	add();
	add();
}

void appendFourChordEstacato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	estacato(instr,X,octave,duration,azimuth);
		estacato(instr,Y,octave,duration,azimuth);
				estacato(instr,Z,octave,duration,azimuth);
					estacato(instr,W,octave,duration,azimuth);
	add();
	add();
	add();
	cat();
}

void fourChordEstacatoMarcato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	estacato(instr,X,octave,duration,azimuth);
		estacato(instr,Y,octave,duration,azimuth);
				estacato(instr,Z,octave,duration,azimuth);
					estacato(instr,W,octave,duration,azimuth);
	add();
	add();
	add();
	MARCATO;
}

void chordEstacatoMartelato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	estacatoMartelato(instr,X,octave,duration,azimuth);
		estacatoMartelato(instr,Y,octave,duration,azimuth);
				estacatoMartelato(instr,Z,octave,duration,azimuth);
	add();
	add();
}

void appendChordEstacatoMartelato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	estacatoMartelato(instr,X,octave,duration,azimuth);
		estacatoMartelato(instr,Y,octave,duration,azimuth);
				estacatoMartelato(instr,Z,octave,duration,azimuth);
	add();
	add();
	cat();
}

void fourChordEstacatoMartelato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	estacatoMartelato(instr,X,octave,duration,azimuth);
		estacatoMartelato(instr,Y,octave,duration,azimuth);
				estacatoMartelato(instr,Z,octave,duration,azimuth);
					estacatoMartelato(instr,W,octave,duration,azimuth);
	add();
	add();
	add();
}


void addFourChordEstacato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	fourChordEstacato(instr,X,Y,Z,W,octave,duration,azimuth);
	add();
}

void arpegio(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
		silence(duration/5);append(instr,Y,octave,4*duration/5,azimuth);
				silence(2*duration/5);append(instr,Z,octave,3*duration/5,azimuth);
	add();
	add();
}

void arpegioEstacato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	estacato(instr,X,octave,duration,azimuth);
		silence(duration/5);appendEstacato(instr,Y,octave,4*duration/5,azimuth);
				silence(2*duration/5);appendEstacato(instr,Z,octave,3*duration/5,azimuth);
	add();
	add();
}
void arpegioEstacatoMartelato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	estacatoMartelato(instr,X,octave,duration,azimuth);
		silence(duration/5);appendEstacatoMartelato(instr,Y,octave,4*duration/5,azimuth);
				silence(2*duration/5);appendEstacatoMartelato(instr,Z,octave,3*duration/5,azimuth);
	add();
	add();
}



void appendArpegio(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
		silence(duration/10);append(instr,Y,octave,9*duration/10,azimuth);
				silence(1*duration/5);append(instr,Z,octave,3*duration/5,azimuth);
	add();
	add();
	cat();
}

void appendArpegioEstacato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	estacato(instr,X,octave,duration,azimuth);
		silence(duration/5);appendEstacato(instr,Y,octave,4*duration/5,azimuth);
				silence(2*duration/5);appendEstacato(instr,Z,octave,3*duration/5,azimuth);
	add();
	add();
	cat();
}


void arpegioDown(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	create(instr,Z,octave,duration,azimuth);
		silence(duration/10);append(instr,Y,octave,9*duration/10,azimuth);
				silence(1*duration/5);append(instr,X,octave,4*duration/5,azimuth);
	add();
	add();
}


void appendArpegioDown(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	create(instr,Z,octave,duration,azimuth);
		silence(duration/10);append(instr,Y,octave,9*duration/10,azimuth);
				silence(duration/5);append(instr,X,octave,4*duration/5,azimuth);
	add();
	add();
	cat();
}

void arpegioTwo(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
		silence(duration/5);append(instr,Y,octave,4*duration/5,azimuth);
	add();
}

void appendArpegioTwo(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
		silence(duration/5);append(instr,Y,octave,4*duration/5,azimuth);
	add();
	cat();
}

void arpegioFour(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
		silence(duration/10);append(instr,Y,octave,9*duration/10,azimuth);
				silence(duration/5);append(instr,Z,octave,4*duration/5,azimuth);
					silence(3*duration/10);append(instr,W,octave,7*duration/10,azimuth);
	add();
	add();
	add();
}

void appendArpegioFour(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
		silence(duration/10);append(instr,Y,octave,9*duration/10,azimuth);
				silence(duration/5);append(instr,Z,octave,4*duration/5,azimuth);
					silence(3*duration/10);append(instr,W,octave,7*duration/10,azimuth);
	add();
	add();
	add();
	cat();
}


void arpegioFourMartelato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	martelato(instr,X,octave,duration,azimuth);
		silence(duration/10);appendMartelato(instr,Y,octave,9*duration/10,azimuth);
				silence(duration/5);appendMartelato(instr,Z,octave,4*duration/5,azimuth);
					silence(3*duration/10);appendMartelato(instr,W,octave,7*duration/10,azimuth);
	add();
	add();
	add();
}

void appendArpegioFourMartelato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	martelato(instr,X,octave,duration,azimuth);
		silence(duration/10);appendMartelato(instr,Y,octave,9*duration/10,azimuth);
				silence(duration/5);appendMartelato(instr,Z,octave,4*duration/5,azimuth);
					silence(3*duration/10);appendMartelato(instr,W,octave,7*duration/10,azimuth);
	add();
	add();
	add();
	cat();
}

void arpegioFourEstacatoMarcato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	estacatoMarcato(instr,X,octave,duration,azimuth);
		silence(duration/10);appendEstacatoMarcato(instr,Y,octave,9*duration/10,azimuth);
				silence(duration/5);appendEstacatoMarcato(instr,Z,octave,4*duration/5,azimuth);
					silence(3*duration/10);appendEstacatoMarcato(instr,W,octave,7*duration/10,azimuth);
	add();
	add();
	add();
}

void arpegioFourEstacatoMartelato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	estacatoMartelato(instr,X,octave,duration,azimuth);
		silence(duration/10);appendEstacatoMartelato(instr,Y,octave,9*duration/10,azimuth);
				silence(duration/5);appendEstacatoMartelato(instr,Z,octave,4*duration/5,azimuth);
					silence(3*duration/10);appendEstacatoMartelato(instr,W,octave,7*duration/10,azimuth);
	add();
	add();
	add();
}
void appendArpegioFourEstacatoMartelato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	estacatoMartelato(instr,X,octave,duration,azimuth);
		silence(duration/10);appendEstacatoMartelato(instr,Y,octave,9*duration/10,azimuth);
				silence(duration/5);appendEstacatoMartelato(instr,Z,octave,4*duration/5,azimuth);
					silence(3*duration/10);appendEstacatoMartelato(instr,W,octave,7*duration/10,azimuth);
	add();
	add();
	add();
	cat();
}


void arpegioFive(double (*instr)(double),double X,double Y,double Z,double U,double V,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
		silence(duration/10);append(instr,Y,octave,9*duration/10,azimuth); add();
				silence(duration/5);append(instr,Z,octave,4*duration/5,azimuth); add();
					silence(3*duration/10);append(instr,U,octave,7*duration/10,azimuth); add();
                                               silence(2*duration/5);append(instr,V,octave,3*duration/5,azimuth); add();
}

void appendArpegioFive(double (*instr)(double),double X,double Y,double Z,double U,double V,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
		silence(duration/10);append(instr,Y,octave,9*duration/10,azimuth); add();
				silence(duration/5);append(instr,Z,octave,4*duration/5,azimuth); add();
					silence(3*duration/10);append(instr,U,octave,7*duration/10,azimuth); add();
                                               silence(2*duration/5);append(instr,V,octave,3*duration/5,azimuth); add();
	cat();
}

void addArpegioFive(double (*instr)(double),double X,double Y,double Z,double U,double V,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
		silence(duration/10);append(instr,Y,octave,9*duration/10,azimuth); add();
				silence(duration/5);append(instr,Z,octave,4*duration/5,azimuth); add();
					silence(3*duration/10);append(instr,U,octave,7*duration/10,azimuth); add();
                                               silence(2*duration/5);append(instr,V,octave,3*duration/5,azimuth); add();
	add();
}





void chordMarcato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	marcato(instr,X,octave,duration,azimuth);
		marcato(instr,Y,octave,duration,azimuth);
				marcato(instr,Z,octave,duration,azimuth);
	add();
	add();
}

void addChordMarcato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	chordMarcato(instr,X,Y,Z,octave,duration,azimuth);
	add();
}

void appendChordMarcato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	chordMarcato(instr,X,Y,Z,octave,duration,azimuth);
	cat();
}

void fourChordMarcato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	marcato(instr,X,octave,duration,azimuth);
		marcato(instr,Y,octave,duration,azimuth);
				marcato(instr,Z,octave,duration,azimuth);
					marcato(instr,W,octave,duration,azimuth);
	add();
	add();
	add();
}

void twoMarcato(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	duration/=2;
	marcato(instr,X,octave,duration,azimuth);
		marcato(instr,Y,octave,duration,azimuth);
	cat();
}

void appendTwoMarcato(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	duration/=2;
	marcato(instr,X,octave,duration,azimuth);
		marcato(instr,Y,octave,duration,azimuth);
	cat();
	cat();
}

void appendTwoMartelato(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	duration/=2;
	martelato(instr,X,octave,duration,azimuth);
		martelato(instr,Y,octave,duration,azimuth);
	cat();
	cat();
}


void threeMarcato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	duration/=3;
	marcato(instr,X,octave,duration,azimuth);
		marcato(instr,Y,octave,duration,azimuth);
				marcato(instr,Z,octave,duration,azimuth);
	cat();
	cat();
}

void appendThreeMarcato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	duration/=3;
	marcato(instr,X,octave,duration,azimuth);
		marcato(instr,Y,octave,duration,azimuth);
				marcato(instr,Z,octave,duration,azimuth);
	cat();
	cat();
	cat();
}



void fourMarcato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	duration/=4;
	marcato(instr,X,octave,duration,azimuth);
		marcato(instr,Y,octave,duration,azimuth);
				marcato(instr,Z,octave,duration,azimuth);
					marcato(instr,W,octave,duration,azimuth);
	cat();
	cat();
	cat();
}

void appendFourMarcato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	duration/=4;
	marcato(instr,X,octave,duration,azimuth);
		marcato(instr,Y,octave,duration,azimuth);
				marcato(instr,Z,octave,duration,azimuth);
					marcato(instr,W,octave,duration,azimuth);
	cat();
	cat();
	cat();
	cat();
}


void appendFourChordMarcato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	marcato(instr,X,octave,duration,azimuth);
		marcato(instr,Y,octave,duration,azimuth);
				marcato(instr,Z,octave,duration,azimuth);
					marcato(instr,W,octave,duration,azimuth);
	add();
	add();
	add();
	cat();
}

void appendIntervalMarcato(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	marcato(instr,X,octave,duration,azimuth);
	marcato(instr,Y,octave,duration,azimuth);
	add();
	cat();
}


void chordEstacato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	estacato(instr,X,octave,duration,azimuth);
		estacato(instr,Y,octave,duration,azimuth);
				estacato(instr,Z,octave,duration,azimuth);
	add();
	add();
}

void twoEstacato(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	estacato(instr,X,octave,duration/2,azimuth);
		estacato(instr,Y,octave,duration/2,azimuth);
	cat();
}

void appendTwoEstacato(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	estacato(instr,X,octave,duration/2,azimuth);
		estacato(instr,Y,octave,duration/2,azimuth);
	cat();
	cat();
}

void threeEstacato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	estacato(instr,X,octave,duration/3,azimuth);
		estacato(instr,Y,octave,duration/3,azimuth);
				estacato(instr,Z,octave,duration/3,azimuth);
	cat();
	cat();
}

void appendThreeEstacato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	estacato(instr,X,octave,duration/3,azimuth);
		estacato(instr,Y,octave,duration/3,azimuth);
				estacato(instr,Z,octave,duration/3,azimuth);
	cat();
	cat();
	cat();
}




void addChordEstacato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	chord(instr,X,Y,Z,octave,duration,azimuth);
	add();
}

void appendChordEstacato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	chordEstacato(instr,X,Y,Z,octave,duration,azimuth);
	cat();
}


void chordMartelato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	martelato(instr,X,octave,duration,azimuth);
		martelato(instr,Y,octave,duration,azimuth);
				martelato(instr,Z,octave,duration,azimuth);
	add();
	add();
}

void addChordMartelato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	chordMartelato(instr,X,Y,Z,octave,duration,azimuth);
	add();
}

void appendChordMartelato(double (*instr)(double),double X,double Y,double Z,short octave,double duration,double azimuth){
	chordMartelato(instr,X,Y,Z,octave,duration,azimuth);
	cat();
}

void fourMartelato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	duration/=4;
	martelato(instr,X,octave,duration,azimuth);
		martelato(instr,Y,octave,duration,azimuth);
				martelato(instr,Z,octave,duration,azimuth);
					martelato(instr,W,octave,duration,azimuth);
	cat();
	cat();
	cat();
}

void appendFourMartelato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	duration/=4;
	martelato(instr,X,octave,duration,azimuth);
		martelato(instr,Y,octave,duration,azimuth);
				martelato(instr,Z,octave,duration,azimuth);
					martelato(instr,W,octave,duration,azimuth);
	cat();
	cat();
	cat();
	cat();
}




void fourChordMartelato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	martelato(instr,X,octave,duration,azimuth);
		martelato(instr,Y,octave,duration,azimuth);
				martelato(instr,Z,octave,duration,azimuth);
					martelato(instr,W,octave,duration,azimuth);
	add();
	add();
	add();
}

void appendFourChordMartelato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	martelato(instr,X,octave,duration,azimuth);
		martelato(instr,Y,octave,duration,azimuth);
				martelato(instr,Z,octave,duration,azimuth);
					martelato(instr,W,octave,duration,azimuth);
	add();
	add();
	add();
	cat();
}


void interval(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
	create(instr,Y,octave,duration,azimuth);
	add();
}
void addInterval(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
	create(instr,Y,octave,duration,azimuth);
	add();
	add();
}

void appendInterval(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
	create(instr,Y,octave,duration,azimuth);
	add();
	cat();
}

void intervalEstacato(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	estacato(instr,X,octave,duration,azimuth);
	estacato(instr,Y,octave,duration,azimuth);
	add();
}

void appendIntervalEstacato(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	estacato(instr,X,octave,duration,azimuth);
	estacato(instr,Y,octave,duration,azimuth);
	add();
	cat();
}

void fourEstacato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	twoEstacato(instr,X,Y,octave,duration/2,azimuth);
		twoEstacato(instr,Z,W,octave,duration/2,azimuth);
	cat();
}
void appendFourEstacato(double (*instr)(double),double X,double Y,double Z,double W,short octave,double duration,double azimuth){
	fourEstacato(instr,X,Y,Z,W,octave,duration,azimuth);
	cat();
}

void intervalMartelato(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	martelato(instr,X,octave,duration,azimuth);
	martelato(instr,Y,octave,duration,azimuth);
	add();
}

void appendIntervalMartelato(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	martelato(instr,X,octave,duration,azimuth);
	martelato(instr,Y,octave,duration,azimuth);
	add();
	cat();
}


void intervalMarcato(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	marcato(instr,X,octave,duration,azimuth);
	marcato(instr,Y,octave,duration,azimuth);
	add();
}


void arpegioInterval(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
		silence(duration/5);append(instr,Y,octave,4*duration/5,azimuth);
	add();
}


void grace(double (*instr)(double),double x,double y,int octave,double duration,double az){
	if(duration<0.25){
		create(instr,x,octave,duration/4,az);
		append(instr,y,octave,duration*3/4,az);
	}
	else
		{
		create(instr,x,octave,duration/8,az);
		append(instr,y,octave,duration*7/8,az);
		}
}

void appendGrace( double (*instr)(double),double x,double y,int octave,double duration,double az){
	grace(instr,x,y,octave,duration,az);
	cat();
}

void doubleGrace(double (*instr)(double),double x,double y,double z,int octave,double duration,double az){
	if(duration<0.25){
		create(instr,x,octave,duration/4,az);
		append(instr,y,octave,duration/4,az);
		append(instr,z,octave,duration/2,az);
	}
	else
		{
		create(instr,x,octave,duration/8,az);
		append(instr,y,octave,duration/8,az);
		append(instr,z,octave,duration*3/4,az);
		}
}

void appendDoubleGrace(double (*instr)(double),double x,double y,double z,int octave,double duration,double az){
	if(duration<0.25){
		create(instr,x,octave,duration/4,az);
		append(instr,y,octave,duration/4,az);
		append(instr,z,octave,duration/2,az);
	}
	else
		{
		create(instr,x,octave,duration/8,az);
		append(instr,y,octave,duration/8,az);
		append(instr,z,octave,duration*3/4,az);
		}
	cat();
}


void appendArpegioInterval(double (*instr)(double),double X,double Y,short octave,double duration,double azimuth){
	create(instr,X,octave,duration,azimuth);
		silence(duration/5);append(instr,Y,octave,4*duration/5,azimuth);
	add();
	cat();
}


void echo(double delay,double decay,int reflections){
	long step = delay*RATE/340, i,lastLength;
	Tone *tone = pop();
	lastLength = tone->length;
	tone->length += reflections * step;
	tone->left=(double *)realloc(tone->left,tone->length*sizeof(double));
	tone->right=(double *)realloc(tone->right,tone->length*sizeof(double));
	for(i=lastLength;i<tone->length;++i){
		tone->left[i]=tone->right[i]=0;
	}
	for(i=step;i<tone->length;++i){
		tone->left[i]+=(tone->left[i-step]+tone->right[i-step])*decay;
		tone->right[i]+=(tone->left[i-step]+tone->right[i-step])*decay;
	}
	push(tone);
}




double trumpet(double x){
	short i;
	double value = 0, norm=0, amp[16]={0.28,0.31,0.33,0.32,0.35,
			0.32,0.3,0.29,0.26,0.2,0.13,0.19,0.15,0.14,0.12,0.08};
#define TRUMPET_CONSTANT 1.0;

	if(startTone){
		//for(i=0;i<16;++i){
		//	amp[i] = gaussian(1,0.2)*amp[i]*TRUMPET_CONSTANT;
		//}
		startTone=0;
	}

	damper = 0;
	x=x/2;
	while(x>1)x-=1;
	while(x<0)x+=1;
	x = DOSPI * x ;
	for(i=0;i<16;i+=1){
		value += amp[i]*sin( (i+1)*x );
	}
	return value;
}

double trombone(double x){
	short i;
	double value = 0, norm=0, amp[16]={0.31,0.36,0.3,0.35,0.33,
			0.31,0.3,0.25,0.23,0.23,0.19,0.16,0.13,0.12,0.08,0.07};
#define TROMBONE_CONSTANT 1.0;

	if(startTone){
		//for(i=0;i<16;++i){
		//	amp[i] = gaussian(1,0.2)*amp[i]*TROMBONE_CONSTANT;
		//}
		startTone=0;
	}

	damper = 0;
	x=x/2;
	while(x>1)x-=1;
	while(x<0)x+=1;
	x = DOSPI * x ;
	for(i=0;i<16;i+=1){
		value += amp[i]*sin( (i+1)*x );
	}
	return value;
}

double frenchHorn(double x){
	short i;
	double value = 0, norm=0, amp[10]={0.37,0.46,0.45,0.39,
		0.33,0.29,0.25,0.16,0.14,0.06};
#define FRENCH_HORN_CONSTANT 1.0;

	if(startTone){
		//for(i=0;i<10;++i){
		//	amp[i] = gaussian(1,0.2)*amp[i]*FRENCH_HORN_CONSTANT;
		//}
		startTone=0;
	}

	damper = 0;
	x=x/2;
	while(x>1)x-=1;
	while(x<0)x+=1;
	x = DOSPI * x ;
	for(i=0;i<16;i+=1){
		value += amp[i]*sin( (i+1)*x );
	}
	return value;
}



double violin(double x){
	return trumpet(-x);
}


double square(double x){
	damper=0;
	while(x>1)x-=1;
	if(x<0.5)
		return -1;
	else
		return 1;
}


double pure(double x){
	damper = 0;
	while(x>1)x-=1;
	x = DOSPI*x;
	return sin(x);
}

#define ESOTERICNUMBER 8



double esoteric(double x){

	/******************************************************
	NOTICE THAT GOLD IS NOT THE GOLDEN RATIO, BUT ITS SQUARE
	ROOT, SO THAT THE GOLDEN RATION APPEARS IN THE POWER SPECTRUM.
	*******************************************************/

	double value;
	static double phase[ESOTERICNUMBER];
	static int index[ESOTERICNUMBER]={1,2,3,5,8,10,15,17};//{1,2,3,5,6,10,12,15};
	static double amp[ESOTERICNUMBER];
	int i;
	static double norm=0;

	if(startTone){
		for(i=0;i<ESOTERICNUMBER;++i){
			phase[i]=(double)rand()/RAND_MAX;
			amp[i] = 1/sqrt(index[i]);
			norm+=amp[i]*amp[i];
		}
		norm=sqrt(norm);
		for(i=0;i<ESOTERICNUMBER;++i){
			amp[i] = gaussian(1,0.2)*amp[i]*10/norm;
		}
		startTone=0;
	}

	while(x>1)x-=1;
	value = damper = 0;

	for(i=ESOTERICNUMBER-1;i>=0;--i){
		value= value*GOLD + cos(index[i]*DOSPI*(x+phase[i]))*amp[i];
	}

	return value;
}




double circleOfRa(double x){

	/******************************************************
	NOTICE THAT GOLD IS NOT THE GOLDEN RATIO, BUT ITS SQUARE
	ROOT, SO THAT THE GOLDEN RATION APPEARS IN THE POWER SPECTRUM.
	*******************************************************/


	double value;
	static double phase[ESOTERICNUMBER];
	static int index[ESOTERICNUMBER]={1,2,3,5,8,10,15,17};//{1,2,3,5,8,13,21,34};
	static double amp[ESOTERICNUMBER];
	int i;
	static double norm=0;

	if(startTone){
		for(i=0;i<ESOTERICNUMBER;++i){
			phase[i]=(double)rand()/RAND_MAX;
			amp[i] = 1/sqrt(index[i]);
			norm+=amp[i]*amp[i];
		}
		norm=sqrt(norm);
		for(i=0;i<ESOTERICNUMBER;++i){
			amp[i] = gaussian(1,0.2)*amp[i]*10/norm;
		}
		startTone=0;
	}

	while(x>1)x-=1;
	value =0;

	damper = 1.0;

	for(i=ESOTERICNUMBER-1;i>=0;--i){
		value= value*GOLD + cos(index[i]*DOSPI*(x+phase[i]))*amp[i];
	}

	return value;
}

double piano(double x){


	/******************************************************
	NOTICE THAT GOLD IS NOT THE GOLDEN RATIO, BUT ITS SQUARE
	ROOT, SO THAT THE GOLDEN RATION APPEARS IN THE POWER SPECTRUM.
	*******************************************************/

	double value;
	static double phase[7];
	static int index[7]={1,2,5,6,8,9,12};
	static double norm;
	int i;

	if(startTone){
		for(i=0;i<7;++i){
			phase[i]=(double)rand()/RAND_MAX;
		}
		norm=sqrt(7);
		startTone=0;
	}

	while(x>1)x-=1;
	value =0;

	damper = 1;

	for(i=6;i>=0;--i){
		value= value*GOLD + cos(index[i]*DOSPI*(x+phase[i]));
	}

	return value/norm;
}



double organ(double x){


	/******************************************************
	NOTICE THAT GOLD IS NOT THE GOLDEN RATIO, BUT ITS SQUARE
	ROOT, SO THAT THE GOLDEN RATION APPEARS IN THE POWER SPECTRUM.
	*******************************************************/

	double value;
	static double phase[7];
	static int index[7]={1,2,5,6,8,9,12};
	static double norm ;
	int i;

	if(startTone){
		for(i=0;i<7;++i){
			phase[i]=(double)rand()/RAND_MAX;
		}
		norm=sqrt(7);
		startTone=0;
	}

	while(x>1)x-=1;
	value = damper = 0;

	for(i=6;i>=0;--i){
		value= value*GOLD + cos(index[i]*DOSPI*(x+phase[i]));
	}

	return value/norm;
}

double oldEsoteric(double x){

	/******************************************************
	NOTICE THAT GOLD IS NOT THE GOLDEN RATIO, BUT ITS SQUARE
	ROOT, SO THAT THE GOLDEN RATION APPEARS IN THE POWER SPECTRUM.
	*******************************************************/


	double sinx,cosx,sin2x,cos2x,sin3x,cos3x,sin5x,cos5x,sin8x,cos8x,sin13x,cos13x;

	while(x>1)x-=1;

	damper = 0;

	x = DOSPI * x ;

	sinx = sin(x);   cosx = cos(x);

	sin2x = 2 * sinx * cosx; cos2x = cosx*cosx - sinx * sinx;

	sin3x = sin2x * cosx + sinx *cos2x; cos3x = cos2x*cosx-sin2x*sinx;

	sin5x = sin3x*cos2x+sin2x*cos3x; cos5x = cos3x * cos2x - sin2x * cos2x;

	sin8x = sin5x * cos3x + sin3x * cos5x ; cos8x = cos3x * cos5x - sin3x * sin5x;

	sin13x = sin8x*cos5x + sin5x*cos8x;

	return  (double)(sinx + GOLD * (
			 sin2x + GOLD * (
				sin3x + GOLD * (
					sin5x+GOLD*(
						sin8x + GOLD *
								sin13x ) ) ) ));
}


double oldCircleOfRa(double x){

	double sinx,cosx,sin2x,cos2x,sin3x,cos3x,sin5x,cos5x,sin8x,cos8x,sin13x,cos13x;

	damper = 1;

	while(x>1)x-=1;

	x = DOSPI * x ;

	sinx = sin(x);   cosx = cos(x);

	sin2x = 2 * sinx * cosx; cos2x = cosx*cosx - sinx * sinx;

	sin3x = sin2x * cosx + sinx *cos2x; cos3x = cos2x*cosx-sin2x*sinx;

	sin5x = sin3x*cos2x+sin2x*cos3x; cos5x = cos3x * cos2x - sin2x * cos2x;

	sin8x = sin5x * cos3x + sin3x * cos5x ; cos8x = cos3x * cos5x - sin3x * sin5x;

	sin13x = sin8x*cos5x + sin5x*cos8x;

	return  (double)(sinx + GOLD * (
			 sin2x + GOLD * (
				sin3x + GOLD * (
					sin5x+GOLD*(
						sin8x + GOLD *
								sin13x ) ) ) ));

}

#define ORGAN_CHANNELS 8

double newOrgan(double x){
        double value=0;
	double phase[ORGAN_CHANNELS];
        double amp[ORGAN_CHANNELS]={
		        1.0,
                0.5,
                1.0,
                0.75,
                0.5,
                0.35,
                0.0,
                0.25,
        };

	double norm ;
	int i;

	if(startTone){
		for(i=0;i<ORGAN_CHANNELS;++i){
			phase[i]=(double)rand()/RAND_MAX;
			norm += amp[i]*amp[i];
		}
		norm=sqrt(norm);
		startTone=0;
		for(i=0;i<ORGAN_CHANNELS;++i){
			amp[i] /= norm;
		}
	}

	while(x>1)x-=1;
	damper = 0;

	for(i=0;i<ORGAN_CHANNELS;++i){
		value += amp[i]*cos(DOSPI*((i+1)*x+phase[i]));
	}

	return value;
}

double sacredOrgan(double x){

	/******************************************************
	NOTICE THAT GOLD IS NOT THE GOLDEN RATIO, BUT ITS SQUARE
	ROOT, SO THAT THE GOLDEN RATION APPEARS IN THE POWER SPECTRUM.
	*******************************************************/


	double sinx,cosx,sin2x,cos2x,sin3x,cos3x,sin5x,cos5x,sin4x,cos4x;

	while(x>1)x-=1;

	damper = 0;

	x = DOSPI * x ;

	sinx = sin(x);   cosx = cos(x);

	sin2x = 2 * sinx * cosx; cos2x = cosx*cosx - sinx * sinx;

    sin4x = 2 * sin2x * cos2x; cos4x = cos2x*cos2x -sin2x*sin2x;

	sin3x = sin2x * cosx + sinx *cos2x; cos3x = cos2x*cosx-sin2x*sinx;

	sin5x = sin3x*cos2x+sin2x*cos3x; cos5x = cos3x * cos2x - sin2x * cos2x;



	return  (sinx + sin2x/2 + sin3x/3 + sin4x/4+sin5x/5);
}

double sacredPiano(double x){

	/******************************************************
	NOTICE THAT GOLD IS NOT THE GOLDEN RATIO, BUT ITS SQUARE
	ROOT, SO THAT THE GOLDEN RATION APPEARS IN THE POWER SPECTRUM.
	*******************************************************/


	double sinx,cosx,sin2x,cos2x,sin3x,cos3x,sin5x,cos5x,sin4x,cos4x;

	while(x>1)x-=1;

	damper = 1;

	x = DOSPI * x ;

	sinx = sin(x);   cosx = cos(x);

	sin2x = 2 * sinx * cosx; cos2x = cosx*cosx - sinx * sinx;

    sin4x = 2 * sin2x * cos2x; cos4x = cos2x*cos2x -sin2x*sin2x;

	sin3x = sin2x * cosx + sinx *cos2x; cos3x = cos2x*cosx-sin2x*sinx;

	sin5x = sin3x*cos2x+sin2x*cos3x; cos5x = cos3x * cos2x - sin2x * cos2x;



	return  (sinx + cos2x/2 + sin3x/3 + cos4x/4+sin5x/5);
}



void pedal(void){
	storeDampingTime = dampingTime;
	dampingTime=3*dampingTime;
}

void releasePedal(void){
	dampingTime = storeDampingTime;
}

