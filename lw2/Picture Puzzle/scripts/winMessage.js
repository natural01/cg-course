import { nextImg } from "./play.js"

export function getMessageCode() {
    const div = document.createElement('div');
    div.id = 'cover';
    let str = `<div>
                    <div class="score">
                        <p calss="textWin">You Win</p>
                        <div style="display: flex;">
                            <button id="button" class="next">Next</button>
                        </div>
                    </div>
                </div>`
    div.innerHTML = str;
    document.getElementById('puzzle').appendChild(div);
}

function removeMessageCode() {
    document.getElementById("cover").remove();
}

export function buttonsEvent() {
    let next = document.querySelector(".next");
    next.addEventListener("click", () => {
        removeMessageCode();
        nextImg();
    });
}