CC = clang
CFLAGS = -Wall -g
INC = ./inc
SRC = ./src
TST = ./tests
OBJS = ./objs
LIB = ./lib
BIN = ./bin

LIBROOTS = $(OBJS)/bisection.o $(OBJS)/newton_rhapson.o $(OBJS)/regula_falsi.o $(OBJS)/secant.o $(OBJS)/newton_forward.o

PROGRAMS = $(BIN)/bisection $(BIN)/newton_rhapson $(BIN)/regula_falsi $(BIN)/secant

all: $(LIBROOTS) $(PROGRAMS) $(LIB)/libinterpol.so

$(OBJS)/bisection.o: $(SRC)/root/bisection.c $(INC)/root/bisection.h
	$(CC) $(CFLAGS) -c $(SRC)/root/bisection.c -I $(INC)/root -o $@

$(OBJS)/newton_rhapson.o: $(SRC)/root/newton_rhapson.c $(INC)/root/newton_rhapson.h
	$(CC) $(CFLAGS) -c $(SRC)/root/newton_rhapson.c -I $(INC)/root -o $@

$(OBJS)/regula_falsi.o: $(SRC)/root/regula_falsi.c $(INC)/root/regula_falsi.h
	$(CC) $(CFLAGS) -c $(SRC)/root/regula_falsi.c -I $(INC)/root -o $@

$(OBJS)/secant.o: $(SRC)/root/secant.c $(INC)/root/secant.h
	$(CC) $(CFLAGS) -c $(SRC)/root/secant.c -I $(INC)/root -o $@

$(OBJS)/newton_forward.o: $(SRC)/interpolation/newton_forward.c $(INC)/interpolation/newton_forward.h
	$(CC) $(CFLAGS) -c $(SRC)/interpolation/newton_forward.c -I $(INC)/interpolation -o $@
	

$(LIB)/libroots.so: $(OBJS)/bisection.o $(OBJS)/newton_rhapson.o $(OBJS)/regula_falsi.o $(OBJS)/secant.o
	$(CC) -fpic -o $@ $^ -shared

$(LIB)/libinterpol.so: $(OBJS)/newton_forward.o
	$(CC) -fpic -o $@ $^ -shared


$(BIN)/bisection: $(TST)/bisection_demo.c $(LIB)/libroots.so
	$(CC) $(CFLAGS) $(TST)/bisection_demo.c -lroots -o $@ -I $(INC)/root -L $(LIB)

$(BIN)/newton_rhapson: $(TST)/newton_demo.c $(LIB)/libroots.so
	$(CC) $(CFLAGS) $(TST)/newton_demo.c -lroots -o $@ -I $(INC)/root -L $(LIB)

$(BIN)/regula_falsi: $(TST)/regula_demo.c $(LIB)/libroots.so
	$(CC) $(CFLAGS) $(TST)/regula_demo.c -lroots -o $@ -I $(INC)/root -L $(LIB)

$(BIN)/secant: $(TST)/secant_demo.c $(LIB)/libroots.so
	$(CC) $(CFLAGS) $(TST)/secant_demo.c -lroots -o $@ -I $(INC)/root -L $(LIB)


.PHONY: clean

clean:
	rm $(LIB)/* $(OBJS)/* $(BIN)/* -d lib objs bin