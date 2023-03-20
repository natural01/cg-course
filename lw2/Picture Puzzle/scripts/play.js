import { imgsPath } from "./paths/imgsPath.js"
import { changeLvl, level, img, changeImg, drawPuzzle } from "./scripts.js"

export var stateGame = false;

function nextLevel() {
    switch (level) {
        case 1:
            changeLvl(2);
            break;
        case 2:
            changeLvl(3);
            break;
        case 3:
            alert("finish");
            changeLvl(1);
            break;
    }
}
export function nextImg() {
    switch (img) {
        case imgsPath.get("clock"):
            changeImg(imgsPath.get("sugar"));
            break;
        case imgsPath.get("sugar"):
            changeImg(imgsPath.get("mountains"));
            break;
        case imgsPath.get("mountains"):
            nextLevel();
            changeImg(imgsPath.get("clock"));
            break;
    }
}

export function startGame() {
    changeImg(imgsPath.get("clock"));
    changeLvl(1);
    drawPuzzle(false);
    stateGame = true;
}

export function stopGame() {
    changeImg(imgsPath.get("clock"));
    changeLvl(1);
    drawPuzzle(false);
    stateGame = false;
}