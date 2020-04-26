INSTALL_DIR=/usr/local/share/pit/scripts

# Create scripts directory
[ -d $INSTALL_DIR ] || mkdir -p $INSTALL_DIR

# Copy content
cp -r pit commands $INSTALL_DIR
