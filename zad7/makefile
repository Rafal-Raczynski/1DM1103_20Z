DEPS=main.o baza.o 


mydb: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic 

%.o:%.c
	cc -c $^ -o $@



clean:
	rm -f main
	rm -f *.o

test: 
	valgrind ./mydb baza.csv list_students

test-ile: 
	./mydb baza.csv count_students

test-memory: 
	 valgrind ./mydb baza.csv count_students 

test-dodajs: 
	 ./mydb baza.csv add_student Marcin Tak 1DDEFG supermarcin@tak.pl

test-dodajp: 
	 ./mydb baza.csv add_subject 1DDDD WF 2020Z

test-dodajo: 
	 ./mydb baza.csv add_ocenka 1DDDDD 8888 5 'dobra robota'

