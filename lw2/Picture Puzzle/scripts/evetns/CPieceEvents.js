import { soundsPath } from "../paths/soundsPath.js"

export class CPieceEvents {
    constructor (obs) {
        this.#observer = obs;
    }

    #observer;
    #transparency = 0;
    #position1;
    #position2;

    #selectPiece = new Audio(soundsPath.get("selectButton"));
    #clickPiece = new Audio(soundsPath.get("clickPiece"));
    #movePiece = new Audio(soundsPath.get("movePiece"));

    setPosition(position) {
        if (this.#position1 == undefined) {
            this.#position1 = position;
        } else {
            this.#position2 = position;
        }
    }
    nullPosition() {
        this.#position1 = undefined;
        this.#position2 = undefined;
    }

    getPiecesEvents(doc) {
        const pieces = doc.querySelectorAll("#clip");
    
        pieces.forEach(piece => {
            piece.addEventListener("mouseenter", () => {
                this.#selectPiece.play();
            });
            piece.addEventListener("click", () => {
                this.#clickPiece.play();
                this.checkTransparency(piece, pieces);
            });
        });
    }

    transparencyOn(elem) {
        elem.style.opacity = 0.6;
    }
    
    transparencyOff(elem) {
        elem.style.opacity = 1;
    }
    
    already(elem) {
        if (elem.style.opacity == 0.6) {
            return true;
        }
        return false;
    }

    checkTransparency(elem, elems) {
        this.nullPosition();
        if (this.#transparency < 1) {
            if (!this.already(elem)) {
                this.transparencyOn(elem);
                this.#transparency++;
            }
        } else {
            if (!this.already(elem)) {
                    this.transparencyOn(elem);
                let count = 0;
                this.#transparency = 0;
                elems.forEach(elem => {
                    if (this.already(elem)) {
                        this.setPosition(count);
                    }
                    this.transparencyOff(elem);
                    count++;
                });
                this.#movePiece.play();
                this.#observer.movePieces(this.#position1, this.#position2, false);
            }
        }
    }
}