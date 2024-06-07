# build/cpp/makefile

.PHONY: all clean zip

all: build zip

PROTO_OUT_DIR = ./generated
PROTO_SRC_DIR = ./../../proto
PROTO_FILES := $(shell find $(PROTO_SRC_DIR) -name '*.proto')

build:
	@mkdir -p $(PROTO_OUT_DIR)
	@echo "Generating C++ code from protobuf files..."
	@echo $(PROTO_FILES)
	@protoc -I=$(PROTO_SRC_DIR) --cpp_out=$(PROTO_OUT_DIR) $(PROTO_FILES)

zip:
	7z a ./../../release/cpp_build.zip ./generated/*

clean:
	rm ./../../release/cpp_build.zip
	rm -rf ./generated
