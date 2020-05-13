CC = gcc

SRC_DIR := src
OBJ_DIR := obj

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS 	:= -g -Wall -D_GNU_SOURCE
LDFLAGS	:= -Llib -pthread
EXE = MyDiskBench

.PHONY: all clean help test

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR):
	mkdir $@

help:
	./$(EXE)
# Run experiments
define iterateOver
	for d in 1 2 3 4 5 6 7 ; do \
		for r in 64 1 16 ; do \
			sudo sh -c "echo 3 > /proc/sys/vm/drop_caches"; \
			./$(EXE) -d $$d -p $(1) -r $$r >>./results/$(2)/$$d-$$r.txt;\
		done \
	done 	
endef

define iterateOver4kb
	for d in 1 2 3 4 5 6 7 ; do \
		sudo sh -c "echo 3 > /proc/sys/vm/drop_caches"; \
		./$(EXE) -d $$d -p $(1) -r 4 >>./results/$(2)/$$d-$$r.txt;\
	done 	
endef

run_seq_write:
	$(call iterateOver,0,seq_write)
run_seq_read:
	$(call iterateOver,1,seq_read)
run_rnd_write:
	$(call iterateOver,2,rnd_write)
run_rnd_read:
	$(call iterateOver,3,rnd_read)
run_rnd_write_iops:
	$(call iterateOver4kb,2,iops_rnd_write)
run_rnd_read_iops:
	$(call iterateOver4kb,3,iops_rnd_read)

# Clear results
define clear_result
	rm -rf ./results/$(1)/*.txt
endef

clear_seq_write:
	$(call clear_result,seq_write)
clear_seq_read:
	$(call clear_result,seq_read)
clear_rnd_write:
	$(call clear_result,rnd_write)
clear_rnd_read:
	$(call clear_result,rnd_read)
clear_rnd_write_iops:
	$(call clear_result,iops_rnd_write)
clear_rnd_read_iops:
	$(call clear_result,iops_rnd_read)

clean:
	$(RM) $(OBJ)


