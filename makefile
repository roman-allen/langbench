test: C++/test Java/Test.class Python/test.py
	./C++/test
	java -cp Java Test
	python3 Python/test.py

C++/test: C++/test.cpp
	g++ -Ofast -o C++/test C++/test.cpp

Java/Test.class: Java/Test.java
	javac Java/Test.java
