/* 
  Assignment 4 (Option 1) - by Bruce Geng

  Open and read a file of integers into an array that is created with the first integer telling you how many to read.
  4  9  11  12  15 mean create an int array size 4 and read in the remaining 4 values into data[].
  Compute their average as a double and their max as an int.  
  Print all this out neatly to the screen and to an output file named answer-hw3.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// read data from the file and return an array
void read_file(FILE *ifp, int d[], int size)
{
    int i; 
    for(i = 0; i < size; i++) {fscanf(ifp, "%d", &d[i]);}
}

// return the average of argument array
double average(int d[], int size){
	double avg;
	int i;
	for(i = 0; i < size; i++){avg += d[i];}
	return (avg/size);
}

// bubble sort to obtian the maximum element
int max_value(int d[], int size){
    if(size < 1){
    	printf("Empty data! Please input the right data");
      exit(1);
    }

    int i, max = d[0];
    for(i = 1; i < size; i++){
        if(d[i] >  max)
            max = d[i];
    }
    return max;
}

// store the answer in the file
void store_answer(int d[], int size, double avg, int max, FILE *ofp){

    char original[] = "The original data is:\n";
    char maximum[] = "The max value is:\t";
    char average[] = "The average is:\t";
    char element[10];
    int i, j;
    
    // write original information to the file
    for(i = 0; i < strlen(original); i++){
        putc(original[i], ofp);
    }

    // write original data to the file
    for(i = 0; i < size; i++){

        // convert elements to string
        sprintf(element, "%d", d[i]);

        //write elements to the file
        for(j = 0; j < strlen(element); j++){
            putc(element[j], ofp);
        }
        putc('\t', ofp);

        // break line every 10 elements
        if((i+1)%10 == 0)
            putc('\n', ofp);

    }
    putc('\n', ofp);
    putc('\n', ofp);

    // write maximum to the file
    for(i = 0; i < strlen(maximum); i++){
        putc(maximum[i], ofp);
    }

    // write maximum value to the file
    sprintf(element, "%d", max); // Converting max value to string
    for (i = 0; i < strlen(element); i++){
        putc(element[i], ofp);
    }
    putc('\n', ofp);
    putc('\n', ofp);

    // write average line to the file
    for(i = 0; i < strlen(average); i++){
        putc(average[i], ofp);
    }

    // write average value to the file
    sprintf(element, "%lf", avg); 
    for(i = 0; i < strlen(element); i++){
        putc(element[i], ofp);
    }
    putc('\n', ofp);
    putc('\n', ofp);
}

// print data
void print_data(int d[], int size){
	int i;
  printf("The original data is:\n");
  for (i = 0; i < size; i++){
  	printf("%d\t", d[i]);
  }
}


// print the content of the file
void print_file(FILE *fpr){
	rewind(fpr); // rewind before the pointer
	char c;
	while((c = getc(fpr)) != EOF){
		putc(c, stdout);
	}
}


/* Main Function */ 

int main(int argc, char *argv[])
{
  FILE *ifp, *ofp; // input and output files
  int n, max;
  double avg;

  // check number of arguments
  if(argc != 2){
  	printf("Please specify only input file\n");
    exit(1);
  }
    
  // open the files
  ifp = fopen(argv[1], "r");
  ofp = fopen("answer-hw3", "w+");
    
  // if the file is valid, declare an array data of size n
  if(fscanf(ifp, "%d", &n) != 1){
      printf("Empty file!\n");
      exit(1);
   }
  int data[n];

  // rewind before that point
  read_file(ifp, data, n);
  
  // print original data
  print_data(data, n);

  // obtain the max and average
  avg = average(data, n);
  printf("\n\nThe average is: %f", avg);
  printf("\n\n");

  max = max_value(data, n);
  printf("\nThe max value is: %d", max);
  printf("\n\n");

  store_answer(data, n, avg, max, ofp);

  printf("All information is contained in the following output file.\n");
  print_file(ofp);

  fclose(ifp);
  fclose(ofp);
  printf("\n\n");
  return 0;
}