app1: staticlib.a libcaller.c
	gcc libcaller.c -o app1 -L. -l:staticlib.a -DLIBSTATIC

staticlib.a: mathlib.c
	gcc -c -o mathlib.o mathlib.c
	ar rcs staticlib.a mathlib.o
	ranlib staticlib.a

app2: dynamiclib.so libcaller.c
	gcc libcaller.c -o app2 -L. -l:dynamiclib.so -DLIBDYNAMIC_S
	
app3: dynamiclib.so libcaller.c
	gcc libcaller.c -o app3 -L. -l:dynamiclib.so -DLIBDYNAMIC
	
dynamiclib.so: mathlib.c
	gcc -fPIC -c mathlib.c
	gcc -shared -o dynamiclib.so mathlib.o