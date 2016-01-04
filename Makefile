compile: main.c arr_util.c 
	gcc -c main.c arr_util.c 
run: main.c arr_util.c
	gcc main.c arr_util.c -o main
show: main
	./main
clean:
	rm main
