all:
	bison -y -d parser.y 
	flex lexer.l
	gcc y.tab.c lex.yy.c Node.c 
