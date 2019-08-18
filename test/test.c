#include "soundlib.h"

#define EXTENSION 12
#define POPSIZE 16
#define MUTATION 0.01
#define CROSSOVER 0.5
#define MAXGENERATION 8
#define END (counter==MAXGENERATION)

double *best;
double **population;
double **newPopulation;
double *testing;
int counter=0;

float bestScore=0;
float *score;
float sumScore=0;

short octave = 0;


double test(double x){
	double value;
	static double phase[EXTENSION];
	double norm ;
	int i;

	if(startTone){
		for(i=0;i<EXTENSION;++i){
			phase[i]=(double)rand()/RAND_MAX;
			norm += testing[i]*testing[i];
		}
		startTone=0;
		norm = sqrt(norm);
		testing[i]/=norm;
	}

	while(x>1)x-=1;
	value = damper = 0;

	for(i=0;i<EXTENSION;++i){
		value += testing[i] * cos(DOSPI*((i+1)*x+phase[i])) ;
	}
	return value;
}


void song(void){
	tempo=100;
	//MEASURE #1
	fourChord(test,C/2,C,E,G,octave,0.25,90);
	fourChord(test,C/2,G/2,C,E,octave,0.25,90);
	cat();
	//MEASURE #2
	fourChord(test,E/2,G/2,G,2*C,octave,0.25,90);
	fourChord(test,C/2,C,E,G,octave,0.25,90);
	cat();
	fourChord(test,G/2,C,G,2*E,octave,0.375,90);
	cat();
	fourChord(test,F/2,B/2,G,2*D,octave,0.125,90);
	cat();
	cat();
	//MEASURE #3
	fourChord(test,E/2,C,G,2*C,octave,0.25,90);
	fourChord(test,E/2,C,G,G,octave,0.25,90);
	cat();
	fourChord(test,F/2,A/2,C,A,octave,0.25,90);
	cat();
	fourChord(test,F/2,C,C,A,octave,0.25,90);
	cat();
	cat();
	//MEASURE #4
	fourChord(test,E/2,G/2,C,G,octave,0.25,90);
	fourChord(test,A/4,A/2,C,2*C,octave,0.25,90);
	cat();
	fourChord(test,B/4,G/2,D,G,octave,0.25,90);
	cat();
	fourChord(test,G/4,G/2,B/2,F,octave,0.25,90);
	cat();
	cat();
	//MEASURE #5
	fourChord(test,C/2,G/2,C,E,octave,0.5,90);
	fourChord(test,C,C,E,G,octave,0.25,90);
	cat();
	fourChord(test,G/2,C,C,E,octave,0.25,90);
	cat();
	cat();
	//MEASURE #6
	fourChord(test,E/2,G/2,G,2*C,octave,0.25,90);
	interval(test,G/2,G,octave,0.25,90);
	two(test,G,F,octave,0.25,90);
	two(test,E,Db,octave-1,0.25,90);
	add();
	add();
	cat();
	cat();
	fourChord(test,C/2,C,E,2*E,octave,0.375,90);
	fourChord(test,D/2,B/2,F,2*D,octave,0.125,90);
	cat();
	cat();
	//MEASURE #7
	fourChord(test,E/2,A/2,E,2*C,octave,0.25,90);
	fourChord(test,E/2,Gs/2,E,B,octave,0.25,90);
	cat();
	fourChord(test,A/2,A/2,E,2*C,octave,0.25,90);
	cat();
	fourChord(test,E/2,Gs/2,E,B,octave,0.25,90);
	cat();
	cat();
	//MEASURE # 8
	fourChord(test,C/2,E,E,A,octave,0.25,90);
	interval(test,A/4,E,octave,0.25,90);
	two(test,B,2*C,octave,0.25,90);
	two(test,D,C,octave,0.25,90);
	add();
	add();
	cat();
	fourChord(test,D/2,D,G,B,octave,0.25,90);
	cat();
	fourChord(test,D/2,C,Fs,A,octave,0.25,90);
	cat();
	cat();
	//MEASURE # 9
	fourChord(test,G/4,B/2,G,G,octave,0.25,90);
	fourChord(test,G/2,B/2,G,2*D,octave,0.375,90);
	fourChord(test,G/2,B/2,G,2*D,octave,0.125,90);
	cat();
	cat();
	cat();
	//MEASURE #10
	fourChord(test,G/2,D,G,B,octave,0.25,90);
	fourChord(test,G/2,B/2,G,2*D,octave,0.25,90);
	fourChord(test,C/2,C,G,2*E,octave,0.375,90);
	fourChord(test,C/2,Bf,E,2*D,octave,0.125,90);
	cat();
	cat();
	cat();
	cat();
	//MEASURE #11
	fourChord(test,F/2,A/2,F,2*C,octave,0.25,90);
	fourChord(test,F/2,C,F,A,octave,0.25,90);
	fourChord(test,Db/2,Db,A,2*F,octave,0.25,90);
	fourChord(test,E/2,G/2,G,2*E,octave,0.25,90);
	cat();
	cat();
	cat();
	cat();
	//MEASURE #12
	four(test,Db,C,C,B/2,octave-1,1.0,90);
	create(test,F,octave,0.25,90);
	appendTwo(test,E,F,octave,0.25,90);
	append(test,G,octave,0.375,90);
	append(test,F,octave,0.125,90);
	add();
	two(test,A,B,octave-1,0.25,90);
	appendThree(test,C,D,D,octave,0.75,90);
	add();
	two(test,F,G,octave-1,0.25,90);
	appendThree(test,A,G,G/2,octave-1,0.75,90);
	add();
	cat();
	//MEASURE #13
	fourChord(test,C/2,C,E,2*C,octave,0.5,90);
	cat();
}


void startPopulation(void){

	int i,j;

	best = (double *)calloc(sizeof(double),EXTENSION);
	population = (double **)calloc(sizeof(double *),POPSIZE);
	newPopulation = (double **)calloc(sizeof(double *),POPSIZE);
	score = (float *)calloc(sizeof(float),POPSIZE);
	for(i=0;i<POPSIZE;++i){
		population[i]=(double *)calloc(sizeof(double),EXTENSION);
		newPopulation[i]=(double *)calloc(sizeof(double),EXTENSION);
		for(j=0;j<EXTENSION;++j){
			population[i][j] = (double)rand()/RAND_MAX;
		}
	}

}


float eval(double *spectrum){
	float grade;
	int errorFlag;
	testing = spectrum;
	song();
	echo(20,0.30,5);
	exportToWav("angels from the realms of glory.wav");
	system("totem \"angels from the realms of glory.wav\"");
	puts("Grade it");
	errorFlag=scanf("%f",&grade);
	if(errorFlag!=1){
		puts("Input error");
		exit(0);
	}
	return grade;
}


void report(void){
	FILE *output;
	int i;
	double norm=0;
	for(i=0;i<EXTENSION;++i){
		norm += best[i]*best[i];
	}
	norm=sqrt(norm);
	output = fopen("report.c","wa");
	fprintf(output,"int i;\ndouble instr(double x){\n\tdouble value=0.0;\nstatic double phase[EXTENSION];");
	fprintf(output,"\tdouble amp[%d]={",EXTENSION);
	for(i=0;i<EXTENSION;++i){
		fprintf(output,"\t\t%lf",best[i]/norm);
		if(i<EXTENSION-1){
			fprintf(output,",\n");
		}
		else{
			fprintf(output,"\n");
		}
	}
	fprintf(output,"\t}");
	fprintf(output,"for(i=0;i<%d;++i){",EXTENSION);
		fprintf(output,"value += amp[i]*cos(DOSPI*((i+1)*x+phase[i]));");
	fprintf(output,"\t}");
	fprintf(output,"}");
}

void evalPopulation(void){
	int i,j;
	float grade;
	sumScore = 0;
	for(i=0;i<POPSIZE;++i){
		printf("%d\t",i);
		sumScore += score[i] = grade = eval(population[i]);
		if(grade > bestScore){
			bestScore = grade;
			report();
			for(j=0;j<EXTENSION;++j){
				best[j]=testing[j];
			}
		}
	}
}


int selectMate(void){
	int i = 0;
	float target = sumScore * (double)rand()/RAND_MAX;
	do{
		target -= score[i];
		i += target > 0;
	}
	while(target>0);
	return i;
}




void mate(void){
	int i,j,k,n;
	double temporal;
	double **tempPop;

	
	for(i=0;i<POPSIZE;i += 2){
		j=selectMate();
		k=selectMate();
		if((double)rand()/RAND_MAX < MUTATION){
			population[j][i] =  (double)rand()/RAND_MAX;
		}
		if((double)rand()/RAND_MAX < MUTATION){
			population[k][i] =  (double)rand()/RAND_MAX;
		}
		for(n=0;n<EXTENSION;++n){
			if( (double)rand()/RAND_MAX < CROSSOVER ){
			newPopulation[i][n] = population[k][n];
			newPopulation[i+1][n] = population[j][n];
			}
			else{
			newPopulation[i][n] = population[j][n];
			newPopulation[i+1][n] = population[k][n];
			}
		}
	}

	tempPop = population;
	population = newPopulation;
	newPopulation = tempPop;
}





void evolve(void){
	startPopulation();
	do{
		evalPopulation();
		mate();
		++counter;
	}
	while(!END);
	report();
}



int main(int argc, char **argv){
	evolve();
}
