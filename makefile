all: schedulability.c 
	gcc -Wall -g schedulability.c -lm -o schedulability 

clean: 
	$(RM) schedulability
