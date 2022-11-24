//https://blog.csdn.net/weixin_42525191/article/details/114670004
clearInterval(timer);
document.body.innerHTML = "";

//每秒移动多少格
let speed = 10;
let speedUpMul = 3;

//是否能穿墙
let isThroughTheWall = true;

//行数
let row = 40;
let headColor = 'red';
let bodyColor = 'green';
let foodColor = 'yellow';
let borderColor = 'grey';



// 游戏全局变量
let hasFood = false;
//游戏状态
let gamestaus = 'start';
let hasAccelerate = false;

let mainContainer = document.createElement("div");
mainContainer.style.width = 20 * row + 1 + "px";
mainContainer.style.height = 20 * row + 1 + "px";
mainContainer.style.margin = "0 auto";
mainContainer.style.position = "relative";
mainContainer.style.border = "1px solid " + borderColor;

document.body.appendChild(mainContainer);

for(let i = 0;i<row;i++){
    let marginTop = 20 * i + "px";
    for(let j = 0;j<row;j++){
        let marginLeft = j * 20 + "px";
        let tempDiv = document.createElement('div');
        tempDiv.style.width = "19px";
        tempDiv.style.height = "19px";
        tempDiv.style.marginTop = marginTop;
        tempDiv.style.marginLeft = marginLeft;
        tempDiv.style.border = "0.5px solid " + borderColor;
        tempDiv.style.position = "absolute";
        tempDiv.id = j + "div" + i;
        mainContainer.appendChild(tempDiv);
    }
}

class Cell{
    constructor(x, y, color){
        if(isThroughTheWall){
            if(x < 0) x = row+x;
            if(x > row - 1) x = x-row;
            if(y < 0) y = row+y;
            if(y > row - 1) y = y-row;
        }else{
            if(x < 0 || y < 0|| x > row - 1 || y > row - 1){
                clearInterval(timer);
                alert('游戏结束');
                return;
            }
        }
        this.x = x;
        this.y = y;
        this.color = color;
        let tempDiv = document.getElementById(x + 'div' + y);
        if(tempDiv) tempDiv.style.backgroundColor = color;
    }
}

snake = {
    head : {},
    body : [],
    dire : 1
}

let headx = Math.floor(Math.random() * 14) + 3;
let heady = Math.floor(Math.random() * 14) + 3;
snake.head = new Cell(headx, heady, headColor);

//上右下左
let direction = [1, 2, 3, 4]

snake.dire = direction[Math.floor(Math.random() * 4)];

if(snake.dire == 1){
    snake.body.push(new Cell(snake.head.x, snake.head.y+1, bodyColor));
    snake.body.push(new Cell(snake.head.x, snake.head.y+2, bodyColor));
    snake.body.push(new Cell(snake.head.x, snake.head.y+3, bodyColor));
}

if(snake.dire == 2){
    snake.body.push(new Cell(snake.head.x-1, snake.head.y, bodyColor));
    snake.body.push(new Cell(snake.head.x-2, snake.head.y, bodyColor));
    snake.body.push(new Cell(snake.head.x-3, snake.head.y, bodyColor));
}

if(snake.dire == 3){
    snake.body.push(new Cell(snake.head.x, snake.head.y-1, bodyColor));
    snake.body.push(new Cell(snake.head.x, snake.head.y-2, bodyColor));
    snake.body.push(new Cell(snake.head.x, snake.head.y-3, bodyColor));
}

if(snake.dire == 4){
    snake.body.push(new Cell(snake.head.x+1, snake.head.y, bodyColor));
    snake.body.push(new Cell(snake.head.x+2, snake.head.y, bodyColor));
    snake.body.push(new Cell(snake.head.x+3, snake.head.y, bodyColor));
}

function game(){
    if(gamestaus == 'pause'){
        return;
    }
    if(gamestaus == 'gameover'){
        clearInterval(timer);
        alert('游戏结束');
        return;
    }
    initFood();
    let snakeHeadX = snake.head.x;
    let snakeHeadY = snake.head.y;
    let color = '';
    if(snake.dire == 1){
        let tempDiv = document.getElementById(snakeHeadX + 'div' + (snakeHeadY-1));
        if(tempDiv) color = tempDiv.style.backgroundColor;
        snake.head = new Cell(snakeHeadX, snakeHeadY - 1, headColor);
    }
    if(snake.dire == 2){
        let tempDiv = document.getElementById((snakeHeadX + 1) + 'div' + snakeHeadY);
        if(tempDiv) color = tempDiv.style.backgroundColor;
        snake.head = new Cell(snakeHeadX + 1, snakeHeadY, headColor);
    }
    if(snake.dire == 3){
        let tempDiv = document.getElementById(snakeHeadX + 'div' + (snakeHeadY+1));
        if(tempDiv) color = tempDiv.style.backgroundColor;
        snake.head = new Cell(snakeHeadX, snakeHeadY + 1, headColor);
    }
    if(snake.dire == 4){
        let tempDiv = document.getElementById((snakeHeadX - 1) + 'div' + snakeHeadY);
        if(tempDiv) color = tempDiv.style.backgroundColor;
        snake.head = new Cell(snakeHeadX - 1, snakeHeadY, headColor);
    }
    snake.body.unshift(new Cell(snakeHeadX, snakeHeadY, bodyColor));
    if(color && color == foodColor){
        hasFood = false;
        initFood();
    }else if(color && color == bodyColor){
        gamestaus = 'gameover';   
    }else{
        let lastBody = snake.body.pop();
        new Cell(lastBody.x, lastBody.y, '');
    }
}
var timer = setInterval(game, 10 / speed * 100)


/**
 * 初始化食物
 */
function initFood(){
    while(!hasFood){
        let x = Math.floor(Math.random() * row);
        let y = Math.floor(Math.random() * row);
        let snakeBody = snake.body;
        let enable = true;
        if(snake.head.x == x && snake.head.y == y){
            enable = false;
        }
        for(sBody of snakeBody){
            if(sBody.x == x && sBody.y == y){
                enable = false;
                break;
            }
        }
        if(enable){
            new Cell(x, y, foodColor);
            hasFood = true;
        }
    }
}

document.onkeydown = function(e){
    if(e.keyCode == 38){
        //上
        if(snake.dire != 3 && snake.dire != 1){
            snake.dire = 1;
        }else if(snake.dire == 1){
            if(!hasAccelerate){
                clearInterval(timer);
                hasAccelerate = true;
                speed = speed * speedUpMul;
                timer = setInterval(game, 10 / speed * 100)
            }
        }

    }

    if(e.keyCode == 39){
        //右
        if(snake.dire != 4 && snake.dire != 2){
            snake.dire = 2;
        }else if(snake.dire == 2){
            if(!hasAccelerate){
                clearInterval(timer);
                hasAccelerate = true;
                speed = speed * speedUpMul;
                timer = setInterval(game, 10 / speed * 100)
            }
        }
    }

    if(e.keyCode == 40){
        //下
        if(snake.dire != 1 && snake.dire != 3){
            snake.dire = 3;
        }else if(snake.dire == 3){
            if(!hasAccelerate){
                clearInterval(timer);
                hasAccelerate = true;
                speed = speed * speedUpMul;
                timer = setInterval(game, 10 / speed * 100)
            }
        }
    }

    if(e.keyCode == 37){
        //左
        if(snake.dire != 2 && snake.dire != 4){
            snake.dire = 4;
        }else if(snake.dire == 4){
            if(!hasAccelerate){
                clearInterval(timer);
                hasAccelerate = true;
                speed = speed * speedUpMul;
                timer = setInterval(game, 10 / speed * 100)
            }
        }
    }
    //空格键暂停
    if(e.keyCode == 32){
        if(gamestaus == 'start'){
            gamestaus = 'pause';
        }else if(gamestaus == 'pause'){
            gamestaus = 'start';
        }
    }
}

document.onkeyup = function(e){
    if(e.keyCode == 38){
        //上
        if(snake.dire == 1 && hasAccelerate){
            clearInterval(timer);
            hasAccelerate = false;
            speed = speed / speedUpMul;
            timer = setInterval(game, 10 / speed * 100)
        }

    }

    if(e.keyCode == 39){
        //右
         if(snake.dire == 2 && hasAccelerate){
            clearInterval(timer);
            hasAccelerate = false;
            speed = speed / speedUpMul;
            timer = setInterval(game, 10 / speed * 100)
        }
    }

    if(e.keyCode == 40){
        //下
         if(snake.dire == 3 && hasAccelerate){
            clearInterval(timer);
            hasAccelerate = false;
            speed = speed / speedUpMul;
            timer = setInterval(game, 10 / speed * 100)
        }
    }

    if(e.keyCode == 37){
        //左
        if(snake.dire == 4 && hasAccelerate){
            clearInterval(timer);
            hasAccelerate = false;
            speed = speed / speedUpMul;
            timer = setInterval(game, 10 / speed * 100)
        }
    }
}
