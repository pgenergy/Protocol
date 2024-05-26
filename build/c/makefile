# build/c/makefile
# Note: this is using nanopb for usage mainly at microcontrollers
# Requires that all requirements of nanopb are met

.PHONY: all clean zip

all: build zip

PROTO_OUT_DIR = ./generated
PROTO_SRC = ./../../proto/Energyleaf.proto

build:
	@mkdir -p $(PROTO_OUT_DIR)
	protoc --plugin=protoc-gen-nanopb=./../../nanopb/generator/protoc-gen-nanopb -I=./../../proto/ --nanopb_out=$(PROTO_OUT_DIR) $(PROTO_SRC)

zip:
	7z a ./../../release/c_build.zip ./generated/*

clean:
	rm ./../../release/c_build.zip
	rm -rf ./generated