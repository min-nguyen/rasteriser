FILE=raytracer

########
#   Directories
S_DIR=Source
B_DIR=Build
GLMDIR=../glm/
########
#   Output
EXEC=$(B_DIR)/$(FILE)

# default build settings
CC_OPTS=-c -fopenmp -std=c++0x -pipe -Wno-switch -ggdb -g3 
LN_OPTS=
CC=g++

########
#       SDL options
SDL_CFLAGS := $(shell sdl2-config --cflags)
GLM_CFLAGS := -I$(GLMDIR)
SDL_LDFLAGS := $(shell sdl2-config --libs)

########
#   This is the default action
all:Build


########
#   Object list
#
OBJ = $(B_DIR)/$(FILE).o


########
#   Objects
$(B_DIR)/$(FILE).o : $(S_DIR)/$(FILE).cpp $(S_DIR)/Scene/SDLauxiliary.h $(S_DIR)/Scene/TestModelH.h
	$(CC) $(CC_OPTS) -o $(B_DIR)/$(FILE).o $(S_DIR)/$(FILE).cpp $(SDL_CFLAGS) $(GLM_CFLAGS)


########
#   Main build rule
Build : $(OBJ) Makefile
	$(CC) -fopenmp $(LN_OPTS) -o $(EXEC) $(OBJ) `sdl2-config --cflags --libs`


clean:
	rm -f $(B_DIR)/*
