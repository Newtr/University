let info =navigator.userAgent;
let el1=document.getElementById("info");
el1.innerHTML=info;

let version =navigator.appVersion;
let el2 = document.getElementById("version");
el2.innerHTML=version;

let broName = navigator.appName;
let el3 = document.getElementById("broName");
el3.innerHTML=broName;

let kod = navigator.appCodeName;
let el4 = document.getElementById("kod");
el4.innerHTML=kod;

let Os = navigator.platform;
let el5 = document.getElementById("Os");
el5.innerHTML=Os;

let JavaSupport = navigator.javaEnabled();
let el6 = document.getElementById("JavaSupport");
el6.innerHTML=JavaSupport;

let WidthHeight = (" "+ screen.width + "Х"+screen.height);
let el7 = document.getElementById("WidthHeight");
el7.innerHTML=WidthHeight;

let glubina =screen.colorDepth;
let el8 = document.getElementById("glubina");
el8.innerHTML=glubina;

let url = history.length;
let el9 = document.getElementById("url");
el9.innerHTML=url;

let tekusUrl = location.href;
let el10 = document.getElementById("tekusUrl");
el10.innerHTML=tekusUrl;

let put = location.pathname;
let el11 = document.getElementById("put");
el11.innerHTML=put;

let nameDomen = location.host;
let el12 = document.getElementById("nameDomen");
el12.innerHTML=nameDomen;

function knopkaOpen(){
    window.open();
}
function knopkaClose(){
    window.close();
}
function knopkaSTextom(){
    let okno = window.open();
    okno.document.title = "New document";
    okno.document.write("Some kind of text"+" <--And the title of page-->"+ okno.document.title);
}
