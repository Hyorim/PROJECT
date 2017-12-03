
.PHONY: all clean 
 
 
all: 
	$(MAKE) -C lib;
	$(MAKE) -C bingo;
 
clean:  
	$(MAKE) -C lib clean;
	$(MAKE) -C bingo clean;
