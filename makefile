test: C++/test Java/Test.class CS/bin/Release/net8.0/test.dll Python/test.py
	./C++/test
	java -cp Java Test
	dotnet CS/bin/Release/net8.0/test.dll
	python3 Python/test.py

C++/test: C++/test.cpp
	g++ -Ofast -o C++/test C++/test.cpp

Java/Test.class: Java/Test.java
	javac Java/Test.java

CS/bin/Release/net8.0/test.dll: CS/test.cs
	cd CS && dotnet publish

clean:
	rm -f C++/test
	rm -rf CS/bin
	rm -rf CS/obj
	rm -f Java/Test.class