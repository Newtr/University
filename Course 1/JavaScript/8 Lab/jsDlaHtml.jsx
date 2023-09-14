function Zadanie1(){
    let NewTextColor = document.getElementById("Zadanie1").style.color = "blue";
}
function Zadanie1BackToNormalColor(){
    let NormalTextColor = document.getElementById("Zadanie1").style.color = "black";
}

function Zadanie2(){
    let NewTextSize = document.getElementById("Zadanie2").style.fontSize = "20px";
}

function Zadanie3(){
    let NewPicture = document.getElementById("Zadanie3");
    NewPicture.src = "Cat_1.jpeg";
}

function Zadanie4(){
    let TextToPicture = document.getElementById("Zadanie4");
    TextToPicture.innerHTML = "<img src='Cat_1.jpeg' />";
}

function Zadanie5(){
    let NewPictureSize = document.getElementById("Zadanie5").style.width = "200px";
}
function Zadanie5BackToNormalSize(){
    let NormalPictureSize = document.getElementById("Zadanie5").style.width = "100px";
}

function Zadanie6(){
    let NewBorderForText = document.getElementById("Zadanie6").style.border = "2px solid red";
}