
function pechat(){
    let knopka = window.open();
    let surname = document.getElementById("surname").value;
    let spec = document.getElementById("spec").value;
    let kurs = document.querySelector('input[name="rad"]:checked').value;

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
    html += '<li>'+value+'</li>';
    });
    html += '</ul>'
    
    knopka.document.write("Студент "+surname+" специальность "+spec+" курс "+kurs+" должен сдавать следующие предметы:<ul>")
    knopka.document.write(html);
    knopka.document.write("</ul>");
}
