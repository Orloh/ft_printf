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

CLEANUP			= rm -f
MKDIR			= mkdir -p
TARGET_EXTENSION	=out

.PHONY: all clean test test_run

PATHU = unity/src/
PATHS = ../src/
PATHI = ../inc/
PATHL = ../libft/
PATHT = ./
PATHB = build/
PATHD = build/depends/
PATHO = build/objs/
PATHR = build/results/

BIN		= ../libftprintf.a

BUILD_PATHS	= $(PATHB) $(PATHD) $(PATHO) $(PATHR)

SRCT 		= $(wildcard $(PATHT)*.c)

COMPILE		=cc -c
LINK		=cc -g -O0
DEPEND		=cc -MM -MG -MF
CFLAGS		=-I. -I$(PATHU) -I$(PATHI) -I$(PATHL) -DTEST -g -O0

RESULTS 	= $(patsubst $(PATHT)test_%.c,$(PATHR)test_%.txt,$(SRCT))

RESULT_FILES = $(PATHR)*.txt

all: $(PATHU)unity.c $(BUILD_PATHS) test

test: $(RESULTS)
	@cat $(RESULT_FILES)

$(PATHR)%.txt: $(PATHB)%.$(TARGET_EXTENSION)
	@{\
		echo "===[ $$(basename $< .$(TARGET_EXTENSION)).c]===";	\
		echo;							\
		./$< 2>&1 || true;					\
		echo;							\
	} > $@.tmp && mv $@.tmp $@

$(PATHB)test_%.$(TARGET_EXTENSION): $(PATHO)test_%.o $(PATHO)unity.o $(BIN)
	$(LINK) -o $@ $^

$(PATHO)%.o:: $(PATHT)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHO)%.o:: $(PATHS)%.c
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHO)unity.o: $(PATHU)unity.c | $(PATHU)
	$(COMPILE) $(CFLAGS) $< -o $@

$(PATHU)unity.c:
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
	rm -rf unity

.PRECIOUS: $(PATHB)test_%.$(TARGET_EXTENSION)
.PRECIOUS: $(PATHD)%.d
.PRECIOUS: $(PATHO)%.o
.PRECIOUS: $(PATHR)%.txt
