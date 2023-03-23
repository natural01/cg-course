export class CWinMessage {

    constructor (obs, play) {
        this.#observer = obs;
        this.#play = play
    }

    #observer;
    #play;

    getMessageCode(document) {
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
    removeMessageCode(document) {
        document.getElementById("cover").remove();
    }
    buttonEvent(document) {
        let next = document.querySelector(".next");
        next.addEventListener("click", () => {
            this.removeMessageCode(document);
            this.#play.nextImg();
        });
    }
}