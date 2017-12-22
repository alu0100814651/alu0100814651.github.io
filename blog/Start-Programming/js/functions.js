function usrpas(inputtxt, pass) {
	var val = /^(([^<>()[\]\.,;:\s@\"]+(\.[^<>()[\]\.,;:\s@\"]+)*)|(\".+\"))@(([^<>()[\]\.,;:\s@\"]+\.)+[^<>()[\]\.,;:\s@\"]{2,})$/i
;
	var pwd = /^[a-zA-Z0-9]{10,}$/;
	if((inputtxt.value.match(val)) && (pass.value.match(pwd))) {
		window.open("./main.html");
	}
	else {
		if(inputtxt.value.match(val)) {
		}
		else {
			alerta();
		}
		if (pass.value.match(pwd)) {
		}
		else {
			altertapass();
		}
	}
}

function alerta() {
	alert("USER INCORRECT!!!!");
}

function altertapass() {
	alert("PASSWORD INCORRECT!!!!");
}

function redireccionarPagina() {
	window.location.href = "log_in.html";
}

function linkedin() {
	window.open("https://www.linkedin.com/in/nitesh-gul-ramnani-8424b714b/");
}

function facebook() {
	window.open("https://www.facebook.com/NiTz.CoOl.RaMnAnI");
}

function instagram() {
	window.open("https://www.instagram.com/nitzramnani/");
}

function google() {
	window.open("https://plus.google.com/u/0/109409789364472151605");
}

function openhtml() {
	window.open("./html.html","_self");
}

function opencss() {
	window.open("./css.html","_self");
}

function openjs() {
	window.open("./js.html","_self");
}


document.oncontextmenu=new Function("return false");