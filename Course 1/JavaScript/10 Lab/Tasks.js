"use strict";
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.0/jquery.min.js"></script>;
var pics = ["cat.jpeg", "download.jpg"];
function onMouseOverFunction(object) {
  object.style.color = "red";
}
function onClickFunction(object) {
  object.style.fontSize = "24px";
}
function imageChange() {
  let image = document.getElementById("image");
  image.src = pics[1];
}
function textChange() {
  let text = document.getElementById("text");
  text.innerHTML = "<img src='download.jpg'/>";
}
function Mouseon(object) {
  object.style.width = "250px";
}
function Mouseoff(object) {
  object.style.width = "200px";
}
function newBorder(object) {
  object.style.border = "outset 5px red";
}
