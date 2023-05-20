build:
	gcc main.c functii.c functii_task1.c functii_task2.c functii_task3.c functii_task4.c functii_task5.c task1.c task2.c task3.c task4.c task5.c -o lanParty -lm
run:
	./lanParty c.in d.in r.out
clean:
	rm -f lanParty
