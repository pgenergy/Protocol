# build/cpp/makefile

.PHONY: all clean zip

all: build zip

PROTO_OUT_DIR = ./
PROTO_SRC = ./../../proto/Energyleaf.proto

build:
	@mkdir -p $(PROTO_OUT_DIR)
	protoc -I=./../../proto/ --go_out=$(PROTO_OUT_DIR) $(PROTO_SRC) --go_opt=MEnergyleaf.proto="github.com/pgenergy/Protocol"

zip:
	7z a ./../../release/cpp_build.zip ./generated/*

clean:
	rm ./../../release/cpp_build.zip
	rm -rf ./generated
