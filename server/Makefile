CFLAGS   += -Wall -D_GNU_SOURCE -I../abcd -std=c99 -O2
LIBS := $(shell pkg-config --libs libgit2)

sync: build/sync.o build/sync-main.o
	$(CC) -g $(LDFLAGS) -o $@ $^ $(LIBS)

build/sync.o: ../abcd/util/sync.c ../abcd/util/sync.h
	@mkdir -p build
	$(CC) -c -g $(CFLAGS) -o $@ $<

build/sync-main.o: sync-main.c ../abcd/util/sync.h
	@mkdir -p build
	$(CC) -c -g $(CFLAGS) -o $@ $<

clean:
	$(RM) -r sync
	$(RM) -r build
