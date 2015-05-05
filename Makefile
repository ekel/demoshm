CPP = g++

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
