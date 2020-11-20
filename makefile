all:taschenrechner

taschenrechner:
	c++ Taschenrechner_V1/Taschenrechner_fancy.cpp

clean:
	-rm -f a.out
