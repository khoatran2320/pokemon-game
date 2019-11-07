
GCC = g++

Checkpoint1: test.o Point2D.o Vector2D.o
	$(GCC) test.o Point2D.o Vector2D.o -o Checkpoint1

test.o: test.cpp
	$(GCC) -c test.cpp

Point2D.o: Point2D.cpp
	$(GCC) -c Point2D.cpp

Vector2D.o: Vector2D.cpp
	$(GCC) -c Vector2D.cpp

clean:
	rm TestCheckpoint1.o Point2D.o Vector2D.o Checkpoint1