all: saida entrada.txt
	./saida < entrada.txt

saida: lex.yy.c y.tab.c
	g++ -std=c++17 y.tab.c -o saida -ll

lex.yy.c: minijs.l
	lex minijs.l

y.tab.c: minijs.y
	yacc minijs.y
	
clean:
	rm -f lex.yy.c y.tab.c saida