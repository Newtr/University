function NewColor1(){
    let NewTextColor = document.getElementById("Glavnaja").style.color = "white";
}
function BackToNormalColor1(){
    let NormalTextColor = document.getElementById("Glavnaja").style.color = "black";
}
function NewColor2(){
    let NewTextColor = document.getElementById("MiniGames").style.color = "white";
}
function BackToNormalColor2(){
    let NormalTextColor = document.getElementById("MiniGames").style.color = "black";
}
function NewColor3(){
    let NewTextColor = document.getElementById("News").style.color = "white";
}
function BackToNormalColor3(){
    let NormalTextColor = document.getElementById("News").style.color = "black";
}
function NewColor4(){
    let NewTextColor = document.getElementById("Shop").style.color = "white";
}
function BackToNormalColor4(){
    let NormalTextColor = document.getElementById("Shop").style.color = "black";
}

function pechataet(){
    let knopka = window.open();
    let kurs = document.querySelector('input[name="radd"]:checked').value;
    let adress = document.getElementById("adress").value;

    let checkboxes = document.getElementsByClassName('checkVybor');
    let checkboxesChecked = []; // можно в массиве их хранить, если нужно использовать (храним в массиве)
    for (var index = 0; index < checkboxes.length; index++) {
    if (checkboxes[index].checked) {
          checkboxesChecked.push(checkboxes[index].value); // положим в массив выбранный элемент
    }
    }

    let predmet = checkboxesChecked;
    let html = '<ul>';
    predmet.forEach(function(value) {        //выполняет функцию callback
    html += '<li>'+"<b>"+value+"</b>"+'</li>';
    });
    html += '</ul>'
    knopka.alert("Кампания не несет ответственность за потерю предметов после их получения");  
    knopka.document.write("Доставка будет осуществялться путем  "+"<b>"+kurs+"</b>"+".</br> Курьер прибудет на место по адресу: "+"<b>"+adress+"</b>"+"</br>Предметы выбраные пользователем:<ul>")
    knopka.document.write(html);
    knopka.document.write("</ul>");
}
