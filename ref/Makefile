CC=gcc
all: nat-timeserv timeclnt

nat-timeserv: nat-timeserv.c
	$(CC) -o $@ $<

timeclnt: timeclnt.c
	$(CC) -o $@ $<

bounce2d: bounce2d.c set_ticker.c -lcurses
	cc -o bounce2d bounce2d.c set_ticker.c -lcurses

.PHONY: clean
clean:
	rm -f nat-timeserv timeclnt bounce2d
