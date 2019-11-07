
GCC = g++

test: test.o Point2D.o Vector2D.o GameObject.o Building.o PokemonCenter.o PokemonGym.o
	$(GCC) test.o Point2D.o Vector2D.o GameObject.o Building.o PokemonCenter.o PokemonGym.o -o test

test.o: test.cpp
	$(GCC) -c test.cpp

Point2D.o: Point2D.cpp
	$(GCC) -c Point2D.cpp

Vector2D.o: Vector2D.cpp
	$(GCC) -c Vector2D.cpp

GameObject.o: GameObject.cpp
	$(GCC) -c GameObject.cpp

Building.o: Building.cpp
	$(GCC) -c Building.cpp

PokemonCenter.o: PokemonCenter.cpp
	$(GCC) -c PokemonCenter.cpp

PokemonGym.o: PokemonGym.cpp
	$(GCC) -c PokemonGym.cpp
clean:
	rm test.o Point2D.o Vector2D.o GameObject.o Building.o PokemonCenter.o PokemonGym.o test