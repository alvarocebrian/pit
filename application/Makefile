BIN_DIR = bin
export BUILD_DIR = $(abspath $(BIN_DIR))

INSTALL_DIR = /usr/local/share/pit
INSTALL_BIN_DIR = /usr/local/bin

# Default target
.SILENT:
build:: $(BUILD_DIR)
	@echo "Building pit"

	$(MAKE) -C lib;
	$(MAKE) -C src/core;
	$(MAKE) -C src/builtin-commands

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(INSTALL_DIR):
	@mkdir -p $(INSTALL_DIR)

clean:
	@rm -rf $(BUILD_DIR)

install: build $(INSTALL_DIR)
	@echo "Installing pit"

	# Install binaries
	@cp -r $(BUILD_DIR) $(INSTALL_DIR)

	# Create symlink
	@ln -fs $(INSTALL_DIR)/$(BIN_DIR)/pit $(INSTALL_BIN_DIR)

all: build install clean

