var express = require("express");
var config = require("config");
var bodyParser = require("body-parser");
var app = express();
var controllers = require(__dirname + "/apps/controllers");

app.use(controllers);
// body parser
app.use(bodyParser.json());

app.set("views", __dirname + "/apps/views");
//Render Html+Json
app.set("view engine", "ejs");

// Staticfolder
app.use("/static", express.static(__dirname + "/public"));

var host = config.get("server.host");
var port = config.get("server.port");

app.listen(port, host, function(){
	console.log("Server is running on port", port);
});