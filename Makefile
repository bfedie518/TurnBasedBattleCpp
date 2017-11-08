EXEC = TurnBasedBattle

SRCDIR = src
OBJDIR = build
BINDIR = bin
INCDIR = include

CC = g++
CFLAGS = -std=c++11 -c -Wall -I$(INCDIR)
LFLAGS = -Wall -I. -lm

SRCS = $(wildcard $(SRCDIR)/*.cpp)
INCS = $(wildcard $(INCDIR)/*.h)
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm = rm -f

$(BINDIR)/$(EXEC): $(OBJS)
	@$(CC) $(OBJS) $(LFLAGS) -o $@
	@echo "Linking complete."

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) $< -o $@
	@echo "Compiled successfully."

.PHONY: clean

clean:
	@$(rm) $(OBJS) $(BINDIR)/$(EXEC)
	@echo "Cleanup complete."
