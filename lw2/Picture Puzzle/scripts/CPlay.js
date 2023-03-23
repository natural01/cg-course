import { imgsPath } from "./paths/imgsPath.js"

export class CPlay {
    constructor (obs) {
        this.#observer = obs;
    }

    #mode = false;
    #observer;

    getMode() {
        return this.#mode;
    }
    setMode(mode) {
        this.#mode = mode;
    }

    nextLevel() {
        switch (this.#observer.getLvl()) {
            case 1:
                this.#observer.changeLvl(2);
                break;
            case 2:
                this.#observer.changeLvl(3);
                break;
            case 3:
                alert("finish");
                this.#observer.changeLvl(1);
                break;
        }
    }
    nextImg() {
        switch (this.#observer.getImg()) {
            case imgsPath.get("clock"):
                this.#observer.changeImg(imgsPath.get("sugar"));
                break;
            case imgsPath.get("sugar"):
                this.#observer.changeImg(imgsPath.get("mountains"));
                break;
            case imgsPath.get("mountains"):
                this.nextLevel();
                this.#observer.changeImg(imgsPath.get("clock"));
                break;
        }
    }

    startGame() {
        this.#observer.changeImg(imgsPath.get("clock"));
        this.#observer.changeLvl(1);
        this.#observer.drawPuzzle(false);
        this.setMode(true);
    }
    stopGame() {
        this.#observer.changeImg(imgsPath.get("clock"));
        this.#observer.changeLvl(1);
        this.#observer.drawPuzzle(false);
        this.setMode(false);
    }
}