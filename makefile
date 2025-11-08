.SILENT: build
build:
	g++ main.cpp src/ractils.cpp -o raccryption

.SILENT: dev
dev:
	g++ test/test.cpp src/ractils.cpp -o test/test && ./test/test