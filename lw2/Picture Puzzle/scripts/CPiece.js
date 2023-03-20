export class CPiece {
    constructor(top, left, position) {
        this.top = top,
        this.left = left,
        this.position = position
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

export let indent = new Map;
indent.set(1, 200);
indent.set(2, 150);
indent.set(3, 120);

export let countOfPieces = new Map;
countOfPieces.set(1, 3);
countOfPieces.set(2, 4);
countOfPieces.set(3, 5);