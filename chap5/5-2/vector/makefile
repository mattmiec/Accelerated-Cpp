# makefile for grader

grader: grader.o grade.o Student_info.o median.o fail.o
	g++ -o grader grader.o grade.o Student_info.o median.o fail.o

grader.o: grader.cpp grade.h Student_info.h median.h fail.h
	g++ -c grader.cpp

grade.o: grade.cpp grade.h Student_info.h median.h
	g++ -c grade.cpp

Student_info.o: Student_info.cpp Student_info.h
	g++ -c Student_info.cpp

median.o: median.cpp median.h
	g++ -c median.cpp

fail.o: fail.cpp fail.h Student_info.h grade.h
	g++ -c fail.cpp
