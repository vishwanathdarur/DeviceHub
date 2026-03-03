BUILD_DIR := build
CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra

CLIENT_SOURCES := Client/src/client.cpp Test/check1.cpp
SERVER_SOURCES := Server/src/server.cpp Test/check.cpp

.PHONY: demo demo-client demo-server clean

demo: demo-server demo-client

demo-server: $(BUILD_DIR)/devicehub_server_demo

demo-client: $(BUILD_DIR)/devicehub_client_demo

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/devicehub_server_demo: $(SERVER_SOURCES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SERVER_SOURCES) -I Server/include -o $@

$(BUILD_DIR)/devicehub_client_demo: $(CLIENT_SOURCES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(CLIENT_SOURCES) -I Client/include -o $@

clean:
	rm -rf $(BUILD_DIR)
