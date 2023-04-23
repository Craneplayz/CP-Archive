const http = require("http");
const fs = require("fs");
const path = require("path");

const defaultPath = "homepage.html";

const contentTypes = {
    "html": "text/html",
    "css": "text/css"
}

const server = http.createServer((request, response) => {
    const { url } = request;
    var requestPath = url.slice(1);

    if (!requestPath) requestPath = defaultPath;
    const filePath = path.join(__dirname, requestPath);
    
    var fileType = requestPath.split(".").pop();
    const contentType = contentTypes[fileType];

    serveStaticFile(response, filePath, contentType);
    
    // response.writeHead(404, { "Content-Type": "text/plain" });
    // response.end("404 Not Found");
});

function serveStaticFile(response, filePath, contentType) {
  fs.readFile(filePath, (err, data) => {
    if (err) {
      response.writeHead(500, { "Content-Type": "text/plain" });
      response.end("Internal Server Error");
    } else {
      response.writeHead(200, { "Content-Type": contentType });
      response.end(data);
    }
  });
}