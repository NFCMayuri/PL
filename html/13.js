onload = function () {
    setInterval(function () {
        var x = document.getElementsByClassName("b")[0];
        console.log(x.style.left); // can be modified
        console.log(x.offsetLeft); // read only
        x.style.left = (x.offsetLeft - 1) + "px"
    }, 10);
}