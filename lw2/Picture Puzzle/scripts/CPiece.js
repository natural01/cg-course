export class CPiece {
    constructor(top, left, position) {
        this.top = top;
        this.left = left;
        this.position = position;
    }

    getTop() {
        return this.top; 
    }
    getLeft() {
        return this.left;
    }
    getPosition() {
        return this.position;
    }
    setTop(top) {
        this.top = top;
    }
    setLeft(left) {
        this.left = left;
    }
    setPosition(position) {
        this.position = position;
    }
}