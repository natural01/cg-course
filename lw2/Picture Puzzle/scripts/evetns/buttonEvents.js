import { soundsPath } from "../paths/soundsPath.js"
import { changeImg, changeLvl } from "../scripts.js"
import { startGame, stopGame } from "../play.js"
const selectButton = new Audio(soundsPath.get("selectButton"));
const clickButton = new Audio(soundsPath.get("clickButton"));
const buttons = document.querySelectorAll("#button");
const images = document.querySelectorAll("#image");

export function getButtonEvents() {
    start();
    stop();
    buttons.forEach(button => {
        button.addEventListener("mouseenter", () => {
          selectButton.play();
        });
        button.addEventListener("click", () => {
          clickButton.play();
        });
      });
      images.forEach(images => {
        images.addEventListener("mouseenter", () => {
        selectButton.play();
      });
      images.addEventListener("click", () => {
        clickButton.play();
      });
    });
}

export function chooseImg() {
  images.forEach(images => {
      images.addEventListener("click", () => {
        changeImg(images.src);
    });
  });
}
export function chooseLvl() {
  let b1 = document.querySelector(".b1");
  let b2 = document.querySelector(".b2");
  let b3 = document.querySelector(".b3");

  b1.addEventListener("click", () => {
    changeLvl(Number(b1.value));
  });
  b2.addEventListener("click", () => {
    changeLvl(Number(b2.value));
  });
  b3.addEventListener("click", () => {
    changeLvl(Number(b3.value));
  });
};

function start() {
  let start = document.querySelector(".start");

  start.addEventListener("click", () => {
    startGame();
  });
}

function stop() {
  let stop = document.querySelector(".stop");

  stop.addEventListener("click", () => {
    stopGame();
  });
}