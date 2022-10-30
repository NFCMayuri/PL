function a() {
    x = document.forms["fo"]["txt"].value
    if (x == null || x == "") {
        alert("input can't be blank")
        return false
    }
    else if (x == "123456") {
        alert("login success!")
    }
    else {
        alert("password is wrong")
        return false
    }
}
function b() {
    windows.location = "11.html"
}

function c()
{
    setTimeout(function(){
        document.write("1234565432")
    },3000)
}