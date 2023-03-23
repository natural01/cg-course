import { CPiece } from "./CPiece.js";
import { CPieceEvents } from './evetns/CPieceEvents.js'
import { imgsPath } from './paths/imgsPath.js'
import { CButtonEvents } from './evetns/CButtonEvents.js'
import { CPlay } from './CPlay.js'
import { CWinMessage } from './CWinMessage.js'

export class CApplication {
    constructor (doc) {
        this.document = doc;
        this.#indent.set(1, 200);
        this.#indent.set(2, 150);
        this.#indent.set(3, 120);
    }

    #pieceEvents = new CPieceEvents(this);
    #buttonEvents = new CButtonEvents(this);
    #play = new CPlay(this);
    #message = new CWinMessage(this, this.#play);

    static document;
    #img = imgsPath.get("clock");
    #lvl = 1;
    #mapOfPuzzle = new Map;
    #indent = new Map;

    getImg() {
        return this.#img;
    }
    getLvl() {
        return this.#lvl;
    }

    getRandomIntInclusive(min, max) {
        min = Math.ceil(min);
        max = Math.floor(max);
        return Math.floor(Math.random() * (max - min + 1) + min);
    }
    randomMatrix() {
        let steps = Math.random() * (10 - 5) + 5;
        for (let i = 0; i < steps; i++) {
            let position1 = this.getRandomIntInclusive(0, (this.#lvl+2)**2-1);
            let position2 = this.getRandomIntInclusive(0, (this.#lvl+2)**2-1);
            if (position1 == position2) {continue;}
            this.movePieces(position1, position2, true);
        }
    }

    changeImg(newImg) {
        this.#img = newImg;
        this.drawPuzzle(true);
        this.randomMatrix();
    }
    changeLvl(newLvl) {
        this.#lvl = newLvl;
        this.drawPuzzle(true);
        this.randomMatrix();
    }

    preparationMatrix() {
        let count = 0;
        for (let i = 0; i < this.#lvl+2; i++) {
            for (let j = 0; j < this.#lvl+2; j++) {
                this.#mapOfPuzzle.set(count, new CPiece(0 - i*this.#indent.get(this.#lvl), 0 - j*this.#indent.get(this.#lvl), count));
                count++;
            }
        }
    }

    addPieces(needToPreparation) {
        if (needToPreparation) {
            this.preparationMatrix();
        }
        let str = '';
        const div = document.createElement('div');
        div.id = 'puzzleArea';
        let count = 0;

        for (let i = 0; i < this.#lvl+2; i++){
            str += '<div class="str">';
            let code = ``;
            for (let j = 0; j < this.#lvl+2; j++) {
                code += `<div id="piece" style="height: ` + this.#indent.get(this.#lvl) + `px; width: ` + this.#indent.get(this.#lvl) + `px">
                            <img id="clip" src="` + this.#img + `" style="margin-top:` + this.#mapOfPuzzle.get(count).getTop() + `px; margin-left:` + this.#mapOfPuzzle.get(count).getLeft() + `px;"/>
                        </div>`
                count++;
            }
            str += code;
            str += '</div>'
        }

        div.innerHTML = str;
        return div;
    }

    drawPuzzle(needToPreparation) {
        if (!this.document.getElementById('puzzleArea')) {
            this.document.getElementById('puzzle').appendChild(this.addPieces(needToPreparation));
        } else {
            this.document.getElementById('puzzleArea').remove();
            this.document.getElementById('puzzle').appendChild(this.addPieces(needToPreparation));
        }
    
        this.#pieceEvents.getPiecesEvents(this.document);
    }

    checkWin() {
        for (let i = 0; i < (this.#lvl+2)**2; i++) {
            if (this.#mapOfPuzzle.get(i).getPosition() != i) {
                return false;
            }
        }
        return true;
    }

    movePieces(position1, position2, ready) {
        let piece = this.#mapOfPuzzle.get(position1);
        this.#mapOfPuzzle.set(position1, this.#mapOfPuzzle.get(position2));
        this.#mapOfPuzzle.set(position2, piece);
        this.drawPuzzle(false);
        if (this.#play.getMode() && this.checkWin()) {
            this.#message.getMessageCode(this.document);
            this.#message.buttonEvent(this.document);
        }
    }

    changeMode(mode) {
        if (mode) {
            this.#play.setMode(true);
            this.#play.startGame();
        } else {
            this.#play.setMode(false);
            this.#play.stopGame();
        }
    }

    startGame() {
        this.drawPuzzle(true);
        this.#buttonEvents.getButtonEvents(this.document);
    }
}