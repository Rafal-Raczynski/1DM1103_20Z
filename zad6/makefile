DEPS=main.o dzialania.o wczyt.o


main: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic -lm

%.o:%.c
	cc -c $^ -o $@



clean:
	rm -f main
	rm -f *.o