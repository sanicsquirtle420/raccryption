.SILENT: build
build:
	g++ main.cpp -o out/main

.SILENT: run
run:
	./out/main $(ARGS)