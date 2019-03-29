main: main.cpp split_url_file.o count_subfile_top100.o ALL_TOP100.o
	g++ -std=c++11 -o main split_url_file.o count_subfile_top100.o ALL_TOP100.o main.cpp

split_url_file.o: split_url_file.cpp split_url_file.h
	g++ -std=c++11 -c -g split_url_file.cpp

count_subfile_top100.o: count_subfile_top100.cpp count_subfile_top100.h
	g++ -std=c++11 -c -g count_subfile_top100.cpp

ALL_TOP100.o: ALL_TOP100.cpp ALL_TOP100.h
	g++ -std=c++11 -c -g ALL_TOP100.cpp

clean:
	rm -f main *.o
