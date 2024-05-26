# build/cpp/makefile

.PHONY: all clean zip

all: build zip

PROTO_OUT_DIR = ./generated
PROTO_SRC = ./../../proto/Energyleaf.proto

build:
	@mkdir -p $(PROTO_OUT_DIR)
	protoc -I=./../../proto/ --cpp_out=$(PROTO_OUT_DIR) $(PROTO_SRC)

zip:
	7z a ./../../release/cpp_build.zip ./generated/*

clean:
	rm ./../../release/cpp_build.zip
	rm -rf ./generated