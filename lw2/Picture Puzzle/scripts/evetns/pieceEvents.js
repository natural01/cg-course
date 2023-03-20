import { soundsPath } from "../paths/soundsPath.js"
import { movePieces } from "../scripts.js"
const movePiece = new Audio(soundsPath.get("movePiece"));
const clickPiece = new Audio(soundsPath.get("clickPiece"));
const selectPiece = new Audio(soundsPath.get("selectButton"));

var transparency = 0;
var position1, position2;

function setPosition(position) {
    if (position1 == undefined) {
        position1 = position;
    } else {
        position2 = position;
    }
}
function nullPosition() {
    position1 = undefined;
    position2 = undefined;
}

export function getPiecesEvents(doc) {
    const pieces = doc.querySelectorAll("#clip");

    pieces.forEach(piece => {
        piece.addEventListener("mouseenter", () => {
            selectPiece.play();
        });
        piece.addEventListener("click", () => {
            clickPiece.play();
            checkTransparency(piece, pieces);
        });
    });
}

function transparencyOn(elem) {
    elem.style.opacity = 0.6;
}

function transparencyOff(elem) {
    elem.style.opacity = 1;
}

function already(elem) {
    if (elem.style.opacity == 0.6) {
        return true;
    }
    return false;
}

function checkTransparency(elem, elems) {
    nullPosition();
    if (transparency < 1) {
        if (!already(elem)) {
            transparencyOn(elem);
            transparency++;
        }
    } else {
        if (!already(elem)) {
                transparencyOn(elem);
            let count = 0;
            transparency = 0;
            elems.forEach(elem => {
                if (already(elem)) {
                    setPosition(count);
                }
                transparencyOff(elem);
                count++;
            });
            movePiece.play();
            movePieces(position1, position2, false);
        }
    }
}