#include <stdio.h>
#include <argp.h>
#include <string.h>

void genInput(char* arg);
void parseOutput(char* arg);

struct argp_option options[] =
 {
 { "input", 'i', "input_val", 0, "Generate a transducer with input_val."},
 { "output", 'o', "outp_file", 0, "Generate the output from the .fst file."},
 { 0 }
 };

static int parse_opt (int key, char *arg, struct argp_state *state) {
	
	switch (key){
 		case 'i': genInput(arg); break;
		case 'o': parseOutput(arg); break;
 	}
 	
	return 0;
} 

struct argp argp = { options, parse_opt }; 

void parseOutput(char* arg) {
	FILE* file;
    char line[256];
    const char *delimiters = " \t\n";
	char outp[256];

	file = fopen(arg, "r");
	if(file == NULL){ printf("Transducer not found.\n"); return; }

	int index = 0;
    while (fgets(line, sizeof(line), file)) {
		
		int x = 0;
		strtok(line, delimiters);
		while(x < 2) { strtok(NULL, delimiters); x++; }

		char* parsed = strtok(NULL, delimiters);
		if(parsed == NULL) break;

		int in = 0;
		while(parsed[in] != '\0')
        	outp[index++] = parsed[in++];
		outp[index] = '\0';
    }

    fclose(file);
    
    printf("%s\n", outp);
}

void genInput(char* arg) {
	int i = 0;
	for(i; arg[i] != '\0'; i++)
		printf("%i	%i	%c	%c\n",i,i+1,arg[i],arg[i]);
	
	printf("%i\n",i);
}

int main(int argc, char** argv){
	
	argp_parse (&argp, argc, argv, 0, 0, 0); 

	return 0;
}
