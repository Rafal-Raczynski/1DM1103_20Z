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

test-dodajsp:
	valgrind -s ./mydb baza.csv add_studp 1DDDDD 8888 

test-sortuj-malejaco:
	./mydb baza.csv sort_descending

test-sortuj-rosnaco:
	./mydb baza.csv sort_ascending

test-sortuj-malejaco-przed-nazw:
	./mydb baza.csv sort_descending_przed_nazw

test-sortuj-rosnaco-przed-nazw:
	./mydb baza.csv sort_ascending_przed_nazw

test-sortuj-malejaco-przed-kod:
	./mydb baza.csv sort_descending_przed_kod

test-sortuj-rosnaco-przed-kod:
	./mydb baza.csv sort_ascending_przed_kod

test-filtr-przed:
	./mydb baza.csv filtr_przed 1DE2103

test-filtr-stud:
	./mydb baza.csv filtr_stud 0000007




