#################################################
#                                               #
#  C++ Makefile                                 #
#  Made by Phantomas <phantomas@phantomas.xyz>  #
#                                               #
#################################################

CXX = g++
ECHO = echo -e 
MKDIR = mkdir -p 
RM = rm -rf
SHELL = /bin/sh

CPPFLAGS += -I srcs

TEST_CPPFLAGS += -I tests/srcs

CXXFLAGS += -std=c++17 
CXXFLAGS += $(DEBUG)

TEST_CXXFLAGS += -fprofile-arcs -ftest-coverage --coverage -fno-builtin -O0

DEPFLAGS += -MT $@ -MMD -MP -MF $(DEPSDIR)/$*.Td
TEST_DEPFLAGS += -MT $@ -MMD -MP -MF $(TEST_DEPSDIR)/$*.Td

LDFLAGS += -Wl,-E 

TEST_LDFLAGS += -lcriterion --coverage

SRCSDIR = srcs
OBJSDIR = objs
TESTDIR = tests
LOGSDIR = logs
DEPSDIR = .deps
OUTDIR = bin

TEST_SRCSDIR = $(TESTDIR)/$(SRCSDIR)
TEST_OBJSDIR = $(TESTDIR)/$(OBJSDIR)
TEST_LOGSDIR = $(TESTDIR)/$(LOGSDIR)
TEST_DEPSDIR = $(TESTDIR)/$(DEPSDIR)
TEST_OUTDIR = $(OUTDIR)

ERRLOG = 2> $(patsubst $(OBJSDIR)/%,$(LOGSDIR)/%,$(@D))/$(shell basename $@).log

CLEANLOG = if [ ! -s $(patsubst $(OBJSDIR)/%,$(LOGSDIR)/%,$(@D))/$(shell basename $@).log ]; \
		   then $(RM) $(patsubst $(OBJSDIR)/%, $(LOGSDIR)/%,$(@D))/$(shell basename $@).log ; fi

POSTCOMP = mv -f $(DEPSDIR)/$*.Td $(DEPSDIR)/$*.d && touch $@

TEST_ERRLOG = 2> $(patsubst $(TEST_OBJSDIR)/%,$(TEST_LOGSDIR)/%,$(@D))/$(shell basename $@).log
TEST_CLEANLOG = if [ ! -s $(patsubst $(TEST_OBJSDIR)/%,$(TEST_LOGSDIR)/%,$(@D))/$(shell basename $@).log ]; \
		   then $(RM) $(patsubst $(TEST_OBJSDIR)/%, $(TEST_LOGSDIR)/%,$(@D))/$(shell basename $@).log ; fi

TEST_POSTCOMP = mv -f $(TEST_DEPSDIR)/$*.Td $(TEST_DEPSDIR)/$*.d && touch $@

DEFAULT = "\033[00m"
GREEN = "\033[0;32m"
TEAL = "\033[0;36m"
RED = "\033[0;31m"

NAME = livecoding_c++

TEST_NAME = test_livecoding_c++

SRCS += $(SRCSDIR)/main.cpp
SRCS += $(SRCSDIR)/JSON/IValue.cpp
SRCS += $(SRCSDIR)/JSON/AValue.cpp
SRCS += $(SRCSDIR)/JSON/Object.cpp
SRCS += $(SRCSDIR)/JSON/Array.cpp
SRCS += $(SRCSDIR)/JSON/Bool.cpp
SRCS += $(SRCSDIR)/JSON/Number.cpp
SRCS += $(SRCSDIR)/JSON/String.cpp

OBJS = $(patsubst $(SRCSDIR)/%,$(OBJSDIR)/%, $(SRCS:.cpp=.o))

TEST_SRCS += $(TEST_SRCSDIR)/

TEST_OBJS = $(patsubst $(TEST_SRCSDIR)/%, $(TEST_OBJSDIR)/%, $(TEST_SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@-$(MKDIR) $(OUTDIR)
	@-$(CXX) -o $(OUTDIR)/$(NAME) $^ $(LDFLAGS) \
	 $(ERRLOG) && \
	 $(ECHO) $(GREEN) "[OK]" $(TEAL) $@ $(DEFAULT) || \
	 $(ECHO) $(RED) "[XX]" $(TEAL) $@ $(DEFAULT)
	@-$(CLEANLOG)

$(OBJSDIR)/%.o: OBJSPATH = $(OBJSDIR)/$(*D)/
$(OBJSDIR)/%.o: LOGSPATH = $(LOGSDIR)/$(*D)/
$(OBJSDIR)/%.o: DEPSPATH = $(DEPSDIR)/$(*D)/
$(OBJSDIR)/%.o: $(SRCSDIR)/%.cpp $(DEPSDIR)/%.d
	@-$(MKDIR) $(OBJSPATH)
	@-$(MKDIR) $(LOGSPATH)
	@-$(MKDIR) $(DEPSPATH)
	@-$(RM) $@
	@-$(CXX) -c $< -o $@ $(DEPFLAGS) $(CPPFLAGS) $(CXXFLAGS) \
	 $(ERRLOG) && \
	 $(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
	 $(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)
	@-$(POSTCOMP)
	@-$(CLEANLOG)

$(DEPSDIR)/%.d: ;

tags:
	@ctags -R $(SRCSDIR)

clean: cleandep
	@-$(RM) $(OBJSDIR)
	@-$(ECHO) $(TEAL) "Removing objects files" $(DEFAULT)

cleandep:
	@-$(RM) $(DEPSDIR)
	@-$(ECHO) $(TEAL) "Removing dependencies files" $(DEFAULT)

cleanlog:
	@-$(RM) $(LOGSDIR)
	@-$(ECHO) $(TEAL) "Removing logs files" $(DEFAULT)

distclean: clean cleanlog 
	@-$(RM) $(OUTDIR)/$(NAME)
	@-$(ECHO) $(TEAL) "Removing binary" $(DEFAULT)

re: distclean all

.PRECIOUS: $(DEPSDIR)/%.d
.PHONY: all clean cleanlog cleandep distclean re tags

.SUFFIXES:
.SUFFIXES: .cpp .o

include $(patsubst $(SRCSDIR)/%,$(DEPSDIR)/%, $(SRCS:.cpp=.d))
