# Languages Performance Test

This is the most "quick and dirty" test of language performance.
Create an issue if you have an idea how to improve it.

Please add a link to this repo if you use any ugly code from it.

## Disclaimer

I know that all the languages in the test have built-in QuickSort functions.
The purpose of this test is to make the language do something CPU-intense and to have code that can be easily portable to other languages.

## Requirements
To run it, you need to have the following installed:
```
ASP.NET Core
G++
JavaSDK
Python3
make
```

## How to build and run

To run it, just execute the following:
```
make
```
It will build and run all the tests.

## My results

Results on my Apple MacBook Pro 2022 with Intel i5 processor:
```
====== C++ ======
825.869 ms
827.067 ms
845.197 ms
813.445 ms
833.388 ms
813.903 ms
801.647 ms
895.92 ms
872.807 ms
933.681 ms
Total duration: 8457 ms
Average duration: 845 ms
java -cp Java Test
====== Java ======
1054 ms
1063 ms
1029 ms
1046 ms
1088 ms
1051 ms
1086 ms
1060 ms
1063 ms
1053 ms
Total duration: 10593 ms
Average duration: 1059 ms
dotnet CS/bin/Release/net8.0/test.dll
====== C# ======
968 ms
958 ms
939 ms
942 ms
959 ms
947 ms
954 ms
946 ms
936 ms
936 ms
Total duration: 9485 ms
Average duration: 948 ms
python3 Python/test.py
====== Python ======
33445.37 ms
35057.07 ms
34532.99 ms
34851.87 ms
33070.03 ms
34293.63 ms
35342.29 ms
35603.66 ms
34288.17 ms
34897.19 ms
Total duration: 345382.25 ms
Average duration: 34538.23 ms
```
