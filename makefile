default: main
sketch: main.c
	clang -std=c11 -Wall -pedantic -g $@.c -lSDL2 -o $@ \
		   -fsanitize=undefined -fsanitize=address

test: sketch.c test.c
	clang -std=c11 -Wall -pedantic -g sketch.c test.c -o $@ \
		   -fsanitize=undefined -fsanitize=address

%: %.c
	clang -Dtest_$@ -std=c11 -Wall -pedantic -g $@.c -o $@ \
		   -fsanitize=undefined -fsanitize=address
		 #
			#  clang -std=c11 -Wall -pedantic -g $@.c display.c -lSDL2 -o $@ \
		 # 		   -fsanitize=undefined -fsanitize=address
		 #
		 # test: sketch.c test.c
		 # 	clang -std=c11 -Wall -pedantic -g sketch.c test.c -o $@ \
		 # 		   -fsanitize=undefined -fsanitize=address
		 #
		 # %: %.c
		 # 	clang -Dtest_$@ -std=c11 -Wall -pedantic -g $@.c -o $@ \
		 # 		   -fsanitize=undefined -fsanitize=address
