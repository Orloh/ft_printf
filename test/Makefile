#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orhernan <ohercelli@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 11:46:23 by orhernan          #+#    #+#              #
#    Updated: 2025/11/12 11:47:43 by orhernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=out
endif

.PHONY: clean test

PATHU = unity/src/
PATHS = ../src/
PATHI = ../inc/
PATHL = ../libft/
PATHT = ./
PATHB = build/
PATHD = build/depends/
PATHO = build/objs/
PATHR = build/results/

BIN = ../bin/libftprintf.a

BUILD_PATHS = $(PATHB) $(PATHD) $(PATHO) $(PATHR)

SRCT = $(wildcard $(PATHT)*.c)

COMPILE=gcc -c
LINK=gcc
DEPEND=gcc -MM -MG -MF
CFLAGS=-I. -I$(PATHU) -I$(PATHI) -I$(PATHL) -DTEST

RESULTS = $(patsubst $(PATHT)test_%.c,$(PATHR)test_%.txt,$(SRCT))

RESULT_FILES = $(PATHR)*.txt

all: $(PATHU) $(BUILD_PATHS) $(RESULTS)
	@echo "-----------------------------------------------------------"
	@cat $(RESULT_FILES)
	@echo "-----------------------------------------------------------"
	@grep -c "PASS"		$(RESULT_FILES) | awk '{sum += $$1} END {print "  PASSED:  " sum}'
	@grep -c "FAIL"		$(RESULT_FILES) | awk '{sum += $$1} END {print "  FAILED:  " sum}'
	@grep -c "IGNORE"	$(RESULT_FILES) | awk '{sum += $$1} END {print "  IGNORED:  " sum}'
	@echo "$(FAIL)"

	@echo "-----------------------------------------------------------"

$(PATHR)%.txt: $(PATHB)%.$(TARGET_EXTENSION)
	-./$< > $@ 2>&1

$(PATHB)test_%.$(TARGET_EXTENSION): $(PATHO)test_%.o $(PATHO)unity.o $(BIN)
	$(LINK) -o $@ $^

$(PATHO)%.o:: $(PATHT)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHO)%.o:: $(PATHS)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHO)%.o:: $(PATHU)%.c | $(PATHU)
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHU):
	@echo "Unity framework not found. Downloading it.."
	@git clone https://github.com/ThrowTheSwitch/Unity.git unity
	@echo "Unity downloaded succescfully!"

$(PATHD)%.d:: $(PATHT)%.c
	$(DEPEND) $@ $<

$(PATHB):
	$(MKDIR) $(PATHB)

$(PATHD):
	$(MKDIR) $(PATHD)

$(PATHO):
	$(MKDIR) $(PATHO)

$(PATHR):
	$(MKDIR) $(PATHR)

clean:
	$(CLEANUP) $(PATHO)*.o
	$(CLEANUP) $(PATHB)*.$(TARGET_EXTENSION)
	$(CLEANUP) $(PATHR)*.txt

.PRECIOUS: $(PATHB)test_%.$(TARGET_EXTENSION)
.PRECIOUS: $(PATHD)%.d
.PRECIOUS: $(PATHO)%.o
.PRECIOUS: $(PATHR)%.txt
