# build/c/makefile
# Note: this is using nanopb for usage mainly at microcontrollers
# Requires that all requirements of nanopb are met

.PHONY: all clean zip

all: build zip

PROTO_OUT_DIR = /generated
PROTO_OUT_DIR_PATH = $(realpath ./)$(PROTO_OUT_DIR)
PROTO_SRC_DIR = ./../../proto
NANOPB = $(realpath ./../../nanopb/generator/protoc)

PROTO_FILES := $(shell find $(PROTO_SRC_DIR) -name '*.proto' -exec realpath {} \;)

build:
	@mkdir -p $(PROTO_OUT_DIR_PATH)
	@echo "Generating C code from protobuf files..."
	@echo $(PROTO_FILES)
	cd $(realpath $(PROTO_SRC_DIR)) && $(NANOPB) --nanopb_out=$(PROTO_OUT_DIR_PATH) $(PROTO_FILES) -I=$(realpath $(PROTO_SRC_DIR))

zip:
	7z a ./../../release/c_build.zip ./generated/*

clean:
	rm -f ./../../release/c_build.zip
	rm -rf ./generated
