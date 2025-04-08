class Sprite {
    constructor ({ position, imageSrc, scale = 1, frames = 1 }) {
        this.position = position
        this.width = 1024
        this.height = 576
        this.image = new Image()
        this.image.src = imageSrc
        this.scale = scale
        this.frames = frames
        this.currframes = 0
        this.framesElapsed = 0
        this.framesHold = 8
    }

    draw() {
        ctx.drawImage(
            this.image,
            this.currframes * (this.image.width / this.frames),
            0,
            this.image.width / this.frames,
            this.image.height,
            this.position.x,
            this.position.y,
            (this.image.width / this.frames) * this.scale,
            this.image.height * this.scale)
    }

    update() {
        this.draw()
        this.framesElapsed++

        if (this.framesElapsed % this.framesHold === 0) {
            if (this.currframes < this.frames - 1) {
                this.currframes++
            } else {
                this.currframes = 0
            }
        }
    }
}

class Fighter extends Sprite {
    constructor ({position, velocity, color = 'white', offset, imageSrc, scale = 1, frames = 1}) {
        super({
            position,
            imageSrc,
            scale,
            frames,
        })
        this.velocity = velocity
        this.width = 50
        this.height = 150
        this.lastkey
        this.attackBox = {
            position: {
                x: this.position.x,
                y: this.position.y
            },
            offset: offset,
            width: 100,
            height: 50
        }
        this.color = color
        this.attacks
        this.health = 100
        this.currframes = 0
        this.framesElapsed = 0
        this.framesHold = 8
    }

    draw() {
        ctx.fillStyle = this.color
        ctx.fillRect(this.position.x, this.position.y, this.width, this.height)

        //attack box rectangle
        if (this.attacks) {
            ctx.fillStyle = 'white'
            ctx.fillRect(this.attackBox.position.x, this.attackBox.position.y,
                this.attackBox.width, this.attackBox.height)
        }
    }

    update() {
        this.draw()
        this.attackBox.position.x = this.position.x + this.attackBox.offset.x
        this.attackBox.position.y = this.position.y
        this.position.x += this.velocity.x
        this.position.y += this.velocity.y

        if (this.position.y + this.height + this.velocity.y >= canvas.height - 95) {
            this.velocity.y = 0
        } else {
            this.velocity.y += gravity
        }
    }

    attacking() {
        this.attacks = true
        setTimeout(() => {
            this.attacks = false
        }, 100)
    }
}
