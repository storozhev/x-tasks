SRCS=$(shell ls *.c | sed -e 's/\.[^.]*$$//')
BIN_FOLDER=./bin

all:
	@mkdir -p $(BIN_FOLDER)
	@$(foreach fname,$(SRCS),gcc -Wall $(fname).c -o $(BIN_FOLDER)/output_$(fname);)	

test:
	@$(foreach fname,$(shell ls $(BIN_FOLDER)/output_*),./$(fname);)	

clean:
	@rm -rf ./bin
