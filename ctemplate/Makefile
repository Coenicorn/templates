# makefile template expects filesystem like so:
# 
# parent dir
# 	- src
# 		- main.c
# 	- lib
# 		- libmylibrary.a
# 	- include
# 		- mylibrary.h
# 	- obj
# 	- build

CC := gcc

EXECDIR := ./build
EXEC := $(EXECDIR)/main.exe

SRCDIR := ./src
OBJDIR := ./obj
INCLUDEDIR := ./include
LIBDIR := ./lib

PLATFORM :=

ifeq ($(OS), Windows_NT)
	PLATFORM = WINDOWS
else
	PLATFORM = LINUX
endif

CFLAGS := -Wall -Wextra -Wpedantic -g -I$(SRCDIR)/ -I$(INCLUDEDIR)/
LFLAGS := -L$(SRCDIR)/ -L$(LIBDIR)/
LDFLAGS := 

ifeq ($(OS))

OBJS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(OBJS:.c=.o)
OBJS := $(subst $(SRCDIR)/,$(OBJDIR)/,$(OBJS))

RM := rmdir

$(EXEC): $(OBJS)
	$(CC) $^ $(CFLAGS) $(LFLAGS) -o $(EXEC) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< $(CFLAGS) -o $@

run: $(EXEC)
	@clear
	$(EXEC)

clean:
ifeq ($(PLATFORM), WINDOWS)
	del *.o *.exe /s
endif

ifeq ($(PLATFORM), LINUX)
	rm -rf ./*.o ./*.exe
endif