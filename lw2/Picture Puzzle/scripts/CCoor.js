export class CCoor {
    constructor(level, countOfPieces) {
        var newCoor = new Map;
        for (let i = 0; i < countOfPieces.get(level)**2; i++) {
            newCoor.set(i, i);
        }
        this.coor = newCoor;
    }
    setPosition(position1, position2) {
        if (this.coor.get(position1) != undefined && this.coor.get(position2) != undefined) {
            let newPosition = this.coor.get(position1);
            this.coor.set(position1, this.coor.get(position2));
            this.coor.set(position2, newPosition);
        }
    }
    getPosition(position1, position2) {
        return [this.coor.get(position1), this.coor.get(position2)];
    }
    getCoor() {
        return this.coor;
    }
}