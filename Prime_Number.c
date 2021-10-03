//mallon needs implementation
//multithreading needs implimentation

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void primePrint(int *prime, int legnth ){

FILE *fp;
int n;

	fp=fopen("OnlyPrimeNumbers.txt", "w");

	for (n=0;n<=legnth;n++){
	fprintf(fp,"%d\n", prime[n]);
	}
	fprintf(fp,"Amount of prime numbers = %d\n", legnth);
	fclose(fp);
}

void file (char file1[30])
{


int counter;
int i;
int c;
int j;
FILE *f;
int n = 0;
int p = 0;
int buffer;
int *number; 
int *pNumbers;
number = (int *) malloc(10000000); // malloc inital size
pNumbers = (int *) malloc(1); 

// reads file and places contents in array

 f = fopen(file1, "r");
    if(f){
        while(!feof(f)){
            fscanf(f, "%d",&buffer);
            n ++;
            //number = (int *) realloc(number, sizeof(int)*n+10);
            number [n] = buffer;
            
            printf("numbers = %d\n", number[n]);
        }
        
    }
    fclose(f);
	// malloc reallocate size of number to stop it from hogging memory
	number = (int *) realloc (number,sizeof(int)*n);  	
	// malloc reallocate to maximum possible prime number amount
	pNumbers = (int *) realloc (pNumbers,sizeof(int)*n);  


// works out prime numbers by going through array
    for(i=0; i<n; i++)
    {
        counter=0;
        for(j=2; j<number[i]; j++)
        {
            // if no remainder then not a prime number
            if(number[i] %j == 0)
            {
                counter = 1;
                break;
            }
        }
        //if prime
        if(counter == 0)
        {
	pNumbers[p] = number[i];
	p++;
        printf("%d\n",number[i]);
        }
    } 
	printf("Number of prime numbers = %d\n",p);

	primePrint(pNumbers,p);
// free their memory
free(number);
free(pNumbers);
}








int main (int argc, char **argv)
{
char str[30];   

    printf("Enter a filename to scan:");
    scanf("%[^\n]%*c", str);



// Declare threads and default attributes
	pthread_t threads[argc-1];
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	// Run all threads concurrently
	int i;
	for (i = 1; i < *argv[0]; i++){
		
		// Create a new thread for every argument passed in by the user, and count word frequency for each
		pthread_create(&threads[i], &attr, (void*) file, (void*) str);
	}
	for (i = 1; i < argc; i++){
		// Join threads to avoid memory leaks
		pthread_join(threads[i], NULL);
	}

   

}
