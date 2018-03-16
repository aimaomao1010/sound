OBJ = main.o sound.o
APPNAME = sound.a
TAR = final.tar

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ)
%.O : %.C
	gcc -c -o $@ $<
clean :
	rm $(OBJ) $(APPNAME)
archive : 
	tar cf $(TAR) *

