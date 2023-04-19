CC =		gcc
INCLUDEPATH =	..
CFLAGS  =  $(FLAGS) -c -I$(INCLUDEPATH)
ifeq ($(OSTYPE), darwin)
	CFLAGS  = $(FLAGS) -c -I$(INCLUDEPATH)
endif
#echo $CFLAGS
FFLAGS  =	 -g

#ran0.o 
OBJS=	gammln.o poidev.o sort.o polint.o nrutil.o ratint.o four1.o \
        svdfit.o svbksb.o  svdcmp.o pythag.o hunt.o svdvar.o \
	mrqmin.o mrqcof.o covsrt.o gaussj.o

.KEEP_STATE:
all:	$(OBJS)
	mv *.o $(MACHTYPE)-$(OSTYPE)





