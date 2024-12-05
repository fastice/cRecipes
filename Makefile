CC =		gcc
INCLUDEPATH =	..
CFLAGS  =  $(FLAGS) -c -I$(INCLUDEPATH)
ifeq ($(OSTYPE), darwin)
	CFLAGS  = $(FLAGS) -c -I$(INCLUDEPATH)
endif

FFLAGS  =	 -g

OBJS=	gammln.o poidev.o sort.o polint.o nrutil.o ratint.o four1.o \
        svdfit.o svbksb.o  svdcmp.o pythag.o hunt.o svdvar.o \
	mrqmin.o mrqcof.o covsrt.o gaussj.o

MACHTYPE = $(shell uname -m)
OSTYPE = $(shell uname -s)

$(shell mkdir -p $(MACHTYPE)-$(OSTYPE))


.KEEP_STATE:
all:	$(OBJS)
	mv *.o $(MACHTYPE)-$(OSTYPE)





