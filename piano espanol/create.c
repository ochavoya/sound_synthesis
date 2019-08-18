#include <stdlib.h>
#include <stdio.h>

#define FRAMENUMBER  4

void createFrame(char *instr,char *az){
	printf("\t\t(%s,,octave,,%s);\n",instr,az);
}



void main(int argc,char **argv){
	int start,end,i,j;
	int voice;
	if(argc==1){
		puts("./create <voice flag> <start> <end> <function header>");
		exit(0);
	}
	voice=atoi(argv[1]);
	start = atoi(argv[2]);
	end = atoi(argv[3]);
	puts("/*");
	printf("%s{\n",argv[4]);
	for(i=start;i<=end;++i){
		printf("\t//MEASURE # %d\r\n",i);
		printf("\t#ifdef DEBUG\r\n");
		printf("\tputs(\"Measure # %d\");\r\n",i);
		printf("\t#endif\r\n");
		if(voice){
			printf("\t\t//VOICE\n");
			for(j=0;j<FRAMENUMBER;++j){
				createFrame("voice","VOICEAZ");
			}
		}
		printf("\t\t//HARMONY\n");
		for(j=0;j<FRAMENUMBER;++j){
			createFrame("harmony","CHORDAZ");
		}
		if(voice){
			printf("\tadd();\n");
		}
		printf("\t\t//BASS\n");
		for(j=0;j<FRAMENUMBER;++j){
			createFrame("bass","BASSAZ");
		}
		printf("\tadd();\n");
		if(i>start){
			printf("\tcat();\n");
		}
	}
	printf("}\n");
	puts("*/");
}
