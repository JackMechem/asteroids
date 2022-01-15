# Compiler
CC = g++
OPTS = -c

# Project name
PROJECT = asteroids

# Directories
OBJDIR = obj
SRCDIR = src
BINDIR = bin

# Libraries
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Files and folders
SRCS    = $(shell find $(SRCDIR) -name '*.cpp')
SRCDIRS = $(shell find . -name '*.cpp' | dirname {} | sort | uniq | sed 's/\/$(SRCDIR)//g' )
OBJS    = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

# Targets
$(PROJECT): buildrepo $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(BINDIR)/$@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(OPTS) -c $< -o $@
	
clean:
	rm $(PROJECT) $(OBJDIR) -Rf
	
buildrepo:
	@$(call make-repo)

# Create obj directory structure
define make-repo
	mkdir -p $(OBJDIR)
	for dir in $(SRCDIRS); \
	do \
		mkdir -p $(OBJDIR)/$$dir; \
	done
endef