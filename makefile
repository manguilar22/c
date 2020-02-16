clean: 
	rm -f *.out *.o main 
	rm -f assignment/tokenizer/main assignment/tokenizer/*.o assignment/tokenizer/*.out 
build: 
	cc main.c -o main
run:   
	./main  

