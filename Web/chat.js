async function sendMessage() {
    let input = document.getElementById("msgInput");
    let text = input.value;

    if (!text.trim()) return;

    addMessage(text, "you");
    input.value = "";

    let response = await fetch("/api/send", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ message: text })
    });

    let data = await response.json();

    if (data.reply) {
        addMessage(data.reply, "cpp");
    }
}

function addMessage(text, type = "cpp") {
    let box = document.getElementById("messages");

    let m = document.createElement("div");
    m.className = "message " + (type === "you" ? "you" : "");

    m.innerText = text;
    box.appendChild(m);

    box.scrollTop = box.scrollHeight;
}