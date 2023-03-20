export const getSVGFlower = () => {
    const div = document.createElement('div');
  
    div.className = 'flower';
    div.innerHTML = `
        <svg xmlns="http://www.w3.org/2000/svg" width="230px" height="210" viewPort="0 0 120 120" version="1.1">
            <polygon points="90 75, 128 173, 120 220, 125 220, 133 173, 90 75" fill="green"></polygon>
            <polygon points="130 170, 150 148, 178 135, 204 142, 190 166, 164 179" fill="green"></polygon>
            <polygon points="80 90, 20 75, 80 60" fill="rgb(232, 224, 71)"></polygon>
            <polygon points="75 60, 90 0, 105 60" fill="rgb(232, 224, 71)"></polygon>
            <polygon points="100 60, 160 75, 100 90" fill="rgb(232, 224, 71)"></polygon>
            <polygon points="75 85, 90 145, 105 85" fill="rgb(232, 224, 71)"></polygon>
            <polygon points="74 76, 46 29, 93 53" fill="rgb(232, 224, 71)"></polygon>
            <polygon points="93 53, 148 31, 117 70" fill="rgb(232, 224, 71)"></polygon>
            <polygon points="117 70, 149 128, 97 103" fill="rgb(232, 224, 71)"></polygon>
            <polygon points="97 103, 48 131, 74 76" fill="rgb(232, 224, 71)"></polygon>
            <circle cx="90" cy="75" r="30" fill="yellow"></circle>
        </svg>
    `;
  
    return div;
}