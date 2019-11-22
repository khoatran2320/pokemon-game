
GCC = g++

PA4: main.o Point2D.o Vector2D.o GameObject.o Building.o PokemonCenter.o PokemonGym.o GameCommand.o Model.o Pokemon.o View.o
	$(GCC) main.o Point2D.o Vector2D.o GameObject.o Building.o PokemonCenter.o PokemonGym.o GameCommand.o Model.o Pokemon.o View.o -o PA4

main.o: main.cpp
	$(GCC) -c main.cpp

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
	
GameCommand.o: GameCommand.cpp
	$(GCC) -c GameCommand.cpp

Model.o: Model.cpp
	$(GCC) -c Model.cpp

Pokemon.o: Pokemon.cpp
	$(GCC) -c Pokemon.cpp

View.o: View.cpp
	$(GCC) -c View.cpp

clean:
	rm main.o Point2D.o Vector2D.o GameObject.o Building.o PokemonCenter.o PokemonGym.o GameCommand.o Model.o Pokemon.o View.o PA4