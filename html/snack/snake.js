let direction = 4;
let row = 40;
// let isThroughTheWall = true;

let HeadColor = 'red';
let SnakeBodyColor = 'orange';
let foodColor = 'green';
let borderColor = 'grey';
eaten = false;
head = {
    x: 3,
    y: 0
};
SnakeBody = [
    { x: 2, y: 0 }, { x: 1, y: 0 }, { x: 0, y: 0 }
];
food = { x: 0, y: 0 }
document.onkeyup = function (e) {
    switch (e.code) {
        case "ArrowUp": {
            if (direction != 2) {
                direction = 1;
            }
            break;
        }
        case "ArrowDown": {
            if (direction != 1) {
                direction = 2;
            }
            break;
        }
        case "ArrowLeft": {
            if (direction != 4) {
                direction = 3;
            }
            break;
        }
        case "ArrowRight": {
            if (direction != 3) {
                direction = 4;
            }
            break;
        }
        case "Space": {
            direction = 4;
            break;
        }
    }
}

document.onkeyup = function (e) {
    switch (e.code) {
        case "ArrowUp": {
            if (direction != 2) {
                direction = 1;
            }
            break;
        }
        case "ArrowDown": {
            if (direction != 1) {
                direction = 2;
            }
            break;
        }
        case "ArrowLeft": {
            if (direction != 4) {
                direction = 3;
            }
            break;
        }
        case "ArrowRight": {
            if (direction != 3) {
                direction = 4;
            }
            break;
        }
        // case "Space": {
        //     direction = 5;
        //     break;
        // }
    }
}

// code捕获函数
// document.onkeydown = function (e) {
//     console.log('code: ', e.code);
// }

function Start() {
    Init();
    //蛇头蛇身食物上色
    document.getElementById(head.x + "-" + head.y).style.backgroundColor = HeadColor;
    for (i of SnakeBody) {
        document.getElementById(i.x + "-" + i.y).style.backgroundColor = SnakeBodyColor;
    }
    //随机食物位置
    randomFood()
    //循环开始
    var loop = setInterval(function Game() {
        if (isFail()) {
            clearInterval(loop);
            alert("Game Over")
        } else {
            if ((food.x === head.x && food.y === head.y)) {
                eaten = true;
                randomFood();
            }
            //蛇头加入蛇身
            SnakeBody.unshift({ x: head.x, y: head.y });
            //蛇身上色
            document.getElementById(head.x + "-" + head.y).style.backgroundColor = SnakeBodyColor;
            //移动蛇头
            switch (direction) {
                case 1:
                    head.y--;
                    break;
                case 2:
                    head.y++;
                    break;
                case 3:
                    head.x--;
                    break;
                case 4:
                    head.x++;
                    break;
            }
            //蛇头上色
            document.getElementById(head.x + "-" + head.y).style.backgroundColor = HeadColor;
            //如果没吃东西去掉末尾的颜色并裁剪末尾
            if (!eaten) {
                document.getElementById((SnakeBody[SnakeBody.length - 1]).x + "-" + (SnakeBody[SnakeBody.length - 1]).y).style.backgroundColor = ""
                SnakeBody.pop()
            } else {
                eaten = false;
            }
        }
    }, 300);
}

function isFail() {
    if (isSnakeBody(head.x, head.y)) {
        return true;
    } else if ((head.x >= row || head.x < 0) || (head.y >= row || head.y < 0)) {
        return true;
    } else {
        return false;
    }
}

function isSnakeBody(x, y) {
    ret = false;
    for (i of SnakeBody) {
        if ((i.x === x) && (i.y === y)) {
            ret = true;
        }
    }
    return ret;
}

function moveUp() {
    if (direction == 1) // Right
    {
        if (array[i][j] == '*') {
            n++; // length++
            p[n] = p[n - 1];
            randomApple();
        }
    }
}
function Init() {
    //清空网页
    document.body.innerHTML = "";
    //边框大div
    let Container = document.createElement("div");
    Container.style.border = "1px solid " + borderColor;
    //每个小格子的长宽均为20px
    Container.style.height = 20 * row + 1 + "px";
    Container.style.width = 20 * row + 1 + "px";
    Container.style.position = "relative";
    //写入网页
    document.body.appendChild(Container);
    //循环创建小div格子并给予一个唯一的id以便后面判断以及修改颜色
    for (let i = 0; i < row; i++) {
        let marginTopI = 20 * i;
        for (let j = 0; j < row; j++) {
            let marginLeftj = 20 * j;
            let Column = document.createElement("div");
            //绝对定位
            Column.style.position = "absolute";
            //记录id(x-y)
            Column.id = j + "-" + i;
            //背景色白色
            Column.style.backgroundColor = "white";
            //长宽均为19px 边框0.5px
            Column.style.width = "19px";
            Column.style.height = "19px";
            Column.style.marginTop = marginTopI + "px";
            Column.style.marginLeft = marginLeftj + "px";
            Column.style.border = "0.5px solid " + borderColor;
            //append到Container div
            Container.appendChild(Column);

        }
    }
}
function randomFood() {
    do {
        food.x = Math.floor(Math.random() * row)
        food.y = Math.floor(Math.random() * row)
    } while (isSnakeBody(food.x, food.y) || (food.x === head.x && food.y === head.y))
    document.getElementById(food.x + "-" + food.y).style.backgroundColor = foodColor;
}