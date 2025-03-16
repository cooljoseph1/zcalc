CC = gcc
CFLAGS = -Wall -Wextra -Os
LIBS = -lm
INSTALL_DIR = /usr/local/bin

default: zcalc

zcalc: zcalc.c percentile_to_z.c z_to_percentile.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

zpercent: zpercent.c z_to_percentile.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

zscore: zscore.c percentile_to_z.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

all: zcalc zpercent zscore

install/zcalc: zcalc
	install zcalc $(INSTALL_DIR)

install/zpercent: zpercent
	install zpercent $(INSTALL_DIR)

install/zscore: zscore
	install zscore $(INSTALL_DIR)

install: install/zcalc

install/all: install/zcalc install/zpercent install/zscore

clean:
	rm -f *.o zcalc zpercent zscore

.PHONY: default all install/zcalc install/zpercent install/zscore install install/all clean
