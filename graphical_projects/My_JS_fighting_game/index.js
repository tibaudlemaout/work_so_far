const canvas = document.querySelector('canvas');
const ctx = canvas.getContext('2d');

canvas.width = 1024
canvas.height = 576

ctx.fillRect(0, 0, 1024, 576)

const gravity = 0.8

const background = new Sprite({
    position: {
        x: 0,
        y: 0
    },
    imageSrc: 'assets/background.png'
})

const shop = new Sprite({
    position: {
        x: 625,
        y: 130
    },
    frames: 6,
    scale: 2.75,
    imageSrc: 'assets/shop.png'
})

const player = new Fighter({
    position: {
        x: 0,
        y: 0
    },
    velocity: {
        x: 0,
        y: 0
    },
    offset: {
        x: 0,
        y: 0
    },
    imageSrc: "assets/Player_asset/Sprites/Idle.png",
    frames: 8
})

const enemy = new Fighter({
    position: {
        x: 400,
        y: 100
    },
    velocity: {
        x: 0,
        y: 0
    },
    offset: {
        x: -50,
        y: 0
    },
    color: 'red'
})

const keys = {
    q: {
        pressed: false
    },
    d: {
        pressed: false
    },
    z: {
        pressed: false
    },
    ArrowLeft: {
        pressed: false
    },
    ArrowRight: {
        pressed: false
    },
    ArrowUp: {
        pressed: false
    }
}

decrease_timer()

function animate() {
    window.requestAnimationFrame(animate)
    ctx.fillStyle = 'black'
    ctx.fillRect(0, 0, 1024, 576)
    background.update()
    shop.update()

    player.update()
    enemy.update()

    player.velocity.x = 0
    enemy.velocity.x = 0

    //player movement
    if (keys.q.pressed && player.lastkey === 'q') {
        player.velocity.x = -5
    } else if (keys.d.pressed && player.lastkey === 'd') {
        player.velocity.x = 5
    }

    //enemy movement
    if (keys.ArrowLeft.pressed && enemy.lastkey === 'ArrowLeft') {
        enemy.velocity.x = -5
    } else if (keys.ArrowRight.pressed && enemy.lastkey === 'ArrowRight') {
        enemy.velocity.x = 5
    }

    //detect player hitting enemy
    if (hitcollision({
        rectangle1 : player,
        rectangle2: enemy
    }) && player.attacks) {
        player.attacks = false
        enemy.health -= 20
        document.querySelector('#enemyhealth').style.width = enemy.health + '%'
        console.log('enemy got hit')
    }

    //detect enemy hitting player
    if (hitcollision({
        rectangle1 : enemy,
        rectangle2: player
    }) && enemy.attacks) {
        enemy.attacks = false
        player.health -= 20
        document.querySelector('#playerhealth').style.width = player.health + '%'
        console.log('player got hit')
    }

    //end game conditions
    if (enemy.health <= 0 || player.health <= 0) {
        winner({player, enemy, timerid})
    }
}

animate()

window.addEventListener('keydown', (event) => {
    switch (event.key) {
        case 'd':
            keys.d.pressed = true
            player.lastkey = 'd'
            break
        case 'q':
            keys.q.pressed = true
            player.lastkey = 'q'
            break
        case 'z':
            player.velocity.y = -20
            break
        case 's':
            player.attacking()
            break

        case 'ArrowRight':
            keys.ArrowRight.pressed = true
            enemy.lastkey = 'ArrowRight'
            break
        case 'ArrowLeft':
            keys.ArrowLeft.pressed = true
            enemy.lastkey = 'ArrowLeft'
            break
        case 'ArrowUp':
            enemy.velocity.y = -20
            break
        case 'ArrowDown':
            enemy.attacking()
            break
    }
})

window.addEventListener('keyup', (event) => {
    switch (event.key) {
        case 'd':
            keys.d.pressed = false
            break
        case 'q':
            keys.q.pressed = false
            break
        case 'z':
            keys.z.pressed = false
            break

        case 'ArrowRight':
            keys.ArrowRight.pressed = false
            break
        case 'ArrowLeft':
            keys.ArrowLeft.pressed = false
            break
        case 'ArrowUp':
            keys.ArrowUp.pressed = false
            break
    }
})
