LIB=./lib
INCLUDE=./include
SRC=./src
OBJ=./obj
BIN=./bin


#FLAGS= -g  -O0 -Wall -D _DEBUG -Wno-unused-result -fPIC -std=gnu99 -pedantic
FLAGS=  -O3 -Wall -Wno-unused-result -fPIC  -pedantic -Wno-write-strings -fopenmp
#-std=gnu99

libFL: $(LIB)/libFL.a
	echo "libFL.a built..."

$(LIB)/libFL.a: \
$(OBJ)/common.o \
$(OBJ)/adjacencyRelation.o \
$(OBJ)/kernel.o \
$(OBJ)/image.o \
$(OBJ)/histogram.o \
$(OBJ)/morphology.o \
$(OBJ)/filtering.o \

	ar csr $(LIB)/libFL.a \
$(OBJ)/common.o \
$(OBJ)/adjacencyRelation.o \
$(OBJ)/kernel.o \
$(OBJ)/image.o \
$(OBJ)/histogram.o \
$(OBJ)/morphology.o \
$(OBJ)/filtering.o \

$(OBJ)/common.o: $(SRC)/common.cpp
	$(CC) $(FLAGS) -c $(SRC)/common.cpp -I$(INCLUDE) \
	-o $(OBJ)/common.o

$(OBJ)/adjacencyRelation.o: $(SRC)/adjacencyRelation.cpp
	$(CC) $(FLAGS) -c $(SRC)/adjacencyRelation.cpp -I$(INCLUDE) \
	-o $(OBJ)/adjacencyRelation.o

$(OBJ)/kernel.o: $(SRC)/kernel.cpp
	$(CC) $(FLAGS) -c $(SRC)/kernel.cpp -I$(INCLUDE) \
	-o $(OBJ)/kernel.o

$(OBJ)/image.o: $(SRC)/image.cpp
	$(CC) $(FLAGS) -c $(SRC)/image.cpp -I$(INCLUDE) \
	-o $(OBJ)/image.o

$(OBJ)/histogram.o: $(SRC)/histogram.cpp
	$(CC) $(FLAGS) -c $(SRC)/histogram.cpp -I$(INCLUDE) \
	-o $(OBJ)/histogram.o


$(OBJ)/morphology.o: $(SRC)/morphology.cpp
	$(CC) $(FLAGS) -c $(SRC)/morphology.cpp -I$(INCLUDE) \
	-o $(OBJ)/morphology.o

$(OBJ)/filtering.o: $(SRC)/filtering.cpp
	$(CC) $(FLAGS) -c $(SRC)/filtering.cpp -I$(INCLUDE) \
	-o $(OBJ)/filtering.o

clean: 
	rm $(LIB)/lib*.a; rm $(OBJ)/*.o;





