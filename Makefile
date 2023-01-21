#OBJS specifies what files to compile 
OBJS = main.cpp

#OBJS_NAME specifies the name of the executable
OBJ_NAME = main

#The target that compiles our executable
all: $(OBJS)
		g++ $(OBJS) -w -lSDL2 -o $(OBJ_NAME)
