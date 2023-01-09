CC=clang++
CLAFGS=-Wall -Wextra -std=c++17 -g

BUILD = ./build
INCLUDE = ./include
SRC = ./src
TARGET = vpl_execution

$(TARGET): $(BUILD)/Cilindro.o $(BUILD)/Circulo.o $(BUILD)/Ponto.o $(BUILD)/main.o
		$(CC) $(CLAFGS) -o $(TARGET) $(BUILD)/*.o

$(BUILD)/Ponto.o: $(INCLUDE)/Ponto.hpp $(SRC)/entidades/Ponto.cpp
		$(CC) $(CLAFGS) -I $(INCLUDE) -c $(SRC)/entidades/Ponto.cpp -o $(BUILD)/Ponto.o

$(BUILD)/Circulo.o: $(INCLUDE)/Circulo.hpp $(SRC)/entidades/Circulo.cpp $(INCLUDE)/Ponto.hpp
		$(CC) $(CLAFGS) -I $(INCLUDE) -c $(SRC)/entidades/Circulo.cpp -o $(BUILD)/Circulo.o

$(BUILD)/Cilindro.o: $(INCLUDE)/Cilindro.hpp $(SRC)/entidades/Cilindro.cpp $(INCLUDE)/Circulo.hpp
		$(CC) $(CLAFGS) -I $(INCLUDE) -c $(SRC)/entidades/Cilindro.cpp -o $(BUILD)/Cilindro.o
	
$(BUILD)/main.o: $(INCLUDE)/Ponto.hpp $(INCLUDE)/Circulo.hpp $(INCLUDE)/Cilindro.hpp $(SRC)/main.cpp
		$(CC) $(CLAFGS) -I $(INCLUDE) -c $(SRC)/main.cpp -o $(BUILD)/main.o

clean:
	rm -f $(BUILD)/*
