from flask import Flask, send_from_directory, request, jsonify
import subprocess
import os

app = Flask(__name__, static_folder="Web", static_url_path="")

CPP_BINARY = "./client"   # your compiled C++ binary

@app.route("/")
def index():
    return send_from_directory("Web", "index.html")

@app.route("/api/send", methods=["POST"])
def send():
    data = request.json
    msg = data.get("message", "")

    if not os.path.exists(CPP_BINARY):
        return jsonify({"error": "C++ binary not found"}), 500

    # Run your C++ binary
    try:
        result = subprocess.check_output([CPP_BINARY, msg], stderr=subprocess.STDOUT, text=True)
    except Exception as e:
        return jsonify({"error": str(e)}), 500

    return jsonify({"reply": result})

# Serve CSS/JS
@app.route("/<path:path>")
def static_proxy(path):
    return send_from_directory("Web", path)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=True)