# build/go/makefile

PROTO_OUT_DIR = ./
PROTO_SRC_DIR = ./../../proto

PROTO_FILES := $(shell find $(PROTO_SRC_DIR) -name '*.proto' ! -name 'Energyleaf-Old.proto')

# Create the go_opt mapping for each proto file
GO_OPTS := $(patsubst $(PROTO_SRC_DIR)/%.proto,--go_opt=M%.proto=github.com/pgenergy/Protocol,$(PROTO_FILES))

.PHONY: build
build:
	protoc -I=$(PROTO_SRC_DIR) --go_out=$(PROTO_OUT_DIR) $(PROTO_FILES) $(GO_OPTS)

