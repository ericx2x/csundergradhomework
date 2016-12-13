JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	AList.java \
	NEList.java \
	EmptyList.java \
	IListVisitor.java \
	ToString.java \
	Copy.java \
	GetMax.java \
	GetNth.java \
	Reverse.java \
	LastElement.java \
	Sum.java \
	Length.java \
	FindMin.java \
	Test.java

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class
