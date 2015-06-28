ROOTCFLAGS     = $(shell root-config --cflags)
ROOTLIBS       = $(shell root-config --libs)
ROOTGLIBS      = $(shell root-config --glibs)

INCLUDES       = -I./include 

CXX            = g++
CXXFLAGS       = -fPIC -fno-var-tracking -Wno-deprecated -D_GNU_SOURCE -O2  $(INCLUDES) 
CXXFLAGS      += $(ROOTCFLAGS)

LD             = g++
LDFLAGS        = 

SOFLAGS        = -O -shared  -fPIC #-flat_namespace 
LIBS           = $(ROOTLIBS) 

GLIBS         = $(ROOTGLIBS) -lMinuit -lMinuit2 -lTreePlayer

SRCS =  src/Extendeds.cc src/BaseMassPlotter.cc src/SingleTopTree.C
OBJS =  $(patsubst %.C,%.o,$(SRCS:.cc=.o))

LIB=lib/libSingleTopAnalysis.so


.SUFFIXES: .cc,.C,.hh,.h

# Rules ====================================
all: $(LIB)  bin/Run2j1t bin/Run3j2t
#bin/Run2j0t bin/Run3j2t bin/RunSynch

lib : $(LIB)
$(LIB): $(OBJS)
	@echo "Creating library $(LIB)"
	mkdir -p lib
	$(LD) $(LDFLAGS) $(GLIBS) $(SOFLAGS) $(OBJS) -o $(LIB)
	@echo "$(LIB) successfully compiled!"

bin/Run2j1t : src/SingleTopAnalysis.C $(LIB)	
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -ldl $(LDFLAGS) -DNUMBEROFJETS=2 -DNUMBEROFBJETS=1 -o $@ $^ $(GLIBS)

bin/RunSynch : src/SingleTopAnalysis.C $(LIB)	
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -ldl $(LDFLAGS) -DSYNCH -DNUMBEROFJETS=2 -DNUMBEROFBJETS=1 -o $@ $^ $(GLIBS)

bin/Run2j0t: src/SingleTopAnalysis.C $(LIB)	
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -ldl $(LDFLAGS) -DNUMBEROFJETS=2 -DNUMBEROFBJETS=0 -o $@ $^ $(GLIBS)

bin/Run3j2t: src/SingleTopAnalysis.C $(LIB)	
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -ldl $(LDFLAGS) -DNUMBEROFJETS=3 -DNUMBEROFBJETS=2 -o $@ $^ $(GLIBS)


clean:
	$(RM) $(OBJS)	
	$(RM) $(LIB)
	$(RM) bin/Run*j*t

purge:
	$(RM) $(OBJS)

deps: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it

