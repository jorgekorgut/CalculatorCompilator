CC = g++
CCFLAGS = -g -Wall -std=c++14
LDFLAGS = 

OBJDIR = bin
SRCDIR = src

SRC := $(shell find $(SRCDIR) -name "*.cpp")
OBJ := $(SRC:$(SRCDIR)%.cpp=$(OBJDIR)%.o)

APP = calculer

all: $(APP)

$(APP): $(OBJ)
	@echo "== LINKING EXECUTABLE $(APP)"
	@$(CC) $^ $(LDFLAGS) -o $(OBJDIR)/$(APP)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "COMPILING SOURCE $< INTO OBJECT $@"
	@mkdir -p $(@D)
	@$(CC) -c $(CCFLAGS) $< -o $@

clean:
	rm -rf $(OBJDIR)