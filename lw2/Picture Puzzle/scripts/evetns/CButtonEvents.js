import { soundsPath } from "../paths/soundsPath.js"

export class CButtonEvents {
    constructor (obs) {
        this.#observer = obs;
    }

    #observer;
    #selectButton = new Audio(soundsPath.get("selectButton"));
    #clickButton = new Audio(soundsPath.get("clickButton"));

    getButtonEvents(document) {
        let buttons = document.querySelectorAll("#button");
        let images = document.querySelectorAll("#image");

        // document.getElementById('getImg').addEventListener('change', function() {
        //     this.#observer.changeImg(""+getImg.files[0]);
        // });

        this.start(document);
        this.stop(document);
        buttons.forEach(button => {
            button.addEventListener("mouseenter", () => {
                this.#selectButton.play();
            });
            button.addEventListener("click", () => {
                this.#clickButton.play();
            });
        });
        images.forEach(images => {
            images.addEventListener("mouseenter", () => {
                this.#selectButton.play();
            });
            images.addEventListener("click", () => {
                this.#clickButton.play();
            });
        });
        this.chooseImg(images);
        this.chooseLvl(document);
    }
    
    chooseImg(images) {
        images.forEach(images => {
            images.addEventListener("click", () => {
            this.#observer.changeImg(images.src);
        });
      });
    }
    chooseLvl(document) {
      let b1 = document.querySelector(".b1");
      let b2 = document.querySelector(".b2");
      let b3 = document.querySelector(".b3");
    
      b1.addEventListener("click", () => {
        this.#observer.changeLvl(Number(b1.value));
      });
      b2.addEventListener("click", () => {
        this.#observer.changeLvl(Number(b2.value));
      });
      b3.addEventListener("click", () => {
        this.#observer.changeLvl(Number(b3.value));
      });
    };
    
    start(document) {
        let start = document.querySelector(".start");
        
        start.addEventListener("click", () => {
            this.#observer.changeMode(true);
        });
    }
    
    stop(document) {
        let stop = document.querySelector(".stop");
        
        stop.addEventListener("click", () => {
            this.#observer.changeMode(false);
        });
    }
}