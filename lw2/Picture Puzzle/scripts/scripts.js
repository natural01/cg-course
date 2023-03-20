import { getButtonEvents, chooseImg, chooseLvl } from './evetns/buttonEvents.js'
import { getPiecesEvents } from './evetns/pieceEvents.js'
import { CPiece, indent, countOfPieces } from './CPiece.js'
import { imgsPath } from './paths/imgsPath.js'
import { CCoor } from "./CCoor.js"
import { stateGame, nextImg } from "./play.js" 
import { getMessageCode, buttonsEvent } from "./winMessage.js"

export var level = 1;
var matrix;
export var img = imgsPath.get("clock");
export var coor;

export function changeImg(newImg) {
    img = newImg;
    drawPuzzle(true);
    randomMatrix();
}
export function changeLvl(newLvl) {
    level = newLvl;
    drawPuzzle(true);
    randomMatrix();
}

function getRandomIntInclusive(min, max) {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min + 1) + min);
}
function randomMatrix() {
    let steps = Math.random() * (10 - 5) + 5;
    for (let i = 0; i < steps; i++) {
        let position1 = getRandomIntInclusive(0, countOfPieces.get(level)**2);
        let position2 = getRandomIntInclusive(0, countOfPieces.get(level)**2);
        if (position1 == position2) {continue;}
        movePieces(position1, position2, true);
    }
}

function preparationMatrix() {
    matrix = [];
    let arr = [];
    let count = 1;
    for (let i = 0; i < countOfPieces.get(level); i++) {
        arr = [];
        for (let j = 0; j < countOfPieces.get(level); j++) {
            arr.push(new CPiece(0 - i*indent.get(level), 0 - j*indent.get(level), count));
            count++;
        }
        matrix.push(arr);
    }
}

function addPieces(needToPreparation) {
    if (needToPreparation) {
        preparationMatrix();
        coor = new CCoor(level, countOfPieces);
    }
    let str = '';
    const div = document.createElement('div');
    div.id = 'puzzleArea';

    for (let i = 0; i < matrix.length; i++){
        str += '<div class="str">';
        let code = ``;
        for (let j = 0; j < matrix[i].length; j++) {
            code += `<div id="piece" style="height: ` + indent.get(level) + `px; width: ` + indent.get(level) + `px">
                        <img id="clip" src="` + img + `" style="margin-top:` + matrix[i][j].getTop() + `px; margin-left:` + matrix[i][j].getLeft() + `px;"/>
                    </div>`
        }
        str += code;
        str += '</div>'
    }
    div.innerHTML = str;
    return div;
}

export function drawPuzzle(needToPreparation) {
    if (!document.getElementById('puzzleArea')) {
        document.getElementById('puzzle').appendChild(addPieces(needToPreparation));
    } else {
        document.getElementById('puzzleArea').remove();
        document.getElementById('puzzle').appendChild(addPieces(needToPreparation));
    }

    getPiecesEvents(document);
}

function checkWin() {
    for (let i = 0; i < countOfPieces.get(level)**2 - 1; i++) {
        if (coor.getCoor().get(i) != i) {
            return false;
        }
    }
    console.log(coor);
    return true;
}
export function movePieces(position1, position2, ready) {
    coor.setPosition(position1, position2);
    let firstPiece = coor.getPosition(position1, position2)[0];
    let secondPiece = coor.getPosition(position1, position2)[1];
    let piece2 = undefined;
    let x = undefined, y = undefined;
    for (let i = 0; i < countOfPieces.get(level); i++) {
        for (let j = 0; j < countOfPieces.get(level); j++) {
            if (matrix[i][j].getPosition()-1 == firstPiece || matrix[i][j].getPosition()-1 == secondPiece) {
                if (x == undefined) {
                    x = i;
                    y = j;    
                } else {
                    piece2 = matrix[i][j];
                    matrix[i][j] = matrix[x][y];
                    matrix[x][y] = piece2;
                }
            }
        }
    }
    drawPuzzle(false);
    if (stateGame && checkWin() && !ready) {
        getMessageCode();
        buttonsEvent();
    }
}

drawPuzzle(true);
getButtonEvents();
chooseImg();
chooseLvl();