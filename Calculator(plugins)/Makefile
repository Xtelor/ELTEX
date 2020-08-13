SOURCE := subtraction.c sum.c division.c multiplication.c
r: libs move result 

libs: $(SOURCE)
		gcc -fPIC $(SOURCE) -c
		gcc -shared -o libsubtraction.so subtraction.o		
		gcc -shared -o libsum.so sum.o		
		gcc -shared -o libmultiplication.so multiplication.o		
		gcc -shared -o libdivision.so division.o
move: 
	      	mv *.so plugins	

result: main.c  menu.c
		gcc main.c menu.c -L. -ldl -Wl,-rpath,./plugins/ -o res
	        ./res	
cl:
		rm -rf *.o res plugins/* 
		clear
