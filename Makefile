SRCS = Calculator.C LLQueue.C LLStacks.C
EXEC = calc

OBJS = $(SRCS:.C=.o)


$(EXEC): $(OBJS)
	g++ -o $(EXEC) $(OBJS)


%.o : %.C
	g++ -std=c++11 -g -Wall -c $<

clean:
	rm -f *.o *~ $(EXEC)



# DO NOT DELETE THIS LINE -- make depend needs it
