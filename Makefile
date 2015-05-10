CPP = g++

INSTDIR = ./bin

OBJS = test.o DemoShm.o

TARGET = test

$(TARGET) : $(OBJS)
	$(CPP) -o $(TARGET) $(OBJS)

test.o : test.cpp DemoShm.h shm_com.h
	$(CPP) -c test.cpp
	
DemoShm.o : DemoShm.cpp DemoShm.h shm_com.h
	$(CPP) -c DemoShm.cpp
		
clean :
	rm $(TARGET) $(OBJS)


install : test
	@if	[ -d $(INSTDIR) ]; \
	   then \
	   cp test $(INSTDIR); \
	   chmod a+x $(INSTDIR)/test; \
	   echo "Installed in $(INSTDIR)"; \
	else \
	   echo "Sorry, $(INSTDIR) does not exist"; \
	fi
	
