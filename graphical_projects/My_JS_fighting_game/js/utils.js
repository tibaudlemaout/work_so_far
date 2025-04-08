function hitcollision({ rectangle1, rectangle2 }) {
    return (rectangle1.attackBox.position.x + rectangle1.attackBox.width >= rectangle2.position.x &&
        rectangle1.attackBox.position.x <= rectangle2.position.x + rectangle2.width &&
        rectangle1.attackBox.position.y + rectangle1.attackBox.height >= rectangle2.position.y &&
        rectangle1.attackBox.position.y <= rectangle2.position.y + rectangle2.height)
}

function winner({player, enemy, timerid}) {
    clearTimeout(timerid)
    document.querySelector('#displaytie').style.display = 'flex'
    if (player.health === enemy.health) {
        document.querySelector('#displaytie').innerHTML = 'Tie'
    } else if (player.health > enemy.health) {
        document.querySelector('#displaytie').innerHTML = 'Player 1 Wins'
    } else if (player.health < enemy.health) {
        document.querySelector('#displaytie').innerHTML = 'Player 2 Wins'
    }
}

let timer = 46
let timerid
function decrease_timer() {
    if (timer > 0) {
        timerid = setTimeout(decrease_timer, 1000)
        timer --
        document.querySelector('#timer').innerHTML = timer
    }

    if (timer === 0) {
        winner({player, enemy, timerid})
    }
}