# build/go/makefile

PROTO_OUT_DIR = ./
PROTO_SRC = ./../../proto/Energyleaf.proto

.PHONY: build
build:
	protoc -I=./../../proto/ --go_out=$(PROTO_OUT_DIR) $(PROTO_SRC) --go_opt=MEnergyleaf.proto="github.com/pgenergy/Protocol"
