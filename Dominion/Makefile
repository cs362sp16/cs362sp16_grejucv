CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testdominion: testdominion.c dominion.o
	gcc -o testdominion testdominion.c -g dominion.o rngs.o $(CFLAGS)

unittest1: unittest1.c dominion.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS) 

unittest2: unittest2.c dominion.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS) 

unittest3: unittest3.c dominion.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS) 

unittest4: unittest4.c dominion.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS) 

cardtest1: cardtest1.c dominion.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS) 

cardtest2: cardtest2.c dominion.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS) 

cardtest4: cardtest4.c dominion.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS) 

randomtestcard1: randomtestcard1.c dominion.o
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)


unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 playdom
	./unittest1 >> unittestresults.out
	echo "GCOV AFTER UNITTEST 1" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./unittest2 >> unittestresults.out
	echo "GCOV AFTER UNITTEST 2" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./unittest3 >> unittestresults.out
	echo "GCOV AFTER UNITTEST 3" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./unittest4 >> unittestresults.out
	echo "GCOV AFTER UNITTEST 4" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./cardtest1 >> unittestresults.out
	echo "GCOV AFTER CARDTEST 1 " >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./cardtest2 >> unittestresults.out
	echo "GCOV AFTER CARDTEST 2" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./cardtest3 >> unittestresults.out
	echo "GCOV AFTER CARDTEST 3" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./cardtest4 >> unittestresults.out
	echo "GCOV AFTER CARDTEST 4" >> unittestresults.out
	gcov dominion.c >> unittestresults.out


	./playdom 3 >> unittestresults.out
	echo "GCOV AFTER PLAYING A GAME" >> unittestresults.out
	gcov dominion.c >> unittestresults.out


randomtestcard1.out: randomtestcard1 playdom
	./randomtestcard1 >> randomtestcard1.out
	echo "GCOV AFTER randomtestcard1" >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out 

randomtestcard2.out: randomtestcard2 playdom
	./randomtestcard2 >> randomtestcard2.out
	echo "GCOV AFTER randomtestcard2” >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out 

randomtestadventurer.out: randomtestadventurer playdom
	./randomtestadventurer >> randomtestadventurer.out
	echo "GCOV AFTER randomtestadventurer" >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out 

testdominion.out: testdominion playdom
	./testdominion >> testdominion.out
	gcov dominion.c >> testdominion.out 

unittest1.out: unittest1 playdom
	./unittest1 >> unittest1.out
	gcov dominion.c >> unittest1.out 

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

clean:
	rm -f *.o playdom.exe playdom test.exe test player testdominion unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM



