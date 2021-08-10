//-------------------------------------------------------------
//   Jacob McClure
//
//   Subset.c
//   C program that uses recursion to print out all 𝑘-element
//   subsets of the 𝑛-element set {1, 2, 3, … , 𝑛}, where both
//   n and k  are given on the command line
//-------------------------------------------------------------   

#include<stdlib.h>
#include<stdio.h>
#define MAX_SIZE 100 // define macro for maximum value to be tested
  
void printSet(int B[], int n) { // define function to print the set from CL
	// counter
	int c = 1;
	printf("{");
	
	// for loop to traverse array and print in order
	for (int i = 1; i < n+1; i++) {
		if (B[i] == 1) {
			// prevent redundant commas at end of the set
			if(c) { 
				c = 0;
			}
			
			// if we are on the first element of the subset, print a comma
			else { 
				printf(", ");
			}
			
			// print the integer
			printf("%d", i); 
		}
	}
	
	// print the second bracket with a new line
	printf("}\n"); 
}


// Function that prints all subsets
void printSubsets(int B[], int n, int k, int i) { 
	// base case:
	if (k == 0) { 
		printSet(B, n);
		return;
	}

	// do not print the subset if it violates constraint
	if (k > (n-i+1)) { 
		return;
	}

	// populating array so it can print from CL args 
	B[i] = 1;
	printSubsets(B, n, k-1, i+1);

	// populating array so it can print from CL args
  	B[i] = 0; 
  	printSubsets(B, n, k, i+1);
  	return;
}

int main(int argc, char* argv[]) {
	// instantiate integer variables for n, k and status
   	int n, k, sts; 
   	
   	// declare a char, ch, to create exclusion condition for invalid inputs
  	char ch; 
   	
   	// if argument count is not 3, the command line input is invalid
   	if (argc!=3) { 
    	printf("Usage: Subset n k (n and k are ints satisfying 0 <= k <= n <= 100)");
    	return 0;
 	}

 	sts = sscanf(argv[1], "%d%c", &n, &ch);
 	// if input is not valid, print usage statement
 	if (sts != 1) { 
    	printf("Usage: Subset n k (n and k are ints satisfying 0 <= k <= n <= 100)");
    	return 0;
  	}
  	
  	sts = sscanf(argv[2], "%d%c", &k, &ch);
  	// if input is not valid, print usage statement
  	if (sts != 1) { 
    	printf("Usage: Subset n k (n and k are ints satisfying 0 <= k <= n <= 100)");
    	return 0;
	}
   
   	// when input indicates n < k, it is invalid: print usage statement
  	if (n < k) { 
    	printf("Usage: Subset n k (n and k are ints satisfying 0 <= k <= n <= 100)");
    	return 0;
   	}

	// initialize integer array with 101 elements
   	int B[MAX_SIZE + 1]; 

   	// traverse array
   	for (int i = 0; i > n; i++) {
    	B[i] = 0;   
    }

	// recursive call to print subsets
    printSubsets(B, n, k, 1); 
}
