CFLAGS=-Wall -g -c
LDFLAGS=-g
	
run: chevaux
	@./chevaux

test: chevaux
	@./chevaux

chevaux: mchevaux.o schevaux.o Librairie/libisentlib.a
	gcc $(LDFLAGS) $^ -o $@ -lm -lglut -lGL -lX11

mchevaux.o: mchevaux.c hchevaux.h Librairie/BmpLib.h Librairie/GfxLib.h 
	gcc $(CFLAGS) $<

schevaux.o: schevaux.c hchevaux.h
	gcc $(CFLAGS) schevaux.c

clean: 
	rm -f mchevaux.o schevaux.o chevaux
	
