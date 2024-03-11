
function mul2(n) {
	return n*2;
}

function make_handler(span, input){
	return function(){
	span.innerHTML = mul2(input.value);
	}	
}

