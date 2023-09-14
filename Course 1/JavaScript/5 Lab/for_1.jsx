"use strict";
let allElems = document.getElementsByTagName('*');
let allElemsNumber = allElems.nodeType;
function go(){
    console.log(allElems);
    console.log(allElemsNumber);
}
function go2(){
for(let i=0; i<document.body.childNodes.length; i++) {
    let child = document.body.childNodes[i]
    console.log(child.tagName)
}
}
function spanById(){
    let elemSpanById=document.getElementById('spanElem');
    console.log(elemSpanById);
}
function spanByClass(){
    let elemSpanByClass=document.getElementsByClassName('spanClassElem');
    console.log(elemSpanByClass);
}
function spanByBy(){
    let elemSpanByBy = document.getElementsByTagName('span');
    console.log(elemSpanByBy);
}
function sredBal(){
    let math=7;
    let fiz=6
    let informat=8;
    let sredniiBal=(math+fiz+informat)/3;
    let el_sredBal = document.getElementById("sred_bal");
    el_sredBal.innerHTML = sredniiBal;
}
function dobSpan(){
    let firtsSpan = document.getElementById("spanElem");
    let math=7;
    let fiz=6
    let informat=8;
    let sredniiBal=(math+fiz+informat)/3;
    firtsSpan.innerHTML=" ВТОРОЙ СПАН. спан как айди и средний балл" +sredniiBal;
}