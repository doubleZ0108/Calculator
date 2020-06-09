let result = null;

window.onload = function(){
    result = $('result');
    $('ac').onclick = function(){
        clear();
    };

    $('equal').onclick = function(){
        calculate();
    };

    document.querySelectorAll("button:not(#ac):not(#equal)").forEach(function(elem, index){
        elem.onclick = function(){
            appendChar(elem.innerHTML);
        };
    });
};

function clear(){
    result.innerHTML = '0';
    result.style.fontSize = 48 + 'px';
}

function appendChar(ch){
    let str = result.innerHTML.trim();
    
    if(str.length > 9 && str.length <= 15){
        result.style.fontSize = 30 + 'px';
    }
    else if(str.length > 15 && str.length <= 24){
        result.style.fontSize = 20 + 'px';
    }
    else if (str.length > 24){
        alert("计算器最大输入位数为24");
        return;
    }

    if(parseInt(str) === 0){
        result.innerHTML = "";
    }
    result.innerHTML += ch;
}

function calculate(){
    console.log(result.innerHTML.trim());
}